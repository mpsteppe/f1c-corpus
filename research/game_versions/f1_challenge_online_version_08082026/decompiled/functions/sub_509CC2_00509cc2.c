void __thiscall sub_509CC2(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *i; // esi
  int v7; // [esp+14h] [ebp+10h]

  v4 = (unsigned __int8 *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[this[1046]]; v4 < i; *(a4 - 1) = (double)v7 * 0.0039215689 )
  {
    *a4 = 0.0;
    a4 += 4;
    *(a4 - 3) = 0.0;
    *(a4 - 2) = 0.0;
    v7 = *v4++;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
