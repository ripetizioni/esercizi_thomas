#include <iostream>
#include <string>

using namespace std;

#define MAX 100

struct s_giacenze {
    int codiceProdotto;
    string descrizioneProdotto;
    string coloreProdotto;
    int quantita;
};

// 1
bool ricerca(s_giacenze v[], int ll, int codice, int& pos) {
    int inizio = 0;
    int fine = ll - 1;
    while (inizio <= fine) {
        int medio = (inizio + fine) / 2;
        if (v[medio].codiceProdotto == codice) {
            pos = medio;
            return true;
        } else if (v[medio].codiceProdotto < codice) {
            inizio = medio + 1;
        } else {
            fine = medio - 1;
        }
    }
    pos = inizio;
    return false;
}

// 2
int inserimento(s_giacenze v[], int ll, int lf, s_giacenze x) {
    int pos;
    if (ll >= lf) {
        cout << "errore magazzino pieno!!" << endl;
        return ll;
    }
    if (ricerca(v, ll, x.codiceProdotto, pos)) {
        cout << "errore: codice gia presente!!" << endl;
        return ll;
    }
    for (int i = ll; i > pos; i--) {
        v[i] = v[i - 1];
    }
    v[pos] = x;
    return ll + 1;
}

// 3
bool addQuantita(s_giacenze v[], int ll, int codice, int quant) {
    int pos;
    if (ricerca(v, ll, codice, pos)) {
        v[pos].quantita += quant;
        return true;
    }
    return false;
}

// 4
bool subQuantita(s_giacenze v[], int ll, int codice, int quant) {
    int pos;
    if (ricerca(v, ll, codice, pos)) {
        if (v[pos].quantita >= quant) {
            v[pos].quantita -= quant;
            return true;
        }
    }
    return false;
}

// 5
void inserisciProdotto(s_giacenze v[], int& ll, int lf) {
    if (ll >= lf) {
        cout << "errore  magazzino pieno!!\n";
        return;
    }
    s_giacenze nuovo;
    cout << "inserisci codice prodotto: ";
    cin >> nuovo.codiceProdotto;
    cout << "descrizione: ";
    cin.ignore();
    getline(cin, nuovo.descrizioneProdotto);
    cout << "colore: ";
    getline(cin, nuovo.coloreProdotto);
    cout << "quantita: ";
    cin >> nuovo.quantita;

    int nuovaLunghezza = inserimento(v, ll, lf, nuovo);

    if (nuovaLunghezza == ll) {
        cout << "prodotto gia esistente, inserimento non effettuato!!\n";
    } else {
        ll = nuovaLunghezza;
        cout << "prodotto inserito correttamente!!\n";
    }
}

// 6
void stampaMagazzino(s_giacenze v[], int ll) {
    cout << "------MAGAZZINO------" << endl;
    for (int i = 0; i < ll; i++) {
        cout << "codice: " << v[i].codiceProdotto << endl;
        cout << "descrizione: " << v[i].descrizioneProdotto << endl;
        cout << "colore: " << v[i].coloreProdotto << endl;
        cout << "quantita: " << v[i].quantita << endl << endl;
    }
}

void cercaEStamapaProdotto(s_giacenze v[], int ll) {
    int codice, pos;
    cout << "inserisci codice prodotto da cercare: ";
    cin >> codice;
    if (ricerca(v, ll, codice, pos)) {
        cout << "------prodotto trovato: ------" << endl;
        cout << "codice:      " << v[pos].codiceProdotto << endl;
        cout << "descrizione: " << v[pos].descrizioneProdotto << endl;
        cout << "colore:      " << v[pos].coloreProdotto << endl;
        cout << "quantita:    " << v[pos].quantita << endl << endl;
    } else {
        cout << "prodotto non trovato!!" << endl;
    }
}

int main() {
    int scelta;
    s_giacenze magazzino[MAX];
    int dim = 0;

    do {
        cout << "----menu---------------------" << endl;
        cout << "1 - INSERIMENTO" << endl;
        cout << "2 - aggiungi QUANTITA" << endl;
        cout << "3 - sottrai QUANTITA" << endl;
        cout << "4 - STAMPA" << endl;
        cout << "5 - RICERCA" << endl;
        cout << "0 - USCITA" << endl;
        cout << "-----------------------------" << "\n\n";
        cin >> scelta;

        switch (scelta) {
            case 1:
                inserisciProdotto(magazzino, dim, MAX);
                break;
            case 2: {
                int codice, quant;
                cout << "inserisci codice prodotto: ";
                cin >> codice;
                cout << "quantita da aggiungere: ";
                cin >> quant;
                if (!addQuantita(magazzino, dim, codice, quant)) {
                    cout << "prodotto non trovato!!\n";
                } else {
                    cout << "quantita aggiornata!\n";
                }
                break;
            }
            case 3: {
                int codice, quant;
                cout << "inserisci codice prodotto: ";
                cin >> codice;
                cout << "quantita da sottrarre: ";
                cin >> quant;
                if (!subQuantita(magazzino, dim, codice, quant)) {
                    cout << "prodotto non trovato o quantita insufficiente!!\n";
                } else {
                    cout << "quantita aggiornata!\n";
                }
                break;
            }
            case 4:
                stampaMagazzino(magazzino, dim);
                break;
            case 5:
                cercaEStamapaProdotto(magazzino, dim);
                break;
            case 0:
                cout << "uscita dal programma!!\n";
                break;
            default:
                cout << "scelta sbagliata!!\n";
        }
    } while (scelta != 0);

    return 0;
}
