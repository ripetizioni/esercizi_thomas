//insertion,selection, bubble

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define MAX 100

void stampArray(int arr[], int dim){
    for(int i =0; i<dim; i++){
        cout<<"["<<arr[i]<<" ]";
    }
    cout<<endl;
}

/*
    Come funziona:
    - Considera il primo elemento come già ordinato
    - Prende il secondo elemento e lo inserisce nella posizione corretta rispetto al primo
    - Prende il terzo elemento e lo inserisce nella posizione corretta rispetto ai primi due ordinati
    - Continua così fino alla fine

    Esempio: `[5, 2, 8, 1]`
    - Passo 1: `[5, 2, 8, 1]` → `[2, 5, 8, 1]` (inserisce 2)
    - Passo 2: `[2, 5, 8, 1]` → `[2, 5, 8, 1]` (8 già al posto giusto)
    - Passo 3: `[2, 5, 8, 1]` → `[1, 2, 5, 8]` (inserisce 1 all'inizio)
*/
void insertionSort_wile(int arr[],int dim){
    for(int i =1; i<dim; i++){
        int tmp=arr[i];
        int j= i-1;

        while(j>=0 && arr[j]>tmp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tmp;
    }

}

void insertionSort_for(int arr[],int dim){
    for(int i =1; i<dim; i++){
        for(int j =i; j>0; j--){
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

/*
    Come funziona:
    - Trova l'elemento più piccolo nell'array e lo scambia con il primo
    - Trova l'elemento più piccolo nel resto dell'array e lo scambia con il secondo
    - Continua finché tutto l'array è ordinato

    Esempio: `[5, 2, 8, 1]`
    - Passo 1: Trova min=1, scambia con 5 → `[1, 2, 8, 5]`
    - Passo 2: Trova min=2, già al posto giusto → `[1, 2, 8, 5]`
    - Passo 3: Trova min=5, scambia con 8 → `[1, 2, 5, 8]`

*/
void selectionSort(int arr[], int dim){
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

/*
    Come funziona:
    - Confronta elementi adiacenti e li scambia se sono nell'ordine sbagliato
    - Dopo ogni passata, l'elemento più grande "bolle" verso la fine
    - Ripete finché non ci sono più scambi

    Esempio: `[5, 2, 8, 1]`
    - Passata 1: `[5,2,8,1]` → `[2,5,8,1]` → `[2,5,8,1]` → `[2,5,1,8]`
    - Passata 2: `[2,5,1,8]` → `[2,5,1,8]` → `[2,1,5,8]`
    - Passata 3: `[2,1,5,8]` → `[1,2,5,8]`
*/
void bubbleSort(int arr[], int dim){
    for(int i =0; i<dim - 1; i++){
        bool scambio=false;
        for(int j =0; j <dim-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                scambio=true;
            }
        }

        if(!scambio)
            break;
    }

}

int main(){

    int arr[MAX];
    int dim=6;
    int scelta;

    do{
        for(int i=0; i<dim; i++){
            arr[i]=rand()%20+1;
        }
        stampArray(arr,dim);
        
        cout << "\n--- MENU ORDINAMENTO ---\n";
        cout << "1. Insertion Sort con while\n";
        cout << "2. Insertion Sort con for\n";
        cout << "3. Selection Sort\n";
        cout << "4. Bubble Sort\n";
        cout << "5. uscita dal programma\n";
        cout << "Scegli un'opzione (1-5): ";
        
        cin >> scelta;
        switch (scelta) {
            case 1:
                insertionSort_wile(arr, dim);
                stampArray(arr,dim);
                break;
            case 2:
                insertionSort_for(arr, dim);
                stampArray(arr,dim);
                break;
            case 3:
                selectionSort(arr, dim);
                stampArray(arr,dim);
                break;
            case 4:
                bubbleSort(arr, dim);
                stampArray(arr,dim);
                break;
            case 5:cout<<"uscita dal programma"<<endl;
                break;
            default:
                cout << "Scelta non valida.\n";
        }
    }while(scelta !=5);
    return 0;
}