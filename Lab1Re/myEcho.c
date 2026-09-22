/* `mycho.c`
    A program that prints in upper case what it receives from the standard input stream. The program ends once the end of transmission marker is sent via [Ctrl]+[D]

    Ardy
*/

#include <stdio.h> //For `EOF`, `getchar` and more.
#include <ctype.h> //For `toupper` and more.

int main(void)
{   
    int character = 'z'; 
    
    while ( (character = getchar()) != EOF)
    {
        putchar(toupper(character));
    }

    return 0;
}
