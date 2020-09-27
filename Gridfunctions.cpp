#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>
#include "Grid.hpp"

using namespace std;

Grid::Grid( int a , int  b){
	length= a;
	width = b;
	int i;
	array= new  string*[length];
	for (int i = 0; i != length; ++i)
		array[i] = new string[width];
	for(i=0;i<3;i++)
		Heros[i]=NULL;
	for(i=0;i<20;i++)
		Monsters[i]=NULL;
	cout <<"creating a Grid with legth "  <<length << " and width " << width <<endl;
}

Grid::~Grid(){
	int i;
	for(i=0;i<width;i++)
		delete[] array[i];
	delete[] array;
	cout<<"The Grid has been deleted"<<endl;
	cout <<"game over " <<endl;
}

void Grid::DispalyGrid(int number){														//it is the main function of the grid
	Market M;
	M.CreateMarket();
	vector<int> array;
	this->CreateMonsters();
	this->CreateTeam(number);
	int teamx,teamy;
	teamx=rand()%(length-2);
	teamy=rand()%(width-2);
	this->InitializeGrid(teamx,teamy);
	cout <<"\033[2J\033[1;1H";
	int i,a;
	do{																							//the main menu of the game
		cout<<"****************************************************************"<<endl;
		cout<<"* if you want to  see the Grid press 1                         *"<<endl;
		cout<<"* if you want to  see the Statistics of your heroes press 2    *"<<endl;
		cout<<"* if you want to move press 3                                  *"<<endl;
		cout<<"* if you want to see your items/spells press 4                 *"<<endl;
		cout<<"* if you want to equip press 5                                 *"<<endl;
		cout<<"* if you want to use a potion press 6                          *"<<endl;
		cout<<"* if you want to quit the game press 0                         *"<<endl;
		cout<<"****************************************************************"<<endl;
		cin>>a;
		string b;
		if(a==1){
			cout <<"\033[2J\033[1;1H";
			this->displayMap();																	//it shows the Grid
		}
		else if(a==2)
			for(i=0;i<number;i++)
				this->Heros[i]->displayStats();													//it shows the statistics of the hero
		else if(a==3)
			this->Move(length, width,M,number);													//it moves the team
		else if(a==4)
			for(i=0;i<number;i++){
				cout<<"Hero number "<< i+1<<endl;
				this->Heros[i]->checkInventory();												//it shows the items/spells the hero has
			}
		else if(a==5)
			for(i=0;i<number;i++){
				cout<<"Hero number "<< i+1<<endl;
				this->Heros[i]->equip(number);													//it helps the hero to use a weapon or to wear an armor
			}
		else if(a==6)
			for(i=0;i<number;i++){
				cout<<"Hero number "<< i+1<<endl;
				this->Heros[i]->use();															//it helps the hero to use a potion
			}
		else if(a==0){
			this->quitGame(number);																//it ends the game
		}
	}while(a!=0);
}

void Grid::InitializeGrid(int teamx,int teamy){
	int i, j, x, y, count = -1 , count2 =0, init;
	string c;
	x=0;
	y=0;
	for (i =0 ; i<length; i++){
		for (j=0 ; j<width; j++){
		 init = rand()%5;
			if (init ==1||init==2||init==0)										//there will be more common boxes
				array[i][j].assign("Pass    ");									//this box is common which means that the heroes may have to fight there
			else if (init ==3)
				array[i][j].assign("Market  ");									//in this box heroes can visit the market
			else if (init==4)
				array[i][j].assign("ban     ");									//this box is not accessible
		}
	}
	array[teamx][teamy].assign("TEAM    ");
	if(teamy==7)
		array[teamx][teamy-1].assign("Market  ");								//the hero will have next to him a market 
	else
		array[teamx][teamy+1].assign("Market  ");								//the hero will have next to him a market 
	cout <<endl;
}


void Grid::displayMap(){														//it shows the grid
	int i,j;
	for (i=0;i<length;i++){
		for (j=0;j<width;j++){
			if ( array[i][j]== "TEAM    "){
				string red("\033[0;31m");
				const std::string reset("\033[0m");
				cout << red << "TEAM    " << reset;
				} 
			else
				cout <<array[i][j] ;
		}
		cout <<endl;
		cout <<endl;
	}
}

