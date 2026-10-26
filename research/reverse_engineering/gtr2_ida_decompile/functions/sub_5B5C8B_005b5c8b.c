double __stdcall sub_5B5C8B(unsigned int *a1)
{
  __m64 v1; // mm0
  __m64 v2; // mm3
  __m64 v3; // mm4
  __m64 v4; // mm2
  __m64 v5; // mm3
  __m64 v6; // mm4

  v1 = *(__m64 *)(a1 + 9);
  v2 = *(__m64 *)(a1 + 13);
  v3 = _m_pfsub(
         _m_pfmul(_m_punpckhdq(*((__m64 *)a1 + 7), *((__m64 *)a1 + 7)), v1),
         _m_pfmul(_m_punpckhdq(*((__m64 *)a1 + 5), *((__m64 *)a1 + 5)), v2));
  v4 = _m_pfsub(
         _m_pfmul(_m_punpckldq(*((__m64 *)a1 + 4), *((__m64 *)a1 + 4)), *((__m64 *)a1 + 7)),
         _m_pfmul(_m_punpckldq(*((__m64 *)a1 + 6), *((__m64 *)a1 + 6)), *((__m64 *)a1 + 5)));
  v5 = _m_pfsub(_m_pfmul(v2, *((__m64 *)a1 + 4)), _m_pfmul(v1, *((__m64 *)a1 + 6)));
  v6 = _m_pfsub(
         _m_pfmul(
           _m_pfsub(
             _m_pfadd(
               _m_pfmul(v3, *((__m64 *)a1 + 2)),
               _m_pfmul(v5, _m_punpckhdq(*((__m64 *)a1 + 3), *((__m64 *)a1 + 3)))),
             _m_pfmul(_m_punpckldq(_m_punpckhdq(v4, v4), v3), *(__m64 *)(a1 + 5))),
           _m_punpckldq(*((__m64 *)a1 + 1), (__m64)*a1)),
         _m_pfmul(
           _m_pfsub(
             _m_pfadd(
               _m_pfmul(_m_punpckhdq(v5, v3), _m_punpckldq(*((__m64 *)a1 + 2), *((__m64 *)a1 + 2))),
               _m_pfmul(_m_punpckldq(v5, v4), *((__m64 *)a1 + 3))),
             _m_pfmul(v4, *(__m64 *)(a1 + 5))),
           _m_punpckhdq(*((__m64 *)a1 + 1), *(__m64 *)a1)));
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfacc(v6, v6)));
}
