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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
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


static volatile bool doButtonAction = false;
static volatile uint16_t msTick = 0;
static volatile uint16_t msPressed = 0;
static bool doToggle;
static state_t currentState = STATE_NORMAL;


static int32_t adcValuePosition = 0;

static uint32_t lowerLimit = 0;
static uint32_t upperLimit = 1023;

//Calibration values
static const int32_t fixedPointFactor = 1000;
static int32_t m = 1 * fixedPointFactor;
static int24_t b = 0;

void timer0CallBack()
{
    
    msTick++;
    
    if(msTick > 200)
    {
        doToggle = true;
        msTick = 0;
    }
}


void setLedsForPositioning(int32_t position);


void setState(state_t newState)
{
    if(newState == currentState)
    {
        return;
    }
    
    
    outputLed1_SetLow();
    outputLed2_SetLow();
    outputLed3_SetLow();                       
    outputLed4_SetLow();
    outputLed5_SetLow(); 
    outputLed6_SetLow();
    outputLed7_SetLow();
    outputLed8_SetLow();
    outputLed9_SetLow();
    outputLed10_SetLow();
    outputLed11_SetLow();
    

    
    switch(newState)
    {
        case STATE_NORMAL:
        {
            //Read calibration values from Flash
            
            
//            //Get factor
//            uint32_t flashEntry;
//            flashEntry =  (uint32_t)FLASH_ReadWord(END_FLASH-7) << 24;
//            flashEntry += (uint32_t)FLASH_ReadWord(END_FLASH-6) << 16;
//            flashEntry += FLASH_ReadWord(END_FLASH-5) << 8;
//            flashEntry += FLASH_ReadWord(END_FLASH-4);
//            
//            factor = (flashEntry != 0xFFFFFFFF) ? flashEntry : factor;
//
//            
//            //Get Offset
//            flashEntry  = FLASH_ReadWord(END_FLASH-3) << 24;
//            flashEntry += FLASH_ReadWord(END_FLASH-2) << 16;
//            flashEntry += FLASH_ReadWord(END_FLASH-1) << 8;
//            flashEntry += FLASH_ReadWord(END_FLASH);
//
//            offset = (flashEntry != 0xFFFFFFFF) ? flashEntry : 0;
            
            break;
        }
           
        case STATE_TEACH_LEFT:
            outputLed1_SetHigh();
            break;
            
        case STATE_TEACH_RIGHT: 
            outputLed11_SetHigh();
            break;
    }
    
    msTick = 0;
            
    currentState = newState;
}


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
 //   INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    setState(STATE_NORMAL);
    
    
    TMR0_SetInterruptHandler(timer0CallBack);
    TMR2_StartTimer();

    while(1)
    {
        static adc_channel_t channel = channelBrightness;
                
        //Select next adc channel
        channel = (channel == channelRudder) ? channelBrightness : channelRudder;
        
        
        
        //Get next adc value
        if(channel == channelRudder)
        {
            adcValuePosition = ADC_GetConversion(channel);
        }
        else
        {    
            //Set brightness
            PWM3_LoadDutyValue(ADC_GetConversion(channel));
        }
        
        

        if(!inputTeachIn_GetValue() && !doButtonAction)
        {
            msPressed++;

            if(msPressed > 3000)
            {
                doButtonAction = true;
            }
            outputLed6_SetHigh();
        }
        else
        {
            msPressed = 0;
            outputLed6_SetLow();
        }
        
        
        
        if(doButtonAction)
        {
            
            while(!inputTeachIn_GetValue())
            {

            }
            
            switch(currentState)
            {
                case STATE_NORMAL:
                    setState(STATE_TEACH_LEFT);
                    break;
                    
                case STATE_TEACH_LEFT:
                    lowerLimit = adcValuePosition;
                    setState(STATE_TEACH_RIGHT);
                    break;

                case STATE_TEACH_RIGHT:
                    upperLimit = adcValuePosition;
                    
                    m = (1023*fixedPointFactor)/(upperLimit - lowerLimit);
                    b = lowerLimit*m; 
                    
                    setState(STATE_NORMAL);
                    break;
            }
            
            doButtonAction = false;
        }
        
   
        
        switch(currentState)
        {
            case STATE_NORMAL:
                if(channel == channelBrightness)
                { 
                    adcValuePosition = (adcValuePosition*m-b)/fixedPointFactor;
                    setLedsForPositioning(adcValuePosition);
                }
                break;    
            
            case STATE_TEACH_LEFT:
                if(doToggle)
                {
                    outputLed1_Toggle();
                    outputLed2_Toggle();
                    outputLed3_Toggle();
                    outputLed4_Toggle();
                    outputLed5_Toggle();
                    doToggle = false;
                }
                break;

                
            
            case STATE_TEACH_RIGHT:               
                if(doToggle)
                {
                    outputLed7_Toggle();
                    outputLed8_Toggle();
                    outputLed9_Toggle();
                    outputLed10_Toggle();
                    outputLed11_Toggle();
                    doToggle = false;
                }
                break;    
        }
        
    };
}




void setLedsForPositioning(int32_t adcValue)
{
    outputLed1_SetLow();
    outputLed2_SetLow();
    outputLed3_SetLow();                       
    outputLed4_SetLow();
    outputLed5_SetLow(); 
    outputLed6_SetHigh();
    outputLed7_SetLow();
    outputLed8_SetLow();
    outputLed9_SetLow();
    outputLed10_SetLow();
    outputLed11_SetLow();



    if(adcValue < 54)
    {  
        outputLed1_SetHigh();
    }
    else if(adcValue < 108)
    {
        outputLed1_SetHigh();
        outputLed2_SetHigh();
    }
    else if(adcValue < 162)
    {
        outputLed2_SetHigh();
    }
    else if(adcValue < 215)
    {
        outputLed2_SetHigh();
        outputLed3_SetHigh();                       
    }
    else if(adcValue < 269)
    {
        outputLed3_SetHigh();                       
    }
    else if(adcValue < 323)
    {
        outputLed3_SetHigh();                       
        outputLed4_SetHigh();
    }
    else if(adcValue < 377)
    {                    
        outputLed4_SetHigh();
    }
    else if(adcValue < 431)
    {                   
        outputLed4_SetHigh();
        outputLed5_SetHigh(); 
    }
    else if(adcValue < 485)
    {
        outputLed5_SetHigh(); 
    }
    else if(adcValue < 538)         //Center
    {

    }
    else if(adcValue < 592)         
    {
        outputLed7_SetHigh();
    }
    else if(adcValue < 646)         
    {
        outputLed7_SetHigh();
        outputLed8_SetHigh();
    }
    else if(adcValue < 700)         
    {
        outputLed8_SetHigh();
    }
    else if(adcValue < 754)         
    {
        outputLed8_SetHigh();
        outputLed9_SetHigh();
    }
    else if(adcValue < 808)         
    {
        outputLed9_SetHigh();
    }
    else if(adcValue < 861)         
    {
        outputLed9_SetHigh();
        outputLed10_SetHigh();
    }
    else if(adcValue < 915)         
    {
        outputLed10_SetHigh();
    }
    else if(adcValue < 969)         
    {
        outputLed10_SetHigh();
        outputLed11_SetHigh();
    }
    else   
    {
        outputLed11_SetHigh();
    }
    
}




















/**
 End of File
*/