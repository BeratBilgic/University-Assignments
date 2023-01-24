#include <iostream>
#include <string>

using namespace std;

class Patient{
public:
    string name;
    string surname;
    int priority;
    Patient(string name,string surname,int priority){ 
        this->name=name;
        this->surname=surname;
        this->priority=priority;
    }
};

class QueueNode{
public:
    Patient* data;
    QueueNode* next; 
    QueueNode(Patient *newNode){
        data = newNode;
    }         
};

class Queue{
public:
    QueueNode* head;
    Queue(){
        head = NULL;
    }
    void insert(Patient *newPatient){
        if(head==NULL){
            head = new QueueNode(newPatient);
            head->next = head; 
        }
        else if(head->data->priority < newPatient->priority){
            QueueNode *iter = head;
            QueueNode *newNode = new QueueNode(newPatient);
            newNode->next = head;

            while(iter->next != head)
                iter = iter->next;

            iter->next = newNode;
            head = newNode;
        }else{
            QueueNode *iter=head;
            QueueNode *temp;
            while(iter->next!=head && iter->next->data->priority > newPatient->priority){                
                iter=iter->next;
            }    

            if(iter!=head && iter->data->priority < newPatient->priority)
                iter= iter->next;

            temp=iter->next;
            iter->next=new QueueNode(newPatient);
            iter->next->next = temp; 
        }
    }
    Patient* deletePQ(){
        if(head==NULL)
            return NULL;
        else if(head->next==head){
            Patient* temp = head->data;
            free(head);
            head=NULL;
            return temp;
        }else{
            QueueNode *deleteNode=head, *iter=head;
            Patient* temp = head->data;

            while (iter->next != head){
                iter = iter->next;
            } 

            head=head->next;
            iter->next = head;
            free(deleteNode);

            return temp;
        }
    }

    void printPQ(){
        QueueNode *iter = head;
        if (head == NULL){
            cout << "\nPriority queue is empty" << endl; 
            return;
        }
        
        cout << "\nPatient Queue" << endl;
        do{
            cout << iter->data->priority << " - " << iter->data->name << " - " << iter->data->surname << endl; 
            iter = iter->next;
        } while (iter != head);
        cout << endl; 
    }

    void insertExamples(){
        insert(new Patient("name4","surnam4",40));
        insert(new Patient("name2","surnam2",20));
        insert(new Patient("name6","surnam6",60));
        insert(new Patient("name5","surnam5",50));
        insert(new Patient("name8","surnam8",80));
        insert(new Patient("name1","surnam1",10));
        insert(new Patient("name3","surnam3",30));
        insert(new Patient("name7","surnam7",70));
    }
};

int main(){
    Queue que=Queue();
    int key,loop=1,priority;
    string name, surname;
    Patient *p;
    
    while (loop)
    {
        cout <<"\n-1 - insertExamples\n1 - insert\n2 - display\n3 - deletePQ\n0 - Exit"<< endl;
        cin>>key;
        switch (key)
        {
        case -1:
            que.insertExamples();
            break;
        case 1:
            cout<< "Priority :";
            cin >> priority;
            cout << "Name :";
            cin >> name;
            cout << "Surname :";
            cin >> surname;
            p = new Patient(name, surname, priority);
            que.insert(p);
            break;
        case 2:
            que.printPQ();
            break;
        case 3:
            p = que.deletePQ();
            cout << "\n" << p->name << " - " << p->surname << " - " << p->priority << endl;     
            break;
        case 0:
            loop = 0;
            break;
        }
    }

    return 0;
}

            