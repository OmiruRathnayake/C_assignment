#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rand_utils.h"
#include "headers.h"

#define floor0 0
#define floor1 1
#define floor2 2
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
Bawana *bawana;
Flag *flag;

int stairs_count = 0;
int poles_count = 0;
int walls_count = 0;

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

//Floor0 boundaries
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


//initializing srand for random number generation
void init_srand(unsigned int seed) {
	srand(seed);
}


//random integer between 1-6
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}


//initialize Bawana blocks
void initBawana(Bawana **bawana){
	*bawana = malloc(sizeof(Bawana));

	(*bawana)->FoodPoisoning_1[0] = floor0;
	(*bawana)->FoodPoisoning_1[1] = rand_int(7,9);
	(*bawana)->FoodPoisoning_1[2] = rand_int(21,24);

	(*bawana)->FoodPoisoning_2[0] = floor0;
	(*bawana)->FoodPoisoning_2[1] = rand_int(7,9);
	(*bawana)->FoodPoisoning_2[2] = rand_int(21,24);

	(*bawana)->Disoriented_1[0] = floor0;
	(*bawana)->Disoriented_1[1] = rand_int(7,9);
	(*bawana)->Disoriented_1[2] = rand_int(21,24);

	(*bawana)->Disoriented_2[0] = floor0;
	(*bawana)->Disoriented_2[1] = rand_int(7,9);
	(*bawana)->Disoriented_2[2] = rand_int(21,24);

	(*bawana)->Triggered_1[0] = floor0;
	(*bawana)->Triggered_1[1] = rand_int(7,9);
	(*bawana)->Triggered_1[2] = rand_int(21,24);
	
	(*bawana)->Triggered_2[0] = floor0;
	(*bawana)->Triggered_2[1] = rand_int(7,9);
	(*bawana)->Triggered_2[2] = rand_int(21,24);

	(*bawana)->Happy_1[0] = floor0;
	(*bawana)->Happy_1[1] = rand_int(7,9);
	(*bawana)->Happy_1[2] = rand_int(21,24);
	
	(*bawana)->Happy_2[0] = floor0;
	(*bawana)->Happy_2[1] = rand_int(7,9);
	(*bawana)->Happy_2[2] = rand_int(21,24);

	//return 0;
}


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


//check whether Stairs are in disable areas
void validateStairs(Stairs **tempStairs, Stairs **stairs, int tempstairs_count)
{
	//count valid stairs
	for (int i = 0; i < tempstairs_count; i++)
	{
		if (!((((*tempStairs)[i].startFloor == 0) && ((*tempStairs)[i].startWidth >= 6 && (*tempStairs)[i].startWidth <= 9) && ((*tempStairs)[i].startLength >= 8 && (*tempStairs)[i].startLength <= 16)) || 
			(((*tempStairs)[i].endFloor == 0) && ((*tempStairs)[i].endWidth >= 6 && (*tempStairs)[i].endWidth <= 9) && ((*tempStairs)[i].endLength >= 8 && (*tempStairs)[i].endLength <= 16)) ||
			(((*tempStairs)[i].startFloor == 1) && ((*tempStairs)[i].startWidth >= 0 && (*tempStairs)[i].startWidth <= 5) && ((*tempStairs)[i].startLength >= 8 && (*tempStairs)[i].startLength <= 16)) ||
			(((*tempStairs)[i].endFloor == 1) && ((*tempStairs)[i].endWidth >= 0 && (*tempStairs)[i].endWidth <= 5) && ((*tempStairs)[i].endLength >= 8 && (*tempStairs)[i].endLength <= 16)) ||
			(((*tempStairs)[i].startFloor == 2) && ((*tempStairs)[i].startWidth >= 0 && (*tempStairs)[i].startWidth <= 9) && (((*tempStairs)[i].startLength >= 0 && (*tempStairs)[i].startLength <= 7) || ((*tempStairs)[i].startLength >= 17 && (*tempStairs)[i].startLength <= 24))) ||
			(((*tempStairs)[i].endFloor == 2) && ((*tempStairs)[i].endWidth >= 0 && (*tempStairs)[i].endWidth <= 9) && (((*tempStairs)[i].endLength >= 0 && (*tempStairs)[i].endLength <= 7) || ((*tempStairs)[i].endLength >= 17 && (*tempStairs)[i].endLength <= 24)))))
		{
			stairs_count++;
		}
		
	}

	*stairs = malloc(sizeof(Stairs) * stairs_count);
	printf("%ld bytes for all %d stairs\n", sizeof(Stairs) * stairs_count, stairs_count);

	//allocate memory for valid stairs
	int j = 0;
	for (int i = 0; i < tempstairs_count; i++)
	{
		if (!((((*tempStairs)[i].startFloor == 0) && ((*tempStairs)[i].startWidth >= 6 && (*tempStairs)[i].startWidth <= 9) && ((*tempStairs)[i].startLength >= 8 && (*tempStairs)[i].startLength <= 16)) || 
			(((*tempStairs)[i].endFloor == 0) && ((*tempStairs)[i].endWidth >= 6 && (*tempStairs)[i].endWidth <= 9) && ((*tempStairs)[i].endLength >= 8 && (*tempStairs)[i].endLength <= 16)) ||
			(((*tempStairs)[i].startFloor == 1) && ((*tempStairs)[i].startWidth >= 0 && (*tempStairs)[i].startWidth <= 5) && ((*tempStairs)[i].startLength >= 8 && (*tempStairs)[i].startLength <= 16)) ||
			(((*tempStairs)[i].endFloor == 1) && ((*tempStairs)[i].endWidth >= 0 && (*tempStairs)[i].endWidth <= 5) && ((*tempStairs)[i].endLength >= 8 && (*tempStairs)[i].endLength <= 16)) ||
			(((*tempStairs)[i].startFloor == 2) && ((*tempStairs)[i].startWidth >= 0 && (*tempStairs)[i].startWidth <= 9) && (((*tempStairs)[i].startLength >= 0 && (*tempStairs)[i].startLength <= 7) || ((*tempStairs)[i].startLength >= 17 && (*tempStairs)[i].startLength <= 24))) ||
			(((*tempStairs)[i].endFloor == 2) && ((*tempStairs)[i].endWidth >= 0 && (*tempStairs)[i].endWidth <= 9) && (((*tempStairs)[i].endLength >= 0 && (*tempStairs)[i].endLength <= 7) || ((*tempStairs)[i].endLength >= 17 && (*tempStairs)[i].endLength <= 24)))))
		{
			(*stairs)[j] = (*tempStairs)[i];
			j++;
		}
		
	}

}


void loadStairs(Stairs **stairs){
    FILE *file = fopen("stairs.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int tempcapacity = 0;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            tempcapacity++;
        }
    }
    rewind(file);

	Stairs *tempstairs = malloc(sizeof(Stairs) * tempcapacity);

    printf("%ld bytes for all %d tempstairs\n", sizeof(Stairs) * tempcapacity, tempcapacity);

	//stairs behaves like a dynamic array of struct Stair.(remember this for future purposes stupid ass)
	for (count = 0; count < tempcapacity; count++){
		if (fscanf(file, "[%d,%d,%d,%d,%d,%d]\n", &tempstairs[count].startFloor, &tempstairs[count].startWidth, &tempstairs[count].startLength, &tempstairs[count].endFloor, &tempstairs[count].endWidth, &tempstairs[count].endLength) != 6)
		{
			break;		//printf("\t%d,%d,%d,%d,%d,%d\n", tempstairs[count].startFloor, tempstairs[count].startWidth, tempstairs[count].startLength, tempstairs[count].endFloor, tempstairs[count].endWidth, tempstairs[count].endLength);
		}
	}

	validateStairs(&tempstairs, stairs, tempcapacity);
	free(tempstairs);

	fclose(file);

}


