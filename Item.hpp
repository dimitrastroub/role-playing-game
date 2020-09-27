#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

class Item{
	protected:
		string name;
		int price;
		int min_level;
	public:
		Item(string,int, int);
		~Item();
		void virtual ShowInfo()=0;
		virtual int get_minlevel()=0;
		virtual int get_price()=0;
		virtual int get_characteristic()=0;
		virtual int get_hands()=0;
		virtual int get_cha()=0;
		virtual int get_damage()=0;
};

class Weapon: public Item {
	int cha;														//for weapons cha=0
	int damage;
	int hands;
public:
	Weapon(string,int, int,int,int);
	~Weapon();
	void virtual ShowInfo();
	virtual int get_minlevel();
	virtual int get_price();
	virtual int get_increase();
	virtual int get_characteristic();
	virtual int get_hands();
	virtual int get_cha();
	virtual int get_damage();
};

class Armor : public Item {
	int cha;														//for armors cha=1
public:
	Armor(string,int, int);
	~Armor();
	void virtual ShowInfo();
	virtual int get_minlevel();
	virtual int get_price();
	virtual int get_increase();
	virtual int get_characteristic();
	virtual int get_cha();
	virtual int get_hands();
	virtual int get_damage();
};

class Potion : public Item {
	int cha;														//for potions cha=2
	int characteristic;												//0 for strength, 1 for dexterity and 2 for agility
public :
	Potion(string,int,int,int);
	~Potion();
	void virtual ShowInfo();
	virtual int get_minlevel();
	virtual int get_price();
	int get_characteristic();
	virtual int get_cha();
	virtual int get_hands();
	virtual int get_damage();
};
