/*
 * =====================================================================================
 *
 *       Filename:  selection_sort.c
 *
 *    Description:  Selection sort repeatedly find the minimum element from unsorted part
 *    						  and putting it at the beginning
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>


void swap(int *a, int *b)
{
		/*
		 * Swap elements a b
		 */
		int z = *b;
		*b = *a;
		*a = z;

}

void printArray(int *array)
{
	/*
	 * Print Array
	 *
	 */

		int len = (int) sizeof(array);

		for (int i=0; i < len; i++) printf("%d ", array[i]);
		printf("\n");

}

int *selection_sort(int *table)
{
 		// Find minimum element in table
		// Place it at the begining of the array
	
		int len = sizeof(table);

		for (int i=0; i < len; i++){

				int minidx = i;
				for (int j =i+1; j < len; j++)
						if ( table[i] > table[j]) minidx = j;

				if (minidx !=i) swap(&table[minidx], &table[i]);

		}

		return table;


}




int main(){
		int to_sort[] = {10,5,6,8,1,20,30,15};
		printArray(to_sort);
		printf("Selection sort\n");
		printArray(selection_sort(to_sort));


		return EXIT_SUCCESS;


}
