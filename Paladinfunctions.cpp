#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Herofunctions.cpp"

using namespace std;

Paladin::Paladin(string N,int L, int H_P, int M_P, int S,int D, int A, int M, int E): Hero(N,L,H_P,M_P,S,D,A,M,E){
	dexterity=dexterity+8; // Paladin has more dexterity , strength than  sorcerer and warrior
	strength=strength+15;
	cout<<"a paladin has been created"<<endl;
}

Paladin::~Paladin(){
	cout<<"a paladin has been deleted"<<endl;
}

void Paladin::LevelUp(){							// when the paladins level up , gain some extra strength and dexterity
	Hero::LevelUp();
	dexterity=dexterity+8;
	strength=strength+15;
}

int Paladin::checkInventory(){
	vector<Item*>::iterator it;
	vector<Spell*>::iterator at;
	int j=1;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	if(listofItems.empty()==true && listofSpells.empty()==true){
		cout<<"You have no item/spell"<<endl;
		return -1;
	}
	for(it=listofItems.begin(); it != listofItems.end(); ++it){
 		if ((*it)->get_cha()== 0) // if the item is a weapon
			if ( flag1== false){ // if it is the first weapon
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\thands"<<endl;
				flag1 = true;
			}
		if ((*it)->get_cha() == 1) // if the item is an armor
			if ( flag2 == false){ // if it is the first armor
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<endl;
				flag2 = true;
			}
		if ((*it)->get_cha() == 2) // if the item is a potion
			if ( flag3 == false){ // if it is the first potion
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tincreases"<<endl;
				flag3 = true;
			}
		cout<<j<<".";
		(*it)->ShowInfo();  // show the items
		j++;
	}
	flag1 = false;
	flag2 = false;
	flag3 = false;
	for(at=listofSpells.begin();at!=listofSpells.end(); at++){
		if ((*at)->get_charac() == 1) // if the spell is an icespell
			if ( flag1 == false){
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag1 = true;
			}
		if ((*at)->get_charac() == 2) // if the spell is an firespell
			if ( flag2 == false){
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag2 = true;
			}
		if ((*at)->get_charac() == 3) // if the spell is a lighthingspell
			if ( flag3 == false){
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag3 = true;
			}
		cout<<j<<".";		
		(*at)->ShowInfo();
		j++;
	}
}

bool Paladin::BuyItem(Item& it){
	if (it.get_minlevel()<= this->getlevel()){ // if he is in a  level where he can buy this item 
		if (this->get_money()>= it.get_price()){ // and if he has enough money 
			money=money-it.get_price();
			listofItems.push_back(&it); // he buys it
			cout<<"You have "<<money<<" money"<<endl;
			return true;
		}
		else
			return false;
	}
	return false;
}

bool Paladin::BuySpell(Spell& it){
	if (it.get_minlevel()<= this->getlevel()){
		if (this->get_money()>= it.get_price()){
			money=money-it.get_price();
			listofSpells.push_back(&it);
			cout<<"You have "<<money<<" money"<<endl;
			return true;
		}
		else 
			return false;
	}
	return false;
}

vector <Item*>:: iterator Paladin::sellItem(int a){
	vector<Item*>::iterator it,at;
	int count=0,price;
	for(it=listofItems.begin(); it != listofItems.end(); ++it){
		cout<<"count="<<count<<endl;
		if(count==a-1){ // when we found the itm we want to sell
			price=(*it)->get_price(); 
			money=money+(price/2);   // we sell the item in the half price of his initial price
			return it; // we return the item we want to sell
		}
		count++;
	}
}

vector <Spell*>:: iterator Paladin::sellSpell(int a){
	vector<Spell*>::iterator it,at;
	int count=0,price;
	for(it=listofSpells.begin(); it != listofSpells.end(); ++it){
		if(count==a-1){
			price=(*it)->get_price();
			money=money+(price/2);
			return it;
		}
		count++;
	}
}

