// Address: 0x0051f400
// Size: 181 bytes
// Name: sub_51F400
// Type: int __userpurge@<eax>(__m128@<xmm1>, __m128@<xmm2>, int, const double *, const double *, const double *, const double *, float)
// Source: IDA Hex-Rays decompilation

int __userpurge sub_51F400@<eax>(
        __m128 a1@<xmm1>,
        __m128 a2@<xmm2>,
        int a3,
        const double *a4,
        const double *a5,
        const double *a6,
        const double *a7,
        float a8)
{
  __m128 v8; // xmm0
  __m128 v9; // xmm0
  __m128 v10; // xmm0
  __m128 v11; // xmm4

  v8 = (__m128)LODWORD(a8);
  a1.m128_f32[0] = v8.m128_f32[0] * v8.m128_f32[0];
  a2.m128_f32[0] = a8 * (float)(v8.m128_f32[0] * v8.m128_f32[0]);
  v9 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), (__m128)xmmword_5D8AC0);
  v9.m128_f32[0] = v9.m128_f32[0] + *(float *)&dword_5D8AA0;
  v10 = _mm_add_ps(
          _mm_add_ps(v9, _mm_mul_ps(_mm_shuffle_ps(a1, a1, 0), (__m128)xmmword_5D8AB0)),
          _mm_mul_ps(_mm_shuffle_ps(a2, a2, 0), (__m128)xmmword_5D8A90));
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_loadh_ps(a4), _mm_shuffle_ps(v10, v10, 0)),
              _mm_mul_ps(_mm_loadh_ps(a5), _mm_shuffle_ps(v10, v10, 85))),
            _mm_mul_ps(_mm_loadh_ps(a6), _mm_shuffle_ps(v10, v10, 170))),
          _mm_mul_ps(_mm_loadh_ps(a7), _mm_shuffle_ps(v10, v10, 255)));
  _mm_storeh_ps((double *)a3, v11);
  *(_DWORD *)(a3 + 8) = v11.m128_i32[0];
  return a3;
}