//check whether the poles are in disallowed areas
void validatePoles(Poles **tempPoles, Poles **poles, int tempPoles_count){
	//count valid poles
	for (int i = 0; i < tempPoles_count; i++)
	{
		if (!((((*tempPoles)[i].endFloor == 0) && ((*tempPoles)[i].width >= 6 && (*tempPoles)[i].width <= 9) && ((*tempPoles)[i].length >= 8 && (*tempPoles)[i].length <= 16)) ||
			(((*tempPoles)[i].startFloor == 1 || (*tempPoles)[i].endFloor == 1) && ((*tempPoles)[i].width >= 0 && (*tempPoles)[i].width <= 5) && ((*tempPoles)[i].length >= 8 && (*tempPoles)[i].length <= 16)) ||
			(((*tempPoles)[i].startFloor == 2 || (*tempPoles)[i].endFloor == 2) && ((*tempPoles)[i].width >= 0 && (*tempPoles)[i].width <= 9) && (((*tempPoles)[i].length >= 0 && (*tempPoles)[i].length <= 7) || ((*tempPoles)[i].length >= 17 && (*tempPoles)[i].length <= 24)))))
		{
			poles_count++;
		}
		
	}

	*poles = malloc(sizeof(Poles) * poles_count);
	printf("%ld bytes for all %d poles\n", sizeof(Poles) * poles_count, poles_count);

	//allocate memory for valid poles
	int j = 0;
	for (int i = 0; i < tempPoles_count; i++)
	{
		if (!((((*tempPoles)[i].startFloor == 0 || (*tempPoles)[i].endFloor == 0) && ((*tempPoles)[i].width >= 6 && (*tempPoles)[i].width <= 9) && ((*tempPoles)[i].length >= 8 && (*tempPoles)[i].length <= 16)) ||
			(((*tempPoles)[i].startFloor == 1 || (*tempPoles)[i].endFloor == 1) && ((*tempPoles)[i].width >= 0 && (*tempPoles)[i].width <= 5) && ((*tempPoles)[i].length >= 8 && (*tempPoles)[i].length <= 16)) ||
			(((*tempPoles)[i].startFloor == 2 || (*tempPoles)[i].endFloor == 2) && ((*tempPoles)[i].width >= 0 && (*tempPoles)[i].width <= 9) && (((*tempPoles)[i].length >= 0 && (*tempPoles)[i].length <= 7) || ((*tempPoles)[i].length >= 17 && (*tempPoles)[i].length <= 24)))))
		{
			(*poles)[j] = (*tempPoles)[i];
			j++;
		}
		
	}
	
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

    Poles *tempPoles = malloc(sizeof(Poles) * capacity);

    printf("%ld bytes for all %d tempPoles\n", sizeof(Poles) * capacity, capacity);

	for (count = 0; count < capacity; count++){
		if (fscanf(file, "[%d,%d,%d,%d]\n", &tempPoles[count].startFloor, &tempPoles[count].endFloor, &tempPoles[count].width, &tempPoles[count].length) != 4)
		{
			break;		//printf("\t%d,%d,%d,%d\n", tempPoles[count].startFloor, tempPoles[count].endFloor, tempPoles[count].width, tempPoles[count].length);
		}
	}

	validatePoles(&tempPoles, poles, capacity);
	free(tempPoles);

	fclose(file);

}


//check whether the walls are in disabled areas
void validateWalls(Walls **tempWalls, Walls **walls, int tempWalls_count){
	//count valid walls
	int validwalls_count = 0;
	for (int i = 0; i < tempWalls_count; i++)
	{
		if (!((((*tempWalls)[i].floor == 0) && ((((*tempWalls)[i].startWidth >= 6 && (*tempWalls)[i].startWidth <= 9) && ((*tempWalls)[i].startLength >= 8 && (*tempWalls)[i].startLength <= 16)) || 
			(((*tempWalls)[i].endWidth >= 6 && (*tempWalls)[i].endWidth <= 9) && ((*tempWalls)[i].endLength >= 8 && (*tempWalls)[i].endLength <= 16)))) || 
			(((*tempWalls)[i].floor == 1) && ((((*tempWalls)[i].startWidth >= 0 && (*tempWalls)[i].startWidth <= 5) && ((*tempWalls)[i].startLength >= 8 && (*tempWalls)[i].startLength <= 16)) || 
			(((*tempWalls)[i].endWidth >= 0 && (*tempWalls)[i].endWidth <= 5) && ((*tempWalls)[i].endLength >= 8 && (*tempWalls)[i].endLength <= 16)))) ||
			(((*tempWalls)[i].floor == 2) && ((((*tempWalls)[i].startWidth >= 0 && (*tempWalls)[i].startWidth <= 9) && (((*tempWalls)[i].startLength >= 0 && (*tempWalls)[i].startLength <= 7) || ((*tempWalls)[i].startLength >= 17 && (*tempWalls)[i].startLength <= 24))) || 
			(((*tempWalls)[i].endWidth >= 0 && (*tempWalls)[i].endWidth <= 9) && (((*tempWalls)[i].endLength >= 0 && (*tempWalls)[i].endLength <= 7) || ((*tempWalls)[i].endLength >= 17 && (*tempWalls)[i].endLength <= 24)))))))
		{
			validwalls_count++;
		}

	}

	Walls *validwalls = malloc(sizeof(Walls) * validwalls_count);
	printf("%ld bytes for all %d validwalls\n", sizeof(Walls) * validwalls_count, validwalls_count);

	//allocate memory for valid walls
	int j = 0;
	for (int i = 0; i < tempWalls_count; i++)
	{
		if (!((((*tempWalls)[i].floor == 0) && ((((*tempWalls)[i].startWidth >= 6 && (*tempWalls)[i].startWidth <= 9) && ((*tempWalls)[i].startLength >= 8 && (*tempWalls)[i].startLength <= 16)) || 
			(((*tempWalls)[i].endWidth >= 6 && (*tempWalls)[i].endWidth <= 9) && ((*tempWalls)[i].endLength >= 8 && (*tempWalls)[i].endLength <= 16)))) || 
			(((*tempWalls)[i].floor == 1) && ((((*tempWalls)[i].startWidth >= 0 && (*tempWalls)[i].startWidth <= 5) && ((*tempWalls)[i].startLength >= 8 && (*tempWalls)[i].startLength <= 16)) || 
			(((*tempWalls)[i].endWidth >= 0 && (*tempWalls)[i].endWidth <= 5) && ((*tempWalls)[i].endLength >= 8 && (*tempWalls)[i].endLength <= 16)))) ||
			(((*tempWalls)[i].floor == 2) && ((((*tempWalls)[i].startWidth >= 0 && (*tempWalls)[i].startWidth <= 9) && (((*tempWalls)[i].startLength >= 0 && (*tempWalls)[i].startLength <= 7) || ((*tempWalls)[i].startLength >= 17 && (*tempWalls)[i].startLength <= 24))) || 
			(((*tempWalls)[i].endWidth >= 0 && (*tempWalls)[i].endWidth <= 9) && (((*tempWalls)[i].endLength >= 0 && (*tempWalls)[i].endLength <= 7) || ((*tempWalls)[i].endLength >= 17 && (*tempWalls)[i].endLength <= 24)))))))
		{
			validwalls[j] = (*tempWalls)[i];
			j++;
		}
	}

/*
	//print valid walls
	printf("Valid walls are:\n");
	for (int i = 0; i < validwalls_count; i++)
	{
		printf("\t%d,%d,%d,%d,%d\n", validwalls[i].floor, validwalls[i].startWidth, validwalls[i].startLength, validwalls[i].endWidth, validwalls[i].endLength);
	}
*/	

	free(*tempWalls);

	//count valid2 (without walls around bawana) walls
	for (int i = 0; i < validwalls_count; i++)
	{
		if (!((validwalls[i].floor == floor0) && 
			((validwalls[i].startLength == 7 || validwalls[i].endLength == 7) && (validwalls[i].startWidth == 9 && validwalls[i].endWidth == 9)) || 
			((validwalls[i].startLength == 17 || validwalls[i].endLength == 17) && (validwalls[i].startWidth == 9 && validwalls[i].endWidth == 9)) || 
			(((validwalls[i].startLength <= 12 && validwalls[i].endLength >= 12) || (validwalls[i].endLength <= 12 && validwalls[i].startLength >= 12)) && (validwalls[i].startWidth == 5 && validwalls[i].endWidth == 5))))
		{
			walls_count++;
		}

	}

	*walls = malloc(sizeof(Walls) * walls_count);
	printf("%ld bytes for all %d walls\n", sizeof(Walls) * walls_count, walls_count);

	//allocate memory for valid2 walls (without walls around bawana)
	int k = 0;
	for (int i = 0; i < validwalls_count; i++)
	{
		//check if the walls are around the standing area
		if (!((validwalls[i].floor == floor0) && 
			((validwalls[i].startLength == 7 || validwalls[i].endLength == 7) && (validwalls[i].startWidth == 9 && validwalls[i].endWidth == 9)) || 
			((validwalls[i].startLength == 17 || validwalls[i].endLength == 17) && (validwalls[i].startWidth == 9 && validwalls[i].endWidth == 9)) || 
			(((validwalls[i].startLength <= 12 && validwalls[i].endLength >= 12) || (validwalls[i].endLength <= 12 && validwalls[i].startLength >= 12)) && (validwalls[i].startWidth == 5 && validwalls[i].endWidth == 5))))
		{
			(*walls)[k] = validwalls[i];
			k++;
		}

	}

	free(validwalls);

}


