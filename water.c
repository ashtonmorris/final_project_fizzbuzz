#include <stdio.h>
#include <cs50.h>

int main(void)
{

    printf("Minutes: ");
     int minutes = get_int();
    
   if (minutes < 0)
   {
       printf("How did you take a shower for less than 0 minutes? Are you tricking me?\n");
   }
   else if (minutes == 0)
   {
       printf("Come on, did you really take a shower?\n");
   }
   else
   {
    printf("Bottles: %i\n", minutes * 12);
   }

}



  