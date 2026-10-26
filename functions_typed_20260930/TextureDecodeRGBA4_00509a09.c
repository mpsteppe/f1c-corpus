void __thiscall sub_509A09(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v5; // eax
  _BYTE *i; // edi
  int v7; // [esp+18h] [ebp+10h]

  v5 = (_BYTE *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v5[2 * this[1046]]; v5 < i; *(a4 - 1) = (double)v7 * 0.06666667 )
  {
    *a4 = (double)(v5[1] & 0xF) * 0.06666667;
    a4 += 4;
    *(a4 - 3) = (double)((*v5 >> 4) & 0xF) * 0.06666667;
    *(a4 - 2) = (double)(*v5 & 0xF) * 0.06666667;
    v7 = *(_WORD *)v5 >> 12;
    v5 += 2;
  }
  if ( this[4] )
    ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
}