void loadWalls(Walls **walls){
    FILE *file = fopen("walls.txt", "r");

    if (file == NULL){
        perror("Error opening file!");
        exit(1);
    }

    int tempcapacity = 0;
    int count;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            tempcapacity++;
        }
    }
	rewind(file);

	Walls *tempWalls = malloc(sizeof(Walls) * tempcapacity);
    printf("%ld bytes for all %d tempwalls\n", sizeof(Walls) * tempcapacity, tempcapacity);

	for (count = 0; count < tempcapacity; count++){
		if (fscanf(file, "[%d,%d,%d,%d,%d]\n", &tempWalls[count].floor, &tempWalls[count].startWidth, &tempWalls[count].startLength, &tempWalls[count].endWidth, &tempWalls[count].endLength) != 5)
		{
			break; //printf("\t%d,%d,%d,%d,%d\n", tempWalls[count].floor, tempWalls[count].startWidth, tempWalls[count].startLength, tempWalls[count].endWidth, tempWalls[count].endLength);
		}
	}

	validateWalls(&tempWalls, walls, tempcapacity);
	fclose(file);

}


void loadSeed(Seed **seed){
    FILE *file = fopen("seed.txt", "r");
    
	if (file == NULL) {
        perror("Error opening seed.txt");
        exit(1);
    }
    
	*seed = malloc(sizeof(Seed));
    printf("%ld bytes for the seed\n", sizeof(Seed));
    
	if (fscanf(file, "%u", &(*seed)->seed) != 1) {
        printf("Error reading seed\n");
        exit(1);
    }
    
	fclose(file);
	
}


void loadPlayers(Player **players){

	*players = malloc(sizeof(Player) * MAX_PLAYERS);

	//below are the initializations of players A, B and C
	(*players)[A].direction = NORTH;
	(*players)[A].currentFloor = floor0;
	(*players)[A].currentWidth = A_START[1];
	(*players)[A].currentLength = A_START[2];
	(*players)[A].isPlayerActive = false;
	(*players)[A].throwCount = 0;
	(*players)[A].score = 0;

	(*players)[B].direction = WEST;
	(*players)[B].currentFloor = floor0;
	(*players)[B].currentWidth = B_START[1];
	(*players)[B].currentLength = B_START[2];
	(*players)[B].isPlayerActive = false;
	(*players)[B].throwCount = 0;
	(*players)[B].score = 0;

	(*players)[C].direction = EAST;
	(*players)[C].currentFloor = floor0;
	(*players)[C].currentWidth = C_START[1];
	(*players)[C].currentLength = C_START[2];
	(*players)[C].isPlayerActive = false;
	(*players)[C].throwCount = 0;
	(*players)[C].score = 0;

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

	fscanf(file, "[%d,%d,%d]", &(*flags)->floor, &(*flags)->width, &(*flags)->length);

	printf("%ld bytes for the flag\n", sizeof(Flag));

	fclose(file);

}


