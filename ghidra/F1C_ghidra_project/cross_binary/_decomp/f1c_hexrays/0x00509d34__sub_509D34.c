// f1c  0x00509d34  size=178
void __thiscall sub_509D34(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v5; // eax
  _BYTE *i; // edi
  int v7; // [esp+18h] [ebp+10h]

  v5 = (_BYTE *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v5[2 * this[1046]]; v5 < i; *(a4 - 1) = (double)(unsigned __int8)*(v5 - 1) * 0.0039215689 )
  {
    *a4 = (double)((*v5 >> 5) & 7) * 0.14285715;
    a4 += 4;
    *(a4 - 3) = (double)((*v5 >> 2) & 7) * 0.14285715;
    v7 = *v5 & 3;
    v5 += 2;
    *(a4 - 2) = (double)v7 * 0.33333334;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
