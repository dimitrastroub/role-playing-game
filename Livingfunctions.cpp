#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Living.hpp"

using namespace std;

Living::Living(string N,int L, int H_P): name(N),level(L), healthPower(H_P){
	cout<<"a living has been created"<<endl;
}

Living::~Living(){
	cout<<"a living has been deleted"<<endl;
}

int Living::getlevel(){
	return level;
}
