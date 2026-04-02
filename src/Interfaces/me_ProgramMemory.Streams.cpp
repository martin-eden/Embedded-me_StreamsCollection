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

// ( Input stream
TBool TProgmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!me_AddrsegTools::IsValid(AddrSeg))
    return false;

  if (
    !me_AddrsegTools::IsInside(
      AddrSeg,
      me_ProgramMemory::Description::Segment
    )
  )
    return false;

  if (!TAddrsegStream::Init(AddrSeg, me_ProgramMemory::Core::GetByteAt))
    return false;

  return true;
}

TBool TProgmemInputStream::Init()
{
  return Init(me_ProgramMemory::Description::Segment);
}
// )

/*
  2025-08-29
  2025-09-05
  2026-03-31
*/
