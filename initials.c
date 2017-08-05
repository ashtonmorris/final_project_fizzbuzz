#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
//ask user for input

printf("What's your name?\n");
  string s = get_string();

//make sure get_string returned a string
  if (s != NULL)
  {

    //print the first initial capitalized
    printf("%c", toupper(s[0]));
    
    //find spaces if any
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            // print next character capitalized
            printf("%c", toupper(s[i + 1]));
        }
    }
  }
    
    //print new line
    printf("\n");
}