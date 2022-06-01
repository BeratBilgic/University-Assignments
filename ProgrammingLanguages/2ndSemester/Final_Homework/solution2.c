#include <stdio.h>
#include <string.h>

struct student
{
    int no;
    char name[32];
    double grade;
};
typedef struct student student;

void createNotlarFile(FILE *ptr);
void printNotlar(FILE *ptr);
void transferRecords(FILE *sePtr, FILE *raPtr);
void printBasari(FILE *ptr);

int main(){
    int loop = 1,key;
    FILE *sePtr,*raPtr;
    while(loop){
        printf("\n1-createNotlarFile(sePtr)\n2-printNotlar(sePtr)\n3-transferRecords(sePtr, raPtr)\n4-printBasari(raPtr)\n0-exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            createNotlarFile(sePtr);
            break;
        case 2:
            printNotlar(sePtr);
            break;
        case 3:
            transferRecords(sePtr, raPtr);
            break;
        case 4:
            printBasari(raPtr);
            break;
        default:
            loop = 0;
            break;
        }
    }

    return 0;
}

void createNotlarFile(FILE *ptr){
    char name[30];
    int no,n;
    double grade;
    if ((ptr = fopen("notlar.txt","w")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("How many records you would like to insert ? \n");
        scanf("%d",&n);
        printf("Enter the no, name, and grade.\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%d%29s%lf",&no,name,&grade);
            fprintf(ptr,"%d %s %lf\n",no,name,grade);
        }
        
        fclose(ptr);
    }
}

void printNotlar(FILE *ptr){
    char name[30];
    int no;
    double grade;
    if ((ptr = fopen("notlar.txt","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-10s%-13s%s\n","No","Name","Grade");
        fscanf(ptr,"%d%s%lf",&no,name,&grade);  
        while (!feof(ptr))
        {
            printf("%-10d%-13s%lf\n",no,name,grade);  
            fscanf(ptr,"%d%s%lf",&no,name,&grade);      
        }
        fclose(ptr);
    }
}

void transferRecords(FILE *sePtr, FILE *raPtr){
    char name[30];
    int no;
    double grade;
    student stdt = {0,"",0};
    if ((sePtr = fopen("notlar.txt","r")) == NULL 
            || (raPtr = fopen("basari.dat","w")) == NULL )
    {
        printf("File could not be opened\n");
    }else
    {
        fscanf(sePtr,"%d%s%lf",&no,name,&grade);  
        while (!feof(sePtr))
        {
            if (grade >= 60 && (strcmp(name,"Ahmet") == 0 
                || strcmp(name,"ahmet") == 0))
            {
                stdt.no = no;
                strcpy(stdt.name, name);
                stdt.grade = grade;
                fwrite(&stdt, sizeof(student),1,raPtr);
            }
            
            fscanf(sePtr,"%d%s%lf",&no,name,&grade);      
        }
        fclose(sePtr);
        fclose(raPtr);
    }
}

void printBasari(FILE *ptr){
    student stdt = {0,"",0};
    if ((ptr = fopen("basari.dat","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-10s%-13s%s\n","No","Name","Grade");

        fread(&stdt, sizeof(student),1,ptr);
        while (!feof(ptr))
        {
            if (stdt.no != 0)
            {
                printf("%-10d%-13s%lf\n",stdt.no,stdt.name,stdt.grade);  
            }
            fread(&stdt, sizeof(student),1,ptr);
        }
        fclose(ptr);
    }
}