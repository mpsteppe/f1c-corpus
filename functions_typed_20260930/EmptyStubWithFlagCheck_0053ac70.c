char __stdcall sub_53AC70(__int16 a1, char a2)
{
  char result; // al

  result = a2;
  if ( (a2 & 4) != 0 )
    return a1 | 0x3F;
  if ( (a2 & 8) != 0 )
    return a1 & 0xC0;
  return result;
}

