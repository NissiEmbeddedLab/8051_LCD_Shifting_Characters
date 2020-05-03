#include<reg51.h>

#define ldata P2
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

void lcdcmd(unsigned char value);
void lcddata(unsigned char value);
void MSDelay(unsigned int itime);
unsigned char i,s;
void lcdcmd(unsigned char value)
	{
		ldata = value;
		rs =  0;
		rw = 0;
		en = 1;
		MSDelay(1);
		en = 0;
		return;
	}
void lcddata(unsigned char value)
	{
		ldata = value;
		rs =  1;
		rw = 0;
		en = 1;
		MSDelay(1);
		en = 0;
		return;
	}
void MSDelay(unsigned int itime)
	{
		unsigned  int i,j;
		for(i=0;i<itime;i++)
			for(j=0;j<1275;j++);
	}

void LCD_Message (unsigned char *c) 
{
	int n;
	for(n=0;c[n]!=0;n++)  
	{
		lcddata(c[n]);  
	}
}

void LCD_String_xy (char row, char pos, char *x)  
{
	if (row == 0)
	lcdcmd((pos & 0x0F)|0x80);
	else if (row == 1)
	lcdcmd((pos & 0x0F)|0xC0);
	LCD_Message(x);	
}

void LCD_Init (void)		
{	
	MSDelay(20);		
	lcdcmd(0x38);	
	lcdcmd(0x0C);	
	lcdcmd(0x06);	
	lcdcmd(0x01);
	lcdcmd(0x80);	
}

void main()
{

	LCD_Init();		
	LCD_Message("                Use only 16 char");  //change your name here do not replace the space inside the ""
	lcdcmd(0xC0);
	LCD_Message("                 Type your Name ");   //add your text here
	MSDelay(250);
	s=48;												
while(1)
{
	for(i=0;i<s;i++)				
  { 
		lcdcmd(0x1c);					//lcdcmd(0x18);		//use this line for right shift
		MSDelay(30);
  }						
 }	
}
 