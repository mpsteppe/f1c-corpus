int __userpurge sub_51F700@<eax>(
        __m128 a1@<xmm5>,
        __m128 a2@<xmm6>,
        int a3,
        __m128 *a4,
        const double *a5,
        const double *a6)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm0
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  float v15; // xmm5_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  int v19; // [esp+0h] [ebp-4h]

  v19 = a3;
  v6 = _mm_loadh_ps(a5);
  v7 = *a4;
  v8 = _mm_shuffle_ps(v7, v7, 78);
  v9 = _mm_loadh_ps(a6);
  v10 = _mm_mul_ps(v6, v8);
  v11 = _mm_mul_ps(v8, v9);
  v12 = _mm_movehl_ps(a1, v10);
  v13 = _mm_movehl_ps(a2, v11);
  v16 = _mm_add_ps(v10, v12);
  v14 = _mm_add_ps(v11, v13);
  v16.m128_f32[0] = v16.m128_f32[0] + _mm_shuffle_ps(v12, v16, 85).m128_f32[0];
  v15 = v16.m128_f32[0] - (float)(v14.m128_f32[0] + _mm_shuffle_ps(v13, v14, 85).m128_f32[0]);
  v16.m128_f32[0] = v16.m128_f32[0] + _mm_shuffle_ps(v7, v7, 255).m128_f32[0];
  if ( v15 == *(float *)&dword_8B00E0 )
    return 0;
  v16.m128_f32[0] = v16.m128_f32[0]
                  * (float)((float)((float)(1.0 / v15) + (float)(1.0 / v15))
                          - (float)((float)(v15 * (float)(1.0 / v15)) * (float)(1.0 / v15)));
  v17 = _mm_add_ps(v6, _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), _mm_sub_ps(v9, v6)));
  _mm_storeh_ps((double *)a3, v17);
  *(_DWORD *)(a3 + 8) = v17.m128_i32[0];
  return v19;
}

