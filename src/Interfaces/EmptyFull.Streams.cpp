// Implementation of empty input and full output streams

/*
  Author: Martin Eden
  Last mod.: 2026-04-13
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

using namespace me_StreamsCollection;

/*
  Read from empty input stream
*/
TBool TEmptyInputStream::Read(
  TUnit *
)
{
  return false;
}

/*
  Write to full output stream
*/
TBool TFullOutputStream::Write(
  TUnit
)
{
  return false;
}

/*
  2026-04-13
*/
