// Umbrella module providing stream interface to memories and UART

/*
  Author: Martin Eden
  Last mod.: 2026-04-12
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
#include <me_StreamTools.h>

namespace me_StreamsCollection
{
  // [Emitter] Input stream == Zeroes
  class TZeroesInputStream : public IInputStream
  {
    public:
      TBool Read(TUnit *) override;
  };

  // ( UART stream

  // [Adapter] Input stream == [UART]
  class TUartInputStream : public me_StreamTools::TReaderInputStream
  {
    public:
      TBool Init();
  };

  // [Adapter] Output stream == [UART]
  class TUartOutputStream : public me_StreamTools::TWriterOutputStream
  {
    public:
      TBool Init();
  };

  // )

  // ( Work memory (SRAM)

  // [Adapter] Input stream == [RAM] + Address segment
  class TWorkmemInputStream : public me_StreamTools::TAddrsegInputStream
  {
    public:
      TBool Init(TAddressSegment);
      TBool Init();
  };

  // [Adapter] Output stream == [RAM] + Address segment
  class TWorkmemOutputStream : public me_StreamTools::TAddrsegOutputStream
  {
    public:
      TBool Init(TAddressSegment);
      TBool Init();
  };

  // )

  // ( Program memory (Flash)

  // [Adapter] Input stream == [Flash] + Address segment
  class TProgmemInputStream : public me_StreamTools::TAddrsegInputStream
  {
    public:
      TBool Init(TAddressSegment);
      TBool Init();
  };

  // )

  // ( EEPROM memory

  // [Adapter] Input stream == [EEPROM] + Address segment
  class TEepromInputStream : public me_StreamTools::TAddrsegInputStream
  {
    public:
      TBool Init(TAddressSegment);
      TBool Init();
  };

  // [Adapter] Output stream == [EEPROM] + Address segment
  class TEepromOutputStream : public me_StreamTools::TAddrsegOutputStream
  {
    public:
      TBool Init(TAddressSegment);
      TBool Init();
  };

  // )
}

/*
  2025 # # # # #
  2026-03-31
  2026-04-11
*/