void Grid::Move(int len, int wid,Market& M,int number){
		int i,j,teamx,teamy,key;
		string c;
		string prev,keep;
		int count=0;
		for(i=0;i<len;i++)
			for(j=0;j<wid;j++)
				if(array[i][j]=="TEAM    "){											//it finds the position of the team on the grid
					teamx=i;
					teamy=j;
				}
		do{
			do {
				cout <<"\033[2J\033[1;1H";
				this->displayMap();
				cout<<"Give a,d,w,s to move , q to return to the main menu"<<endl;
				cin>>c;
				count++;
				if (count==1)
					prev="Pass    ";
			}while ((c!="a")&&(c!="d")&&(c!="w")&&(c!="s")&&(c!="q"));					//a=left, d=right,w=up, s=down, q=quit
			if (c=="w"){
				if((teamx-1)<0 || array[teamx-1][teamy].compare("ban     ")==0 ){		//it checks if the box is accessible
					cout <<"You cannot enter this box"<<endl;
					this->Move(len , wid , M , number);
				}
				else{
					keep=array[teamx-1][teamy];											
					array[teamx-1][teamy].assign("TEAM    ");							//it  moves the team
					array[teamx][teamy].assign(prev);									//it puts in the box the content that had before
					teamx--;
					prev.assign(keep);													//it saves the content of the box
				}
			}
			else if(c=="a"){
				if((teamy-1)<0 || array[teamx][teamy-1].compare("ban     ")==0){
					cout <<"You cannot enter this box"<<endl;
					this->Move(len , wid , M , number);
				}
				else{
					keep=array[teamx][teamy-1];
					array[teamx][teamy-1].assign("TEAM    ");
					array[teamx][teamy].assign(prev);
					teamy--;
					prev.assign(keep);
				}
			}
			else if( c=="s"){
				if((teamx+1)>=len || array[teamx+1][teamy].compare("ban     ")==0){
					cout <<"You cannot enter this box"<<endl;
					this->Move(len , wid , M , number);
				}
				else{
					keep=array[teamx+1][teamy];
					array[teamx+1][teamy].assign("TEAM    ");
					array[teamx][teamy].assign(prev);
					teamx++;
					prev.assign(keep);
				}
			}
			else if(c=="d"){
				if((teamy+1)>=wid || array[teamx][teamy+1].compare("ban     ")==0){
					cout <<"You cannot enter this box"<<endl;
					this->Move(len , wid , M , number);
				}
				else{
					keep=array[teamx][teamy+1];
					array[teamx][teamy+1].assign("TEAM    ");
					array[teamx][teamy].assign(prev);
					teamy++;
					prev.assign(keep);
				}
			}
			else if(c=="q"){
				cout <<"\033[2J\033[1;1H";
				return;
			}
		if (prev.compare("Market  ")==0) {
			cout <<"\033[2J\033[1;1H";
			this->Checking_Market(M,number);
			cout <<"\033[2J\033[1;1H";										//the heroes visit the market
		}
		if(prev.compare("Pass    ")==0){
			key=this->Checking_Pass(number);											//the heroes may have to fight
			if(key==2)
				c="q";
		}
	}while(c!="q");
}

void Grid::Buy(Market &M,int i){
		bool flag;
				int d ;
				M.displayMenu();															//it shows the items/spells the market has
				cout <<" choose the items/spells that you want to buy " <<endl;
				cout <<" if you want to exit market press 0 " <<endl;
				cin>>d;
				while (d!=0){
					if ( d <= M.get_size()){												//if the hero chose an item
						flag = Heros[i]->BuyItem(*(M.get_Item(d)));
						if (flag == true){													//if the hero can buy this item(has enough money and a propriate level)
							cout <<"\033[2J\033[1;1H";
							cout << "the buy was successful" <<endl;
							int mon = Heros[i]->get_money();
							cout << " You have " << mon<< " money "<<endl;
							M.delete_Item(d-1);												//we delete this item from the list of the market
							cout <<" Do you want to buy another item/spell? (YES/NO) " <<endl;
							string n;
							cin >> n;
							if ( n == "YES"){
								M.displayMenu();
							}
							else															//if he doesn't want to continue
								return;														//he returns to the menu of the market
						}
						else{																//if the hero cannot buy this item
							cout <<"you cannot buy this item" <<endl;
							cout <<" Choose another item/spell  to buy" <<endl;
						}
					}
					else{																	//if the hero chose a spell
						d=d-M.get_size();
						flag = Heros[i]->BuySpell(*(M.get_Spell(d)));
						if (flag == true){													//if the hero can buy this spell
							cout <<"\033[2J\033[1;1H";
							cout << "the buy was successful" <<endl;
							cout << " You have " <<Heros[i]->get_money()<<" money "<<endl;
							M.delete_Spell(d-1);											//we delete this spell from the list of the market
							cout <<" Do you want to buy another item/spell ? (YES/NO) " <<endl;
							string n;
							cin >> n;
							if ( n == "YES")
								M.displayMenu();
							else 															//if he doesn't want to continue
								return;														//he returns to the menu of the market
						}
						else{																//if the hero cannot buy this spell
							cout <<"you cannot buy this sell" <<endl;
							cout << " choose another item/spell to buy "<<endl;
						}
					}
					cin >> d;																//the hero chooses the next item/spell he wants to buy
				}
}

