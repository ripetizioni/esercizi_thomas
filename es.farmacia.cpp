#include <iostream>
#include <string>

using namespace std;

#define MAX 100

struct s_prodotto{
    string casaProduttrice;
    string nome;
    char forma; //(C=compresse, F=fiale, S=capsule, P=polver)
    float prezzoUnitario;
    char dataScadenza[11];
    int quantita;
};

//prototipi
void inserisciProdotto(s_prodotto stock[], int &n);
void cercaProdotto(s_prodotto stock[], int n, string nome);
void eliminaProdotto(s_prodotto stock[], int &n, string nome);
void visualizzaPrezzoMaggiore(s_prodotto stock[], int n, float soglia);
void visualizzaTutti(s_prodotto stock[], int n);

int main(){
    s_prodotto stock[MAX];
    int dim=0;
    int scelta;

    do{
        cout << "---------------MENU-----------------------------" << endl;
        cout << "1 -- INSERIMENTO prodotto nell'archivio" << endl;
        cout << "2 -- RICERCA prodotto per NOME" << endl;
        cout << "3 -- ELIMINAZIONE prodotto" << endl;
        cout << "4 -- VISUALIZZAZIONE per PREZZO SUPERIORE a ... " << endl;
        cout << "5 -- STAMPA tutti i prodotti" << endl;
        cout << "0 -- ---Uscita---" << endl;
        cout << "------------------------------------------------" << endl;
        cout<<"scelta: ";
        cin>>scelta;
        switch (scelta)
        {
        case 1:inserisciProdotto(stock,dim);
            break;
        case 2:{
            string nome;
            cin.ignore();
            cout<<"inserisci nome prodotto da cercare: ";
            getline(cin,nome);
            cercaProdotto(stock, dim, nome);

            break;
        }
        case 3:{
            string nome;
            cin.ignore();
            cout<<"inserisci nome prodotto da eliminare: ";
            getline(cin, nome);
            eliminaProdotto(stock, dim, nome);
            break;
        }
        case 4:
        {
            float soglia;
            cout<<"inserisci soglia prezzo: ";
            cin>>soglia;
            visualizzaPrezzoMaggiore(stock, dim, soglia);
            break;
        }
        case 5:visualizzaTutti(stock, dim);
            break;
        case 0:cout<<"uscita dal programma!!\n";
            break;
        
        default:cout<<"scelta non valida!!\n";
        }
    }while(scelta != 0);






    return 0;
}

void inserisciProdotto(s_prodotto stock[], int &n){
    if(n >=MAX){
        cout<<"archivio pieno!!\n";
    }

    s_prodotto nuovo;
    cin.ignore();
    cout<<"inserisci casa produttrice: ";
    getline(cin,nuovo.casaProduttrice);

    cout<<"inserisci nome prodotto: ";
    getline(cin, nuovo.nome);

    cout<<"inserisci forma(C=compresse, F=fiale, S=capsule, P=polver): ";
    cin>>nuovo.forma;

    cout<<"inserisci prezzo unitario: ";
    cin>>nuovo.prezzoUnitario;

    cout<<"inserisci data di scadenza(gg/mm/aaaa): ";
    cin.ignore();
    cin.getline(nuovo.dataScadenza, 11);

    cout<<"inserisci quantita': ";
    cin>>nuovo.quantita;

    stock[n++]=nuovo;

    cout<<"dati inseriti correttamente!!\n";
}

void cercaProdotto(s_prodotto stock[], int n, string nome){
    bool trovato=false;
    for(int i=0; i<n; i++){
        if(stock[i].nome==nome){
            cout<<"prodotto trovato!!\n";
            cout<<"casa produttrice: "<<stock[i].casaProduttrice<<endl;
            cout<<"nome: "<<stock[i].nome<<endl;
            cout<<"forma(C=compresse, F=fiale, S=capsule, P=polver): "<<stock[i].forma<<endl;
            cout<<"prezzo: "<<stock[i].prezzoUnitario<<endl;
            cout<<"data di scadenza(gg/mm/aaaa): "<<stock[i].dataScadenza<<endl;
            cout<<"quantita: "<<stock[i].quantita;
            trovato=true;
            break;
        }
    }
    if(!trovato){
        cout<<"prodotto NON trovato!!\n";
    }
}

void eliminaProdotto(s_prodotto stock[], int &n, string nome){
    int pos=-1;
    for(int i=0; i<n;i++){
        if(stock[i].nome==nome){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        cout<<"prodotto NON trovato!!\n";
        return;
    }
    for(int i=pos; i<n-1; i++){
        stock[i]=stock[i+1];
    }
    n--;
    cout<<"prodotto eliminato correttamente!!\n";
}

void visualizzaPrezzoMaggiore(s_prodotto stock[], int n, float soglia){
    cout<<"prodotti con prezzo superiore a "<<soglia<<":\n";
    for(int i=0;i<n;i++){
        if(stock[i].prezzoUnitario>=soglia){
            cout<<stock[i].nome<<"("<<stock[i].prezzoUnitario<<"€)\n";
        }
    }
}

void visualizzaTutti(s_prodotto stock[], int n){
    for(int i=0; i<n; i++){
        cout<<"prodotto stampato numero: "<<i+1<<endl;
        cout<<"casa produttrice: "<<stock[i].casaProduttrice<<endl;
        cout<<"nome: "<<stock[i].nome<<endl;
        cout<<"forma(C=compresse, F=fiale, S=capsule, P=polver): "<<stock[i].forma<<endl;
        cout<<"prezzo: "<<stock[i].prezzoUnitario<<endl;
        cout<<"data di scadenza(gg/mm/aaaa): "<<stock[i].dataScadenza<<endl;
        cout<<"quantita: "<<stock[i].quantita;
    }
}
