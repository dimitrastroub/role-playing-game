#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Spell.hpp"

using namespace std;

Spell::Spell(string N,int P, int M_L, int W_D, int M_E): name(N), price(P), min_level(M_L), wide_damage(W_D),magic_energy(M_E){
	cout<<"a spell has created"<<endl;
}

Spell::~Spell(){
	cout<<"a spell has deleted"<<endl;
}

int Spell::get_price(){
	return price;
}

int Spell::get_minlevel(){
	return min_level;
}

int Spell::get_damage(){
	return wide_damage;
}

IceSpell::IceSpell(string N,int P, int M_L, int W_D, int M_E): Spell(N,P,M_L,W_D,M_E){
	charac = 1;																	//this variable helps us to know the kind of the spell
	cout<<"an icespell has created"<< endl;
}

IceSpell::~IceSpell(){
	cout<<"an icespell has deleted"<<endl;
}

void IceSpell::ShowInfo(){
	cout<< "\t"<<name <<"\t"<< price <<"\t"<<min_level<<"\t"<<wide_damage <<"\t"<<magic_energy<<endl;
}

int IceSpell::get_energy(){
	return magic_energy;	
}

int IceSpell::get_charac(){
	return charac;
}

FireSpell::FireSpell(string N,int P, int M_L, int W_D, int M_E): Spell(N,P,M_L,W_D,M_E){
	charac = 2;																	//this variable helps us to know the kind of the spell
	cout<< "a firespell has created"<<endl;
}

FireSpell::~FireSpell(){
	cout<<"a firespell has deleted"<<endl;
}

void FireSpell::ShowInfo(){
	cout<< "\t"<<name <<"\t"<< price <<"\t"<<min_level<<"\t"<<wide_damage <<"\t"<<magic_energy<<endl;
}

int FireSpell::get_energy(){
	return magic_energy;	
}

int FireSpell::get_charac(){
	return charac;
}

LightingSpell::LightingSpell(string N,int P, int M_L, int W_D, int M_E): Spell(N,P,M_L,W_D,M_E){
	charac = 3;																	//this variable helps us to know the kind of the spell
	cout<<"a lightingspell has created"<<endl;
}

LightingSpell::~LightingSpell(){
	cout<<"a lightingspell has deleted"<<endl;
}

void LightingSpell::ShowInfo(){
	cout<< "\t"<<name <<"\t"<< price <<"\t"<<min_level<<"\t"<<wide_damage <<"\t"<<magic_energy<<endl;	
}

int LightingSpell::get_energy(){
	return magic_energy;	
}

int LightingSpell::get_charac(){
	return charac;
}
