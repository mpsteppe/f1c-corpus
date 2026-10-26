void __thiscall sub_5468BE(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v4; // eax
  _DWORD *i; // edi
  double v7; // st6

  v4 = (_DWORD *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[this[1046]]; v4 < i; *(a4 - 1) = v7 * 0.33333334 )
  {
    *a4 = (double)(*v4 & 0x3FF) * 0.00097751711;
    a4[1] = (double)((*v4 >> 10) & 0x3FF) * 0.00097751711;
    a4[2] = (double)((*v4 >> 20) & 0x3FF) * 0.00097751711;
    v7 = (double)(*v4++ >> 30);
    a4 += 4;
  }
  if ( this[4] )
    sub_54464B((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
