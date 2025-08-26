#include <iostream>
#include <string>

using namespace std; 

#define MAX_DIPENDENTI 50
 
struct s_dipendente{
    string nome;
    string cognome;
    float stipendio;
};

//prototipi
void inizializzaVettore(s_dipendente v[], int dim);
void stampaVettore(s_dipendente v[], int dim);
double calcolaMediaStipendi(s_dipendente v[], int dim);
void visualizzaDipendente(s_dipendente v[], int dim, int pos);

int main(){
    s_dipendente dipendenti[MAX_DIPENDENTI];
    int scelta;
    int n;
    bool inizializzato =false;

    cout<<"quanti dipendenti vuoi inserire?(max "<<MAX_DIPENDENTI<<"): ";
    cin>>n;

    do{
        cout<<"\n--MENU--\n";
        cout<<"1. iniziallizzare il vettore\n";
        cout<<"2. stampare l'intero vettore\n";
        cout<<"3. stampare la media degli stipendi\n";
        cout<<"4. visualizzare un dipendente per posizione\n";
        cout<<"5. esci\n";
        cout<<"scelta: ";
        cin>>scelta;
        switch(scelta){
            case 1:
                inizializzaVettore(dipendenti, n);
                inizializzato=true;
                break;
            case 2:
            if(!inizializzato){
                cout<<"devi prima inizializzare il vettore!\n";
            }else{
                stampaVettore(dipendenti, n);
            }
                break;
            case 3: 
                if(!inizializzato){
                    cout<<"devi prima inizializzare il vettore!\n";
                }else{
                    cout<<"media stpendi: "<<calcolaMediaStipendi(dipendenti, n)<<"\n";
                }
                break;
            case 4:
                if(!inizializzato){
                cout<<"devi prima inizializzare il vettore!\n";
                }else{
                    int posizione;
                    cout<<"inserisci la posizione (1-"<<n<<"): ";
                    cin>>posizione;
                    visualizzaDipendente(dipendenti, n, posizione-1);
                }
                break;
            case 0:cout<<"uscita dal programma!!\n";
                break;
            default:cout<<"scelta non valida!!\n";
        }
    }while(scelta !=0);


    return 0;
}

void inizializzaVettore(s_dipendente v[], int dim){
    for(int i =0; i<dim; i++){
        cout<<"dipendente "<<i+1<<":\n";
        cout<<"nome: ";
        cin>>v[i].nome;
        cout<<"cognome: ";
        cin>>v[i].cognome;
        cout<<"stipendio: ";
        cin>>v[i].stipendio;
    }
}

void stampaVettore(s_dipendente v[], int dim){
    cout<<"----lista dipendenti----\n";
    for(int i =0; i<dim; i++){
        cout<<i+1<<"."<<v[i].nome<<" "<<v[i].cognome<<" "<<"stiepndio: "<<v[i].stipendio<<"\n";
    }
    cout<<endl;
}

double calcolaMediaStipendi(s_dipendente v[], int dim){
    float somma=0;
    float media=0;
    for(int i =0; i<dim; i++){
        somma+=v[i].stipendio;
    }
    media=(float)somma/dim;
    return media;
}


void visualizzaDipendente(s_dipendente v[], int dim, int pos){
    if(pos<0 || pos>=dim){
        cout<<"posizione non valida!!\n";
    }else{
        cout<<"dipendente "<<pos +1<<": "
        <<v[pos].nome<<" "<<v[pos].cognome
        <<"Stipendio: "<<v[pos].stipendio<<"\n";
    }
}
