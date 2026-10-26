int __thiscall sub_54566D(_DWORD *this, char a2, char a3, int a4)
{
  unsigned int v4; // edi
  int v5; // eax
  int v6; // ebx
  _WORD *v7; // edx
  int v8; // esi
  __int16 v9; // cx
  float v11; // [esp+10h] [ebp-10h]
  float v12; // [esp+18h] [ebp-8h]
  _DWORD *v13; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  v13 = this;
  if ( this[1042] )
  {
    v5 = sub_543AE8(this, a4);
    this = v13;
    a4 = v5;
  }
  v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_544279();
  if ( v13[1046] )
  {
    v8 = 0;
    do
    {
      v12 = (*(float *)(v8 + a4 + 8) * 0.072099999
           + *(float *)(v8 + a4 + 4) * 0.71539998
           + *(float *)(v8 + a4) * 0.21250001)
          * 255.0
          + *(float *)(v6 + 4 * (v4 & 3));
      v11 = *(float *)(v8 + a4 + 12) * 255.0 + *(float *)(v6 + 4 * (v4 & 3));
      LOBYTE(v9) = 0;
      HIBYTE(v9) = (int)v11;
      v8 += 16;
      *v7++ = (int)v12 | v9;
      ++v4;
    }
    while ( v4 < v13[1046] );
  }
  return dword_7E0598;
}
