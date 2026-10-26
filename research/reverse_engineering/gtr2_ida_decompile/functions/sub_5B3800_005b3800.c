__m128 *__stdcall sub_5B3800(__m128 *a1, int a2, unsigned int *a3, int a4, __m128 *a5, int a6)
{
  int v6; // ecx
  __m128 *v7; // eax
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm7
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm3

  v6 = a6;
  v7 = a1;
  if ( a6 > 0 )
  {
    v9 = *a5;
    v10 = a5[1];
    v11 = a5[2];
    v12 = a5[3];
    do
    {
      v13 = _mm_shuffle_ps((__m128)*a3, (__m128)*a3, 0);
      v14 = _mm_shuffle_ps((__m128)a3[1], (__m128)a3[1], 0);
      v15 = _mm_shuffle_ps((__m128)a3[2], (__m128)a3[2], 0);
      v16 = _mm_shuffle_ps((__m128)a3[3], (__m128)a3[3], 0);
      a3 = (unsigned int *)((char *)a3 + a4);
      *v7 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v13, v9), _mm_mul_ps(v14, v10)),
              _mm_add_ps(_mm_mul_ps(v15, v11), _mm_mul_ps(v16, v12)));
      v7 = (__m128 *)((char *)v7 + a2);
    }
    while ( v6-- > 1 );
  }
  return a1;
}
