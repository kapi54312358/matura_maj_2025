#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
	ifstream we("E:/dron.txt");
	int y[100], x[100], p1[101], p2[101], wynikp1[100], wynikp2[100];
	int i=0, l=0, j=0, k=0, m=0, n=0, pom=0;
	bool srodekp1=false;
	bool srodekp2=false;

	for(i=0; i<100; i++){
		we>>x[i];
		we>>y[i];
	}
	
	p1[0]=0;
	p2[0]=0;
	
	for(i=1; i<101; i++){
		p1[i]=p1[i-1]+x[i-1];
		p2[i]=p2[i-1]+y[i-1];
	}
	
	for(i=1; i<101; i++){
		if(p1[i]>0 && p1[i]<5000 && p2[i]>0 && p2[i]<5000) l++; // podpunkt a)
		
		srodekp1=false;//podpunkt b)
		srodekp2=false;
		k=50-(abs(50-i));
		m=0;
		while(m>k || srodekp1==true){
			m++;
			pom=p1[i-m]+p1[i+m]/2;
			if(pom==p1[i]) srodekp1=true;
			else srodekp1=false;
		}
		n=0;
		while(n>k || srodekp2==true){
			n++;
			pom=p2[i-n]+p2[i+n]/2;
			if(pom==p2[i]) srodekp2=true;
			else srodekp2=false;
		}
		if(srodekp1 && srodekp2){
			wynikp1[j]=p1[i];
			wynikp2[j]=p2[i];
			j++;
		}
	}
	
	cout<<"a) "<<l;
	
	for(i=0; i<j; i++){
		cout<<wynikp1[i]<<" "<<wynikp2[i]<<endl;
	}
	
	we.close();
	return 0;
}
