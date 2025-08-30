#include <stdio.h>

#define MAX_WIDTH 9
#define MAX_LENGTH 24

//#define NORTH (-1)			//width + NORTH = w - 1    ///after throwing direction dice///
//#define EAST 1				//length + EAST = l + 1
//#define SOUTH 1				//width + SOUTH = w + 1
//#define WEST (-1)				//length + WEST = l - 1

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


//Logics of ground floor.
void Floor1(int max_width, int max_length)
{
	printf("floor1 width=%d,length=%d\n", max_width, max_length);
	/*code*/
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
	for (int i = 0; i<3; i++){
		printf("%d", A_START[i]);
		(i!=2) ? printf(",") : printf("\n");
	}	
	*/

	drctions north = NORTH;
	(north = -1) ? printf("north\n"):printf("?\n");
	
	return 0;
}
