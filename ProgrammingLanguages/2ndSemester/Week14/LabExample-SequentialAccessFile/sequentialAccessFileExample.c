#include <stdio.h>
#include <string.h>

void createStudentFile(FILE *ptr);
void addNewRecord(FILE *ptr);
void printStudents(FILE *ptr);
void findByName(FILE *ptr);
//void updateRecord(FILE *ptr);

int main(){
    int loop = 1,key;
    FILE *mfPtr;
    while(loop){
        printf("\n1 - Create Student File\n2 - List whole file content \n");
        printf("3 - List single line according to name\n4 - Add new record at the end\n");
        //printf("5 - Update a record\n");
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
            findByName(mfPtr);
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
    char name[30],department[50];
    int no,n;
    if ((ptr = fopen("students","w")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("How many records you would like to insert ? \n");
        scanf("%d",&n);
        printf("Enter the no, name, and departmant.\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%d%29s%s",&no,name,department);
            fprintf(ptr,"%d %s %s\n",no,name,department);
        }
        
        fclose(ptr);
    }
}

void printStudents(FILE *ptr){
    char name[30],department[50];
    int no;
    if ((ptr = fopen("students","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-10s%-13s%s\n","No","Name","Departmant");
        fscanf(ptr,"%d%s%s",&no,name,department);  
        while (!feof(ptr))
        {
            printf("%-10d%-13s%s\n",no,name,department);  
            fscanf(ptr,"%d%s%s",&no,name,department);      
        }
        fclose(ptr);
    }
}

void findByName(FILE *ptr){
    char name[30],department[50],inputName[30];
    int no;
    printf("Student Name = ");
    scanf("%s",inputName);
    if ((ptr = fopen("students","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-10s%-13s%s\n","No","Name","Departmant");
        while (!feof(ptr))
        {
            if (strcmp(name,inputName) == 0)
            {
                printf("%-10d%-13s%s\n",no,name,department); 
            }
            fscanf(ptr,"%d%s%s",&no,name,department);      
        }
        fclose(ptr);
    }
}

void addNewRecord(FILE *ptr){
    char name[30],department[50];
    int no,n;
    if ((ptr = fopen("students","a+")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("How many new records you would like to insert ? \n");
        scanf("%d",&n);
        printf("Enter the no, name, and departmant.\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%d%29s%s",&no,name,department);
            fprintf(ptr,"%d %s %s\n",no,name,department);
        }
        
        fclose(ptr);
    }
}
