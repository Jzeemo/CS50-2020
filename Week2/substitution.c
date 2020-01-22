#include <stdio.h>
#include <cs50.h>
#include <string.h>

char InputArray[26] = {};

//Check whethere input string is valid number or not,if valid,return true otherwise return false
bool isValidString(string inputstring)
{
    for (int i = 0; i < strlen(inputstring); i++)
        if (!((inputstring[i] >= 'a' && inputstring[i] <= 'z') || (inputstring[i] >= 'A' && inputstring[i] <= 'Z')))
            return false;

    return true;
}

//Get the index of input char from Input Char Array
int getIndexof(char inputchar)
{
    for (int i = 0; i <= strlen(InputArray); i++)
    {
        if (inputchar == InputArray[i])
        {
            return i;
        }
    }

    return -1;
}

//Make Cipher Text
void Makecipher(string inputstring)
{

    printf("ciphertext:");

    for (int i = 0; i < strlen(inputstring); i++)
    {

        if (inputstring[i] >= 'a' && inputstring[i] <= 'z')
        {
            //coming h
            //get index of h
            //change to upper case and minus 65 to get index of h
            //get value from inputstring according index
            //change to lower case
            char tempchar = ((int)inputstring[i]) - 32;

            tempchar = InputArray[((int)tempchar) - 65];

            tempchar = (char)(((int)tempchar) + 32);

            printf("%c", tempchar);
        }
        else if (inputstring[i] >= 'A' && inputstring[i] <= 'Z')
        {
            char tempchar = InputArray[((int)inputstring[i]) - 65];

            printf("%c", tempchar);
        }
        else
        {
            printf("%c", (char)inputstring[i]);
        }
    }

    printf("\n");
}

int main(int argc, string argv[])
{

    if (argc <= 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!isValidString(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {

        char c[1] = "";

        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            //Convert to Upper Letter;
            c[0] = (char)(((int)argv[1][i]) - 32);
        }
        else
        {
            c[0] = argv[1][i];
        }

        if (getIndexof(c[0]) > 0)
        {
            printf("Usage: ./substitution duplicate key\n");
            return 1;
        }

        InputArray[i] = c[0];
    }

    Makecipher(get_string("plaintext:"));
}
