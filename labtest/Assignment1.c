#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){
    int id, total;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &total);
    printf("Rank %d of total %d\n", id, total);
    MPI_Finalize();

}