#include<stdio.h>
#include<cs50.h>
#include <string.h>

int * getsplitarray(long value)
{
    static int digit[16];
    long num = value;
    for(int i=0;num!=0;i++)
    {
        int r=num%10;       
        
        digit[i]=r;      
        
        num=num/10;        
    }
    
    return digit;   
   
}


void checkvalue(int digit[])
{
    int muliby2[6];
    
    int start =0;
   for(int i=1;i<=16;i=i+2){
       muliby2[start] =  digit[i] * 2;
       start ++;
   }
}

void mainmethod(long value)
{
    int * mainarray = getsplitarray(value);
    
    
    //start multiply each of the underlined digits by 2
    int start=0;
    int muliby2[8];
    for(int i=1;i<=16;i=i+2){
       muliby2[start] =  mainarray[i] * 2;
       start ++;
    }
    //end multiply each of the underlined digits by 2
    
    
    int totalplus=0;
    for(int i=0;i<8;i++)
    {
        int num = muliby2[i];
        for(int j=0;num!=0;j++)
        {
            int r=num%10;

            totalplus = totalplus + r;      

            num=num/10;
        }    
    }
    
    
    start=0;
    int startarrary[8];
    for(int i=0;i<16;i=i+2){
       totalplus = totalplus + mainarray[i];
    }
    
    
    int result = getsplitarray(totalplus)[0];
    
    char valuestring[50];
    
    sprintf(valuestring, "%ld", value );
    
    if(result != 0)
    {
        printf("INVALID\n");
    }
    else{
        if(strlen(valuestring) == 15 && (strstr(valuestring,"34") || strstr(valuestring,"37")))
        {
             printf("AMEX\n");
        }
        else if(strlen(valuestring) == 16 && (strstr(valuestring,"51") || strstr(valuestring,"52") || strstr(valuestring,"53") || strstr(valuestring,"54") || strstr(valuestring,"55"))){
            printf("MASTERCARD\n");
        }
        else if((strlen(valuestring) == 13 || strlen(valuestring) == 16) && strstr(valuestring,"4"))
        {
            printf("VISA\n");
        }
        else
        {
             printf("INVALID\n");
        }
    }
    
    
    
}

int main(void)
{        
    long num = get_long("Number:");
    mainmethod(num);        
}
