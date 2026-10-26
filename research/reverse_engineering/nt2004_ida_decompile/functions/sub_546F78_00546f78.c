void __thiscall sub_546F78(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v5; // eax
  _BYTE *i; // edi
  int v7; // [esp+18h] [ebp+10h]
  int v8; // [esp+18h] [ebp+10h]

  v5 = (_BYTE *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v5[2 * this[1046]]; v5 < i; *(a4 - 1) = (double)v8 * 0.015873017 )
  {
    v7 = (char)(8 * (*(unsigned __int16 *)v5 >> 5)) >> 3;
    *a4 = (double)((char)(8 * *v5) >> 3) * 0.0625;
    a4 += 4;
    *(a4 - 3) = (double)v7 * 0.0625;
    *(a4 - 2) = 0.0;
    v8 = *(_WORD *)v5 >> 10;
    v5 += 2;
  }
  if ( this[4] )
    sub_54464B((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
