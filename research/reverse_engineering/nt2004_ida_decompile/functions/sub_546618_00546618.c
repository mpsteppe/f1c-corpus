void __thiscall sub_546618(_DWORD *this, int a2, int a3, float *a4)
{
  _WORD *v5; // eax
  _WORD *i; // edi
  int v7; // [esp+18h] [ebp+10h]

  v5 = (_WORD *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v5[this[1046]]; v5 < i; *(a4 - 1) = 1.0 )
  {
    *a4 = (double)(*v5 >> 11) * 0.032258064;
    a4 += 4;
    *(a4 - 3) = (double)(((unsigned __int16)*v5 >> 5) & 0x3F) * 0.015873017;
    v7 = *(_BYTE *)v5++ & 0x1F;
    *(a4 - 2) = (double)v7 * 0.032258064;
  }
  if ( this[4] )
    sub_54464B((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
