#include "math.h"
#include <stdio.h>
#include <time.h>

double factorial(const double x)
{
    double result = 1;
    for (double i = 1; i <= x; i++)
    {
        result *= i;
    }
    return result;
}
long double calculate_cos(float x)
{

    double result = 0.0;
    for (double i = 0; i <= 5000; i++)
    {
         long double numerator_1 = pow(-1, i);
         long double numerator_2 = pow(x, 2*i);
         long double denominator = factorial(2 * i);
        result+= (numerator_1*numerator_2)/denominator;
    }
    return result;
}

int main(void)
{
   
    float x;
    printf("please enter the value of x:\n");
    scanf("%f",&x);
    clock_t t;
    clock_t t_final;
    t = clock();
    double res = calculate_cos(x);
   
    printf("The valuse of cos(x) is %f\n", res);
    printf("The values of sin(x) is %f\n",sqrt(1-pow(res,2)));
    t_final = clock() - t;
    double time_taken = ((double)t_final) / CLOCKS_PER_SEC; 

    printf("The total time for calculation %f \n", time_taken);

    return 0;
}
//if(i >20) continue