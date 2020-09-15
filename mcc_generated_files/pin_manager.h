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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.5
        Device            :  PIC16F1507
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set channelRudder aliases
#define channelRudder_TRIS                 TRISAbits.TRISA4
#define channelRudder_LAT                  LATAbits.LATA4
#define channelRudder_PORT                 PORTAbits.RA4
#define channelRudder_WPU                  WPUAbits.WPUA4
#define channelRudder_ANS                  ANSELAbits.ANSA4
#define channelRudder_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define channelRudder_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define channelRudder_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define channelRudder_GetValue()           PORTAbits.RA4
#define channelRudder_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define channelRudder_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define channelRudder_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define channelRudder_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define channelRudder_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define channelRudder_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set inputTeachIn aliases
#define inputTeachIn_TRIS                 TRISAbits.TRISA5
#define inputTeachIn_LAT                  LATAbits.LATA5
#define inputTeachIn_PORT                 PORTAbits.RA5
#define inputTeachIn_WPU                  WPUAbits.WPUA5
#define inputTeachIn_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define inputTeachIn_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define inputTeachIn_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define inputTeachIn_GetValue()           PORTAbits.RA5
#define inputTeachIn_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define inputTeachIn_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define inputTeachIn_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define inputTeachIn_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)

// get/set channelBrightness aliases
#define channelBrightness_TRIS                 TRISBbits.TRISB4
#define channelBrightness_LAT                  LATBbits.LATB4
#define channelBrightness_PORT                 PORTBbits.RB4
#define channelBrightness_WPU                  WPUBbits.WPUB4
#define channelBrightness_ANS                  ANSELBbits.ANSB4
#define channelBrightness_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define channelBrightness_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define channelBrightness_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define channelBrightness_GetValue()           PORTBbits.RB4
#define channelBrightness_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define channelBrightness_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define channelBrightness_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define channelBrightness_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define channelBrightness_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define channelBrightness_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set outputLed9 aliases
#define outputLed9_TRIS                 TRISBbits.TRISB5
#define outputLed9_LAT                  LATBbits.LATB5
#define outputLed9_PORT                 PORTBbits.RB5
#define outputLed9_WPU                  WPUBbits.WPUB5
#define outputLed9_ANS                  ANSELBbits.ANSB5
#define outputLed9_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define outputLed9_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define outputLed9_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define outputLed9_GetValue()           PORTBbits.RB5
#define outputLed9_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define outputLed9_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define outputLed9_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define outputLed9_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define outputLed9_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define outputLed9_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set outputLed10 aliases
#define outputLed10_TRIS                 TRISBbits.TRISB6
#define outputLed10_LAT                  LATBbits.LATB6
#define outputLed10_PORT                 PORTBbits.RB6
#define outputLed10_WPU                  WPUBbits.WPUB6
#define outputLed10_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define outputLed10_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define outputLed10_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define outputLed10_GetValue()           PORTBbits.RB6
#define outputLed10_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define outputLed10_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define outputLed10_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define outputLed10_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set outputLed11 aliases
#define outputLed11_TRIS                 TRISBbits.TRISB7
#define outputLed11_LAT                  LATBbits.LATB7
#define outputLed11_PORT                 PORTBbits.RB7
#define outputLed11_WPU                  WPUBbits.WPUB7
#define outputLed11_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define outputLed11_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define outputLed11_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define outputLed11_GetValue()           PORTBbits.RB7
#define outputLed11_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define outputLed11_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define outputLed11_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define outputLed11_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set outputLed1 aliases
#define outputLed1_TRIS                 TRISCbits.TRISC0
#define outputLed1_LAT                  LATCbits.LATC0
#define outputLed1_PORT                 PORTCbits.RC0
#define outputLed1_ANS                  ANSELCbits.ANSC0
#define outputLed1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define outputLed1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define outputLed1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define outputLed1_GetValue()           PORTCbits.RC0
#define outputLed1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define outputLed1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define outputLed1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define outputLed1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set outputLed2 aliases
#define outputLed2_TRIS                 TRISCbits.TRISC1
#define outputLed2_LAT                  LATCbits.LATC1
#define outputLed2_PORT                 PORTCbits.RC1
#define outputLed2_ANS                  ANSELCbits.ANSC1
#define outputLed2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define outputLed2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define outputLed2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define outputLed2_GetValue()           PORTCbits.RC1
#define outputLed2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define outputLed2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define outputLed2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define outputLed2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set outputLed3 aliases
#define outputLed3_TRIS                 TRISCbits.TRISC2
#define outputLed3_LAT                  LATCbits.LATC2
#define outputLed3_PORT                 PORTCbits.RC2
#define outputLed3_ANS                  ANSELCbits.ANSC2
#define outputLed3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define outputLed3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define outputLed3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define outputLed3_GetValue()           PORTCbits.RC2
#define outputLed3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define outputLed3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define outputLed3_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define outputLed3_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set outputLed4 aliases
#define outputLed4_TRIS                 TRISCbits.TRISC3
#define outputLed4_LAT                  LATCbits.LATC3
#define outputLed4_PORT                 PORTCbits.RC3
#define outputLed4_ANS                  ANSELCbits.ANSC3
#define outputLed4_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define outputLed4_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define outputLed4_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define outputLed4_GetValue()           PORTCbits.RC3
#define outputLed4_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define outputLed4_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define outputLed4_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define outputLed4_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set outputLed5 aliases
#define outputLed5_TRIS                 TRISCbits.TRISC4
#define outputLed5_LAT                  LATCbits.LATC4
#define outputLed5_PORT                 PORTCbits.RC4
#define outputLed5_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define outputLed5_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define outputLed5_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define outputLed5_GetValue()           PORTCbits.RC4
#define outputLed5_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define outputLed5_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set outputLed6 aliases
#define outputLed6_TRIS                 TRISCbits.TRISC5
#define outputLed6_LAT                  LATCbits.LATC5
#define outputLed6_PORT                 PORTCbits.RC5
#define outputLed6_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define outputLed6_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define outputLed6_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define outputLed6_GetValue()           PORTCbits.RC5
#define outputLed6_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define outputLed6_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set outputLed7 aliases
#define outputLed7_TRIS                 TRISCbits.TRISC6
#define outputLed7_LAT                  LATCbits.LATC6
#define outputLed7_PORT                 PORTCbits.RC6
#define outputLed7_ANS                  ANSELCbits.ANSC6
#define outputLed7_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define outputLed7_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define outputLed7_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define outputLed7_GetValue()           PORTCbits.RC6
#define outputLed7_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define outputLed7_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define outputLed7_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define outputLed7_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set outputLed8 aliases
#define outputLed8_TRIS                 TRISCbits.TRISC7
#define outputLed8_LAT                  LATCbits.LATC7
#define outputLed8_PORT                 PORTCbits.RC7
#define outputLed8_ANS                  ANSELCbits.ANSC7
#define outputLed8_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define outputLed8_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define outputLed8_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define outputLed8_GetValue()           PORTCbits.RC7
#define outputLed8_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define outputLed8_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define outputLed8_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define outputLed8_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/