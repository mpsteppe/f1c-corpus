int __stdcall sub_55DF9E(int a1, int a2)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm0
  int result; // eax
  __int128 v5; // xmm1
  int v6; // [esp-14h] [ebp-64h]
  int v7; // [esp-10h] [ebp-60h]
  int v8; // [esp-Ch] [ebp-5Ch]
  int v9; // [esp-8h] [ebp-58h]
  __m128 v10; // [esp+1Ch] [ebp-34h]
  __m128 v11; // [esp+2Ch] [ebp-24h]
  void *vars0; // [esp+50h] [ebp+0h]
  void *retaddr; // [esp+58h] [ebp+8h]

  vars0 = retaddr;
  v11 = (__m128)xmmword_804230;
  v10 = (__m128)xmmword_804220;
  v2 = sub_566320(v6, v7, v8, v9);
  v3 = _mm_and_ps(_mm_shuffle_ps(v2, v2, 80), v11);
  result = a1;
  *(__m128 *)a1 = _mm_xor_ps(v10, v3);
  *(_OWORD *)(a1 + 16) = xmmword_804210;
  v5 = xmmword_804200;
  *(__m128 *)(a1 + 32) = _mm_shuffle_ps(v3, v3, 70);
  *(_OWORD *)(a1 + 48) = v5;
  return result;
}
