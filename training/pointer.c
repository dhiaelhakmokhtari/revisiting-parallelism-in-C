#include <stdio.h>

void add(int *a, int *b, int *c);

int main(){
int a = 3;
int b = 3;
int c = 3;

printf("les valeurs avant ADD sont :\n a = %d \n b = %d \n c = %d",a,b,c);

add(&a, &b, &c);

printf("les valeurs avant ADD adding b et c sur a sont :\n a = %d \n b = %d \n c = %d",a,b,c);

}

void add(int *a, int *b, int *c){
*a = *a + *b + *c;
}
