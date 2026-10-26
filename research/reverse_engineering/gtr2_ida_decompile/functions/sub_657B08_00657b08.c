void __thiscall sub_657B08(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int16 *v4; // eax
  unsigned __int16 *i; // edx
  double v7; // st7
  int v8; // [esp+14h] [ebp+10h]

  v4 = (unsigned __int16 *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *(a4 - 1) = 1.0 )
  {
    v8 = *v4++;
    v7 = (double)v8 * 0.000015259022;
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
