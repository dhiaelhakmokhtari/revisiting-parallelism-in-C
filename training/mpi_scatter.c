#include <stdio.h>
#include <mpi.h>

#define TOTAL_SIZE 8

int main(int argc, char **argv){
         int rank,size;
         int data[TOTAL_SIZE];
         int recvbuf[2];
         
       MPI_Init(&argc, &argv);
       MPI_Comm_rank(MPI_COMM_WORLD,&rank);
       MPI_Comm_size(MPI_COMM_WORLD,&size);
       
       if(rank=!4){
         if(rank == 0){
           printf("this example works with only 4 processes");
           MPI_Finalize();
           return 1;
         }
       }
         
       if(rank == 0){
         for(int i=0; i<TOTAL_SIZE; i++){
          data[i] = i*10;
         }
         printf("process 0 is scaterring :\n");
         for(int i=0; i<TOTAL_SIZE; i++){printf("%d\t", data[i]);}
       }
       MPI_Scatter(data, 2, MPI_INT, recvbuff, 2, MPI_INT, 0, MPI_COMM_WORLD);
       printf("process %d recieved this values %d", rank, recvbuf[0], recvbuf[1]);
       
     MPI_Finalize():
    return 0;
