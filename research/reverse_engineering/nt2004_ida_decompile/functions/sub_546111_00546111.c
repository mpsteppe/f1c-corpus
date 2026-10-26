int __thiscall sub_546111(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int v5; // edi
  int *v6; // edx
  unsigned int v7; // esi
  int v8; // ecx
  float v10; // [esp+4h] [ebp-10h]
  float v11; // [esp+Ch] [ebp-8h]
  _DWORD *v12; // [esp+10h] [ebp-4h]

  v12 = this;
  if ( this[1042] )
  {
    v4 = sub_543AE8(this, a4);
    this = v12;
    a4 = v4;
  }
  v5 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_544279();
  v7 = 0;
  if ( v12[1046] )
  {
    v8 = 0;
    do
    {
      v11 = (*(float *)(v8 + a4 + 8) * 0.072099999
           + *(float *)(v8 + a4 + 4) * 0.71539998
           + *(float *)(v8 + a4) * 0.21250001)
          * 65535.0
          + *(float *)(v5 + 4 * (v7 & 3));
      v10 = *(float *)(v8 + a4 + 12) * 65535.0 + *(float *)(v5 + 4 * (v7 & 3));
      *v6++ = (int)v11 | ((int)v10 << 16);
      ++v7;
      v8 += 16;
    }
    while ( v7 < v12[1046] );
  }
  return dword_7E0598;
}
