#ifndef HEADERS_H
#define HEADERS_H

//difining directions as datatypes.
typedef enum
{
	NORTH = (-1),	//width + NORTH = w - 1 
	EAST = (1), 	//length + EAST = l + 1
	SOUTH = (1), 	//width + SOUTH = w + 1
	WEST = (-1)		//length + WEST = l - 1
}directions;


//block architecture.
struct Cell
{
	int floor,width,length;	//cells(blocks)
};


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
	int throwCount;
}Player;


void loadStairs(Stairs **stairs);
void loadPoles(Poles **poles);
void loadWalls(Walls **walls);
void loadPlayers(Player *players);
int rand_int_0_6(void);
int play();

#endif