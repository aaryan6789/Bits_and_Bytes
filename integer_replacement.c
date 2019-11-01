/*
 * integer_replacement.c
 *
 *  Created on: Apr 22, 2018
 *      Author: hsahu
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "bit.h"

/* Given a positive integer n and you can do operations as follow:
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * What is the minimum number of replacements needed for n to become 1?
 */
int integerReplacement(int n) {
    int count = 0;

    // Corner Case
    if (n == INT_MAX)
        return 32;

    // Base Case
    if (n <= 1)
        return 0;

    if( n == 2)
        return 1;

    if (n == 3)
        return 2;

    // Recursive Case
    // When n is Even
    else if (n % 2 == 0 ) {
        count = integerReplacement(n>>1) + 1;
    }
    else {
        // When n is odd
        int countPlus = integerReplacement(n - 1) + 1;
        int countMinus = integerReplacement(n + 1) + 1;

        // Which ever is smaller
        count = countPlus < countMinus ? countPlus : countMinus;
    }
    return count;
}
