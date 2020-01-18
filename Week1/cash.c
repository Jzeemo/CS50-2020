#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Count the change
int MoneyCount(int i){
    
    int count =0;    
    
    int centlist[] = {25,10,5,1};
    
    for(int r=0;r<4;r++){
        while(i>=centlist[r]){
            i=i-centlist[r];
            count ++;
        }        
    }  
    
    return count;
}

//Check the change amount and print result
void CheckMoney(float changeamt){
    int count=0;  
    
    int cents = round(changeamt * 100);
    
    count = MoneyCount(cents); 
    
    printf("%i \n",count);
}

//Ask user to enter the valid change
void AskChange(void){
    float changeamt = get_float("Change owed:");     
    
    if(changeamt>0){
        CheckMoney(changeamt);
    }else{
        AskChange();
    } 
}

int main(void)
{    
    AskChange();
}
