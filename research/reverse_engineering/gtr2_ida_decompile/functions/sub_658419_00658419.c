void __thiscall sub_658419(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // eax
  _DWORD *i; // edx
  int v7; // edi

  v4 = (_DWORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[2 * this[26]]; v4 < i; a4 += 16 )
  {
    *(_DWORD *)a4 = *v4;
    v7 = v4[1];
    *(float *)(a4 + 12) = 1.0;
    *(_DWORD *)(a4 + 4) = v7;
    *(float *)(a4 + 8) = 1.0;
    v4 += 2;
  }
  if ( this[6] )
    sub_650019((int)this, a4 - 16 * this[26]);
  if ( this[4] )
    sub_650286(this, a4 - 16 * this[26]);
}
