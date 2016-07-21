#include<lpc214x.h>

#include"extrafunc.h"

#include<string.h>

#define EN (1<<10)

#define RW (1<<12)

#define RS (1<<13)

#define DATA (0xff<<15)

#define PORT (EN|RS|RW|DATA)




void lcd_cmd(char cmd)
{
	IODIR0=PORT;

	IOPIN0=(cmd<<15);

	IOCLR0=RW;

	IOCLR0=RS;

	IOSET0=EN;

	delay(50);

	IOCLR0=EN;

	
}

void lcd_string(char str[])
{
	int len=strlen(str);

	int i;

	for(i=0;i<len;i++)

	{
		IOPIN0=(str[i]<<15);

		IOCLR0=RW;

		IOSET0=RS;

		IOSET0=EN;

		delay(50);

		IOCLR0=EN;

	}
}

void delay(long int count)
{
	int i,j;

	for(i=0;i<count;i++)

		for(j=0;j<5000;j++);

	
}

void lcd_data(char res)
{
	IOPIN0=(res<<15);
	IOCLR0=RW;
	IOSET0=RS;
	IOSET0=EN;
	delay(50);
	IOCLR0=EN;
}

// void lcd_stat(long int ch)
// {
// 		if(ch)
//		{
//		 lcd_stat(ch/16);
//		 lcd_data((ch%16) + 0x30);
//		}
// 	 int long b=0,c;	
// 	 char a;
// 	   while(ch)
//	   {
//	   		c=(ch%16);
//			b=(b*10+c);
//			ch=(ch/16);
//		}
//	   while(b)
//	   {
//	   		a=(b%10);
//			a=a+0x30;
//	   		IOPIN0=a<<15;
//			IOSET0=RS;
//			IOCLR0=RW;
//			IOSET0=EN;
//			delay(50);
//			IOCLR0=EN;
//			b=b/10;
//		}
//		delay(1000);
//		lcd_cmd(0x01);
		
//}
