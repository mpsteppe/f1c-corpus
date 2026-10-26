// f1c  0x0050a5cb  size=142
void __thiscall sub_50A5CB(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v4; // eax
  _DWORD *i; // esi
  double v7; // st6

  v4 = (_DWORD *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[this[1046]]; v4 < i; *(a4 - 1) = (double)*((unsigned __int16 *)v4 - 1) * 0.000015259022 )
  {
    v7 = (double)(unsigned __int16)*v4++ * 0.000015259022;
    a4[2] = v7;
    a4[1] = v7;
    *a4 = v7;
    a4 += 4;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
