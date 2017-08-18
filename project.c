#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //initialize variable
    int n;
    //get input from user
    printf("Please provide an integer to play FizzBuzz: ");
    n = get_int();

    //iterate until integer provided by user is reached
    for (int i = 1; i <= n; i++)
    {
        //for numbers divisible by both 3 and 5, print 'FizzBuzz,' until last number is reached and then print newline
        if ((i % 15 == 0) && (i < n))
            printf("FizzBuzz, ");
        else if ((i % 15 == 0) && (i == n))
            printf("FizzBuzz\n");
        //for numbers divisible by 3, print 'Fizz,' until last number is reached and then print newline
        else if ((i % 3 == 0) && (i < n))
            printf("Fizz, ");
        else if ((i % 3 == 0) && (i == n))
            printf("Fizz\n");
        //for numbers divisible by 5, print 'Buzz,' until last number is reached and then print newline
        else if ((i % 5 == 0) && (i < n))
            printf("Buzz, ");
        else if ((i % 5 == 0) && (i == n))
            printf("Buzz\n");
        //for numbers divisible by neither 3 nor 5, print only the number followed by a comma until last number is reached and then print newline
        else if (i < n)
            printf("%d, ", i);
        else
            printf("%d\n", i);
    }
}