int Paladin::getsize(){
	return listofItems.size();
}

void Paladin::delete_Item(vector <Item*>:: iterator it){
	listofItems.erase(it);
}

void Paladin::delete_Spell(vector <Spell*>:: iterator it){
	listofSpells.erase(it);
}

void Paladin::displayStats(){
	cout<<"Paladin with name: "<< name<< " is in level: "<< level<<", his healthPower is: "<< healthPower;
	cout<<" his strength is: "<< strength<<", his dexterity is: "<< dexterity<< " and his agility is: "<<agility<< endl;
}

void Paladin::use(){
	vector<Item*>::iterator it;
	int j=1,count=1,increase,characterisitc,a;
	bool flag3 = false;
	for(it=listofItems.begin(); it != listofItems.end(); ++it){  // it shows the potions that the hero have
		if((*it)->get_cha()==2){ // if the item is a potion
			if ( flag3 == false){ // if it is the first potion
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tincreases"<<endl;
				flag3 = true;
			}
			cout<<j<<".";
			(*it)->ShowInfo();
			j++;
		}
	}
	if(j>1){ // if the wardrobe has at least one potion
		cout<<"Choose the Potion you want to use"<<endl;
		cin>>a;
		if(a==0 || a>=j){
			cout<<"Wrong input"<<endl;
			return;
		}
		for(it=listofItems.begin(); it != listofItems.end(); ++it){
			if((*it)->get_cha()==2){
				if(a==count)
					break;
				count++;
			}
		}
		increase=10;
		characterisitc=(*it)->get_characteristic();
		//the potion raises different fields depending on its type 
		if(characterisitc==0)
			strength=strength+increase;
		else if(characterisitc==1)
			dexterity=dexterity+increase;
		else
			agility=agility+increase;
		listofItems.erase(it);
		cout<<"You can use this potion"<<endl;
	}
	else
		cout<<"You have no potion to use"<<endl;
}

void Paladin::equip(int number){
	int i=1, ch;
	vector<Item*>::iterator it;
	WearingItems.clear(); // when a hero enters his wardrobe , he removes his weapons / armors
	this->set_armor(false);
	bool flag1 = false;
	bool flag2 = false; 
	bool flag3 = false;
	for(it=listofItems.begin(); it != listofItems.end(); ++it){
		if((*it)->get_cha()!=2){ // if the item is not a potion , show its info
	 		if ((*it)->get_cha()== 0) // if the item is a weapon
			if ( flag1== false){ // if it is the first weapon
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\thands"<<endl;
				flag1 = true;
			}
		if ((*it)->get_cha() == 1) // if the item is an armor
			if ( flag2 == false){ // if it is the first armor
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<endl;
				flag2 = true;
			}
			cout << i <<".";
			(*it)->ShowInfo();
			i++;
		}
	}
	if(i==1){
		cout<<"You have no weapon/armor"<<endl;
		return;
	}
	do {
		do{
			cout << " choose the items you want , when you finish press 0"<< endl;
			cin >> ch;
			if(ch>i-1){
				cout<<"Error! Try again!"<<endl;
			}
		}while(ch>i-1);
		int j=1;
		for(it=listofItems.begin(); it != listofItems.end(); ++it){
			if ( j== ch){ // if we find the item the hero wants to wear 
				if ( (*it)->get_cha() == 0){ // if it is a weapon
					if (this->get_freehands() >= (*it)->get_hands()){ // if he has enough free hands to keep it
						this->set_freehands(this->get_freehands()-(*it)->get_hands()); 
						this->WearingItems.push_back(*it); // he wears it
						cout << " You can use this Weapon" <<endl;
					}
					else 
						cout << " You cannot use this Weapon" <<endl;
				}
				else if ((*it)->get_cha()==1 ){ // if the item is an armor 
					if (this->get_armor()==false){ // if he doesnt wear an armor already 
						this->WearingItems.push_back(*it);
						cout <<" you can wear this armor "<<endl;
						this->set_armor(true);
					}
					else 
						cout <<" you cannot wear this armor "<<endl;					
				}
			}
			j++;
		}
	}while (ch!=0);
}

