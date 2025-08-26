#include <iostream>

using namespace std;
#define MAX 100
int main(){
	int fibonacci[MAX];
    int dim;
	
    do{
        cout<<"quanti numeri vuoi stampare: ";
        cin>> dim;
        if(dim>100){
            cout<<"errore dimensione troppo grande"<<en
        }
    }while(dim>100)
   

    fibonacci[0]=0;
    fibonacci[1]=1;

    for(int i =2; i<dim; i++){
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
        cout<<"["<<fibonacci[i]<<"] ";
    }

	return 0;
}