int __stdcall sub_646616(int a1, unsigned int a2)
{
  int result; // eax

  result = 0;
  if ( !a2 )
    return 0;
  while ( *(_BYTE *)(result + a1) != 10 )
  {
    if ( ++result >= a2 )
      return 0;
  }
  return result;
}
