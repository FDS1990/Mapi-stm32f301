//
// Created by frank on 01/08/17.
//

#include<stm32f30x.h>

#include<stdio.h>


/*
 *
 * in questo programma si ha la gestione del timer tramite interrupt
 * dopo aver effettuato il conteggio 4 volte il microcontrollore
 * disabilita il timer
 *
 *
 *
 */



int time_stop=0;
int flag=0;

int main()
{

    RCC->AHBENR=RCC_AHBENR_GPIOEEN;
    RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;


    GPIOE->MODER=0x55550000;

    TIM2->DIER+=1;
    NVIC->ISER[0]=(1<<28);

    TIM2->ARR=36000000;
    TIM2->CNT=0;

    TIM2->CR1+=1;

    while(1);

}

void TIM2_IRQHandler()
{

    TIM2->SR&=~1;

    if(flag == 0)
    {

        GPIOE->ODR|=(1<<9);

        if(time_stop>4)
        {

            TIM2->CR1&=~1;
            GPIOE->ODR=0;

            GPIOE->ODR|=(1<<11);
            GPIOE->ODR|=(1<<15);

            printf("ZA WARUDO!! \n");

        }

        time_stop++;
        flag=1;

    }
    else
    {

        GPIOE->ODR=0;
        flag=0;

    }

}