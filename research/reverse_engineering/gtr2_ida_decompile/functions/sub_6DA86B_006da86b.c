_DWORD *__stdcall sub_6DA86B(int a1, _BYTE *a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx

  v4 = *(_DWORD *)(a1 + 5812);
  if ( v4 <= 13 )
  {
    *(_WORD *)(a1 + 5808) |= a4 << v4;
    *(_DWORD *)(a1 + 5812) = v4 + 3;
  }
  else
  {
    v5 = a4 << v4;
    v6 = *(_DWORD *)(a1 + 8);
    *(_WORD *)(a1 + 5808) |= v5;
    *(_BYTE *)(v6 + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
    *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
    v7 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v7 - 13;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)a4 >> (16 - v7);
  }
  return sub_6DA4DD(a1, a2, a3, 1);
}
