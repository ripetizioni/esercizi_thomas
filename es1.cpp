#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	
int num;
int tentativo;

srand(time(0));

num=rand()%100+1;

do{
    cout<<"\ninserisci il tuo tentativo: ";
    cin>>tentativo;

    if(tentativo <num)
        cout<<"\ntroppo basso";
    else if(tentativo > num)
        cout<<"\ntroppo alto";
    else{
        cout<<"\nhai indovinato il numero";
    }
    

}while(tentativo !=num);

	
	return 0;
}