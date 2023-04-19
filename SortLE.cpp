#include <iostream>
using namespace std;

template <class T>
struct nodo
{
    T valor[3];
    nodo* next;
    nodo()
    {
        next = nullptr;
    }
};


template<class T>
struct SortLeX
{
    nodo<T>* head = nullptr;
    int nro_elementos = 0; //cantidad de elementos en la estructura
    ~SortLeX()
    {
        nodo<T>* tmp;

        while (head)
        {
            tmp = head;
            head = tmp->next;
            //cout << "Destruyendo " << tmp->valor << endl;
            delete tmp;
        }
    };
    void add(T v);
    void print();
    bool find(T v, nodo<T>*& pos, int& recorridos); //pos - posición del nodo, recorridos - items recorridos
};

template<class T>
void SortLeX<T>::print()
{
    int cont = 0;
    cout << "Head->";
    for (nodo<T>* p = head; p; p = p->next)
    {
       for(int i=0; i<3 && cont < nro_elementos; i++,cont++)
        cout << p->valor[i]<< "->";
    }
    cout << "NULL" << endl;
}
template<class T>
bool SortLeX<T>::find(T v, nodo<T>*& pos,int& recorridos)
{
     //TO DO
}

template<class T>
void SortLeX<T>::add(T v)
{
   //TO DO
}



int main() {
    SortLeX<int> lista;
    int Entrada[10] = { 5, 1, 6, 3, 9 , 2, 4, 8, 10, 7 };

    lista.print();
    for (int i = 0; i < 10; i++)
        lista.add(Entrada[i]);
    lista.print();
   
    return 0;
}
