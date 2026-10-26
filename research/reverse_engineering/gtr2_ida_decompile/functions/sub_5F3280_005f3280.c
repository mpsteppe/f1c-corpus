int __stdcall sub_5F3280(int a1)
{
  int result; // eax
  int v2; // esi
  int v3; // edx
  int v4; // edi
  int v5; // ecx
  int v6; // ebp
  int v7; // ebp

  result = 0;
  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 360);
    v3 = 0;
    if ( v2 > 0 )
    {
      v4 = 0;
      do
      {
        v5 = v4 + *(_DWORD *)(a1 + 364);
        v6 = *(_DWORD *)(v5 + 8);
        if ( (*(_BYTE *)v5 & 8) != 0 )
          v7 = 88 * v6;
        else
          v7 = v6 << 6;
        ++v3;
        v4 += 108;
        result += v7 + 2 * *(_DWORD *)(v5 + 36);
      }
      while ( v3 < v2 );
    }
  }
  return result;
}
