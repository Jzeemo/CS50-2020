#include <cs50.h>
#include <stdio.h>

//Do Pyramid
void pyramid(int bricks)
{
    for(int i=1;i<=bricks;i++)
    {
        for(int s=1;s<=bricks-i;s++)
        {
            printf(" ");
        }
        for(int s=1;s<=i;s++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//Ask For height
void ask_height()
{
    int size=get_int("Height:");
    if(size>=1 && size<=8){
        pyramid(size);
    }
    else{
        ask_height();
    }
}


int main(void)
{
  ask_height();  
}