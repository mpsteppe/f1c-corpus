int __stdcall sub_67B3C8(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int result; // eax

  result = 0;
  if ( a1 && a2 && (*(_BYTE *)(a2 + 8) & 0x10) != 0 )
  {
    if ( *(_BYTE *)(a2 + 25) == 3 )
    {
      if ( a3 )
      {
        *a3 = *(_DWORD *)(a2 + 48);
        result = 16;
      }
      if ( a5 )
        *a5 = a2 + 52;
    }
    else
    {
      if ( a5 )
      {
        *a5 = a2 + 52;
        result = 16;
      }
      if ( a3 )
        *a3 = 0;
    }
    if ( a4 )
    {
      *a4 = *(unsigned __int16 *)(a2 + 22);
      return result | 0x10;
    }
  }
  return result;
}
