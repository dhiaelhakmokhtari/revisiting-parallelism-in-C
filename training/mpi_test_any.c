#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank, buffer[3], flag = 0, index;
    MPI_Request requests[3];
    MPI_Status status;

    MPI_Init(&argc, &argv);                          // ✅ REQUIRED
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // Send 3 messages with tags 0, 1, 2
        for (int i = 0; i < 3; i++) {
            int value = (i + 1) * 10;
            MPI_Send(&value, 1, MPI_INT, 1, i, MPI_COMM_WORLD);
        }
    }

    if (rank == 1) {
        // Start 3 non-blocking receives
        for (int i = 0; i < 3; i++) {
            MPI_Irecv(&buffer[i], 1, MPI_INT, 0, i, MPI_COMM_WORLD, &requests[i]);
        }

        int completed = 0;
        while (completed < 3) {
            MPI_Testany(3, requests, &index, &flag, &status);
            if (flag && index != MPI_UNDEFINED) {
                printf("Rank 1 received buffer[%d] = %d (tag %d)\n", index, buffer[index], status.MPI_TAG);
                completed++;
            }
        }
    }

    MPI_Finalize();                                  // ✅ REQUIRED
    return 0;
}

