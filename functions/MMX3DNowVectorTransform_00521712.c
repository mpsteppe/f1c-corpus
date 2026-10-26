__m64 *__stdcall sub_521712(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, unsigned int a5, unsigned int a6)
{
  __m64 v6; // mm0
  __m64 v7; // mm2
  __m64 *result; // eax
  __m64 v9[2]; // [esp+Ch] [ebp-24h] BYREF
  __m64 v10[2]; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int v11; // [esp+44h] [ebp+14h]

  _m_femms();
  v11 = _mm_cvtsi64_si32(_m_pfadd(_mm_cvtsi32_si64(a5), _mm_cvtsi32_si64(a6)));
  SIMDVectorNormalization(v9, a2, a3, v11);
  SIMDVectorNormalization(v10, a2, a4, v11);
  v6 = _mm_cvtsi32_si64(v11);
  v7 = _m_pfrcp(v6);
  SIMDVectorNormalization(
    a1,
    v9,
    v10,
    _mm_cvtsi64_si32(_m_pfmul(_m_pfrcpit2(_m_pfrcpit1(v6, v7), v7), _mm_cvtsi32_si64(a6))));
  result = a1;
  _m_femms();
  return result;
}