int Paladin::attack(int number,vector<Monster*> *FightMonster){
	cout<<"Do you want to choose an other weapon/armor? (YES/NO)"<<endl;
	string ch;
	cin>>ch;
	int damage,defence,possibility;
	if(ch=="YES")
		this->equip(number); // he wears this item ( weapon or armor )
	vector<Item*>::iterator it;
	vector<Monster*>::iterator at;
	int i,count=1;
	if (WearingItems.empty()!=true){ // if he wears an armor or a weapon
		for(it=WearingItems.begin(); it != WearingItems.end(); ++it){
			if((*it)->get_cha()==0){ // if he wears a weapon
				for(at=(*FightMonster).begin(); at != (*FightMonster).end(); ++at){ // show the statistics of the monsters
					cout<<count<<")";
					count++;
					(*at)->displayStats();
				}
				cout<<"Choose the monster you want to attack to"<<endl;
				int a;
				cin>>a;
				damage=(*it)->get_damage()+strength; // damage  caused to the  monster
				count=1;
				for(at=(*FightMonster).begin(); at != (*FightMonster).end(); ++at){
					if(count==a){ // when we find the monster to which we want to attack 
						defence=(*at)->get_defence();
						possibility=(*at)->get_possibility();
						int key;
						key=(rand()%10+1) *10;
						if(key>possibility){ // if it does not avoid the attack
							cout<<"i heat the monster"<<endl;
							if(damage-defence>0)  
								(*at)->set_healthpower(damage-defence);
							if((*at)->get_healthpower()==0){ // if the monster has no healthpower left , hero killed it
								if((*FightMonster).size()==1){
									(*FightMonster).erase(at);
									cout<<"I killed all the monsters"<<endl;
									return 1;
								}
								else{
									(*FightMonster).erase(at);
									cout<<"i killed a monster"<<endl;
									return 0;
								}
							}
						}
						else
							cout<<"the monster avoided the attack"<<endl;
					}
					count++;
				}
			}
		}
	}
	return 0;
}

