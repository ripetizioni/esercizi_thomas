#include <iostream>
#include <string>

using namespace std;
#define MAX_OPERE 50

struct s_opera {
    string nomeArtista;
    string cognomeArtista;
    string nomeOpera;
    double valoreOpera;
    string codiceOpera;
};

void aggiungiOpera(s_opera collezione[], int &n);
void rimuoviOpera(s_opera collezione[], int &n);
void stampaArtistaPiuCostosa(s_opera collezione[], int n);
void stampaValoreTotale(s_opera collezione[], int n);
void stampaValorePerArtista(s_opera collezione[], int n);
void stampaOpereValoreMaggiore(s_opera collezione[], int n);
void stampaTutteLeOpere(s_opera collezione[], int n);

int main() {
    s_opera collezione[MAX_OPERE];
    int n = 0;
    int scelta;

    do {
        cout << "\n----- MENU ----\n";
        cout << "1. Aggiungi opera\n";
        cout << "2. Rimuovi opera\n";
        cout << "3. Artista opera piu' costosa\n";
        cout << "4. Valore totale collezione\n";
        cout << "5. Valore totale per artista\n";
        cout << "6. Opere con valore maggiore di soglia\n";
        cout << "7. Stampa tutte le opere\n";
        cout << "0. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;
        cin.ignore(); 

        switch (scelta) {
            case 1:
                aggiungiOpera(collezione, n);
                break;
            case 2:
                rimuoviOpera(collezione, n);
                break;
            case 3:
                stampaArtistaPiuCostosa(collezione, n);
                break;
            case 4:
                stampaValoreTotale(collezione, n);
                break;
            case 5:
                stampaValorePerArtista(collezione, n);
                break;
            case 6:
                stampaOpereValoreMaggiore(collezione, n);
                break;
            case 7:
                stampaTutteLeOpere(collezione, n);
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

void aggiungiOpera(s_opera collezione[], int &n) {
    if (n >= MAX_OPERE) {
        cout << "Collezione piena!\n";
        return;
    }

    s_opera nuovo;

    cout << "Nome artista: ";
    getline(cin, nuovo.nomeArtista);

    cout << "Cognome artista: ";
    getline(cin, nuovo.cognomeArtista);

    cout << "Nome opera: ";
    getline(cin, nuovo.nomeOpera);

    cout << "Valore opera: ";
    cin >> nuovo.valoreOpera;
    cin.ignore(); 

    cout << "Codice identificativo opera: ";
    getline(cin, nuovo.codiceOpera);

    int i = n - 1;
    while (i >= 0 && collezione[i].cognomeArtista > nuovo.cognomeArtista) {
        collezione[i + 1] = collezione[i];
        i--;
    }
    collezione[i + 1] = nuovo;
    n++;

    cout << "Opera aggiunta correttamente!\n";
}

void rimuoviOpera(s_opera collezione[], int &n) {
    if (n == 0) {
        cout << "Collezione vuota!\n";
        return;
    }

    string codice;
    cout << "Inserisci codice dell'opera da rimuovere: ";
    getline(cin, codice);

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (collezione[i].codiceOpera == codice) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < n - 1; i++) {
            collezione[i] = collezione[i + 1];
        }
        n--;
        cout << "Opera rimossa!\n";
    } else {
        cout << "Opera non trovata.\n";
    }
}

void stampaArtistaPiuCostosa(s_opera collezione[], int n) {
    if (n == 0) {
        cout << "Collezione vuota.\n";
        return;
    }

    double maxValore = collezione[0].valoreOpera;
    for (int i = 1; i < n; i++) {
        if (collezione[i].valoreOpera > maxValore) {
            maxValore = collezione[i].valoreOpera;
        }
    }

    cout << "Artista/i dell'opera piu' costosa (" << maxValore << "):\n";
    for (int i = 0; i < n; i++) {
        if (collezione[i].valoreOpera == maxValore) {
            cout << collezione[i].nomeArtista << " " << collezione[i].cognomeArtista << endl;
        }
    }
}

void stampaValoreTotale(s_opera collezione[], int n) {
    double totale = 0;
    for (int i = 0; i < n; i++) {
        totale += collezione[i].valoreOpera;
    }
    cout << "Valore totale collezione: " << totale << endl;
}

void stampaValorePerArtista(s_opera collezione[], int n) {
    if (n == 0) {
        cout << "Collezione vuota!\n";
        return;
    }

    string nome, cognome;
    cout << "Nome artista: ";
    getline(cin, nome);
    cout << "Cognome artista: ";
    getline(cin, cognome);

    double totale = 0;
    for (int i = 0; i < n; i++) {
        if (collezione[i].nomeArtista == nome && collezione[i].cognomeArtista == cognome) {
            totale += collezione[i].valoreOpera;
        }
    }

    cout << "Valore totale per " << nome << " " << cognome << ": " << totale << endl;
}

void stampaOpereValoreMaggiore(s_opera collezione[], int n) {
    if (n == 0) {
        cout << "Collezione vuota!\n";
        return;
    }

    double soglia;
    cout << "Inserisci valore soglia: ";
    cin >> soglia;
    cin.ignore();

    cout << "Opere con valore maggiore di " << soglia << ":\n";
    for (int i = 0; i < n; i++) {
        if (collezione[i].valoreOpera >= soglia) {
            cout << collezione[i].nomeOpera << " -- "
                 << collezione[i].nomeArtista << " "
                 << collezione[i].cognomeArtista
                 << " (" << collezione[i].valoreOpera << ")\n";
        }
    }
}

void stampaTutteLeOpere(s_opera collezione[], int n) {
    if (n == 0) {
        cout << "Collezione vuota!\n";
        return;
    }

    cout << "Elenco opere:\n";
    for (int i = 0; i < n; i++) {
        cout << collezione[i].nomeOpera << " -- "
             << collezione[i].nomeArtista << " "
             << collezione[i].cognomeArtista
             << " (" << collezione[i].valoreOpera
             << ") - codice: " << collezione[i].codiceOpera << endl;
    }
}
