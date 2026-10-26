void __thiscall sub_6583A5(_DWORD *this, int a2, int a3, int a4)
{
  int *v4; // eax
  int *i; // edx
  int v7; // edi

  v4 = (int *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *(float *)(a4 - 12) = 1.0 )
  {
    v7 = *v4;
    *(float *)(a4 + 12) = 1.0;
    *(_DWORD *)a4 = v7;
    ++v4;
    *(float *)(a4 + 8) = 1.0;
    a4 += 16;
  }
  if ( this[6] )
    sub_650019((int)this, a4 - 16 * this[26]);
  if ( this[4] )
    sub_650286(this, a4 - 16 * this[26]);
}
