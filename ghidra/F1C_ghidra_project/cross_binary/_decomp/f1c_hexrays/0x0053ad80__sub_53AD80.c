// f1c  0x0053ad80  size=128
__int32 __cdecl sub_53AD80(int a1, __int32 *a2, _DWORD *a3, __m128 *a4)
{
  __m128 *v4; // edi
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 *v7; // esi
  __int32 v8; // ebx
  __int32 v9; // edx
  __int32 result; // eax
  __int32 v11; // ebx
  __int32 v12; // edx

  v4 = *(__m128 **)(a1 + 48);
  v5 = a4[1];
  v6 = a4[2];
  *v4 = *a4;
  v4[1] = v5;
  v4[2] = v6;
  v7 = *(__m128 **)(a1 + 16);
  v8 = a2[1];
  v9 = a2[2];
  v7->m128_i32[0] = *a2;
  v7->m128_i32[1] = v8;
  v7->m128_i32[2] = v9;
  *v7 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 0), *v4), _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 85), v4[1])),
          _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 170), v4[2]));
  result = v7->m128_i32[0];
  v11 = v7->m128_i32[1];
  v12 = v7->m128_i32[2];
  *a3 = v7->m128_i32[0];
  a3[1] = v11;
  a3[2] = v12;
  return result;
}
