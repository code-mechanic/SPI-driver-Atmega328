#include "spi.h"
#include "ADC_MCP3004.h"

void ADC_Init()
{
  SPI_Init();
}
uint16_t ADC_Read(uint8_t channel)
{
  uint8_t byte,data_high,data_low;
  byte = 0b00000001; //START BIT
  SPI_Write(byte);
  switch(channel)
  {
    /*7    -> single_ended configuration
      6    -> don't care bit
      5,4  -> channel select bit
      BIT SEQUENCE -> 76543210*/  
    case 0: byte =  0b10000000;break;
    case 1: byte =  0b10010000;break;
    case 2: byte =  0b10100000;break;
    case 3: byte =  0b10110000;break;
  }
  data_high=SPI_Write(byte);
  data_high&=0b00000011;    // 10th and 9th bit of ADC conversion 
  data_low=SPI_Write(0x00); // Don't care argument 
  data_low&=0xFF;           // last 8 bit of ADC conversion
  CS_HIGH();
  return ((data_high<<8)|data_low);
}