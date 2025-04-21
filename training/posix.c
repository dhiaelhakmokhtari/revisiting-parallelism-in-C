#include <stdio.h>
#include <pthread.h>
#define nb_threads 6

void *say_hello(void *arg){
printf("hello\n");
return NULL;
}

int main(){
pthread_t threads[nb_threads];

for (int i=0; i< nb_threads; i++){
int rc = pthread_create(&threads[i], NULL, say_hello, NULL);
}

for (int i=0; i< nb_threads; i++){
pthread_join(threads[i],NULL);
}

return 0;
}
