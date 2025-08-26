//Realizzare un programma in c++ che chieda in input un numero e dica all'utente se
//il numero è pari o dispari.


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX 100
int main(){

    int arr[MAX];

    int dim=10;
    srand(time(0));

    for(int i =0; i<dim; i++){
        arr[i]=rand()%(99-10+1)+10;
    }

    for(int i =0; i<dim; i++){
        cout<<"["<<arr[i]<<"] ";
   }
   cout<<endl;


    for(int i=0; i<dim; i++){
        if(arr[i]%2==0){
            arr[i]=0;
        }
        if(arr[i]%2==1){
            arr[i]=1;
        }
        
    }

    for(int i =0; i<dim; i++){
        cout<<"["<<arr[i]<<"] ";
   }
   cout<<endl;
    return 0;
}