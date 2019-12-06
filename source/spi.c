#include <avr/io.h>
#include "spi.h"
#include"stdint.h"

void SPI_Init(void)
{
  /*MOSI,CS and SCK output*/
  SPI_DDR|=((1<<MOSI_POS)|(1<<SCK_POS)|(1<<CS_POS));
  /*
  SPI BUS CONFIGURATION
  ---------------------
  *Master Mode
  *MSB first
  *CPOL=0
  *CPHA=0
  *Above two implies SPI MODE0
  *SCK Freq = FCPU/16 i.e. 1MHz
  */
  SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
  CS_LOW();
}

void SPI_Close(void)
{
  SPCR&=(~(1<<SPE));
  SPI_DDR&=(~((1<<MOSI_POS)|(1<<SCK_POS)));
}
uint8_t SPI_Write(uint8_t data)
{
  SPDR = data;
  while(!(SPSR & (1<<SPIF)));
  return (SPDR);
}