#include <iostream>
#include <string>
using namespace std;

// Struttura per la data
struct Data {
    int giorno, mese, anno;
};

// Struttura per il conto corrente
struct ContoCorrente {
    int numeroConto;
    string intestatario;
    Data dataApertura;
    double saldo;
    double fido;
    bool attivo;
};

// Funzioni per date
bool annoBisestile(int anno) {
    return (anno % 400 == 0) || (anno % 4 == 0 && anno % 100 != 0);
}

int giorniDelMese(int mese, int anno) {
    int giorniPerMese[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mese == 2 && annoBisestile(anno)) return 29;
    return giorniPerMese[mese-1];
}

int giorniDaInizioAnno(Data d) {
    int giorni = d.giorno;
    for (int m = 1; m < d.mese; m++) {
        giorni += giorniDelMese(m, d.anno);
    }
    return giorni;
}

int giorniTraDate(Data d1, Data d2) {
    if (d1.anno == d2.anno) {
        return giorniDaInizioAnno(d2) - giorniDaInizioAnno(d1);
    }
    int giorni = 0;
    giorni += (annoBisestile(d1.anno) ? 366 : 365) - giorniDaInizioAnno(d1);
    for (int a = d1.anno + 1; a < d2.anno; a++) {
        giorni += (annoBisestile(a) ? 366 : 365);
    }
    giorni += giorniDaInizioAnno(d2);
    return giorni;
}

// Funzioni richieste
void ccStampa(ContoCorrente conti[], int totale, bool tutti, int numero = -1) {
    if (tutti) {
        cout << "\n--- Elenco conti correnti ---\n";
        for (int i = 0; i < totale; i++) {
            if (conti[i].attivo) {
                cout << conti[i].numeroConto << " - " << conti[i].intestatario
                     << " - Saldo: " << conti[i].saldo << " €\n";
            }
        }
    } else {
        for (int i = 0; i < totale; i++) {
            if (conti[i].numeroConto == numero && conti[i].attivo) {
                cout << "\nConto n." << conti[i].numeroConto << " - " << conti[i].intestatario
                     << "\nApertura: " << conti[i].dataApertura.giorno << "/"
                     << conti[i].dataApertura.mese << "/" << conti[i].dataApertura.anno
                     << "\nSaldo: " << conti[i].saldo << " €\n";
                return;
            }
        }
        cout << "Conto non trovato.\n";
    }
}

void ccApertura(ContoCorrente conti[], int &totale, int &ultimoID) {
    if (totale >= 100) {
        cout << "Limite massimo conti raggiunto!\n";
        return;
    }
    ContoCorrente nuovo;
    nuovo.numeroConto = ultimoID++;
    cin.ignore();
    cout << "Nome e cognome titolare: ";
    getline(cin, nuovo.intestatario);
    cout << "Data apertura (gg mm aaaa): ";
    cin >> nuovo.dataApertura.giorno >> nuovo.dataApertura.mese >> nuovo.dataApertura.anno;
    cout << "Saldo iniziale: ";
    cin >> nuovo.saldo;
    nuovo.fido = -500.0;
    nuovo.attivo = true;
    conti[totale++] = nuovo;
    cout << "Conto aperto con successo! Numero: " << nuovo.numeroConto << "\n";
}

void ccSaldo(ContoCorrente conti[], int totale, int numero) {
    ccStampa(conti, totale, false, numero);
}

void ccVersamento(ContoCorrente conti[], int totale, int numero, double importo) {
    for (int i = 0; i < totale; i++) {
        if (conti[i].numeroConto == numero && conti[i].attivo) {
            conti[i].saldo += importo;
            cout << "Versamento effettuato.\n";
            ccStampa(conti, totale, false, numero);
            return;
        }
    }
    cout << "Conto non trovato.\n";
}

