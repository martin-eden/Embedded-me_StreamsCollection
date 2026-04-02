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

// ( Input stream
TBool TWorkmemInputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!me_AddrsegTools::IsValid(AddrSeg))
    return false;

  if (
    !me_AddrsegTools::IsInside(
      AddrSeg,
      me_WorkMemory::Description::Segment
    )
  )
    return false;

  if (
    !me_StreamTools::TAddrsegInputStream::Init(
      AddrSeg,
      me_WorkMemory::Core::GetByteFrom
    )
  )
    return false;

  return true;
}

TBool TWorkmemInputStream::Init()
{
  return Init(me_WorkMemory::Description::Segment);
}
// )

// ( Output stream
TBool TWorkmemOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  if (!me_AddrsegTools::IsValid(AddrSeg))
    return false;

  if (
    !me_AddrsegTools::IsInside(
      AddrSeg,
      me_WorkMemory::Description::Segment
    )
  )
    return false;

  if (
    !me_StreamTools::TAddrsegOutputStream::Init(
      AddrSeg,
      me_WorkMemory::Core::SetByteAt
    )
  )
    return false;

  return true;
}

TBool TWorkmemOutputStream::Init()
{
  return Init(me_WorkMemory::Description::Segment);
}
// )

/*
  2025-08-26
  2025-08-29
  2025-09-04
  2026-03-31
*/
