// [me_Eeprom] streams adapter

/*
  Author: Martin Eden
  Last mod.: 2026-04-02
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_AddrsegTools.h>
#include <me_StreamTools.h>
#include <me_Eeprom.h>

using namespace me_StreamsCollection;

const TMethod
  Op_Get = me_Eeprom::Core::Get,
  Op_Put = me_Eeprom::Core::Put;
const TAddressSegment
  MemorySegment = me_Eeprom::Description::Segment;

// ( Input stream
TBool TEepromInputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!TAddrsegStream::Init(AddrSeg, Op_Get))
    return false;

  if (!me_AddrsegTools::IsInside(AddrSeg, MemorySegment))
    return false;

  return true;
}

TBool TEepromInputStream::Init()
{
  return Init(MemorySegment);
}
// )

// ( Output stream
TBool TEepromOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!TAddrsegStream::Init(AddrSeg, Op_Put))
    return false;

  if (!me_AddrsegTools::IsInside(AddrSeg, MemorySegment))
    return false;

  return true;
}

TBool TEepromOutputStream::Init()
{
  return Init(MemorySegment);
}
// )

/*
  2025 # #
  2026-03-31
  2026-04-02
*/
