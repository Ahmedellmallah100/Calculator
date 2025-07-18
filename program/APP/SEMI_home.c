 #include <stdio.h>
 #include <avr/io.h>
#include <util/delay.h>
#include "../Library/std_Bytes.h"
#include "../Library/bit_math.h"
#include "../MCAL/Dio/Dio_interface.h"
#include "../HALL/7_Segment/7_segment_inter.h"
#include "../HALL/Led/Led_interface.h"
#include "../HALL/kypad/kypad_interface.h"
#include "../HALL/Lcd/Lcd_interface.h"
#include "../MCAL/ADC/Adc_config.h"
#include "../MCAL/ADC/Adc_interface.h"
#include "../MCAL/ADC/Adc_private.h"






#define TEMP_CHANNEL       ADC0     // LM35 على A0
#define LDR_CHANNEL        ADC1     // LDR على A1
#define BUZZER_PORT        PORTC
#define BUZZER_PIN         PIN1
#define LED_PORT           PORTC
#define LED_PIN            PIN0

int main (){
   
   AdcVoid_init();
   lcd_init
   DIO_voidSetPinDirect(BUZZER_PORT, BUZZER_PIN, OUTPUT);
   DIO_voidSetPinDirect(LED_PORT, LED_PIN, OUTPUT);



 lcdsend_cursor_atPosition(LINE0 ,0);
LCD_voidWriteString ("SEMI SMART SYS");
 lcdsend_cursor_atPosition(LINE1 ,0);
LCD_voidWriteString ("By AHMED HAMED");
 _delay_ms(200);
LCD_voidClearDisplay ();


while (1)
{   
         u16 adc_temp = ADC_u16ReadSynchronus(TEMP_CHANNEL);
        u16 temp_mv = (adc_temp * 5000UL) / 1024;
        u16 temperature = temp_mv / 10;

        
        if (temperature >= 50)
        {
            DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, High);
            lcdsend_cursor_atPosition(LINE0 ,0);
            LCD_voidWriteString(" FIRE...FIRE");
        }
        else
        {
            DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, Low);
            LCD_voidClearDisplay ();
            lcdsend_cursor_atPosition(LINE0 ,0);
            LCD_voidWriteString("TEMP = ");
            lcdsend_print_data(temperature);
            LCD_voidWriteString(" C");
        }


       u16 light_read = ADC_u16ReadSynchronus(LDR_CHANNEL); 
		
		u16 light_mv = (light_read * 5000UL) / 1023;  
        u8 light_percent = (light_read * 100UL) / 1023;
        
        
       

        if (light_percent < 40 )
        { 
            lcdsend_cursor_atPosition(LINE1 ,0);

			LCD_voidWriteString("Light:");
            lcdsend_print_data(light_percent);
          
            LCD_voidWriteString(" Dark");
            DIO_voidSetPinValue(LED_PORT, LED_PIN, High);  
        }
     
        else
        {
            lcdsend_cursor_atPosition(LINE1 ,0);

			LCD_voidWriteString("Light:");
             lcdsend_print_data(light_percent);
           
            LCD_voidWriteString(" Bright");
            DIO_voidSetPinValue(LED_PORT, LED_PIN, Low);
        }

        _delay_ms(150); 




}


return 0;




}