int __thiscall sub_544E0D(_DWORD *this, char a2, char a3, int a4)
{
  unsigned int v4; // edi
  int v5; // eax
  int v6; // ebx
  _BYTE *v7; // edx
  int v8; // esi
  char v9; // al
  int v11; // [esp+Ch] [ebp-1Ch]
  float v12; // [esp+1Ch] [ebp-Ch]
  float v13; // [esp+1Ch] [ebp-Ch]
  float v14; // [esp+1Ch] [ebp-Ch]
  float v15; // [esp+20h] [ebp-8h]
  _DWORD *v16; // [esp+24h] [ebp-4h]

  v4 = 0;
  v16 = this;
  if ( this[1042] )
  {
    v5 = sub_543AE8(this, a4);
    this = v16;
    a4 = v5;
  }
  v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_544279();
  if ( v16[1046] )
  {
    v8 = 0;
    do
    {
      v15 = *(float *)(v6 + 4 * (v4 & 3));
      v12 = *(float *)(v8 + a4) * 7.0 + v15;
      v9 = (int)v12;
      v13 = *(float *)(v8 + a4 + 4) * 7.0 + v15;
      v11 = (int)v13;
      v14 = *(float *)(v8 + a4 + 8) * 3.0 + v15;
      v8 += 16;
      *v7++ = (int)v14 | (4 * (v11 | (8 * v9)));
      ++v4;
    }
    while ( v4 < v16[1046] );
  }
  return dword_7E0598;
}
