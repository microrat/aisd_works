#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;





class Node{
public:

    int key;
    int value;
    Node* next;

    Node(int temp){next=NULL;value=temp;}

    void setKey(int key){this->key=key;}
    int getKey(){return key;}
    void setValue(int val){value=val;}
    int getValue(){return value;}
    void setNext(Node *x){next=x;}
    Node* getNext(){return next;}
};

const int SIZE = 10;
class hashTable{
private:
    Node* data[SIZE];
public:
    hashTable(){
        for ( int i = 0; i < SIZE; i++ )
    {
        data[i] = NULL;
    }
    }
    int chainHash(int num,int size){return num%size;}

    void insert(int key,int val){
    if(data[key]==NULL){

        data[key] = new Node(val);

    }
    else
    {

        Node* temp = data[key];

        while (temp->getNext() != NULL)
        {

            temp = temp->getNext();
        }

        Node* newEntry = new Node(val);
        temp->setNext(newEntry) ;




    }
    }
    void printTable(){
     for ( int i = 0; i < SIZE; i++ )
    {
        Node* temp = data[i];

        while (temp!=NULL)
        {

            cout << temp->getValue()<<" ";
            temp = temp->getNext();

        }
        cout<<endl;
    }
    }
};

const int sizearr=30;

int main()
{
    srand ( time(0) );
    hashTable theChain;
    int arr[sizearr]  ;
    
    for (int i=0; i<sizearr; i++)
    arr[i] = rand() % 100;   

    for ( int i = 0; i < sizearr; i++ )
    {
        int arrHash = theChain.chainHash(arr[i],SIZE);
        theChain.insert(arrHash,arr[i]);

    }
    theChain.printTable();

    getch();
    return 0;
}

