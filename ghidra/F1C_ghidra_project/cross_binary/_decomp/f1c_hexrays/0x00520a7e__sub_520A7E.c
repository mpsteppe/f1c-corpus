// f1c  0x00520a7e  size=380
double *__stdcall sub_520A7E(double *a1, __m128 *a2, __m128 *a3)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm3
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  char v8; // al
  __m128 v9; // xmm4
  float v10; // xmm3_4
  float v11; // xmm5_4
  double *result; // eax
  __m128 v13; // xmm4
  __m128 v14; // xmm0
  __m128 v15; // xmm0
  __m128 v16; // xmm0
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  float v19; // xmm7_4
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3

  v3 = *a3;
  v4 = _mm_and_ps((__m128)xmmword_5D8CA0, *a3);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_add_ps(v5, _mm_movehl_ps((__m128)0LL, v5));
  v7 = _mm_shuffle_ps(v6, v6, 1);
  v7.m128_f32[0] = v7.m128_f32[0] + v6.m128_f32[0];
  if ( v7.m128_f32[0] != 0.0 )
  {
    v8 = byte_8D46B0;
    if ( (byte_8D46B0 & 1) != 0 )
    {
      v9 = (__m128)xmmword_8D4690;
    }
    else
    {
      v8 = byte_8D46B0 | 1;
      v9 = (__m128)(unsigned int)dword_8D6220;
      byte_8D46B0 |= 1u;
      xmmword_8D4690 = (unsigned int)dword_8D6220;
    }
    if ( (v8 & 2) != 0 )
    {
      v10 = *(float *)&xmmword_8D46A0;
    }
    else
    {
      v10 = *(float *)&dword_8D6224;
      byte_8D46B0 = v8 | 2;
      xmmword_8D46A0 = (unsigned int)dword_8D6224;
    }
    v11 = 1.0 / fsqrt(v7.m128_f32[0]);
    v9.m128_f32[0] = (float)(v9.m128_f32[0] * v11) * (float)(v10 - (float)((float)(v7.m128_f32[0] * v11) * v11));
    v7 = _mm_mul_ps(v3, _mm_shuffle_ps(v9, v9, 0));
  }
  result = a1;
  v13 = _mm_xor_ps((__m128)xmmword_5D8C60, v7);
  v14 = _mm_mul_ps(v7, *a2);
  v15 = _mm_add_ps(v14, _mm_movehl_ps(v6, v14));
  v15.m128_f32[0] = v15.m128_f32[0] + _mm_shuffle_ps(v15, v15, 1).m128_f32[0];
  v16 = _mm_shuffle_ps(v15, v15, 0);
  v17 = _mm_and_ps((__m128)xmmword_5D8C80, v16);
  v18 = _mm_and_ps((__m128)xmmword_5D8C90, v16);
  v19 = v16.m128_f32[0];
  v20 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), *a2), _mm_and_ps((__m128)xmmword_5D8C70, v16));
  v21 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), *a2), v17);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), *a2);
  v22 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), *a2), v18);
  v23.m128_f32[0] = v23.m128_f32[0] + v19;
  if ( ((unsigned __int8)a1 & 0xF) != 0 )
  {
    _mm_storel_ps(a1, v23);
    _mm_storeh_ps(a1 + 1, v23);
    _mm_storel_ps(a1 + 2, v20);
    _mm_storeh_ps(a1 + 3, v20);
    _mm_storel_ps(a1 + 4, v21);
    _mm_storeh_ps(a1 + 5, v21);
    _mm_storel_ps(a1 + 6, v22);
    _mm_storeh_ps(a1 + 7, v22);
  }
  else
  {
    *(__m128 *)a1 = v23;
    *((__m128 *)a1 + 1) = v20;
    *((__m128 *)a1 + 2) = v21;
    *((__m128 *)a1 + 3) = v22;
  }
  return result;
}
