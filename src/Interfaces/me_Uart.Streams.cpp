// Wrapping [me_Uart] for streams

/*
  Author: Martin Eden
  Last mod.: 2025-09-03
*/

/*
  Implementation notes

    * Read() will wait for data forever
    * Init() is optional
    * Connection speed is hardcoded
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

/*
  [TFixedOperation] Read unit
*/
TBool Op_ReadUnit(
  TAddress DataAddr
)
{
  me_Uart::WaitByte((TUint_1 *) DataAddr);

  return true;
};

/*
  Init
*/
TBool TUartInputStream::Init()
{
  ReaderInputStream.Init(Op_ReadUnit);

  return me_Uart::Init(UartChannelSpeed_Bps);
}

/*
  Read
*/
TBool TUartInputStream::Read(
  TUnit * Unit
)
{
  return ReaderInputStream.Read(Unit);
}
// )

// ( Output stream

/*
  [TFixedOperation] Write unit
*/
TBool Op_WriteUnit(
  TAddress DataAddr
)
{
  me_Uart::SendByte(*(TUint_1 *) DataAddr);

  return true;
}

/*
  Init
*/
TBool TUartOutputStream::Init()
{
  WriterOutputStream.Init(Op_WriteUnit);

  return me_Uart::Init(UartChannelSpeed_Bps);
}

/*
  Write
*/
TBool TUartOutputStream::Write(
  TUnit Unit
)
{
  return WriterOutputStream.Write(Unit);
}
// )

/*
  2025-08-29
  2025-09-03
*/
