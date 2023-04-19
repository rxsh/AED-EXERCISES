// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

template<class T>
struct nodo{
    T data;
    nodo<T>* next;
    nodo(int d)
    {
        data = d;
        next = NULL;
    }
};
/*
template<class T>
struct stackLE{
    nodo<T>* top = NULL;

    void push(T data){
        nodo<T>* newNodo = new nodo<T>;
        newNodo->data = data;
        newNodo->next = top;

        top = newNodo;
        cout << "Top: " <<top->data << endl;
    }

    void pop(){
        if(top == NULL){
            cout << "stack empty" << endl;
            return;
        }

        nodo<T> *tmp = top;
        top = top->next;
        cout << "Delete: " << tmp->data << endl;
        delete tmp;

    }
};*/

template<class T>
struct queue {
    nodo<T>* head = NULL;
    nodo<T>* tail = NULL;


    void push(T data) {
    
        nodo<T>* tmp = new nodo<T>(data);
        if(tail == nullptr){
            head = tail = nullptr;
            return;
        }

        tail->next = tmp;
        tail = tmp;
        cout << "Add: " << tail->data << endl; 
        }
    
    void pop() {
        if(head == NULL){
            cout << "Queue empty" << endl;
            return;
        }

        nodo<T>* tmp = head;
        head = head -> next;
        cout << "Delete: " << tmp->data << endl;
        delete tmp;
        if(head == nullptr){
            tail = nullptr;
        }
    }
};




int main()
{
    /*
    stackLE<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.pop();
*/
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();

}