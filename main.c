//
//  main.c
//  Exercise_find_the_sum_of_the_array_elements_closest_to_zero
//
//  Created by Karol Czołpiński on 08/07/2022.
//

#include <stdio.h>
#include <stdlib.h> // to use abs();

void find_the_sum_of_array_elements_which_is_closest_to_zero(void);

void find_the_sum_of_array_elements_which_is_closest_to_zero(void)
{
    int i, j; // for loops
    int size;
    int two_elements_sum_distance_from_zero;
    int element1;
    int element2;
    
    printf("Choose the array size: ");
    scanf("%d", &size);
    
    if (size < 2)
    {
        printf("The size of an array has to be at least 2, try again...\n");
        printf("Input the size of an array: ");
        scanf(" %d", &size);
    }
    
    int array[size]; // array declaration
    
    printf("\nInput the array elements (can be greater or smaller than 0):\n");
    
    for (i = 0; i < size; i++)  // values assignment to the array elements
        scanf(" %d", &array[i]);
    
    // now the crutial part - searching for the pair sum closest to zero
    // before beginning let's assume, that the first two elements are the closest to zero
    two_elements_sum_distance_from_zero = abs(array[0] + array[1]);
    element1 = array[0];
    element2 = array[1];

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size && j !=  i; j++)   // i know, it's not the most optimized way
        {
            if (abs(array[i] + array[j]) < two_elements_sum_distance_from_zero)
                // abs() from <stdlib.h>
            {
                two_elements_sum_distance_from_zero = abs(array[i] + array[j]);
                element1 = array[i];
                element2 = array[j];
            }
        }
    }
    
    printf("The two array elements sum distance, which is closest to zero is %d.\n",
           two_elements_sum_distance_from_zero);
    printf("Those elements are %d and %d.", element1, element2);
}

int main(void)
{
    find_the_sum_of_array_elements_which_is_closest_to_zero();
    return 0;
}
