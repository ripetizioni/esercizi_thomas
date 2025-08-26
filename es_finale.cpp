#include <iostream>
#include <string>
using namespace std;
#define MAX 50

struct s_studente {
    string nome;
    int eta;
    int voti[MAX];
    int numVoti;
    float mediaVoti;
};


float calcolaMedia(int voti[], int numVoti) {
    int somma = 0;
    for (int i = 0; i < numVoti; i++) {
        somma += voti[i];
    }

    if (numVoti == 0)
        return 0.0;
    else
        return (float)somma / numVoti;
}


void stampaStudenti(s_studente studenti[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "\nNome: " << studenti[i].nome << endl;
        cout << "Eta: " << studenti[i].eta << endl;
        cout << "Media voti: " << studenti[i].mediaVoti << endl;
    }
}


void inserimento_ordinato_eta(s_studente studenti[], int dim) {
    for (int i = 1; i < dim; i++) {
        s_studente studenteCorrente = studenti[i];
        int j = i - 1;
        while (j >= 0 && studenti[j].eta > studenteCorrente.eta) {
            studenti[j + 1] = studenti[j];
            j--;
        }
        studenti[j + 1] = studenteCorrente;
    }
}

void ordinaMedia(s_studente studenti[], int dim) {
    for (int i = 0; i < dim - 1; i++) {
        int max = i;
        for (int j = i + 1; j < dim; j++) {
            if (studenti[j].mediaVoti > studenti[max].mediaVoti) {
                max = j;
            }
        }
        if (max != i) {
            s_studente temp = studenti[i];
            studenti[i] = studenti[max];
            studenti[max] = temp;
        }
    }
}

void mostraMigliori(s_studente studenti[], int dim) {
    for (int i = 0; i < dim; i++) {
        if (studenti[i].mediaVoti >= 8.0) {
            cout << "Studente con media >= 8: " << studenti[i].nome << endl;
        }
    }
}

int main() {
    s_studente studenti[MAX];
    int numStudenti = 0;
    int scelta;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Inserisci studente\n";
        cout << "2. Stampa tutti gli studenti\n";
        cout << "3. Ordina per eta (insertion sort)\n";
        cout << "4. Ordina per media voti (selection sort)\n";
        cout << "5. Mostra migliori studenti (media >= 8.0)\n";
        cout << "0. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: {
                if (numStudenti >= MAX) {
                    cout << "Numero massimo di studenti raggiunto.\n";
                    break;
                }

                s_studente nuovo;
                cout << "Nome: ";
                cin >> nuovo.nome;
                cout << "Eta: ";
                cin >> nuovo.eta;
                cout << "Quanti voti vuoi inserire? ";
                cin >> nuovo.numVoti;

                if (nuovo.numVoti > MAX) {
                    cout << "Troppi voti! Max consentiti: " << MAX << endl;
                    break;
                }

                cout << "Inserisci i voti:\n";
                for (int i = 0; i < nuovo.numVoti; i++) {
                    cin >> nuovo.voti[i];
                }

                nuovo.mediaVoti = calcolaMedia(nuovo.voti, nuovo.numVoti);
                studenti[numStudenti++] = nuovo;

                break;
            }

            case 2:
                stampaStudenti(studenti, numStudenti);
                break;

            case 3:
                inserimento_ordinato_eta(studenti, numStudenti);
                cout << "Studenti ordinati per eta!\n";
                break;

            case 4:
                ordinaMedia(studenti, numStudenti);
                cout << "Studenti ordinati per media voti!\n";
                break;

            case 5:
                mostraMigliori(studenti, numStudenti);
                break;

            case 0:
                cout << "Uscita dal programma...\n";
                break;

            default:
                cout << "Scelta non valida. Riprova.\n";
        }

    } while (scelta != 0);

    return 0;
}
