int __cdecl sub_58A05A(_DWORD *a1)
{
  int v1; // ebx
  const void *v2; // eax
  DWORD v3; // edi
  int v4; // eax
  int v5; // eax

  v1 = 0;
  if ( (a1[3] & 3) == 2 && (a1[3] & 0x108) != 0 )
  {
    v2 = (const void *)a1[2];
    if ( *a1 - (int)v2 > 0 )
    {
      v3 = *a1 - (_DWORD)v2;
      if ( sub_58E22B(a1[4], v2, v3) == v3 )
      {
        v4 = a1[3];
        if ( (v4 & 0x80u) != 0 )
        {
          LOBYTE(v4) = v4 & 0xFD;
          a1[3] = v4;
        }
      }
      else
      {
        a1[3] |= 0x20u;
        v1 = -1;
      }
    }
  }
  v5 = a1[2];
  a1[1] = 0;
  *a1 = v5;
  return v1;
}
