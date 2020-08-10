#include <stdio.h>
#include <cs50.h>

int main()
{
    long long userinput = get_long_long("Number: ");
    int counter1 = 0, counter2 = 0, cardlength = 0, oddtotaldouble = 0, eventotal = 0;

    while (userinput > 0)
    {

        counter2 = counter1;
        counter1 = userinput % 10;

        if (cardlength % 2 == 0)
        {
            eventotal += counter1;
        }
        else
        {
            int multiple = 2 * counter1;
            oddtotaldouble += (multiple / 10) + (multiple % 10);
        }
        userinput /= 10;
        cardlength++;
    }

    bool validitycheck = (eventotal + oddtotaldouble) % 10 == 0;
    int firsttwo = (counter1 * 10) + counter2;

    if (counter1 == 4 && cardlength >= 13 && cardlength <= 16 && validitycheck)
    {
        printf("VISA\n");
    }
    else if (firsttwo >= 51 && firsttwo <= 55 && cardlength == 16 && validitycheck)
    {
        printf("MASTERCARD\n");
    }
    else if ((firsttwo == 34 || firsttwo == 37) && cardlength == 15 && validitycheck)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}