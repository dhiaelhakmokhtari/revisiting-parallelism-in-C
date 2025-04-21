#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define nb_threads 5
typedef struct thread_data{
             int thread_id;
             }thread_data;


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void* increment(void* threadarg){

 thread_data *data = (thread_data *) threadarg;
 printf("hello this is thread %d\n",data->thread_id);
 
 pthread_mutex_lock(&mutex);
 counter++;
 printf("counter : %d\n",counter);
 pthread_mutex_unlock(&mutex);
 return NULL;
 
 }
 
 int main() {
 
 pthread_t threads[nb_threads];
 struct thread_data thread_data_array[nb_threads];
 int rc;
 
 for(int t = 0; t<nb_threads ; t++){
 
 thread_data_array[t].thread_id = t;
 
 rc = pthread_create(&threads[t], NULL, increment,(void *) &thread_data_array[t]);
 if (rc != 0) {
 printf("error creating thread number %d\n",t);
 exit(-1);
 }
 }
 // Wait for all threads to finish
   for (int t = 0; t < nb_threads; t++) {
        pthread_join(threads[t], NULL);
    }
  return 0;
}
