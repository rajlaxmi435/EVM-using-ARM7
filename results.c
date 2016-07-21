#include<lpc214x.h>

#include"extrafunc.h"

char res[]="RESULT";

char c[]="CONGRESS:";

char b[]="BJP:";

char a[]="AAP:";

char nop[]="NIR:";


void display(int cn, int bs, int aa, int nda)
{
		lcd_cmd(0x01);  //for congress

		lcd_cmd(0x83);

		lcd_string(res);
		
		lcd_cmd(0xc0);
		
		lcd_string(c);

		eepm_read(0xA0, 0xA1, 0x00, 0x00, cn);

		eepm_clearall();

							
		//////////////////////////////////// for bjp

		delay(2000);

		lcd_cmd(0x01);

		lcd_cmd(0x80);
		
		lcd_string(b);

		eepm_read(0xA0, 0xA1, 0x00, 0x10, bs);

		eepm_clearall();
		///////////////////////////////for aap

		delay(2000);

		lcd_cmd(0x01);

		lcd_cmd(0x80);
		
		lcd_string(a);

		eepm_read(0xA0, 0xA1, 0x00, 0x20, aa);

		eepm_clearall();
		/////////////////////for nir
		
		delay(2000);

		lcd_cmd(0x01);
		
		lcd_cmd(0x80);
		
		lcd_string(nop);

		eepm_read(0xA0, 0xA1, 0x00, 0x30,nda);

		eepm_clearall();
}
