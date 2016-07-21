#include<lpc214x.h>

#include"extrafunc.h"

void eepm_config()
{
	PINSEL0=(1<<4)|(1<<6); //for slecting SCL and ADA (p0.2 p0.3)

	I2C0CONSET=(1<<6); //for I2c Enabled.

	I2C0SCLL=75; //low duty cycle for bit freq of 100khz

	I2C0SCLH=75; //high duty cycle for bit freq of 100khz

	return;
}

void eepm_wait()
{
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.

	return;
}


void eepm_clear()
{
	
		I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

		return;
}

void eepm_start()
{
	I2C0CONSET=1<<5; //Giving the Start Condition

//	 lcd_stat(I2C0STAT);
	return;
}

void eepm_data(long int data)
{
	
	I2C0DAT=data; //SLA+w;
	return;
}

char eepm_dtoasc(int dig)
{
	int asc=0;
	asc=(dig|0x30);
	return asc;
}

void eepm_stop()
{
	I2C0CONSET=1<<4; //Stop condition 
}

void eepm_akn()
{
	I2C0CONSET=1<<2; //Aknowledge bit.
}

void eepm_clear1()
{
		I2C0CONCLR=(1<<3);
}

void eepm_clearall()
{
//
//	I2C0CONSET=0;
	I2C0SCLL=0; //low duty cycle for bit freq of 100khz
   	I2C0SCLH=0;	 
	I2C0CONCLR=0x46;
	
}
