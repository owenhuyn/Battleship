#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

#include <vector>
	std::vector<std::string> reader(std::string);
class Grid{
	//on the grid, 
	//0 = empty
	//1 = ship
	//2 = hit
	//3 = miss
private:
	std::vector< std::vector<int> > grid;//(10, vector<int>(10));
	std::vector< std::vector<int> > ships;
public:
	Grid();
	bool loaded;
	double totalShots(std::string);//returns the total amount of shots
	double HitPercent(std::string);//returns the players hit percent
	void statistics(std::string,std::string,double,int,int);//saves a highscore file
	int sunkenShips(std::string);//returns how many ships have been sunken for each player
	int isSunk(int,int);//checks if a ship is sunk
	bool addShip(int,int,int,int);//adds ship to grid
	bool addShipBlock(int,int);//x,y
	int shoot(int,int);//x,y : returns 0 - failure| 2 - hit| 3- miss
	int getBlock(int,int);//checks if a ship was at specified block
	void clear();//clears the grid
	void printGrid();//For testing
	void reset();// resets game
	void save(std::string,int,int,double,int);//saves current game progress
	int load(std::string);//loads a saved game
	void AIsetup();
    void EasyAIshoot();
    int* MediumAIshoot();
    void InsaneAIshoot();
};
#endif