/*🧠 ESERCIZIO – GESTIONE DI UNA GARA A PUNTI
✅ FASE 1 – Versione base senza funzioni
Scrivi un programma in C++ che gestisce una gara con 5 partecipanti. Il programma deve:

Creare un array di 5 interi che rappresentano i punti dei 5 partecipanti, inizializzati a 0.
Simulare 10 manche di gara. In ogni manche:
 - Viene generato casualmente un vincitore tra i 5 (indice da 0 a 4).
 - Il vincitore ottiene 3 punti.

Al termine della gara, stampa:
 - I punti di ciascun partecipante.
 - Il numero del partecipante vincitore (quello con più punti).
 - In caso di parità, stampa "Parità!" e mostra tutti i partecipanti a pari merito.

Usare:
 - rand() e srand().
 - For annidati (se si vuole visualizzare manche per manche).
 - Uso di condizioni per identificare il massimo e gestire la parità.
*/
 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int estrazione(int punti[], int Nmanche)
{
    int vincitore;
    srand(time(0));
    for(int i=1; i<=Nmanche; i++){
        vincitore=rand()%(4-0+1)+0;
        punti[vincitore]+=3;

        cout<<"il vincitore e' stato il numero "<<vincitore+1<<endl;
    }
    return vincitore;
}

void stampapunti(int punti[], int Npartecipanti){
    cout<<"-------- punti finali --------"<<endl;
    for(int i =0; i<Npartecipanti; i++){
        cout<<"partecipante "<<i+1<<": "<<punti[i]<<" punti"<<endl;
    }
}

int vincitoreN(int punti[], int Npartecipanti,int vincitore){

    for(int i =0; i<Npartecipanti; i++){
        if(punti[i]>punti[vincitore]){
            vincitore=i;
        }
    }

    return vincitore;
}

void parita(int punti[], int Npartecipanti, int vincitore){
    for(int i =0; i<Npartecipanti; i++){
        if(punti[i]==punti[vincitore]){
            cout<<"il giocatore "<<i+1<<" e' a parimerito."<<endl;
        }
    }
}

int main(){

    const int Npartecipanti=5;
    const int Nmanche= 10;

    int punti[Npartecipanti]={0,0,0,0,0};
    int vincitore;    
    
    vincitore = estrazione(punti, Nmanche);

    stampapunti(punti, Npartecipanti);
    vincitore=vincitoreN(punti,Npartecipanti,vincitore);
    
    cout<<"il vincitore è il partecipante in posizione "<<vincitore+1<<endl;
    
    parita(punti, Npartecipanti,vincitore);

    return 0;
}