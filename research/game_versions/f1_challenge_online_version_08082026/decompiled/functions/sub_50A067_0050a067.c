void __thiscall sub_50A067(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v5; // eax
  _BYTE *i; // edi
  double v7; // st6
  int v8; // [esp+18h] [ebp+10h]

  v5 = (_BYTE *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v5[this[1046]]; v5 < i; *(a4 - 1) = (double)v8 * 0.06666667 )
  {
    v7 = (double)(*v5 & 0xF) * 0.06666667;
    a4[2] = v7;
    a4[1] = v7;
    *a4 = v7;
    v8 = *v5++ >> 4;
    a4 += 4;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
