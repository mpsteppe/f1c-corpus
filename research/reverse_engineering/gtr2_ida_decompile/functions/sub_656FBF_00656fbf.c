void __thiscall sub_656FBF(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v4; // eax
  _BYTE *i; // edi
  int v7; // [esp+18h] [ebp+10h]

  v4 = (_BYTE *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[2 * this[26]]; v4 < i; *(a4 - 1) = (float)v7 )
  {
    *a4 = (double)((*(unsigned __int16 *)v4 >> 10) & 0x1F) * 0.032258064;
    a4 += 4;
    *(a4 - 3) = (double)((*(unsigned __int16 *)v4 >> 5) & 0x1F) * 0.032258064;
    *(a4 - 2) = (double)(*v4 & 0x1F) * 0.032258064;
    v7 = *(_WORD *)v4 >> 15;
    v4 += 2;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
