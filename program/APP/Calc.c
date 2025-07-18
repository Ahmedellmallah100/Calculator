 #include <avr/io.h>
#include <util/delay.h>
#include "../Library/std_Bytes.h"
#include "../Library/bit_math.h"
#include "../MCAL/Dio/Dio_interface.h"
#include "../HALL/7_Segment/7_segment_inter.h"
#include "../HALL/Led/Led_interface.h"
#include "../HALL/kypad/kypad_interface.h"
#include "../HALL/Lcd/Lcd_interface.h"

#define LINE0  0
#define LINE1  1

int main(){
    u8 arr[] = { 'H', 'E', 'L', 'L', 'O', '\0' };
        u8 arr2[] = { 'R', 'E', 'S', 'U', 'L','T',':', '\0' };


    u8 key1, key2 ,num1 , num2 ,op,equal;
    int result ;

// Initializations
KPAD_voidInit ();
lcd_init();

// Show welcome message
 lcdsend_cursor_atPosition(LINE0 ,0);
LCD_voidWriteString ( arr);
 _delay_ms(100);
LCD_voidClearDisplay ();
 _delay_ms(100);
 
 while (1){
  // 1st number
    do {
        key1 = KPAD_u8GetPressedKey();
    } while (key1 == 0xff);
    
        lcdsend_data_atPosition(LINE0 , 0 , key1);
   while (KPAD_u8GetPressedKey() !=0xff);
       _delay_ms(30);

 num1 = key1 - '0';
   
   
   
    // Operator
    do {
        op = KPAD_u8GetPressedKey();
    } while (op == 0xff);
            lcdsend_data_atPosition(LINE0 , 1, op);

       while (KPAD_u8GetPressedKey() != 0xff);
    _delay_ms(30);
    
   

    // 2nd number
    do {
        key2 = KPAD_u8GetPressedKey();
    } while (key2 == 0xff);
            lcdsend_data_atPosition(LINE0 , 2 , key2);

       while (KPAD_u8GetPressedKey() != 0xff);
           _delay_ms(30);

         num2 = key2 - '0';
    

               // Wait for '=' key to display result
        do {
            equal = KPAD_u8GetPressedKey();
        } while (equal != '=');
        while (KPAD_u8GetPressedKey() != 0xFF);
        _delay_ms(30);
   

    // Result
    lcdsend_cursor_atPosition(LINE1, 0);
    LCD_voidWriteString(arr2);

    // Perform operation
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else
                result = 0;  // Avoid division by zero
            break;
        default:
            result = 0;
            break;
    }
if (result < 10) {
    lcdsend_data_atPosition(LINE1, 7, result + '0');
} else {
    lcdsend_data_atPosition(LINE1, 7, (result / 10) + '0');  
    lcdsend_data_atPosition(LINE1, 8, (result % 10) + '0');  
}




}




}