void Grid::Sell(int i,Market &M){
	int a,size,count;
	vector <Item*>:: iterator it;
	vector<Spell*>::iterator at;
	count=Heros[i]->checkInventory();
	if(count==-1)															//if the hero doesn't have anything to sell
		return;
				cout<<"Choose the items and the spells that you want to sell and press 0 to quit"<<endl;
				cin>>a;
				while(a!=0){
					size=Heros[i]->getsize();								//if the hero wants to sell an item
					if(a<=size){
						it=Heros[i]->sellItem(a);
						M.insert_Item(**it);								//we insert this item in the list of the market
						Heros[i]->delete_Item(it);							//and we delete it from the list of the hero
						cout <<"\033[2J\033[1;1H";
						cout << " You have " <<Heros[i]->get_money()<<endl;
						cout <<" Do you want to sell something else ?(YES/NO) " <<endl;
						cout << " You have " <<Heros[i]->get_money()<<" money "<<endl;
						string n;
						cin >> n;
						if ( n == "YES"){
							count=Heros[i]->checkInventory();
							if(count==-1)									//if the hero doesn't have anything to sell
								return;
						}
						else												//if the hero doesn't want to sell anything else
							return;											//he returns to the menu of the market
					}
					else{													//if the hero wants to sell a spell
						at=Heros[i]->sellSpell(a-size);
						M.insert_Spell(**at);								//we insert this spell in the list of the market
						Heros[i]->delete_Spell(at);							//and we delete it from the list of the hero
						cout <<"\033[2J\033[1;1H";
						cout << " You have " <<Heros[i]->get_money()<<endl;
						cout <<" Do you want to sell something else?(YES/NO) " <<endl;
						cout << " You have " <<Heros[i]->get_money()<<" money "<<endl;
						string n;
						cin >> n;
						if ( n == "YES"){
								count=Heros[i]->checkInventory();
								if(count==-1)								//if the hero doesn't have anything to sell
									return;
							}
						else 												//if the hero doesn't want to sell anything else
							return;											//he returns to the menu of the market
					}
					cin>>a;													//the hero chooses the next item/spell he wants to sell
				}
}

void Grid::Checking_Market(Market &M , int number){
	int i, size,a,key;
	cout<<"***********************************************************"<<endl;					//the menu of the market
	cout<<"* if you want to  buy press 1                             *" <<endl;
	cout<<"* if you want to  sell press 2                            *"<<endl;
	cout<<"* if you want to see the statistics of your heros press 3 *"<<endl;
	cout<<"* if you want to see the Grid press 4                     *"<<endl;
	cout<<"* if you want to exit market press 0                      *"<<endl;
	cout<<"***********************************************************"<<endl;
	do{
		cin>> key;
		if (key!=0&&key!=1&&key!=2&&key!=3&&key!=4){
			cout <<"\033[2J\033[1;1H";
			cout <<" please press again the number of your choise "<<endl;
		}
	}while (key!=0&&key!=1&&key!=2&&key!=3&&key!=4);
	if (key==1){
			int i;
			for(i=0;i<number;i++){
				cout << " Hero " <<i+1 <<endl;
				cout<<"does your hero want to buy anything (YES/NO)?"<<endl;
				string a;
				cin>>a;
				cout <<"\033[2J\033[1;1H";
				if(a=="YES")
					this->Buy(M,i);																//the hero wants to buy something
				if  (i == number - 1)															//if we are at the last hero
					this->Checking_Market(M,number);											//we go back to the menu of the market
			}
	}
	else if (key==2){
		for(i=0;i<number;i++){
				cout << " Hero " <<i+1 <<endl;
				cout<<"does your hero want to sell anything (YES/NO)?"<<endl;
				string a;
				cin>>a;
				cout <<"\033[2J\033[1;1H";
				if(a=="YES")
					this->Sell(i,M);															//the hero wants to sell something
				if  (i == number - 1)															//if we are at the last hero
					this->Checking_Market(M,number);											//we go back to the menu of the market
			}
		}
	if(key==3){
		for(i=0;i<number;i++)
			Heros[i]->displayStats();															//the hero wants to see the statistics of the heroes
		cout << "if you want to return in the menu of the Market press 1 , to exit Market press 0" <<endl;
		int ch;
		cin>> ch;
		cout <<"\033[2J\033[1;1H";
		if ( ch == 1){
			this->Checking_Market(M,number);													//return to the menu of the market
		}
		else if (ch == 0)
			return;																				//exit the market return to the main menu
	}
	else if(key==4){
		this->displayMap();																		//the hero wants to see the grid
		cout << "if you want to return in the menu of the Market press 1 , to exit Market press 0" <<endl;
		int ch;
		cin>> ch;
		if ( ch == 1){
			this->Checking_Market(M,number);
		}
		else if ( ch == 0)
			return;
	}
	else if(key==0)																				//exit the market
		return ;	
}

