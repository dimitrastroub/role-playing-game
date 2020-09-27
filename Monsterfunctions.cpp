#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Livingfunctions.cpp"

using namespace std;

Monster::Monster(string N,int L, int H_P, int W_D, int A_D, int A_P): Living(N,L,H_P), wide_damage(W_D), amount_defence(A_D), avoid_possibility(A_P){
	roundfordamage=0;
	roundfordefence=0;
	roundforpossibility=0;
	cout<<"a monster has created"<<endl;
}

Monster::~Monster(){
	cout<<"a monster has deleted"<<endl;
}

void Monster::set_roundfordamage(int i){
	if(i==0 || i>roundfordamage)
		roundfordamage=i;
}

void Monster::set_roundfordefence(int i){
	if(i==0 || i>roundfordefence)
		roundfordefence=i;
}

void Monster::set_roundforpossibility(int i){
	if(i==0 || i>roundforpossibility)
		roundforpossibility=i;
}

int Monster::get_roundfordamage(){
	return roundfordamage;
}

int Monster::get_roundfordefence(){
	return roundfordefence;
}

int Monster::get_roundforpossibility(){
	return roundforpossibility;
}

Dragon::Dragon(string N,int L, int H_P, int W_D, int A_D, int A_P): Monster(N,L,H_P,W_D,A_D,A_P){
	cout<<"a dragon has created"<<endl;
	wide_damage=wide_damage+10;												//dragons can cause more damage than the other monsters
}

Dragon::~Dragon(){
	cout<<"a dragon has deleted"<<endl;
}

void Dragon::displayStats(){
	cout<<"Dragon with name: "<< name<< " is in level: "<< level<<", his healthPower is: "<< healthPower;
	cout<<" his wide of damage is: "<<wide_damage<<", his amount of defence is: "<<amount_defence<<" and his possibility to avoid an attack is: "<<avoid_possibility<<"%"<<endl;
}

int Dragon::get_defence(){
	return amount_defence;
}

int Dragon::get_possibility(){
	return avoid_possibility;
}


int Dragon::get_healthpower(){
	return healthPower;
}

void Dragon::set_damage(int a){
	if(wide_damage -a>=0)									//this variable cannot be a negative number
		wide_damage = wide_damage -a;
	else
		wide_damage=0;
}

void Dragon::set_defence(int a){
	if(amount_defence - a>=0)								//this variable cannot be a negative number
		amount_defence = amount_defence - a;
	else
		amount_defence=0;
}

void Dragon::set_poss( int a){
	if(avoid_possibility-a>=0)								//this variable cannot be a negative number
		avoid_possibility = avoid_possibility - a;
	else
		avoid_possibility=0;	
}

void Dragon::set_healthpower(int a){
	if(healthPower-a>=0)									//this variable cannot be a negative number
		healthPower=healthPower-a;
	else
		healthPower=0;
}

void Dragon::increase_healthpower(){
	healthPower=healthPower+ 10;
	if(healthPower>60)
		healthPower=60;
}

void Dragon::attack(Hero* H){								//the dragon attacks to a hero
	int damage,possibility,count;
	possibility=H->get_agility()/3;							//the possibility depends on the agility of the hero
	count=rand()/10+1;
	if(count>possibility){									//if the hero didn't manage to avoid the attack
		if(H->get_armor()==true){							//if the hero wears an armor the damage is less
			cout<<"The hero wears an armor"<<endl;
			damage=rand()%10 +wide_damage-5;
		}
		else
			damage=rand()%10 +wide_damage;
		H->decrease_healthPower(damage);
	}
	else
		cout<<"The hero avoided the attack"<<endl;
}

Exoskeleton::Exoskeleton(string N,int L, int H_P, int W_D, int A_D, int A_P): Monster(N,L,H_P,W_D,A_D,A_P){
	amount_defence=amount_defence+3;						//exoskeletons can defend themselves more than the other monsters
	cout<<"a exoskeleton has created"<<endl;
}

Exoskeleton::~Exoskeleton(){
	cout<<"a exoskeleton has deleted"<<endl;
}

void Exoskeleton::displayStats(){
	cout<<"Exoskeleton with name: "<< name<< " is in level: "<< level<<", his healthPower is: "<< healthPower;
	cout<<" his wide of damage is: "<<wide_damage<<", his amount of defence is: "<<amount_defence<<" and his possibility to avoid an attack is: "<<avoid_possibility<<"%"<<endl;
}

