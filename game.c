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

Stairs stairs;
Poles poles;
Walls walls;
Player players;

//const int A_START[3]= {0,6,12};
//const int B_START[3]= {0,9,8};
//const int C_START[3]= {0,9,16};

//Logics of ground floor.
void Floor1(int floor, int width, int length, char Player_tag, int move)
{
	//
}

//Logics of 1st floor.
void Floor2(int max_width, int max_length)
{
	printf("floor2 width=%d,length=%d\n", max_width, max_length);
	/*code*/
}

//Logics of 2nd floor.
void Floor3(int max_width, int max_length)
{
	printf("floor3 width=%d,length=%d\n", max_width, max_length);
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


//direction dice
int directionDice()
{
	srand(time(NULL));
	return rand_int_0_6();
}


//movement dice
int movementDice()
{
	srand(time(NULL));
	return rand_int_0_6();
}


void loadStairs(Stairs *stairs){
    FILE *file = fopen("stairs.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int capacity;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            capacity++;
        }
    }
    rewind(file);

	stairs = malloc(sizeof(Stairs) * capacity);

    printf("%ld bytes for all stairs\n", sizeof(Stairs) * capacity);

	//stairs behaves like a dynamic array of struct Stair.(remember this for future purposes stupid ass)
	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d %d %d", &stairs[count].startFloor, &stairs[count].startWidth, &stairs[count].startLength, &stairs[count].endFloor, &stairs[count].endWidth, &stairs[count].endLength) == 6)
		{
			printf("\t%d,%d,%d,%d,%d,%d\n", stairs[count].startFloor, stairs[count].startWidth, stairs[count].startLength, stairs[count].endFloor, stairs[count].endWidth, stairs[count].endLength);
		}
	}

	free(stairs);	//remove this line.
	fclose(file);

}


void loadPoles(Poles *poles){
    FILE *file = fopen("poles.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int capacity;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            capacity++;
        }
    }
	rewind(file);
    
    poles = malloc(sizeof(Poles) * capacity);

    printf("%ld bytes for all Poles\n", sizeof(Poles) * capacity);

	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d", &poles[count].startFloor, &poles[count].endFloor, &poles[count].width, &poles[count].length) == 4)
		{
			printf("\t%d,%d,%d,%d\n", poles[count].startFloor, poles[count].endFloor, poles[count].width, poles[count].length);
		}
	}

	free(poles);	//remove this line.
	fclose(file);

}


void loadWalls(Walls *walls){
    FILE *file = fopen("walls.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int capacity;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            capacity++;
        }
    }
	rewind(file);
    
    walls = malloc(sizeof(Walls) * capacity);

    printf("%ld bytes for all walls\n", sizeof(Walls) * capacity);

	for (count = 0; count < capacity; count++){
		if (fscanf(file, "%d %d %d %d %d", &walls[count].floor, &walls[count].startWidth, &walls[count].startLength, &walls[count].endWidth, &walls[count].endLength) == 5)
		{
			printf("\t%d,%d,%d,%d,%d\n", walls[count].floor, walls[count].startWidth, walls[count].startLength, walls[count].endWidth, walls[count].endLength);
		}
	}

	free(walls);	//remove this line.
	fclose(file);

}


void loadPlayers(Player *players){
	//
}


int play()
{
	displayFloor();

	printf("\n");

	//printf("%d\n", movementDice());
	loadStairs(&stairs);
	loadPoles(&poles);
	loadWalls(&walls);
	loadPlayers(&players);

	return 0;
}
