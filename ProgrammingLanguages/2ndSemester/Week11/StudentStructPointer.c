#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int no;
    char name[30];
    int midtermGrade;
    int finalGrade;
    int average;
};
typedef struct student stu;

void addNewRecord(stu* ptr, int len);
void listRecord(stu* ptr, int len);
void updateRecord(stu* ptr, int len);
int calClassAverage(stu* ptr, int len);
void showBest(stu* ptr, int len);

int main(){
    stu *students;
    students = (stu*)malloc(sizeof(stu));
    int key,len = 0,loop=1,classAve;
    while (loop)
    {
        printf("\n1 - Add New Record\n");
        printf("2 - List Record\n");
        printf("3 - Update Record\n");
        printf("4 - Calculate Class Average\n");
        printf("5 - Show Best Student Record\n");
        printf("0 - Exit\n");
        printf("Your Choice = ");
        scanf("%d",&key);
        printf("\n");
        switch (key){
        case 1:
            len++;
            students = (stu*)realloc(students,len);
            addNewRecord(students,len);
            break;
        
        case 2:
            listRecord(students, len);
            break;

        case 3:
            updateRecord(students,len);
            break;
        
        case 4:
            classAve = calClassAverage(students,len);
            printf("Average of the class = %d\n",classAve);
            break;

        case 5:
            showBest(students, len);
            break;

        default:
            loop = 0;
            break;
        }
    } 
}

void addNewRecord(stu* ptr, int len){
    int i = len-1;
    //ptr = (stu*)realloc(ptr,len);
    printf("\nEnter new record\n");
    printf("No = ");
    scanf("%d",&(ptr+i)->no);
    printf("Name = ");
    scanf("%s",(ptr+i)->name);
    printf("Midterm Grade = ");
    scanf("%d",&(ptr+i)->midtermGrade);
    printf("Final Grade = ");
    scanf("%d",&(ptr+i)->finalGrade);
    (ptr+i)->average = (((ptr+i)->midtermGrade)*0.4) + (((ptr+i)->finalGrade)*0.6);
}

void listRecord(stu* ptr, int len){
    printf("No\tName\tMidterm Grade\tFinal Grade\tAverage\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",(ptr+i)->no);
        printf("%s\t",(ptr+i)->name);
        printf("%d\t\t",(ptr+i)->midtermGrade);
        printf("%d\t\t",(ptr+i)->finalGrade);
        printf("%d\n",(ptr+i)->average);
    }   
}

void updateRecord(stu* ptr, int len){
    int temp;
    printf("The number of the student you want to change = ");
    scanf("%d",&temp);
    for (int i = 0; i < len; i++)
    {
        if (temp == (ptr+i)->no)
        {
            printf("Update record\n");
            printf("Old No = %d\n",(ptr+i)->no);
            printf("New No = ");
            scanf("%d",&(ptr+i)->no);
            printf("\nOld Name = %s\n",(ptr+i)->name);
            printf("New Name = ");
            scanf("%s",(ptr+i)->name);
            printf("\nOld Midterm Grade = %d\n",(ptr+i)->midtermGrade);
            printf("New Midterm Grade = ");
            scanf("%d",&(ptr+i)->midtermGrade);
            printf("\nOld Final Grade = %d\n",(ptr+i)->finalGrade);
            printf("New Final Grade = ");
            scanf("%d",&(ptr+i)->finalGrade);
            (ptr+i)->average = (((ptr+i)->midtermGrade)*0.4) + (((ptr+i)->finalGrade)*0.6);
        }
    }
}

int calClassAverage(stu* ptr, int len){
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum = sum + ((ptr+i)->average);
    }
        
    return sum/len;
}

void showBest(stu* ptr, int len){
    int max = 0,index;
    for (int i = 0; i < len; i++)
    {
        if ((ptr+i)->average > max)
        {
            max = (ptr+i)->average ;
            index = i;
        }
    }
    printf("Best Student Information\n");
    printf("No\tName\tMidterm Grade\tFinal Grade\tAverage\n");

    printf("%d\t",(ptr+index)->no);
    printf("%s\t",(ptr+index)->name);
    printf("%d\t\t",(ptr+index)->midtermGrade);
    printf("%d\t\t",(ptr+index)->finalGrade);
    printf("%d\n",(ptr+index)->average);
}
