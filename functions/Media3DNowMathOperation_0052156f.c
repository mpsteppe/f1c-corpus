__m64 *__stdcall sub_52156F(__m64 *a1, int a2, unsigned int a3)
{
  __m64 v3; // mm0
  __m64 *result; // eax
  __m64 v5; // mm3
  __m64 v6; // mm2
  __m64 v7; // [esp+0h] [ebp-18h] BYREF
  unsigned int v8; // [esp+8h] [ebp-10h]

  _m_femms();
  sub_5262C2((int)&v7, a2);
  v3 = _m_pfmul(_mm_cvtsi32_si64(a3), (__m64)0x3F0000003F000000LL);
  PackedFloatingPointMath();
  result = a1;
  v5 = _m_punpckhdq(v3, v3);
  v6 = _m_punpckldq(_m_pfmul(_mm_cvtsi32_si64(v8), v5), v3);
  a1->m64_u64 = (unsigned __int64)_m_pfmul(v7, v5);
  a1[1].m64_u64 = (unsigned __int64)v6;
  _m_femms();
  return result;
}
