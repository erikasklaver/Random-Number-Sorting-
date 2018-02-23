/*
 * Lab1.c


 *
 *  Created on: Sep 11, 2015
 *      Author: Erika
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lab1.h"

int main(){

//This allows for random numbers to be selected each time the program runs
	srand(time(NULL));

//The user will choose how many numbers they want sorted
	printf("How many numbers do you want sorted? ");
	int numReals = 0;
	scanf("%d", &numReals);
	while (numReals == 0){
		printf("You entered no numbers");
		return (0);
	}
	if (numReals < 0){
		printf("Error: cannot enter a negative number");
	}
	else{


		int *reals2 = (int *) malloc(numReals * sizeof(int));
		if (reals2 == NULL){
			printf("Error: Malloc in main failed");
			return EXIT_FAILURE;
		}
		for (int i = 0; i < numReals; ++i){
			reals2[i] = (rand()%(MAX_RAND_NUM - MIN_RAND_NUM +1)) + MIN_RAND_NUM;
		}

		printArray(reals2, numReals);

		selectionSort(reals2, numReals);

		printArray(reals2, numReals);

	}
	return EXIT_SUCCESS;






}

void printArray (int *intArray, int size){
	for (int i = 0; i < size; ++i){
		printf("%d ", intArray[i]);
	}
}

int findIndexOfMax (int *intArray, int numItems){
	int x = 0;
	int max = intArray[0];
	for (int i=1; i<numItems; ++i){
		if (intArray[i]>max){
		max = intArray[i];
		x = i;
		}
	}
	return x;
}


void selectionSort(int *intArray, int numItems){

	for(int i = numItems; i>1; --i){


	int maxIndex = findIndexOfMax(intArray, i);
	int maxNum = intArray[maxIndex];
	int temp = intArray[i-1];

	intArray[i-1] = maxNum;
	intArray[maxIndex] = temp;
	}
}


