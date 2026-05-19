/*
 * main.c
 *
 *  Created on: Feb 24, 2025
 *      Author: brak3r
 */


#include <stdio.h>


int main (void)
{
	int n1, n2, n3;
	float average;
		printf("Enter the number n1: \n");
		fflush(stdout);
		        scanf("%d",&n1);

		printf("Enter the number n2: \n");
		fflush(stdout);
				scanf("%d",&n2);

		printf("Enter the number n3: \n");
		fflush(stdout);
				scanf("%d",&n3);

		average = (n1+n2+n3)/3;

		printf("\nAverage is :%f \n",average);
		fflush(stdout);

		//getchar();



	return 0;
}
