#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
Node *head;

void InsertDepan(Node *temp, int x){
    temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void InsertBelakang(Node *temp, int x){
    Node *tail;
    tail = head;
    if(head != NULL){
        InsertDepan(temp, x);
    }
    else {
        while(tail -> next != NULL){
            tail = tail -> next;
        }
        temp = new Node();
        temp -> data = x;
        temp -> next = NULL;
        tail -> next = temp;
        tail = temp;
    }
}

void InsertN(Node *temp, int x, int pos){
    Node *bantu;
    if(pos == 1){
        temp = new Node();
        temp -> data = x;
        temp -> next = head;
        head = temp;
    }
    else {
        bantu = head;
        for(int i = 0; i < pos - 2; i++){
            bantu = bantu -> next;
        }
        temp = new Node();
        temp -> data = x;
        temp -> next = bantu -> next;
        bantu -> next = temp;
    }
}

void HapusPosisi(Node *temp, int x){
    temp = head;
    while(temp != NULL){
        if(temp -> data = x){
            if(temp == head){
                Node *del;
                del = head;
                head = head -> next;
                del -> next = NULL;
                free(del);
            }
            else{
                Node *pretemp;
                pretemp = temp;
                pretemp -> next = temp -> next;
                temp -> next = NULL;
            }
            free(temp);
        }
        else{
            Node *pretemp;
            pretemp -> next = temp -> next;
            temp -> next = NULL;
        }
    }
}

void HapusDepan(Node *temp){
    Node *del;
    del = head;
    head = head -> next;
    del -> next = NULL;
    free(del);
}

void HapusBelakang(Node *temp){
    Node *del;
    Node *predel;
    while(del -> next != NULL){
        predel = del;
        del = del -> next;
    }
    predel -> next = NULL;
    free(del);
}

void cetak(Node *temp){
    temp = head;
    while(temp != NULL){
        cout << temp -> data << "-";
        temp = temp -> next;
    }
}

int main()
{
    return 0;
}
