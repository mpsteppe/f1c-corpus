void __thiscall sub_5474EB(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v4; // esi
  _DWORD *i; // [esp+14h] [ebp+8h]
  unsigned int v7; // [esp+1Ch] [ebp+10h]

  v4 = (_DWORD *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[2 * this[1046]]; v4 < i; *(a4 - 1) = (double)*((unsigned __int16 *)v4 - 1) * 0.000015259022 )
  {
    *a4 = (double)(unsigned __int16)v4[1] * 0.000015259022;
    a4[1] = (double)(unsigned __int16)HIWORD(*v4) * 0.000015259022;
    v7 = (unsigned __int16)*v4;
    v4 += 2;
    a4 += 4;
    *(a4 - 2) = (double)v7 * 0.000015259022;
  }
  if ( this[4] )
    sub_54464B((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
