//-----------------------------------------------------------------------------
// F93x_PCA0_8Bit_PWM_Output.c
//-----------------------------------------------------------------------------
// Copyright 2009 Silicon Laboratories, Inc.
// http://www.silabs.com
//
// Program Description:
//
// This program sends a PWM waveform out of an I/O pin, using the PCA's
// 8-bit PWM Output Mode.  The duty cycle of the waveform is modified
// periodically within the main loop.
//
// In this example, PCA Module 0 is used to generate the waveform, and the
// crossbar is configured to send the CEX0 pin out on P0.0.
//
// How To Test:
//
// 1) Download code to a 'F93x device which has an oscilloscope monitoring P0.0
// 2) Run the program - the waveform should be visible on the oscilloscope.
// 3) Verify that the duty cycle of the waveform varies smoothly between
//    minimum and maximum values.
//
//
// Target:         C8051F93x
// Tool chain:     Generic
// Command Line:   None
//
//
// Release 1.2 
//    - Updated to be compatible with Raisonance Toolchain (FB)
//    - 14 APR 2010
//
// Release 1.1 
//    - Compiled and tested for C8051F930-TB (JH)
//    - 07 JULY 2009
//
// Release 1.0
//    - Initial Revision (FB)
//    - 16 NOV 2007
//

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <compiler_defs.h>
#include <C8051F930_defs.h>            // SFR declaration
#include "sound.h"
//-----------------------------------------------------------------------------
// Global Constants
//-----------------------------------------------------------------------------

#define SYSCLK       24500000          // Internal oscillator frequency in Hz
SBIT (LED, SFR_P1, 6);
unsigned int g_wait = 0;
//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Initialization Subroutines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// OSCILLATOR_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function initializes the system clock to use the internal precision
// oscillator.
//
//-----------------------------------------------------------------------------
void OSCILLATOR_Init (void)
{
   
   
   OSCICN |= 0x80;                     // Enable the precision internal osc.
      
   RSTSRC = 0x06;                      // Enable missing clock detector and
                                       // leave VDD Monitor enabled.

   CLKSEL = 0x00;                      // Select precision internal osc. 
                                       // divided by 1 as the system clock
  
}

//-----------------------------------------------------------------------------
// PORT_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function configures the crossbar and GPIO ports.
//
// P0.0/1   digital   push-pull     PCA0 CEX0/1
//
//-----------------------------------------------------------------------------
void PORT_Init (void)
{
   XBR0    = 0x00;
   XBR1    = 0x02;                     // Route CEX0 to P0.0, CEX1 to P0.1
   XBR2    = 0x40;                     // Enable crossbar and weak pull-ups

   P0MDOUT |= 0x03;                    // Set CEX0/1 (P0.0/1) to push-pull
   P1MDOUT = 0x40;                     // Set LED
}

