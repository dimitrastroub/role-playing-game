#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>
#include "Marketfunctions.cpp"

using namespace std;

class Grid {
	int  length;
	int  width;
	string **array;																	//an array that symbolizes the grid
	Hero* Heros[3];																	//an array of the heroes with whom the player is going to play
	Monster* Monsters[20];															//an array of some monsters with whom the player may has to fight
	public:
		Grid(int, int);
		~Grid();
		void InitializeGrid(int,int);
		void DispalyGrid(int);
		void Move(int,int,Market&,int);
		void CreateTeam(int);
		void displayMap();
		void Checking_Market(Market&  ,int );
		int Checking_Pass(int);
		void quitGame(int);
		void Fight(int);
		void CreateMonsters();
		void Buy(Market&,int);
		void Sell(int,Market&);
};
