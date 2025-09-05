// [me_Eeprom] streams adapter

/*
  Author: Martin Eden
  Last mod.: 2025-09-05
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_StreamTools.h>
#include <me_Eeprom.h>

using namespace me_StreamsCollection;

// ( Input stream
static TBool Op_GetByte(
  TAddress ValueAddr,
  TAddress ReadAddr
)
{
  return me_Eeprom::Get((TUint_1 *) ValueAddr, ReadAddr);
}

TBool TEepromInputStream::Init(
  TAddressSegment AddrSeg
)
{
  return me_StreamTools::TAddrsegInputStream::Init(AddrSeg, Op_GetByte);
}
// )

// ( Output stream
static TBool Op_SetByte(
  TAddress ValueAddr,
  TAddress WriteAddr
)
{
  return me_Eeprom::Put(*(TUnit *) ValueAddr, WriteAddr);
}

TBool TEepromOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  return me_StreamTools::TAddrsegOutputStream::Init(AddrSeg, Op_SetByte);
}
// )

/*
  2025-08-29
  2025-09-05
*/
