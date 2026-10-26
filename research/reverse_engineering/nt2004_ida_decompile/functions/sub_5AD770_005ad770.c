void __thiscall sub_5AD770(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // edi
  int i; // ebp
  int v7; // esi

  v4 = *(_DWORD *)(this[7] + 20);
  if ( a3 <= v4 )
    this[2] = a3;
  else
    this[2] = v4 - 1;
  v5 = this[6];
  for ( i = 0; i < this[5]; ++i )
  {
    if ( (unsigned __int8)*(_DWORD *)v5 != 255 )
    {
      v7 = *(_DWORD *)(44 * (unsigned __int8)*(_DWORD *)v5 + *(_DWORD *)(this[7] + 16) + 40) + 32 * this[2];
      sub_590850((float *)(v7 + 16), (float *)(v5 + 4));
      *(_DWORD *)(v5 + 52) = *(_DWORD *)(v7 + 4);
      *(_DWORD *)(v5 + 56) = *(_DWORD *)(v7 + 8);
      *(_DWORD *)(v5 + 60) = *(_DWORD *)(v7 + 12);
    }
    v5 += 136;
  }
  this[1] |= 0x10000u;
  if ( a2 )
    sub_59DFD0(*(_DWORD **)(a2 + 312), 64, 32, 0);
}
