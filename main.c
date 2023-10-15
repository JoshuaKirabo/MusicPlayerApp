//
//  main.c
//  Code Example
//
//  Created by Joshua Kirabo on 10/15/23.
//

#include<stdio.h>
#include<stdlib.h>

int main() 
{
    // A one-dimensional array and a pointer to an integer.
    int array[3] = {1, 2, 3};
    int *pointerArray;

    //Assigning the address of the pointer to the first element of the array
    pointerArray = array;

    // Printing the elements of the array
    printf("One-dimensional array using pointer:\n");
    for(int i=0; i<3; i++) 
        {
            printf("%d ", *(pointerArray + i));
        }
    printf("\n\n");

    // 2D Array with Pointer to Ponter integer
    int twoDArray[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int **twoDArrayPointer;

    // Allocating an array of integer pointers.
    twoDArrayPointer = (int **)malloc(2 * sizeof(int *));

    // Assigning the address of the two arrays to the pointers.
    twoDArrayPointer[0] = twoDArray[0];
    twoDArrayPointer[1] = twoDArray[1];

    // Printing the 2D array elements
    printf("Two-dimensional array using pointer to pointer:\n");
    for(int i=0; i<2; i++) 
        {
            for(int j=0; j<3; j++)
                {
                    printf("%d ", *(*(twoDArrayPointer + i) + j)); 
                }
            printf("\n");
        }

    // Freeing the memory
    free(twoDArrayPointer);
    
    printf("\n");
    return 0;
}
