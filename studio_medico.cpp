#include <iostream>
#include <string>

using namespace std;

struct DataOra{
    int giorno;
    int mese;
    int anno;
    int ora;
    int minuti;
};

struct Appuntamento{
    DataOra dataOra;
    string cognome;
    string nome;
    string codicefiscale;
    string telefono;
};

bool confrontoDate(Appuntamento &a, Appuntamento &b){
    if(a.dataOra.anno != b.dataOra.anno){
        return a.dataOra.anno < b.dataOra.anno;
    }
    if(a.dataOra.mese != b.dataOra.mese){
        return a.dataOra.mese < b.dataOra.mese;
    }
    if(a.dataOra.giorno != b.dataOra.giorno){
        return a.dataOra.giorno < b.dataOra.giorno;
    }
    if(a.dataOra.ora != b.dataOra.ora){
        return a.dataOra.ora < b.dataOra.ora;
    }
    return a.dataOra.minuti < b.dataOra.minuti;
}

void inserisciAppuntamento(Appuntamento lista[], int &n){
    Appuntamento nuovo;
    cout << "Inserisci data (gg mm aaaa): ";
    cin >> nuovo.dataOra.giorno >> nuovo.dataOra.mese >> nuovo.dataOra.anno;
    cout << "Inserisci ora (hh mm): ";
    cin >> nuovo.dataOra.ora >> nuovo.dataOra.minuti;
    cout << "Cognome: ";
    cin >> nuovo.cognome;
    cout << "Nome: ";
    cin >> nuovo.nome;

    do{
        cout << "Inserisci codice fiscale (16 caratteri): ";
        cin >> nuovo.codicefiscale;
    }while(nuovo.codicefiscale.size() != 16);

    cout << "Telefono: ";
    cin >> nuovo.telefono;

    // inserimento ordinato
    int i = n - 1;
    while(i >= 0 && confrontoDate(nuovo, lista[i])){
        lista[i + 1] = lista[i];
        i--;
    }
    lista[i + 1] = nuovo;
    n++;
    cout << "Appuntamento inserito!!\n";
}

void cercaPrimoAppuntamento(Appuntamento lista[], int n){
    string codice;
    cout << "Inserisci codice fiscale: ";
    cin >> codice;

    for(int i = 0; i < n; i++){
        if(lista[i].codicefiscale == codice){
            cout << "Primo appuntamento: " << lista[i].dataOra.giorno << "/" 
                 << lista[i].dataOra.mese << "/" << lista[i].dataOra.anno << " "
                 << lista[i].dataOra.ora << ":" << lista[i].dataOra.minuti << "\n";
            return;
        }
    }
    cout << "Nessun appuntamento trovato per questo paziente\n";
}

void modificaAppuntamento(Appuntamento lista[], int n) {
    DataOra d;
    cout << "Inserisci data (gg mm aaaa): ";
    cin >> d.giorno >> d.mese >> d.anno;
    cout << "Inserisci ora (hh mm): ";
    cin >> d.ora >> d.minuti;

    for (int i = 0; i < n; i++) {
        if (lista[i].dataOra.giorno == d.giorno && lista[i].dataOra.mese == d.mese &&
            lista[i].dataOra.anno == d.anno && lista[i].dataOra.ora == d.ora &&
            lista[i].dataOra.minuti == d.minuti) {
            cout << "Nuovo cognome: ";
            cin >> lista[i].cognome;
            cout << "Nuovo nome: ";
            cin >> lista[i].nome;
            cout << "Appuntamento modificato con successo!\n";
            return;
        }
    }
    cout << "Nessun appuntamento trovato con la data e ora inserite.\n";
}

void visualizzaPerData(Appuntamento lista[], int n){
    int g, m, a;
    cout << "Inserisci data (gg mm aaaa): ";
    cin >> g >> m >> a;

    bool trovato = false;
    for(int i = 0; i < n; i++){
        if(lista[i].dataOra.giorno == g && lista[i].dataOra.mese == m && lista[i].dataOra.anno == a){
            cout << lista[i].dataOra.ora << ":" << lista[i].dataOra.minuti << " -- "
                 << lista[i].cognome << " " << lista[i].nome
                 << " (CF: " << lista[i].codicefiscale << ")\n";
            trovato = true;
        }
    }
    if(!trovato) cout << "Nessun appuntamento trovato in questa data!\n";
}

void visualizzaPerPaziente(Appuntamento lista[], int n){
    string codice;
    cout << "Inserisci codice fiscale: ";
    cin >> codice;
    bool trovato = false;
    for(int i = 0; i < n; i++){
        if(lista[i].codicefiscale == codice){
            cout << lista[i].dataOra.giorno << "/" 
                 << lista[i].dataOra.mese << "/" << lista[i].dataOra.anno << " "
                 << lista[i].dataOra.ora << ":" << lista[i].dataOra.minuti << " -- "
                 << lista[i].cognome << " " << lista[i].nome << "\n";
            trovato = true;
        }
    }
    if(!trovato) cout << "Nessun appuntamento trovato per questo paziente!\n";
}

int main(){
    Appuntamento lista[50];
    int n = 0;
    int scelta;

    do{
        cout << "\n--- MENU ---\n";
        cout << "1. Inserisci appuntamento\n";
        cout << "2. Cerca primo appuntamento di un paziente\n";
        cout << "3. Modifica nome/cognome appuntamento\n";
        cout << "4. Visualizza appuntamenti per data\n";
        cout << "5. Visualizza appuntamenti per paziente\n";
        cout << "0. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch(scelta){
            case 1:
                inserisciAppuntamento(lista, n);
                break;
            case 2:
                cercaPrimoAppuntamento(lista, n);
                break;
            case 3: 
                modificaAppuntamento(lista, n);
                break;
            case 4:
                visualizzaPerData(lista, n);
                break;
            case 5:
                visualizzaPerPaziente(lista, n);
                break;
            case 0:
                cout << "Uscita dal programma!!\n";
                break;
            default:
                cout << "Scelta non valida!!\n";
        }
    }while(scelta != 0);

    return 0;
}