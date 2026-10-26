int __userpurge sub_5B21A7@<eax>(__m128 a1@<xmm0>, __m128 a2@<xmm3>, int a3, int a4, unsigned int a5)
{
  unsigned int v5; // esi
  double *v6; // ecx
  int v7; // edx
  unsigned int i; // ebx
  unsigned int v9; // edx
  int v11; // [esp+10h] [ebp-8h]

  v11 = a3;
  if ( a5 >= 8 )
  {
    v5 = a5 & 0xFFFFFFF8;
    do
    {
      sub_5B207D();
      _mm_storel_ps(v6, a1);
      _mm_storeh_ps(v6 + 1, a1);
      _mm_storel_ps(v6 + 2, a2);
      _mm_storeh_ps(v6 + 3, a2);
    }
    while ( v7 != 8 );
    _m_empty();
    a5 -= v5;
    a4 += 2 * v5;
    a3 += 4 * v5;
  }
  for ( i = 0; i < a5; ++i )
  {
    v9 = *(_WORD *)(a4 + 2 * i) & 0x7C00;
    if ( v9 <= 0x400 )
      v9 = 1024;
    *(float *)(a3 + 4 * i) = (double)(*(_WORD *)(a4 + 2 * i) & 0x3FF
                                    | ((*(_WORD *)(a4 + 2 * i) & 0x7C00) != 0 ? 0x400 : 0))
                           * COERCE_FLOAT(((*(_WORD *)(a4 + 2 * i) & 0x8000) << 16) | ((v9 + 104448) << 13));
  }
  return v11;
}
