/*
 * power_of_3.c
 *
 *  Created on: Apr 22, 2018
 *      Author: hsahu
 */

/* One simple way of finding out if a number n is a power of a number b
 * is to keep dividing n by b as long as the remainder is 0.
 *
 * This is because we can write
 * 		n=b^x= b X b X ..... X b
 *
 * Hence it should be possible to divide n by b x times,
 * every time with a remainder of 0 and the end result to be 1.
 *
 * Time complexity : O(log_b(n))O(log​b​​ (n)).
 * In our case that is O(log_3n)O(log3​ n).
 *
 * The number of divisions is given by that logarithm.
 */

#define false 0
#define true 1

int isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }

/* ^Note^ : We need a guard to check that n != 0,
 * otherwise the while loop will never finish.
 *
 * For negative numbers, the algorithm does not make sense,
 * so we will include this guard as well.
 */
