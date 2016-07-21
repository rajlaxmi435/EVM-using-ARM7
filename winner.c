#include<lpc214x.h>

#include"extrafunc.h"

char win[]="WINNER";

char cg[]="CONGRESS";

char bp[]="BJP"	;

char aa[]="AAP";

char np[]="NIRDALIYA";

char tie[]="TIE";


void winner(int co, int bj, int ap, int ni)
{
	if(co>bj && co>ap && co>ni)
	{
		lcd_cmd(0x01);

		lcd_cmd(0x84);

		lcd_string(win);

		lcd_cmd(0xc4);

		lcd_string(cg);
	}

	else if (bj>co && bj>ap && bj>ni)
	{
		lcd_cmd(0x01);

		lcd_cmd(0x84);

		lcd_string(win);

		lcd_cmd(0xc4);

		lcd_string(bp);
	}
	else if(ap>co && ap>bj && ap>ni)
	{
		lcd_cmd(0x01);

		lcd_cmd(0x84);

		lcd_string(win);

		lcd_cmd(0xc4);

		lcd_string(aa);
	}
	else if(ni>co && ni>ap && ni>bj)
	{
		lcd_cmd(0x01);

		lcd_cmd(0x85);

		lcd_string(win);

		lcd_cmd(0xc4);

		lcd_string(np);
	}
	
	else
	{
		lcd_cmd(0x01);

		lcd_cmd(0x85);

		lcd_string(win);

		lcd_cmd(0xc4);

		lcd_string(tie);
	}

	return;
}	
