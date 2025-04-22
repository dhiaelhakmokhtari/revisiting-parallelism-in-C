#include <stdio.h>
#include <omp.h>

int main(){

#pragma opm parallel
{
   
   #pragma opm for ordered nowait
   for (int i=0;i<10;i++)
   {   
   #pragma omp ordered
    printf("thread number %d, run number %d\n",omp_get_thread_num(),i);
   }
   
   printf("thread %d got out of the loop didnt wait",omp_get_thread_num());
}

}
