/*
	Simulating First Fit, Best Fit and Worst Fit Algorithm
*/
#include<stdio.h>

int main(void)
{
	int i; // loop counter
	int n; // number of blocks
	int b[10]; // hold size of blocks
	int c[10]; // will be used for space wastage calculation
	int option; // option to perform switch case
	int new; // size of arriving block
	int min; // hold block with minimum space wastage
	int max; // hold block with maximum space wastage

	printf("Simulating first fit, best fit and worst fit :\n");
	// ask for number of blocks
	printf("Enter the number of blocks : ");
	scanf ("%d", &n);

	// get size of each block
	for (i = 1; i <= n; i++)
	{
		printf ("Enter the size of %d block:", i);
		scanf ("%d", &b[i]);
	}

	// size of new arriving block
	printf ("Enter the size of Arriving block :");
	scanf ("%d", &new);

	// prompt to select the algorithm
	printf ("Select algorithm :\n1.First fit\n2.Best fit\n3.Worst fit\n:");
	scanf ("%d", &option);

	switch (option)
	{
		case 1:
			// First fit
			// Allocate the new block to first block that can hold it 
			for (i = 1; i <= n; i++)
			{
				// check if block can hold the new block
				// if the size => new block
				// allocate it and break
				if (b[i] >= new)
	    			{
	      				printf ("Arriving block is allocated to %d block.\n", i);
	      				break;
	    			}
			}
	  		break;

		case 2:
			// Best fit
			// Allocate the best block to minimize the space wastage
			// loop over all blocks to calculate the space wastage
	  		for (i = 1; i <= n; i++)
			{
	  			c[i] = b[i] - new; // calculate space wastage
			}
			// find block with minimum space wastage
			min = 1;	// assume block 1 has min wastage

			// loop over other blocks to find min
	  		for (i = 2; i <= n; i++)
			{
	  			if (c[min] >= c[i])
	    			min = i;
			}
			// min will hold the block with min wastage
			// allocate it and break
	      		printf ("Arriving block is allocated to %d block.\n", min);
	  		break;

		case 3:
			// Worst case
			// Allocate the biggest block first
	  		for (i = 1; i <= n; i++)
			{
	  			c[i] = b[i] - new; // calculate space wastage
			}
			// find block with maximum space wastage
			max = 1;
	  		for (i = 2; i <= n; i++)
			{
	  			if (c[max] < c[i])
	    			max = i;
			}
	      		printf ("Arriving block is allocated to %d block.\n", max);
	  		break;

		default:
	  		printf ("Invalid option selected.\n");
	}
}
