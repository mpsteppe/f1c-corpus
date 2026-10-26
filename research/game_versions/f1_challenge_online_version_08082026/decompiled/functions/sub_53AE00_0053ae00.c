__int32 __cdecl sub_53AE00(int a1, __int32 *a2, _DWORD *a3, __m128 *a4)
{
  __m128 *v4; // edi
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 *v8; // esi
  __int32 v9; // ebx
  __int32 v10; // edx
  __m128 v11; // xmm3
  __int32 result; // eax
  __int32 v13; // ebx
  __int32 v14; // edx

  v4 = *(__m128 **)(a1 + 48);
  v5 = a4[1];
  v6 = a4[2];
  v7 = a4[3];
  *v4 = *a4;
  v4[1] = v5;
  v4[2] = v6;
  v4[3] = v7;
  v8 = *(__m128 **)(a1 + 16);
  v9 = a2[1];
  v10 = a2[2];
  v8->m128_i32[0] = *a2;
  v8->m128_i32[1] = v9;
  v8->m128_i32[2] = v10;
  v8->m128_i32[3] = 1065353216;
  v11 = *v8;
  *v8 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), *v4), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v4[1])),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v4[2])),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), v4[3]));
  result = v8->m128_i32[0];
  v13 = v8->m128_i32[1];
  v14 = v8->m128_i32[2];
  *a3 = v8->m128_i32[0];
  a3[1] = v13;
  a3[2] = v14;
  return result;
}
