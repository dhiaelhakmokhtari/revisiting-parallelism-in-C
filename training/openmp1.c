#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 12

int main(){
   
   int c[N], b[N], result[N];
   int shared_counter = 0; 
   
   omp_set_num_threads(5);
   
   for(int i=0; i<N; i++)
   {
   b[i] = i;
   c[i] = i*2;
   }
      
   #pragma omp parallel 
   {
         #pragma omp single 
         {
         printf("this task is done by a single thread, number %d\n",omp_get_thread_num());
         }   
         
         #pragma omp master
         {
         printf("this task is monitored by a master thread, number %d\n",omp_get_thread_num());
         }
         
         #pragma omp parallel for schedule(static,2)
         for(int i=0;i<N;i++){
            result[i] = b[i]+c[i];
            printf("thread %d completed filling result[%d]\n",omp_get_thread_num(),i);
            }
         
         #pragma omp sections
         {
            #pragma omp section
            printf("task by thread %d\n",omp_get_thread_num());
            #pragma omp section
            printf("task by thread %d\n",omp_get_thread_num());
            #pragma omp section
            printf("task by thread %d\n",omp_get_thread_num());
         
         }   
         
         #pragma omp critical 
         {
         shared_counter++;
         printf("thread %d incremented shared counter to %d\n",omp_get_thread_num(),shared_counter);
         }
    }
        printf("\nFinal result array:\n");
    for (int i = 0; i < N; i++) {
        printf("result[%d] = %d\n", i, result[i]);
    }

    printf("Final shared_counter = %d\n", shared_counter);

    return 0;
}


