#include <cs50.h>
#include <stdio.h>

const int american_express_card = 1;
const int mastercard_card = 2;
const int visa_card = 3;

int main(void)
{
    long card_number = get_long("Number: ");
    long temp = card_number;
    int count = 0;
    int last_digit_series_sum = 0;
    int second_last_digit_series_sum = 0;

    //determines of which company the card will be
    int card_type = 0;

    //counts number of digits in the card
    while (temp > 0)
    {
        count++;
        temp /= 10;
    }

    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    if (count == 15)
    {
        //10^13
        int first_two_digits = card_number / 10000000000000;
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            card_type = 1;
        }
    }
    else if (count == 13)
    {
        //10^12
        int first_digit = card_number / 1000000000000;
        if (first_digit == 4)
        {
            card_type = 3;
        }
    }
    else
    {
        //10^15
        int first_digit = card_number / 1000000000000000;
        if (first_digit == 4)
        {
            card_type = 3;
        }
        else
        {
            //10^14
            int first_two_digits = card_number / 100000000000000;
            if (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53
                || first_two_digits == 54 || first_two_digits == 55)
            {
                card_type = 2;
            }
        }
    }
    //Don't validate checksum if the card_type is still none
    if (card_type == 0)
    {
        printf("INVALID\n");
        return 0;
    }
    //validates for checksum
    while (card_number > 0)
    {
        //adding which are at odd digits place
        last_digit_series_sum += card_number % 10;

        //removing the processed digit to access the numbers at even position starting from second last digit
        card_number /= 10;

        int remainder = (card_number % 10) * 2;

        if (remainder > 9)
        {
            second_last_digit_series_sum += remainder / 10 + remainder % 10;
        }
        else
        {
            second_last_digit_series_sum += remainder;
        }

        //removing the processed digit at even's position
        card_number /= 10;
    }

    if ((last_digit_series_sum + second_last_digit_series_sum) % 10 == 0)
    {
        if (card_type == american_express_card)
        {
            printf("AMEX\n");
        }
        else if (card_type == mastercard_card)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("VISA\n");
        }
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}