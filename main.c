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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F1507
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

typedef enum states
{
    STATE_NORMAL,
    STATE_TEACH_LEFT,
    STATE_TEACH_RIGHT
}state_t;

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    static state_t mainState = STATE_NORMAL;

    while (1)
    {
        static adc_channel_t channel = channelBrightness;
        
                
        //Select next adc channel
        if(channel == channelBrightness)
        {
            channel = channelRudder;
        }
        else
        {
            channel = channelBrightness;
        }
        
        
        //Get next adc value
        ADC_SelectChannel(channel);
        ADC_StartConversion();
        while(!ADC_IsConversionDone());
        uint16_t adcValue = ADC_GetConversionResult();
        
        switch(mainState)
        {
            STATE_NORMAL:
                //Brightness control
                if(channel == channelBrightness)
                {
                    PWM3_LoadDutyValue(adcValue);
                }
                else //Rudder position
                {
                    //Select next ADC
                    channel = channelBrightness;
                }
                break;
            
            STATE_TEACH_LEFT:
                //On
                outputLed1_SetHigh();
                outputLed2_SetHigh();
                outputLed3_SetHigh();
                outputLed4_SetHigh();
                outputLed5_SetHigh();

                //Off
                outputLed6_SetLow();
                outputLed7_SetLow();
                outputLed8_SetLow();
                outputLed9_SetLow();
                outputLed10_SetLow();
                outputLed11_SetLow();
                break;
            
            STATE_TEACH_RIGHT:
                //Off
                outputLed1_SetLow();
                outputLed2_SetLow();
                outputLed3_SetLow();
                outputLed4_SetLow();
                outputLed5_SetLow();
                outputLed6_SetLow();
                
                //On
                outputLed7_SetHigh();
                outputLed8_SetHigh();
                outputLed9_SetHigh();
                outputLed10_SetHigh();
                outputLed11_SetHigh();
                break;    
        }
        

        
        

    }
}
/**
 End of File
*/