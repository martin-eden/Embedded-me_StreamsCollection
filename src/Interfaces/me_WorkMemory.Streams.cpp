// Adapting [me_WorkMemory] for streams

/*
  Author: Martin Eden
  Last mod.: 2025-09-05
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_WorkMemory.h>
#include <me_StreamTools.h>

using namespace me_StreamsCollection;

// ( Input stream
TBool TWorkmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  return Rator.Init(AddrSeg);
}

TBool TWorkmemInputStream::Read(
  TUnit * Unit
)
{
  TAddress ReadAddr;

  if (!Rator.GetNextAddr(&ReadAddr))
    return false;

  return me_WorkMemory::GetByteFrom((TUint_1 *) Unit, ReadAddr);
}
// )

// ( Output stream
TBool Op_SetByte(
  TAddress ValueAddr,
  TAddress WriteAddr
)
{
  return me_WorkMemory::SetByteAt(WriteAddr, *(TUint_1 *) ValueAddr);
}

TBool TWorkmemOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  return me_StreamTools::TAddrsegOutputStream::Init(AddrSeg, Op_SetByte);
}
// )

/*
  2025-08-26
  2025-08-29
  2025-09-04
*/
