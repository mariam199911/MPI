#include "mpi.h"
#include "math.h"
#include <stdio.h>

long double factorial(const long double x)
{
    long double result = 1;
    for (long double i = 1; i <= x; i++)
    {
        result *= i;
    }
    return result;
}

long double calculate_part_of_cos(const long double  local_start, const long double  local_end, float x)
{
     double result = 0.0;
    for (long double  i = local_start ;i <= local_end; i++)
    {
        if(i >20) continue;
         long double numerator_1 = pow(-1, i);
         long double numerator_2 = pow(x, 2*i);
         long double denominator = factorial(2 * i);
        result+= (numerator_1*numerator_2)/denominator;
    }
    return result;
}



int main(int argc, char *argv[])
{
    int rank, size,n;
    int    local_n, local_start, local_end;
    float x;
    long double local_cos, total_cos;
    if(argc != 1){
        printf("%s",argv[1]);
    }

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
   
    
    if (rank == 0)
    {
        printf("please enter the upper limit of i:\n");
        scanf("%d",&n);
        printf("please enter the value of x:\n");
        scanf("%f",&x);
        printf("upper limit of i is %d, Number of processes is %d \n", n, size);
        for (int dist = 1; dist < size; dist++)
        {
            MPI_Send(&n,1,MPI_INT,dist,0,MPI_COMM_WORLD);
            MPI_Send(&x,1,MPI_INT,dist,0,MPI_COMM_WORLD);
        }
      //MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        
    }
    else
    {
         MPI_Recv(&n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(&x,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
         
    }
    double start = MPI_Wtime();

    
    local_n = n / size;
    local_start = rank * local_n;
     //local_end = (rank + 1) * local_n - 1;
     local_end = (rank+1)*local_n-1;
    //  local_end = 20;
    // printf("rank %d ,with local_start = %d , local_end =  %d\n, x value = %f",rank, local_start,local_end,x);
    local_cos=calculate_part_of_cos(local_start,local_end,x);
     //printf("rank %d ,with local_value = %Lf \n ",rank, local_pi);
      //printf("size %d ,with n  = %d \n ",size, n);
    if (rank == 0)
    {
        total_cos = local_cos;
        for (int sender =1; sender < size; sender++)
        {
            
            MPI_Recv(&local_cos,1,MPI_LONG_DOUBLE,sender,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            total_cos += local_cos;
            
        }
        double end = MPI_Wtime()-start;
       printf("The values of cos(x) is %Lf\n",total_cos);
       printf("The values of sin(x) is %f\n",sqrt(1-pow(total_cos,2)));
       printf("The total time for calculation %f\n",end);

        
    }
    else
    {
       
        MPI_Send(&local_cos,1,MPI_LONG_DOUBLE,0,0,MPI_COMM_WORLD);
    }
    
    MPI_Finalize();

    return 0;
}