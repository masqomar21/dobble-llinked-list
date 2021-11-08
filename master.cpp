#include <iostream>
using namespace std;

struct DataUser
{
    int Nkp;

    DataUser *next, *prev;
};

struct list
{
    DataUser *head, *tail;
};

DataUser *newnode, *cur;

void creat (list *l){
    (*l).head = NULL;
    (*l).tail = NULL;
}

bool cek(list l){
    return (l.head == NULL && l.tail == NULL);
}

void addfirst(list *l, int nomor){
    newnode = new DataUser();

    newnode->Nkp = nomor;
    if (cek(*l)){
        (*l).head = newnode;
        (*l).tail = (*l).head;
    } else {
        newnode->next = (*l).head;
        (*l).head->prev = newnode;
        (*l).head = newnode;
    }
}

void addlast(list *l, int nomor){
    newnode = new DataUser();
    newnode->Nkp = nomor;
    if (cek(*l)){
        addfirst(&(*l), nomor);
    } else {
        (*l).tail->next = newnode;
        newnode->prev = (*l).tail;
        (*l).tail = newnode;
    }
}

void print(list *l){
    cur = (*l).head;
    int step = 1;
    while (cur!= NULL){
        cout << step << " NKP : " << cur->Nkp << endl;
        cur= cur->next;
        step ++;
    }
}


int main(){
    list antrian;

    creat(&antrian);

    addfirst(&antrian, 5);
    addfirst(&antrian, 3);
    addfirst(&antrian, 6);
    addfirst(&antrian, 8);
    addfirst(&antrian, 1);
    addfirst(&antrian, 0);

    print(&antrian);
}
