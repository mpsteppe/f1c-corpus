void __thiscall sub_65817D(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v6; // edx
  int v7; // eax
  double v8; // st6
  double v9; // st5
  long double v10; // st4
  long double v11; // st6
  _BYTE *i; // [esp+10h] [ebp+8h]

  v6 = (_BYTE *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v6[2 * this[26]]; v6 < i; a4 += 4 )
  {
    v7 = (char)(v6[1] + (v6[1] == 0x80));
    v8 = (double)(char)(*v6 + (*v6 == 0x80)) * 0.0078740157;
    *a4 = v8;
    v9 = (double)v7 * 0.0078740157;
    a4[1] = v9;
    v10 = 1.0 - v8 * v8 - v9 * v9;
    if ( v10 > 0.0 )
      v11 = sqrt(v10);
    else
      v11 = 0.0;
    a4[2] = v11;
    v6 += 2;
    a4[3] = 1.0;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
