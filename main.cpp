#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>
#include "Gridfunctions.cpp"

using namespace std;

int main (void){
	srand(time(NULL));
	int len=10, wid=8;
	int number;
	cout <<"\033[2J\033[1;1H";
	cout << "give the number of heros (1-3)"<<endl;
	cin >>number;														//the number of the heroes
	while(number<1 || number>3){										//must be 1,2 or 3
		cout << "give the number of heros (1-3)"<<endl;
		cin >>number;
	}
	Grid G(len,wid);
	G.DispalyGrid(number);
}
