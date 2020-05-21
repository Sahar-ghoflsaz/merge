#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool searchA(int* outarray, int n, int number)
{
    for (int i = 0; i < n; i++) 
        if (outarray[i] == number) 
            return false;
    
    return true;
}

/*
bool validate(string line)
{
    string number = "";
    for (unsigned int i = 0; i < line.length(); i++)
        if (line[i] == 32) //represents ascii code of space
            return false;
}
*/




// Checking whether user's input is an integer or not
unsigned int readInt(bool is_negative)
{
    char num[12];
    unsigned long long temp = 0; // used to test if abstract of the value is less than or equal with 2,147,483,648


    while (true)
    {
    start:
        temp = 0;

        fgets(num, 12, stdin);
        //check if the input is a number without other characters

        unsigned int i;
        if (!is_negative)
            i = 0;
        else
            i = 1;
        for (i; i < _mbstrlen(num) - 1; i++)
        {
            if (num[i] < 48 || num[i] > 57)
            {
                printf("!!!Please enter a valid number. Please try again\n");
                goto start;
            }
        }


        //check for negative value
        if (!is_negative && num[0] == '-')
        {
            printf("!!!Please enter a positive number. Please try again!\n");
            continue;
        }

        //check if abstract of the value is less than 2,147,483,648
        int power = 0, threshold;

        if (num[0] == '-')
        {
            for (int i = _mbstrlen(num) - 2; i > 0; i--)
            {
                int digit = num[i] - '0';
                if (digit == 0 && i > 1)
                {
                    power++;
                    digit = num[i - 1] - '0';
                    temp = temp + digit * (unsigned long)pow(10, power++);
                    i = i - 2;
                }
                else
                    temp = temp + digit * (unsigned long)pow(10, power++);
            }
        }
        else
        {
            for (int i = _mbstrlen(num) - 2; i > -1; i--)
            {
                int digit = num[i] - '0';
                if (digit == 0 && i > 0)
                {
                    power++;
                    digit = num[i - 1] - '0';
                    temp = temp + digit * (unsigned long)pow(10, power++);
                    i = i - 1;
                }
                else
                    temp = temp + digit * (unsigned long)pow(10, power++);
            }
        }

        
        if (temp > 2147483648)
        {
            printf("!!!Please enter a positive number less than 2147483648. Please try again\n");
            continue;
        }

        //finally, the number is good to be returned
        break;
    }
    
    if (num[0] == '-')
        temp *= -1;

    return (int)temp;
}




int main() {


    printf("Please enter only positive numbers\nPlease note that your number should be up to 10 digits and less than or equal with 2147483648\n");

    printf("Enter size of the first array: \n");
    int n = readInt(false); //size of the first array
    
    int* FirstArray = (int*)malloc(sizeof(int) * n);
    printf("\n\nEnter the first array's elemenct one by one: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d of the first array: ", (i + 1));
        FirstArray[i] = readInt(true);
    }
        
    printf("\n=====================================================\n\n");
    printf("Enter size of the second array: \n");
    int m = readInt(false); //size of the second array
    int* SecondArray = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++)
    {
        printf("Enter element %d of the second array: ", (i + 1));
        SecondArray[i] = readInt(true);
    }
    
    int* OutputArray = (int*)malloc(sizeof(int) * (m + n));

    int counter = 0;

    for (int i = 0; i < n; i++) 
    {
        if (searchA(OutputArray, counter, FirstArray[i]))
        {
            OutputArray[counter] = FirstArray[i];
            counter++;
        }
    }

    for (int i = 0; i < m; i++) {
        if (searchA(OutputArray, counter, SecondArray[i]))
        {
            OutputArray[counter] = SecondArray[i];
            counter++;
        }
    }

    printf("\n\nHere is the result:\n");
    for (int i = 0; i < counter; i++) 
        printf("%d  ", OutputArray[i]);

    printf("\n\n=========================================================================\n\n");

    
    return 0;
    
}
