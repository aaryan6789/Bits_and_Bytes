/* bit.c */
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
/**
 * Check if a number is a Power of 2
 * A number is a power of 2 means : 2, 4, 8, 16, 32, 64 etc
 * Then it will have only 1 set bit.
 * 	  32 16 8 4 2 1
 * 2   0  0 0 0 1 0
 * 4   0  0 0 1 0 0
 * 8   0  0 1 0 0 0
 * 16  0  1 0 0 0 0
 * 32  1  0 0 0 0 0
 */
void power_of_2(int num){

	// Bitwise AND of n and num-1 will be 0.
	if ((num & (num-1)) == 0)
		printf("The num:%d is a power of 2.\n", num);
}


/**
 * Multiply by 7, 9
 * n<<k -- LeftShift Operator
 * Means n*2^k
 *
 * So we can calculate multiply by 3, 5, 7, 9, 11, 13 etc
 */
void multiply_by_7(int num){
	int result;

	result = ((num<<3) - num);
	printf("%d multiply by 7 = %d\n", num, result);
}

void multiply_by_9(int num){
	int result;

	result = ((num<<3) + num);
	printf("%d multiply by 9 = %d\n", num, result);
}

/**
 * Check if a number is Multiple of 3
 *
 */
void is_multiple_of_3(int num){

}


int main() {

	power_of_2(8);
	multiply_by_7(9);
	multiply_by_9(9);
	return 0;
}
