#include <iostream>

using namespace std;

int main(){
	int altezza=4;

	for(int i=1; i<=altezza; i++){
		for(int j=1; j<=i; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
	return 0;
}