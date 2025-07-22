#include <iostream>
#include <string>

#define MAX_BRANI 50

using namespace std;

struct s_branoMusicale{
    string titolo;
    string autore;
    string genere;
    int anno;
    int durataSec;
};

struct s_cdAudio{
    string nome;
    s_branoMusicale brani[MAX_BRANI];
    int numBrani;
};

bool aggiungiBrano (s_branoMusicale brano, s_cdAudio &cd) {
    for(int i =0; i<cd.numBrani; i++){
        if(cd.brani[i].titolo==brano.titolo){
            return false;
        }
    }
    cd.numBrani++;
    cd.brani[numBrani]=brano;
    return true;
}
bool cancellaBrano(string titolo, s_cdAudio &cd){
    for(int i=0; i<cd.numBrani; i++){
        if(cd.brani[i].titolo==titolo){
            for(int j=i; j<cd.numBrani-1; j++){
                cd.brani[j]=cd.brani[j+1];
            }
            numBrani--;
            return true;
        }
    }
    return false;
}

s_branoMusicale search(string titolo, s_cdAudio &cd) {
    for(int i=0; i<cd.numBrani; i++){
        if(cd.brani[i].titolo==titolo){
            return cd.brani[i];
        }
    }
    return; 
}
void modificaBrano(s_branoMusicale nuovoBrano, s_cdAudio &cd, int pos) {
    if(pos<0 || pos>=cd.numBrani){
        couut << "Posizione non valida." << endl;
        return;
    }
    cd.brani[pos]=nuovoBrano;
}
int contaBrani(string autore, s_cdAudio &cd){
    int count =0;
    for(int i =0; i<cd.numBrani; i++){
        if(cd.brani[i].autore==autore){
            count++;
        }
    }
    return count;
}

s_branoMusicale maxDurata(s_cdAudio &cd){
    if(cd.numBrani==0){
        return;
    }
    int maxDurata= cd.brani[0].durataSec;
    int posMax=0;
    for(int i=1;  i<cd.numBrani; i++){
        if(cd.brani[i].durataSec>maxDurata){
            maxDurata=cd.brani[i].durataSec;
            posMax=i;
        }
    }
    return cd.brani[posMax];
}


int main{


    return 0;
}