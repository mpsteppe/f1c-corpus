// f1c  0x005096d0  size=166
void __thiscall sub_5096D0(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned int v4; // eax
  unsigned int i; // esi
  double v7; // st6

  v4 = this[6] + a3 * this[1045] + a2 * this[1044];
  for ( i = v4 + 4 * this[1046]; v4 < i; *(a4 - 1) = (double)*(unsigned __int8 *)(v4 - 1) * 0.0039215689 )
  {
    *a4 = (double)*(unsigned __int8 *)(v4 + 2) * 0.0039215689;
    a4[1] = (double)*(unsigned __int8 *)(v4 + 1) * 0.0039215689;
    v7 = (double)(unsigned __int8)*(_DWORD *)v4;
    v4 += 4;
    a4 += 4;
    *(a4 - 2) = v7 * 0.0039215689;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
