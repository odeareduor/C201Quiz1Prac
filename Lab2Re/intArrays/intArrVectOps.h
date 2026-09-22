#ifndef INT_ARR_VECT_OPS_H
#define INT_ARR_VECT_OPS_H



#include <limits.h> //For `INT_MAX`, `INT_MIN`, `LLONG_MIN`, `LLONG_MAX` and more.
#define ARR_ERROR_OUTPUT LLONG_MIN 




/* `arr_sum_d`
    Sum the elements of an array of `int`s.

    Parameters:
        arr: The `int` array whose elements we sum.

        len: The length of `arr`.

    Preconditions:
        - `arr` points to a valid array of at least `len` elements.

        - `len` is positive.

    Return:
        The sum of the elems if for every `i` the partial sum of the 
        first `i` elems is in the range `LLONG_MIN + 1` to `LLONG_MAX` inclusive.
        Otherwise, `ARR_ERROR_OUTPUT` is returned.

    Postconditions:
        - The elements of `arr` remain unaltered.

        - The return value is in the range `LLONG_MIN + 1` to `LLONG_MAX` inclusive if the function is successful.

        - If the partial sum at index `i` grows greater than `LLONG_MAX` or less than `LLONG_MIN + 1` the function prints an error message onto `stderr` and returns `ARR_ERROR_OUTPUT`.
    
    Example:
        Assume `int x[3] = {5,6,7};`
        Then
        ```
        arr_sum_d(3,x);
        ```
        returns 18.
*/
long long arr_sum_d(int len, const int arr[]);




/* `arr_vect_sum_d`
    Alter the elements of an array to be the elements of the vector sum
    (i.e. elementwise sum) of that array with another array of the same length. 

    Parameters:
        len: The length of `arr` and `addend`.

        arr: The `int` array whose elements will be altered to become the elementwise sum.

        addend: The array that is (elementwise) added to `arr` to produce the vector sum.

    Preconditions:
        - `arr` points to a valid array of at least `len` elements.

        - `addend` points to a valid array of at least `len` elements.

        - `arr` and `addend` must not overlap.

        - `len` is positive.


    Postcondition:
        - The elements of `arr` are each altered to reflect the elementwise sum if no overflow occurs.

        - If the sum of `arr[i]` with `addend[i]` is greater than `INT_MAX` or less than `INT_MIN` the function prints an error message onto `stderr` that mentions the first index at which this happened. The elements at index `i` onwards remain unchanged in this case.

    
    Example:
        Assume 
        `int x[3] = {5,6,7};`
        and 
        `int y[3] = {1,2,3};`
        Then
        ```
        arr_vect_sum_d(3, x, y);
        ```
        alters `x` to have the elements 6, 8, and 10.
*/
void arr_vect_sum_d(int len, int arr[], const int addend[]);




/* `arr_elemwise_inc_d`
    Increment every element of an `int` array by a single `int` value.

    Mathematically, thinking of a C `int` array as a vector in $\mathbb{Z}^n \cap \mathbb{R}^n$, this function is the elementwise incrementation of that vector by an integer scalar value.

    Parameters:
        arr: The `int` array whose elements we increment.

        len: The length of `arr`.

        x: The value by which every element is incremented.

    Preconditions:
        - `arr` points to a valid array of at least `len` elements.

        - `len` is positive.

    Postcondition:
        The elements of `arr` are each incremented by `x` if no overflow occurs.


    Notes:
        - This function alters/mutates the array `arr`.

        - If the sum with `x` at index `i` is greater than `INT_MAX` or less than `INT_MIN` the function prints an error message onto `stderr` that mentions the first index at which this happened. The elements at index `i` onwards remain unchanged in this case.

    
    Example:
        Assume `int x[3] = {5,6,7};`
        Then
        ```
        arr_elemwise_inc_d(3, x, 1);
        ```
        alters `x` to have the elements 6, 7, and 8.
*/
void arr_elemwise_inc_d(int len, int arr[], int x);




/* `arr_vect_dot_prod_d`
    Calculate the dot product of two `int` arrays seen as vectors.  

    Parameters:
        len: The length of `arr1` and `arr2`.

        arr1: The `int` array to be dot-produced with `arr2`.

        arr2: The `int` array that is to dot-produce `arr1`.

    Preconditions:
        - `arr1` points to a valid array of at least `len` elements.

        - `arr2` points to a valid array of at least `len` elements.

        - `len` is positive.


    Return:
        The weighted sum of the elements of `arr1` where the weights are the 
        elements of `arr2` if for every `i` the partial weighted sum of 
        the first `i` elems is in the range `LLONG_MIN + 1` to `LLONG_MAX` 
        inclusive. Else it returns `ARR_ERROR_OUTPUT`.


    Postconditions:
        - `arr1` and `arr2` remain unaltered.

        - The return value is in the range `LLONG_MIN + 1` to `LLONG_MAX` inclusive if the function is successful.


    Notes:
        - This function does not alter the elements of either array.

        - If the partial sum of weighted elements at index `i`  greater than `LLONG_MAX` or less than `LLONG_MIN + 1` the function returns `ARR_ERROR_OUTPUT` and prints an error message onto `stderr` that mentions the first index at which this happened. 

    
    Example:
        Assume 
        `int x[3] = {5,6,7};`
        and 
        `int y[3] = {1,2,3};`
        Then
        ```
        arr_vect_dot_prod_d(3, x, y);
        ```
        returns 38.
*/
long long arr_vect_dot_prod_d(int len, const int arr1[], const int arr2[]);




#endif