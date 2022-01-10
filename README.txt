This README explains the steps required to run the Assignment 3 files

Contents: 

1. sequential.c
2. mpi.c (contains mpi code)
3. README.txt

Steps:
1. Open Terminal in the Directory where you extracted the .zip file
2. compile files
   gcc sequential.c -o sequential -lm  ---> for sequential.c file 
   mpicc -o ver3 ver3.c -lm            ---> for mpi.c file
3. type the following ./sequential to run the exe of sequential.c file
4. type the following command:  mpirun -np 2 ./ver3 to run the exe of ver3.c file
   2 ---> represents the number of process you can type any number  


