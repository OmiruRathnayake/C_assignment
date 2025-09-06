#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rand_utils.h"
#include "headers.h"

#define floor1 0
#define floor2 1
#define floor3 2
#define MAX_WIDTH 9
#define MAX_LENGTH 24
#define MAX_PLAYERS 3
#define STARTING_POINTS 100
#define MOVEMENT_COST 2
#define A 0
#define B 1
#define C 2
#define GAMEOVER 0

Stairs *stairs;
Poles *poles;
Walls *walls;
Seed *seed;
Player *players;
Bwna *bawana;
Flag *flag;

int stairs_count;
int poles_count;
int walls_count;

int player_count = 0;
int currentPlayer = 0;
int turn = 1;
int throwCount = 0;

//player movement points at the beginning
int AXP = STARTING_POINTS;
int BXP = STARTING_POINTS;
int CXP = STARTING_POINTS;

//player starting positions
const int A_START[3]= {0,6,12};
const int B_START[3]= {0,9,8};
const int C_START[3]= {0,9,16};

//player entering positions
const int A_ENTER[3]= {0,5,12};
const int B_ENTER[3]= {0,9,7};
const int C_ENTER[3]= {0,9,17};

//Bawana walls
const int bawanaWall1[5] = {0,6,20,6,24};
const int bawanaWall2[5] = {0,6,20,9,20};
int bawanaEntrance[3] = {0,9,19};

//Standing area
int standAreaWidthStart = 6;
int standAreaWidthEnd = 9;
int standAreaLengthStart = 8;
int standAreaLengthEnd = 16;

//Floor1
int f1DisabledWidthStart = 0;
int f1DisabledWidthEnd = 5;
int f1DisabledLengthStart = 8;
int f1DisabledLengthEnd = 16;

//Floor2
int f2DisabledWidthStart = 0;		//floor 2 disabled width start
int f2DisabledWidthEnd = 9;
int f2DisabledLengthStart_1 = 0;
int f2DisabledLengthEnd_1 = 7;
int f2DisabledLengthStart_2 = 17;
int f2DisabledLengthEnd_2 = 24;


//initializing srand or random number generation
void init_srand(unsigned int seed) {
	srand(seed);
}


//random integer between 1-6
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}


//Logics of ground floor.
void Floor0()
{
	//
}


void Bawana(Bwna **bawana){
	*bawana = malloc(sizeof(Bwna));

	(*bawana)->FoodPoisoning_1[0] = floor1;
	(*bawana)->FoodPoisoning_1[1] = rand_int(7,9);
	(*bawana)->FoodPoisoning_1[2] = rand_int(21,24);

	(*bawana)->FoodPoisoning_2[0] = floor1;
	(*bawana)->FoodPoisoning_2[1] = rand_int(7,9);
	(*bawana)->FoodPoisoning_2[2] = rand_int(21,24);

	(*bawana)->Disoriented_1[0] = floor1;
	(*bawana)->Disoriented_1[1] = rand_int(7,9);
	(*bawana)->Disoriented_1[2] = rand_int(21,24);

	(*bawana)->Disoriented_2[0] = floor1;
	(*bawana)->Disoriented_2[1] = rand_int(7,9);
	(*bawana)->Disoriented_2[2] = rand_int(21,24);

	(*bawana)->Triggered_1[0] = floor1;
	(*bawana)->Triggered_1[1] = rand_int(7,9);
	(*bawana)->Triggered_1[2] = rand_int(21,24);
	
	(*bawana)->Triggered_2[0] = floor1;
	(*bawana)->Triggered_2[1] = rand_int(7,9);
	(*bawana)->Triggered_2[2] = rand_int(21,24);

	(*bawana)->Happy_1[0] = floor1;
	(*bawana)->Happy_1[1] = rand_int(7,9);
	(*bawana)->Happy_1[2] = rand_int(21,24);
	
	(*bawana)->Happy_2[0] = floor1;
	(*bawana)->Happy_2[1] = rand_int(7,9);
	(*bawana)->Happy_2[2] = rand_int(21,24);

	//return 0;
}


