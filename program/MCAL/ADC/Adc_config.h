


#ifndef Adc_CONFIG_H
#define Adc_CONFIG_H






//Select Refrance Voltage
#define     AREF                         0
#define     AVCC                         1
#define     RESERVED                     2
#define     INTERNAL                     3
#define     REFERENCE_VOLTAGE           AVCC
//********************************************************** 


//Select Adjust
#define     RIGHT                        0
#define     LEFT                         1
#define     ADJUST                     RIGHT
//********************************************************** 



//Select ADC Enable or disable
#define     DISABLE                      0
#define     ENABLE                       1
#define     ADEN                       ENABLE
//===============================================



//Select trigger Enable or disable
#define     DISABLE                      0
#define     ENABLE                       1
#define     ADATE                       ENABLE
//Auto Triggger
#define  Free_Running_Mode               0
#define  Analog_Comparator               1
#define  External_Interrupt_Request_0    2
#define  Timer_Counter0_Compare_Match    3
#define  Timer_Counter0_Overflow         4
#define  Timer_Counter1_Compare_MatchB   5
#define  Timer_Counter1_Overflow         6
#define  Timer_Counter1_Capture_Event    7
#define  AUTO_TRIGGER_SOURCE     Free_Running_Mode
//===============================================



//Select Interupput Enable or disable
#define     DISABLE                      0
#define     ENABLE                       1
#define     ADIE                       ENABLE
//===============================================



// Select Adc Prescaler Select Bit
// Decreae feequency in micro controller
#define     NOT_USE_PRESCALER             0
#define     PRESCALER_DIVISION_BY_2       2
#define     PRESCALER_DIVISION_BY_4       4
#define     PRESCALER_DIVISION_BY_8       8
#define     PRESCALER_DIVISION_BY_16      16
#define     PRESCALER_DIVISION_BY_32      32
#define     PRESCALER_DIVISION_BY_64      64
#define     PRESCALER_DIVISION_BY_128     128
#define     PRESCALE                     NOT_USE_PRESCALER



#endif