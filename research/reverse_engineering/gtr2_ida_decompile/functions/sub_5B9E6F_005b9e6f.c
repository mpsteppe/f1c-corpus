__m64 *__userpurge sub_5B9E6F@<eax>(
        __m64 a1@<mm2>,
        __m64 a2@<mm3>,
        __m64 *a3,
        __m64 *a4,
        __m64 *a5,
        __m64 *a6,
        __m64 *a7,
        __m64 *a8)
{
  __m64 *v8; // esi
  __m64 v9; // mm1
  __m64 v11; // [esp+8h] [ebp-40h] BYREF
  float v12; // [esp+10h] [ebp-38h]
  float v13; // [esp+14h] [ebp-34h]
  float v14; // [esp+18h] [ebp-30h]
  float v15; // [esp+1Ch] [ebp-2Ch]
  float v16; // [esp+20h] [ebp-28h]
  float v17; // [esp+24h] [ebp-24h]
  float v18; // [esp+28h] [ebp-20h]
  float v19; // [esp+2Ch] [ebp-1Ch]
  float v20; // [esp+30h] [ebp-18h]
  float v21; // [esp+34h] [ebp-14h]
  float v22; // [esp+38h] [ebp-10h]
  float v23; // [esp+3Ch] [ebp-Ch]
  float v24; // [esp+40h] [ebp-8h]
  float v25; // [esp+44h] [ebp-4h]

  v8 = &v11;
  switch ( (a6 != 0) | (2 * ((a7 != 0) | (2 * (a8 != 0)))) )
  {
    case 0:
      v24 = 0.0;
      v23 = 0.0;
      v22 = 0.0;
      v21 = 0.0;
      v19 = 0.0;
      v18 = 0.0;
      v17 = 0.0;
      v16 = 0.0;
      v14 = 0.0;
      v13 = 0.0;
      v12 = 0.0;
      v11.m64_f32[1] = 0.0;
      v25 = 1.0;
      v20 = 1.0;
      v15 = 1.0;
      v11.m64_f32[0] = 1.0;
      break;
    case 1:
      v8 = a6;
      break;
    case 2:
      v8 = a7;
      break;
    case 3:
      _m_femms();
      sub_5B9C9B(a1, a2, &v11, a7, a6);
      _m_femms();
      break;
    case 4:
      v8 = a8;
      break;
    case 5:
      _m_femms();
      sub_5B9C9B(a1, a2, &v11, a8, a6);
      _m_femms();
      break;
    case 6:
      _m_femms();
      sub_5B9C9B(a1, a2, &v11, a8, a7);
      _m_femms();
      break;
    case 7:
      _m_femms();
      sub_5B9C9B(a1, a2, &v11, a8, a7);
      sub_5B9C9B(a1, a2, &v11, &v11, a6);
      _m_femms();
      break;
    default:
      break;
  }
  sub_5B9C0E(a3, a4, v8);
  if ( a5 )
  {
    _m_femms();
    v9 = _m_pfadd(_m_pfmul(_mm_cvtsi32_si64(a3[1].m64_u32[0]), _m_pfsub(_m_punpckhdq(a5[2], a5[2]), a5[2])), a5[2]);
    a3->m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfmul(
                                        _m_pfadd(
                                          _m_pxor((__m64)a3->m64_u64, (__m64)0x8000000000000000uLL),
                                          (__m64)0x3F8000003F800000LL),
                                        _m_pfmul(_m_pi2fd(a5[1]), (__m64)0x3F0000003F000000LL)),
                                      _m_pi2fd((__m64)a5->m64_u64));
    a3[1].m64_i32[0] = _mm_cvtsi64_si32(v9);
    _m_femms();
  }
  return a3;
}
