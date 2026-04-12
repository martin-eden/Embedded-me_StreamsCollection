// Number text encoder. Binary to decimal in ASCII

/*
  Author: Martin Eden
  Last mod.: 2026-04-12
*/

#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Console.h>

using namespace me_StreamsCollection;

/*
  Current guideline is that text codecs should use Console

  Rationale is that we like built-in entities separation in Console.
  We can do it manually here but then we should do it manually
  in every other text codec implementation.

  Of course if you redirected Console's output to your memory
  buffer you will capture stream with indentation spaces.
  But text codec can write as much space characters as it likes,
  there is no minimality requirement for encoding.
*/

/*
  [Interface] Write unit

  Write byte as ASCII decimal to output stream.
  Separate entities with space.
*/
TBool TByteToDecStream::Write(
  TUnit Byte
)
{
  Console.Print(Byte);
}

/*
  2026-04-12
*/
