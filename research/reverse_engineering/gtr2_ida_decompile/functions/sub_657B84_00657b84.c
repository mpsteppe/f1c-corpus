void __thiscall sub_657B84(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v6; // eax
  char v7; // dl
  _BYTE *i; // [esp+10h] [ebp+8h]

  v6 = (_BYTE *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v6[2 * this[26]]; v6 < i; *(a4 - 1) = 1.0 )
  {
    v7 = v6[1];
    *a4 = (double)(char)(*v6 + (*v6 == 0x80)) * 0.0078740157;
    v6 += 2;
    a4 += 4;
    *(a4 - 3) = (double)(char)(v7 + (v7 == (char)0x80)) * 0.0078740157;
    *(a4 - 2) = 1.0;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
