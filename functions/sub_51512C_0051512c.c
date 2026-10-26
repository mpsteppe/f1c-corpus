int __cdecl sub_51512C(float *a1, unsigned __int16 *a2)
{
  int result; // eax
  unsigned int v3; // ecx
  int v4; // edx
  float *v5; // eax
  double v6; // st6
  unsigned int v7; // esi
  int v8; // ecx
  float *v9; // eax
  double v10; // st6

  result = KeyframeQuadInterpolationWithBitPackedSelector(a1, a2 + 4);
  if ( result >= 0 )
  {
    v3 = *(_DWORD *)a2;
    v4 = 8;
    v5 = a1 + 3;
    do
    {
      v6 = (double)(v3 & 0xF);
      v3 >>= 4;
      *v5 = v6 * 0.06666667;
      v5 += 4;
      --v4;
    }
    while ( v4 );
    v7 = *((_DWORD *)a2 + 1);
    v8 = 8;
    v9 = a1 + 35;
    do
    {
      v10 = (double)(v7 & 0xF);
      v7 >>= 4;
      *v9 = v10 * 0.06666667;
      v9 += 4;
      --v8;
    }
    while ( v8 );
    return 0;
  }
  return result;
}
