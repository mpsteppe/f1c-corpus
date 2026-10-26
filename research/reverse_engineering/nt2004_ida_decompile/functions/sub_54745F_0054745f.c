void __thiscall sub_54745F(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int16 *v4; // eax
  unsigned __int16 *i; // esi
  int v7; // [esp+14h] [ebp+10h]

  v4 = (unsigned __int16 *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = (unsigned __int16 *)((char *)v4 + this[1049]); v4 < i; *(a4 - 1) = 1.0 )
  {
    *a4 = (double)v4[2] * 0.000015259022;
    a4 += 4;
    *(a4 - 3) = (double)v4[1] * 0.000015259022;
    v7 = *v4;
    v4 += 3;
    *(a4 - 2) = (double)v7 * 0.000015259022;
  }
  if ( this[4] )
    sub_54464B((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
