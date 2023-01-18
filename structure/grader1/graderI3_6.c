#include<stdio.h>
int main ()
{   
    int rub,pun,haroi,roi,hasib,yeesib,sib,baht;


    scanf("%d",&rub);
    pun = rub / 1000 ;
    haroi = (rub % 1000) / 500;
    roi = ((rub % 1000 ) % 500)/100;
    hasib = (((rub % 1000 ) % 500)%100)/50;
    yeesib = ((((rub % 1000 ) % 500)%100)%50)/20;
    sib = (((((rub % 1000 ) % 500)%100)%50)%20)/10;
    baht = ((((((rub % 1000 ) % 500)%100)%50)%20)%10)/1;

    printf("%d %d %d %d %d %d %d",pun,haroi,roi,hasib,yeesib,sib,baht);



    return 0 ;
}