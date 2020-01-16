#include <cs50.h>
#include <stdio.h>

//Print #
void printblock(int bricks)
{
    for(int s=1;s<=bricks;s++)
        {
            printf("#");
        }
}

//Print Space
void printspace(int count){
    for(int i=0;i<count;i++)
    {
        printf(" "); 
    }             
}

//Print Bricks
void pyramid(int bricks)
{
    for(int i=1;i<=bricks;i++)
    {
        for(int s=1;s<=bricks-i;s++)
        {
            printspace(1);
        }
        printblock(i);
        
        printspace(2);
        
        printblock(i);
            
        printf("\n");
    }
}

//Ask height to user
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
