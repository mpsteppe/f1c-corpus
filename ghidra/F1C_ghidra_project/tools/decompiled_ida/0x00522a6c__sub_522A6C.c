// Address: 0x00522a6c
// Size: 71 bytes
// Name: sub_522A6C
// Type: __m64 *__stdcall(__m64 *, unsigned int, unsigned int, unsigned int)
// Source: IDA Hex-Rays decompilation

__m64 *__stdcall sub_522A6C(__m64 *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __m64 *result; // eax

  _m_femms();
  result = a1;
  a1->m64_u64 = (unsigned __int64)_mm_cvtsi32_si64(a2);
  a1[1].m64_u64 = 0;
  a1[3].m64_u64 = 0;
  a1[4].m64_u64 = 0;
  a1[6].m64_u64 = 0;
  a1[2].m64_u64 = (unsigned __int64)_m_psllqi(_mm_cvtsi32_si64(a3), 0x20u);
  a1[5].m64_u64 = (unsigned __int64)_mm_cvtsi32_si64(a4);
  a1[7].m64_u64 = 0x3F80000000000000LL;
  _m_femms();
  return result;
}