int Exoskeleton::get_defence(){
	return amount_defence;
}

int Exoskeleton::get_possibility(){
	return avoid_possibility;
}

int Exoskeleton::get_healthpower(){
	return healthPower;
}

void Exoskeleton::set_damage(int a){
	if(wide_damage -a>=0)									//this variable cannot be a negative number
		wide_damage = wide_damage -a;
	else
		wide_damage=0;
}

void Exoskeleton::set_defence(int a){
	if(amount_defence - a>=0)								//this variable cannot be a negative number
		amount_defence = amount_defence - a;
	else
		amount_defence=0;
}

void Exoskeleton::set_poss( int a){
	if(avoid_possibility-a>=0)								//this variable cannot be a negative number
		avoid_possibility = avoid_possibility - a;
	else
		avoid_possibility=0;	
}
void Exoskeleton::set_healthpower(int a){
	if(healthPower-a>=0)									//this variable cannot be a negative number
		healthPower=healthPower-a;
	else
		healthPower=0;
}

void Exoskeleton::increase_healthpower(){
	healthPower=healthPower+ 10;
	if(healthPower>60)
		healthPower=60;
}

void Exoskeleton::attack(Hero* H){							//the Exoskeleton attacks to a hero
	int damage,possibility,count;
	possibility=H->get_agility()/3;							//the possibility depends on the agility of the hero
	count=rand()/10+1;
	if(count>possibility){									//if the hero didn't manage to avoid the attack
		if(H->get_armor()==true){							//if the hero wears an armor the damage is less
			cout<<"The hero wears an armor"<<endl;
			damage=rand()%10 +wide_damage-5;
		}
		else
			damage=rand()%10 +wide_damage;
		H->decrease_healthPower(damage);
	}
	else
		cout<<"The hero avoided the attack"<<endl;
}

Spirit::Spirit(string N,int L, int H_P, int W_D, int A_D, int A_P): Monster(N,L,H_P,W_D,A_D,A_P){
	avoid_possibility=avoid_possibility+10;					//spirits have more possibilities to avoid an attack than the other monsters
	cout<<"a spirit has created"<<endl;
}

Spirit::~Spirit(){
	cout<<"a spirit has deleted"<<endl;
}

void Spirit::displayStats(){
	cout<<"Spirit with name: "<< name<< " is in level: "<< level<<", his healthPower is: "<< healthPower;
	cout<<" his wide of damage is: "<<wide_damage<<", his amount of defence is: "<<amount_defence<<" and his possibility to avoid an attack is: "<<(avoid_possibility)<<"%"<<endl;
}

int Spirit::get_defence(){
	return amount_defence;
}

int Spirit::get_possibility(){
	return avoid_possibility;
}

int Spirit::get_healthpower(){
	return healthPower;
}

void Spirit::set_damage(int a){
	if(wide_damage -a>=0)									//this variable cannot be a negative number
		wide_damage = wide_damage -a;
	else
		wide_damage=0;
}

void Spirit::set_defence(int a){
	if(amount_defence - a>=0)								//this variable cannot be a negative number
		amount_defence = amount_defence - a;
	else
		amount_defence=0;
}

void Spirit::set_poss( int a){
	if(avoid_possibility-a>=0)								//this variable cannot be a negative number
		avoid_possibility = avoid_possibility - a;
	else
		avoid_possibility=0;	
}

void Spirit::set_healthpower(int a){
	if(healthPower-a>=0)									//this variable cannot be a negative number
		healthPower=healthPower-a;
	else
		healthPower=0;
}

void Spirit::increase_healthpower(){
	healthPower=healthPower+ 10;
	if(healthPower>60)
		healthPower=60;
}

void Spirit::attack(Hero* H){								//the Spirit attacks to a hero
	int damage,possibility,count;
	possibility=H->get_agility()/3;							//the possibility depends on the agility of the hero
	count=rand()/10+1;
	if(count>possibility){									//if the hero didn't manage to avoid the attack
		if(H->get_armor()==true){							//if the hero wears an armor the damage is less
			cout<<"The hero wears an armor"<<endl;
			damage=rand()%10 +wide_damage-5;
		}
		else
			damage=rand()%10 +wide_damage;
		H->decrease_healthPower(damage);
	}
	else
		cout<<"The hero avoided the attack"<<endl;
}
