#include <stdio.h>
#include <string.h>

struct patient{
    int id;
    char name[30];
    int age;
    char illnessInfo[50];
};

typedef struct patient patient; 

int addRecord(FILE *ptr, int counter);
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
            counter = addRecord(mfPtr,counter);
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

int addRecord(FILE *ptr, int counter){
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
            counter++;
            patient.id = counter;
            fwrite(&patient, sizeof(patient), 1, ptr);
        }
        
        fclose(ptr);
    }
    return counter;
}

void findByName(FILE *ptr){
    char name[30];
    patient patient = {0,"",0,""};
    if ((ptr = fopen("patients","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("Patient Name = ");
        scanf("%s",name);
        printf("\n%-4s%-13s%-8s%s\n","Id","Name","Age","Illness Information");
        
        fread(&patient, sizeof(patient),1,ptr);
        while (!feof(ptr))
        {
            if (strcmp(name,patient.name) == 0)
            {
                printf("%-4d%-13s%-8d%s\n",patient.id,patient.name,patient.age,patient.illnessInfo);  
            }
             
            fread(&patient, sizeof(patient),1,ptr);
        }
        fclose(ptr);
    }
}

void deleteRecord(FILE *ptr){
    int id;
    patient patient = {0,"",0,""};
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
    patient patient = {0,"",0,""};
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
    patient patient = {0,"",0,""};
    if ((ptr = fopen("patients","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        printf("\n%-4s%-13s%-8s%s\n","Id","Name","Age","Illness Information");
        
        fread(&patient, sizeof(patient),1,ptr);
        while (!feof(ptr))
        {   
            if (patient.id != 0)
            {
                printf("%-4d%-13s%-8d%s\n",patient.id,patient.name,patient.age,patient.illnessInfo);  
            }
            
            fread(&patient, sizeof(patient),1,ptr);
        }
        fclose(ptr);
    }
}
