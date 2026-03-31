// Adapting [me_ProgramMemory] for streams

/*
  Author: Martin Eden
  Last mod.: 2026-03-31
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
  if (
    !me_StreamTools::TAddrsegInputStream::Init(
      AddrSeg,
      me_ProgramMemory::Core::GetByteAt
    )
  )
    return false;

  if (
    me_AddrsegTools::GetEndAddr(AddrSeg) >
    me_ProgramMemory::Description::MaxAddress
  )
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
