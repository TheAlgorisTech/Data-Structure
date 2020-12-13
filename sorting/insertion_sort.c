/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.c
 *
 *    Description:  Array is split into a sorted and unsoreted part, values from unsorted
 *    					   part are picked and placed at the correct position in the sorted part
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



int *insertion_sort(int *table)
{
	int len = sizeof(table);
  int j;
	for (int i=1; i < len; i++) {

				int temp = table[i];

				for (j=i-1; j>=0 && temp <= table[j]; j--) table[j+1] = table[j];
				table[j+1] = temp;

			 }
	return table;
}



int main(){
		int to_sort[] = {10,5,6,8,1,20,30,15};
		printArray(to_sort);
		printf("Insertion sort\n");
		printArray(insertion_sort(to_sort));


		return EXIT_SUCCESS;


}









