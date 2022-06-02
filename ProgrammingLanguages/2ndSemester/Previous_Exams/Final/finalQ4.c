#include <stdio.h>

struct student { 
    int number;
    float midterm;
    char name[40]; 
};

typedef struct student student;

void printStudents(FILE *ptr);
void addRecord(FILE *ptr);
void swapRecord(FILE *ptr);

int main(){
    int key,loop=1;
    FILE *mptr;
    
    while (loop)
    {
        printf("\n1-addRecord\n2-printStudents\n3-swapRecord\n0-exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            addRecord(mptr);
            break;
        case 2:
            printStudents(mptr);
            break;
        case 3:
            swapRecord(mptr);
            break;
        default:
            loop = 0;
            break;
        }
    }
    
    return 0;
}

void swapRecord(FILE *ptr){
    int n1, n2;
    student record1 = {0,0,""}, record2 = {0,0,""};
    if ((ptr = fopen("students","r+")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("Enter the values you want to swap. \n");
        printf("The position of the first record :");
        scanf("%d",&n1);
        printf("The position of the second record :");
        scanf("%d",&n2);

        fseek(ptr, (n1-1)*sizeof(student), SEEK_SET);   
        fread(&record1, sizeof(student),1,ptr);
        fseek(ptr, (n2-1)*sizeof(student), SEEK_SET);  
        fread(&record2, sizeof(student),1,ptr);

        fseek(ptr, (n1-1)*sizeof(student), SEEK_SET);  
        fwrite(&record2, sizeof(student), 1, ptr);
        fseek(ptr, (n2-1)*sizeof(student), SEEK_SET);  
        fwrite(&record1, sizeof(student), 1, ptr);

        fclose(ptr);
    }
}

void addRecord(FILE *ptr){
    student stdt = {0,0,""};
    int n;
    if ((ptr = fopen("students","a+")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("How many records you would like to insert ? \n");
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
            printf("Enter the number, midterm and name\n");
            scanf("%d%f%s",&stdt.number,&stdt.midterm,stdt.name);
            fwrite(&stdt, sizeof(student), 1, ptr);
        }
        
        fclose(ptr);
    }
}

void printStudents(FILE *ptr){
    student stdt = {0,0,""};
    if ((ptr = fopen("students","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-10s%-13s%s\n","Number","Midterm","Name");
        fread(&stdt, sizeof(student),1,ptr);

        while (!feof(ptr))
        {
            if (stdt.number != 0)
            {
                printf("%-10d%-13f%s\n",stdt.number,stdt.midterm,stdt.name);  
            }
            fread(&stdt, sizeof(student),1,ptr);
        }
        fclose(ptr);
    }
}