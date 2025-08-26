/*Realizzare un programma in c++ che stampi in output un conto alla rovescia
partendo da un numero intero chiesto in input all'utente.
L'output dovrà essere del tipo:
## 10 ##
## 9 ##
## 8 ##
....
## 0 ##*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"inserisci un numero da dove far partire il conto alla rovescia: ";
    cin>>n;

    for(int i= n; i>=0; i--){
        cout<<"## "<<i<<" ##"<<endl;
        for(int j=0; j<400000000; j++){
                
        }
    }

    return 0;
}