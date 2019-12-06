/*
 *File:   spi.h
 *Author: Mohan
 *
 * Created on November 23, 2019, 8:54 AM
 */

/*INCLUDE GUARD===============================================================*/

#ifndef SPI_H
#define	SPI_H

/*HEADER FILES================================================================*/

#include <avr/io.h>

/*PUBLIC MACRO FUNCTION AND SUBSTITUTION======================================*/

#ifdef	__cplusplus
extern "C" {
#endif

#define SPI_PORT 	PORTB
#define SPI_DDR 	DDRB
//PINS 
#define SCK_POS 	PB5
#define MISO_POS 	PB4
#define MOSI_POS	PB3
#define CS_POS		PB2
//CS CONFIG
#define CS_HIGH() (SPI_PORT|=(1<<CS_POS))
#define CS_LOW() (SPI_PORT&=(~(1<<CS_POS)))

/*PUBLIC FUNCTION DEFINITIONS AND PROTOTYPING=================================*/

void SPI_Init(void);
void SPI_Close(void);
uint8_t SPI_Write(uint8_t data);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

