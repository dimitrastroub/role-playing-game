#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Warriorfunctions.cpp"

using namespace std;

class Market{
	vector<Item*> Itemsforsale;
	vector<Spell*> Spellsforsale;
	public:
		Market();
		~Market();
		void insert_Item(Item&);
		void insert_Spell(Spell&);
		void delete_Item(int);
		void delete_Spell(int);
		void displayMenu();
		void CreateMarket();
		int get_size();
		Item* get_Item(int);
		Spell* get_Spell(int);
};
