// Adapting [me_ProgramMemory] for streams

/*
  Author: Martin Eden
  Last mod.: 2025-08-30
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_ProgramMemory.h>

using namespace me_StreamsCollection;

// ( Input stream
TBool TProgmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  return Rator.Init(AddrSeg);
}

TBool TProgmemInputStream::Read(
  TUnit * Unit
)
{
  TAddress ReadAddr;

  if (!Rator.GetNextAddr(&ReadAddr))
    return false;

  return me_ProgramMemory::GetByteAt((TUint_1 *) Unit, ReadAddr);
}
// )

/*
  2025-08-29
*/
