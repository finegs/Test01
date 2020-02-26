#define SHT20_TEMPERATURE 0xE3
#define SHT20_HUMIDITY   0xE5

void SHT20_read(unsigned char chip, unsigned char addr, unsigned char * dat);
void SHT20_SoftReset(void);
void SHT20_Digit(unsigned char pos, unsigned char *dat, unsigned char DataType);

unsigned char TWCR;
unsigned char TWDR;
unsigned char TWSR;
unsigned char TWBR;
unsigned char dat;
unsigned char SHT20;


void main(void)
{

             SHT20_SoftReset();

             while(1)
             {
                       //SHT20 0x80 //SHT20 Temp Humidity sensor ID
                       SHT20_read(SHT20, SHT20_TEMPERATURE, &dat); //SHT20_TEMPERATURE 0xE3 //Measure Temperature under Hole Mode
                       SHT20_Digit(0xC2, &dat, 'T'); //SHT20_HUMIDITY 0xE5 //Measure Humidity under Hold Mode
               }
}


void SHT20_read(unsigned char chip, unsigned char addr, unsigned char * dat)
{
	TWCR = 0xA4;  // START       
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x08));
	TWDR = chip;  // SLA-W
	TWCR = 0x84;
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x18));

	TWDR = addr;
	TWCR = 0x84; // Temperature or Humidity
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x28));

	TWCR = 0x94;

	TWCR = 0xA4;                    // RE-START
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x10));

	TWDR = chip | 0x01;                    // SLA-R
	TWCR = 0xC4;//with ACK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x40));

	TWCR = 0xC4;//with ACK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x50));

	*dat = (unsigned char)TWDR;

	TWCR = 0xC4;//with ACK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x50));

	dat++;
	*dat = (unsigned char)TWDR;

	TWCR = 0x84;//with NAK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x58));

	dat++;
	*dat = (unsigned char)TWDR;

	TWCR = 0x94;
}

void SHT20_SoftReset(void)
{
	TWBR = 32;
	TWSR = 0x00;

	TWCR = 0xA4;                    // START
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x08));
	TWDR = SHT20;                    // SLA-W
	TWCR = 0x84;
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x18));
	TWDR = 0xFE;//soft reset
	TWCR = 0x84;                    // ADDRESS
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x28));
	TWCR = 0x94;
}

void SHT20_Digit(unsigned char pos, unsigned char *dat, unsigned char DataType)
{

	unsigned int value = (unsigned char)dat[0];
	value <<= 8;
	value += (unsigned char)dat[1];

	

	if (DataType == 'T')
		value = (int)(-46.85 * 10 + 175.72 * (double)value / 65536 * 10); //Convert Temperature
	else
		value = (int)(-6 * 10 + 125 * (double)value / 65536 * 10); //Convert Humidity



	if (value>=100)
	{
		digit_out(pos++, 0x30 + value/100); //Display Digit on Character LCD
		value -= (value/100)*100;
	}
	else
		digit_out(pos++, 0x30);



	if (value>=10)
	{
		digit_out(pos++, 0x30 + value/10);
		value -= (value/10)*10;
	}
	else
		digit_out(pos++, 0x30);
	
	digit_out(pos++, '.');

	digit_out(pos++, 0x30 + value);

	if (DataType == 'T')
	{
		digit_out(pos++, 0xDF);
		digit_out(pos++, 'C');
	}

	else
		digit_out(pos++, '%');

}
