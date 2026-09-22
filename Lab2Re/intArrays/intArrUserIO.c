/* `intArrUserIO.c`
    Implementations of user input/output functions for `int` arrays.

    See `intArrUserIO.h` for the public interface.  

    Author: Ardy
    Date: Aug 18, 2026
*/

#include <stdio.h> //For `printf`, `scanf`, and more.
#include "intArrUserIO.h" //For consistency.


/* `arr_fill_d`
  Fill the elements of an array of `int`s with user inputs.
  See the associated H file for the documentation.  
*/
void arr_fill_d(int len, int arr[]) //No `const` because we mutate the arr.
{ 
    printf("Please enter %d integers: ", len);
    int i = 0;
    while (i < len && scanf("%d", &arr[i]) == 1) //Precedence of `==` is
                                                  //higher than that of `&&`.
    {
        i++;
    }

    return;
}




/* `arr_print_d`
    Print the elements of an array of `int`s.
    See the associated H file for the documentation.  
*/
void arr_print_d(int len, const int arr[]) //`const` ensures we don't
                                         //accidentally mutate `arr` elements.
{ 
    if (len <= 0)
    { 
        printf("[]");
        return;
    }
    //Else if `len` is legitimate:
    printf("[");
    int i = 0;
    while (i < len-1) //Print all but last elem followed by commas.
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("%d]", arr[i]); //Print the last elem.

    return;
}