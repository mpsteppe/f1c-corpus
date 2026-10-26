int __cdecl _dosmaperr(unsigned int a1)
{
  unsigned int i; // esi
  int result; // eax

  *(_DWORD *)(_getptd() + 12) = a1;
  for ( i = 0; i < 0x2D; ++i )
  {
    if ( a1 == dword_912B10[2 * i] )
    {
      result = _getptd();
      *(_DWORD *)(result + 8) = dword_912B14[2 * i];
      return result;
    }
  }
  if ( a1 < 0x13 || a1 > 0x24 )
  {
    if ( a1 < 0xBC || a1 > 0xCA )
    {
      result = _getptd();
      *(_DWORD *)(result + 8) = 22;
    }
    else
    {
      result = _getptd();
      *(_DWORD *)(result + 8) = 8;
    }
  }
  else
  {
    result = _getptd();
    *(_DWORD *)(result + 8) = 13;
  }
  return result;
}
