// Adapting [me_ProgramMemory] for streams

/*
  Author: Martin Eden
  Last mod.: 2026-04-02
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_AddrsegTools.h>
#include <me_StreamTools.h>
#include <me_ProgramMemory.h>

using namespace me_StreamsCollection;

const TMethod
  Op_Get = me_ProgramMemory::Core::GetByteAt;
const TAddressSegment
  MemorySegment = me_ProgramMemory::Description::Segment;

// ( Input stream
TBool TProgmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!TAddrsegStream::Init(AddrSeg, Op_Get))
    return false;

  if (!me_AddrsegTools::IsInside(AddrSeg, MemorySegment))
    return false;

  return true;
}

TBool TProgmemInputStream::Init()
{
  return Init(MemorySegment);
}
// )

/*
  2025 # #
  2026-03-31
  2026-04-02
*/
