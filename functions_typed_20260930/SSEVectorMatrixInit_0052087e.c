int __stdcall sub_52087E(int a1, int a2)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm2
  int result; // eax
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  int v7; // [esp-14h] [ebp-44h]
  int v8; // [esp-10h] [ebp-40h]
  int v9; // [esp-Ch] [ebp-3Ch]
  int v10; // [esp-8h] [ebp-38h]
  void *vars0; // [esp+30h] [ebp+0h]
  void *retaddr; // [esp+38h] [ebp+8h]

  vars0 = retaddr;
  v2 = EmptyStub_8bd0(v7, v8, v9, v10);
  v3 = (__m128)xmmword_8D61B0;
  result = a1;
  v5 = v2;
  v6 = (__m128)xmmword_8D61C0;
  *(_OWORD *)a1 = xmmword_8D61D0;
  *(_DWORD *)(a1 + 16) = v6.m128_i32[0];
  _mm_storel_ps((double *)(a1 + 20), v5);
  _mm_storel_ps((double *)(a1 + 28), v6);
  *(_DWORD *)(a1 + 44) = v6.m128_i32[0];
  _mm_storel_ps((double *)(a1 + 36), _mm_xor_ps(_mm_shuffle_ps(v5, v5, 17), v3));
  *(__m128 *)(a1 + 48) = v6;
  return result;
}

