/* bit.c */
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <math.h>

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
 */
void is_multiple_of_3(int num){
}

/**
 * Binary Representation of a Decimal number.
 */
void binary_repr(int num) {
	printf("Binary representation of %d is = \n", num);
	if (num>1)
		binary_repr(num/2);

	printf("%d", (num%2));
}

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
int power_of_2(int num){
	int ret = 0;
	// Bitwise AND of n and num-1 will be 0.
	if ((num & (num-1)) == 0) {
		ret = 1;
		printf("The num=%d is a power of 2.\n", num);
	}

	printf("\nThe num=%d is not a power of 2.\n", num);
	return ret;
}

/**
 * Find the position of the only SET bit.
 */
int find_position_of_only_set_bit(int num) {
	unsigned int i, pos = 1;

	if (!power_of_2(num)) {
		printf("This number has more than 1 SET bit.\n");
		return -1;
	}

	while(!(i&num)) {
		i = i<<1;
		++pos;
	}
	printf("The position of the ONLY SET bit in %d is %d", num, pos);
	return pos;
}

/**
 * Count the number of Set Bits
 */
int count_set_bits(unsigned int num) {
	// Method 1
	unsigned int i = 1, count = 0;
	unsigned int cached_num = num;

	while(num){
		if (i&num){
			count++;
		}
		num = num>>1;
	}

	printf("\nNumber of Set Bits in %d are %d\n", cached_num, count);


	// Method 2
	/* When we subtract 1 from a number then if
	 * - LSB of the num is 1 then its toggled and then done you have num-1
	 * - LSB of the num is 0 then all the bits are toggled till the 1st SET_BIT(1)
	 * 		of the number and done you have a num-1.
	 *
	 * 	So when you do (num & (num-1)) if clears the Right Most set Bit.
	 */
	count = 0;
	num = cached_num;
	while (num != 0){
		printf("\nNum = %d", num);
		num = (num & (num-1));
		count++;
	}
	printf("\nNumber of Set Bits in %d are %d\n", cached_num, count);

	return count;
}

/**
 * rotate_num - Rotate "d" bits of a Number
 * 0010 1101 1001 0111 ---> 1001 0111 0010 1101
 * Bit Rotation is similar to the shift operation except that in rotation
 * the bits that fall off at one end are put back together at the other end.
 * @IP: num = number , d = number of bits to be rotated
 * @OP: Rotated number
 */
int rotate_num(int num, unsigned int d) {
	printf("\nRotating num=%d by %d bits\n", num, d);
	int rotated_num, cached_num, length;

	//length = (8 * (sizeof(int)));
	length = 4;

	printf("Length of the number= %d %d ", length, length-d);
	num = num<<d;
	cached_num = num>>(length-d);

	rotated_num = num|cached_num;

	return rotated_num;
}

/**
 * The idea is to keep putting set bits of the num in reverse_num
 * until num becomes zero.
 *
 * After num becomes zero, shift the remaining bits of reverse_num.
 * Let num is stored using 8 bits and num be 00000110.
 * After the loop you will get reverse_num as 00000011.
 * Now you need to left shift reverse_num 5 more times and you get
 * the exact reverse 01100000.
 */

unsigned int reverseBits1(unsigned int num) {
	unsigned int count = sizeof(num) * 8 - 1;
	unsigned int reverse_num = num;

	// Right Shift the num by 1
	num >>= 1;
	while(num) {
	   reverse_num <<= 1;
	   reverse_num |= num & 1;
	   num >>= 1;
	   count--;
	}

	reverse_num <<= count;
	return reverse_num;

}

/* Loop through all the bits of an integer.
 * If a bit at ith position is set in the I/p num then
 * set the bit at (NO_OF_BITS – 1) – i in O/p.
 * Where NO_OF_BITS is number of bits present in the given number.
 */
unsigned int reverseBits2(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
   }
    return reverse_num;
}


/**
 * add_1 - Adds 1 to a number
 *
 * Check the LSB first
 * if LSB == 0, then Flip it and then done -- > you have n+1
 * if LSB == 1,
 * Then Flip all the bits after the rightmost 0th bit
 * also flip this 0th bit too.
 *
 * XOR is your friend here.
 */
int add_1(int num) {
	int k = 1;

	while (num & k) {
		//printf("\nnum = %d , %d , %d, %d", num, k,  (num & k), (num ^ k));
		num = num ^ k;
		k = k <<1;
	}

	num = num ^ k;
	return num;
}

/*
 * Detect opposite signs
 * Concept of Sign Bit
 * XOR truth Table
 */
int detect_opposite_signs(int x, int y) {
	if ((x^y) < 0)
		return 1;

	return 0;
}




int main() {
	int num;
	power_of_2(9);
	multiply_by_7(9);
	multiply_by_9(9);
	num = 18;
	printf("Binary representation of %d is = \n", num);
	binary_repr(num);

	num = find_position_of_only_set_bit(16);
	num = count_set_bits(17);

	num = count_set_bits(-21);

	num = add_1(19);
	binary_repr(19);
	printf("\nAdds 1 equals = %d ", num);
	binary_repr(num);
	num = detect_opposite_signs(23, 5);
	printf("\n%d", num);

	num = rotate_num(8, 2);
	printf("\nrotated %d\n", num);
	binary_repr(num);

	int res= flip_bit(4);
	printf("\nLargest sequence %d \n", res);

	insert_m_in_n(4, 2, 4, 2);

	return 0;
}
