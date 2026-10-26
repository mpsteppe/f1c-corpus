__m64 *__userpurge sub_5642A5@<eax>(
        __m64 a1@<mm2>,
        __m64 a2@<mm3>,
        __m64 *a3,
        __m64 *a4,
        __m64 *a5,
        __m64 *a6,
        __m64 *a7,
        __m64 *a8)
{
  __m64 v8; // mm4
  __m64 v9; // mm2
  __m64 v10; // mm5
  __m64 v11; // mm0
  __m64 v12; // mm5
  __m64 v13; // mm6
  __m64 v14; // mm3
  __m64 *v16; // [esp-4h] [ebp-50h]
  __m64 v17[8]; // [esp+Ch] [ebp-40h] BYREF

  switch ( (a6 != 0) | (2 * ((a7 != 0) | (2 * (a8 != 0)))) )
  {
    case 0:
      sub_560272(v17);
      break;
    case 1:
      sub_562F10(v17, 0, a6);
      break;
    case 2:
      sub_562F10(v17, 0, a7);
      break;
    case 3:
      sub_563D2B(a1, a2, v17, a7, a6);
      goto LABEL_11;
    case 4:
      sub_562F10(v17, 0, a8);
      break;
    case 5:
      v16 = a6;
      goto LABEL_9;
    case 6:
      v16 = a7;
LABEL_9:
      sub_563D2B(a1, a2, v17, a8, v16);
      goto LABEL_11;
    case 7:
      sub_563D2B(a1, a2, v17, a8, a7);
      sub_563D2B(a1, a2, v17, v17, a6);
LABEL_11:
      sub_562F10(v17, 0, v17);
      break;
    default:
      break;
  }
  if ( a5 )
  {
    _m_femms();
    v8 = a5[2];
    v9 = _m_pi2fd(a5[1]);
    v10 = _m_punpckldq(_m_pfrcp(v9), _m_pfrcp(_m_punpckhdq(v9, v9)));
    v11 = _m_pfmul(
            _m_pfsub((__m64)a4->m64_u64, _m_pi2fd((__m64)a5->m64_u64)),
            _m_pfmul(_m_pfrcpit2(_m_pfrcpit1(v9, v10), v10), (__m64)0x4000000040000000LL));
    v12 = _m_pfsub(_m_punpckhdq(v8, v8), v8);
    v13 = _m_pfrcp(v12);
    v14 = _m_pfmul(_m_pfsub(_mm_cvtsi32_si64(a4[1].m64_u32[0]), v8), _m_pfrcpit2(_m_pfrcpit1(v12, v13), v13));
    a3->m64_u64 = (unsigned __int64)_m_pxor(_m_pfsub(v11, (__m64)0x3F8000003F800000LL), (__m64)0x8000000000000000uLL);
    a3[1].m64_i32[0] = _mm_cvtsi64_si32(v14);
    _m_femms();
    sub_563CA0(a3, a3, v17);
  }
  else
  {
    sub_563CA0(a3, a4, v17);
  }
  return a3;
}
