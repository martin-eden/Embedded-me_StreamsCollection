// [me_StreamsCollection] test

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_Console.h>

#include <me_StreamTools.h>
#include <me_Delays.h>

void DummyTest()
{
}

void UartEchoTest()
{
  /*
    Attention! This is infinite test
  */

  me_StreamsCollection::TUartInputStream UartIn;
  me_StreamsCollection::TUartOutputStream UartOut;

  const TUint_4 UartSpeed = 115200;

  if (!UartIn.Init(UartSpeed))
    Console.Print("Failed to setup UART for input");

  if (!UartOut.Init(UartSpeed))
    Console.Print("Failed to setup UART for output");

  me_StreamTools::CopyStreamTo(&UartIn, &UartOut);
}

void setup()
{
  Console.Init();

  Console.Print("[me_StreamsCollection] test");

  me_Delays::Delay_Ms(20);

  DummyTest();
  UartEchoTest();

  Console.Print("Done");
}

void loop()
{
}

/*
  2025-08-29
*/
