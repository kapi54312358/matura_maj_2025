#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	ifstream we("E:/dron.txt");
	int j=100;
	int y[j], x[j], p1[j+1], p2[j+1], wynikp1[j*j], wynikp2[j*j], i_p1k[j*j], i_p2k[j*j];
	int i=0, l=0, k=0, n=1, m=0, srodekp1=0, srodekp2=0;
	
	for(i=0; i<j; i++){
		we>>x[i];
		we>>y[i];
	}
	
	p1[0]=0;
	p2[0]=0;
	j++;
	
	for(i=1; i<j; i++){
		p1[i]=p1[i-1]+x[i-1];
		p2[i]=p2[i-1]+y[i-1];
	}
	
	for(i=1; i<j; i++){
		for(k=i+1; k<j; k++){
			srodekp1=(p1[i]+p1[k]);
			srodekp2=(p2[i]+p2[k]);
			if(srodekp1%2==0 && srodekp2%2==0){
					wynikp1[n]=srodekp1/2;
					wynikp2[n]=srodekp2/2;
					i_p1k[n]=i;
					i_p2k[n]=k;
					n++;
			}	
		}
	}
	
	for(int i=0; i<n; i++) {
        for(int k=1; k<j; k++){
            if(wynikp1[i]==p1[k] && wynikp2[i]==p2[k]){
                cout<<"b) Znaleziona trojka punktow: ";
                cout<<"("<<p1[i_p1k[i]]<<", "<<p2[i_p1k[i]]<<") ";
                cout<<"("<<p1[k]<<", "<<p2[k]<<") ";
                cout<<"("<<p1[i_p2k[i]]<<", "<<p2[i_p2k[i]]<<") ";
            }
        }
    }
		
	we.close();
	return 0;
}
