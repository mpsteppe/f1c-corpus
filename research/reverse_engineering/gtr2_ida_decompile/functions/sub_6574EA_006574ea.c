void __thiscall sub_6574EA(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v5; // esi
  double v7; // st7
  double v8; // st6
  _DWORD *v9; // [esp+14h] [ebp+8h]

  v5 = (_DWORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  v9 = &v5[2 * this[26]];
  if ( v5 < v9 )
  {
    v7 = 0.000015259022;
    do
    {
      *a4 = (double)(unsigned __int16)*v5 * v7;
      a4[1] = (double)(unsigned __int16)HIWORD(*v5) * v7;
      v7 = 0.000015259022;
      v8 = (double)(unsigned __int16)v5[1];
      v5 += 2;
      a4 += 4;
      *(a4 - 2) = v8 * 0.000015259022;
      *(a4 - 1) = (double)*((unsigned __int16 *)v5 - 1) * 0.000015259022;
    }
    while ( v5 < v9 );
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
