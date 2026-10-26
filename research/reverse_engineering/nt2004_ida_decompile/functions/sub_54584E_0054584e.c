int __thiscall sub_54584E(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int v5; // edi
  _WORD *v6; // edx
  unsigned int v7; // eax
  int v8; // esi
  __int16 v9; // cx
  float v11; // [esp+4h] [ebp-10h]
  float v12; // [esp+Ch] [ebp-8h]
  _DWORD *v13; // [esp+10h] [ebp-4h]

  v13 = this;
  if ( this[1042] )
  {
    v4 = sub_543AE8(this, a4);
    this = v13;
    a4 = v4;
  }
  v5 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_544279();
  v7 = 0;
  if ( v13[1046] )
  {
    v8 = 0;
    do
    {
      v12 = *(float *)(v8 + a4) * 128.0 + *(float *)(v5 + 4 * (v7 & 3));
      LOBYTE(v9) = (int)v12;
      v11 = *(float *)(v8 + a4 + 4) * 128.0 + *(float *)(v5 + 4 * (v7 & 3));
      v8 += 16;
      HIBYTE(v9) = (int)v11;
      *v6++ = v9;
      ++v7;
    }
    while ( v7 < v13[1046] );
  }
  return dword_7E0598;
}
