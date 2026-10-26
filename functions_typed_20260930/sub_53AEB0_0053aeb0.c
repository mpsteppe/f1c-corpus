__int32 __cdecl sub_53AEB0(int a1, _DWORD *a2, __m128 *a3, __m128 *a4)
{
  __int32 *v4; // ebx
  _DWORD *v5; // edx
  __m128 *v6; // edi
  __m128 *v7; // esi
  __int32 v8; // ecx
  __m128 v9; // xmm3
  __int32 v10; // ecx
  bool v11; // cc
  __int32 *v12; // ebx
  __m128 *v13; // edi
  __m128 *v14; // esi
  __int32 v15; // ecx
  __int32 v16; // ecx
  __int32 result; // eax
  int v18; // [esp-4h] [ebp-18h]
  int v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+Ch] [ebp-8h]

  v19 = a2[2];
  v18 = v19;
  v4 = (__int32 *)a2[3];
  v5 = (_DWORD *)a2[8];
  v6 = *(__m128 **)(a1 + 48);
  *v6 = *a3;
  v6[1] = a3[1];
  v6[2] = a3[2];
  v6[3] = a3[3];
  v7 = *(__m128 **)(a1 + 16);
  v7->m128_i32[3] = 1065353216;
  do
  {
    v8 = v4[1];
    v7->m128_i32[0] = *v4;
    v7->m128_i32[1] = v8;
    v7->m128_i32[2] = v4[2];
    v9 = *v7;
    *v7 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *v6), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v6[1])),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v6[2])),
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), v6[3]));
    v10 = v7->m128_i32[1];
    *v5 = v7->m128_i32[0];
    v5[1] = v10;
    v5[2] = v7->m128_i32[2];
    v5 += 16;
    v4 += 12;
    v11 = v19-- <= 1;
  }
  while ( !v11 );
  v12 = (__int32 *)(a2[3] + 12);
  v20 = v18;
  v13 = *(__m128 **)(a1 + 48);
  *v13 = *a4;
  v13[1] = a4[1];
  v13[2] = a4[2];
  v14 = *(__m128 **)(a1 + 16);
  do
  {
    v15 = v12[1];
    v14->m128_i32[0] = *v12;
    v14->m128_i32[1] = v15;
    v14->m128_i32[2] = v12[2];
    *v14 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 0), *v13),
               _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 85), v13[1])),
             _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 170), v13[2]));
    v16 = v14->m128_i32[1];
    *v5 = v14->m128_i32[0];
    v5[1] = v16;
    result = v14->m128_i32[2];
    v5[2] = result;
    v12 += 12;
    v5 += 5;
    v11 = v20-- <= 1;
  }
  while ( !v11 );
  return result;
}

