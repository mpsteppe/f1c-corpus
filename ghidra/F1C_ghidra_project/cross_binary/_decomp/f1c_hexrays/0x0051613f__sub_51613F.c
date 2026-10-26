// f1c  0x0051613f  size=158
int __cdecl sub_51613F(_DWORD *a1, unsigned int a2, int a3, signed int a4)
{
  int v4; // edi
  signed int v5; // esi
  unsigned int v7; // edi
  _DWORD *v8; // eax
  signed int v9; // ecx
  int v11; // [esp+24h] [ebp+14h]

  v4 = a1[1];
  v5 = 0x3B9AC9F0u / (a3 << 7);
  if ( v5 <= 0 )
  {
    *(_DWORD *)(*a1 + 20) = 69;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( v5 >= a4 )
    v5 = a4;
  *(_DWORD *)(v4 + 76) = v5;
  v7 = 0;
  v11 = sub_515F23(a1, a2, 4 * a4);
  while ( v7 < a4 )
  {
    if ( v5 >= a4 - v7 )
      v5 = a4 - v7;
    v8 = sub_51601F(a1, a2, (a3 * v5) << 7);
    if ( v5 )
    {
      v9 = v5;
      do
      {
        *(_DWORD *)(v11 + 4 * v7) = v8;
        v8 += 32 * a3;
        ++v7;
        --v9;
      }
      while ( v9 );
    }
  }
  return v11;
}
