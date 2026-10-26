__m64 *__stdcall sub_55EF0F(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, __m64 *a5, unsigned int a6)
{
  __m64 v6; // mm1
  __m64 *result; // eax
  __m64 v8[2]; // [esp+10h] [ebp-20h] BYREF
  __m64 v9[2]; // [esp+20h] [ebp-10h] BYREF

  sub_55ED4B(v8, a2, a5, a6);
  sub_55ED4B(v9, a3, a4, a6);
  v6 = _mm_cvtsi32_si64(a6);
  result = sub_55ED4B(
             a1,
             v8,
             v9,
             _mm_cvtsi64_si32(_m_pfmul(_m_pfsub(v6, _m_pfmul(v6, v6)), (__m64)0x4000000040000000LL)));
  _m_femms();
  return result;
}
