char __cdecl sub_58D060(int a1)
{
  int v1; // edi
  _BYTE *v2; // ebp
  signed int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // ecx
  _BYTE *v6; // edx
  unsigned int v7; // esi
  char v8; // bl

  v1 = *(unsigned __int8 *)(a1 + 5);
  v2 = (_BYTE *)(((v1 * ((*(_BYTE *)(a1 + 4) & 0xF) + 2) + 15) & 0xFFFFFFFC) + a1 + 4 * (*(_BYTE *)(a1 + 4) & 0xF));
  LOBYTE(v3) = *v2;
  v4 = (unsigned __int8)*v2;
  if ( *v2 )
  {
    v3 = v1 * (dword_7FF9E4 % v4 + 1) / v4 - dword_7FF9E4 % v4 * v1 / v4;
    v5 = (dword_7FF9E4 % v4 * v1 / v4) & 7;
    if ( v3 > 0 )
    {
      v6 = &v2[((dword_7FF9E4 % v4 * v1 / v4) >> 3) + 1];
      v7 = v1 * (dword_7FF9E4 % v4 + 1) / v4 - dword_7FF9E4 % v4 * v1 / v4;
      do
      {
        LOBYTE(v3) = 1 << v5;
        v8 = (1 << v5++) | *v6;
        *v6 = v8;
        if ( v5 == 8 )
        {
          v5 = 0;
          ++v6;
        }
        --v7;
      }
      while ( v7 );
    }
  }
  return v3;
}
