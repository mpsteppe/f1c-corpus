__m64 *__stdcall sub_52243A(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 v3; // mm1
  __m64 v4; // mm4
  __m64 v5; // mm5
  __m64 v6; // mm7
  __m64 v7; // mm1
  __m64 v8; // mm6
  __m64 v9; // mm4
  __m64 v10; // mm2
  __m64 *result; // eax
  __m64 v12; // mm5
  __m64 v13; // mm4
  __m64 v14; // mm4
  __m64 v15; // mm5
  __m64 v16; // mm4
  __m64 v17; // mm5
  __m64 v18; // mm4
  __m64 v19; // mm5
  __m64 v20; // [esp+0h] [ebp-44h]
  __m64 v21; // [esp+8h] [ebp-3Ch]
  __m64 v22; // [esp+10h] [ebp-34h]
  __m64 v23; // [esp+18h] [ebp-2Ch]
  __m64 v24; // [esp+28h] [ebp-1Ch]
  __m64 v25; // [esp+30h] [ebp-14h]
  __m64 v26; // [esp+38h] [ebp-Ch]

  _m_femms();
  v3 = a3[2];
  v4 = a3[7];
  v5 = a3[5];
  v20 = _m_punpckldq((__m64)a3->m64_u64, v3);
  v22 = _m_punpckhdq((__m64)a3->m64_u64, v3);
  v6 = a3[3];
  v7 = a3[1];
  v24 = _m_punpckldq(v5, v4);
  v26 = _m_punpckhdq(v5, v4);
  v8 = _m_punpckldq(v7, v6);
  v9 = a3[6];
  v10 = a3[4];
  v25 = _m_punpckhdq(v7, v6);
  v23 = _m_punpckhdq(v10, v9);
  v21 = _m_punpckldq(v10, v9);
  result = a1;
  v12 = a2[1];
  v13 = _m_pfadd(
          _m_pfacc(_m_pfmul((__m64)a2->m64_u64, v8), _m_pfmul((__m64)a2->m64_u64, v25)),
          _m_pfacc(_m_pfmul(v12, v24), _m_pfmul(v12, v26)));
  a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                    _m_pfacc(_m_pfmul((__m64)a2->m64_u64, v20), _m_pfmul((__m64)a2->m64_u64, v22)),
                                    _m_pfacc(_m_pfmul(v12, v21), _m_pfmul(v12, v23)));
  a1[1].m64_u64 = (unsigned __int64)v13;
  v14 = a2[2];
  v15 = a2[3];
  a1[2].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfacc(_m_pfmul(v14, v20), _m_pfmul(v14, v22)),
                                      _m_pfacc(_m_pfmul(v15, v21), _m_pfmul(v15, v23)));
  a1[3].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfacc(_m_pfmul(v14, v8), _m_pfmul(v14, v25)),
                                      _m_pfacc(_m_pfmul(v15, v24), _m_pfmul(v15, v26)));
  v16 = a2[4];
  v17 = a2[5];
  a1[4].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfacc(_m_pfmul(v16, v20), _m_pfmul(v16, v22)),
                                      _m_pfacc(_m_pfmul(v17, v21), _m_pfmul(v17, v23)));
  a1[5].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfacc(_m_pfmul(v16, v8), _m_pfmul(v16, v25)),
                                      _m_pfacc(_m_pfmul(v17, v24), _m_pfmul(v17, v26)));
  v18 = a2[6];
  v19 = a2[7];
  a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfacc(_m_pfmul(v18, v20), _m_pfmul(v18, v22)),
                                      _m_pfacc(_m_pfmul(v19, v21), _m_pfmul(v19, v23)));
  a1[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfacc(_m_pfmul(v18, v8), _m_pfmul(v18, v25)),
                                      _m_pfacc(_m_pfmul(v19, v24), _m_pfmul(v19, v26)));
  _m_femms();
  return result;
}
