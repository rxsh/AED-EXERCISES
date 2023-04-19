#include <bits/utility.h>
#include <iostream>

using namespace std;

void merge(int *p, int *q){
    int *f= q + (q-p); // mitad 
    while (p<q && q<f){
        if(*p < *q){
            p++;
        }
        else{
            for(int *r=p; r<q; r++){
                swap(*r,*q);
            }
            p++;
            q++;
        }
    }
}

int main(){
    int arr[10] = {2,12,22,24,32,1,3,21,35,43};

    merge(arr,arr + (sizeof(arr)/sizeof(arr[0]))/2);

    for(int i=0; i<10;i++){
        cout << arr[i] << " ";
    }


    return 0;
}