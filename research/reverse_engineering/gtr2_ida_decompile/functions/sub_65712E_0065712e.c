void __thiscall sub_65712E(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v4; // eax
  _DWORD *i; // edi
  double v7; // st6

  v4 = (_DWORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *(a4 - 1) = v7 * 0.33333334 )
  {
    *a4 = (double)(*v4 & 0x3FF) * 0.00097751711;
    a4[1] = (double)((*v4 >> 10) & 0x3FF) * 0.00097751711;
    a4[2] = (double)((*v4 >> 20) & 0x3FF) * 0.00097751711;
    v7 = (double)(*v4++ >> 30);
    a4 += 4;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
