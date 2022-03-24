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


void IOC0_ISR(void)
{
    INTCONbits.IOCIE = 0; //IOC erstmal ausschalten
    doLED_Toggle();
    INTCONbits.IOCIE = 1; //IOC erstmal ausschalten
    
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
    
    uint16_t t_period = 0;
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
        
        PWM3_LoadDutyValue(1023);
        PWM3_LoadDutyValue(1023);
        doMotorLR_SetLow();
        doMotorRR_SetLow();
        
        /*
        if (btn1_GetValue()) {
            doLED_SetLow();
        } else {
            doLED_SetHigh();
        }
        */
        
        if (btn2_GetValue()) {
            doSpeaker1_SetHigh();
            doSpeaker2_SetLow();
            for (uint16_t i = 0; i < t_period; i++) {
                __delay_us(1);
            }
            doSpeaker1_SetLow();
            doSpeaker2_SetHigh();
            for (uint16_t i = 0; i < t_period; i++) {
                __delay_us(1);
            }
        }
        
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
/**
 End of File
*/