#include<lpc214x.h>
#define EN (1<<10)
#define RW (1<<12)
#define RS (1<<13)
#define DATA (0xff<<15)
#define PORT (EN|RS|RW|DATA)
void lcd_data(char cha);
void lcdint(char c);
void delay(long int count);
void lcd_stat(long int ch);
int main()
{
	
	lcdint(0x38);
	lcdint(0x0e);
	lcdint(0x80);
	lcdint(0x01);
	PINSEL0=(1<<4)|(1<<6); //for slecting SCL and ADA (p0.2 p0.3)
	I2C0CONSET=(1<<6); //for I2c Enabled.
	I2C0SCLL=75; //low duty cycle for bit freq of 100khz
	I2C0SCLH=75; //high duty cycle for bit freq of 100khz

	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA0; //SLA+w;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x00; //msb of my intilation command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x00; //lsb of my intilaization command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	
	I2C0CONSET=1<<4; //Stop condition

	I2C0CONSET=1<<2; //Aknowledge bit.
	
	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA1; //SLA+R;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_data(I2C0DAT);
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	

	//--------------
	
	
	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA0; //SLA+w;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x00; //msb of my intilation command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x10; //lsb of my intilaization command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0CONSET=1<<4; //Stop condition


	I2C0CONSET=1<<2; //Aknowledge bit.
	
	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA1; //SLA+R;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_data(I2C0DAT);
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.
	
			
	//---------

	
	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA0; //SLA+w;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x00; //msb of my intilation command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x20; //lsb of my intilaization command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0CONSET=1<<4; //Stop condition


	I2C0CONSET=1<<2; //Aknowledge bit.
	
	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA1; //SLA+R;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_data(I2C0DAT);
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.
	
	
	//-----------

	
	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA0; //SLA+w;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x00; //msb of my intilation command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0DAT=0x30; //lsb of my intilaization command
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0CONSET=1<<4; //Stop condition


	I2C0CONSET=1<<2; //Aknowledge bit.
	
	I2C0CONSET=1<<5; //Giving the Start Condition
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3)|(1<<5); //Clearing flag and start.

	I2C0DAT=0xA1; //SLA+R;
	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	while(!(I2C0CONSET & (1<<3))); //waiting for the flag to go high.
	lcd_data(I2C0DAT);
	lcd_stat(I2C0STAT);
	I2C0CONCLR=(1<<3); //Clearing flag and start.

	I2C0CONSET=1<<4; //Stop condition
	
 }

void lcdint(char c)
{
	IODIR0=PORT;
	IOPIN0=(c<<15);
	IOCLR0=RW;
	IOCLR0=RS;
	IOSET0=EN;
	delay(50);
	IOCLR0=EN;
}

void delay(long int count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<5000;j++);
}

void lcd_data(char cha)
 {
 	IOPIN0=(cha<<15);
	IOCLR0=RW;
	IOSET0=RS;
	IOSET0=EN;
	delay(50);
	IOCLR0=EN;
		
}

void lcd_stat(long int ch)
 {
 	 int long b=0,c;	
 	 char a;
 	   while(ch)
	   {
	   		c=(ch%16);
			b=(b*10+c);
			ch=(ch/16);
		}
	   while(b)
	   {
	   		a=(b%10);
			a=a+0x30;
	   		IOPIN0=a<<15;
			IOSET0=RS;
			IOCLR0=RW;
			IOSET0=EN;
			delay(50);
			IOCLR0=EN;
			b=b/10;
		}
		delay(1000);
		lcdint(0x01);
		
}