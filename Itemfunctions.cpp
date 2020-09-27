#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Item.hpp"

using namespace std;

Item::Item(string N,int P,int M_L): name(N), price(P), min_level(M_L){
	cout<< "an item has created"<< endl;
}

Item::~Item(){
	cout<< "an item has deleted"<<endl;
}

Weapon::Weapon(string N,int P, int M_L,int D,int H): Item(N,P,M_L), damage(D), hands(H){
	cha =0;																			//this variable helps us to know the kind of the item
	cout<< "a weapon has created"<<endl;
}

Weapon::~Weapon(){
	cout<<"a weapon has deleted"<< endl;
}

void Weapon::ShowInfo(){
	cout<< "\t"<<name <<"\t\t"<< price <<"\t"<<min_level<<"\t"<<damage<<"\t"<<hands<<endl;
}

int Weapon::get_minlevel(){
	return min_level;
}

int Weapon::get_price(){
	return price;	
}

int Weapon::get_increase(){
	return 0;
}

int Weapon::get_characteristic(){
	return -1;
}

int Weapon::get_hands(){
	return hands;
}

int Weapon::get_cha(){
	return cha;
}

int Weapon::get_damage(){
	return damage;
}

Armor::Armor(string N,int P, int M_L): Item(N,P,M_L){
	cha = 1;																			//this variable helps us to know the kind of the item
	cout<<" an armor has created"<<endl;
}

Armor::~Armor(){
	cout<<"an armor has deleted"<<endl;
}

void Armor::ShowInfo(){
	cout<< "\t"<<name <<"\t\t"<< price <<"\t"<<min_level<<endl;
}

int Armor::get_minlevel(){
	return min_level;
}

int Armor::get_price(){
	return price;	
}

int Armor::get_increase(){
	return 0;
}

int Armor::get_characteristic(){
	return -1;
}

int Armor::get_cha(){
	return cha;
}

int Armor::get_hands(){
	return -1;
}

int Armor::get_damage(){
	return -1;
}

Potion::Potion(string N,int P, int M_L,int C):Item(N,P,M_L), characteristic(C){
	cha = 2;																						//this variable helps us to know the kind of the spell
	cout<<"a potion has created"<<endl;
}

Potion::~Potion(){
	cout<<"a potion has deleted"<<endl;
}

void Potion::ShowInfo(){
	cout<< "\t"<<name <<"\t\t"<< price <<"\t"<<min_level<<"\t";
	if(characteristic==0)																			//this varieble shows which characteristic of the heroes increases the potion
		cout<<" the strength"<<endl;
	else if(characteristic==1)
		cout<<" the dexterity"<<endl;
	else
		cout<<" the agility"<<endl;
}

int Potion::get_minlevel(){
	return min_level;
}

int Potion::get_price(){
	return price;	
}

int Potion::get_characteristic(){
	return characteristic;
}

int Potion::get_cha(){
	return cha;
}

int Potion::get_hands(){
	return -1;
}

int Potion::get_damage(){
	return -1;
}

