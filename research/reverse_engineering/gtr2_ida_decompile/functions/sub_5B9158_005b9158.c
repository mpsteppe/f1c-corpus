__m64 *__stdcall sub_5B9158(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 v3; // mm1
  __m64 v4; // mm4
  __m64 v5; // mm5
  __m64 v6; // mm7
  __m64 v7; // mm0
  __m64 v8; // mm1
  __m64 v9; // mm4
  __m64 *result; // eax
  __m64 v11; // mm4
  __m64 v12; // mm4
  __m64 v13; // mm4
  __m64 v14; // mm4
  __m64 v15; // mm4
  __m64 v16; // mm4
  __m64 v17; // mm4
  __m64 v18; // [esp+0h] [ebp-44h]
  __m64 v19; // [esp+0h] [ebp-44h]
  __m64 v20; // [esp+8h] [ebp-3Ch]
  __m64 v21; // [esp+8h] [ebp-3Ch]
  __m64 v22; // [esp+10h] [ebp-34h]
  __m64 v23; // [esp+10h] [ebp-34h]
  __m64 v24; // [esp+18h] [ebp-2Ch]
  __m64 v25; // [esp+18h] [ebp-2Ch]
  __m64 v26; // [esp+20h] [ebp-24h]
  __m64 v27; // [esp+20h] [ebp-24h]
  __m64 v28; // [esp+28h] [ebp-1Ch]
  __m64 v29; // [esp+28h] [ebp-1Ch]
  __m64 v30; // [esp+30h] [ebp-14h]
  __m64 v31; // [esp+38h] [ebp-Ch]

  _m_femms();
  v3 = a3[2];
  v4 = a3[7];
  v5 = a3[5];
  v18 = _m_punpckldq((__m64)a3->m64_u64, v3);
  v22 = _m_punpckhdq((__m64)a3->m64_u64, v3);
  v6 = a3[3];
  v7 = a3[4];
  v8 = a3[1];
  v28 = _m_punpckldq(v5, v4);
  v31 = _m_punpckhdq(v5, v4);
  v9 = a3[6];
  v26 = _m_punpckldq(v8, v6);
  v30 = _m_punpckhdq(v8, v6);
  v24 = _m_punpckhdq(v7, v9);
  v20 = _m_punpckldq(v7, v9);
  result = a1;
  v11 = _m_pfadd(
          _m_pfacc(_m_pfmul(v18, a2[4]), _m_pfmul(v18, a2[6])),
          _m_pfacc(_m_pfmul(v20, a2[5]), _m_pfmul(v20, a2[7])));
  if ( a2 == a1 )
  {
    v19 = _m_pfadd(
            _m_pfacc(_m_pfmul(v18, (__m64)a2->m64_u64), _m_pfmul(v18, a2[2])),
            _m_pfacc(_m_pfmul(v20, a2[1]), _m_pfmul(v20, a2[3])));
    v21 = v11;
    v15 = _m_pfadd(
            _m_pfacc(_m_pfmul(v22, a2[4]), _m_pfmul(v22, a2[6])),
            _m_pfacc(_m_pfmul(v24, a2[5]), _m_pfmul(v24, a2[7])));
    v23 = _m_pfadd(
            _m_pfacc(_m_pfmul(v22, (__m64)a2->m64_u64), _m_pfmul(v22, a2[2])),
            _m_pfacc(_m_pfmul(v24, a2[1]), _m_pfmul(v24, a2[3])));
    v25 = v15;
    v16 = _m_pfadd(
            _m_pfacc(_m_pfmul(v26, a2[4]), _m_pfmul(v26, a2[6])),
            _m_pfacc(_m_pfmul(v28, a2[5]), _m_pfmul(v28, a2[7])));
    v27 = _m_pfadd(
            _m_pfacc(_m_pfmul(v26, (__m64)a2->m64_u64), _m_pfmul(v26, a2[2])),
            _m_pfacc(_m_pfmul(v28, a2[1]), _m_pfmul(v28, a2[3])));
    v29 = v16;
    v17 = _m_pfadd(
            _m_pfacc(_m_pfmul(v30, a2[4]), _m_pfmul(v30, a2[6])),
            _m_pfacc(_m_pfmul(v31, a2[5]), _m_pfmul(v31, a2[7])));
    a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                        _m_pfacc(_m_pfmul(v30, (__m64)a2->m64_u64), _m_pfmul(v30, a2[2])),
                                        _m_pfacc(_m_pfmul(v31, a2[1]), _m_pfmul(v31, a2[3])));
    a1[7].m64_u64 = (unsigned __int64)v17;
    a1->m64_u64 = (unsigned __int64)v19;
    a1[1].m64_u64 = (unsigned __int64)v21;
    a1[2].m64_u64 = (unsigned __int64)v23;
    a1[3].m64_u64 = (unsigned __int64)v25;
    a1[4].m64_u64 = (unsigned __int64)v27;
    a1[5].m64_u64 = (unsigned __int64)v29;
  }
  else
  {
    a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfacc(_m_pfmul(v18, (__m64)a2->m64_u64), _m_pfmul(v18, a2[2])),
                                      _m_pfacc(_m_pfmul(v20, a2[1]), _m_pfmul(v20, a2[3])));
    a1[1].m64_u64 = (unsigned __int64)v11;
    v12 = _m_pfadd(
            _m_pfacc(_m_pfmul(v22, a2[4]), _m_pfmul(v22, a2[6])),
            _m_pfacc(_m_pfmul(v24, a2[5]), _m_pfmul(v24, a2[7])));
    a1[2].m64_u64 = (unsigned __int64)_m_pfadd(
                                        _m_pfacc(_m_pfmul(v22, (__m64)a2->m64_u64), _m_pfmul(v22, a2[2])),
                                        _m_pfacc(_m_pfmul(v24, a2[1]), _m_pfmul(v24, a2[3])));
    a1[3].m64_u64 = (unsigned __int64)v12;
    v13 = _m_pfadd(
            _m_pfacc(_m_pfmul(v26, a2[4]), _m_pfmul(v26, a2[6])),
            _m_pfacc(_m_pfmul(v28, a2[5]), _m_pfmul(v28, a2[7])));
    a1[4].m64_u64 = (unsigned __int64)_m_pfadd(
                                        _m_pfacc(_m_pfmul(v26, (__m64)a2->m64_u64), _m_pfmul(v26, a2[2])),
                                        _m_pfacc(_m_pfmul(v28, a2[1]), _m_pfmul(v28, a2[3])));
    a1[5].m64_u64 = (unsigned __int64)v13;
    v14 = _m_pfadd(
            _m_pfacc(_m_pfmul(v30, a2[4]), _m_pfmul(v30, a2[6])),
            _m_pfacc(_m_pfmul(v31, a2[5]), _m_pfmul(v31, a2[7])));
    a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                        _m_pfacc(_m_pfmul(v30, (__m64)a2->m64_u64), _m_pfmul(v30, a2[2])),
                                        _m_pfacc(_m_pfmul(v31, a2[1]), _m_pfmul(v31, a2[3])));
    a1[7].m64_u64 = (unsigned __int64)v14;
  }
  _m_femms();
  return result;
}
