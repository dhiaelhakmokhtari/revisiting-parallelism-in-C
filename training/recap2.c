#include <stdio.h>

void addFirstToSecond(int *a, int *b)
{
*b = *a + *b;
}

int main()
{
int a = 3, b = 2;
printf(" before : a=%d and b=%d\n",a,b);
addFirstToSecond(&a,&b);
printf(" after : a=%d and b=%d\n",a,b);

return 0;
}

