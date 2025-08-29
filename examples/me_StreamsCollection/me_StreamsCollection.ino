// [me_StreamsCollection] test

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_Console.h>

#include <me_WorkmemTools.h>
#include <me_StreamTools.h>
#include <me_Delays.h>

void MemReadTest()
{
  TAddressSegment TestDataSeg =
    me_WorkmemTools::FromAsciiz("TEST DATA\n");

  me_StreamsCollection::TWorkmemInputStream MemIn;
  me_StreamsCollection::TUartOutputStream UartOut;

  Console.Print("( Memory data");

  if (!MemIn.Init(TestDataSeg))
    Console.Print("Failed to setup memory input stream");

  me_StreamTools::CopyStreamTo(&MemIn, &UartOut);

  Console.Print(")");
}

void UartEchoTest()
{
  /*
    Attention! This is infinite test
  */

  me_StreamsCollection::TUartInputStream UartIn;
  me_StreamsCollection::TUartOutputStream UartOut;

  Console.Print("( Infinite UART echo");

  // UART.Init() will flush current output buffer. Giving time to transfer
  me_Delays::Delay_Ms(20);

  if (!UartIn.Init())
    Console.Print("Failed to setup UART for input");

  if (!UartOut.Init())
    Console.Print("Failed to setup UART for output");

  me_StreamTools::CopyStreamTo(&UartIn, &UartOut);

  Console.Print(")");  // lol
}

void setup()
{
  Console.Init();

  Console.Print("[me_StreamsCollection] test");

  MemReadTest();
  UartEchoTest();

  Console.Print("Done");
}

void loop()
{
}

/*
  2025-08-29
*/
