#include <mpi.h>
#include <stdio.h>
#define size 5

int main1 (int argc, char **argv){
int rank, value;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMME_WORLD,&rank);

if(rank == 0){
value = 123;
}
MPI_Bcast(&value, 1, MPI_INT, 0,MPI_COMM_WORLD);
printf("brodcasted value : %d\n",value);
MPI_Finalize();
return 0;
}


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int main2 (int argc, char **argv)
{
int rank;
int data[size];

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);

if(rank == 0){
   for(int i=0; i<size; i++){
       data[i] = i*3;
    }
} 

printf("0 is broadcasting :\n");
MPI_Bcast(data, size,MPI_INT,0,MPI_COMM_WORLD);

for(int i=0; i<size; i++){
printf("process %d recieved %d :\n", rank, data[i]);
}
MPI_Finalize();
return 0;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


