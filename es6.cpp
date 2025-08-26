//Realizzare un programma in c++ che chieda in input tre numeri interi e ne stampi la
//somma e la media.

#include <iostream>
#define MAX 100
using namespace std;

int main(){
    int num[MAX];
    int dim=10;
    int somma=0;
    float media=1;

    for(int i=0; i<dim; i++){
        cout<<"inserisci il "<<i+1<<"° numero"<<endl;
        cin>>num[i];
    }
    for(int i =0; i<dim; i++){
        somma=somma+num[i];
    }

    media=(float)somma/dim;
    cout<<"la somma e'--> "<<somma<<endl;
    cout<<"la media e'--> "<<media<<endl;

    return 0;
}