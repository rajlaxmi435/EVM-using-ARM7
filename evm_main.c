#include<lpc214x.h>

#include<string.h>

#include"extrafunc.h"

#define EN (1<<10)

#define RW (1<<12)

#define RS (1<<13)

#define ROW_ALL (1<<17)|(1<<18)|(1<<19)|(1<<20)

#define COL_ALL (1<<21)|(1<<22)|(1<<23)|(1<<24)

int con=0, bjp=0, app=0, n=0; //parties

//char ascon=0, asbjp=0, asapp=0, asn=0;

char porc[]="PROCESSING"; //10  char
				
char vot[]="YOU VOTED"; //9 char

char wel[]="WELCOME";

char start[]="PUSH START EVM";   //14 char

char sel[]="1.C 2.B 3.A 4.N"; //15 char.

char sel2[]="CAST YOUR VOTE"; //14 char.

char nmat[]="Not Match";

char mat[]="Granted";

int flagisr=0;

int flagdat=0;

int main()
{	
		
		//IODIR0= (1<<4) | (1<<5) | (1<<6) | (1<<7) | (1<<10) | (1<<11) | (1<<12) | (1<<13);
			
		PINSEL0=(1<<29)|(0<<28); //for selection functionality as Intruppt.

		lcd_cmd(0x38);  //intial command for lcd

		lcd_cmd(0x0e);

		lcd_cmd(0x01);

		lcd_cmd(0x80);

		VICIntEnable=(1<<15); //EINT1 as Intruppt or start

		VICIntSelect=(0<<15); //as irq

		VICVectCntl0=(1<<5)|15; //enabling slot 0 for EINT 1 

		VICVectAddr0=(long)isr_eint1;

		EXTMODE=(1<<1); 

		EXTPOLAR=(0<<1);

		lcd_cmd(0x84);
		
		lcd_string(wel);

		lcd_cmd(0xc1);

		lcd_string(start);


		while(1)
		{
			if (flagisr==1)
			{
				if (flagdat==0)
				{
					flagdat=1;
						
					eepm_write(0xA0,0x00,0x00,con);

					eepm_clearall();
					
					eepm_write(0xA0,0x00,0x10,bjp);

					eepm_clearall();
					
					eepm_write(0xA0,0x00,0x20,app);

					eepm_clearall();
					
					eepm_write(0xA0,0x00,0x30,n);	

					eepm_clearall();
				}
				if(flagdat==1)
				{	
					long int x=0;
  					IODIR1= ROW_ALL;
				   	IOCLR1=ROW_ALL;

					x=IOPIN1 & (0xf<<21);

					x=x>>21;

					if(x==0xe)
					{
						delay(400);

				   		row_col();
						
						delay(3000);
													
						EXTINT = 1<<1;

						PINSEL0=0x0000;

						IODIR0=IODIR0|1<<14;

						IOSET0=IOSET0|1<<14;

						VICVectAddr = 0;

						IODIR0 &=~(1<<14);

						IODIR1 &=~(1<<0);

						flagisr=0;

						main();

					}
					if(x==0xb)
					{
						delay(400);
						
						row_res();

					//	break;	
					} 
				}	
			}
			
		}
		
}
void row_col()
{
		 long int y=0;

		 IODIR1=COL_ALL;

		 IOCLR1=COL_ALL;

		 y=IOPIN1 & (0xf<<17);

		 y=y>>17;

	  	if(y==0xe)
		{
			con++;
			
			eepm_write(0xA0, 0x00, 0x00, con);
			eepm_clearall();

			lcd_cmd(0x01);
			lcd_string(porc);
			
			IODIR0=1<<25;
		   	IOSET0=1<<25;
		   	delay(3000);
		   	IOCLR0=1<<25;

			lcd_cmd(0x01);
			
			lcd_string(vot);
			return;
		}

		if(y==0xd)
		{
			bjp++;

			eepm_write(0xA0, 0x00, 0x10, bjp);
			eepm_clearall();

			lcd_cmd(0x01);
			lcd_string(porc);
			
			IODIR0=1<<25;
			IOSET0=1<<25;
			delay(3000);
			IOCLR0=1<<25;

			lcd_cmd(0x01);
			
			lcd_string(vot);

			return;

		}
		
		if(y==0xb)
		{
			app++;

			eepm_write(0xA0, 0x00, 0x20, app);
			eepm_clearall();

			lcd_cmd(0x01);
			lcd_string(porc);
			
			IODIR0=1<<25;
			IOSET0=1<<25;
			delay(3000);
			IOCLR0=1<<25;

			lcd_cmd(0x01);
			
			lcd_string(vot);

			return;

		}

		if(y==0x7)
		{
			n++;

			eepm_write(0xA0, 0x00, 0x30, n);
		   	eepm_clearall();

			lcd_cmd(0x01);
			lcd_string(porc);
			
			IODIR0=1<<25;
			IOSET0=1<<25;
			delay(3000);
			IOCLR0=1<<25;

			lcd_cmd(0x01);
			
			lcd_string(vot);

			return;

		}
}		

void isr_eint1(void)__irq
{
	
	lcd_cmd(0x01);

	lcd_cmd(0x80);
			
	lcd_string(sel);
	
	lcd_cmd(0xc0);
	
	lcd_string(sel2);
	
	flagisr=1;

}

void row_res()
{
	long int z=0;
	int pas;

	IODIR1=COL_ALL;

	 IOCLR1=COL_ALL;

	 z=IOPIN1 & (0xf<<17);

	 z=z>>17;

	  	if(z==0xe)
		{
			 
			while(1)
			{
				pas=pass();
			 	if(pas==0)
				{
			 		lcd_cmd(0x01);

				 	lcd_string(mat);

					delay(1000);

					display(con, bjp, app, n);
	
					delay(6000);

					winner(con, bjp, app, n);

					delay(6000);

					flagisr=0;

					VICVectAddr=0;

					EXTINT=1<<1;

					VICIntEnClr=1<<15;

					break;

				}
			 	else
			 	{
			 		lcd_cmd(0x01);
					lcd_string(nmat);

					delay(1000);

					continue;
				}
			}
		}
	return;
}
