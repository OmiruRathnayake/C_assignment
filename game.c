#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rand_utils.h"
#include "headers.h"

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
Seed *seeds;
Player players;

int seed_count;
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

//Bawana walls
const int bawanaWall1[5] = {0,6,20,6,24};
const int bawanaWall2[5] = {0,6,20,9,20};
int bawanaEntrance[3] = {0,9,19};

//Ground floor
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


//Logics of ground floor.
void Floor0()
{
	//
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

	// Floor 2
    printf("\n\n\t\t     FLOOR 2\n");
	printf("\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .                  . . . . . . . .\n. . . . . . . .==================. . . . . . . .\n. . . . . . . .==================. . . . . . . .\n. . . . . . . .==================. . . . . . . .\n. . . . . . . .==================. . . . . . . .\n");
    printf("Bridge(=) across positions [7-17]\n");

	// Floor 3
    printf("\n\n\t\t     FLOOR 3\n");
	printf("\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n                . . . . . . . . .\n");
    printf("Similar layout to Floor 2 with bridge [7-17]\n");

}


//random integer between 1-6
int rand_int_0_6(void) {
    return (rand() % 6) + 1;  // 1–6
}


//direction dice
int directionDice()
{
	return rand_int_0_6();
}


//movement dice
int movementDice()
{
	return rand_int_0_6();
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

    printf("%ld bytes for all stairs%d\n", sizeof(Stairs) * capacity, capacity);

	//stairs behaves like a dynamic array of struct Stair.(remember this for future purposes stupid ass)
	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d %d %d", &(*stairs)[count].startFloor, &(*stairs)[count].startWidth, &(*stairs)[count].startLength, &(*stairs)[count].endFloor, &(*stairs)[count].endWidth, &(*stairs)[count].endLength) == 6)
		{
			printf("\t%d,%d,%d,%d,%d,%d\n", (*stairs)[count].startFloor, (*stairs)[count].startWidth, (*stairs)[count].startLength, (*stairs)[count].endFloor, (*stairs)[count].endWidth, (*stairs)[count].endLength);
		}
	}

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

    printf("%ld bytes for all Poles%d\n", sizeof(Poles) * capacity, capacity);

	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d", &(*poles)[count].startFloor, &(*poles)[count].endFloor, &(*poles)[count].width, &(*poles)[count].length) == 4)
		{
			printf("\t%d,%d,%d,%d\n", (*poles)[count].startFloor, (*poles)[count].endFloor, (*poles)[count].width, (*poles)[count].length);
		}
	}

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

    printf("%ld bytes for all walls%d\n", sizeof(Walls) * capacity, capacity);

	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d %d", &(*walls)[count].floor, &(*walls)[count].startWidth, &(*walls)[count].startLength, &(*walls)[count].endWidth, &(*walls)[count].endLength) == 5)
		{
			printf("\t%d,%d,%d,%d,%d\n", (*walls)[count].floor, (*walls)[count].startWidth, (*walls)[count].startLength, (*walls)[count].endWidth, (*walls)[count].endLength);
		}
	}

	fclose(file);

}


void loadSeed(Seed **Seeds){
	FILE *file = fopen("seed.txt", "r");

	int lines = 0;
	char character;

	while ((character = fgetc(file)) != EOF) {
		if (character == '\n') {
			lines++;
		}
	}
	rewind(file);

	*Seeds = malloc(sizeof(Seed) * lines);
	
	printf("%ld bytes for all seeds%d\n", sizeof(Seed) * lines, lines);

	for (int i = 0; i < lines; i++)
	{
		if (fscanf(file, "%u", &((*Seeds)[i].seed)) != 1)
		{
			break;
		}
	}

	seed_count = lines;
	fclose(file);
	
}


void loadPlayers(Player *players){
	//
}


int play()
{
	displayFloor();

	printf("\n");

	loadStairs(&stairs);
	loadPoles(&poles);
	loadWalls(&walls);
	loadPlayers(&players);
	loadSeed(&seeds);

	for (int i = 0; i < seed_count; i++)
	{
		srand(seeds[i].seed);

	    printf("Movement dice: %d\n", movementDice());
		printf("Direction dice: %d\n", directionDice());
	}

	free(stairs);
	free(poles);
	free(walls);
	free(seeds);

	return 0;
}
