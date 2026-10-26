// Address: 0x0051fb1e
// Size: 198 bytes
// Name: sub_51FB1E
// Type: __m128 *__stdcall(__m128 *, const double *)
// Source: IDA Hex-Rays decompilation

__m128 *__stdcall sub_51FB1E(__m128 *a1, const double *a2)
{
  __m128 *result; // eax
  __m128 v3; // xmm1
  __m128 v4; // xmm0
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __m128 v7; // xmm0
  float v8; // xmm5_4
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm4

  result = a1;
  v3 = _mm_loadl_ps(a2);
  v4 = _mm_and_ps((__m128)xmmword_5D8BC0, v3);
  v5 = (__m128)(unsigned int)dword_5D8BB0;
  v6 = _mm_mul_ps(v4, v4);
  v7 = _mm_add_ps(v6, _mm_movehl_ps(v6, v6));
  v8 = v7.m128_f32[0] + _mm_shuffle_ps(v7, v7, 1).m128_f32[0];
  v7.m128_f32[0] = 1.0 / fsqrt(v8);
  v5.m128_f32[0] = (float)(*(float *)&dword_5D8BB0 * v7.m128_f32[0])
                 * (float)(*(float *)&dword_5D8BA0 - (float)((float)(v8 * v7.m128_f32[0]) * v7.m128_f32[0]));
  v9 = _mm_mul_ps(v3, _mm_shuffle_ps(v5, v5, 0));
  v10 = _mm_mul_ps((__m128)xmmword_5D8B90, v9);
  v11 = v9;
  v12 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v10), (__m128)xmmword_5D8B80);
  v13 = v11;
  v14 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), v10), (__m128)xmmword_5D8B50);
  v15 = v13;
  v16 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v10), (__m128)xmmword_5D8B60);
  v17 = _mm_add_ps(_mm_mul_ps(v10, _mm_shuffle_ps(v15, v15, 85)), (__m128)xmmword_5D8B70);
  *a1 = v12;
  a1[1] = v17;
  a1[2] = v16;
  a1[3] = v14;
  return result;
}
