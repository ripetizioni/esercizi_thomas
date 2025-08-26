#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    int risposta, tentativo;
    int tentativi=0;
    int min = 1;
    int max = 100;
    srand(time(0));

    do
    {
        cout<<max << " " << min << endl;
        tentativo = rand() % (max - min + 1) + min;
        cout << "Il computer ha scelto il numero: " << tentativo << endl;
        cin >> risposta;
        

        while (risposta < 0 || risposta > 2)
        {
            cout << "sbagliato, reinserisci: ";
            cin >> risposta;
        }

        if (risposta == 1)
        {
            max = tentativo-1;
            tentativi++;
        }
        else if (risposta == 2){
            min = tentativo-1;
            tentativi++;
        }
        else
        {
            cout << "il computer ha indovinato il numero in " << tentativi << " tentativi" << endl;
        }
        

    } while (risposta != 0);

    return 0;
}