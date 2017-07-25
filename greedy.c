#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    
    //get amount in dollars
    float n; 
    do
    {
        printf("How much change is owed? ");
        n = get_float();
    }
    while(n <= 0);


    //initialize coins
    int coins = 0;
    
    //convert dollars to cents
    int change = round(n * 100);
    
    //until all change has been dispensed
    while (change > 0)
    {
        //while(quarters can be used)
        if (change >= 25)
        {
            change = change - 25;
        }
        //while(dimes can be used)
        else if (change >= 10)
        {
            change = change - 10;
        }
        //while(nickels can be used)
        else if (change >= 5)
        {
            change = change - 5;
        }
        //while(pennies can be used)
        else 
        {
            change = change - 1;
        }
        coins++;
    }
       
//print number of coins used
printf("%i\n", coins);

}