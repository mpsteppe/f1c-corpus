void __thiscall sub_657DC4(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v6; // eax
  char v7; // cl
  _DWORD *i; // [esp+8h] [ebp-4h]
  char v9; // [esp+17h] [ebp+Bh]
  int v10; // [esp+18h] [ebp+Ch]

  v6 = (_DWORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v6[this[26]]; v6 < i; *(a4 - 1) = (double)(char)(v9 + (v9 == (char)0x80)) * 0.0078740157 )
  {
    v9 = HIBYTE(*v6);
    v10 = (char)(BYTE1(*v6) + (BYTE1(*v6) == 0x80));
    v7 = HIWORD(*v6) + ((unsigned __int8)BYTE2(*v6) == 0x80);
    *a4 = (double)(char)(*v6 + ((unsigned __int8)*v6 == 0x80)) * 0.0078740157;
    a4[1] = (double)v10 * 0.0078740157;
    ++v6;
    a4 += 4;
    *(a4 - 2) = (double)v7 * 0.0078740157;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
