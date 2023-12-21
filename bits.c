/*
 * CS:APP Data Lab
 *
 * Derek Kwon, 931069092
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

 int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) { //Function already solved
  return ~(~x | ~y); //Demorgan's law: ~(x&y) = ~x | ~y, add ~ at the front to negate the negation and get x&y
  //return 2;
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) { //Function already solved
	return	(x << 31) >> 31; //Shift left until LSB is at the front, then push LSB back to original place
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    n <<= 3; //Get nth byte position in bit form (3 becomes 24, 2 becomes 16, 1 becomes 8)
    x >>= n;
    return (x & 0xff); //0xff is least significant bit
    //I used information from https://stackoverflow.com/questions/12379109/how-can-i-get-the-least-significant-byte-of-a-variable-in-c
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
    int equals = !(x ^ y); //If equal, x^y will always result in 0, !(0) = 1
    return equals;
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    unsigned int high = ~0; //All 1s
    unsigned int low = ~0;
    high <<= highbit + 1; //Create 2 masks
    low <<= lowbit;
    return (low ^ high) & low; //return xor of high and low
    //&low to ensure return 0 if lowbit > highbit

}
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
    int result = 0; //Could not use a loop so this was the next best way I could think of
    int a = x;      //Uses shifts to get byte at position n starting at n=0 and moves byte to position 3-n
    int shift1 = 24;
    a <<= shift1;
    a >>= 24;
    a <<= shift1;
    result += a; //Once byte is moved, add to result
    int b = x; //Repeat
    int shift2 = 16;
    b <<= shift2;
    b >>= 24;
    b <<= shift2;
    result += b;
    int c = x;
    int shift3 = 8;
    c <<= shift3;
    c >>= 24;
    c <<= shift3;
    result += c;
    int d = x;
    int shift4 = 0;
    d <<= shift4;
    d >>= 24;
    d <<= shift4;
    result += d;
    return result;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    int not = ~x+1; //results in 0 if x is 0, different number otherwise
    int bits = (not | x) >> 31; //if x is 0, sign bit will be 0, will result in -1 otherwise
    return bits + 1; //1 if x is 0, 0 otherwise
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x) {
    int negative = ~x + 1; //logical negative of x
    return(x & negative);
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  return ~0;
  //0: 0000 0000 0000 0000 0000 0000 0000 0000
  //-1: 1111 1111 1111 1111 1111 1111 1111 1111
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    unsigned int x = ~0; //Max unsigned int value
    x >>= 1; //max value of signed int is 1 bit less
    return x;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) { //Function already solved
	int negN = ~n + 1; //Becomes -(n+1) + 1
	int shiftVal = 32 + negN; //Becomes 32 - n
	int shiftLeft = x << shiftVal; //Shifts x starting at MSB to the front
	int shiftRight = shiftLeft >> shiftVal; //Shifts right using 1s instead of 0s
	int same = shiftRight ^ x; //Bitwise XOR
	return !same;
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    int sum = x + y; //Add x and y
    int a = x>>31; //Check sign bit of x
    int b = x>>31; //Check sign bit of y
    int c = sum>>31; //Check sign bit of sum
    return !!(a^b)|(!(a^c)&!(b^c));
    //Check if sign bit of x = sign bit of y = sign bit of sum
    //if sign bit of x != sign bit of y, there cannot be overflow
    //Otherwise, if sign bit of x = sign bit of y != sign bit of sum, there is overflow
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    int a = !((x + ~y) >> 31); //Check if x > y ignoring signs
    x = x >> 31; //Isolate sign bit of x
    y = y >> 31; //Isolate sign bit of y
    return (!x & y) | (a & (!x | y)); //Will return 1 if x is positive or y is negative, returns value otherwise
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
    x >>= 31; //Gets sign bit, 1 for negative and 0 for positive or 0
    return x || 0; //will return 1 if 1 || 0, 0 otherwise
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
    int product = (x << 2) + x; //Multiply by 5
    int sum = 7 & (product >> 31); //get sign bit of product, add 7 before shift if negative
    int quotient = (product + sum) >> 3; //Divide by 8
    return quotient;
}
/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) { //Function already solved
	int signBit = x >> 31; //extend the sign bit to all bits. If x is negative, signBit is all 1s; otherwise, signBit is all 0s
	int maskSignBit = ~(1 << 31); //a mask to remove sign bit
	int reverse = ~(x & maskSignBit) + 1; //get 2's complement for negative cases
	return ((~signBit) & x) | (signBit & reverse); //if positive or 0, return x; else, return reverse.
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    int exp = 158; //31 + bias, bias = 127
    int mask = 1<<31;
    int sign = x&mask; //Find sign
    int frac;
    if (x == mask)
        return mask | (158<<23);
    if (!x)
        return 0;
    if (sign)
        x = ~x + 1;
    while (!(x&mask)) { //Find exponent
        x = x<<1;
        exp = exp - 1;
    }
    frac = (x&(~mask)) >> 8; //Find fraction
    if (x&0x80 && ((x&0x7F) > 0 || frac&1))
        frac = frac + 1;
    return sign + (exp<<23) + frac; //Put sign in leftmost bit, then exponent in next 8 bits (shifted 23 to make room for frac), then fraction
}

int main()
{

}