int Grid::Checking_Pass(int number){
	int key,possibility;
	possibility=rand()%10;
	if(possibility==0||possibility==1||possibility==2){											//the heroes have to fight
		cout <<"\033[2J\033[1;1H";
		cout<<"THE FIGHT STARTS!!!"<<endl;
		this->Fight(number);
		cout<<"***********************************************************"<<endl;
		cout<<"* if you want to move press 1                             *"<<endl;
		cout<<"* if you want to return to the main menu press 2          *"<<endl;
		cout<<"***********************************************************"<<endl;
		cin>> key;
		cout <<"\033[2J\033[1;1H";
		return key;
	}
}

void Grid::Fight(int number){
	int numberofmonsters,i,j,flag;
	numberofmonsters=rand()%3+1;											//the monsters that will fight with the heroes are 1,2 or 3
	int array[numberofmonsters];
	vector<Monster*> FightMonster;											//an array of the fightmonsters
	vector<Monster*>::iterator it;
	bool alive;
	for(i=0;i<numberofmonsters;i++){
		flag=0;
		int count, M_level,H_level;
		do{
			count=rand()% 20;
			M_level=Monsters[count]->getlevel();
			H_level=Heros[0]->getlevel();
		}
		while(M_level<H_level-2||M_level>H_level+2);						//the monsters must have similar level with the heroes
		if(i!=0)															//if it is not the first monster
			for(j=0;j<i;j++){												//we have to check if we have already chosen this monster from the array
				if(array[j]==count){										//if we have already chosen it we cannot take it again
					i=i-1;
					flag=1;
				}
			}
		if(flag==0){														//if we have not already chosen it
			array[i]=count;
			FightMonster.push_back(Monsters[count]);						//we insert it in the array of fightmonsters
		}
	}
	int key=0;
	int ch,rounds=1,rounds_now ,a, b , c;
	do{
		cout<< "ROUND "<<rounds<<endl;
		for(it=FightMonster.begin(); it != FightMonster.end(); ++it){
			if(rounds==(*it)->get_roundfordamage()){
				(*it)->set_damage(-10);
				(*it)->set_roundfordamage(0);
			}
			else if(rounds==(*it)->get_roundfordefence()){
				(*it)->set_defence(-5);
				(*it)->set_roundfordefence(0);
			}
			else if(rounds==(*it)->get_roundforpossibility()){
				(*it)->set_poss(-5);
				(*it)->set_roundforpossibility(0);
			}
		}
		cout<<"Heroes's turn"<<endl;
		for(i=0;i<number;i++){											//heroes's turn
			cout << "HERO " <<i+1 <<endl;
			cout<<"if you want to attack press 1"<<endl;
			cout<<"if you want to use a spell press 2"<<endl;
			cout<<"if you want to use a potion press 3"<<endl;
			cin>>ch;
			if(ch==1){														//the hero wants to attack
				key=Heros[i]->attack(number,&FightMonster);
				if(key==1)													//the heroes won the battle
					break;
			}
			else if(ch==2){													//the hero wants to cast a spell
				key=Heros[i]->castSpell(FightMonster,rounds);
				if(key==1)
					break;
			}
			else if(ch==3)													//the hero wants to use a potion
				Heros[i]->use();
		}
		if ( key!=1 ){
				cout<<"Monsters's turn"<<endl;
			int dead=0;
			for(it=FightMonster.begin(); it != FightMonster.end(); ++it){				//monsters's turn
				int count;
				do{
					count=rand()%number;
				}
				while(Heros[count]->get_healthPower()==0);									//it has to choose the hero it wants to attack to
				cout<<"The monster attacked to the Hero number "<< count+1<<endl;
				(*it)->attack(Heros[count]);
				for(i=0;i<number;i++)
					Heros[i]->displayStats();
				for(i=0;i<number;i++){
					if(Heros[i]->get_healthPower()==0)
						dead++;																//we count the number of heroes are dead
				}
				if(dead==number){															//if all the heroes are dead
					key=2;																	//the monsters won this battle
					break;
				}
				dead = 0;
			}
		}
		if(key==1){																	//if the heroes won the battle
			cout<<"CONGRATULATIONS!! HEROES WON THIS BATTLE"<<endl;
			for(i=0;i<number;i++){													//for each one of them
				Heros[i]->set_money(numberofmonsters,key);							//we increase his money
				Heros[i]->set_experience(numberofmonsters);							//we increase his experience
				Heros[i]->LevelUp();												//we increase his level
				if(Heros[i]->get_healthPower()==0){									//and if he is dead
					alive=false;
					Heros[i]->increase_healthPower(alive);							//we increase his healthPower
				}
			}
		}
		else if(key==0){															//if nobody has won yet
			for(it=FightMonster.begin(); it != FightMonster.end(); ++it){
				(*it)->increase_healthpower();										//we increase healthPower for each monster is alive
			}
			for(i=0;i<number;i++){
				bool alive;
				if(Heros[i]->get_healthPower()>0){
					alive=true;
					Heros[i]->increase_healthPower(alive);							//we increase healthPower for each hero is alive
					Heros[i]->increase_magicPower();								//and his magicPower
				}									
			}
			rounds++;
			string a;
			cout<<"Do you want to see the statistics of the heroes and of the monsters? (YES/NO)"<<endl;
			cin>>a;
			if(a=="YES"){
				for(i=0;i<number;i++)
					Heros[i]->displayStats();
				for(it=FightMonster.begin(); it != FightMonster.end(); ++it)
					(*it)->displayStats();
			}
		}
		else if(key==2){															//if the monsters won the battle
			cout<<"OOOUPS MONSTERS WON THIS BATTLE!"<<endl;
			for(i=0;i<number;i++){
				Heros[i]->set_money(numberofmonsters,key);							//we decrease the money of the heroes
				if(Heros[i]->get_healthPower()==0){
					alive=false;
					Heros[i]->increase_healthPower(alive);							//and we increase their healthPower
				}
			}
		}
	}while(key!=1 && key!=2);														//while the battle is not over
}