int Paladin::castSpell( vector<Monster*> FightMonster, int round_now ){
	int i =1 , ch , rounds = 0;
	vector <Spell*> :: iterator it;
	vector<Monster*> :: iterator at;
	int k = 1;	
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	for(it=listofSpells.begin(); it != listofSpells.end(); ++it){ // it shows the info for all the spells
		if ((*it)->get_charac() == 1)
			if ( flag1 == false){
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag1 = true;
			}
		if ((*it)->get_charac() == 2) // if the spell is an firespell
			if ( flag2 == false){
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag2 = true;
			}
		if ((*it)->get_charac() == 3) // if the spell is a lighthingspell
			if ( flag3 == false){
				cout <<"code"<<"\tname"<<"\t\tprice"<<"\tlevel"<<"\tdamage"<<"\tenergy"<<endl;
				flag3 = true;
			}
		cout << k <<".";
		k++;
		(*it)->ShowInfo();
	}
	if(listofSpells.size()==0){
		cout<<"You have no spell"<<endl;
		return 0;
	}	
	cout <<" Choose the spells that you want to use "<<endl;
	cin >> ch;
	for(it=listofSpells.begin(); it != listofSpells.end(); ++it){
		if ( i == ch ){ // when it finds the spell that the hero wants to use
			if ((*it)->get_minlevel()<= this->getlevel()){ // if he is in a level where he can use this spell
				int P= this->get_magicPower();// p is the magic power that required the spell to be casted
				P = P- ( (*it)->get_energy()); // the magic energy of the spell reduces hero's energy 
				if(P<0){
					cout<<"Your magic power is not enough to cast this spell"<<endl;
					return 0;
				}
				this->set_magicPower(P);
				cout << " Choose in which monster you want to cast the Spell "<<endl;
				int l =1;
				for(at=FightMonster.begin(); at != FightMonster.end(); ++at){
					cout << l <<")";
					l++;
					(*at)->displayStats();
				}
				int ch;
				cin >> ch;
				int j = 1;
				for(at=FightMonster.begin(); at != FightMonster.end(); ++at){
					if ( ch == j){ // when we find the monster in which we want to cast the spell
						int possibility=(*at)->get_possibility();
						int key;
						key=(rand()%10+1) *10;
						if ( key> possibility ){ // if the monster  can not avoid the attack with the spell
							int a = this->get_dexterity(); 
							a = a*3;
							// a is the damage that is caused in the monster form the spell
							if ( a >= (*it)->get_damage())
								a = (*it)->get_damage();
							(*at)->set_healthpower(a);
							if((*at)->get_healthpower()<=0){ // when the health power of the monster is 0 , it means that the monster has been killed
								if((FightMonster).size()==1){
									(FightMonster).erase(at);
									cout<<"I killed all the monsters"<<endl;
									return 1;
								}
								else{
									(FightMonster).erase(at);
									cout<<"i killed a monster"<<endl;
									return 0;
								}
							}
							cout <<" Hero's magic power has been decreased by " << (*it)->get_energy() <<endl;
							cout <<" Monster's health power has been decreased by " << a << endl;
							//according to the type of the spell , the spell reduces different elements at the monster
							if ( (*it)->get_charac() == 1){
								rounds = rand()%4 +1;
								cout << "The wide damage of your enemy has been decreased  by 10 for " << rounds << "rounds " <<endl;
								if((*at)->get_roundfordamage()==0)
									(*at)->set_damage(10);
								(*at)->set_roundfordamage(round_now+rounds);
								return 0; 
							}
							else if ( (*it)->get_charac()== 2){
								rounds = rand()%4 +1;
								cout <<" The amount of defence of your enemy has been decreased by 5 for "<<rounds <<" rounds" <<endl;
								if((*at)->get_roundfordefence()==0)
									(*at)->set_defence(5);
								(*at)->set_roundfordefence(round_now+rounds);
								return 0; 
							}
							else {
								rounds = rand()%4 +1;
								cout <<" The possibility of avoiding an attack of  your enemy has been decreased by 5 for "<<rounds <<" rounds" <<endl;
								if((*at)->get_roundforpossibility()==0)
									(*at)->set_poss(5);
								(*at)->set_roundforpossibility(round_now+rounds);
								return 0; 
							}
						}
						else {
							cout << "The monster avoided the attack!" <<endl;
							return 0;
						}
					}
					j++;
				}
			}
			else{
				cout << " You cannot use this Spell " <<endl;
				cout << "Do you want to choose again? (YES/N0) " <<endl;
				string a;
				cin >> a;
				if ( a =="YES"){
					 this->castSpell(FightMonster,round_now);
				}
				else 
					return 0;
			}
		}
		i++;		
	}
	cout<<"Error! You should choose one of the spells you have"<<endl;
	return 0;
}

bool Paladin::get_armor(){
	return armor;
}

int Paladin::get_magicPower(){
	return magicPower;	
}

void Paladin::increase_magicPower(){
	magicPower=magicPower+ (magicPower)/4;
	if(magicPower>50)
		magicPower=50;
}

int Paladin::get_healthPower(){
	return healthPower;
}

void Paladin::increase_healthPower(bool alive){
	if(alive==true){
		healthPower=healthPower+15;
		if(healthPower>100)
			healthPower=100;
	}
	else
		healthPower=50;
}

void Paladin::decrease_healthPower(int i){
	healthPower=healthPower-i;
	if(healthPower<0){
		healthPower=0;
		cout<<"The Hero is dead"<<endl;
	}
}

int Paladin::get_dexterity(){
	return dexterity;
}

int Paladin::get_agility(){
	return agility;
}

void Paladin::set_magicPower(int a){
	magicPower = a;
}
