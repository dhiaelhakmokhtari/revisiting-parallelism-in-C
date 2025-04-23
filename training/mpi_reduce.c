#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank, size;
    int local_value, total_sum;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Each process generates its local value
    local_value = rank + 1;

    printf("Process %d contributes %d\n", rank, local_value);

    // Reduce all values to root (rank 0)
    MPI_Reduce(&local_value, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Total sum at root = %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}

