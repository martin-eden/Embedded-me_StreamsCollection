// Adapting [me_WorkMemory] for streams

/*
  Author: Martin Eden
  Last mod.: 2026-04-02
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_AddrsegTools.h>
#include <me_StreamTools.h>
#include <me_WorkMemory.h>

using namespace me_StreamsCollection;

const TMethod
  Op_Get = me_WorkMemory::Core::GetByteFrom,
  Op_Put = me_WorkMemory::Core::SetByteAt;
const TAddressSegment
  MemorySegment = me_WorkMemory::Description::Segment;

// ( Input stream
TBool TWorkmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!TAddrsegStream::Init(AddrSeg, Op_Get))
    return false;

  if (!me_AddrsegTools::IsInside(AddrSeg, MemorySegment))
    return false;

  return true;
}

TBool TWorkmemInputStream::Init()
{
  return Init(MemorySegment);
}
// )

// ( Output stream
TBool TWorkmemOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!TAddrsegStream::Init(AddrSeg, Op_Put))
    return false;

  if (!me_AddrsegTools::IsInside(AddrSeg, MemorySegment))
    return false;

  return true;
}

TBool TWorkmemOutputStream::Init()
{
  return Init(MemorySegment);
}
// )

/*
  2025 # # #
  2026-03-31
  2026-04-02
*/
