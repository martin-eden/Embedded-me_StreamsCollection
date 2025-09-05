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
TBool Op_GetByte(
  TAddress ValueAddr,
  TAddress ReadAddr
)
{
  return me_WorkMemory::GetByteFrom((TUint_1 *) ValueAddr, ReadAddr);
}

TBool TWorkmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  return me_StreamTools::TAddrsegInputStream::Init(AddrSeg, Op_GetByte);
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
