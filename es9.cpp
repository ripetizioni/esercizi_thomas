//conta cifre

#include <iostream>
using namespace std;

int main(){
    int n;
    int cifre=0;

    cout<<"inserisci un numero: ";
    cin>>n;

    if(n==0){
        cifre=1;
    }
    else{
        if(n<0){
            n=n*(-1);
        }
    }

    while(n>0){
        n=n/10;
        cifre++;
    }

    cout<<"le cifre del numero inserito sono--> "<<cifre<<endl;


    return 0;
}

