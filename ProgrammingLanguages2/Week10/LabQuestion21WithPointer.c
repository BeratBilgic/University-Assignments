#include <stdio.h>
#include <stdlib.h>

struct student
{
    int number;
    char name[20];
    char surname[20];
    int midtermGrade;
};
 
int main(){

    struct student *ptr;

    ptr = (struct student*)malloc(1 * sizeof(struct student));

    for (int i = 0; i < 3; i++)
    {
        ptr = (struct student*)realloc(ptr,i);
        printf("Student %d\n",i+1);
        printf("Number = ");
        scanf("%d",&(ptr+i)->number);
        printf("Name = ");
        scanf("%s",(ptr+i)->name);
        printf("Surname = ");  
        scanf("%s",(ptr+i)->surname);
        printf("Midterm Grade = ");
        scanf("%d",&(ptr+i)->midtermGrade);
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Number = %d \t",(ptr+i)->number);
        printf("Name = %s \t",(ptr+i)->name);
        printf("Surname = %s \t",(ptr+i)->surname);
        printf("Midterm Grade = %d \t\n",(ptr+i)->midtermGrade);
    }

    return 0;
}