#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int word = 0;
int sentence = 0;
int letter = 0;

//Check For Input String
void checkstring(string inputstring)
{
    word = 0;
    sentence = 0;
    letter = 0;

    int tempwordcount = 0;

    for (int i = 0; i < strlen(inputstring); i++)
    {

        tempwordcount++;

        if (inputstring[i] == ' ')
        {

            tempwordcount = 0;
            word++;
        }
        else if (inputstring[i] == '.' || inputstring[i] == '!' || inputstring[i] == '?')
        {

            sentence++;
        }
        else if ((inputstring[i] >= 'a' && inputstring[i] <= 'z') || (inputstring[i] >= 'A' && inputstring[i] <= 'Z'))
        {
            letter++;
        }
    }

    if (tempwordcount > 0)
    {
        word++;
    }
}

int main()
{

    string inputchar = get_string("Text : ");

    checkstring(inputchar);

    float L = ((float)letter / (float)word) * 100;
    float S = ((float)sentence / (float)word) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = roundf(index);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return 0;
}
