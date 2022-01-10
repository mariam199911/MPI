This README explains the steps required to run the Assignment 3 files

Contents: 

1. sequential.c
2. mpi.c (contains mpi code)
3. README.txt

Steps:
1. Open Terminal in the Directory where you extracted the .zip file
2. compile files
   gcc sequential.c -o sequential -lm  ---> for sequential.c file 
   mpicc -o mpi mpi.c -lm            ---> for mpi.c file
3. type the following ./sequential to run the exe of sequential.c file
4. type the following command:  mpirun -np 2 ./mpi to run the exe of mpi.c file
   2 ---> represents the number of process you can type any number  


