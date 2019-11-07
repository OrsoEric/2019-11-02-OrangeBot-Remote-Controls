/****************************************************************************
**	INCLUDE
****************************************************************************/

#include "global.h"

/****************************************************************************
** INTERRUPT SERVICE ROUTINE
*****************************************************************************
**	In the AT4809 ISR flags have to be cleared manually
****************************************************************************/

/****************************************************************************
**	RTC Periodic Interrupt
*****************************************************************************
**	Periodic interrupt generated by the RTC from it's independent clock source
****************************************************************************/

ISR( RTC_PIT_vect )
{	
	//----------------------------------------------------------------
	//	VARS
	//----------------------------------------------------------------

	//----------------------------------------------------------------
	//	INIT
	//----------------------------------------------------------------
	
	//----------------------------------------------------------------
	//	BODY
	//----------------------------------------------------------------	
	
	//Set the System Tick
	g_isr_flags.system_tick = true;
	
	//----------------------------------------------------------------
	//	RETURN
	//----------------------------------------------------------------
	
	//Manually clear the interrupt flag
	RTC.PITINTFLAGS = RTC_PI_bm;
}

/****************************************************************************
**	USART3 RX Interrupt
*****************************************************************************
**	
****************************************************************************/

ISR( USART3_RXC_vect )
{
	//----------------------------------------------------------------
	//	VARS
	//----------------------------------------------------------------
	
	//Temp var
	uint8_t rx_data_tmp;
	
	//----------------------------------------------------------------
	//	INIT
	//----------------------------------------------------------------
	
	//----------------------------------------------------------------
	//	BODY
	//----------------------------------------------------------------
	
	//Fetch the data and clear the interrupt flag
	rx_data_tmp = USART3.RXDATAL;
	//Push byte into RS485 buffer for processing
	AT_BUF_PUSH_SAFER( rpi_rx_buf, rx_data_tmp );
	
	//----------------------------------------------------------------
	//	RETURN
	//----------------------------------------------------------------	
	
}
