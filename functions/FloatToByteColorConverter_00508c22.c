int __thiscall sub_508C22(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int *v5; // edx
  unsigned int v6; // eax
  int v7; // esi
  unsigned __int8 v8; // di
  unsigned __int16 v9; // bx
  int v11; // [esp+0h] [ebp-20h]
  float v12; // [esp+10h] [ebp-10h]
  float v13; // [esp+10h] [ebp-10h]
  float v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  float v16; // [esp+18h] [ebp-8h]
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v17 = this;
  if ( this[1042] )
  {
    v4 = DirectXVertexBufferFormatConversion(this, a4);
    this = v17;
    a4 = v4;
  }
  v15 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  UtilityFunction_7473();
  v6 = 0;
  if ( v17[1046] )
  {
    v7 = 0;
    do
    {
      v16 = *(float *)(v15 + 4 * (v6 & 3));
      v12 = *(float *)(v7 + a4) * 128.0 + v16;
      v8 = (int)v12;
      v13 = *(float *)(v7 + a4 + 4) * 128.0 + v16;
      v11 = (int)v13;
      v14 = *(float *)(v7 + a4 + 12) * 255.0 + v16;
      HIBYTE(v9) = (int)v14;
      v7 += 16;
      LOBYTE(v9) = v11;
      *v5++ = v8 | (v9 << 8);
      ++v6;
    }
    while ( v6 < v17[1046] );
  }
  return dword_8B009C;
}
