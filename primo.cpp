#include <iostream>

using namespace std;

int main(){
    int n;

    cout<<"inserisci un numero: ";
    cin>>n;

    /*for(int i =2; i<=n; i++){
        if(n%i == 0 && i != n ){
            cout<<"numero NON primo!!\n";
            break;
        }else{
            cout<<"numero PRIMO\n";
            break;
        }
    }*/

    //con while
    int i =2;
    bool primo =true;
    while(i <=n){
        if(n%i == 0 && i != n){
            primo =false;
            break;
        }
        i++;
    }
    if(primo){
        cout<<"numero PRIMO\n";
    }else{
        cout<<"numero NON primo\n";
    }


    return 0;
}