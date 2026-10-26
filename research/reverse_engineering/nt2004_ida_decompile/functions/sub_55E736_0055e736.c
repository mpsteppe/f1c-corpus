int __stdcall sub_55E736(__m64 *a1, int a2, _DWORD *a3)
{
  __m64 m64_u64; // mm2
  __m64 v4; // mm0
  __m64 v5; // mm5
  __m64 v6; // mm5
  __m64 v7; // mm1
  int result; // eax
  __m64 v9; // mm4
  __m64 v10; // mm1
  __m64 v11; // mm1

  m64_u64 = (__m64)a1->m64_u64;
  v4 = a1[1];
  v5 = _m_pfadd(_m_pfmul(m64_u64, m64_u64), _m_pfmul(v4, v4));
  v6 = _m_pfacc(v5, v5);
  v7 = _m_pfrsqrt(v6);
  result = _mm_cvtsi64_si32(_m_pfcmpge((__m64)0x80000000800000LL, v6));
  v9 = v7;
  if ( result )
  {
    if ( a2 )
    {
      *(_QWORD *)(a2 + 4) = 0;
      *(_DWORD *)a2 = _mm_cvtsi64_si32((__m64)0xBF8000003F800000uLL);
    }
    if ( a3 )
      *a3 = _mm_cvtsi64_si32(0);
  }
  else
  {
    v10 = _m_pfmul(v7, v7);
    if ( a2 )
    {
      v11 = _m_pfrcpit2(_m_pfrsqit1(v10, v6), v9);
      *(__m64 *)a2 = _m_pfmul(m64_u64, v11);
      *(_DWORD *)(a2 + 8) = _mm_cvtsi64_si32(_m_pfmul(v11, v4));
    }
    if ( a3 )
    {
      result = sub_566740(a3, a2);
      *a3 = _mm_cvtsi64_si32(_m_pfmul(_m_punpckhdq(v4, v4), (__m64)0x4000000040000000LL));
    }
  }
  _m_femms();
  return result;
}
