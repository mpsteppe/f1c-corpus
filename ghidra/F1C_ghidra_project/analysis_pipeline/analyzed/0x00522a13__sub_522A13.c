// Address: 0x00522a13
// Size: 89 bytes
// Name: sub_522A13
// Type: __m64 *__stdcall(__m64 *, unsigned int)
// Source: IDA Hex-Rays decompilation

__m64 *__stdcall sub_522A13(__m64 *a1, unsigned int a2)
{
  __m64 v2; // mm0
  __m64 *result; // eax

  _m_femms();
  v2 = _mm_cvtsi32_si64(a2);
  sub_5295E0();
  result = a1;
  a1->m64_u64 = (unsigned __int64)v2;
  a1[1].m64_u64 = 0;
  a1[3].m64_u64 = 0;
  a1[4].m64_u64 = 0;
  a1[5].m64_u64 = 1065353216;
  a1[6].m64_u64 = 0;
  a1[7].m64_u64 = 0x3F80000000000000LL;
  a1[2].m64_u64 = (unsigned __int64)_m_pxor(_m_punpckldq(_m_punpckhdq(v2, v2), v2), (__m64)0x80000000LL);
  _m_femms();
  return result;
}
