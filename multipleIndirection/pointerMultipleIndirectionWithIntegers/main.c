/*
Author:       Billy Gene Ridgeway
Purpose:      Explore how pointers and multiple indirection works in C.
Date:         June 23rd., 2022
*/

#include <stdio.h>

#define LENGTH 3

int data[LENGTH];			// An array of some integers.

int main(int argc, char **argv) {
	int *pi;			    // A simple pointer to an integer.
	int **ppi;			// A pointer to a pointer to an integer.

	printf("Multiple Indirection example\n\n");

	// Initialize our integer array from zero to LENGTH.
	for (int i = 0; i < LENGTH; i++) {
		data[i] = i;
	}
	for (int i = 0; i < LENGTH; i++) {
		printf("%d\n", data[i]);
	}

	printf("\n\n");     // Add some spaces to make the output more readable.

	/*
	* A: simple pointer to a pointer to an integer
	*
	*/
	pi = data;								// set the pointer to an integer  to the start of the data array
	ppi = &pi;								// and set the pointer to a pointer to pi itself

	for (int i = 0; i < LENGTH; i++) {
		printf("The array's address is: %p\n", data);                  // 'p; with the string name will print the address.
		printf("The item pointed to by pi is: %d\n", *pi);         // 'd' with the '*' dereferencer will print the value in the address where the pointer is referencing.
		printf("The item pointed to by ppi is: %p\n", *ppi);     // 'p' with the dereferencer '*' will print the address stored in the variable pi.
		printf("The item pointed to by double indirection of ppi is: %d\n", **ppi);                                             // 'd' with 2 '*' dereferencers will print the value that the pointer pi references.
		printf("The address of pi is: %p and the value of ppi (what it points to) is: %p\n\n", &pi, ppi);      // '&' pi will print the address of pi and ppi will print the address of ppi.
        printf("The value of pi is %p and it points to %d\n\n", pi, *pi);       // "pi" will print out pi's address and pi with '*' will print out the value stored at that address.

		pi += 1;		// Advance the pointer to point to the next element of the data array.
	}

	return 0;
}
