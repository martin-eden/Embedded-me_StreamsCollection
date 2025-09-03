// Umbrella module providing stream interface to memories and UART

/*
  Author: Martin Eden
  Last mod.: 2025-09-03
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
  // ( UART

  // [Adapter] Input stream == [UART]
  class TUartInputStream : public IInputStream
  {
    public:
      TBool Init();

      TBool Read(TUnit * Unit) override;

    private:
      me_StreamTools::TReaderInputStream ReaderInputStream;
  };

  // [Adapter] Output stream == [UART]
  class TUartOutputStream : public IOutputStream
  {
    public:
      TBool Init();

      TBool Write(TUnit Unit) override;

    private:
      me_StreamTools::TWriterOutputStream WriterOutputStream;
  };

  // )

  // ( Work memory (SRAM)

  // [Adapter] Input stream == [RAM] + Address segment
  class TWorkmemInputStream : public IInputStream
  {
    public:
      TBool Init(TAddressSegment AddrSeg);

      TBool Read(TUnit * Unit) override;

    private:
      TAddrsegIterator Rator;
  };

  // [Adapter] Output stream == [RAM] + Address segment
  class TWorkmemOutputStream : public IOutputStream
  {
    public:
      TBool Init(TAddressSegment AddrSeg);

      TBool Write(TUnit Unit) override;

    private:
      TAddrsegIterator Rator;
  };

  // )

  // ( Program memory (Flash)

  // [Adapter] Input stream == [Flash] + Address segment
  class TProgmemInputStream : public IInputStream
  {
    public:
      TBool Init(TAddressSegment AddrSeg);

      TBool Read(TUnit * Unit) override;

    private:
      TAddrsegIterator Rator;
  };

  // )

  // [Adapter] Input stream == [EEPROM] + Address segment
  class TEepromInputStream : public IInputStream
  {
    public:
      TBool Init(TAddressSegment AddrSeg);

      TBool Read(TUnit * Unit) override;

    private:
      TAddrsegIterator Rator;
  };

  // [Adapter] Output stream == [EEPROM] + Address segment
  class TEepromOutputStream : public IOutputStream
  {
    public:
      TBool Init(TAddressSegment AddrSeg);

      TBool Write(TUnit Unit) override;

    private:
      TAddrsegIterator Rator;
  };

  // )
}

/*
  2025-08-29
  2025-09-03
*/
