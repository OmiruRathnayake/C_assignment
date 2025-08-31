#include <stdio.h>

#define MAX_WIDTH 9
#define MAX_LENGTH 24

const int A_START[3]= {0,6,12};
const int B_START[3]= {0,9,8};
const int C_START[3]= {0,9,16};


//difining directions as datatypes.
typedef enum Directions
{
	NORTH = (-1),	//width + NORTH = w - 1 
	EAST = (1), 	//length + EAST = l + 1
	SOUTH = (1), 	//width + SOUTH = w + 1
	WEST = (-1)		//length + WEST = l - 1
}drctions;


//block architecture.
struct Cell
{
	int floor,width,length;	//cells(blocks)
};


typedef struct Palyer
{
	int A[3];
	int B[3];
	int C[3];
}plyr;


//Logics of ground floor.
void Floor1(int floor, int width, int length, char Player_tag)
{
	//printf("floor1 width=%d,length=%d\n", max_width, max_length);
	plyr P;
	
	if (Player_tag == 'A')
	{
		P.A[0] = floor;
    	P.A[1] = width;
    	P.A[2] = length;
		printf("A = {%d,%d,%d}\n", floor, width, length);
	}

	if (Player_tag == 'B')
	{
		P.B[0] = floor;
    	P.B[1] = width;
    	P.B[2] = length;
		printf("B = {%d,%d,%d}\n", floor, width, length);
	}
	
	if (Player_tag == 'C')
	{
		P.C[0] = floor;
    	P.C[1] = width;
    	P.C[2] = length;
		printf("C = {%d,%d,%d}\n", floor, width, length);
	}
	
	/*
	for (int i = 0; i < 3; i++)
	{
		(i == 3) ? printf("%d,", A[i]) : printf("\n");
	}*/

	//printf("%d,%d,%d\n", floor, width, length);

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
int stairs(int sf, int sw, int sl, int ef, int ew, int el)
{
	//[sf,sw,sl,ef,ew,el] => [start floor, start block width number, start block length number, end floor, end block width number, end block length number]


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


int main()
{
	displayFloor();

	/*
	drctions north = NORTH;
	(north = -1) ? printf("north\n"):printf("?\n");
	*/

	printf("\n");

	FILE *entr;
	entr = fopen("test.txt", "r");
	if (entr == NULL)
	{
		printf("Error opening file!");
	}

	int A,B,C, A_entered=0, B_entered=0, C_entered=0;
	
	while (fscanf(entr, "%d,%d,%d", &A,&B,&C) == 3)
	{
		if (A == 6 && !A_entered)
		{
			printf("A has entered the game!\n");
			Floor1(A_START[0], A_START[1], A_START[2], 'A');
			A_entered = 1;
		}
		
		if (B == 6 && !B_entered)
		{
			printf("B has entered the game!\n");
			Floor1(B_START[0], B_START[1], B_START[2], 'B');
			B_entered = 1;
		}
		
		if (C == 6 && !C_entered)
		{
			printf("C has entered the game!\n");
			Floor1(C_START[0], C_START[1], C_START[2], 'C');
			C_entered = 1;
		}
	
	}

	fclose(entr);

	return 0;
}
