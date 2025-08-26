#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 50

void insertionsort(int arr[], int dim){
    for(int i =1; i<dim; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }else{
                break;
            }
        }
    }
}
void selectionsort(int arr[], int dim){
    for(int i =0; i<dim-1; i++){
        int min=i;
        for(int j =i+1; j<dim; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min !=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        
        }
    }
}
void bubblesort(int arr[], int dim){
    for(int i =0; i<dim-1; i++){
        bool scambio=false;
        for(int j=0; j<dim-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[+1];
                arr[j+1]=temp;
                scambio=true;
            }
        }
        if(!scambio){
            break;
        }
    }
}
void stampaArray(int arr[], int dim){
    for(int i = 0; i<dim; i++){
        cout<<"["<<arr[i]<<"] ";
    }
    cout<<endl<<endl;
}
int main(){
    int arr[MAX];

    int dim;
    int scelta;

    srand(time(0));
        cout<<"inserisci la dimensione: ";
        cin>>dim;

        //popolamento
        for(int i=0; i<dim; i++){
            arr[i]=rand()%20+1;
        }
        stampaArray(arr,dim);

    do{
        cout << "----------menu----------\n";
        cout << "1. INSERTION Sort" << endl;
        cout << "2. SELECTION Sort" << endl;
        cout << "3. BUBBLE Sort"  << endl;
        cout << "------------------------\n";
        cout << "   scelta: "; 
        cin >> scelta;
        cout << "------------------------\n";
        
        switch(scelta){
            // insertion sort
            case 1:
            insertionsort(arr, dim);
            stampaArray(arr, dim);
                break;
            // selection sort
            case 2:
            selectionsort(arr, dim);
            stampaArray(arr, dim);
                break;
            // bubble sort
            case 3:
            bubblesort(arr, dim);
            stampaArray(arr, dim);
                break;
            case 0:cout<<"uscita dal programma!!";
                break;
            default:cout<<"scelta non valida!!";
        }
    }while(scelta !=0);


    return 0;
}