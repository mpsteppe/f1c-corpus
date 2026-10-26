int __thiscall sub_5079A1(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int v5; // edi
  int *v6; // edx
  unsigned int v7; // esi
  int v8; // ecx
  int v9; // ebx
  int v11; // [esp+0h] [ebp-24h]
  int v12; // [esp+4h] [ebp-20h]
  float v13; // [esp+18h] [ebp-Ch]
  float v14; // [esp+18h] [ebp-Ch]
  float v15; // [esp+18h] [ebp-Ch]
  float v16; // [esp+18h] [ebp-Ch]
  float v17; // [esp+1Ch] [ebp-8h]
  _DWORD *v18; // [esp+20h] [ebp-4h]

  v18 = this;
  if ( this[1042] )
  {
    v4 = DirectXVertexBufferFormatConversion(this, a4);
    this = v18;
    a4 = v4;
  }
  v5 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  UtilityFunction_7473();
  v7 = 0;
  if ( v18[1046] )
  {
    v8 = 0;
    do
    {
      v17 = *(float *)(v5 + 4 * (v7 & 3));
      v13 = *(float *)(v8 + a4) * 255.0 + v17;
      v9 = (int)v13;
      v14 = *(float *)(v8 + a4 + 4) * 255.0 + v17;
      v12 = (int)v14;
      v15 = *(float *)(v8 + a4 + 8) * 255.0 + v17;
      v11 = (int)v15;
      v16 = *(float *)(v8 + a4 + 12) * 255.0 + v17;
      v8 += 16;
      *v6++ = v11 | ((v12 | ((v9 | ((int)v16 << 8)) << 8)) << 8);
      ++v7;
    }
    while ( v7 < v18[1046] );
  }
  return dword_8B009C;
}

