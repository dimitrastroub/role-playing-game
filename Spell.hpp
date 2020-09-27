#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Spell {
	protected:
		string name;
		int price;
		int min_level;
		int wide_damage;
		int magic_energy;
		int charac;									//1 for IceSpells , 2 for FireSpells, 3 for LightingSpells
	public :
		Spell(string,int,int,int,int);
		~Spell();
		virtual void ShowInfo()=0;
		int get_price();
		int get_minlevel();
		virtual int get_energy()= 0;
		virtual int get_charac() = 0;
		void set_rounds(int);
		int get_damage();
};

class IceSpell : public Spell{
	public :
		IceSpell(string,int,int,int,int);
		~IceSpell();
		virtual void ShowInfo();
		virtual int get_energy();
		virtual int get_charac();
};

class FireSpell : public Spell {
	public :
		FireSpell(string,int,int,int,int);
		~FireSpell();
		virtual void ShowInfo();
		virtual int get_energy();
		virtual int get_charac();
};

class LightingSpell : public Spell {
	public :
		LightingSpell(string,int,int,int,int);
		~LightingSpell();
		virtual void ShowInfo();
		virtual int get_energy();
		virtual int get_charac();
};	
