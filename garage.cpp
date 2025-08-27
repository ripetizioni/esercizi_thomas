#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX_POSTI 80
#define INIZIO_ID 101

struct Tempo {
    int hh;
    int mm;
};

struct Posto {
    int id;
    string targa;
    string tipo;     // "normale" o "grande"
    Tempo ingresso;
    bool occupato;
};

//Funzioni di supporto 
int inMinuti(Tempo t) { return t.hh*60 + t.mm; }
int differenza(Tempo a, Tempo b) { return inMinuti(b) - inMinuti(a); }

// --- Funzioni richieste dal testo 
void ppIngresso(Posto g[], bool liberi[], string targa, string tipo, Tempo oraIngresso) {
    for (int i=0; i<MAX_POSTI; i++) {
        if (liberi[i]) {
            if (tipo=="grande" && (g[i].id>=141 && g[i].id<=160)) {
                g[i].targa=targa;
                g[i].tipo=tipo;
                g[i].ingresso=oraIngresso;
                g[i].occupato=true;
                liberi[i]=false;
                cout<<"Veicolo "<<targa<<" entrato al posto "<<g[i].id<<endl;
                return;
            }
            if (tipo=="normale" && !(g[i].id>=141 && g[i].id<=160)) {
                g[i].targa=targa;
                g[i].tipo=tipo;
                g[i].ingresso=oraIngresso;
                g[i].occupato=true;
                liberi[i]=false;
                cout<<"Veicolo "<<targa<<" entrato al posto "<<g[i].id<<endl;
                return;
            }
        }
    }
    cout<<"Nessun posto disponibile per "<<targa<<endl;
}

void ppUscita(Posto g[], bool liberi[], string targa, Tempo oraUscita) {
    for (int i=0; i<MAX_POSTI; i++) {
        if (!liberi[i] && g[i].targa==targa) {
            int tempo=differenza(g[i].ingresso,oraUscita);
            cout<<"Veicolo "<<targa<<" uscito. Permanenza: "<<tempo<<" minuti\n";
            liberi[i]=true;
            g[i].occupato=false;
            return;
        }
    }
    cout<<"Veicolo non trovato\n";
}

int ppCalcoloTempoPermanenza(Posto g[], bool liberi[], string targa, Tempo fine) {
    for (int i=0; i<MAX_POSTI; i++) {
        if (!liberi[i] && g[i].targa==targa) {
            return differenza(g[i].ingresso,fine);
        }
    }
    return -1;
}

void ppStampaTrovaTempiLunghi(Posto g[], bool liberi[], Tempo adesso) {
    cout<<"Tempi di permanenza:\n";
    for (int i=0; i<MAX_POSTI; i++) {
        if (!liberi[i]) {
            int t=differenza(g[i].ingresso,adesso);
            cout<<g[i].targa<<" ("<<g[i].id<<") "<<t<<" minuti\n";
        }
    }
}

void ppStampaPostiGrandiDisponibili(bool liberi[], Posto g[]) {
    int cont=0;
    for (int i=0; i<MAX_POSTI; i++) {
        if (liberi[i] && g[i].id>=141 && g[i].id<=160) cont++;
    }
    cout<<"Posti grandi liberi: "<<cont<<endl;
}

void ppStampaGenerale(Posto g[], bool liberi[], Tempo adesso) {
    cout<<"Situazione garage:\n";
    for (int i=0; i<MAX_POSTI; i++) {
        if (!liberi[i]) {
            int t=differenza(g[i].ingresso,adesso);
            cout<<"Posto "<<g[i].id<<" | "<<g[i].targa<<" | "<<g[i].tipo<<" | "<<t<<" minuti\n";
        }
    }
}


int main() {
    srand(time(0));
    Posto garage[MAX_POSTI];
    bool libero[MAX_POSTI];

    for (int i=0; i<MAX_POSTI; i++) {
        garage[i].id=INIZIO_ID+i;
        garage[i].occupato=false;
        libero[i]=true;
    }

    int scelta;
    do {
        cout<<"\nMENU\n";
        cout<<"1. Ingresso veicolo\n";
        cout<<"2. Uscita veicolo\n";
        cout<<"3. Calcolo tempo permanenza\n";
        cout<<"4. Stampa tempi lunghi\n";
        cout<<"5. Stampa posti grandi liberi\n";
        cout<<"6. Stampa generale\n";
        cout<<"0. Esci\n";
        cout<<"Scelta: ";
        cin>>scelta;

        switch(scelta) {
            case 1: {
                string targa,tipo; Tempo ora;
                cout<<"Targa: "; cin>>targa;
                cout<<"Tipo (normale/grande): "; cin>>tipo;
                cout<<"Ora (hh mm): "; cin>>ora.hh>>ora.mm;
                ppIngresso(garage,libero,targa,tipo,ora);
                break;
            }
            case 2: {
                string targa; Tempo ora;
                cout<<"Targa: "; cin>>targa;
                cout<<"Ora uscita (hh mm): "; cin>>ora.hh>>ora.mm;
                ppUscita(garage,libero,targa,ora);
                break;
            }
            case 3: {
                string targa; Tempo ora;
                cout<<"Targa: "; cin>>targa;
                cout<<"Ora attuale (hh mm): "; cin>>ora.hh>>ora.mm;
                int m=ppCalcoloTempoPermanenza(garage,libero,targa,ora);
                if (m>=0) cout<<"Tempo di permanenza: "<<m<<" minuti\n";
                else cout<<"Veicolo non trovato\n";
                break;
            }
            case 4: {
                Tempo ora; cout<<"Ora attuale (hh mm): "; cin>>ora.hh>>ora.mm;
                ppStampaTrovaTempiLunghi(garage,libero,ora);
                break;
            }
            case 5: {
                ppStampaPostiGrandiDisponibili(libero,garage);
                break;
            }
            case 6: {
                Tempo ora; cout<<"Ora attuale (hh mm): "; cin>>ora.hh>>ora.mm;
                ppStampaGenerale(garage,libero,ora);
                break;
            }
            case 0:
                cout<<"Uscita dal programma...\n";
                break;
            default:
                cout<<"Scelta non valida\n";
        }
    } while(scelta!=0);

    return 0;
}
