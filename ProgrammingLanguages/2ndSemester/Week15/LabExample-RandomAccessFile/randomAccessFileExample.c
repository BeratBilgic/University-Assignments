#include <stdio.h>
#include <string.h>

struct student 
{
    int no;
    char name[30],department[30];
};
typedef struct student students;

void createStudentFile(FILE *ptr);
void addNewRecord(FILE *ptr);
void printStudents(FILE *ptr);
void findByNo(FILE *ptr);

int main(){
    int loop = 1,key;
    FILE *mfPtr;
    while(loop){
        printf("\n1 - Create Student File\n2 - List whole file content \n");
        printf("3 - List single line according to no\n4 - Add new record or update record\n");
        printf("0 - Exit\n");
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
            findByNo(mfPtr);
            break;
        case 4:
            addNewRecord(mfPtr);
            break;
        default:
            loop = 0;
            break;
        }
    }

    return 0;
}

void createStudentFile(FILE *ptr){
    students student = {0,"",""};
    int n;
    if ((ptr = fopen("students","w")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("How many null records you would like to insert ? \n");
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
            fwrite(&student, sizeof(student), 1, ptr);
        }
        
        fclose(ptr);
    }
}

void printStudents(FILE *ptr){
    students student = {0,"",""};
    if ((ptr = fopen("students","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-10s%-13s%s\n","No","Name","Departmant");
        
        while (!feof(ptr))
        {
            fread(&student, sizeof(students),1,ptr);
            if (student.no != 0)
            {
                printf("%-10d%-13s%s\n",student.no,student.name,student.department);  
            }
        }
        fclose(ptr);
    }
}

void findByNo(FILE *ptr){
    students student = {0,"",""};
    int no;
    if ((ptr = fopen("students","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("Student No = ");
        scanf("%d",&no);
        printf("\n%-10s%-13s%s\n","No","Name","Departmant");
        
        while (!feof(ptr))
        {
            fread(&student, sizeof(students),1,ptr);
            if (student.no != 0 && student.no == no)
            {
                printf("%-10d%-13s%s\n",student.no,student.name,student.department);  
            }
        }
        fclose(ptr);
    }
}

void addNewRecord(FILE *ptr){
    students student = {0,"",""};
    if ((ptr = fopen("students","r+")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("Enter the no, name and departmant[0-Exit]\n");
        scanf("%d",&student.no);
        while (student.no != 0)
        {
            scanf("%s%s",student.name,student.department);
            fseek(ptr, (student.no-1)*sizeof(students),SEEK_SET);
            fwrite(&student, sizeof(students),1,ptr);

            printf("Enter the no, name and departmant[0-Exit]\n");
            scanf("%d",&student.no);
        }
        
        fclose(ptr);
    }
}
