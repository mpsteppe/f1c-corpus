__m64 *__stdcall sub_527393(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 *result; // eax
  __m64 v4; // mm1
  __m64 v5; // mm2
  __m64 v6; // mm2

  _m_femms();
  result = a1;
  v4 = _mm_cvtsi32_si64(a3[1].m64_u32[0]);
  v5 = _m_pfmul((__m64)a2->m64_u64, (__m64)a3->m64_u64);
  v6 = _m_pfadd(_m_pfacc(v5, v5), _m_pfmul(_mm_cvtsi32_si64(a2[1].m64_u32[0]), v4));
  a1->m64_u64 = a3->m64_u64;
  a1[1].m64_i32[0] = _mm_cvtsi64_si32(v4);
  a1[1].m64_i32[1] = _mm_cvtsi64_si32(_m_pxor(v6, (__m64)0x80000000LL));
  _m_femms();
  return result;
}

