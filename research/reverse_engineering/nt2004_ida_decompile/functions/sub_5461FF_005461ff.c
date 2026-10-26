int __thiscall sub_5461FF(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int v5; // edi
  _WORD *v6; // edx
  unsigned int v7; // esi
  int v8; // eax
  float v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+Ch] [ebp-Ch]
  float v12; // [esp+Ch] [ebp-Ch]
  float v13; // [esp+10h] [ebp-8h]
  _DWORD *v14; // [esp+14h] [ebp-4h]

  v14 = this;
  if ( this[1042] )
  {
    v4 = sub_543AE8(this, a4);
    this = v14;
    a4 = v4;
  }
  v5 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_544279();
  v7 = 0;
  if ( v14[1046] )
  {
    v8 = 0;
    do
    {
      v13 = *(float *)(v5 + 4 * (v7 & 3));
      v10 = *(float *)(v8 + a4 + 8) * 65535.0 + v13;
      *v6 = (int)v10;
      v11 = *(float *)(v8 + a4 + 4) * 65535.0 + v13;
      v6[1] = (int)v11;
      v12 = *(float *)(v8 + a4) * 65535.0 + v13;
      v6[2] = (int)v12;
      v6 += 3;
      ++v7;
      v8 += 16;
    }
    while ( v7 < v14[1046] );
  }
  return dword_7E0598;
}
