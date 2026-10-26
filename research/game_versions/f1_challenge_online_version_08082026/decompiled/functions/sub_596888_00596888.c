int __cdecl sub_596888(int a1, _DWORD *a2)
{
  int v2; // eax
  int v4; // eax

  if ( a1 == -1 )
    return -1;
  v2 = a2[3];
  if ( (v2 & 1) == 0 && ((v2 & 0x80u) == 0 || (v2 & 2) != 0) )
    return -1;
  if ( !a2[2] )
    sub_5957BD(a2);
  if ( *a2 == a2[2] )
  {
    if ( a2[1] )
      return -1;
    ++*a2;
  }
  if ( (a2[3] & 0x40) != 0 )
  {
    if ( *(_BYTE *)--*a2 != (_BYTE)a1 )
    {
      ++*a2;
      return -1;
    }
  }
  else
  {
    *(_BYTE *)--*a2 = a1;
  }
  v4 = a2[3];
  ++a2[1];
  LOBYTE(v4) = v4 & 0xEE | 1;
  a2[3] = v4;
  return (unsigned __int8)a1;
}
