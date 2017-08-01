//
// Created by frank on 01/08/17.
//

#include<stm32f30x.h>

#include<math.h>
#include<stdio.h>


/*
 *
 * creazione di un contatore numerico tramite microcontrollore
 * ma con l'aggiunta di un valore di soglia
 * superato il valore di soglia (questo caso 3) viene visualizzato
 * un messaggio
 *
 */





#define Tck 125*pow(10,-9);

float tau=0.0;

int main()
{

    int N_cont=0;

    RCC->AHBENR=RCC_AHBENR_GPIOAEN;
    RCC->APB1ENR=RCC_APB1ENR_TIM2EN;

    GPIOA->MODER&=0xFFFFFFFD;


    while(1)
    {

        if( (GPIOA->IDR & 0x00000001) == 1)
        {

            TIM2->CR1+=1;
            TIM2->CNT=0;

            while((GPIOA->IDR & 0x00000001) == 1);

            TIM2->CR1&=~1;
            N_cont=TIM2->CNT;
            tau=(float)N_cont*Tck;

            if(tau>3.0)
                printf(" >:(  non farlo mai piu' \n");


        }



    }

}