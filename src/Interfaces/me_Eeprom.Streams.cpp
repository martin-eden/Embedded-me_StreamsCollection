// [me_Eeprom] streams adapter

/*
  Author: Martin Eden
  Last mod.: 2026-03-31
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_AddrsegTools.h>
#include <me_StreamTools.h>
#include <me_Eeprom.h>

using namespace me_StreamsCollection;

// ( Input stream
TBool TEepromInputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (
    !me_StreamTools::TAddrsegInputStream::Init(
      AddrSeg,
      me_Eeprom::Core::Get
    )
  )
    return false;

  if (
    me_AddrsegTools::GetEndAddr(AddrSeg) >
    me_Eeprom::Description::MaxAddress
  )
    return false;

  return true;
}

TBool TEepromInputStream::Init()
{
  return Init(me_Eeprom::Description::Segment);
}
// )

// ( Output stream
TBool TEepromOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (
    !me_StreamTools::TAddrsegOutputStream::Init(
      AddrSeg,
      me_Eeprom::Core::Put
    )
  )
    return false;

  if (
    me_AddrsegTools::GetEndAddr(AddrSeg) >
    me_Eeprom::Description::MaxAddress
  )
    return false;

  return true;
}

TBool TEepromOutputStream::Init()
{
  return Init(me_Eeprom::Description::Segment);
}
// )

/*
  2025-08-29
  2025-09-05
  2026-03-31
*/
