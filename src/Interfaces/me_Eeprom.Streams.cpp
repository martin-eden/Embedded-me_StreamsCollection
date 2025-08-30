// [me_Eeprom] streams adapter

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_Eeprom.h>

using namespace me_StreamsCollection;

// ( Input stream
TBool TEepromInputStream::Init(
  TAddressSegment AddrSeg
)
{
  return Rator.Init(AddrSeg);
}

TBool TEepromInputStream::Read(
  TUnit * Unit
)
{
  TAddress ReadAddr;

  if (!Rator.GetNextAddr(&ReadAddr))
    return false;

  return me_Eeprom::Get((TUint_1 *) Unit, ReadAddr);
}
// )

// ( Output stream
TBool TEepromOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  return Rator.Init(AddrSeg);
}

TBool TEepromOutputStream::Write(
  TUnit Unit
)
{
  TAddress WriteAddr;

  if (!Rator.GetNextAddr(&WriteAddr))
    return false;

  return me_Eeprom::Put((TUint_1) Unit, WriteAddr);
}
// )

/*
  2025-08-29
*/
