int __cdecl sub_58ED00(int a1, int a2, int a3)
{
  unsigned int v3; // esi
  __int64 v4; // rax

  v3 = ((4 * *(unsigned __int8 *)(a1 + 6) + 3) & 0xFFFFFFFC)
     + (((*(unsigned __int8 *)(a1 + 4) >> 2) + 3) & 0xFFFFFFFC)
     + a1
     + 8;
  v4 = (unsigned int)*(char *)(a2 + 4);
  if ( (int)v4 > 0 )
  {
    do
    {
      if ( *(_BYTE *)(a2 + HIDWORD(v4) + 8) == 0xFE )
      {
        LOBYTE(v4) = *(_BYTE *)(HIDWORD(v4) + a2 + 16);
        if ( (v4 & 0x80u) != 0LL )
          *(_DWORD *)(v3 + 4 * (v4 & 0x7F)) |= 1 << *(_BYTE *)(HIDWORD(v4) + a3);
      }
      LODWORD(v4) = *(char *)(a2 + 4);
      ++HIDWORD(v4);
    }
    while ( SHIDWORD(v4) < (int)v4 );
  }
  return v4;
}
