void __thiscall sub_54675F(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v5; // eax
  _BYTE *i; // edi
  int v7; // [esp+18h] [ebp+10h]

  v5 = (_BYTE *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v5[2 * this[1046]]; v5 < i; *(a4 - 1) = (float)v7 )
  {
    *a4 = (double)((*(unsigned __int16 *)v5 >> 10) & 0x1F) * 0.032258064;
    a4 += 4;
    *(a4 - 3) = (double)((*(unsigned __int16 *)v5 >> 5) & 0x1F) * 0.032258064;
    *(a4 - 2) = (double)(*v5 & 0x1F) * 0.032258064;
    v7 = *(_WORD *)v5 >> 15;
    v5 += 2;
  }
  if ( this[4] )
    sub_54464B((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
