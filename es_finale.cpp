#include <iostream>
#include <string>
using namespace std;
#define MAX 50

struct s_studente{
    string nome;
    int eta;
    int voti[MAX];
    int numVoti;
    float mediaVoti;
};

void stampaStudenti(s_studente studenti[], int dim){
    for(int i=0; i<dim; i++){
        cout<<"nome: "<<studenti[i].nome<<<endl;
        cout<<"eta: "<<studenti[i].eta<<endl;
        cout<<"media voti: "<<studenti[i].mediaVoti<<endl;
    }
}

void inserimento_ordinato_eta(s_studente studenti[], int dim){
    for(int i =0; i<dim; i++){
        s_studente studenteCorrente =studenti[i];
        int j=i-1;
        while(j>=0&& studenti[j].eta > studenteCorrente.eta){
            studenti[j+1]=studenti[j];
            j--;
        }
        studenti[j+1]=studenteCorrente;
    }
}

int main(){

    return 0;
}