#include <stdio.h>
#include <stdlib.h>

int sumTab(int *array, int arrsize){

int total = 0;

for(int i=0; i<arrsize ; i++){
total = total + array[i]; //or *(array + i);
}
return total;
}

int main(){

int size = 5;
int *dyn_arr = malloc(size * sizeof(int));

if(dyn_arr == NULL){
printf("error memoire");
return 1;
}

for(int i=0; i<size; i++){
dyn_arr[i] = i;
}

int t = sumTab(dyn_arr, size);
printf("total =%d\n",t);

free(dyn_arr);

return 0;
}
