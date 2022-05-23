#include <stdio.h>
#include <string.h>

struct patient{
    char name[30];
    int age;
    char illnessInfo[50];
};

typedef struct patient patient; 

void addRecord(FILE *ptr);
void findByName(FILE *ptr);
void deleteRecord(FILE *ptr);
void modifyRecord(FILE *ptr);
void printRecords(FILE *ptr);


int main(){
    int loop = 1,key,counter = 0;
    FILE *mfPtr;
    while(loop){
        printf("\n1 - Insert a number of patient\n2 - Find any patient who has got some key data \n");
        printf("3 - Delete a patient record\n4 - Modify a patient record\n");
        printf("5 - List all patients info\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            addRecord(mfPtr);
            break;
        case 2:
            findByName(mfPtr);
            break;
        case 3:
            deleteRecord(mfPtr);
            break;
        case 4:
            modifyRecord(mfPtr);
            break;
        case 5:
            printRecords(mfPtr);
            break;
        default:
            loop = 0;
            break;
        }
    }

    return 0;
}

void addRecord(FILE *ptr){
    patient patient;
    int n;
    if ((ptr = fopen("patients","a+")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("How many records you would like to insert ? \n");
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
            printf("Enter the name, age and illness information\n");
            scanf("%s%d%s",patient.name,&patient.age,patient.illnessInfo);
            fwrite(&patient, sizeof(patient), 1, ptr);
        }
        
        fclose(ptr);
    }
}

void findByName(FILE *ptr){
    int counter = 1;
    char name[30];
    patient patient = {"",0,""};
    if ((ptr = fopen("patients","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("Patient Name = ");
        scanf("%s",name);
        printf("\n%-4s%-12s%-8s%s\n","ID","Name","Age","Illness Information");
        
        fread(&patient, sizeof(patient),1,ptr);
        while (!feof(ptr))
        {
            if (strcmp(name,patient.name) == 0)
            {
                printf("%-4d%-12s%-8d%s\n",counter,patient.name,patient.age,patient.illnessInfo);  
            }
             
            fread(&patient, sizeof(patient),1,ptr);
            counter++;
        }
        fclose(ptr);
    }
}

void deleteRecord(FILE *ptr){
    int id;
    patient patient = {"",0,""};
    if ((ptr = fopen("patients","r+")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("Patient id = ");
        scanf("%d",&id);

        fseek(ptr,(id-1)*sizeof(patient),SEEK_SET);
        fwrite(&patient, sizeof(patient),1,ptr);

        fclose(ptr);
    }
}

void modifyRecord(FILE *ptr){
    int id;
    patient patient = {"",0,""};
    if ((ptr = fopen("patients","r+")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("Patient id = ");
        scanf("%d",&id);

        fseek(ptr,(id-1)*sizeof(patient),SEEK_SET);
        fread(&patient, sizeof(patient),1,ptr);
        fseek(ptr,(id-1)*sizeof(patient),SEEK_SET);
        printf("Enter the name, age and illness information\n");
        scanf("%s%d%s",patient.name,&patient.age,patient.illnessInfo);
        fwrite(&patient, sizeof(patient),1,ptr);

        fclose(ptr);
    }
}

void printRecords(FILE *ptr){
    patient patient = {"",0,""};
    int counter = 1;
    if ((ptr = fopen("patients","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-4s%-12s%-8s%s\n","ID","Name","Age","Illness Information");
        
        fread(&patient, sizeof(patient),1,ptr);
        while (!feof(ptr))
        {   
            if (strcmp(patient.name,"") != 0)
            {
                printf("%-4d%-12s%-8d%s\n",counter,patient.name,patient.age,patient.illnessInfo); 
            }

            fread(&patient, sizeof(patient),1,ptr);
            counter++;
        }
        fclose(ptr);
    }
}
