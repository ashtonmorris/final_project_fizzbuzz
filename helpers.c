/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 //implement a searching algorithm
bool search(int value, int values[], int n)
{
    //initialize the min and max
    int min = 0;
    int max = n - 1;
    
     //while length of list > 0
     while(min <= max)
     {
        //min and max will be adjusted based on result of mid index
        int mid = min + ((max - min) / 2);
        if (value == values[mid])
            return true;
        else if (value < values[mid])
            max = mid - 1;
        else if (value > values[mid])
            min = mid + 1;
     }
     
     return false;
}

/**
 * Sorts array of n values.
 */

//implement a sorting algorithm using choice of bubble, selection or insertion

void sort(int values[], int n)

{
    //using selection sort
    for (int i = 0; i < n - 1; i++)
    {
        // set smallest
        int s = i;
        
        for (int l = i; l < n; l++) 
        {
            // Find index 
            if (values[s] > values[l])
            {
                s = l;
            }
        }
        
        // check to see if smallest has changed
        if (s != i)
        {
            // switch i with smallest value
            int temp = values[s];
            values[s] = values[i];
            values[i] = temp;
        }
    }
    
    return;
}
    
