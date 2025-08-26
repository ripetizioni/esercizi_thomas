#include <iostream>
using namespace std;

#define MAX 20

void visualizza(int arr[], int n) {
    if (n == 0) {
        cout << "Array vuoto!\n";
        return;
    }
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inserisciCoda(int arr[], int &n) {
    if (n < MAX) {
        int valore;
        cout << "Inserisci valore: ";
        cin >> valore;
        arr[n++] = valore;
    } else cout << "Array pieno!" << endl;
}

void cancellaCoda(int &n) {
    if (n > 0) {
        n--;
        cout << "Elemento in coda eliminato." << endl;
    } else cout << "Array vuoto!" << endl;
}

void modificaElemento(int arr[], int n) {
    int pos, valore;
    cout << "Posizione (0-" << n - 1 << "): ";
    cin >> pos;
    if (pos >= 0 && pos < n) {
        cout << "Nuovo valore: ";
        cin >> valore;
        arr[pos] = valore;
    } else cout << "Posizione non valida." << endl;
}

void ricercaValore(int arr[], int n) {
    int valore;
    cout << "Valore da cercare: ";
    cin >> valore;
    bool trovato = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == valore) {
            cout << "Trovato in posizione " << i << endl;
            trovato = true;
        }
    }
    if (!trovato) cout << "Valore non presente." << endl;
}

void massimo(int arr[], int n) {
    if (n == 0) {
        cout << "Array vuoto!\n";
        return;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Massimo = " << max << endl;
}

void inserisciPosizione(int arr[], int &n) {
    if (n < MAX) {
        int pos, valore;
        cout << "Posizione (0-" << n << "): ";
        cin >> pos;
        if (pos >= 0 && pos <= n) {
            cout << "Valore: ";
            cin >> valore;
            for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
            arr[pos] = valore;
            n++;
        } else cout << "Posizione non valida." << endl;
    } else cout << "Array pieno!" << endl;
}

void cancellaPosizione(int arr[], int &n) {
    int pos;
    cout << "Posizione (0-" << n - 1 << "): ";
    cin >> pos;
    if (pos >= 0 && pos < n) {
        for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
        n--;
        cout << "Elemento eliminato." << endl;
    } else cout << "Posizione non valida." << endl;
}

void cancellaValore(int arr[], int &n) {
    int valore;
    cout << "Valore da cancellare: ";
    cin >> valore;
    bool trovato = false;
    for (int i = 0; i < n; ) {
        if (arr[i] == valore) {
            for (int j = i; j < n - 1; j++) arr[j] = arr[j + 1];
            n--;
            trovato = true;
        } else {
            i++;
        }
    }
    if (trovato) cout << "Tutte le occorrenze eliminate." << endl;
    else cout << "Valore non trovato." << endl;
}

int main() {
    int arr[MAX], n = 0;
    int scelta;

    do {
        cout << "\n--- MENU ---\n";
        cout << "  1 -- INIZIALIZZAZIONE dell'array" << endl;
        cout << "  2 -- INSERIMENTO elemento IN CODA all'array" << endl;
        cout << "  3 -- CANCELLAZIONE elemento in coda all'array" << endl;
        cout << "  4 -- MODIFICA di un elemento nell'array (posizione nota)" << endl;
        cout << "  5 -- RICERCA di un valore nell'array" << endl;
        cout << "  6 -- RICERCA MAX elemento nell'array" << endl;
        cout << "  7 -- INSERIMENTO in POSIZ data (se possibile)" << endl;
        cout << "  8 -- CANCELLAZIONE da POSIZ data" << endl;
        cout << "  9 -- CANCELLAZIONE di VALORE dato" << endl;
        cout << " 10 -- VISUALIZZAZIONE di tutti gli elementi dell'array" << endl;
        cout << "  0 -- USCITA" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                n = 0;
                cout << "Array inizializzato." << endl;
                break;
            case 2: inserisciCoda(arr, n); break;
            case 3: cancellaCoda(n); break;
            case 4: modificaElemento(arr, n); break;
            case 5: ricercaValore(arr, n); break;
            case 6: massimo(arr, n); break;
            case 7: inserisciPosizione(arr, n); break;
            case 8: cancellaPosizione(arr, n); break;
            case 9: cancellaValore(arr, n); break;
            case 10: visualizza(arr, n); break;
            case 0: cout << "Uscita..." << endl; break;
            default: cout << "Scelta non valida!" << endl;
        }
    } while (scelta != 0);

    return 0;
}
