#include <iostream>
#include <string>
#define MAX 50

using namespace std;

struct s_ordine {
    int    codiceOrdine;
    string codiceCliente;
    float  totaleFattura;
    bool   pagato;
    bool   spedito;
}; 

// Funzione 1
void inserimento(s_ordine elenco[], int &dim) {
    if (dim >= MAX) {
        cout << "Limite massimo raggiunto!" << endl;
        return;
    }
    s_ordine nuovo;
    cout << "Codice ordine: ";
    cin >> nuovo.codiceOrdine;
    cout << "Codice cliente: ";
    cin >> nuovo.codiceCliente;
    cout << "Totale fattura: ";
    cin >> nuovo.totaleFattura;
    cout << "Pagato (0=falso, 1=vero): ";
    cin >> nuovo.pagato;
    cout << "Spedito (0=falso, 1=vero): ";
    cin >> nuovo.spedito;

    elenco[dim++] = nuovo;
    cout << "Dati inseriti!" << endl;
}

// Funzione 6
void stampa(s_ordine elenco[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Codice ordine: " << elenco[i].codiceOrdine << endl;
        cout << "Codice cliente: " << elenco[i].codiceCliente << endl;
        cout << "Totale fattura: " << elenco[i].totaleFattura << endl;
        cout << "Pagato: " << (elenco[i].pagato ? "vero" : "falso") << endl;
        cout << "Spedito: " << (elenco[i].spedito ? "vero" : "falso") << endl << endl;
    }
}

// Funzione 2
float ricercaTotale(s_ordine elenco[], int dim, int codiceOrdine) {
    for (int i = 0; i < dim; i++) {
        if (elenco[i].codiceOrdine == codiceOrdine) {
            return elenco[i].totaleFattura;
        }
    }
    return -1;
}

// Funzione di stampa 
void stampaID(s_ordine elenco[], int j) {
    cout << "Codice ordine: " << elenco[j].codiceOrdine << endl;
    cout << "Codice cliente: " << elenco[j].codiceCliente << endl;
    cout << "Totale fattura: " << elenco[j].totaleFattura << endl;
    cout << "Pagato: " << (elenco[j].pagato ? "vero" : "falso") << endl;
    cout << "Spedito: " << (elenco[j].spedito ? "vero" : "falso") << endl << endl;
}

// Funzione 3
void visualizzaDaSpedire(s_ordine elenco[], int dim) {
    for (int i = 0; i < dim; i++) {
        if (!elenco[i].spedito) {
            stampaID(elenco, i);
        }
    }
}

// Funzione 4
float totaleCliente(s_ordine elenco[], int dim, string codiceCliente) {
    float totale = 0;
    for (int i = 0; i < dim; i++) {
        if (elenco[i].codiceCliente == codiceCliente && !elenco[i].pagato) {
            totale += elenco[i].totaleFattura;
        }
    }
    return totale;
}

// Funzione 5
bool elimina(s_ordine elenco[], int &dim, int codice) {
    for (int i = 0; i < dim; i++) {
        if (elenco[i].codiceOrdine == codice) {
            for (int j = i; j < dim - 1; j++) {
                elenco[j] = elenco[j + 1];
            }
            dim--;
            return true;
        }
    }
    return false;
}

// MAIN
int main() {
    int scelta;
    s_ordine elencoOrdini[MAX];
    int dimensione = 0;

    do {
        cout << "\n=== GESTIONE ORDINI ===" << endl;
        cout << "1. Inserimento ordine" << endl;
        cout << "2. Ricerca totale per codice ordine" << endl;
        cout << "3. Visualizza ordini da spedire" << endl;
        cout << "4. Totale cliente (non pagati)" << endl;
        cout << "5. Elimina ordine" << endl;
        cout << "6. Stampa lista completa ordini" << endl;
        cout << "0. Esci" << endl;
        cout << "Scegli un'opzione: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                inserimento(elencoOrdini, dimensione);
                break;
            case 2: {
                int codice;
                cout << "Inserisci il codice ordine da cercare: ";
                cin >> codice;
                float totale = ricercaTotale(elencoOrdini, dimensione, codice);
                if (totale >= 0) {
                    cout << "Totale fattura ordine " << codice << ": " << totale << endl;
                } else {
                    cout << "Ordine non trovato." << endl;
                }
                break;
            }
            case 3:
                visualizzaDaSpedire(elencoOrdini, dimensione);
                break;
            case 4: {
                string cliente;
                cout << "Inserisci codice cliente: ";
                cin >> cliente;
                float totale = totaleCliente(elencoOrdini, dimensione, cliente);
                cout << "Totale da pagare per cliente " << cliente << ": " << totale << endl;
                break;
            }
            case 5: {
                int codice;
                cout << "Inserisci codice ordine da eliminare: ";
                cin >> codice;
                if (elimina(elencoOrdini, dimensione, codice)) {
                    cout << "Ordine eliminato con successo." << endl;
                } else {
                    cout << "Ordine non trovato." << endl;
                }
                break;
            }
            case 6:
                stampa(elencoOrdini, dimensione);
                break;
            case 0:
                cout << "Uscita dal programma!" << endl;
                break;
            default:
                cout << "Scelta non valida!" << endl;
        }
    } while (scelta != 0);

    return 0;
}
