int __thiscall sub_5EB330(_DWORD *this, float a2)
{
  int result; // eax
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // edi
  unsigned int *v7; // eax
  unsigned int v8; // edi

  result = this[90];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = 0;
    do
    {
      *(float *)(v4 + this[91] + 100) = a2;
      v5 = this[91];
      v6 = *(_DWORD *)(v5 + v4);
      v7 = (unsigned int *)(v4 + v5);
      if ( a2 == 0.0 )
        v8 = v6 & 0xFFFFDFFF;
      else
        v8 = v6 | 0x2000;
      *v7 = v8;
      result = this[90];
      ++v3;
      v4 += 108;
    }
    while ( v3 < result );
  }
  return result;
}
