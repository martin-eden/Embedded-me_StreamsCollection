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

// ( Input stream
TBool TEepromInputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!me_AddrsegTools::IsValid(AddrSeg))
    return false;

  if (
    !me_AddrsegTools::IsInside(
      AddrSeg,
      me_Eeprom::Description::Segment
    )
  )
    return false;

  if (!TAddrsegStream::Init(AddrSeg, me_Eeprom::Core::Get))
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
  if (!me_AddrsegTools::IsValid(AddrSeg))
    return false;

  if (
    !me_AddrsegTools::IsInside(
      AddrSeg,
      me_Eeprom::Description::Segment
    )
  )
    return false;

  if (!TAddrsegStream::Init(AddrSeg, me_Eeprom::Core::Put))
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
