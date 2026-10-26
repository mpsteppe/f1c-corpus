int __thiscall sub_5084F5(_DWORD *this, char a2, char a3, int a4)
{
  unsigned int v4; // edi
  int v5; // eax
  int v6; // esi
  int *v7; // edx
  int v8; // ecx
  float v10; // [esp+10h] [ebp-10h]
  float v11; // [esp+18h] [ebp-8h]
  _DWORD *v12; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  v12 = this;
  if ( this[1042] )
  {
    v5 = DirectXVertexBufferFormatConversion(this, a4);
    this = v12;
    a4 = v5;
  }
  v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  UtilityFunction_7473();
  if ( v12[1046] )
  {
    v8 = 0;
    do
    {
      v11 = *(float *)(v8 + a4) * 65535.0 + *(float *)(v6 + 4 * (v4 & 3));
      v10 = *(float *)(v8 + a4 + 4) * 65535.0 + *(float *)(v6 + 4 * (v4 & 3));
      *v7++ = (int)v11 | ((int)v10 << 16);
      ++v4;
      v8 += 16;
    }
    while ( v4 < v12[1046] );
  }
  return dword_8B009C;
}
