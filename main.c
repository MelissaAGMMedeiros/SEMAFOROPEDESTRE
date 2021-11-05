/*
 * File:   main.c
 * Author: 21193460
 *
 * Created on 4 de Novembro de 2021, 11:07
 */

#include "config.h"
#include <xc.h>

#define _XTAL_FREQ 4000000

#define LED_VM     PORTDbits.RD5
#define LED_AM     PORTDbits.RD6
#define LED_VD     PORTDbits.RD7
#define LED_VM_PD  PORTDbits.RD2
#define LED_VD_PD  PORTDbits.RD3
#define BT         PORTDbits.RD0
#define ATRASO(n)  __delay_ms(n)
void main(void) 
{      // Configuração dos pinos
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD0 = 1;
    
        // Inicialização do estado dos LEDs
    LED_VM = 0;
    LED_AM = 0;
    LED_VD = 0;
    LED_VM_PD = 0;
    LED_VD_PD = 0;

    while( 1 )
    {
        LED_VD = 1;
        LED_VM_PD = 1;
        
        if( BT == 1 )
        {
            ATRASO(5000);
            LED_VD = 0;
            LED_AM  = 1;
            ATRASO(3000);
            LED_AM  = 0;
            LED_VM  = 1;
            LED_VM_PD = 0;
            LED_VD_PD = 1;
            ATRASO(10000);
            LED_VM_PD = 0;
            LED_VD_PD = 1;
            LED_VM  = 0;
            LED_VD = 1;
        }
    }
}
