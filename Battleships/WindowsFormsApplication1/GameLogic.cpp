#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <time.h>
#include <windows.h>

using namespace std;
#include "GameLogic.h"
#include "Form1.h"
//Grid class
Grid::Grid(){
	for (int i = 0; i < 10; i++) {
		vector<int> row; // Create an empty row
		for (int j = 0; j < 10; j++) {
			row.push_back(0); // Add an element (column) to the row
		}
		grid.push_back(row); // Add the row to the main vector
	}

	for (int i = 0; i < 7; i++) {
		vector<int> rowz; // Create an empty row
		for (int j = 0; j < 3; j++) {
			rowz.push_back(0); // Add an element (column) to the row
		}
		ships.push_back(rowz); // Add the row to the main vector
	}
	//MessageBox::Show()
	printGrid();
	clear();
}

//Clear grid function
void Grid::clear(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) {
			grid[i][j] = 0;
		}
	}
}

//reader function for statistics
std::vector <std::string> reader(string fileName){
	ifstream myfile;
	string line;
	vector <string>  stats;
	int lines = 0;
	myfile.open(fileName);//opens the stats file.
	if(myfile.is_open()){
		while(myfile.good()){
			getline(myfile,line);
			stats.push_back(line);//puts each line into a vector of strings.
		}
	}
	myfile.close();
	return stats;//returns vector of strings.
}

//Save functions
void Grid::save(std::string save, int score, int shipsSunk, double HitPercent, int totalShots){
	Grid* scoreGrid;
	scoreGrid = new Grid();
	int topScore = scoreGrid->load(save);

	ofstream myfile;
	myfile.open(save + ".txt");//opens file
	for (int i = 0; i < 7; i++){
		if(ships[i][1] == 10){
			ships[i][1] = 0;
		}
		if(ships[i][2] == 10){
			ships[i][2] = 0;
		}
		//saves each ship for the grid
		myfile << ships[i][0];//Orientation
		myfile << ships[i][1];//X position
		myfile << ships[i][2] << endl;//Y position
	};
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			myfile << grid[i][j];//saves the grid state
		}
	}
	myfile << endl;
	myfile << score;
	myfile << endl << shipsSunk;
	myfile << endl << HitPercent;
	myfile << endl << totalShots;
	myfile.close();
}

//Save the users statistics
void Grid::statistics(std::string playerName, std::string name, double playerHitPercent , int totalShots, int score){
	string line;
	//appends all of a specified users data to a text file for recording their previous game stats.
	ofstream myfile;
	myfile.open(playerName, myfile.app);//opens file
	myfile << "Player: " << name << "     ";
	myfile << "HitPercent: " << playerHitPercent << "%     ";
	myfile << "TotalShotsFired: " << totalShots << "     ";
	myfile << "Score: " <<score << endl;
	myfile.close();
}


//loads a users gamestate
int Grid::load(std::string load){
	string line;
	int lines = 0;
	ifstream myfile (load + ".txt");
	if (myfile.is_open()){//opens the saved file
		int k=0;
		for(lines = 0; getline(myfile,line) && lines < 12; lines++){
			if(lines < 7){
				if((line[1] - 48) == 0){
					line[1] = 58;
				}
				if((line[2] - 48) == 0){
					line[2] = 58;
				}
			addShip(lines,line[0]-48,line[1]-48,line[2]-48);//adds the ships back to grid
			}
			else if(lines == 7){
				for (int i = 1; i < 11; i++){
					for (int j = 1; j < 11; j++){
						if((line[k]-48) == 2 || (line[k]-48) == 3){
							shoot(j,i);//shoots appropriate places on the grid
							k++;
						}
						else if((line[k]-48) == 0 || (line[k]-48) == 1){
							k++;
						}
					}
				}
			}
			else if(lines == 8){
				int score = atoi(line.c_str());
				return score;
			}
		}
	} else {
		return -1;
	}
	myfile.close();
}

//loads how many ships have been sunk
int Grid::sunkenShips(std::string load){
	string line;
	ifstream myfile (load + ".txt");//opens the saved file
	if (myfile.is_open()){
		for(int lines = 0; getline(myfile,line) && lines < 12; lines++){
			if(lines == 9){
				int sunkenShips = atoi(line.c_str());//reads the specified line in save file and stores value
				return sunkenShips;
			}
		}
	}

	myfile.close();


}

