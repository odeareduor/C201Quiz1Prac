/* `myProg.c`
    A simple program the prompts the user for integers, performs some vector operations on those numbers, and prints some results.
    The details of this program are immaterial. The program is used to proctice automated build using Make, as well as autmated testing.

    Author: Ardy
    Date: Aug 24, 2026.
*/

#include <stdio.h> //For `printf`.
#include "intArrUserIO.h" //For `arr_fill_d` and `arr_print_d`.
#include "intArrVectOps.h" //For `arr_vect_dot_prod_d` `ARR_ERROR_OUTPUT` and more.


//The following should be at least 3.
#define N 4

int main(void)
{
    int v[N] = {0};
    int w[N] = {0};
    long long temp = 0;

    printf("\n*********************** The Great Oracle program ***********************\n");

    //Prompt the user and get their `N` numbers:
    arr_fill_d(N, v);

    printf("\nYour entered numbers were:\n");
    arr_print_d(N, v);

    //Use `v` to create another vector `w`:
    arr_elemwise_inc_d(N, w, v[0]);
    w[1] = w[1] - 10;
    
    temp = arr_vect_dot_prod_d(N, v, w);
    if (temp != ARR_ERROR_OUTPUT)
    {
        w[2] = (int) temp;
    }

    printf("\nThe numbers that predict the future are:\n");
    arr_print_d(3, w);

    printf("\n********************* The Great Oracle has spoken **********************\n");


    return 0;
}