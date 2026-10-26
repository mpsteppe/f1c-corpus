// f1c  0x0051fbf0  size=130
double *__stdcall sub_51FBF0(double *a1, int a2, int a3)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1

  v3 = _mm_loadh_ps((const double *)(a2 + 8));
  v4 = _mm_loadh_ps((const double *)(a3 + 8));
  v5 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 255), v3);
  v6 = _mm_shuffle_ps(v3, v3, 27);
  v7 = _mm_add_ps(v5, _mm_mul_ps(_mm_xor_ps(_mm_shuffle_ps(v4, v4, 0), (__m128)xmmword_8D6100), v6));
  v8 = _mm_shuffle_ps(v6, v6, 177);
  v9 = _mm_add_ps(
         _mm_add_ps(v7, _mm_mul_ps(_mm_xor_ps(_mm_shuffle_ps(v4, v4, 85), (__m128)xmmword_8D60F0), v8)),
         _mm_mul_ps(_mm_xor_ps(_mm_shuffle_ps(v4, v4, 170), (__m128)xmmword_8D60E0), _mm_shuffle_ps(v8, v8, 27)));
  _mm_storel_ps(a1, v9);
  _mm_storeh_ps(a1 + 1, v9);
  return a1;
}