//returns the players hit percent from the save file.
double Grid::HitPercent(std::string load){
	string line;
	ifstream myfile (load + ".txt");//opens the saved file
	if (myfile.is_open()){
		for(int lines = 0; getline(myfile,line) && lines < 12; lines++){
			if(lines == 10){
				double HitPercent = atoi(line.c_str());//reads the specified line in save file and stores value
				return HitPercent;
			}
		}
	}

	myfile.close();


}

//returns the total shots taken from the save file
double Grid::totalShots(std::string load){
	string line;
	ifstream myfile (load + ".txt");//opens the saved file
	if (myfile.is_open()){
		for(int lines = 0; getline(myfile,line) && lines < 12; lines++){
			if(lines == 11){
				int totalShots = atoi(line.c_str());//reads the specified line in save file and stores value
				return totalShots;
			}
		}
	}

	myfile.close();


}


//Printing grid for testing purposes
void Grid::printGrid(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) {
			cout << grid[i][j];
		}
		cout << "\r\n";
	}
}

//Get functions for game info
int Grid::getBlock(int x, int y){
	return grid[y-1][x-1];
}

//checks if a ship is sunk
int Grid::isSunk(int x,int y){
	int sizes[] = {1,1,2,2,3,4,5};
	int returner = -1;
	if (getBlock(x,y) != 2){
		return -1;
	}
	for(int i = 0; i < ships.size(); i++){
		if (ships[i][0] == 0){
			if (y == ships[i][2] && x >= ships[i][1] && x < ships[i][1]+sizes[i]){
				for (int j = 0; j < sizes[i]; j++){
					if (getBlock(ships[i][1]+j,y) != 2){
						return -1;
					}
				}
				return i;
			}
		} else {
			if (x == ships[i][1] && y >= ships[i][2] && y < ships[i][2]+sizes[i]){
				for (int j = 0; j < sizes[i]; j++){
					if (getBlock(x,ships[i][2]+j) != 2){
						return -1;
					}
				}
				return i;
			}
		}
	}
	return -1;
}

//Game Functions
//add ship array to the grid
bool Grid::addShip(int ship, int orientation, int x, int y){
	int sizes[] = {1,1,2,2,3,4,5};
	if (orientation == 0){//horizontal
		if (x >0 && x < 12-sizes[ship] && y > 0 && y < 11){
			ships[ship][0] = orientation;
			ships[ship][1] = x;
			ships[ship][2] = y;
			for (int i = 0; i < sizes[ship]; i++){
				if (getBlock(x+i,y) != 0){
					return false;
				}
			}
			for (int i  = 0; i < sizes[ship]; i++){
				addShipBlock(x+i,y);
			}
			return true;
		}
	} else {//vertical
		if (y >0 && y < 12-sizes[ship] && x > 0 && x < 11){
			ships[ship][0] = orientation;
			ships[ship][1] = x;
			ships[ship][2] = y;
			for (int i = 0; i < sizes[ship]; i++){
				if (getBlock(x,y+i) != 0){
					return false;
				}
			}
			for (int i  = 0; i < sizes[ship]; i++){
				addShipBlock(x,y+i);
			}
			return true;
		}
	}
	return false;
}
//create specific blocks for each ship
bool Grid::addShipBlock(int x,int y){
	if (x > 0 && x < 11 && y > 0 && y < 11){
		grid[y-1][x-1] = 1;
		return true;
	} else {
		return false;
	}
}
//shoots the grid
int Grid::shoot(int x,int y){
	if (grid[y-1][x-1] == 0){
		grid[y-1][x-1] = 3;
		return 3;
	} else if (grid[y-1][x-1] == 1){
		grid[y-1][x-1] = 2;
		return 2;
	} else if (grid[y-1][x-1] == 2){
		return 0;
	} else if (grid[y-1][x-1] == 3){
		return 0;
	}
	return 0;

}

