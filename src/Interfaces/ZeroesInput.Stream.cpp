// Zeroes emitter

/*
  Author: Martin Eden
  Last mod.: 2026-04-11
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>

using namespace me_StreamsCollection;

/*
  [Emitter] Zeroes emitter
*/
TBool TZeroesInputStream::Read(
  TUnit * Unit
)
{
  *Unit = (TUnit) 0;

  return true;
}

/*
  2025-08-26
  2026-04-11
*/
