#include <iostream>

using namespace std;

class PILA
{
    int A[10];
    int *I=A, *f=A+9, *TOP=NULL;

    public:

    void add(int x)
    {
        if(TOP)
        {
            if(TOP<f)
            {
                TOP++;
                *TOP=x;
            }
            else {
                cout << "Pila llena" << endl;
            }
        } else {
            TOP = I;
            *TOP = x;
        }
    }

    int pop()
    {
        int tmp = 0;
        if(TOP)
        {
            tmp = *TOP;
            TOP--; 
            if(TOP<I)
                TOP = NULL;   
        }
        else {
            cout << "Pila vacia";
        }
        return tmp;
    }
};


int main(){

    PILA p;
    p.add(10);
    p.add(20);
    p.add(30);
    p.add(40);
    p.add(50);
    p.add(60);
    p.add(70);
    p.add(80);
    
    

    int x = p.pop();
    cout << x << endl;

    /*while(true){
        int x = p.pop();
        if(x != 0){
            cout << x << " ";
        } else {
            break;
        }
    }*/



    return 0;
}