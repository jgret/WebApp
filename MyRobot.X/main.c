/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1509
        Driver Version    :  2.00
 
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
/*
                         Main application
 */

char zeichen;
char first = 1;

void IOC0_ISR(void)
{
    INTCONbits.IOCIE = 0; //IOC erstmal ausschalten
    zeichen = 0;
    __delay_us(30);

    //RX Leitung auswerten
    for(char cnt = 0; cnt < 8; cnt++){
        __delay_us(104);
        zeichen = zeichen | (inTx_GetValue() << cnt);

    }
    first = 1;
    INTCONbits.IOCIE = 1; //IOC wieder einschalten
    
}

void blink(void) {
    doLED_SetLow();
   __delay_ms(100);
   doLED_SetHigh();
   __delay_ms(100);
}

void click(void) {
    doSpeaker1_SetHigh();
    doSpeaker2_SetLow();
    __delay_us(250);
    doSpeaker1_SetLow();
    doSpeaker2_SetHigh();
    __delay_us(250);
}

void motor_off() {
    PWM3_LoadDutyValue(0); // linker motor an
    PWM4_LoadDutyValue(0);
    doMotorLR_SetLow();
    doMotorRR_SetLow();
    __delay_ms(10);
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //IOCAF0_SetInterruptHandler(isr_tx);
    
    IOCAF0_SetInterruptHandler(IOC0_ISR);
    

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    
    char con = 0;
    doLED_SetHigh();
    
    while (1)
    {
        
        /*
         * PWM3 -> links
         * PWM4 -> rechts
         * 
         * sens == 0V -> rechts beleuchtet
         * sens == 5V -> links beleuchtet
         *
         */
        
        if (btn1_GetValue()) {
            con = 0;
            
            click();
            blink();
            click();
            blink();
       }
        
        if (btn2_GetValue()) {
            con = 1;
            
            click();
            blink();
            click();
            blink();
            click();
            blink();
        }
        
        if (con) {
            switch (zeichen) {
                case ('e'): {
                    doLED_SetLow();
                    break;
                }
                case ('a'): {
                    doLED_SetHigh();
                    break;
                }
                case ('p'): {
                    doSpeaker1_SetHigh();
                    doSpeaker2_SetLow();
                    __delay_us(250);
                    doSpeaker1_SetLow();
                    doSpeaker2_SetHigh();
                    __delay_us(250);
                    break;
                }
                case ('I'): {
                    PWM3_LoadDutyValue(0); // linker motor an
                    PWM4_LoadDutyValue(0);
                    doMotorLR_SetLow();
                    doMotorRR_SetLow();
                    break;
                }
                case('F'): {
                    if (first) {
                        motor_off();
                        first = 0;
                    }
                    PWM3_LoadDutyValue(1023); // linker motor an
                    PWM4_LoadDutyValue(1023);
                    doMotorLR_SetLow();
                    doMotorRR_SetLow();
                    break;
                }
                case('B'): {
                    if (first) {
                        motor_off();
                        first = 0;
                    }
                    PWM3_LoadDutyValue(0); // linker motor an
                    PWM4_LoadDutyValue(0);
                    doMotorLR_SetHigh();
                    doMotorRR_SetHigh();
                    break;
                }
                case('L'): {
                    if (first) {
                        motor_off();
                        first = 0;
                    }
                    PWM3_LoadDutyValue(0);
                    PWM4_LoadDutyValue(1023);
                    doMotorLR_SetHigh();
                    doMotorRR_SetLow();
                    break;
                }
                case('l'): {
                    if (first) {
                        motor_off();
                        first = 0;
                    }
                    PWM3_LoadDutyValue(0);
                    PWM4_LoadDutyValue(1023);
                    doMotorLR_SetLow();
                    doMotorRR_SetLow();
                    break;
                }
                case('R'): {
                    if (first) {
                        motor_off();
                        first = 0;
                    }
                    PWM3_LoadDutyValue(1023);
                    PWM4_LoadDutyValue(0);
                    doMotorLR_SetLow();
                    doMotorRR_SetHigh();
                    break;
                }
                case('r'): {
                    if (first) {
                        motor_off();
                        first = 0;
                    }
                    PWM3_LoadDutyValue(3);
                    PWM4_LoadDutyValue(0);
                    doMotorLR_SetLow();
                    doMotorRR_SetLow();
                    break;
                }
            }
        } else {
            PWM3_LoadDutyValue(1023);
            PWM3_LoadDutyValue(1023);
            doMotorLR_SetLow();
            doMotorRR_SetLow();
            
            adc_result_t sens = ADC_GetConversion(aiSensorRL);
            if (sens < 400) { // licht rechts
                PWM3_LoadDutyValue(1023); // linker motor an
                PWM4_LoadDutyValue(0);

                if (sens < 200) {
                    doMotorRR_SetHigh();
                    doMotorLR_SetLow();
                }
            }

            if (sens > 600) {   // licht links
                PWM3_LoadDutyValue(0);  
                PWM4_LoadDutyValue(1023); // rechter motor an

                if (sens > 800) {
                    doMotorRR_SetLow();
                    doMotorLR_SetHigh();
                }
            }       
        }
    }
}
/**
 End of File
*/