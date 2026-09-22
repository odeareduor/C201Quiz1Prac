/* `intArrVectOps.c`
    Implementations of some functions for `int` arrays.

    See `intArrVectOps.h` for the public interface.  

    Author: Ardy
    Date: Aug 18, 2026
*/

#include "intArrVectOps.h" //For `ARR_ERROR_OUTPUT` and consistency.
#include <stdio.h> //For `printf`, `scanf`, `stdin`, `stderr`, and more.
#include <limits.h> //For `INT_MAX`, `INT_MIN`, `LLONG_MIN`, `LLONG_MAX` and more.




/* `arr_sum_d`
    Sum the elements of an array of `int`s.
    See the associated H file for the documentation.  
*/
long long arr_sum_d(int len, const int arr[])
{ 
    int i = 0;
    long long sum = 0;
    while (i < len) //We want to add `arr[i]` to the sum.
    {   
        //First, check for overflow:

        if (arr[i] >= 0)
        {
            if (sum > LLONG_MAX - arr[i])
            {
                fprintf(stderr, "Overflow error: `sum` is too large.\n");
                return ARR_ERROR_OUTPUT; 
            }
        }
        else //If the element is negative:
        { 
            if (sum  < LLONG_MIN + 1 - arr[i]){
                fprintf(stderr, "Overflow error: `sum` is too small.\n");
                return ARR_ERROR_OUTPUT; 
            }       
        }

        //Now add to the sum:

        sum += arr[i]; //Implicit conversion.
        i++;
    }

    return sum;
}




/* `arr_vect_sum_d`
    Alter the elements of an array to be the elements of the vector sum
    (i.e. elementwise sum) of that array with another array of the same length.

    See the associated H file for the documentation.  
*/
void arr_vect_sum_d(int len, int arr[], const int addend[])
{
    int i = 0;
    while (i < len)
    {   
        //First, check for overflow:
        if (addend[i]  >= 0) //If the addend element is positive:
        {
            if (arr[i] > INT_MAX - addend[i])
            {
                fprintf(stderr, "Overflow error: augmented element at index %d is too large.\n", i);
                return; //Leave the `i`th element onwards untouched.
            }
        }
        else //If the addend element is negative:
        { 
            if (arr[i]  < INT_MIN - addend[i])
            {
                fprintf(stderr, "Overflow error: augmented element at index %d is too small.\n", i);
                return; //Leave the `i`th element onwards untouched.
            }       
        }
        arr[i] += addend[i]; //Do the elementwise addition.
        i++;
    }

    return;
}




/* `arr_elemwise_inc_d`
    Increment every element of an `int` array by a single `int` value.

    See the associated H file for the documentation.  
*/
void arr_elemwise_inc_d(int len, int arr[], int x)
{
    int i = 0;
    while (i < len) 
    {   
        if (x == 0) 
        {   
            return; //Function is a no-op in this case.
        }
        //Else:
        //First, check for overflow:
        if (x > 0) //If the increment value is positive:
        {
            if (arr[i] > INT_MAX - x)
            {
                fprintf(stderr, "Overflow error: The incremented element at index %d is too large.\n", i);
                return; //Leave the `i`th element onwards untouched.
            }
        }
        else //If the increment value is negative:
        { 
            if (arr[i]  < INT_MIN - x)
            {
                fprintf(stderr, "Overflow error: The incremented element at index %d is too small.\n", i);
                return; //Leave the `i`th element onwards untouched.
            }       
        }
        arr[i] += x; //Do the incrementation.
        i++;
    }

    return;
}




/* `arr_vect_dot_prod_d`
    Calculate the dot product of two `int` arrays seen as vectors.  

    See the associated H file for the documentation.  
*/
long long arr_vect_dot_prod_d(int len, const int arr1[], const int arr2[])
{
    int i = 0;
    long long dotprod = 0;
    long long prodOfithElems = 0;
    while (i < len) //We want to add `arr1[i] * arr2[i]` to the sum.
    {   
        prodOfithElems = arr1[i] * (long long) arr2[i];

        //First, check for overflow:
        if (prodOfithElems >= 0)
        {
            if (dotprod > LLONG_MAX - prodOfithElems)
            {
                fprintf(stderr, "Overflow error: weighted partial sum at index %d is too large.\n", i);
                return ARR_ERROR_OUTPUT; 
            }
        }
        else //If the product of the `i`th elements is negative:
        { 
            if (dotprod < LLONG_MIN + 1 - prodOfithElems){
                fprintf(stderr, "Overflow error: weighted partial sum at index %d is too small.\n", i);
                return ARR_ERROR_OUTPUT;
            }       
        }

        //Now add the product of the `i`th elements to the sum:

        dotprod += prodOfithElems; //Implicit conversion.
        i++;
    }

    return dotprod;
}






