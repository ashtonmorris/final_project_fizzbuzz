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
        printf("Must have 2 arguments.  Try again. \n");
        return 1;
    }
    
    //ensure that input consists solely of alphabetic characters
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if  (isalpha (argv[1][i]))
            {
                printf("Text to encrypt: \n");
            }
            else
            {
                printf("Alphabetic characters only.  Try again. \n");
                return 1;
            }
        }
    }
        
    
    
    //once correct, put key into k and get length
   string k = argv[1];
   int klength = strlen(k);
   
   //get text to encipher
    string p = get_string();
    
    //convert text to cipher
        printf("ciphertext: ");
        for (int i = 0, f = 0, n = strlen(p); i < n; i++)
        {
            //get new key for the letter
            int newkey = tolower(k[f % klength]) - 'a';
            
            //check case of letter and retain
            if (islower(p[i]))
            {
                printf("%c", 'a' + (p[i] - 'a' + newkey) % 26);
                f++;
            }
            else if (isupper(p[i]))
            {
                printf("%c", 'A' + (p[i] - 'A' + newkey) % 26);
                f++;
            }
            else
                printf("%c", p[i]);
        }

    //After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
    printf("\n");
    return 0;
}
