// Adapting [me_ProgramMemory] for streams

/*
  Author: Martin Eden
  Last mod.: 2025-09-05
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_StreamTools.h>
#include <me_ProgramMemory.h>

using namespace me_StreamsCollection;

// ( Input stream
static TBool Op_GetByte(
  TAddress ValueAddr,
  TAddress ReadAddr
)
{
  return me_ProgramMemory::GetByteAt((TUint_1 *) ValueAddr, ReadAddr);
}

TBool TProgmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  return me_StreamTools::TAddrsegInputStream::Init(AddrSeg, Op_GetByte);
}
// )

/*
  2025-08-29
  2025-09-05
*/
