void __thiscall sub_65770C(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v4; // eax
  _BYTE *i; // edi
  int v7; // [esp+18h] [ebp+10h]

  v4 = (_BYTE *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[2 * this[26]]; v4 < i; *(a4 - 1) = (double)(unsigned __int8)*(v4 - 1) * 0.0039215689 )
  {
    *a4 = (double)((*v4 >> 5) & 7) * 0.14285715;
    a4 += 4;
    *(a4 - 3) = (double)((*v4 >> 2) & 7) * 0.14285715;
    v7 = *v4 & 3;
    v4 += 2;
    *(a4 - 2) = (double)v7 * 0.33333334;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
