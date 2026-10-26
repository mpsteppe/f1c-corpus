// Address: 0x0051fd2e
// Size: 97 bytes
// Name: sub_51FD2E
// Type: __m128 *__stdcall(__m128 *, int)
// Source: IDA Hex-Rays decompilation

__m128 *__stdcall sub_51FD2E(__m128 *a1, int a2)
{
  __m128 *result; // eax
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm0
  __m128 v6; // xmm3

  result = a1;
  v3 = _mm_loadh_ps((const double *)(a2 + 8));
  v4 = _mm_mul_ps(v3, v3);
  v5 = _mm_add_ps(v4, _mm_movehl_ps(v4, v4));
  v4.m128_f32[0] = v5.m128_f32[0] + _mm_shuffle_ps(v5, v5, 85).m128_f32[0];
  v5.m128_f32[0] = 1.0 / v4.m128_f32[0];
  v6 = v5;
  v6.m128_f32[0] = (float)(v6.m128_f32[0] + v6.m128_f32[0])
                 - (float)((float)(v5.m128_f32[0] * v4.m128_f32[0]) * v5.m128_f32[0]);
  *a1 = _mm_mul_ps(_mm_mul_ps(v3, (__m128)xmmword_5D8C00), _mm_shuffle_ps(v6, v6, 0));
  return result;
}
