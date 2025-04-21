#include <stdio.h>

//defining a structure
typedef struct {
int b;
int c;
}TwoIntegers;

//function prototype
void print_essai(int number);
//function 2 prototype
int add(TwoIntegers values);

//main
int main (int argc, char ** argv){
int a = 3;
int results;

TwoIntegers numbers;
numbers.b = 5;
numbers.c = 3;

print_essai(a);

results = add(numbers);
printf("the sum of TwoIntegers is %d \n",results);

return 0;
}

void print_essai( int number){
printf("Essai de programmation %d \n",number);
}

int add(TwoIntegers values){
 return(values.b + values.c);
} 
