#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Global Move Value
int stepcount = 0;

//Check whethere input string is valid number or not,if valid,return true otherwise return false
bool isNumber(string inputstring)
{
    for (int i = 0; i < strlen(inputstring); i++)
        if (isdigit(inputstring[i]) == false)
            return false;

    return true;
}

//Caluculate Move Charactor
int getNumber(int start, int end, int startinput)
{

    int movecount = stepcount;
    int pointer = startinput;

    while (movecount > 0)
    {

        if (pointer == end)
        {
            pointer = start;
            movecount--;
            continue;
        }
        pointer++;
        movecount--;
    }

    return pointer;
}

//Make Cipher Text
void Makecipher(string inputstring)
{

    printf("ciphertext:");

    for (int i = 0; i < strlen(inputstring); i++)
    {

        if (inputstring[i] >= 'a' && inputstring[i] <= 'z')
        { //97 to 122
            printf("%c", (char)getNumber(97, 122, inputstring[i]));
        }
        else if (inputstring[i] >= 'A' && inputstring[i] <= 'Z')
        { //65 to 90
            printf("%c", (char)getNumber(65, 90, inputstring[i]));
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
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!isNumber(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    sscanf(argv[1], "%d", &stepcount);

    Makecipher(get_string("plaintext:"));
}
