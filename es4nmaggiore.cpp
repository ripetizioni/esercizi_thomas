#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define MAX 100
int main(){
	int arr[MAX];
    int dim;
    int maggiore;
    int cont=0;

        srand(time(0));
    do{
        cout<<"quanti numeri vuoi stampare: ";
        cin>> dim;
        if(dim>100){
            cout<<"errore dimensione troppo grande"<<endl;
        }
    }while(dim>100);

    for(int i=0; i<dim; i++){
        arr[i]=rand()%50+1;
    }
    for(int i=0; i<dim; i++){
        cout<<"["<<arr[i]<<"] ";
    }
    cout<<endl;

    maggiore=arr[0];
    cont=1;

    for(int i=1; i<dim; i++){
        if(arr[i]>maggiore){
            maggiore=arr[i];
            cont=1;
        }
        else if(arr[i]==maggiore){
            cont++;
        }
        
    }

    cout<<"il numero maggiore dell'array e'--> "<<maggiore<<endl;
    cout<<"il numero maggiore compare "<<cont<<" volte."<<endl;

	return 0;
}