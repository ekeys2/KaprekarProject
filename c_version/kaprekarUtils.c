#include<math.h>

#include "kaprekarUtils.h"

/**
 * <p>This function tests whether the given input <code>n</code>
 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
 * integer n whose square can be split into two positive integers
 * whose sum is equal to the original number.  For the purposes of
 * this method, we restrict our consideration to base-10 representations.</p>
 *
 * For example, 45 is a Kaprekar number, because
 *   45<sup>2</sup> = 2025
 * and
 *   20 + 25 = 45.
 *
 * <p>See Wikipedia's
 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
 * article for more information.</p>
 *
 * @param n
 * @return <code>true</code> if <code>n</code> is a Kaprekar Number,
 * <code>false</code> otherwise.
 */
int isKaprekar(int n) {

  if(n < 1) {
    return 0; // false is not a recognized keyword
  }

  int i;
  //compute the square
  long square = n * (long) n;
  //compute the number of digits of the square
  int numDigits = (int) log10(square) + 1; // it was counting the number of digits for the wrong variable
  long modulus = 1; //modulus could not equal zero
  long first, second;

  //for each possible "split" of the square...
  for(i=1; i<=numDigits; i++) { // The variablw is numDigits not NumberOfDigits
    //increase the modulus by a factor of 10
    modulus *= 10; // the variable "modulus" was misspelled

    //split the square into two parts
    first = square / modulus;
    second = square % modulus;

    //test if the split makes a Kaprekar number
    //the second part cannot be zero and if
    //the sum of the two parts is equal to n, then it is
    if(second > 0 && n == first + second) { //there needed to be two equal signs
      return 1;
    }
  }
  return 0;

}
