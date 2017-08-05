#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[1])
{
    //check for 2 arguments only and return from main a value of 1 if error
    if (argc != 2)
    {
        printf("Invalid input.  Try again. \n");
        return 1;
    }
    
    else 
    {
        printf("Text to encrypt: \n");
    }
    
    //once correct, put key into k
    int k = atoi(argv[1]);
    
    string p = get_string();
    
    //convert text to cipher
        printf("ciphertext: ");
        for (int i = 0, n = strlen(p); i < n; i++)
        {
           
            //check case of letter and then convert
            if (islower(p[i]))
                printf("%c", (((p[i] + k) - 97) % 26) + 97);
            else if (isupper(p[i]))
                printf("%c", (((p[i] + k) - 65) % 26) + 65);
            else
                printf("%c", p[i]);
        }

    //After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
    printf("\n");
    return 0;
}