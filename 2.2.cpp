#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int trojka(string s, int p){
	if(s[p]==s[p+1] && s[p]==s[p+2]) return p;
	return -1;
}

bool kolumna(string p, string d, string t, int poz){
	if(p[poz]!=d[poz]) return false;
	if(p[poz]!=t[poz]) return false;
	return true;
}

int main(int argc, char** argv) {
	string A[2000];
	int i=0, j=0, k=0, licznik=0;
	ostringstream wynik;
	string wyniko;
	ifstream we("E:/symbole.txt");
	
	while(!we.eof()){
		getline(we, A[j]);
		j++;
	}
	for (j=0; j<1998; j++){
		for(i=0; i<10; i++){
			if(trojka(A[j],i)!=-1 &&
			trojka(A[j+1],i)!=-1 &&
			trojka(A[j+2],i)!=-1 &&
			kolumna(A[j],A[j+1],A[j+2],i)){
				wynik<<j+2;
				wyniko=wyniko+wynik.str();
				wynik.str("");
				wynik<<" ";
				wyniko=wyniko+wynik.str();
				wynik.str("");
				wynik<<i+2;
				wyniko=wyniko+wynik.str();
				wynik.str("");
				wynik<<" ";
				wyniko=wyniko+wynik.str();
				wynik.str("");
				wynik<<endl;
				wyniko=wyniko+wynik.str();
				wynik.str("");
				licznik++;
			}
		}
	}
	wyniko=wyniko+wynik.str();
	wynik.str("");
	wynik<<" ";
	wyniko=wyniko+wynik.str();
	wynik.str("");
	cout<<"Liczba kwadratow: "<<licznik<<endl<<wyniko;
	we.close();
	
	return 0;
}
