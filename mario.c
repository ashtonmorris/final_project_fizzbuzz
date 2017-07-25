
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: now ");
        height = get_int();
    }
    while ((height < 0) || (height > 23));
    
        for (int rows = 1; rows <= height; rows++) 
            {
            for (int spaces = (height - rows); spaces > 0; spaces--)
                {
                printf(" "); 
                }

            for (int hashes = 1; hashes <= (rows + 1); hashes++)
                {   
                printf("#"); 
                }
            printf("\n");
            }
    return 0;
}  

   
      