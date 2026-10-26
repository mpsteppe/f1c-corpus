int __stdcall sub_5B4672(__m64 *a1, __m64 *a2, _DWORD *a3)
{
  __m64 v3; // mm0
  __m64 v4; // mm0
  int result; // eax

  v3 = a1[1];
  if ( a2 )
  {
    a2->m64_u64 = a1->m64_u64;
    a2[1].m64_i32[0] = _mm_cvtsi64_si32(v3);
  }
  v4 = _m_punpckhdq(v3, v3);
  if ( a3 )
  {
    result = sub_5BB540();
    *a3 = _mm_cvtsi64_si32(_m_pfmul(v4, (__m64)0x4000000040000000LL));
  }
  _m_femms();
  return result;
}
