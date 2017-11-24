#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;
bool win(int *mass)
{
	for (int i=0;i<16;i++)
	{
		if(mass[i]!=mass[i+1]-1) return false;break;
	}
	return true;
}
void vpravo(int *mass)
{
	int k;
	for(int i=0;i<16;i++){if (mass[i]==0) k=i;}
	if ((k!=0)&&(k!=4)&&(k!=8)&&(k!=12)) swap (mass[k],mass[k-1]);
	else cout<<"I can't do it"<<endl;
}
void vlevo(int *mass)
{
	int k;
	for(int i=0;i<16;i++){if (mass[i]==0) k=i;}
	if ((k!=3)&&(k!=7)&&(k!=11)&&(k!=15)) swap (mass[k],mass[k+1]);
	else cout<<"I can't do it"<<endl;
}
void vverh(int *mass)
{
	int k;
	for(int i=0;i<16;i++){if (mass[i]==0) k=i;}
	if ((k!=12)&&(k!=13)&&(k!=14)&&(k!=15)) swap (mass[k],mass[k+4]);
	else cout<<"I can't do it"<<endl;
}
void vniz(int *mass)
{
	int k;
	for(int i=0;i<16;i++){if (mass[i]==0) k=i;}
	if ((k!=0)&&(k!=1)&&(k!=2)&&(k!=3)) swap (mass[k],mass[k-4]);
	else cout<<"I can't do it"<<endl;
}
void tablica(int *mass) {
	cout << " +----+----+----+----+" << endl;
	for(int i=0;i<4;i++) {if (mass[i]<10) { if (mass[i]==0)cout << " | "<<" ";else cout << " | " <<"0"<<mass[i];}	else cout << " | " <<mass[i];if (mass[i]==0)cout <<" ";}cout<< " | "<<endl;
	cout << " +----+----+----+----+" << endl;
	for(int i=4;i<8;i++) {if (mass[i]<10) { if (mass[i]==0)cout << " | "<<" ";else cout << " | " <<"0"<<mass[i];}	else cout << " | " <<mass[i];if (mass[i]==0)cout <<" ";}cout<< " | "<<endl;
	cout << " +----+----+----+----+" << endl;
	for(int i=8;i<12;i++) {if (mass[i]<10) { if (mass[i]==0)cout << " | " <<" ";else cout << " | " <<"0"<<mass[i];}	else cout << " | " <<mass[i];if (mass[i]==0)cout <<" ";}cout<< " | "<<endl;
	cout << " +----+----+----+----+" << endl;
	for(int i=12;i<16;i++) {if (mass[i]<10) { if (mass[i]==0)cout << " | "<<" ";else cout << " | " <<"0"<<mass[i];}	else cout << " | " <<mass[i];if (mass[i]==0)cout <<" ";}cout<< " | "<<endl;
	cout << " +----+----+----+----+" << endl;	
}
void zapoln(int *mass)
{
	int i=0 ;
	while(i<15){
	int r=rand()%16;
	if (mass[r]==0){
		mass[r]=i+1;
		i++;	
	}
}
}
int main(int argc, char** argv) {
	srand(time(NULL));
	char op;
	int mass[16] = { };
	zapoln(mass);
	tablica(mass);
	cout<<"Insert operation"<<endl;
	while(win)
	{
		cin>>op;
		if (op=='l') vpravo(mass);
		else if (op=='j') vniz(mass);
		else if (op=='h') vlevo(mass);
		else if (op=='k') vverh(mass);
		else if(op=='q') return -1;
		else cout<<"Uncorrect operation"<<endl;
		tablica(mass);
	}
	return 0;
}
