#include <stdio.h>

struct student
{
    int number;
    char name[20];
    char surname[20];
    int midtermGrade;
}students[10]; 
 
int main(){
    for (int i = 0; i < 3; i++)
    {
        printf("Student %d\n",i+1);
        printf("Number = ");
        scanf("%d",&students[i].number);
        printf("Name = ");
        scanf("%s",students[i].name);
        printf("Surname = ");  
        scanf("%s",students[i].surname);
        printf("Midterm Grade = ");
        scanf("%d",&students[i].midtermGrade);
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Number = %d \t",students[i].number);
        printf("Name = %s \t",students[i].name);
        printf("Surname = %s \t",students[i].surname);
        printf("Midterm Grade = %d \t\n",students[i].midtermGrade);
    }

    return 0;
}