//tabellina
#include <iostream>

using namespace std;
int main(){
    const int righe=10;
    const int colonne=10;

    int tab[righe][colonne];
    
    for(int i=1; i<=righe; i++){
        for(int j=1; j<=colonne; j++){
            tab[i][j]=i*j;
        }
    }
    cout<<"tabellina da 1 a 10"<<endl;

    //stampa

    for(int i=1; i<=righe; i++){
        for(int j=1; j<=colonne; j++){
            cout<<"["<<tab[i][j]<<"]  ";
        }
        cout<<endl;
    }


    return 0;
}