void Grid::CreateTeam(int number){
	int i,count,L,H_P,M_P,S,D,A,M,E;
	string N,Str;
	for(i=0;i<number;i++){																//it creates the heroes and it initializes all the data-members
		count=rand()%3;																	//there are three types of heroes
		L=1;
		H_P=100;
		M_P=50;
		S=rand()%15 +1;
		D=rand()%15 +1;
		A=rand()%15 +1;
		M=200; 
		E=1;
		ostringstream os;
		os << (i+1);
		Str=os.str();
		N="Hero"+Str;
		if(count==0)
			Heros[i]= new Warrior(N,L,H_P,M_P,S,D,A,M,E);								//it inserts the warrior in the array of heroes
		else if(count==1)
			Heros[i]= new Sorcerer(N,L,H_P,M_P,S,D,A,M,E);								//it inserts the sorcerer in the array of heroes
		else
			Heros[i]= new Paladin(N,L,H_P,M_P,S,D,A,M,E);								//it inserts the paladin in the array of heroes
	}
}

void Grid::CreateMonsters(){
	int i,L,H_P,W_D,A_D,A_P,type;
	string N,Str;
	for(i=0;i<20;i++){																	//it creates the monsters and it initializes all the data-members
		ostringstream os;
		os << (i+1);
		Str=os.str();
		N="Monster"+Str;
		L=rand()%10 +1;
		H_P=60;
		W_D=rand()%10+20;
		A_D=rand()%10+1;
		A_P=(rand()%3+1)*10;
		type=rand()%3;																	//there are three types of monsters
		if(type==0){
			Monsters[i]=new Dragon(N,L,H_P,W_D,A_D,A_P);								//it inserts the dragon in the array of monsters
		}
		else if(type==1){
			Monsters[i]=new Exoskeleton(N,L,H_P,W_D,A_D,A_P);							//it inserts the exoskeleton in the array of monsters
		}
		else{
			Monsters[i]=new Spirit(N,L,H_P,W_D,A_D,A_P);								//it inserts the spirit in the array of monsters
		}
	}
}

void Grid::quitGame(int number){														//the game ends with this function
	int i;
	for(i=0;i<number;i++)
			delete Heros[i];
	for(i=0;i<20;i++)
		delete Monsters[i];
}
