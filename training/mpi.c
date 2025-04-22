//#include <mpi.h>
//#include <stdio.h>
//
//int main (int argc, char **argv){
//  MPI_Init(&argc, &argv);
//  int data, rank, size;
//  MPI_Comm_size(MPI_COMM_WORLD,&size);
//  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//  
//  if(rank ==0){
//         data = 42;
//         MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
//         printf("thread %d sent data = %d to thread 1",rank, data);
//  }
//  
//  if (rank==1){
//         MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//         printf("thread %d recieved data : %d from thread 1", rank, data);
//         }
//   MPI_Finalize(); 
//   
//   return 0;      
//}
#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello from process %d of %d\n", rank, size);

    MPI_Finalize();
    return 0;
}

