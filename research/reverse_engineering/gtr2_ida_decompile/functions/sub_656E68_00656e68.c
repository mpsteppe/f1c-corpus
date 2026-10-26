void __thiscall sub_656E68(_DWORD *this, int a2, int a3, float *a4)
{
  _WORD *v4; // eax
  _WORD *i; // edi
  int v7; // [esp+18h] [ebp+10h]

  v4 = (_WORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *(a4 - 1) = 1.0 )
  {
    *a4 = (double)(*v4 >> 11) * 0.032258064;
    a4 += 4;
    *(a4 - 3) = (double)(((unsigned __int16)*v4 >> 5) & 0x3F) * 0.015873017;
    v7 = *(_BYTE *)v4++ & 0x1F;
    *(a4 - 2) = (double)v7 * 0.032258064;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
