int __cdecl _flush(_DWORD *a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax

  v1 = a1[3];
  v2 = 0;
  if ( (v1 & 3) == 2 && (v1 & 0x108) != 0 )
  {
    v3 = a1[2];
    if ( *a1 - v3 > 0 )
    {
      v4 = *a1 - v3;
      if ( sub_638801(a1[4], v3, v4) == v4 )
      {
        v5 = a1[3];
        if ( (v5 & 0x80u) != 0 )
          a1[3] = v5 & 0xFFFFFFFD;
      }
      else
      {
        a1[3] |= 0x20u;
        v2 = -1;
      }
    }
  }
  v6 = a1[2];
  a1[1] = 0;
  *a1 = v6;
  return v2;
}
