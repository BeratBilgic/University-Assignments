#include <stdio.h>

void createStudentFile(FILE *ptr);
void printStudents(FILE *ptr);
//void updateLess50(FILE *ptr);
int findAverage(FILE *ptr);

int main(){
    int loop = 1,key;
    FILE *mfPtr;
    while(loop){
        printf("\n1 - Create Student File \n2 - Print students with midterm grade greater than 50\n3 - Print midterm average\n");
        //printf("4 - Add 10 points to students with a midterm grade of less than 50\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            createStudentFile(mfPtr);
            break;
        case 2:
            printStudents(mfPtr);
            break;
        case 3:
            printf("Midterm Average = %d\n",findAverage(mfPtr));
            break;
        default:
            loop = 0;
            break;
        }
    }

    return 0;
}

void createStudentFile(FILE *ptr){
    char name[30];
    int no,midGrade,n;
    if ((ptr = fopen("student","w")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("How many records you would like to insert ? \n");
        scanf("%d",&n);
        printf("Enter the no, name, and midterm grade.\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%d%29s%d",&no,name,&midGrade);
            fprintf(ptr,"%d %s %d\n",no,name,midGrade);
        }
        
        fclose(ptr);
    }
}

void printStudents(FILE *ptr){
    char name[30];
    int no,midGrade;
    if ((ptr = fopen("student","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\nStudents with a midterm grade greater than 50\n");
        printf("%-10s%-13s%s\n","No","Name","Midterm Grade");
        while (!feof(ptr))
        {
            if (midGrade >= 50)
            {
                printf("%-10d%-13s%d\n",no,name,midGrade);  
            }
            fscanf(ptr,"%d%s%d",&no,name,&midGrade);      
        }
        fclose(ptr);
    }
}

int findAverage(FILE *ptr){
    char name[30];
    int no,midGrade=0,sum=0,counter=0;
    if ((ptr = fopen("student","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        fscanf(ptr,"%d%s%d",&no,name,&midGrade);
        while (!feof(ptr))
        { 
            sum+=midGrade;
            counter++; 
            fscanf(ptr,"%d%s%d",&no,name,&midGrade);    
        }
        fclose(ptr);
    }
    return sum/counter;
}