//check if the player is in bawana
bool isInBawana(Player **players, int playerName)
{
	if(((*players)[playerName].currentFloor == floor0) && 
		(((*players)[playerName].currentWidth >= 7 && (*players)[playerName].currentWidth <= 9) && ((*players)[playerName].currentLength >= 21 && (*players)[playerName].currentLength <= 24)) && 
		((*players)[playerName].score <= 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//bawana logic
void bawanaLogic(Player **players, Bawana **bawana, int playerName)
{
	if (isInBawana(players, playerName))
	{
		//food poisoning
		if ((*players)[playerName].currentFloor == floor0 && 
			(((*players)[playerName].currentWidth == (*bawana)->FoodPoisoning_1[1]) || ((*players)[playerName].currentWidth == (*bawana)->FoodPoisoning_2[1])) && 
			((*players)[playerName].currentLength == (*bawana)->FoodPoisoning_1[2] || (*players)[playerName].currentLength == (*bawana)->FoodPoisoning_2[2]))  
		{
			printf("%c eats from Bawana and have a bad case of food poisoning. Will need three rounds to recover.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'));
			//(*players)[playerName].throwCount = 3;	//FOOD_POISONING_PENALTY
		}
		//disoriented
		else if ((*players)[playerName].currentFloor == floor0 && 
				(((*players)[playerName].currentWidth == (*bawana)->Disoriented_1[1]) && ((*players)[playerName].currentLength == (*bawana)->Disoriented_1[2])) || 
				(((*players)[playerName].currentWidth == (*bawana)->Disoriented_2[1]) && ((*players)[playerName].currentLength == (*bawana)->Disoriented_2[2])))
		{
			printf("%c eats from Bawana and is disoriented and is placed at the entrance of Bawana with 50 movement points.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'));
			(*players)[playerName].currentFloor = bawanaEntrance[0];
			(*players)[playerName].currentWidth = bawanaEntrance[1];
			(*players)[playerName].currentLength = bawanaEntrance[2];
			(*players)[playerName].score += 50;		//DISORIENTED_PENALTY
			(*players)[playerName].direction = rand_int(1, 4); //random direction {NORTH, EAST, SOUTH, WEST}
		}
		//triggered
		else if (((*players)[playerName].currentFloor == floor0) && 
				((((*players)[playerName].currentWidth == (*bawana)->Triggered_1[1]) && ((*players)[playerName].currentLength == (*bawana)->Triggered_1[2])) || 
				(((*players)[playerName].currentWidth == (*bawana)->Triggered_2[1]) && ((*players)[playerName].currentLength == (*bawana)->Triggered_2[2]))))
		{
			printf("%c eats from Bawana and is triggered due to bad quality of food. %c is placed at the entrance of Bawana with 50 movement points.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'));
			(*players)[playerName].currentFloor = bawanaEntrance[0];
			(*players)[playerName].currentWidth = bawanaEntrance[1];
			(*players)[playerName].currentLength = bawanaEntrance[2];
			(*players)[playerName].score += 50;		//TRIGGERED_PENALTY
			//(*players)[playerName].currentWidth *= 2;
			//(*players)[playerName].currentLength *= 2;
		}
		//happy
		else if (((*players)[playerName].currentFloor == floor0) && 
				((((*players)[playerName].currentWidth == (*bawana)->Happy_1[1]) && ((*players)[playerName].currentLength == (*bawana)->Happy_1[2])) || 
				(((*players)[playerName].currentWidth == (*bawana)->Happy_2[1]) && ((*players)[playerName].currentLength == (*bawana)->Happy_2[2]))))
		{
			printf("%c eats from Bawana and is happy. %c is placed at the entrance of Bawana with 200 movement points.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'));
			(*players)[playerName].currentFloor = bawanaEntrance[0];
			(*players)[playerName].currentWidth = bawanaEntrance[1];
			(*players)[playerName].currentLength = bawanaEntrance[2];
			(*players)[playerName].score += 200;		//HAPPY_PENALTY
		}
		else
		{
			(*players)[playerName].score += rand_int(10, 100);		//NORMAL_PENALTY
			(*players)[playerName].currentFloor = bawanaEntrance[0];
			(*players)[playerName].currentWidth = rand_int(7, 9);
			(*players)[playerName].currentLength = rand_int(21, 24);
			printf("%c eats from Bawana and earns %d movement points and is placed at the [%d,%d,%d] of the maze.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), (*players)[playerName].score, (*players)[playerName].currentFloor, (*players)[playerName].currentWidth, (*players)[playerName].currentLength);
		}
		
	}
}


//check if the player is in standing area
bool isInStandingArea(Player **players, int playerName)
{
	if(((*players)[playerName].currentFloor == floor0) && (((*players)[playerName].currentWidth >= standAreaWidthStart) && ((*players)[playerName].currentLength >= standAreaLengthStart && (*players)[playerName].currentLength <= standAreaLengthEnd)))
	{
		if (playerName == A)
		{
			(*players)[playerName].currentWidth = A_START[1];
			(*players)[playerName].currentLength = A_START[2];
		}
		
		if (playerName == B)
		{
			(*players)[playerName].currentWidth = B_START[1];
			(*players)[playerName].currentLength = B_START[2];
		}

		if (playerName == C)
		{
			(*players)[playerName].currentWidth = C_START[1];
			(*players)[playerName].currentLength = C_START[2];
		}
		
		return true;
	}
	else
	{
		return false;
	}
}


//check whether the player enters the game
bool isPlayerEntersGame(Player **players, bool isInStandingArea, int playerName, int movementDiceValue)
{
	if (isInStandingArea && (movementDiceValue == 6))
	{
		(*players)[playerName].isEnteredGame = true;
		(*players)[playerName].currentFloor = ((playerName == A) ? A_ENTER[0] : (playerName == B) ? B_ENTER[0] : C_ENTER[0]);
		(*players)[playerName].currentWidth = ((playerName == A) ? A_ENTER[1] : (playerName == B) ? B_ENTER[1] : C_ENTER[1]);
		(*players)[playerName].currentLength = ((playerName == A) ? A_ENTER[2] : (playerName == B) ? B_ENTER[2] : C_ENTER[2]);
		(*players)[playerName].score = STARTING_POINTS;
		printf("%c is at the starting area and rolls 6 on the movement dice and is placed on [%d,%d,%d] of the maze.\n", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), (*players)[playerName].currentFloor, (*players)[playerName].currentWidth, (*players)[playerName].currentLength);
		return true;
	}
	else
	{
		printf("%c is at the starting area and rolls %d on the movement dice cannot enter the maze.\n", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), movementDiceValue);
		return false;
	}
}


//check if a player has been captured
int isPlayerCaptured(){
	if ((players[A].currentFloor == players[B].currentFloor) && 
		(players[A].currentWidth == players[B].currentWidth) && 
		(players[A].currentLength == players[B].currentLength) && 
		(players[A].isPlayerActive && !players[B].isPlayerActive))
	{
		printf("Player B has been captured by Player A\n");
		return B;
	}
	else if ((players[A].currentFloor == players[C].currentFloor) && 
			(players[A].currentWidth == players[C].currentWidth) && 
			(players[A].currentLength == players[C].currentLength) && 
			(players[A].isPlayerActive && !players[C].isPlayerActive))
	{
		printf("Player C has been captured by Player A\n");
		return C;
	}
	else if ((players[B].currentFloor == players[A].currentFloor) && 
			(players[B].currentWidth == players[A].currentWidth) && 
			(players[B].currentLength == players[A].currentLength) && 
			(players[B].isPlayerActive && !players[A].isPlayerActive))
	{
		printf("Player A has been captured by Player B\n");
		return A;
	}
	else if ((players[B].currentFloor == players[C].currentFloor) && 
			(players[B].currentWidth == players[C].currentWidth) && 
			(players[B].currentLength == players[C].currentLength) && 
			(players[B].isPlayerActive && !players[C].isPlayerActive))
	{
		printf("Player C has been captured by Player B\n");
		return C;
	}
	else if ((players[C].currentFloor == players[A].currentFloor) && 
			(players[C].currentWidth == players[A].currentWidth) && 
			(players[C].currentLength == players[A].currentLength) && 
			(players[C].isPlayerActive && !players[A].isPlayerActive))
	{
		printf("Player A has been captured by Player C\n");
		return A;
	}
	else if ((players[C].currentFloor == players[B].currentFloor) && 
			(players[C].currentWidth == players[B].currentWidth) && 
			(players[C].currentLength == players[B].currentLength) && 
			(players[C].isPlayerActive && !players[B].isPlayerActive))
	{
		printf("Player B has been captured by Player C\n");
		return B;
	}
	else
	{
		return -1;
	}
}


//captured to standing area
void capturedToStandingArea(int capturedPlayer)
{
	if (capturedPlayer == A)
	{
		players[A].currentFloor = floor0;
		players[A].currentWidth = A_START[1];
		players[A].currentLength = A_START[2];
		//players[A].isPlayerActive = false;
		printf("Player A has been moved to the starting area [%d,%d,%d]\n", players[A].currentFloor, players[A].currentWidth, players[A].currentLength);
	}
	else if (capturedPlayer == B)
	{
		players[B].currentFloor = floor0;
		players[B].currentWidth = B_START[1];
		players[B].currentLength = B_START[2];
		//players[B].isPlayerActive = false;
		printf("Player B has been moved to the starting area [%d,%d,%d]\n", players[B].currentFloor, players[B].currentWidth, players[B].currentLength);
	}
	else if (capturedPlayer == C)
	{
		players[C].currentFloor = floor0;
		players[C].currentWidth = C_START[1];
		players[C].currentLength = C_START[2];
		//players[C].isPlayerActive = false;
		printf("Player C has been moved to the starting area [%d,%d,%d]\n", players[C].currentFloor, players[C].currentWidth, players[C].currentLength);
	}
	//else
	//{
	//	return;
	//}
}


//check if there is a stair in the path(change the function if want, as an example to a stair struct pointer)
//this function will also changes the "player position to -> stair end position"
//and this returns the remaining moves
int remainingMovesIfStairInPath(int playerName, int movementDiceValue)
{
	int direction = players[playerName].direction;
	int remainingMoves = 0;
	if (direction == NORTH)
	{
		for (int i = 0; i < stairs_count; i++)
		{
			if (((players[playerName].currentWidth - movementDiceValue) > 0 && (players[playerName].currentWidth - movementDiceValue) <= stairs[i].startWidth) && 
				(players[playerName].currentLength == stairs[i].startLength) && 
				(players[playerName].currentFloor == stairs[i].startFloor))
			{
				// Check if there are multiple stairs at the same start position
				// "manhetten distance" method to find the closest stair to the flag  
				int closestStair = i;
				int minDistance = abs(stairs[i].endWidth - flag->width) + abs(stairs[i].endLength - flag->length);
				
				for (int j = i + 1; j < stairs_count; j++)
				{
					if ((stairs[j].startFloor == stairs[i].startFloor) && 
						(stairs[j].startWidth == stairs[i].startWidth) && 
						(stairs[j].startLength == stairs[i].startLength))
					{
						int distance = abs(stairs[j].endWidth - flag->width) + abs(stairs[j].endLength - flag->length);
						if (distance < minDistance)
						{
							minDistance = distance;
							closestStair = j;
						}
					}
				}
				
				remainingMoves = movementDiceValue - (players[playerName].currentWidth - stairs[closestStair].startWidth) - 1;
				players[playerName].currentFloor = stairs[closestStair].endFloor;
				players[playerName].currentWidth = stairs[closestStair].endWidth;
				players[playerName].currentLength = stairs[closestStair].endLength;
				break;
			}
		}

		return remainingMoves;
		
	}
	else if (direction == EAST)
	{
		for (int i = 0; i < stairs_count; i++)
		{
			if (((players[playerName].currentLength + movementDiceValue) >= stairs[i].startLength && (players[playerName].currentLength + movementDiceValue) <= MAX_LENGTH) && 
				(players[playerName].currentWidth == stairs[i].startWidth) && 
				(players[playerName].currentFloor == stairs[i].startFloor))
			{
				// Check if there are multiple stairs at the same start position
				int closestStair = i;
				int minDistance = abs(stairs[i].endWidth - flag->width) + abs(stairs[i].endLength - flag->length);
				
				for (int j = i + 1; j < stairs_count; j++)
				{
					if ((stairs[j].startFloor == stairs[i].startFloor) && 
						(stairs[j].startWidth == stairs[i].startWidth) && 
						(stairs[j].startLength == stairs[i].startLength))
					{
						int distance = abs(stairs[j].endWidth - flag->width) + abs(stairs[j].endLength - flag->length);
						if (distance < minDistance)
						{
							minDistance = distance;
							closestStair = j;
						}
					}
				}
				
				remainingMoves = movementDiceValue - (stairs[closestStair].startLength - players[playerName].currentLength) - 1;
				players[playerName].currentFloor = stairs[closestStair].endFloor;
				players[playerName].currentWidth = stairs[closestStair].endWidth;
				players[playerName].currentLength = stairs[closestStair].endLength;
				break;
			}
		}
		
		return remainingMoves;
		
	}
	else if (direction == SOUTH)
	{
		for (int i = 0; i < stairs_count; i++)
		{
			if (((players[playerName].currentWidth + movementDiceValue) > 0 && (players[playerName].currentWidth + movementDiceValue) <= stairs[i].startWidth) && 
				(players[playerName].currentLength == stairs[i].startLength) && 
				(players[playerName].currentFloor == stairs[i].startFloor))
			{
				// Check if there are multiple stairs at the same start position
				int closestStair = i;
				int minDistance = abs(stairs[i].endWidth - flag->width) + abs(stairs[i].endLength - flag->length);
				
				for (int j = i + 1; j < stairs_count; j++)
				{
					if ((stairs[j].startFloor == stairs[i].startFloor) && 
						(stairs[j].startWidth == stairs[i].startWidth) && 
						(stairs[j].startLength == stairs[i].startLength))
					{
						int distance = abs(stairs[j].endWidth - flag->width) + abs(stairs[j].endLength - flag->length);
						if (distance < minDistance)
						{
							minDistance = distance;
							closestStair = j;
						}
					}
				}
				
				remainingMoves = movementDiceValue - (stairs[closestStair].startWidth - players[playerName].currentWidth) - 1;
				players[playerName].currentFloor = stairs[closestStair].endFloor;
				players[playerName].currentWidth = stairs[closestStair].endWidth;
				players[playerName].currentLength = stairs[closestStair].endLength;
				break;
			}
		}

		return remainingMoves;

	}
	else if (direction == WEST)
	{
		for (int i = 0; i < stairs_count; i++)
		{
			if (((players[playerName].currentLength - movementDiceValue) >= stairs[i].startLength && (players[playerName].currentLength - movementDiceValue) <= MAX_LENGTH) && 
				(players[playerName].currentWidth == stairs[i].startWidth) && 
				(players[playerName].currentFloor == stairs[i].startFloor))
			{
				// Check if there are multiple stairs at the same start position
				int closestStair = i;
				int minDistance = abs(stairs[i].endWidth - flag->width) + abs(stairs[i].endLength - flag->length);
				
				for (int j = i + 1; j < stairs_count; j++)
				{
					if ((stairs[j].startFloor == stairs[i].startFloor) && 
						(stairs[j].startWidth == stairs[i].startWidth) && 
						(stairs[j].startLength == stairs[i].startLength))
					{
						int distance = abs(stairs[j].endWidth - flag->width) + abs(stairs[j].endLength - flag->length);
						if (distance < minDistance)
						{
							minDistance = distance;
							closestStair = j;
						}
					}
				}
				
				remainingMoves = movementDiceValue - (players[playerName].currentLength - stairs[closestStair].startLength) - 1;
				players[playerName].currentFloor = stairs[closestStair].endFloor;
				players[playerName].currentWidth = stairs[closestStair].endWidth;
				players[playerName].currentLength = stairs[closestStair].endLength;
				break;
			}
		}

		return remainingMoves;
		
	}

}


//Stairs logic
void stairsLogic(Player **players, int playerName, int movementDiceValue)
{
	//[sf,sw,sl,ef,ew,el] => [start floor, start block width number, start block length number, end floor, end block width number, end block length number]
	int remainingMoves = remainingMovesIfStairInPath(playerName, movementDiceValue);
	int direction = (*players)[playerName].direction;
	if (remainingMoves != 0)
	{
		if (direction == NORTH)
		{
			(*players)[playerName].currentWidth -= remainingMoves;
		}
		else if (direction == EAST)
		{
			(*players)[playerName].currentLength += remainingMoves;
		}
		else if (direction == SOUTH)
		{
			(*players)[playerName].currentWidth += remainingMoves;
		}
		else if (direction == WEST)
		{
			(*players)[playerName].currentLength -= remainingMoves;
		}
		
	}
	
	printf("%c lands on [%d,%d,%d] which is a stair cell. %c takes the stairs and now placed at [%d,%d,%d] in floor %d.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), (*players)[playerName].currentFloor, (*players)[playerName].currentWidth, (*players)[playerName].currentLength, ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), (*players)[playerName].currentFloor, (*players)[playerName].currentWidth, (*players)[playerName].currentLength, (*players)[playerName].currentFloor);

}


//check if there is a wall in the path
bool isWallInPath(int playerName, int movementDiceValue)
{
    int direction = players[playerName].direction;
    for (int i = 0; i < walls_count; i++)
    {
        if (direction == NORTH) {
            if (((players[playerName].currentWidth - movementDiceValue) <= walls[i].startWidth || (players[playerName].currentWidth - movementDiceValue) <= walls[i].endWidth) &&
                (players[playerName].currentFloor == walls[i].floor)) 
			{
                return true;
            }
        } 
		else if (direction == EAST) 
		{
            if ((((players[playerName].currentLength + movementDiceValue) >= walls[i].startLength && (players[playerName].currentLength + movementDiceValue) <= walls[i].endLength) &&
                (players[playerName].currentFloor == walls[i].floor)) || (((players[playerName].currentLength + movementDiceValue) >= bawanaWall1[2] && (players[playerName].currentLength + movementDiceValue) <= bawanaWall1[4]) &&
                (players[playerName].currentFloor == bawanaWall1[0])) || (((players[playerName].currentLength + movementDiceValue) >= bawanaWall2[2] && (players[playerName].currentLength + movementDiceValue) <= bawanaWall2[4]) &&
                (players[playerName].currentFloor == bawanaWall2[0])))
			{
                return true;
            }
        } 
		else if (direction == SOUTH) 
		{
            if ((((players[playerName].currentWidth + movementDiceValue) >= walls[i].startWidth && (players[playerName].currentWidth + movementDiceValue) <= walls[i].endWidth) &&
                (players[playerName].currentFloor == walls[i].floor)) || (((players[playerName].currentWidth + movementDiceValue) >= bawanaWall1[1] && (players[playerName].currentWidth + movementDiceValue) <= bawanaWall1[3]) &&
                (players[playerName].currentFloor == bawanaWall1[0])) || (((players[playerName].currentWidth + movementDiceValue) >= bawanaWall2[1] && (players[playerName].currentWidth + movementDiceValue) <= bawanaWall2[3]) &&
				(players[playerName].currentFloor == bawanaWall2[0])))
			{
                return true;
            }
        } 
		else if (direction == WEST) 
		{
            if (((players[playerName].currentLength - movementDiceValue) <= walls[i].startLength || (players[playerName].currentLength - movementDiceValue) <= walls[i].endLength) &&
                (players[playerName].currentFloor == walls[i].floor)) 
			{
                return true;
            }
        }
    }

    return false;
}


//check if there is a pole in the path and move the remaining moves
void poleInPath(int playerName, int movementDiceValue)
{
	int direction = (players)[playerName].direction;
	int remainingMoves = 0;
	if (direction == NORTH)
	{
		for (int i = 0; i < poles_count; i++)
		{
			if ((players[playerName].currentFloor == poles[i].startFloor) && 
				((players[playerName].currentWidth - movementDiceValue) <= poles[i].width))
			{
				remainingMoves = movementDiceValue - (players[playerName].currentWidth - poles[i].width) - 1;
				players[playerName].currentFloor = poles[i].endFloor;
				//players[playerName].currentLength = poles[i].length ;
				//players[playerName].currentWidth = poles[i].width;

				printf("%c lands on [%d,%d,%d] which is a pole cell.\n", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), poles[i].startFloor, poles[i].width, poles[i].length); 
				break;
			}
			
		}

		players[playerName].currentWidth -= remainingMoves;

		printf("%c slides down and now placed at [%d,%d,%d] in floor %d.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), players[playerName].currentFloor, players[playerName].currentLength, players[playerName].currentWidth, players[playerName].currentFloor);

	}
	else if (direction == EAST)
	{
		for (int i = 0; i < poles_count; i++)
		{
			if ((players[playerName].currentFloor == poles[i].startFloor) && 
				((players[playerName].currentLength + movementDiceValue) >= poles[i].length))
			{
				remainingMoves = movementDiceValue - (poles[i].length - players[playerName].currentLength) - 1;
				players[playerName].currentFloor = poles[i].endFloor;
				//players[playerName].currentLength = poles[i].length ;
				//players[playerName].currentWidth = poles[i].width;

				printf("%c lands on [%d,%d,%d] which is a pole cell.\n", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), poles[i].startFloor, poles[i].width, poles[i].length); 
				break;
			}
		}

		players[playerName].currentLength += remainingMoves;

		printf("%c slides down and now placed at [%d,%d,%d] in floor %d.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), players[playerName].currentFloor, players[playerName].currentLength, players[playerName].currentWidth, players[playerName].currentFloor);

	}
	else if (direction == SOUTH)
	{
		for (int i = 0; i < poles_count; i++)
		{
			if ((players[playerName].currentFloor == poles[i].startFloor) && 
				((players[playerName].currentWidth + movementDiceValue) >= poles[i].width))
			{
				remainingMoves = movementDiceValue - (poles[i].width - players[playerName].currentWidth) - 1;
				players[playerName].currentFloor = poles[i].endFloor;
				//players[playerName].currentLength = poles[i].length ;
				//players[playerName].currentWidth = poles[i].width;

				printf("%c lands on [%d,%d,%d] which is a pole cell.\n", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), poles[i].startFloor, poles[i].width, poles[i].length); 
				break;
			}
		}
		players[playerName].currentWidth += remainingMoves;

		printf("%c slides down and now placed at [%d,%d,%d] in floor %d.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), players[playerName].currentFloor, players[playerName].currentLength, players[playerName].currentWidth, players[playerName].currentFloor);

	}
	else if (direction == WEST)
	{
		for (int i = 0; i < poles_count; i++)
		{
			if ((players[playerName].currentFloor == poles[i].startFloor) && 
				((players[playerName].currentLength - movementDiceValue) <= poles[i].length))
			{
				remainingMoves = movementDiceValue - (players[playerName].currentLength - poles[i].length) - 1;
				players[playerName].currentFloor = poles[i].endFloor;
				//players[playerName].currentLength = poles[i].length ;
				//players[playerName].currentWidth = poles[i].width;

				printf("%c lands on [%d,%d,%d] which is a pole cell.\n", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), poles[i].startFloor, poles[i].width, poles[i].length); 
				break;
			}
		}
		players[playerName].currentLength -= remainingMoves;

		printf("%c slides down and now placed at [%d,%d,%d] in floor %d.", ((playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C'), players[playerName].currentFloor, players[playerName].currentLength, players[playerName].currentWidth, players[playerName].currentFloor);

	}
}


//check if player meets the boundaries of a floor
bool isAtFloorBoundary(Player **players, int playerName, int directionDiceValue, int movementDiceValue)
{
	int playerFloor = (*players)[playerName].currentFloor;
	int playerWidth = (*players)[playerName].currentWidth;
	int playerLength = (*players)[playerName].currentLength;

	if (playerFloor == floor0)
	{
		if (playerWidth < 0 || playerWidth > MAX_WIDTH || playerLength < 0 || playerLength > MAX_LENGTH || (!isInStandingArea(players, playerName) && (*players)[playerName].isEnteredGame))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	if (playerFloor == floor1)
	{
		if ((playerWidth < 0 || playerWidth > MAX_WIDTH || playerLength < 0 || playerLength > MAX_LENGTH || ((playerWidth >= f1DisabledWidthStart && playerWidth <= f1DisabledWidthEnd) && (playerLength >= f1DisabledLengthStart && playerLength <= f1DisabledLengthEnd))) && (*players)[playerName].isEnteredGame)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	if (playerFloor == floor2)
	{
		if ((playerWidth < 0 || playerWidth > MAX_WIDTH || playerLength <= f2DisabledLengthEnd_1 || playerLength >= f2DisabledLengthStart_2) && (*players)[playerName].isEnteredGame)
		{
			return true;
		}
		else
		{
			return false;
		}
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
    init_srand(seed->seed);	//initializing srand for random number generation

    printf("Seed: %u\n", seed->seed);
    initBawana(&bawana);		//memory has been allocated for bawana

    displayFloor();

    printf("\n");

    printf("!Flag position = [%d,%d,%d]\n", flag->floor, flag->width, flag->length);

    printf("\n");

	//if (isInStandingArea(&players, C))
	//{
	//	printf("[%d,%d,%d]\n", players[C].currentFloor, players[C].currentWidth, players[C].currentLength);
	//}
	

    //print loaded data for verification
/*
    for (int x = 0; x < stairs_count; x++){
        printf("\t%d,%d,%d,%d,%d,%d\n", stairs[x].startFloor, stairs[x].startWidth, stairs[x].startLength, stairs[x].endFloor, stairs[x].endWidth, stairs[x].endLength);
    }
*/
/*
    for (int y = 0; y < walls_count; y++){
        printf("\t%d,%d,%d,%d,%d\n", walls[y].floor, walls[y].startWidth, walls[y].startLength, walls[y].endWidth, walls[y].endLength);
    }
*/
/*
    for (int z = 0; z < poles_count; z++){
        printf("\t%d,%d,%d,%d\n", poles[z].startFloor, poles[z].endFloor, poles[z].width, poles[z].length);
    }
*/	
/*
    for (int i = 0; i < 3; i++)
    {
        printf("FoodPoisoning: %d, Disoriented: %d, Triggered: %d, Happy: %d\n", bawana->FoodPoisoning_1[i], bawana->Disoriented_1[i], bawana->Triggered_1[i], bawana->Happy_1[i]);
    }
*/
/*
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("Player %c: Direction: %d, Floor: %d, Width: %d, Length: %d, Active: %d, ThrowCount: %d, Score: %d\n", ((i == A) ? 'A' : (i == B) ? 'B' : 'C'), players[i].direction, players[i].currentFloor, players[i].currentWidth, players[i].currentLength, players[i].isPlayerActive, players[i].throwCount, players[i].score);
    }
*/


// Updated game loop implementation using your existing functions and header definitions
// Replace the existing return 0; with this game loop

	bool gameOver = false;
	int gameRound = 1;
	int foodPoisonTurns[MAX_PLAYERS] = {0, 0, 0}; // Track food poison turns for each player
	int disorientedTurns[MAX_PLAYERS] = {0, 0, 0}; // Track disoriented turns
	bool isTriggered[MAX_PLAYERS] = {false, false, false}; // Track triggered state

	printf("\n=== GAME STARTS ===\n");

	while (!gameOver) {
	    printf("\n--- Round %d ---\n", gameRound);

	    // Each player takes their turn
	    for (currentPlayer = 0; currentPlayer < MAX_PLAYERS && !gameOver; currentPlayer++) {
	        char playerName = (currentPlayer == A) ? 'A' : (currentPlayer == B) ? 'B' : 'C';
		
	        players[currentPlayer].isPlayerActive = true;
	        printf("\nPlayer %c's turn:\n", playerName);
		
	        // Check if player is food poisoned (skip turn if so)
	        if (foodPoisonTurns[currentPlayer] > 0) {
	            printf("%c is still food poisoned and misses the turn.\n", playerName);
	            foodPoisonTurns[currentPlayer]--;
			
	            if (foodPoisonTurns[currentPlayer] == 0) {
	                printf("%c is now fit to proceed from the food poisoning episode and now placed on a random Bawana cell and the effects take place.\n", playerName);
	                // Place player in Bawana and apply random cell effects
	                players[currentPlayer].currentFloor = 0;
	                players[currentPlayer].currentWidth = rand_int(7, 9);
	                players[currentPlayer].currentLength = rand_int(21, 24);
	                bawanaLogic(&players, &bawana, currentPlayer);
	            }
	            continue;
	        }
		
	        // Roll movement dice
	        int movementRoll = movementDice();
	        int directionRoll = 0;
	        bool rollDirectionDice = false;
		
	        // Check if we need to roll direction dice (every 4th throw after entering maze)
	        if (players[currentPlayer].isEnteredGame && (players[currentPlayer].throwCount % 4 == 3)) {
	            directionRoll = directionDice();
	            rollDirectionDice = true;
	        }
		
	        // Check if player is in starting area
	        if (isInStandingArea(&players, currentPlayer)) {
	            if (isPlayerEntersGame(&players, true, currentPlayer, movementRoll)) {
	                // Player entered the maze
	                players[currentPlayer].isPlayerActive = true;
	                players[currentPlayer].isEnteredGame = true;
	                players[currentPlayer].throwCount = 1; // First throw after entering
				
	                // Check if player enters directly on the flag
	                if (players[currentPlayer].currentFloor == flag->floor && 
	                    players[currentPlayer].currentWidth == flag->width && 
	                    players[currentPlayer].currentLength == flag->length) {
						
	                    printf("\n*** GAME OVER! Player %c has captured the flag upon entering the maze! ***\n", playerName);
	                    gameOver = true;
	                    break;
	                }
				
	                // Check if player enters directly on a stair cell
	                for (int i = 0; i < stairs_count; i++) {
	                    if (players[currentPlayer].currentFloor == stairs[i].startFloor &&
	                        players[currentPlayer].currentWidth == stairs[i].startWidth &&
	                        players[currentPlayer].currentLength == stairs[i].startLength) {
							
	                        printf("%c lands on [%d,%d,%d] which is a stair cell. %c takes the stairs and now placed at [%d,%d,%d] in floor %d.\n", 
	                               playerName, stairs[i].startFloor, stairs[i].startWidth, stairs[i].startLength,
	                               playerName, stairs[i].endFloor, stairs[i].endWidth, stairs[i].endLength, stairs[i].endFloor);
							
	                        players[currentPlayer].currentFloor = stairs[i].endFloor;
	                        players[currentPlayer].currentWidth = stairs[i].endWidth;
	                        players[currentPlayer].currentLength = stairs[i].endLength;
							
	                        // Check if player reached the flag after taking stairs
	                        if (players[currentPlayer].currentFloor == flag->floor && 
	                            players[currentPlayer].currentWidth == flag->width && 
	                            players[currentPlayer].currentLength == flag->length) {
								
	                            printf("\n*** GAME OVER! Player %c has captured the flag after taking stairs! ***\n", playerName);
	                            gameOver = true;
	                            break;
	                        }
	                        break;
	                    }
	                }
				
	                if (gameOver) break;
	            }
	            continue;
	        }
		
	        // Player is in the maze - process movement
	        if (players[currentPlayer].isEnteredGame) {
	            players[currentPlayer].throwCount++;
			
	            // Store original position
	            int originalFloor = players[currentPlayer].currentFloor;
	            int originalWidth = players[currentPlayer].currentWidth;
	            int originalLength = players[currentPlayer].currentLength;
			
	            // Update direction if direction dice was rolled
	            if (rollDirectionDice) {
	                switch(directionRoll) {
	                    case 2: players[currentPlayer].direction = NORTH; break;
	                    case 3: players[currentPlayer].direction = EAST; break;
	                    case 4: players[currentPlayer].direction = SOUTH; break;
	                    case 5: players[currentPlayer].direction = WEST; break;
	                    // Cases 1 and 6 are empty - keep current direction
	                }
				
	                char* directionName = (players[currentPlayer].direction == NORTH) ? "North" : 
	                                    (players[currentPlayer].direction == EAST) ? "East" :
	                                    (players[currentPlayer].direction == SOUTH) ? "South" : "West";
				
	                char* diceDirection = (directionRoll == 1 || directionRoll == 6) ? "empty" : 
	                                    (directionRoll == 2) ? "North" :
	                                    (directionRoll == 3) ? "East" :
	                                    (directionRoll == 4) ? "South" : "West";
				
	                printf("%c rolls %d on the movement dice and %s on the direction dice, changes direction to %s", 
	                       playerName, movementRoll, diceDirection, directionName);
	            } else {
	                char* directionName = (players[currentPlayer].direction == NORTH) ? "North" : 
	                                    (players[currentPlayer].direction == EAST) ? "East" :
	                                    (players[currentPlayer].direction == SOUTH) ? "South" : "West";
				
	                printf("%c rolls %d on the movement dice and moves %s", 
	                       playerName, movementRoll, directionName);
	            }
			
	            // Check for walls or boundaries blocking the movement
	            if (isWallInPath(currentPlayer, movementRoll) || isAtFloorBoundary(&players, currentPlayer, directionRoll, movementRoll)) {
	                char* directionName = (players[currentPlayer].direction == NORTH) ? "North" : 
	                                    (players[currentPlayer].direction == EAST) ? "East" :
	                                    (players[currentPlayer].direction == SOUTH) ? "South" : "West";
				
	                printf(" and cannot move in the %s. Player remains at [%d,%d,%d]\n", 
	                       directionName, originalFloor, originalWidth, originalLength);
					
	                // Deduct movement points for blocked movement
	                players[currentPlayer].score -= MOVEMENT_COST;
					
	                char* currentDirection = (players[currentPlayer].direction == NORTH) ? "North" : 
	                                       (players[currentPlayer].direction == EAST) ? "East" :
	                                       (players[currentPlayer].direction == SOUTH) ? "South" : "West";
					
	                printf("%c moved 0 cells that cost %d movement points and is left with %d movement points and is moving in the %s.\n", 
	                       playerName, MOVEMENT_COST, players[currentPlayer].score, currentDirection);
	            } else {
	                // Calculate new position based on direction
	                int newWidth = originalWidth;
	                int newLength = originalLength;
	                int cellsMoved = movementRoll;
	                int actualCellsMoved = 0;
	                bool stairEncountered = false;
	                bool poleEncountered = false;
				
	                // Handle triggered state (move twice as fast)
	                if (isTriggered[currentPlayer]) {
	                    cellsMoved = movementRoll * 2;
	                    printf("%c is triggered and ", playerName);
	                }
				
	                // Handle disoriented state (random direction)
	                if (disorientedTurns[currentPlayer] > 0) {
	                    players[currentPlayer].direction = rand_int(1, 4); // Random direction 1-4
	                    switch(rand_int(1, 4)) {
	                        case 1: players[currentPlayer].direction = NORTH; break;
	                        case 2: players[currentPlayer].direction = EAST; break;
	                        case 3: players[currentPlayer].direction = SOUTH; break;
	                        case 4: players[currentPlayer].direction = WEST; break;
	                    }
	                    disorientedTurns[currentPlayer]--;
					
	                    char* randomDirection = (players[currentPlayer].direction == NORTH) ? "North" : 
	                                          (players[currentPlayer].direction == EAST) ? "East" :
	                                          (players[currentPlayer].direction == SOUTH) ? "South" : "West";
					
	                    printf("%c is disoriented and moves in the %s", playerName, randomDirection);
					
	                    if (disorientedTurns[currentPlayer] == 0) {
	                        printf("\n%c has recovered from disorientation.\n", playerName);
	                    }
	                }
				
	                // Move step by step to check for stairs and poles
	                for (int step = 1; step <= cellsMoved; step++) {
	                    int tempWidth = originalWidth;
	                    int tempLength = originalLength;
					
	                    // Calculate position after this step
	                    switch(players[currentPlayer].direction) {
	                        case NORTH: tempWidth = originalWidth - step; break;
	                        case EAST: tempLength = originalLength + step; break;
	                        case SOUTH: tempWidth = originalWidth + step; break;
	                        case WEST: tempLength = originalLength - step; break;
	                    }
					
	                    // Check boundaries
	                    if (tempWidth < 0 || tempWidth > MAX_WIDTH || tempLength < 0 || tempLength > MAX_LENGTH) {
	                        break; // Can't move further
	                    }
					
	                    // Check for stair at this position
	                    for (int i = 0; i < stairs_count; i++) {
	                        if (players[currentPlayer].currentFloor == stairs[i].startFloor &&
	                            tempWidth == stairs[i].startWidth &&
	                            tempLength == stairs[i].startLength) {
								
	                            printf(" and moves %d cells", step);
	                            printf("\n%c lands on [%d,%d,%d] which is a stair cell. %c takes the stairs and now placed at [%d,%d,%d] in floor %d.", 
	                                   playerName, stairs[i].startFloor, stairs[i].startWidth, stairs[i].startLength,
	                                   playerName, stairs[i].endFloor, stairs[i].endWidth, stairs[i].endLength, stairs[i].endFloor);
								
	                            // Move player to stair end position
	                            players[currentPlayer].currentFloor = stairs[i].endFloor;
	                            players[currentPlayer].currentWidth = stairs[i].endWidth;
	                            players[currentPlayer].currentLength = stairs[i].endLength;
								
	                            // Continue movement with remaining steps from new position
	                            int remainingSteps = cellsMoved - step;
	                            if (remainingSteps > 0) {
	                                switch(players[currentPlayer].direction) {
	                                    case NORTH: players[currentPlayer].currentWidth -= remainingSteps; break;
	                                    case EAST: players[currentPlayer].currentLength += remainingSteps; break;
	                                    case SOUTH: players[currentPlayer].currentWidth += remainingSteps; break;
	                                    case WEST: players[currentPlayer].currentLength -= remainingSteps; break;
	                                }
	                                printf(" Player continues moving %d more cells and is now at [%d,%d,%d].\n", 
	                                       remainingSteps, players[currentPlayer].currentFloor, 
	                                       players[currentPlayer].currentWidth, players[currentPlayer].currentLength);
	                            } else {
	                                printf("\n");
	                            }
							
	                            actualCellsMoved = cellsMoved;
	                            stairEncountered = true;
	                            break;
	                        }
	                    }
					
	                    if (stairEncountered) break;
					
	                    // Check for pole at this position
	                    for (int i = 0; i < poles_count; i++) {
	                        if (players[currentPlayer].currentFloor == poles[i].startFloor &&
	                            tempWidth == poles[i].width &&
	                            tempLength == poles[i].length) {
								
	                            printf(" and moves %d cells", step);
	                            printf("\n%c lands on [%d,%d,%d] which is a pole cell. %c slides down and now placed at [%d,%d,%d] in floor %d.", 
	                                   playerName, poles[i].startFloor, poles[i].width, poles[i].length,
	                                   playerName, poles[i].endFloor, poles[i].width, poles[i].length, poles[i].endFloor);
								
	                            // Move player down the pole
	                            players[currentPlayer].currentFloor = poles[i].endFloor;
	                            players[currentPlayer].currentWidth = poles[i].width;
	                            players[currentPlayer].currentLength = poles[i].length;
								
	                            // Continue movement with remaining steps from new position
	                            int remainingSteps = cellsMoved - step;
	                            if (remainingSteps > 0) {
	                                switch(players[currentPlayer].direction) {
	                                    case NORTH: players[currentPlayer].currentWidth -= remainingSteps; break;
	                                    case EAST: players[currentPlayer].currentLength += remainingSteps; break;
	                                    case SOUTH: players[currentPlayer].currentWidth += remainingSteps; break;
	                                    case WEST: players[currentPlayer].currentLength -= remainingSteps; break;
	                                }
	                                printf(" Player continues moving %d more cells and is now at [%d,%d,%d].\n", 
	                                       remainingSteps, players[currentPlayer].currentFloor, 
	                                       players[currentPlayer].currentWidth, players[currentPlayer].currentLength);
	                            } else {
	                                printf("\n");
	                            }
							
	                            actualCellsMoved = cellsMoved;
	                            poleEncountered = true;
	                            break;
	                        }
	                    }
					
	                    if (poleEncountered) break;
					
	                    // Update actual cells moved
	                    actualCellsMoved = step;
	                }
				
	                // If no stairs or poles encountered, move normally
	                if (!stairEncountered && !poleEncountered) {
	                    switch(players[currentPlayer].direction) {
	                        case NORTH: newWidth = originalWidth - actualCellsMoved; break;
	                        case EAST: newLength = originalLength + actualCellsMoved; break;
	                        case SOUTH: newWidth = originalWidth + actualCellsMoved; break;
	                        case WEST: newLength = originalLength - actualCellsMoved; break;
	                    }
					
	                    // Check if final position is valid
	                    bool validMove = true;
	                    if (newWidth < 0 || newWidth > MAX_WIDTH || newLength < 0 || newLength > MAX_LENGTH) {
	                        validMove = false;
	                    }
					
	                    if (validMove) {
	                        players[currentPlayer].currentWidth = newWidth;
	                        players[currentPlayer].currentLength = newLength;
	                        printf(" and moves %d cells and is now at [%d,%d,%d].\n", 
	                               actualCellsMoved, players[currentPlayer].currentFloor, newWidth, newLength);
	                    } else {
	                        printf(" but cannot complete the movement due to boundaries. Player remains at [%d,%d,%d]\n", 
	                               originalFloor, originalWidth, originalLength);
	                        actualCellsMoved = 0;
	                    }
	                }
				
	                // Calculate movement cost
	                int movementCost = (actualCellsMoved > 0) ? actualCellsMoved : MOVEMENT_COST;
	                players[currentPlayer].score -= movementCost;
				
	                char* currentDirection = (players[currentPlayer].direction == NORTH) ? "North" : 
	                                       (players[currentPlayer].direction == EAST) ? "East" :
	                                       (players[currentPlayer].direction == SOUTH) ? "South" : "West";
				
	                printf("%c moved %d cells that cost %d movement points and is left with %d movement points and is moving in the %s.\n", 
	                       playerName, actualCellsMoved, movementCost, players[currentPlayer].score, currentDirection);
	            }
			
	            // Check if player reached the flag
	            if (players[currentPlayer].currentFloor == flag->floor && 
	                players[currentPlayer].currentWidth == flag->width && 
	                players[currentPlayer].currentLength == flag->length) {
					
	                printf("\n*** GAME OVER! Player %c has captured the flag! ***\n", playerName);
	                gameOver = true;
	                break;
	            }
			
	            // Check for player captures using your existing function
	            int capturedPlayer = isPlayerCaptured();
	            if (capturedPlayer != -1) {
	                capturedToStandingArea(capturedPlayer);
	            }
			
	            // Check if player needs to be transported to Bawana (movement points <= 0)
	            if (players[currentPlayer].score <= 0) {
	                printf("%c movement points are depleted and requires replenishment. Transporting to Bawana.\n", playerName);
	                players[currentPlayer].currentFloor = 0;
	                players[currentPlayer].currentWidth = rand_int(7, 9);
	                players[currentPlayer].currentLength = rand_int(21, 24);
	                bawanaLogic(&players, &bawana, currentPlayer);
	            }
			
	            // Check if player entered Bawana area
	            if (isInBawana(&players, currentPlayer)) {
	                bawanaLogic(&players, &bawana, currentPlayer);
	            }
			
	            // Check if player fell back to starting area
	            if (isInStandingArea(&players, currentPlayer)) {
	                players[currentPlayer].isPlayerActive = false;
	                players[currentPlayer].isEnteredGame = false;
	                printf("%c has returned to the starting area.\n", playerName);
	            }
	        }
	    }

	    gameRound++;

	    //to prevent infinite games (optional)
	    //if (gameRound > 10) {
	    //    printf("\nGame ended due to maximum rounds reached.\n");
	    //    gameOver = true;
	    //}

	    printf("A: [%d,%d,%d]\n", players[A].currentFloor, players[A].currentWidth, players[A].currentLength);
	    printf("B: [%d,%d,%d]\n", players[B].currentFloor, players[B].currentWidth, players[B].currentLength);
	    printf("C: [%d,%d,%d]\n", players[C].currentFloor, players[C].currentWidth, players[C].currentLength);
	
	    printf("A points: %d\n", players[A].score);
	    printf("B points: %d\n", players[B].score);
	    printf("C points: %d\n", players[C].score);
	}


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
