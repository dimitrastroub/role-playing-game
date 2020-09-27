#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Market.hpp"
#include <sstream>

using namespace std;

Market::Market(){
	cout<<" a market has created"<<endl;
}

Market::~Market(){
	cout<<"a market has been deleted"<<endl;
}

void Market::insert_Item(Item &I){									//it inserts an item in the list of items that Market has
	Itemsforsale.push_back(&I);
}

void Market::insert_Spell(Spell &S){								//it inserts a spell in the list of spells that Market has
	Spellsforsale.push_back(&S);
}

void Market::delete_Item(int i){									//it deletes an item from the list of items that Market has
	vector<Item*>::iterator it;
	int count=0;
	for(it=Itemsforsale.begin(); it != Itemsforsale.end(); ++it){	//it searches in the list of items
		if(count==i){												//and when it finds the item
				Itemsforsale.erase(it);								//it removes it from the list
				return;
		}
		count++;
	}
}

void Market::delete_Spell(int i){									//it deletes a spell from the list of spells that Market has
	vector<Spell*>::iterator it;
	int count=0;
	for(it=Spellsforsale.begin(); it != Spellsforsale.end(); ++it){	//it searches in the list of spells
		if(count==i){												//and when it finds the spell
				Spellsforsale.erase(it);							//it removes it from the list
				return;
		}
		count++;
	}
}

void Market::displayMenu(){
	vector<Item*>::iterator it;
	vector<Spell*>::iterator at;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	int j=1;
	for(it=Itemsforsale.begin(); it != Itemsforsale.end(); ++it){
 		if ((*it)->get_cha()== 0)															//if it is a weapon
			if ( flag1== false){															//before the first weapon it prints the names of the characteristics
				cout<<"WEAPONS LIST"<<endl; 
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\thands"<<endl;
				flag1 = true;
			}
		if ((*it)->get_cha() ==1 )															//if it is an armor
			if ( flag2 == false){															//before the first armor it prints the names of the characteristics
				cout <<" ARMORS LIST" <<endl;
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<endl;
				flag2 = true;
			}
		if ((*it)->get_cha() == 2)															//if it is a potion
			if ( flag3 == false){															//before the first potion it prints the names of the characteristics
				cout <<" POTIONS LIST"<<endl;
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tincreases"<<endl;
				flag3 = true;
			}
		cout<<j<<".";
		(*it)->ShowInfo();																	//and then it prints the information of each item
		j++;
	}
	flag1 = false;
	flag2 = false;
	flag3 = false;
	for(at=Spellsforsale.begin();at!=Spellsforsale.end(); at++){
		if ((*at)->get_charac() == 1)														//if it is a, icespell
			if ( flag1 == false){															//before the first icespell it prints the names of the characteristics
				cout <<"ICESPELLS LIST"<<endl;
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag1 = true;
			}
		if ((*at)->get_charac() == 2)														//if it is a firespell
			if ( flag2 == false){															//before the first firespell it prints the names of the characteristics
				cout <<" FIRESPELLS LIST "<<endl;
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag2 = true;
			}
		if ((*at)->get_charac() == 3)														//if it is a lightingspell
			if ( flag3 == false){															//before the first lightingspell it prints the names of the characteristics
				cout <<" LIGHTINGSPELLS LIST "<<endl;
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\twdamage"<<"\tenergy"<<endl;
				flag3 = true;
			}
		cout<<j<<".";		
		(*at)->ShowInfo();																	//and then it prints the information of each spell
		j++;
	}
}

int Market::get_size(){
	return Itemsforsale.size();	
}

Item* Market::get_Item(int d){																//it searches an item from the list when it knows it's position
	vector<Item*>::iterator it;
	int i=0;
	for(it=Itemsforsale.begin(); it != Itemsforsale.end(); ++it){							//it searces in the list
		if ( i == d-1){																		//when it finds it
			return (*it);																	//it returns it
		}
		i++;
	}
}

Spell* Market::get_Spell(int d){															//it searches a spell from the list when it knows it's position
	vector<Spell*>::iterator it;
	int i=0;
	for(it=Spellsforsale.begin(); it != Spellsforsale.end(); ++it){							//it searces in the list
		if ( i == d-1){																		//when it finds it
			return (*it);																	//it returns it
		}
		i++;
	}
}

void Market::CreateMarket(){
	int weap= rand()%9+1;
	int arm = rand()%9+1;
	int pot = rand()%9+1;
	int i;
	string str,N;
	for (i=0 ; i< weap; i++){																//it creates the weapons and it initializes all the data-members
		ostringstream os;
		os << (i+1);
		str = os.str();
		N= "Weapon"+str;
		int price = rand()%50+1;
		int level = rand()%5+1;
		int damage = rand()%20+1;
		int hands= rand()%2 +1;
		Weapon* W= new Weapon(N,price, level, damage, hands);
		this->insert_Item(*W);																//it inserts the weapon it the list of the market
	}
	for ( i=0 ; i<arm; i++){																//it creates the armors and it initializes all the data-members
		ostringstream os;
		os << (i+1);
		str = os.str();
		N= "Armor"+str;
		int price = rand()%40+1;
		int level = rand()%5+1;
		Armor* A=new Armor(N, price, level);
		this->insert_Item(*A);																//it inserts the armor it the list of the market
	}
	for (i =0; i<pot; i++){																	//it creates the potions and it initializes all the data-members
		ostringstream os;
		os << (i+1);
		str = os.str();
		N= "Potion"+str;
		int price = rand()%50+1;
		int level = rand()%5+1;
		int characteristic = rand()%3;
		Potion* P=new Potion(N, price , level , characteristic);	
		this->insert_Item(*P);																//it inserts the potion it the list of the market
	}
	int fire = rand()%9+1;
	int ice = rand()%9+1;
	int light = rand()%9+1;
	for (i =0 ; i<fire; i++){																//it creates the firespells and it initializes all the data-members
		ostringstream os;
		os << (i+1);
		str = os.str();
		N= "FireSpell"+str;		
		int price = rand()%20+60;
		int level = rand()%5+1;
		int damage = rand()%20+1;
		int energy = rand()%20+10;
		FireSpell* F= new FireSpell(N, price, level, damage, energy);						//it inserts the firespell it the list of the market
		this->insert_Spell(*F);
	}
	for ( i = 0; i<=ice; i++){																//it creates the icespells and it initializes all the data-members
		ostringstream os;
		os << (i+1);
		str = os.str();
		N= "IceSpell"+str;
		int price = rand()%20+60;
		int level = rand()%5+1;
		int damage = rand()%20+1;
		int energy = rand()%20+10;
		IceSpell* I=new IceSpell(N, price, level, damage, energy);
		this->insert_Spell(*I);																//it inserts the icespell it the list of the market
	}
	for ( i =0; i<light; i++){																//it creates the lightingspells and it initializes all the data-members
		ostringstream os;
		os << (i+1);
		str = os.str();
		N= "LightingSpell"+str;		
		int price = rand()%20+60;
		int level = rand()%5+1;
		int damage = rand()%20+1;
		int energy = rand()%20+10;
		LightingSpell* L=new LightingSpell(N, price, level, damage, energy);
		this->insert_Spell(*L);																//it inserts the lightingspell it the list of the market
	}
}
