#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define MAX 100
int main(){
	int arr[MAX];
    int dim;
    int p1;
    int temp;

        srand(time(0));
    do{
        cout<<"inserisci la dimensione dell'array: ";
        cin>> dim;
        if(dim>100){
            cout<<"errore dimensione troppo grande"<<endl;
        }
    }while(dim>100)


    for(int i=0; i<dim; i++){
        arr[i]=rand()%50+1;
    }
    for(int i=0; i<dim; i++){
        cout<<"["<<arr[i]<<"] ";
    }
    cout<<endl;

    cout<<"quale posizione vuoi spostare in fondo?: ";
    cin>>p1;

    for(int i =p1; i<dim-1; i++){
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    
    for(int i =dim-1; i>p1; i-- ){
        temp=arr[i-1];
        arr[i-1]=arr[i];
        arr[i]=temp;
    }

    for(int i=0; i<dim; i++){
        cout<<"["<<arr[i]<<"] ";
    }
    cout<<endl;
	return 0;
}