//
// Created by frank on 01/08/17.
//


/*

Spiegazione traccia


 in pratica si preme il pulsante 40 volte alla 40 volta in output sulla terminal window
 viene mostrato a schermo il messaggio die die die

 */


#include<stdio.h>

#include<stm32f30x.h>


int main()
{
    int kill=0;

    RCC->AHBENR|=RCC_AHBENR_GPIOAEN;
    RCC->AHBENR|=RCC_AHBENR_GPIOEEN;

    GPIOA->MODER &= 0xFFFFFFFD;
    GPIOE->MODER |= 0x55550000;

    while(1)
    {

        if( (GPIOA->IDR & 0x00000001) == 1)
        {

            if(kill<=40)
            {

                GPIOE->ODR|=(1<<8);
                GPIOE->ODR|=(1<<9);
                GPIOE->ODR|=(1<<10);

                kill++;

                printf("<%d> \n",kill);

            }
            else
                printf("DIE DIE DIE :> \n");
        }
        else
        {
            if(kill >=40)
            {

                GPIOE->ODR = 0;

                GPIOE->ODR |= (1<<12);
                GPIOE->ODR |= (1<<13);
                GPIOE->ODR |= (1<<14);

            }

        }


    }


}