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
}drctns;


//block architecture.
struct Cell
{
	int floor,width,length;	//cells(blocks)
};


//player postions.
typedef struct PlayerStartPositions
{
	int A[3];
	int B[3];
	int C[3];
}position;


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
void displayFloor(int floor) {
    switch (floor) {
        case 0: // Floor 1 (Ground floor)
            printf("FLOOR 1 (GROUND FLOOR)\n");
            printf("Start positions:\n");
            printf("A[0,6,12] -> (*a)\n");
            printf("B[0,9,8]  -> (*b)\n");
            printf("C[0,9,16] -> (*c)\n");
            printf("Entrance to BAWANA (#)\n");
            break;

        case 1: // Floor 2
            printf("FLOOR 2\n");
            printf("Bridge across positions [7–17]\n");
            break;

        case 2: // Floor 3
            printf("FLOOR 3\n");
            printf("Similar layout to Floor 2 with bridge [7–17]\n");
            break;

        default:
            printf("Invalid floor number! Use 0, 1, or 2.\n");
    }
}


int main()
{
	position start = {A_START, B_START, C_START};

	for (int i = 0; i<3; i++){
		printf("%d,", start.A[i]);
	}

	Floor1(MAX_WIDTH,MAX_LENGTH);
	Floor2(MAX_WIDTH,MAX_LENGTH);
	Floor3(MAX_WIDTH,MAX_LENGTH);

	
	//displayFloor(){}		/*below should change according to player position*/
	int floor_num;
	printf("Enter floor number: ");
	scanf("%d", &floor_num);

	displayFloor(floor_num);
	

	return 0;
}
