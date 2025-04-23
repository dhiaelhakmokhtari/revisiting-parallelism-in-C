// my version

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

/// simple version testing

//#include <mpi.h>
//#include <stdio.h>
//
//int main(int argc, char **argv) {
//    int rank, size;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    printf("Hello from process %d of %d\n", rank, size);
//
//    MPI_Finalize();
//    return 0;
//}

// non-blocking comm.

//#define N 5

//int main (int argc, char **argv)
//{
//
//int rank, data;
//MPI_Request request;
//MPI_Status status;
//
//MPI_Init(&argc, &argv);
//MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//   for (int i=0; i<N; i++)
//   {
//    if(rank == 0)
//   {
//    data = i*3;
//    MPI_Isend(&data, 1, MPI_INT, 1, 123,MPI_COMM_WORLD, &request);
//    MPI_Wait(&request, &status);
//    printf("process 0 sent data : %d",data); 
//    }  
//    if(rank == 1)
//    {
//    MPI_Irecv(&data, 1, MPI_INT, 0, 123, MPI_COMM_WORLD, &request);
//    MPI_Wait(&request, &status);
//    printf("process 1 recieved data : %d",data);
//    }
//   }
//MPI_Finalize();
//return 0;
//}

#include <mpi.h>
#include <stdio.h>
#define N 5

int main (int argc, char **argv) {
    int rank, data, size; //data;
    int flag = 0;
    MPI_Request request;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0)
            printf("Run this with at least 2 processes.\n");
        MPI_Finalize();
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (rank == 0) {
            data = i * 3;
            MPI_Send(&data, 1, MPI_INT, 1, 123, MPI_COMM_WORLD);
            //MPI_Wait(&request, &status);
            printf("Process 0 sent data: %d\n", data);
        }

        if (rank == 1) {
            MPI_Irecv(&data, 1, MPI_INT, 0, 123, MPI_COMM_WORLD, &request);
            
            //MPI_Wait(&request, &status);
            while (!flag){
            printf("process 1 is working while waiting...")
            MPI_Test(&request, &flag, &status);
            }
            printf("Process 1 received data: %d\n", data);
        }
    }

    MPI_Finalize();
    return 0;
}

