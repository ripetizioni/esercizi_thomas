#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void stampaArray(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void scambioSpeciale(int arr[], int n, int posizioneElemento) {
    if (posizioneElemento < 0 || posizioneElemento >= n) {
        cout << "Posizione non valida!" << endl;
        return;
    }
    
    // Se l'elemento è già all'ultima posizione, non fare nulla
    if (posizioneElemento == n - 1) {
        cout << "L'elemento è già all'ultima posizione!" << endl;
        return;
    }
    
    cout << "\n--- Inizio scambio speciale ---" << endl;
    stampaArray(arr, n);
    
    int elementoScelto = arr[posizioneElemento];
    int ultimoElemento = arr[n - 1];
    int posizioneOriginale = posizioneElemento;
    
    cout << "Elemento scelto: " << elementoScelto << " (posizione " << posizioneElemento << ")" << endl;
    cout << "Ultimo elemento: " << ultimoElemento << " (posizione " << n-1 << ")" << endl;
    
    // Fase 1: L'elemento scelto si sposta verso destra una posizione alla volta
    cout << "\n--- Fase 1: Spostamento dell'elemento scelto verso destra ---" << endl;
    for (int i = posizioneElemento; i < n - 1; i++) {
        // Scambia con l'elemento successivo
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        
        cout << "Scambio posizione " << i << " con posizione " << i+1 << ": ";
        stampaArray(arr, n);
    }
    
    // Fase 2: L'ultimo elemento originale si sposta verso sinistra una posizione alla volta
    cout << "\n--- Fase 2: Spostamento dell'ultimo elemento originale verso sinistra ---" << endl;
    for (int i = n - 2; i >= posizioneOriginale; i--) {
        // Scambia con l'elemento precedente
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        
        cout << "Scambio posizione " << i+1 << " con posizione " << i << ": ";
        stampaArray(arr, n);
    }
    
    cout << "\n--- Fine scambio speciale ---" << endl;
}

int main() {
    // Inizializza il generatore di numeri casuali
    srand(time(0));
    
    int n;
    
    cout << "Inserisci il numero di elementi dell'array: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Il numero di elementi deve essere positivo!" << endl;
        return 1;
    }
    
    int* arr = new int[n];
    
    // Riempie l'array con numeri casuali da 1 a 100
    cout << "Riempimento array con numeri casuali..." << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;  // Numeri casuali da 1 a 100
    }
    
    cout << "\nArray iniziale:" << endl;
    stampaArray(arr, n);
    
    int posizione;
    cout << "\nInserisci la posizione dell'elemento da spostare alla fine (0-" << n-1 << "): ";
    cin >> posizione;
    
    scambioSpeciale(arr, n, posizione);
    
    cout << "\nArray finale:" << endl;
    stampaArray(arr, n);
    
    delete[] arr;
    return 0;
}
