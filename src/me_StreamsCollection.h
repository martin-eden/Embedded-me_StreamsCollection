// Wrapping known functionality as streams

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

/*
  At this point I have modules for UART, SRAM, Flash and EEPROM.
  Recently I've added stream interface.

  I can add stream support to them but it feels wrong.
  Their code is done and they should not try to catch up with
  new overhyped trends.

  So their public relations managers will be placed here.
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_StreamsCollection
{
  // ( UART

  // [Adapter] Input stream == [UART]
  class TUartInputStream : public IInputStream
  {
    public:
      TBool Init();

      TBool Read(TUnit * Unit) override;
  };

  // [Adapter] Output stream == [UART]
  class TUartOutputStream : public IOutputStream
  {
    public:
      TBool Init();

      TBool Write(TUnit Unit) override;
  };

  // )

  // ( Work memory (SRAM)

  // [Adapter] Input stream == [RAM] + Address segment
  class TWorkmemInputStream : public IInputStream
  {
    public:
      TBool Init(TAddressSegment MemSeg);

      TBool Read(TUnit * Unit) override;

    private:
      TAddressIterator Rator;
  };

  // [Adapter] Output stream == [RAM] + Address segment
  class TWorkmemOutputStream : public IOutputStream
  {
    public:
      TBool Init(TAddressSegment MemSeg);

      TBool Write(TUnit Unit) override;

    private:
      TAddressIterator Rator;
  };

  // )

}

/*
  2025-08-29
*/
