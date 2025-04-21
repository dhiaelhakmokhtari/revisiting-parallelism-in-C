#include <stdio.h>

struct Person{
char name;
int age;
};

void updateStruct(struct Person *p, int age)
{
 p->age = age;
 printf("aged into %d years old",age);
}
void main (int argc, char **argv)
{
struct Person p1;
updateStruct(&p1, 30);
}