//Logics of 1st floor.
void Floor1(/*f1DisabledWidthStart, f1DisabledWidthEnd, f1DisabledLengthStart, f1DisabledLengthEnd*/)
{
	/*code*/
}


//Logics of 2nd floor.
void Floor2(/*f2DisabledWidthStart, f2DisabledWidthEnd, f2DisabledLengthStart_1, f2DisabledLengthEnd_1, f2DisabledLengthStart_2, f2DisabledLengthEnd_2*/)
{
	/*code*/
}


//Stairs logic
int tairs(int sf, int sw, int sl, int ef, int ew, int el)
{
	//[sf,sw,sl,ef,ew,el] => [start floor, start block width number, start block length number, end floor, end block width number, end block length number]
	/*code*/
}


//Floor map 
void displayFloor() {
    
	// Floor 1 (Ground floor)
    printf("\n\t     FLOOR 1 (GROUND FLOOR)\n");
	printf("\n. . . . . . . . . . . . . . . . . . . . . . . . .\n. . . . . . . . . . . . . . . . . . . . . . . . .\n. . . . . . . . . . . . . . . . . . . . . . . . .\n. . . . . . . . . . . . . . . . . . . . . . . . .\n. . . . . . . . . . . . . . . . . . . . . . . . .\n. . . . . . . . . . . . a . . . . . . . . . . . .\n. . . . . . . .[][][][][A][][][][]. . . # # # # #\n. . . . . . . .[][][][][[][][][][]. . . # . . . .\n. . . . . . . .[][][][][[][][][][]. . . # . . . .\n. . . . . . . .[][][][][[][][][][]. . . # . . . .\n. . . . . . . b[B][][][][[][][][C]c . E # . . . .\n");
    printf("Start positions:\n");
    printf("\tA[0,6,12] -> (*a[0,5,12])\n");
    printf("\tB[0,9,8]  -> (*b[0,9,7])\n");
    printf("\tC[0,9,16] -> (*c[0,9,17])\n");
    printf("Entrance to BAWANA-> (*E[0,9,19])\n");
	printf("Bawana walls (#) across positions [6-9,20-24] and [6-9,20-24]\n");
	printf("Bawana FP1 = [%d,%d,%d]\n", (*bawana).FoodPoisoning_1[0], (*bawana).FoodPoisoning_1[1], (*bawana).FoodPoisoning_1[2]);
	printf("Bawana FP2 = [%d,%d,%d]\n", (*bawana).FoodPoisoning_2[0], (*bawana).FoodPoisoning_2[1], (*bawana).FoodPoisoning_2[2]);
	printf("Bawana D1 = [%d,%d,%d]\n", (*bawana).Disoriented_1[0], (*bawana).Disoriented_1[1], (*bawana).Disoriented_1[2]);
	printf("Bawana D2 = [%d,%d,%d]\n", (*bawana).Disoriented_2[0], (*bawana).Disoriented_2[1], (*bawana).Disoriented_2[2]);
	printf("Bawana T1 = [%d,%d,%d]\n", (*bawana).Triggered_1[0], (*bawana).Triggered_1[1], (*bawana).Triggered_1[2]);
	printf("Bawana T2 = [%d,%d,%d]\n", (*bawana).Triggered_2[0], (*bawana).Triggered_2[1], (*bawana).Triggered_2[2]);
	printf("Bawana H1 = [%d,%d,%d]\n", (*bawana).Happy_1[0], (*bawana).Happy_1[1], (*bawana).Happy_1[2]);
	printf("Bawana H2 = [%d,%d,%d]\n", (*bawana).Happy_2[0], (*bawana).Happy_2[1], (*bawana).Happy_2[2]);
	
	// Floor 2
    printf("\n\n\t\t     FLOOR 2\n");
	printf("\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .==================. . . . . . . .\n. . . . . . . .==================. . . . . . . .\n. . . . . . . .==================. . . . . . . .\n. . . . . . . .==================. . . . . . . .\n");
    printf("Bridge(=) across positions [7-17]\n");

	// Floor 3
    printf("\n\n\t\t     FLOOR 3\n");
	printf("\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n");
    printf("Similar layout to Floor 2 with bridge [7-17]\n");

}