void ccBonifico(ContoCorrente conti[], int totale, int da, int a, double importo) {
    int idxDa = -1, idxA = -1;
    for (int i = 0; i < totale; i++) {
        if (conti[i].numeroConto == da && conti[i].attivo) idxDa = i;
        if (conti[i].numeroConto == a && conti[i].attivo) idxA = i;
    }
    if (idxDa != -1 && idxA != -1) {
        if (conti[idxDa].saldo - importo >= conti[idxDa].fido) {
            conti[idxDa].saldo -= importo;
            conti[idxA].saldo += importo;
            cout << "Bonifico effettuato.\n";
            ccStampa(conti, totale, false, da);
            ccStampa(conti, totale, false, a);
        } else {
            cout << "Fondi insufficienti per il bonifico.\n";
        }
    } else {
        cout << "Uno dei conti non esiste.\n";
    }
}

void ccChiusuraConto(ContoCorrente conti[], int totale, int numero) {
    for (int i = 0; i < totale; i++) {
        if (conti[i].numeroConto == numero && conti[i].attivo) {
            cout << "Importo da consegnare al cliente: " << conti[i].saldo << " €\n";
            conti[i].attivo = false;
            cout << "Conto chiuso.\n";
            return;
        }
    }
    cout << "Conto non trovato.\n";
}

void ccComputoInteressi(ContoCorrente conti[], int totale, int numero, Data dataOggi) {
    for (int i = 0; i < totale; i++) {
        if (conti[i].numeroConto == numero && conti[i].attivo) {
            if (conti[i].saldo > 0) {
                int giorni = giorniTraDate(conti[i].dataApertura, dataOggi);
                double interessi = conti[i].saldo * 0.01 * (giorni / 365.0);
                conti[i].saldo += interessi;
                cout << "Interessi calcolati: " << interessi << " €\n";
            } else {
                cout << "Saldo negativo, nessun interesse applicato.\n";
            }
            ccStampa(conti, totale, false, numero);
            return;
        }
    }
    cout << "Conto non trovato.\n";
}

void ccChiusuraBanca(ContoCorrente conti[], int &totale) {
    cout << "--- Chiusura banca ---\n";
    for (int i = 0; i < totale; i++) {
        if (conti[i].attivo) {
            cout << "Conto " << conti[i].numeroConto 
                 << ": saldo da restituire = " << conti[i].saldo << " €\n";
            conti[i].attivo = false;
        }
    }
    totale = 0;
}

// MAIN con switch-case
int main() {
    ContoCorrente conti[100];
    int numeroConti = 0;
    int ultimoNumeroConto = 1001;
    int scelta;

    do {
        cout << "\n--- Menu Banca ---\n"
             << "1. Apertura conto\n"
             << "2. Visualizza saldo\n"
             << "3. Versamento\n"
             << "4. Bonifico\n"
             << "5. Chiusura conto\n"
             << "6. Computo interessi\n"
             << "7. Stampa tutti i conti\n"
             << "8. Chiusura banca\n"
             << "0. Esci\n"
             << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                ccApertura(conti, numeroConti, ultimoNumeroConto);
                break;
            case 2: {
                int numero; cout << "Numero conto: "; cin >> numero;
                ccSaldo(conti, numeroConti, numero);
                break;
            }
            case 3: {
                int numero; double importo;
                cout << "Numero conto: "; cin >> numero;
                cout << "Importo versamento: "; cin >> importo;
                ccVersamento(conti, numeroConti, numero, importo);
                break;
            }
            case 4: {
                int da, a; double importo;
                cout << "Conto mittente: "; cin >> da;
                cout << "Conto destinatario: "; cin >> a;
                cout << "Importo: "; cin >> importo;
                ccBonifico(conti, numeroConti, da, a, importo);
                break;
            }
            case 5: {
                int numero; cout << "Numero conto: "; cin >> numero;
                ccChiusuraConto(conti, numeroConti, numero);
                break;
            }
            case 6: {
                int numero; Data oggi;
                cout << "Numero conto: "; cin >> numero;
                cout << "Data attuale (gg mm aaaa): ";
                cin >> oggi.giorno >> oggi.mese >> oggi.anno;
                ccComputoInteressi(conti, numeroConti, numero, oggi);
                break;
            }
            case 7:
                ccStampa(conti, numeroConti, true);
                break;
            case 8:
                ccChiusuraBanca(conti, numeroConti);
                break;
            case 0:
                cout << "Uscita dal programma...\n";
                break;
            default:
                cout << "Scelta non valida.\n";
        }

    } while (scelta != 0);

    return 0;
}
