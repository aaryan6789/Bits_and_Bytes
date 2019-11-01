/* insert_m_in_n.c * Created on: Apr 16, 2018 *      Author: hsahu */
#include <stdlib.h>
#include <stdio.h>
//#include <error.h>
#include <math.h>
#include "bit.h"

/* CTCI | 6 5.1
 * Insertion:
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
 * Write a method to insert M into N such that M starts at bit j and ends at bit i.
 * You can assume that the bits j through i have enough space to fit all of M.
 *
 * That is, if M = 10011, you can assume that there are at least 5 bits between
 * j and i.
 * You would not, for example, have j = 3 and i = 2, because M could not fully
 * fit between bit 3 and bit 2.
 */

/* Algorithm:
 * 1. N should have its bits flushed out from j to i
 * 2. Shift M to be in that position
 */
int insert_m_in_n(int n, int m, int i, int j){
	// Lets assume int is a 8 bit number
	printf("Insertion of %d in %d\n", m, n);
	int allOnes = ~0;				// we get allOnes = 1111 1111
	int left = allOnes << (j+1);		// Push all 1s before jth bit position

	int right = (1<<i) - 1 ;		// Push 1's after ith position

	// Mask = All 1s except from j to i
	int mask = right | left;

	// Clear M bits from N
	int M_cleared_N = n & mask;

	m = m<<i;
	int res = (M_cleared_N | m);

	printf("= %d\n", res);
	return (M_cleared_N | m);
}
