void __thiscall sub_657210(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v4; // eax
  _DWORD *i; // edx
  double v7; // st6

  v4 = (_DWORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *(a4 - 1) = (double)*((unsigned __int8 *)v4 - 1) * 0.0039215689 )
  {
    v7 = (double)(unsigned __int8)*v4++;
    *a4 = v7 * 0.0039215689;
    a4 += 4;
    *(a4 - 3) = (double)*((unsigned __int8 *)v4 - 3) * 0.0039215689;
    *(a4 - 2) = (double)*((unsigned __int8 *)v4 - 2) * 0.0039215689;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