/*
//random integer between 0-3
int rand_int_0_3(void) {
	return (rand() % 3);  // 0–3
}


//random integer between 0-9
int rand_int_0_9(void) {
	return (rand() % 10);  // 0–9
}


//random integer between 0-24
int rand_int_0_24(void) {
	return (rand() % 25);  // 0–24
}
*/

//direction dice
int directionDice()
{
	return rand_int(1, 6);
}


//movement dice
int movementDice()
{
	return rand_int(1, 6);
}


void loadStairs(Stairs **stairs){
    FILE *file = fopen("stairs.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int capacity = 0;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            capacity++;
        }
    }
    rewind(file);

	*stairs = malloc(sizeof(Stairs) * capacity);

    printf("%ld bytes for all %d stairs\n", sizeof(Stairs) * capacity, capacity);

	//stairs behaves like a dynamic array of struct Stair.(remember this for future purposes stupid ass)
	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d %d %d", &(*stairs)[count].startFloor, &(*stairs)[count].startWidth, &(*stairs)[count].startLength, &(*stairs)[count].endFloor, &(*stairs)[count].endWidth, &(*stairs)[count].endLength) != 6)
		{
			break;		//printf("\t%d,%d,%d,%d,%d,%d\n", (*stairs)[count].startFloor, (*stairs)[count].startWidth, (*stairs)[count].startLength, (*stairs)[count].endFloor, (*stairs)[count].endWidth, (*stairs)[count].endLength);
		}
	}

	stairs_count = capacity;
	fclose(file);

}


void loadPoles(Poles **poles){
    FILE *file = fopen("poles.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int capacity = 0;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            capacity++;
        }
    }
	rewind(file);
    
    *poles = malloc(sizeof(Poles) * capacity);

    printf("%ld bytes for all %d Poles\n", sizeof(Poles) * capacity, capacity);

	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d", &(*poles)[count].startFloor, &(*poles)[count].endFloor, &(*poles)[count].width, &(*poles)[count].length) != 4)
		{
			break;		//printf("\t%d,%d,%d,%d\n", (*poles)[count].startFloor, (*poles)[count].endFloor, (*poles)[count].width, (*poles)[count].length);
		}
	}

	poles_count = capacity;
	fclose(file);

}


void loadWalls(Walls **walls){
    FILE *file = fopen("walls.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int capacity = 0;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            capacity++;
        }
    }
	rewind(file);
    
    *walls = malloc(sizeof(Walls) * capacity);

    printf("%ld bytes for all %d walls\n", sizeof(Walls) * capacity, capacity);

	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d %d", &(*walls)[count].floor, &(*walls)[count].startWidth, &(*walls)[count].startLength, &(*walls)[count].endWidth, &(*walls)[count].endLength) != 5)
		{
			break;		//printf("\t%d,%d,%d,%d,%d\n", (*walls)[count].floor, (*walls)[count].startWidth, (*walls)[count].startLength, (*walls)[count].endWidth, (*walls)[count].endLength);
		}
	}

	walls_count = capacity;
	fclose(file);

}


void loadSeed(Seed **Seed){
	FILE *file = fopen("seed.txt", "r");

	*Seed = malloc(sizeof(Seed));

	printf("%ld bytes for the seed\n", sizeof(Seed));

	fscanf(file, "%u", &(*Seed)->seed);

	fclose(file);
	
}


void loadPlayers(Player **players){

	*players = malloc(sizeof(Player) * MAX_PLAYERS);

	//below are the initializations of players A, B and C
	(*players)[A].direction = NORTH;
	(*players)[A].currentFloor = floor1;
	(*players)[A].currentWidth = A_START[1];
	(*players)[A].currentLength = A_START[2];
	(*players)[A].isPlayerActive = false;
	(*players)[A].throwCount = 0;
	(*players)[A].score = STARTING_POINTS;

	(*players)[B].direction = WEST;
	(*players)[B].currentFloor = floor1;
	(*players)[B].currentWidth = B_START[1];
	(*players)[B].currentLength = B_START[2];
	(*players)[B].isPlayerActive = false;
	(*players)[B].throwCount = 0;
	(*players)[B].score = STARTING_POINTS;

	(*players)[C].direction = EAST;
	(*players)[C].currentFloor = floor1;
	(*players)[C].currentWidth = C_START[1];
	(*players)[C].currentLength = C_START[2];
	(*players)[C].isPlayerActive = false;
	(*players)[C].throwCount = 0;
	(*players)[C].score = STARTING_POINTS;

	player_count = 3;

	printf("%ld bytes for all %d players\n", sizeof(Player) * MAX_PLAYERS, MAX_PLAYERS);

}


