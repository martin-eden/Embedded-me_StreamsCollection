// Wrapping [me_Uart] for streams

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

/*
  Interface notes

    * Read() will wait data forever
    * Init() is optional
    * Connection speed is not configurable
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_Uart.h>

using namespace me_StreamsCollection;

// Hardcoded UART transmission speed
const TUint_4 UartChannelSpeed_Bps = me_Uart::Speed_115k_Bps;

// ( Input stream
TBool TUartInputStream::Init()
{
  return me_Uart::Init(UartChannelSpeed_Bps);
}

TBool TUartInputStream::Read(
  TUnit * Unit
)
{
  me_Uart::WaitByte((TUint_1 *) Unit);

  return true;
}
// )

// ( Output stream
TBool TUartOutputStream::Init()
{
  return me_Uart::Init(UartChannelSpeed_Bps);
}

TBool TUartOutputStream::Write(
  TUnit Unit
)
{
  me_Uart::SendByte((TUint_1) Unit);

  return true;
}
// )

/*
  2025-08-29
*/
