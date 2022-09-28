#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){
    int id, a = 8, b=9;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    if(id == 0){
        printf("[Process %d] Addition of %d & %d: %d \n",id,a,b,a+b);
    }
    else if(id == 1){
        printf("[Process %d] Subtraction of %d & %d: %d \n",id,a,b,a-b);
    }
    else if(id == 2){
        printf("[Process %d] Multiplication of %d & %d: %d \n",id,a,b,a*b);
    }
    else if(id == 3){
        printf("[Process %d] divition of %d & %d: %d \n",id,a,b,a/b);
    }
    MPI_Finalize();
}