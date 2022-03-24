/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1509
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set inTx aliases
#define inTx_TRIS                 TRISAbits.TRISA0
#define inTx_LAT                  LATAbits.LATA0
#define inTx_PORT                 PORTAbits.RA0
#define inTx_WPU                  WPUAbits.WPUA0
#define inTx_ANS                  ANSELAbits.ANSA0
#define inTx_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define inTx_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define inTx_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define inTx_GetValue()           PORTAbits.RA0
#define inTx_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define inTx_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define inTx_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define inTx_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define inTx_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define inTx_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set doMotorLF aliases
#define doMotorLF_TRIS                 TRISAbits.TRISA2
#define doMotorLF_LAT                  LATAbits.LATA2
#define doMotorLF_PORT                 PORTAbits.RA2
#define doMotorLF_WPU                  WPUAbits.WPUA2
#define doMotorLF_ANS                  ANSELAbits.ANSA2
#define doMotorLF_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define doMotorLF_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define doMotorLF_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define doMotorLF_GetValue()           PORTAbits.RA2
#define doMotorLF_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define doMotorLF_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define doMotorLF_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define doMotorLF_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define doMotorLF_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define doMotorLF_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set btn1 aliases
#define btn1_TRIS                 TRISAbits.TRISA4
#define btn1_LAT                  LATAbits.LATA4
#define btn1_PORT                 PORTAbits.RA4
#define btn1_WPU                  WPUAbits.WPUA4
#define btn1_ANS                  ANSELAbits.ANSA4
#define btn1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define btn1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define btn1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define btn1_GetValue()           PORTAbits.RA4
#define btn1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define btn1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define btn1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define btn1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define btn1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define btn1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set btn2 aliases
#define btn2_TRIS                 TRISAbits.TRISA5
#define btn2_LAT                  LATAbits.LATA5
#define btn2_PORT                 PORTAbits.RA5
#define btn2_WPU                  WPUAbits.WPUA5
#define btn2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define btn2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define btn2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define btn2_GetValue()           PORTAbits.RA5
#define btn2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define btn2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define btn2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define btn2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)

// get/set aiSensorRL aliases
#define aiSensorRL_TRIS                 TRISBbits.TRISB5
#define aiSensorRL_LAT                  LATBbits.LATB5
#define aiSensorRL_PORT                 PORTBbits.RB5
#define aiSensorRL_WPU                  WPUBbits.WPUB5
#define aiSensorRL_ANS                  ANSELBbits.ANSB5
#define aiSensorRL_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define aiSensorRL_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define aiSensorRL_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define aiSensorRL_GetValue()           PORTBbits.RB5
#define aiSensorRL_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define aiSensorRL_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define aiSensorRL_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define aiSensorRL_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define aiSensorRL_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define aiSensorRL_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set doMotorLR aliases
#define doMotorLR_TRIS                 TRISCbits.TRISC0
#define doMotorLR_LAT                  LATCbits.LATC0
#define doMotorLR_PORT                 PORTCbits.RC0
#define doMotorLR_ANS                  ANSELCbits.ANSC0
#define doMotorLR_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define doMotorLR_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define doMotorLR_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define doMotorLR_GetValue()           PORTCbits.RC0
#define doMotorLR_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define doMotorLR_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define doMotorLR_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define doMotorLR_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set doMotorRF aliases
#define doMotorRF_TRIS                 TRISCbits.TRISC1
#define doMotorRF_LAT                  LATCbits.LATC1
#define doMotorRF_PORT                 PORTCbits.RC1
#define doMotorRF_ANS                  ANSELCbits.ANSC1
#define doMotorRF_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define doMotorRF_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define doMotorRF_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define doMotorRF_GetValue()           PORTCbits.RC1
#define doMotorRF_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define doMotorRF_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define doMotorRF_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define doMotorRF_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set doMotorRR aliases
#define doMotorRR_TRIS                 TRISCbits.TRISC2
#define doMotorRR_LAT                  LATCbits.LATC2
#define doMotorRR_PORT                 PORTCbits.RC2
#define doMotorRR_ANS                  ANSELCbits.ANSC2
#define doMotorRR_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define doMotorRR_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define doMotorRR_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define doMotorRR_GetValue()           PORTCbits.RC2
#define doMotorRR_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define doMotorRR_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define doMotorRR_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define doMotorRR_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set doSpeaker1 aliases
#define doSpeaker1_TRIS                 TRISCbits.TRISC4
#define doSpeaker1_LAT                  LATCbits.LATC4
#define doSpeaker1_PORT                 PORTCbits.RC4
#define doSpeaker1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define doSpeaker1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define doSpeaker1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define doSpeaker1_GetValue()           PORTCbits.RC4
#define doSpeaker1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define doSpeaker1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set doLED aliases
#define doLED_TRIS                 TRISCbits.TRISC5
#define doLED_LAT                  LATCbits.LATC5
#define doLED_PORT                 PORTCbits.RC5
#define doLED_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define doLED_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define doLED_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define doLED_GetValue()           PORTCbits.RC5
#define doLED_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define doLED_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set doSpeaker2 aliases
#define doSpeaker2_TRIS                 TRISCbits.TRISC7
#define doSpeaker2_LAT                  LATCbits.LATC7
#define doSpeaker2_PORT                 PORTCbits.RC7
#define doSpeaker2_ANS                  ANSELCbits.ANSC7
#define doSpeaker2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define doSpeaker2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define doSpeaker2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define doSpeaker2_GetValue()           PORTCbits.RC7
#define doSpeaker2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define doSpeaker2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define doSpeaker2_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define doSpeaker2_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF0 pin functionality
 * @Example
    IOCAF0_ISR();
 */
void IOCAF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_InterruptHandler);

*/
extern void (*IOCAF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_DefaultInterruptHandler);

*/
void IOCAF0_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/