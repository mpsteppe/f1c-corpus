int __userpurge sub_5B2EE8@<eax>(__m128 a1@<xmm3>, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // esi
  int v5; // eax
  __m128 v6; // xmm0
  double *v7; // ecx
  int v8; // edx
  unsigned int i; // ebx
  unsigned int v10; // edx
  int v12; // [esp+10h] [ebp-8h]

  v12 = a2;
  if ( a4 >= 8 )
  {
    v4 = a4 & 0xFFFFFFF8;
    v5 = a3;
    do
    {
      v6 = _mm_loadh_ps((const double *)(v5 + 8));
      sub_5B2DF5();
      _mm_storel_ps(v7, v6);
      _mm_storeh_ps(v7 + 1, v6);
      _mm_storel_ps(v7 + 2, a1);
      _mm_storeh_ps(v7 + 3, a1);
    }
    while ( v8 != 8 );
    a4 -= v4;
    a3 += 2 * v4;
    a2 += 4 * v4;
  }
  for ( i = 0; i < a4; ++i )
  {
    v10 = *(_WORD *)(a3 + 2 * i) & 0x7C00;
    if ( v10 <= 0x400 )
      v10 = 1024;
    *(float *)(a2 + 4 * i) = (double)(*(_WORD *)(a3 + 2 * i) & 0x3FF
                                    | ((*(_WORD *)(a3 + 2 * i) & 0x7C00) != 0 ? 0x400 : 0))
                           * COERCE_FLOAT(((*(_WORD *)(a3 + 2 * i) & 0x8000) << 16) | ((v10 + 104448) << 13));
  }
  return v12;
}
