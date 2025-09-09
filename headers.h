#ifndef HEADERS_H
#define HEADERS_H

//difining directions as datatypes.
typedef enum
{
	NORTH = 2,	 
	EAST = 3, 	
	SOUTH = 4, 	
	WEST = 5
}directions;


//block architecture.
typedef struct
{
	int floor,width,length;	//cells(blocks)
}Flag;


//Bawana
typedef struct
{
	int FoodPoisoning_1[3];
	int Disoriented_1[3];
	int Triggered_1[3];
	int Happy_1[3];
	int FoodPoisoning_2[3];
	int Disoriented_2[3];
	int Triggered_2[3];
	int Happy_2[3];
}Bawana;


//Stairs
typedef struct
{
    int startFloor;
    int startWidth;
    int startLength;
    int endFloor;
    int endWidth;
    int endLength;
}Stairs;


//Poles
typedef struct
{
    int startFloor;
	int endFloor;
	int width;
	int length;
}Poles;


//Walls
typedef struct
{
    int floor;
    int startWidth;
    int startLength;
    int endWidth;
    int endLength;
}Walls;


//Seed
typedef struct
{
	unsigned int seed;
}Seed;


//Player
typedef struct
{
	int direction;
	int currentFloor;
	int currentWidth;
	int currentLength;
	bool isPlayerActive;
	bool isEnteredGame;
	int throwCount;
	int score;
}Player;


void loadStairs(Stairs **stairs);
void loadPoles(Poles **poles);
void loadWalls(Walls **walls);
void loadPlayers(Player **players);
void initBawana(Bawana **bawana);
int play();

#endif