#include <stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("test.txt", "r");
    char line[10];

    int a,b,c;

    while (fscanf(fptr, "%d,%d,%d", &a, &b, &c) == 3){
        printf("%d,%d,%d\n", a,b,c);
    }

    fclose(fptr);
}