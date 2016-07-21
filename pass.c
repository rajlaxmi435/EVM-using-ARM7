#include<lpc214x.h>
#include"extrafunc.h"
#include<string.h>

int pass()
{
	int i=0,c;
	char ask[]="Enter Password";
	char prepass[]="12345";
	char pass[5];
	PINSEL0=(1<<0)|(1<<2);	 //pin p0.0 act as uART0 TX snf pin0.1 act as UART0 Rx.
	U0LCR=(1<<7); //to Enable the wirite access buffer registers.
	U0DLL=97; //for baud rate of 9600.
	U0LCR=3; //Disable the buffers write access buffer register.

while(1)
{	   	
		delay(1000);

		lcd_cmd(0x01);

		lcd_string(ask);

		i=0;
	   	while(1)
		{
			while(!(U0LSR & (1<<0))); //wait until RBR contails valid data.
			pass[i]=U0RBR; //Reading the data from buffer.
			if(pass[i]=='\n')
			{
				 i--;
				pass[i]='\0';
				break;
			}
			else
			{
				i++;
			}
		}
	   	
		c=strcmp(prepass,pass);
 		if(c==0)
		{
				return 0;
		}  
		else
		{
				return 1;
		}
}
}
