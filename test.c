#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rand_utils.h"

FILE *filex(){
	FILE *fptr;
	fptr = fopen("test.txt", "w");
	return fptr;
}
int main()
{
    FILE *fptrx = filex();
	fprintf(fptrx, "Hello");
	fprintf(fptrx, "\nWorld!");
	fclose(fptrx);
}
    /*
    FILE *fptr;
    fptr = fopen("test.txt", "r");
    char line[10];

    int a,b,c;

    while (fscanf(fptr, "%d,%d,%d", &a, &b, &c) != -1)
    {
        printf("%d\n", fscanf(fptr, "%d,%d,%d", &a, &b, &c));
    }
    
    //while (fscanf(fptr, "%d,%d,%d", &a, &b, &c) == 3){
    //    printf("%d,%d,%d\n", a,b,c);
    //}

    fclose(fptr);
    */
//}

/*
	FILE *entr;
	entr = fopen("enter.txt", "r");
	if (entr == NULL)
	{
		printf("Error opening file!");
	}

	FILE *move_A = fopen("move_A.txt", "r");
	FILE *move_B = fopen("move_B.txt", "r");
	FILE *move_C = fopen("move_C.txt", "r");

	int A,B,C, A_entered=0, B_entered=0, C_entered=0, turn;

	/*while (1){	
		if (turn == 0)	//A s turn
		{
			fscanf(entr, "%d,%d,%d", &A,&B,&C);
			if (A == 6 && !A_entered)
			{
				printf("A has entered the game!\n");
				A_entered = 1;
			}
			if (A_entered)
			{
				if (move_A == NULL){
					printf("Error opening file!");
				}
			
				int move,dir;

				while (fscanf(move_A, "%d,%d", &move, &dir) == 2)
				{
					printf("%d,%d\n", move, dir);
				}

				//fclose(move_A);

				Floor1(A_START[0], A_START[1], A_START[2], 'A', move);
			}
		}
		else if (turn == 1)	//B s turn
		{
			...
		}
		else if (turn == 2)	//C s turn
		{
			...
		}
    */		
		
		
/*
	while (fscanf(entr, "%d,%d,%d", &A,&B,&C) == 3)
	{
		if (A == 6 && !A_entered)
		{
			printf("A has entered the game!\n");
			A_entered = 1;
		}
		if (A_entered)
		{
			//FILE *move_A = fopen("move_A.txt", "r");
			if (move_A == NULL){
				printf("Error opening file!");
			}
		
			int move,dir;
			while (fscanf(move_A, "%d,%d", &move, &dir) == 2)
			{
				printf("%d,%d\n", move, dir);
			}
			
			//fclose(move_A);
			Floor1(A_START[0], A_START[1], A_START[2], 'A', move);
		}
		
		if (B == 6 && !B_entered)
		{
			printf("B has entered the game!\n");
			B_entered = 1;
		}
		if (B_entered)
		{
			//FILE *move_B = fopen("move_B.txt", "r");
			if (move_B == NULL){
				printf("Error opening file!");
			}
			int move,dir;
			while (fscanf(move_B, "%d,%d", &move, &dir) == 2)
			{
				printf("%d,%d\n", move, dir);
			}
			
			//fclose(move_B);
			Floor1(B_START[0], B_START[1], B_START[2], 'B', move);
		}
		
		if (C == 6 && !C_entered)
		{
			printf("C has entered the game!\n");
			C_entered = 1;
		}
		if (C_entered)
		{
			//FILE *move_C = fopen("move_C.txt", "r");
			if (move_C == NULL){
				printf("Error opening file!");
			}
			int move,dir;
			while (fscanf(move_C, "%d,%d", &move, &dir) == 2)
			{
				printf("%d,%d\n", move, dir);
			}
			
			//fclose(move_C);
			Floor1(C_START[0], C_START[1], C_START[2], 'C', move);
		}
	
	}

	fclose(entr);
*/