void loadFlag(Flag **flags){

	FILE *file = fopen("flag.txt", "r");

	if (file == NULL){
		perror("Error opening file!");
		exit(1);
	}

	*flags = malloc(sizeof(Flag));

	fscanf(file, "%d %d %d", &(*flags)->floor, &(*flags)->width, &(*flags)->length);

	printf("%ld bytes for the flag\n", sizeof(Flag));

	fclose(file);

}


//check if the player is in bawana
bool isInBawana(int playerFloor, int playerWidth, int playerLength)
{
	if((playerFloor == floor1) && (playerWidth > bawanaWall1[1] && (playerLength > bawanaWall1[2])))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//check if the player is in standing area
bool isInStandingArea(int playerFloor, int playerWidth, int playerLength, char playerName, int movementDiceValue)
{
	if((playerFloor == floor1) && (playerWidth > standAreaWidthStart) && (playerLength >= standAreaLengthStart && playerLength <= standAreaLengthEnd))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//check whether the player enters the game
bool isPlayerEntersGame(bool isInStandingArea, char playerName, int movementDiceValue)
{
	if (isInStandingArea && (movementDiceValue == 6))
	{
		printf("%c is at the starting area and rolls 6 on the movement dice and is placed on [%d,%d,%d] of the maze.\n", playerName, floor1,  ((playerName == 'A') ? A_ENTER[1] : (playerName == 'B') ? B_ENTER[1] : C_ENTER[1]), ((playerName == 'A') ? A_ENTER[2] : (playerName == 'B') ? B_ENTER[2] : C_ENTER[2]));
		return true;
	}
	else
	{
		printf("%c is at the starting area and rolls %d on the movement dice cannot enter the maze.\n", playerName, movementDiceValue);
		return false;
	}
}


int play()
{
	loadFlag(&flag);		//memory has been allocated for flag
	loadStairs(&stairs);	//memory has been allocated for stairs
	loadPoles(&poles);		//memory has been allocated for poles
	loadWalls(&walls);		//memory has been allocated for walls
	loadSeed(&seed);		//memory has been allocated for seed
	loadPlayers(&players);	//memory has been allocated for players
	init_srand(seed->seed);	//initializing srand or random number generation

	printf("Seed: %u\n", seed->seed);
	Bawana(&bawana);		//memory has been allocated for bawana

	displayFloor();

	printf("\n");

	printf("!!! Flag position = [%d,%d,%d] !!!\n", flag->floor, flag->width, flag->length);

	printf("\n");

	//print loaded data for verification
/*
	for (int x = 0; x < stairs_count; x++){
		printf("\t%d,%d,%d,%d,%d,%d\n", stairs[x].startFloor, stairs[x].startWidth, stairs[x].startLength, stairs[x].endFloor, stairs[x].endWidth, stairs[x].endLength);
	}

	for (int y = 0; y < walls_count; y++){
		printf("\t%d,%d,%d,%d,%d\n", walls[y].floor, walls[y].startWidth, walls[y].startLength, walls[y].endWidth, walls[y].endLength);
	}

	for (int z = 0; z < poles_count; z++){
		printf("\t%d,%d,%d,%d\n", poles[z].startFloor, poles[z].endFloor, poles[z].width, poles[z].length);
	}
*/	

	/*for (int i = 0; i < 3; i++)
	{
		printf("FoodPoisoning: %d, Disoriented: %d, Triggered: %d, Happy: %d\n", bawana->FoodPoisoning[i], bawana->Disoriented[i], bawana->Triggered[i], bawana->Happy[i]);
	}*/

	//freeing up the allocated memory
	free(stairs);
	free(poles);
	free(walls);
	free(seed);
	free(players);
	free(bawana);
	free(flag);

	return 0;
}
