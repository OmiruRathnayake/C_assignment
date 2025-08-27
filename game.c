#include <stdio.h>

#define A_START {0,6,12}
#define B_START {0,9,8}
#define C_START {0,9,16}
#define MAX_WIDTH 9
#define MAX_LENGTH 24

typedef struct PlayerStartPositions
{
	int A[3];
	int B[3];
	int C[3];
}position;


struct Cell
{
	int floor,width,length;	//cells(blocks)
};


void Floor1(int max_width, int max_length)
{
	printf("floor1 width=%d,length=%d\n", max_width, max_length);
}

void Floor2(int max_width, int max_length)
{
	printf("floor2 width=%d,length=%d\n", max_width, max_length);
	/*code*/
}


void Floor3(int max_width, int max_length)
{
	printf("floor3 width=%d,length=%d\n", max_width, max_length);
	/*code*/
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

	return 0;
}
