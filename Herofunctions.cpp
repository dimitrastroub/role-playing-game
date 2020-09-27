#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "Monsterfunctions.cpp"

using namespace std;

Hero::Hero(string N,int L, int H_P, int M_P, int S,int D, int A, int M, int E): Living(N,L,H_P), magicPower(M_P), strength(S), dexterity(D),agility(A), money(M), experience(E){
	freehands= 2;  // he has 2 free hands
	armor= false; // he doesnt wear an armor
	cout<<"a hero has been created"<<endl;
}

Hero::~Hero(){
	cout<<"a hero has been deleted"<<endl;
}

void Hero::LevelUp(){
	level++;
	// strength , agility and dexterity are increased each time the hero levels up 
	strength=strength+(3*level);
	agility=agility+(3*level);
	dexterity=dexterity+(3*level);
}

int Hero::get_money(){
	return money;
}

void Hero::set_money(int numberofmonsters,int key){
	if(key==1)
		money=money+5*numberofmonsters*level;
	else if(key==2)
		money=money/2;
}

void Hero::set_experience(int numberofmonsters){
	experience=experience+ 2*numberofmonsters*level;
}

int Hero::get_freehands(){
	return freehands;
}

void Hero::set_freehands(int hands){
	freehands=hands;
}

void Hero::set_armor(bool wear){
	armor=wear;
}
