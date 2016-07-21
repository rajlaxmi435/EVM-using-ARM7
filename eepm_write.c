#include<lpc214x.h>

#include"extrafunc.h"

char dat,ascon;

int i;

void eepm_write(char mode, char msb, char lsb, int data)
{

	int temp=0, rev=0;

	if (data<=9)
	{
		eepm_config();

		eepm_start();
		eepm_wait();
		eepm_clear();
	
		eepm_data(mode);
		eepm_wait();
		eepm_clear1();

		eepm_data(msb);
		eepm_wait();
		eepm_clear1();

		eepm_data(lsb);
		eepm_wait();
		eepm_clear1();

		eepm_data(data+0x30);
		eepm_wait();
		eepm_clear1();

		eepm_stop();

		return;
	}
	else if ((data%10)==0)
	{
		eepm_config();

		eepm_start();
		eepm_wait();
		eepm_clear();
	
		eepm_data(mode);
		eepm_wait();
		eepm_clear1();

		eepm_data(msb);
		eepm_wait();
		eepm_clear1();

		eepm_data(lsb);
		eepm_wait();
		eepm_clear1();

		eepm_data((data/10)+0x30);
		eepm_wait();
		eepm_clear1();

		eepm_data(0+0x30);
		eepm_wait();
		eepm_clear1();

		eepm_stop();

		return;
	}

	while(data)
	{
	
		temp=data%10;
	
		rev=(rev*10)+temp;
	   	
		data/=10;
	}

		eepm_config();

		eepm_start();
		eepm_wait();
		eepm_clear();
	
		eepm_data(mode);
		eepm_wait();
		eepm_clear1();

		eepm_data(msb);
		eepm_wait();
		eepm_clear1();

		eepm_data(lsb);
		eepm_wait();
		eepm_clear1();

	while(rev)
	{
			
			temp=rev%10;
		   	eepm_data(temp+0x30);
			eepm_wait();
			eepm_clear1();

			rev/=10;	

			
    }	
	eepm_stop();

}

void eepm_read(char txmode, char rxmode, char msb, char lsb, int data)
{			
	if (data<=9)
	{
   		eepm_config();
	
		eepm_start();
		eepm_wait();
		eepm_clear();
		//lcd_stat(I2C0STAT);

		eepm_data(txmode);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		//I2C0CONCLR=1<<3;

		eepm_data(msb);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		eepm_data(lsb);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();
	
		eepm_stop();

		eepm_start();
		eepm_wait();
		eepm_clear1();

		eepm_akn();
		
		eepm_data(rxmode);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		eepm_wait();
		lcd_data(I2C0DAT);
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		eepm_stop();

		return;
	}
	else if ((data%10)==0) 
	{
		eepm_config();
	
		eepm_start();
		eepm_wait();
		eepm_clear();
		//lcd_stat(I2C0STAT);

		eepm_data(txmode);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		//I2C0CONCLR=1<<3;

		eepm_data(msb);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		eepm_data(lsb);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();
	
		eepm_stop();

		eepm_start();
		eepm_wait();
		eepm_clear1();

		eepm_akn();

		eepm_data(rxmode);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		for (i=0; i<2;i++)
		{
			eepm_wait();
			lcd_data(I2C0DAT);
			//lcd_stat(I2C0STAT);
			eepm_clear1();
		}
		
		eepm_stop();
		return;
	}

		eepm_config();
	
		eepm_start();
		eepm_wait();
		eepm_clear();
		//lcd_stat(I2C0STAT);

		eepm_data(txmode);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		//I2C0CONCLR=1<<3;

		eepm_data(msb);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();

		eepm_data(lsb);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();
	
		eepm_stop();

		
		eepm_start();
		eepm_wait();
		eepm_clear1();

		eepm_akn();

		eepm_data(rxmode);
		eepm_wait();
		//lcd_stat(I2C0STAT);
		eepm_clear1();
			 
		while(data)
		{
			eepm_wait();
			lcd_data(I2C0DAT);
			//lcd_stat(I2C0STAT);
			eepm_clear1();

			data=data/10;
		}

		eepm_stop();
		return;
}
