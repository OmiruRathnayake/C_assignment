#include <stdio.h>
#include <stdbool.h>

struct Player
{
	int direction;
	int currentFloor;
	int currentWidth;
	int currentLength;
	bool isPlayerActive;
	int throwCount;
};


struct Stair
{
    int startFloor;
    int startWidth;
    int startLength;
    int endFloor;
    int endWidth;
    int endLength;

};


struct Wall
{
    int floor;
    int startWidth;
    int startLength;
    int endWidth;
    int endLength;
};


struct Pole
{
    //
};


//global variables
struct Stair *stairs = NULL;
int numStairs = 0;

void loadStairs(){
    FILE *file = fopen("stairs.txt", "r");

    if (file == NULL){
        printf("Error opening file!");
    }

    int capacity = 10;
    int count = 0;

    stairs = malloc(capacity * sizeof(struct Stair));

    if (!stairs)
    {
        perror("memory allocation failed");
        exit(1);
    }
    
    while (fscanf(file, "[%d,%d,%d,%d,%d,%d]", &stairs[count].startFloor, &stairs[count].startWidth, &stairs[count].startLength, &stairs[count].endFloor, &stairs[count].endWidth, &stairs[count].endLength))
    {
        count++;
        if (count >= capacity)
        {
            capacity *= 2;
            stairs = realloc(stairs, capacity * sizeof(sizeof(struct Stair)));
            if (!stairs)
            {
                perror("memory allocation error!");
                exit(1);
            }
            
        }
        
    }
    
    fclose(file);
    numStairs = count;
}

//loadWalls

//loadFlags

//load the seed

int main(){
    //
}