//-----------------------------------------------------------------------------
// PCA0_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function configures the PCA time base, and sets up 8-bit PWM output
// mode for Module 0 (CEX0 pin).
//
// The frequency of the PWM signal generated at the CEX0 pin is equal to the
// PCA main timebase frequency divided by 256.
//
// The PCA time base in this example is configured to use SYSCLK, and SYSCLK
// is set up to use the internal oscillator running at 24.5 MHz.  Therefore,
// the frequency of the PWM signal will be 24.5 MHz / 256 = 95.7 kHz.
// Using different PCA clock sources or a different processor clock will
// result in a different frequency for the PWM signal.
//
//    -------------------------------------------------------------------------
//    How "8-Bit PWM Mode" Works:
//
//       The PCA's 8-bit PWM Mode works by setting an output pin low every
//    time the main PCA counter low byte (PCA0L) overflows, and then setting
//    the pin high whenever a specific match condition is met.
//
//    Upon a PCA0L overflow (PCA0L incrementing from 0xFF to 0x00), two things
//    happen:
//
//    1) The CEXn pin will be set low.
//    2) The contents of the PCA0CPHn register for the module are copied into
//       the PCA0CPLn register for the module.
//
//    When the PCA0L register increments and matches the PCA0CPLn register for
//    the selected module, the CEXn pin will be set high, except when the
//    ECOMn bit in PCA0CPMn is cleared to '0'.  By varying the value of the
//    PCA0CPHn register, the duty cycle of the waveform can also be varied.
//
//    When ECOMn = '1', the duty cycle of the PWM waveform is:
//
//       8-bit PWM Duty Cycle = (256 - PCA0CPLn) / 256
//
//    To set the duty cycle to 100%, a value of 0x00 should be loaded into the
//    PCA0CPHn register for the module being used (with ECOMn set to '1').
//    When the value of PCA0CPLn is equal to 0x00, the pin will never be
//    set low.
//
//    To set the duty cycle to 0%, the ECOMn bit in the PCA0CPMn register
//    should be cleared to 0.  This prevents the PCA0CPLn match from occuring,
//    which results in the pin never being set high.
//    -------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void PCA0_Init (void)
{
   /* Stop counter; clear all flags */
   PCA0CN = 0x00;                      
   /* Enable PCA counter*/
   PCA0CN    = 0x40;
   /* Use SYSCLK as time base */
   PCA0MD    = 0x08;
   /* Module 0,1 Comparator Function and Pulse Width Modulation Mode Enable */
   PCA0CPM0  = 0x42;
   PCA0CPM1  = 0x42;
   /* Cycle length 9 bit */
   // PCA0PWM   = 0x01; 


   /* Configure initial PWM duty cycle = 50% */
   // PCA0PWM   |= 0x80;           // ARSEL = 1
   // PCA0CPL0  = 0x00;
   // PCA0CPH0  = 0x01;
   // PCA0CPL1  = 0x00;
   // PCA0CPH1  = 0x01;
   // PCA0PWM   &= ~0x80;          // ARSEL = 0
   
}

void Timer0_Init(void)
{
   TH0 = 256 - (SYSCLK / 48 / 8000) ;           // Init Timer0 High register
   TL0 = TH0;                          // Set the intial Timer0 value

   TMOD = 0x02;                        // Timer0 in 8-bit reload mode
   CKCON = 0x02;                       // Timer0 uses a 1:48 prescaler
   ET0 = 1;                              // Timer0 interrupt enabled
   TCON = 0x10;                        // Timer0 ON
}


INTERRUPT (TIMER0_ISR, INTERRUPT_TIMER0)
{
   if (g_wait) g_wait--;
   LED = !LED;                     
}

void fun_test()
{
   unsigned int delay_count;           // Used to implement a delay
   unsigned short pwm_value = 0x80;     // initial value 
   bit duty_direction = 0;             // 0 = Decrease; 1 = Increase
   while (1)
   {
      // Wait a little while
      for (delay_count = 30000; delay_count > 0; delay_count--);

      PCA0CPH0  = pwm_value;
      PCA0CPH1  = (0xFF - pwm_value);
   
      if (duty_direction == 1) {
         pwm_value--;
         if (pwm_value == 0) {
            duty_direction = 0;
         }
      }else{
         pwm_value++;
         if (pwm_value == 0xFF) {
            duty_direction = 1;
         }
      }
   }
}

void pcm_test()
{
   int i;
   unsigned short pwm_value;
   while(1){
      for(i = 0; i < PCM_SIZE; i++){
         pwm_value = sounddata[i];
         PCA0CPH0  = pwm_value;
         PCA0CPH1  = (0xFF - pwm_value);
         g_wait = 1;
         while(g_wait);
      }
      g_wait = 8000;
      while(g_wait);
   }
}


// main() Routine
//-----------------------------------------------------------------------------

void main (void)
{

   PCA0MD = 0x00;                      // Disable watchdog timer
   Timer0_Init (); 
   PORT_Init ();                       // Initialize crossbar and GPIO
   OSCILLATOR_Init ();                 // Initialize oscillator
   PCA0_Init ();                       // Initialize PCA0
   EA = 1;                             // Enable global interrupts
   // fun_test();
   pcm_test();
   while(1);
}


//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------