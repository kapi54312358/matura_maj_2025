#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const n=2000;

bool palindrom(string a){
	int i=0;
	for(i=0; i<=a.size()-1; i++){
		if(a[i]!=a[a.size()-1-i])
			return false;
	}
	return true;
}

int main(int argc, char** argv) {
	ifstream we("C:/cpp/symbole.txt");
	int i=0;
	string symbole[n];
	
	for(i=0; i<n; i++){
		we>>symbole[i];
	}
	
	for(i=0; i<n; i++){
		if(palindrom(symbole[i]))
			cout<<symbole[i]<<endl;
	}
	
	return 0;
}
