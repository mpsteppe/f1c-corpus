__m64 *__userpurge sub_56407F@<eax>(
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
  __m64 v16; // [esp+Ch] [ebp-40h] BYREF
  float v17; // [esp+14h] [ebp-38h]
  float v18; // [esp+18h] [ebp-34h]
  float v19; // [esp+1Ch] [ebp-30h]
  float v20; // [esp+20h] [ebp-2Ch]
  float v21; // [esp+24h] [ebp-28h]
  float v22; // [esp+28h] [ebp-24h]
  float v23; // [esp+2Ch] [ebp-20h]
  float v24; // [esp+30h] [ebp-1Ch]
  float v25; // [esp+34h] [ebp-18h]
  float v26; // [esp+38h] [ebp-14h]
  float v27; // [esp+3Ch] [ebp-10h]
  float v28; // [esp+40h] [ebp-Ch]
  float v29; // [esp+44h] [ebp-8h]
  float v30; // [esp+48h] [ebp-4h]

  switch ( (a6 != 0) | (2 * ((a7 != 0) | (2 * (a8 != 0)))) )
  {
    case 0:
      v29 = 0.0;
      v28 = 0.0;
      v27 = 0.0;
      v26 = 0.0;
      v24 = 0.0;
      v23 = 0.0;
      v22 = 0.0;
      v21 = 0.0;
      v19 = 0.0;
      v18 = 0.0;
      v17 = 0.0;
      v16.m64_f32[1] = 0.0;
      v30 = 1.0;
      v25 = 1.0;
      v20 = 1.0;
      v16.m64_f32[0] = 1.0;
      break;
    case 1:
      _m_femms();
      sub_5635EA(&v16, 0, a6);
      _m_femms();
      break;
    case 2:
      _m_femms();
      sub_5635EA(&v16, 0, a7);
      _m_femms();
      break;
    case 3:
      _m_femms();
      sub_563D2B(a1, a2, &v16, a7, a6);
      sub_5635EA(&v16, 0, &v16);
      _m_femms();
      break;
    case 4:
      _m_femms();
      sub_5635EA(&v16, 0, a8);
      _m_femms();
      break;
    case 5:
      _m_femms();
      sub_563D2B(a1, a2, &v16, a8, a6);
      sub_5635EA(&v16, 0, &v16);
      _m_femms();
      break;
    case 6:
      _m_femms();
      sub_563D2B(a1, a2, &v16, a8, a7);
      sub_5635EA(&v16, 0, &v16);
      _m_femms();
      break;
    case 7:
      _m_femms();
      sub_563D2B(a1, a2, &v16, a8, a7);
      sub_563D2B(a1, a2, &v16, &v16, a6);
      sub_5635EA(&v16, 0, &v16);
      _m_femms();
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
    sub_563CA0(a3, a3, &v16);
  }
  else
  {
    sub_563CA0(a3, a4, &v16);
  }
  return a3;
}
