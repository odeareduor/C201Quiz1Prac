/* `intArrUserIO.h`
    Declarations for user input/output functions for `int` arrays.

    The functions are:
        `arr_fill_d`
        `arr_print_d`
*/

#ifndef SUBFUNCS_H
#define SUBFUNCS_H

#include <stddef.h> //For `size_t`.
#include <stdbool.h> //For `bool` datatype.




/* `arr_fill_d`
    Fill the elements of an array of `int`s with inputs from `stdin`.

    Parameters:
        arr: The `int` array to be assigned to.

        len: The length of `arr`.

    Preconditions:
        - `arr` points to a valid writable array of at least `len` elements.

        - `len` is positive.

    Postconditions:
        - The user is prompted to enter `len` many numbers.
         
        - Each element of `arr` is assigned user input integers until input
        parsing fails. Remaining elements retain their previous values.

    Notes:
        - The inputs must be delimited by (any positive number of) white-space
          characters.

        - The function may not work as intended if the entered integers are not
          between `INT_MIN` and `INT_MAX` inclusive. These macros are defined
          in `limits.h`.

        - If any character other than digits (with the exception of '+' and 
          '-' preceding the digits) is entered, it prevents the remaining 
          elements from being assigned a value. Consequently, they retain the 
          value they had prior to the call to this function.

        - An EOF mark (often sent with [Ctrl]+[D]) prevents the remaining 
          elements from being assigned a value. Consequently, they retain the
          value they had prior to the call to this function.

        - `stdin` remains unflushed.
*/
void arr_fill_d(int len, int arr[]);




/* `arr_print_d`
    Print the elements of a `int` array as a comma-separated list.

    Parameters:
        arr: The `int` array to be printed.

        len: The length of `arr`.

    Preconditions:
        - `arr` points to a valid array of at least `len` elements.
        - `len` is non-negative.

    Side effect:
        The array elements will be printed. All but the final element are
        followed by a comma and a space. The comma-separated list is enclosed
        within brackets.
    
    Notes:
        - A `len` of 0 -- while nonsensical -- results into printing `[]`.

    Example: 
        Assume `int x[3] = {5,6,7};`.
        Then the function prints:
        ```
        [5, 6, 7]
        ```
*/
void arr_print_d(int len, const int arr[]);


#endif