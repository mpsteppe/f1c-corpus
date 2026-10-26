int __thiscall sub_507BC5(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int v5; // edi
  _WORD *v6; // edx
  unsigned int v7; // esi
  int v8; // ecx
  __int16 v9; // ax
  int v11; // [esp+0h] [ebp-1Ch]
  float v12; // [esp+10h] [ebp-Ch]
  float v13; // [esp+10h] [ebp-Ch]
  float v14; // [esp+10h] [ebp-Ch]
  float v15; // [esp+14h] [ebp-8h]
  _DWORD *v16; // [esp+18h] [ebp-4h]

  v16 = this;
  if ( this[1042] )
  {
    v4 = DirectXVertexBufferFormatConversion(this, a4);
    this = v16;
    a4 = v4;
  }
  v5 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  UtilityFunction_7473();
  v7 = 0;
  if ( v16[1046] )
  {
    v8 = 0;
    do
    {
      v15 = *(float *)(v5 + 4 * (v7 & 3));
      v12 = *(float *)(v8 + a4) * 31.0 + v15;
      v9 = (int)v12;
      v13 = *(float *)(v8 + a4 + 4) * 63.0 + v15;
      v11 = (int)v13;
      v14 = *(float *)(v8 + a4 + 8) * 31.0 + v15;
      v8 += 16;
      *v6++ = (int)v14 | (32 * (v11 | (v9 << 6)));
      ++v7;
    }
    while ( v7 < v16[1046] );
  }
  return dword_8B009C;
}
