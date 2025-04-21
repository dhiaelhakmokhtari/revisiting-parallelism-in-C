#include <stdio.h>
#include <omp.h>

int main(){

omp_set_num_threads(5);

#pragma omp parallel
{
int id = omp_get_thread_num();
printf("hello world, this is thread number %d\n",id);

int n = omp_get_num_threads();
printf("there are %d threads running\n",n);
}

int max = omp_get_max_threads(); 
printf("max number of threads is : %d\n",max);

return 0;
}