//Ship placement for AI
void Grid::AIsetup(){
if(loaded == false){
	srand (time(NULL));
	int xCoor = rand() % 10 + 1;
	int yCoor = rand() % 10 + 1;
	// 5 block ship
	while(!addShip(6,rand()%2,xCoor,yCoor)){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
	}

	// 4 block ship

	while(!addShip(5,rand()%2,xCoor,yCoor)){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
	}

	// 3 block ship

	while(!addShip(4,rand()%2,xCoor,yCoor)){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
	}

	// 2x two block boats

	while(!addShip(3,rand()%2,xCoor,yCoor)){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
	}
	while(!addShip(2,rand()%2,xCoor,yCoor)){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
	}

	// 2x one block submarines
	while(!addShip(1,0,xCoor,yCoor)){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
	}
	while(!addShip(0,0,xCoor,yCoor)){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
	}
}
else {};
}

//medium difficulty for AI to use
int* Grid::MediumAIshoot(){

	bool fired = false;
	bool preExisting = false;
	int xCoor,yCoor;
	for (int i = 1; i < 11; i++){
		for (int j = 1; j < 11; j++){
			if (getBlock(i,j) == 2 && (isSunk(i,j) == -1)){
				if (i < 10 && i > 1){
					if ((getBlock(i+1,j) == 2) && ((getBlock(i-1,j) == 0) || (getBlock(i-1,j) == 1))){

						shoot(i-1,j);
						xCoor = i-1;
						yCoor = j;
						fired = true;
						preExisting = true;
						break;
					}
				}
				if (i < 10 && i > 1){
					if ((getBlock(i-1,j) == 2) && ((getBlock(i+1,j) == 0) || (getBlock(i+1,j) == 1))){

						shoot(i+1,j);
						xCoor = i-1;
						yCoor = j;
						fired = true;
						preExisting = true;
						break;
					}
				}
				if (j < 10 && j > 1){
					if ((getBlock(i,j-1) == 2) && ((getBlock(i,j+1) == 0) || (getBlock(i,j+1) == 1))){

						shoot(i,j+1);
						xCoor = i;
						yCoor = j+1;
						fired = true;
						preExisting = true;
						break;
					}
				}
				if (j < 10 && j > 1){
					if ((getBlock(i,j+1) == 2) && ((getBlock(i,j-1) == 0) || (getBlock(i,j-1) == 1))){

						shoot(i,j-1);
						xCoor = i;
						yCoor = j-1;
						fired = true;
						preExisting = true;
						break;
					}
				}
				if (i < 10){
					if ((getBlock(i+1,j) == 0) || (getBlock(i+1,j) == 1)){

						shoot(i+1, j);
						xCoor = i+1;
						yCoor = j;
						fired = true;
						preExisting = true;
						break;
					}
				}
				if (i > 1){
					if ((getBlock(i-1,j) == 0) || (getBlock(i-1,j) == 1)){

						shoot(i-1, j);
						xCoor = i-1;
						yCoor = j;
						fired = true;
						preExisting = true;
						break;
					}
				}
				if (j < 10){
					if ((getBlock(i,j+1) == 0) || (getBlock(i,j+1) == 1)){

						shoot(i, j+1);
						xCoor = i;
						yCoor = j+1;
						fired = true;
						preExisting = true;
						break;
					}
				}
				if (j > 1){
					if ((getBlock(i,j-1) == 0) || (getBlock(i,j-1) == 1)){

						shoot(i, j-1);
						xCoor = i;
						yCoor = j-1;
						fired = true;
						preExisting = true;
						break;
					}
				}
			}

		}
		if (fired == true){
			break;
		}
	}

	if (preExisting == false){
		xCoor = rand() % 10 + 1;
		yCoor = rand() % 10 + 1;
		while (!(getBlock(xCoor,yCoor)==0) && !(getBlock(xCoor,yCoor)==1)){
			xCoor = rand() % 10 + 1;
			yCoor = rand() % 10 + 1;
		}
		//if (grid[xCoor-1][yCoor-1] == 0 ){
		shoot(xCoor, yCoor);

		//}
	}
	int* returner = new int[2];
	returner[0] = xCoor;
	returner[1] = yCoor;
	return returner;
}
