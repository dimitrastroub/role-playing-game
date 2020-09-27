#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "Itemfunctions.cpp"
#include "Spellfunctions.cpp"

using namespace std;

class Monster;

class Living {
	protected:
		string name;
		int level;
		int healthPower;
	public :
		Living(string N,int L, int H_P);
		virtual ~Living();
		bool check_fails();
		virtual void displayStats()=0;
		int getlevel();
};

class Hero : public Living {
	protected:
	int magicPower;
	int strength;
	int dexterity;
	int agility;
	int money;
	int experience;
	int freehands;
	bool armor;
	vector<Item*> listofItems;
	vector<Spell*> listofSpells;
	vector<Item*> WearingItems;
public :
	Hero(string N,int L, int H_P, int M_P, int S,int D, int A, int M, int E);
	virtual ~Hero();
	virtual void LevelUp();
	virtual void equip(int)=0;
	virtual void use()=0;
	void printInfo();
	int get_freehands();
	void set_freehands(int);
	virtual void displayStats()=0;
	virtual bool BuyItem(Item&) = 0;
	virtual bool BuySpell(Spell&) = 0;
	int get_money();
	void set_money(int,int);
	void set_experience(int);
	virtual int checkInventory()=0;
	virtual int getsize()=0;
	virtual vector <Item*>:: iterator sellItem(int)=0;
	virtual vector <Spell*>:: iterator sellSpell(int)=0;
	virtual void delete_Item(vector <Item*>:: iterator)=0;
	virtual void delete_Spell(vector <Spell*>:: iterator)=0;
	virtual bool get_armor()=0;
	void set_armor(bool);
	virtual int attack(int,vector<Monster*>*)=0;
	virtual int castSpell(vector<Monster*>,int)=0;
	virtual int get_magicPower()=0;
	virtual void increase_magicPower()=0;
	virtual int get_healthPower()=0;
	virtual void increase_healthPower(bool)=0;
	virtual void decrease_healthPower(int)=0;
	virtual int get_dexterity()=0;
	virtual int get_agility()=0;
	virtual void set_magicPower(int)=0;
};

class Warrior : public Hero {
public :
	Warrior(string N,int L, int H_P, int M_P, int S,int D, int A, int M, int E);
	~Warrior();
	void LevelUp();
	virtual void displayStats();
	virtual bool BuyItem(Item&) ;
	virtual bool BuySpell(Spell&) ;
	virtual int checkInventory();
	virtual vector <Item*>:: iterator sellItem(int);
	virtual vector <Spell*>:: iterator sellSpell(int);
	virtual int getsize();
	virtual void delete_Item(vector <Item*>:: iterator);
	virtual void delete_Spell(vector <Spell*>:: iterator);
	virtual bool get_armor();
	virtual void use();
	virtual void equip(int);
	virtual int attack(int,vector<Monster*>*);
	virtual int castSpell(vector<Monster*>,int);
	virtual int get_magicPower();
	virtual void increase_magicPower();
	virtual int get_healthPower();
	virtual void increase_healthPower(bool);
	virtual void decrease_healthPower(int);
	virtual int get_dexterity();
	virtual int get_agility();
	virtual void set_magicPower(int);
};

class Sorcerer : public Hero {
public :
	Sorcerer(string N,int L, int H_P, int M_P, int S,int D, int A, int M, int E);
	~Sorcerer();
	void LevelUp();
	virtual void displayStats();
	virtual bool BuyItem(Item&) ;
	virtual bool BuySpell(Spell&) ;
	virtual int checkInventory();
	virtual vector <Item*>:: iterator sellItem(int);
	virtual vector <Spell*>:: iterator sellSpell(int);
	virtual int getsize();
	virtual void delete_Item(vector <Item*>:: iterator);
	virtual void delete_Spell(vector <Spell*>:: iterator);
	virtual bool get_armor();
	virtual void use();
	virtual void equip(int);
	virtual int attack(int,vector<Monster*>*);
	virtual int castSpell(vector<Monster*>,int);
	virtual int get_magicPower();
	virtual void increase_magicPower();
	virtual int get_healthPower();
	virtual void increase_healthPower(bool);
	virtual void decrease_healthPower(int);
	virtual int get_dexterity();
	virtual int get_agility();
	virtual void set_magicPower(int);
};

class Paladin : public Hero {
public :
	Paladin(string N,int L, int H_P, int M_P, int S,int D, int A, int M, int E);
	~Paladin();
	void LevelUp();
	virtual void displayStats();
	virtual bool BuyItem(Item&) ;
	virtual bool BuySpell(Spell&) ;
	virtual int checkInventory();
	virtual vector <Item*>:: iterator sellItem(int);
	virtual vector <Spell*>:: iterator sellSpell(int);
	virtual int getsize();
	virtual void delete_Item(vector <Item*>:: iterator);
	virtual void delete_Spell(vector <Spell*>:: iterator);
	virtual bool get_armor();
	virtual void use();
	virtual void equip(int);
	virtual int attack(int,vector<Monster*>*);
	virtual int castSpell(vector<Monster*>,int);
	virtual int get_magicPower();
	virtual void increase_magicPower();
	virtual int get_healthPower();
	virtual void increase_healthPower(bool);
	virtual void decrease_healthPower(int);
	virtual int get_dexterity();
	virtual int get_agility();
	virtual void set_magicPower(int);
};

class Monster : public Living {
	protected:
		int wide_damage;
		int amount_defence;
		int avoid_possibility;
		int roundfordamage;
		int roundfordefence;
		int roundforpossibility;
	public :
		Monster(string,int,int,int,int,int);
		virtual ~Monster();
		virtual void displayStats()=0;
		virtual int get_defence()=0;
		virtual int get_possibility()=0;
		virtual int get_healthpower()=0;
		virtual void set_damage(int) = 0;
		virtual void set_defence(int) = 0 ;
		virtual void set_poss(int ) = 0;
		virtual void set_healthpower(int)=0;
		virtual void increase_healthpower()=0;
		virtual void attack(Hero*)=0;
		void set_roundfordamage(int);
		void set_roundfordefence(int);
		void set_roundforpossibility(int);
		int get_roundfordamage();
		int get_roundfordefence();
		int get_roundforpossibility();
};

class Dragon : public Monster {
public :
	Dragon(string,int,int,int,int,int);
	~Dragon();
	virtual void displayStats();
	virtual int get_defence();
	virtual int get_possibility();
	virtual int get_healthpower();
	virtual void set_damage(int);
	virtual void set_defence(int);
	virtual void set_poss(int );
	virtual void set_healthpower(int);
	virtual void increase_healthpower();
	virtual void attack(Hero*);
};


class Exoskeleton : public Monster {
public :
	Exoskeleton(string,int,int,int,int,int);
	~Exoskeleton();
	virtual void displayStats();
	virtual int get_defence();
	virtual int get_possibility();
	virtual int get_healthpower();
	virtual void set_damage(int);
	virtual void set_defence(int);
	virtual void set_poss(int );
	virtual void set_healthpower(int);
	virtual void increase_healthpower();
	virtual void attack(Hero*);
};


class Spirit : public Monster {
public :
	Spirit(string,int,int,int,int,int);
	~Spirit();
	virtual void displayStats();
	virtual int get_defence();
	virtual int get_possibility();
	virtual int get_healthpower();
	virtual void set_damage(int);
	virtual void set_defence(int);
	virtual void set_poss(int );
	virtual void set_healthpower(int);
	virtual void increase_healthpower();
	virtual void attack(Hero*);
};
