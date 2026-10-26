void __thiscall sub_6579E6(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *i; // edi
  double v7; // st6
  int v8; // [esp+18h] [ebp+10h]

  v4 = (unsigned __int8 *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[2 * this[26]]; v4 < i; *(a4 - 1) = (double)*(v4 - 1) * 0.0039215689 )
  {
    v8 = *v4;
    v4 += 2;
    v7 = (double)v8 * 0.0039215689;
    a4[2] = v7;
    a4[1] = v7;
    *a4 = v7;
    a4 += 4;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
