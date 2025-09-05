// Wrapping [me_Uart] for streams

/*
  Author: Martin Eden
  Last mod.: 2025-09-05
*/

/*
  Implementation notes

    * Connection speed is hardcoded
    * Read() will wait for data forever
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

#include <me_StreamTools.h>
#include <me_Uart.h>

using namespace me_StreamsCollection;

// UART transmission speed
const TUint_4 UartChannelSpeed_Bps = me_Uart::Speed_115k_Bps;

// ( Input stream
static TBool Op_ReadUnit(
  TAddress DataAddr
)
{
  me_Uart::WaitByte((TUint_1 *) DataAddr);

  return true;
};

TBool TUartInputStream::Init()
{
  if (!me_Uart::Init(UartChannelSpeed_Bps))
    return false;

  me_StreamTools::TReaderInputStream::Init(Op_ReadUnit);

  return true;
}
// )

// ( Output stream
static TBool Op_WriteUnit(
  TAddress DataAddr
)
{
  me_Uart::SendByte(*(TUint_1 *) DataAddr);

  return true;
}

TBool TUartOutputStream::Init()
{
  if (!me_Uart::Init(UartChannelSpeed_Bps))
    return false;

  me_StreamTools::TWriterOutputStream::Init(Op_WriteUnit);

  return true;
}
// )

/*
  2025-08-29
  2025-09-03
*/
