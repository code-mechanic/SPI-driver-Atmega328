/* 
 * File:   ADC_MCP3004.h
 * Author: Mohan
 *
 * Created on November 23, 2019, 9:48 AM
 */
/*INCLUDE GUARD===============================================================*/

#ifndef ADC_MCP3004_H
#define	ADC_MCP3004_H

/*HEADER FILES================================================================*/

/*PUBLIC MACRO FUNCTION AND SUBSTITUTION======================================*/

#ifdef  __cplusplus
extern "C" {
#endif

/*PUBLIC FUNCTION DEFINITIONS AND PROTOTYPING=================================*/

void ADC_Init();
uint16_t ADC_Read(uint8_t ch);

#ifdef	__cplusplus
}
#endif

#endif  /* ADC_MCP3004_H */