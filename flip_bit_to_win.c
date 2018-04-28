/*
 * flip_bit_to_win.c
 *
 *  Created on: Apr 16, 2018
 *      Author: hsahu
 */
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <math.h>
#include "bit.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
/** CTCI
 * Flip a bit from 0 to 1 to get the max continuous sequence of 1s
 */
int flip_bit(unsigned int a){
    /* If all bits are l, binary representation of 'a' has all 1s */
	if (~a == 0)
    	return 8*sizeof(int);

	int currLen = 0, prevLen = 0, maxLen = 0;

	// Traverse through the number bit by bit
    while (a!= 0){
        // If Current bit is a 1 then increment currLen++
    	if ((a & 1) == 1){
    		currLen++;
    	}
    	// If Current bit is a 0 then check next bit of 'a'
        else if ((a & 1) == 0){
            /* Update prevLen to 0 (if next bit is 0)
            or currLen (if next bit is 1). */
            prevLen = (a & 2) == 0 ? 0 : currLen;

//            if ((a&2) == 0)
//            	prevLen = 0;
//            else
//            	prevLen = currLen;

            // If two consecutively bits are 0 then currLen also will be 0.
            currLen = 0;
        }

        // Update maxLen if required
        maxLen = MAX(prevLen + currLen, maxLen);

        // Remove last bit (Right shift)
        a >>= 1;
    }

    // We can always have a sequence of at least one 1, this is flipped bit
    return maxLen+1;
}
