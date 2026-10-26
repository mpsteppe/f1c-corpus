__m64 **__userpurge sub_6D13E0@<eax>(__m64 ***a1@<eax>, int a2@<ecx>, int a3, int a4)
{
  __m64 **result; // eax
  int v5; // edx
  int v6; // ebx
  __m64 *v7; // esi
  __m64 *v8; // edi
  __m64 m64_u64; // mm7
  __m64 v10; // mm0
  __m64 v11; // mm3
  __m64 v12; // mm0
  __m64 v13; // mm1
  __m64 v14; // mm2
  __m64 v15; // mm7
  __m64 *v16; // edi
  __m64 *v17; // esi
  int i; // ecx
  __m64 v19; // mm0
  __m64 v20; // mm0
  __m64 v21; // mm1
  __m64 v22; // mm2
  __m64 v23; // mm0
  __m64 v24; // mm0
  int v25; // [esp+4h] [ebp-8h]

  result = *a1;
  v25 = *(_DWORD *)(a2 + 40);
  v5 = 0;
  if ( *(int *)(a3 + 316) > 0 )
  {
    v6 = a4 - (_DWORD)result;
    do
    {
      v7 = *(__m64 **)((char *)result + v6);
      v8 = *result;
      m64_u64 = (__m64)v7->m64_u64;
      v10 = _m_pmullw(_m_punpcklbw((__m64)v7->m64_u64, 0), (__m64)0x3000300030003LL);
      v8->m64_u64 = (unsigned __int64)_m_paddb(
                                        _m_psllqi(
                                          _m_psrlwi(
                                            _m_paddw(
                                              _m_paddw(_m_punpcklbw(_m_psrlqi((__m64)v7->m64_u64, 8u), 0), v10),
                                              (__m64)0x2000200020002LL),
                                            2u),
                                          8u),
                                        _m_psrlwi(
                                          _m_paddw(
                                            _m_paddw(
                                              _m_punpcklbw(
                                                _m_paddb(
                                                  _m_psllqi((__m64)v7->m64_u64, 8u),
                                                  _m_pand((__m64)v7->m64_u64, (__m64)255LL)),
                                                0),
                                              v10),
                                            (__m64)0x1000100010001LL),
                                          2u));
      v11 = m64_u64;
      v12 = _m_pmullw(_m_punpckhbw(m64_u64, 0), (__m64)0x3000300030003LL);
      v13 = _m_psllqi(m64_u64, 8u);
      v14 = _m_psrlqi(m64_u64, 8u);
      v15 = v7[1];
      v8[1].m64_u64 = (unsigned __int64)_m_paddb(
                                          _m_psllqi(
                                            _m_psrlwi(
                                              _m_paddw(
                                                _m_paddw(_m_punpckhbw(_m_paddb(v14, _m_psllqi(v15, 0x38u)), 0), v12),
                                                (__m64)0x2000200020002LL),
                                              2u),
                                            8u),
                                          _m_psrlwi(
                                            _m_paddw(_m_paddw(_m_punpckhbw(v13, 0), v12), (__m64)0x1000100010001LL),
                                            2u));
      v16 = v8 + 2;
      v17 = v7 + 1;
      for ( i = v25 - 8; i > 8; i -= 8 )
      {
        v19 = _m_pmullw(_m_punpcklbw(v15, 0), (__m64)0x3000300030003LL);
        v16->m64_u64 = (unsigned __int64)_m_paddb(
                                           _m_psllqi(
                                             _m_psrlwi(
                                               _m_paddw(
                                                 _m_paddw(_m_punpcklbw(_m_psrlqi(v15, 8u), 0), v19),
                                                 (__m64)0x2000200020002LL),
                                               2u),
                                             8u),
                                           _m_psrlwi(
                                             _m_paddw(
                                               _m_paddw(
                                                 _m_punpcklbw(_m_paddb(_m_psllqi(v15, 8u), _m_psrlqi(v11, 0x38u)), 0),
                                                 v19),
                                               (__m64)0x1000100010001LL),
                                             2u));
        v11 = v15;
        v20 = _m_pmullw(_m_punpckhbw(v15, 0), (__m64)0x3000300030003LL);
        v21 = _m_psllqi(v15, 8u);
        v22 = _m_psrlqi(v15, 8u);
        v15 = v17[1];
        v16[1].m64_u64 = (unsigned __int64)_m_paddb(
                                             _m_psllqi(
                                               _m_psrlwi(
                                                 _m_paddw(
                                                   _m_paddw(_m_punpckhbw(_m_paddb(v22, _m_psllqi(v15, 0x38u)), 0), v20),
                                                   (__m64)0x2000200020002LL),
                                                 2u),
                                               8u),
                                             _m_psrlwi(
                                               _m_paddw(_m_paddw(_m_punpckhbw(v21, 0), v20), (__m64)0x1000100010001LL),
                                               2u));
        v16 += 2;
        ++v17;
      }
      v23 = _m_pmullw(_m_punpcklbw(v15, 0), (__m64)0x3000300030003LL);
      v16->m64_u64 = (unsigned __int64)_m_paddb(
                                         _m_psllqi(
                                           _m_psrlwi(
                                             _m_paddw(
                                               _m_paddw(_m_punpcklbw(_m_psrlqi(v15, 8u), 0), v23),
                                               (__m64)0x2000200020002LL),
                                             2u),
                                           8u),
                                         _m_psrlwi(
                                           _m_paddw(
                                             _m_paddw(
                                               _m_punpcklbw(_m_paddb(_m_psllqi(v15, 8u), _m_psrlqi(v11, 0x38u)), 0),
                                               v23),
                                             (__m64)0x1000100010001LL),
                                           2u));
      if ( i > 4 )
      {
        v24 = _m_pmullw(_m_punpckhbw(v15, 0), (__m64)0x3000300030003LL);
        v16[1].m64_u64 = (unsigned __int64)_m_paddb(
                                             _m_psllqi(
                                               _m_psrlwi(
                                                 _m_paddw(
                                                   _m_paddw(
                                                     _m_punpckhbw(
                                                       _m_paddb(
                                                         _m_psrlqi(v15, 8u),
                                                         _m_pand(v15, (__m64)0xFF00000000000000uLL)),
                                                       0),
                                                     v24),
                                                   (__m64)0x2000200020002LL),
                                                 2u),
                                               8u),
                                             _m_psrlwi(
                                               _m_paddw(
                                                 _m_paddw(_m_punpckhbw(_m_psllqi(v15, 8u), 0), v24),
                                                 (__m64)0x1000100010001LL),
                                               2u));
      }
      _m_empty();
      ++v5;
      ++result;
    }
    while ( v5 < *(_DWORD *)(a3 + 316) );
  }
  return result;
}
