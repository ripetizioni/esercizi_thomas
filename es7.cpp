/*Implementare un programma che esponga il seguente menu utente ed esegua le funzionalità indicate:
# # # # # #  MENU  # # # # # # 
Scegliere l'operazione da eseguire:
1) Somma tra due numeri
2) Sottrazione tra due numeri
3) Moltiplicazione tra due numeri
4) Divisione tra due numeri

Dopo aver stampato sullo schermo il risultato richiesto, tramite un messaggio chiedere all'utente se uscire dal programma oppure effettuare una nuova operazione.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 100
using namespace std;

int addizione(int a, int b) {
    int somma=0;
    somma=a+b;

    return somma;
}
int sottrazione(int a, int b) {
    int diff=0;
    if(a>b) diff=a-b;

    else{
        int temp=a;
        a=b;
        b=temp;
        diff=a-b;
    }
     
    return diff;
}
int moltiplicazione(int a, int b ){
    int prod;
    prod=a*b;

    return prod;
}
float divisione(int a, int b ){
    float quoz=0;
    quoz=(float)a/b;

    return quoz;
}


int main(){
    int n1, n2;
    int scelta;
    
    cout<<endl;
		cout<<"insersci un numero intero (n1) -->";
		cin>>n1;
		
		cout<<"insersci un numeri interi (n2) -->";
		cin>>n2;
do{
		
		
		cout<<"-----------------------------"<<endl;
		cout<<"scelta 1 addizione"<<endl;
	 	cout<<"scelta 2 sottrazione"<<endl;
		cout<<"scelta 3 moltiplicazione"<<endl;
		cout<<"scelta 4 divisione"<<endl;
		cout<<"scelta 5 termina il programma"<<endl;
		cout<<"-----------------------------"<<endl;
		cin>>scelta;
		
		switch(scelta){
			case 1:
				cout<<"il risultato della somma e'--> "<<addizione(n1,n2)<<endl;
				
				break;
				
			case 2:
				cout<<"il risultato della sottrazione e'-->"<<sottrazione(n1,n2)<<endl;
				break;
			case 3:
				cout<<"il risultato del prodotto e'-->"<<moltiplicazione(n1,n2)<<endl;
				break;
			case 4:
				cout<<"il risultato del quoziente e'--<"<<divisione(n1,n2)<<endl;
				break;
			case 5:	
				cout<<"FINE PROGRAMMA!"<<endl;
				break;
            defualt:cout<<"scelta sbagliata!!";
		}
		
	}while(scelta !=5);

    

    return 0;
}