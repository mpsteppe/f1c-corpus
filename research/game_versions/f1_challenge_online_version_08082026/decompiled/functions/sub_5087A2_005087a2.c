int __thiscall sub_5087A2(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // edi
  int v5; // eax
  int v6; // esi
  _BYTE *v7; // edx
  unsigned int i; // ecx
  float v10; // [esp+10h] [ebp-8h]
  _DWORD *v11; // [esp+14h] [ebp-4h]

  v4 = 0;
  v11 = this;
  if ( this[1042] )
  {
    v5 = sub_506CE2(this, a4);
    this = v11;
    a4 = v5;
  }
  v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_507473();
  for ( i = 0; i < v11[1046]; v4 += 16 )
  {
    v10 = (*(float *)(v4 + a4 + 8) * 0.072099999
         + *(float *)(v4 + a4 + 4) * 0.71539998
         + *(float *)(v4 + a4) * 0.21250001)
        * 255.0
        + *(float *)(v6 + 4 * (i & 3));
    *v7++ = (int)v10;
    ++i;
  }
  return dword_8B009C;
}
