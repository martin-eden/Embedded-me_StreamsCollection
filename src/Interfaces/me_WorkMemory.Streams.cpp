// Adapting [me_WorkMemory] for streams

/*
  Author: Martin Eden
  Last mod.: 2025-09-04
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

#include <me_WorkMemory.h>

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
TBool TWorkmemOutputStream::Init(
  TAddressSegment AddrSeg
)
{
  return Rator.Init(AddrSeg);
}

TBool TWorkmemOutputStream::Write(
  TUnit Unit
)
{
  TAddress WriteAddr;

  if (!Rator.GetNextAddr(&WriteAddr))
    return false;

  return me_WorkMemory::SetByteAt(WriteAddr, (TUint_1) Unit);
}

TAddress TWorkmemOutputStream::GetWriteAddr()
{
  return Rator.GetAddr();
}

TBool TWorkmemOutputStream::IsFull()
{
  return Rator.IsDone();
}
// )

/*
  2025-08-26
  2025-08-29
  2025-09-04
*/
