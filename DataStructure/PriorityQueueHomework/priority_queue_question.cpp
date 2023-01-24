#include <stdio.h>

//IMPLEMENT PRİORİTY QUEUE USING LİNKED LISTS. SINGLE OR DOUBLE LINKED LISTS

// PLEASE STUDY AND UNDERSTAND IT, THEN WRİTE IT IN C/C++/PYTHON/JAVA .. PLACES INCOMING PATIENTS IN A CIRCULAR LINKED LIST (OR IF YOU WANT SINGLE LINKED LIST)
// USING PRIORITY QUEUE AND THEN RETRIVES TO INCOMING PATIENTS FROM THE LIST. 

//Öncelik sırası (priority queue), kullanarak gelen hastaları verilen önceliğe göre dairesel bir bağlı listeye (CIRCULAR linked list) yerleştiren
// ve ardından sırayla gelen hastaları listeden alan bir kodu C++ dilinde yazalım.

class Patient{
public:
    string name;
    string surname;
    int priority;
    Patient(string name,string surname,int priority){ //constructor
        this->name=name;
        this->surname=surname;
        this->priority=priority;
    }
};