__m64 *__userpurge sub_6D17A0@<eax>(int *a1@<eax>, int a2@<edx>, int a3, int a4)
{
  int v4; // ecx
  __m64 *result; // eax
  int v6; // ebx
  __m64 **v7; // eax
  __m64 *v8; // edx
  __m64 *v9; // esi
  __m64 m64_u64; // mm4
  __m64 v11; // mm5
  __m64 v12; // mm0
  __m64 v13; // mm2
  __m64 v14; // mm1
  __m64 v15; // mm6
  __m64 v16; // mm2
  __m64 v17; // mm0
  __m64 *v18; // edi
  __m64 *v19; // eax
  int i; // ecx
  __m64 v21; // mm0
  __m64 v22; // mm2
  __m64 v23; // mm1
  __m64 v24; // mm6
  __m64 v25; // mm1
  __m64 v26; // mm3
  __m64 v27; // mm0
  __m64 *v28; // edi
  __m64 v29; // mm0
  __m64 v30; // mm1
  __m64 v31; // mm0
  __m64 v32; // mm2
  __m64 v33; // mm3
  __m64 v34; // mm1
  __m64 v35; // mm0
  __m64 v36; // mm0
  __m64 v37; // mm1
  __m64 v38; // mm0
  __m64 *v39; // esi
  __m64 *v40; // edx
  __m64 v41; // mm5
  __m64 v42; // mm2
  __m64 *v43; // edi
  int j; // ecx
  __m64 v45; // mm1
  __m64 v46; // mm6
  __m64 v47; // mm2
  __m64 v48; // mm3
  __m64 *v49; // edi
  __m64 v50; // mm2
  __m64 v51; // [esp+4h] [ebp-30h]
  __m64 v52; // [esp+Ch] [ebp-28h]
  __m64 *v53; // [esp+14h] [ebp-20h]
  __m64 *v54; // [esp+1Ch] [ebp-18h]
  __m64 *v55; // [esp+20h] [ebp-14h]
  __m64 *v56; // [esp+24h] [ebp-10h]
  __m64 *v57; // [esp+28h] [ebp-Ch]
  int v58; // [esp+2Ch] [ebp-8h]
  __m64 *v59; // [esp+30h] [ebp-4h]
  __m64 **v60; // [esp+40h] [ebp+Ch]

  v4 = *a1;
  result = *(__m64 **)(a2 + 40);
  v6 = 0;
  v59 = result;
  v58 = v4;
  if ( *(int *)(a3 + 316) > 0 )
  {
    v7 = (__m64 **)(a4 + 4);
    v60 = (__m64 **)(a4 + 4);
    while ( 1 )
    {
      v53 = *(v7 - 1);
      v56 = *v7;
      v54 = *(__m64 **)(v4 + 4 * v6);
      v57 = *(__m64 **)(v4 + 4 * v6 + 4);
      v6 += 2;
      v55 = (__m64 *)((char *)v54 + 4 * (_DWORD)v59);
      v8 = v53;
      v9 = *(v7 - 2);
      m64_u64 = (__m64)v53->m64_u64;
      v11 = (__m64)v9->m64_u64;
      v12 = _m_punpcklbw((__m64)v53->m64_u64, 0);
      v13 = _m_punpcklbw((__m64)v9->m64_u64, 0);
      v14 = _m_paddw(
              _m_pmullw(_m_psllqi(v12, 0x10u), (__m64)0x3000300030003LL),
              _m_pmullw(v12, (__m64)0x900090009000CLL));
      v55->m64_u64 = (unsigned __int64)v14;
      v15 = _m_psrlwi(
              _m_paddw(
                _m_paddw(v14, _m_paddw(_m_psllqi(v13, 0x10u), _m_pmullw(v13, (__m64)0x3000300030004LL))),
                (__m64)0x8000800080008LL),
              4u);
      v16 = _m_pmullw(_m_punpcklbw(v11, 0), (__m64)0x3000300030003LL);
      v17 = _m_paddw(
              _m_pmullw(_m_punpcklbw(m64_u64, 0), (__m64)0x9000900090009LL),
              _m_pmullw(_m_punpcklbw(_m_psrlqi(m64_u64, 8u), 0), (__m64)0x3000300030003LL));
      v55[1].m64_u64 = (unsigned __int64)v17;
      v54->m64_u64 = (unsigned __int64)_m_paddw(
                                         v15,
                                         _m_psllqi(
                                           _m_psrlwi(
                                             _m_paddw(
                                               _m_paddw(
                                                 _m_paddw(v17, _m_punpcklbw(_m_psrlqi(v11, 8u), 0)),
                                                 (__m64)0x7000700070007LL),
                                               v16),
                                             4u),
                                           8u));
      v18 = v54 + 1;
      v19 = v55 + 2;
      for ( i = (int)&v59[-1]; i > 0; i -= 8 )
      {
        v51 = m64_u64;
        v52 = v11;
        v21 = _m_pmullw(_m_punpckhbw(m64_u64, 0), (__m64)0x9000900090009LL);
        v22 = _m_pmullw(_m_punpckhbw(v11, 0), (__m64)0x3000300030003LL);
        v23 = _m_paddw(_m_pmullw(_m_punpckhbw(_m_psllqi(m64_u64, 8u), 0), (__m64)0x3000300030003LL), v21);
        v19->m64_u64 = (unsigned __int64)v23;
        v24 = _m_psrlwi(
                _m_paddw(_m_paddw(v23, (__m64)0x8000800080008LL), _m_paddw(_m_punpckhbw(_m_psllqi(v11, 8u), 0), v22)),
                4u);
        v25 = _m_psrlqi(m64_u64, 8u);
        m64_u64 = v8[1];
        v26 = _m_psrlqi(v11, 8u);
        v11 = v9[1];
        v27 = _m_paddw(
                v21,
                _m_pmullw(_m_punpckhbw(_m_paddb(v25, _m_psllqi(m64_u64, 0x38u)), 0), (__m64)0x3000300030003LL));
        v19[1].m64_u64 = (unsigned __int64)v27;
        v18->m64_u64 = (unsigned __int64)_m_paddw(
                                           v24,
                                           _m_psllqi(
                                             _m_psrlwi(
                                               _m_paddw(
                                                 _m_paddw(
                                                   v27,
                                                   _m_paddw(
                                                     _m_punpckhbw(_m_paddb(v26, _m_psllqi(v11, 0x38u)), 0),
                                                     (__m64)0x7000700070007LL)),
                                                 v22),
                                               4u),
                                             8u));
        v28 = v18 + 1;
        v29 = _m_punpcklbw(m64_u64, 0);
        v30 = _m_paddw(_m_psllqi(v29, 0x10u), _m_psrlqi(v51, 0x38u));
        v31 = _m_pmullw(v29, (__m64)0x9000900090009LL);
        v32 = _m_punpcklbw(v11, 0);
        v33 = _m_paddw(_m_psllqi(v32, 0x10u), _m_psrlqi(v52, 0x38u));
        v16 = _m_pmullw(v32, (__m64)0x3000300030003LL);
        v34 = _m_paddw(_m_pmullw(v30, (__m64)0x3000300030003LL), v31);
        v19[2].m64_u64 = (unsigned __int64)v34;
        v35 = _m_paddw(v31, _m_pmullw(_m_punpcklbw(_m_psrlqi(m64_u64, 8u), 0), (__m64)0x3000300030003LL));
        v19[3].m64_u64 = (unsigned __int64)v35;
        v28->m64_u64 = (unsigned __int64)_m_paddw(
                                           _m_psrlwi(
                                             _m_paddw(_m_paddw(v34, (__m64)0x8000800080008LL), _m_paddw(v33, v16)),
                                             4u),
                                           _m_psllqi(
                                             _m_psrlwi(
                                               _m_paddw(
                                                 _m_paddw(
                                                   _m_paddw(v35, _m_punpcklbw(_m_psrlqi(v11, 8u), 0)),
                                                   (__m64)0x7000700070007LL),
                                                 v16),
                                               4u),
                                             8u));
        v18 = v28 + 1;
        ++v8;
        ++v9;
        v19 += 4;
      }
      v36 = _m_pmullw(_m_punpckhbw(m64_u64, 0), (__m64)0x9000900090009LL);
      v37 = _m_paddw(_m_pmullw(_m_punpckhbw(_m_psllqi(m64_u64, 8u), 0), (__m64)0x3000300030003LL), v36);
      v19->m64_u64 = (unsigned __int64)v37;
      v38 = _m_paddw(
              v36,
              _m_pmullw(
                _m_punpckhbw(_m_paddb(_m_psrlqi(m64_u64, 8u), _m_pand(m64_u64, (__m64)0xFF00000000000000uLL)), 0),
                (__m64)0x3000300030003LL));
      v19[1].m64_u64 = (unsigned __int64)v38;
      v18->m64_u64 = (unsigned __int64)_m_paddw(
                                         _m_psrlwi(
                                           _m_paddw(
                                             _m_paddw(v37, (__m64)0x8000800080008LL),
                                             _m_paddw(_m_punpckhbw(_m_psllqi(v11, 8u), 0), v16)),
                                           4u),
                                         _m_psllqi(
                                           _m_psrlwi(
                                             _m_paddw(
                                               _m_paddw(
                                                 v38,
                                                 _m_paddw(
                                                   _m_punpckhbw(
                                                     _m_paddb(
                                                       _m_psrlqi(v11, 8u),
                                                       _m_pand(v11, (__m64)0xFF00000000000000uLL)),
                                                     0),
                                                   (__m64)0x7000700070007LL)),
                                               v16),
                                             4u),
                                           8u));
      v39 = v56;
      v40 = v53;
      v41 = (__m64)v56->m64_u64;
      v42 = _m_punpcklbw((__m64)v56->m64_u64, 0);
      v57->m64_u64 = (unsigned __int64)_m_paddw(
                                         _m_psrlwi(
                                           _m_paddw(
                                             _m_paddw(
                                               (__m64)v55->m64_u64,
                                               _m_paddw(_m_psllqi(v42, 0x10u), _m_pmullw(v42, (__m64)0x3000300030004LL))),
                                             (__m64)0x8000800080008LL),
                                           4u),
                                         _m_psllqi(
                                           _m_psrlwi(
                                             _m_paddw(
                                               _m_paddw(
                                                 _m_paddw(v55[1], _m_punpcklbw(_m_psrlqi((__m64)v56->m64_u64, 8u), 0)),
                                                 (__m64)0x7000700070007LL),
                                               _m_pmullw(v42, (__m64)0x3000300030003LL)),
                                             4u),
                                           8u));
      v43 = v57 + 1;
      result = v55 + 2;
      for ( j = (int)&v59[-1]; j > 0; j -= 8 )
      {
        v45 = v41;
        v46 = _m_psrlwi(
                _m_paddw(
                  _m_paddw((__m64)result->m64_u64, (__m64)0x8000800080008LL),
                  _m_paddw(
                    _m_punpckhbw(_m_psllqi(v41, 8u), 0),
                    _m_pmullw(_m_punpckhbw(v41, 0), (__m64)0x3000300030003LL))),
                4u);
        v47 = _m_punpckhbw(v41, 0);
        v48 = _m_psrlqi(v41, 8u);
        v41 = v39[1];
        v43->m64_u64 = (unsigned __int64)_m_paddw(
                                           v46,
                                           _m_psllqi(
                                             _m_psrlwi(
                                               _m_paddw(
                                                 _m_paddw(
                                                   result[1],
                                                   _m_paddw(
                                                     _m_punpckhbw(_m_paddb(v48, _m_psllqi(v41, 0x38u)), 0),
                                                     (__m64)0x7000700070007LL)),
                                                 _m_pmullw(v47, (__m64)0x3000300030003LL)),
                                               4u),
                                             8u));
        v49 = v43 + 1;
        v50 = _m_punpcklbw(v41, 0);
        v49->m64_u64 = (unsigned __int64)_m_paddw(
                                           _m_psrlwi(
                                             _m_paddw(
                                               _m_paddw(result[2], (__m64)0x8000800080008LL),
                                               _m_paddw(
                                                 _m_paddw(_m_psllqi(v50, 0x10u), _m_psrlqi(v45, 0x38u)),
                                                 _m_pmullw(v50, (__m64)0x3000300030003LL))),
                                             4u),
                                           _m_psllqi(
                                             _m_psrlwi(
                                               _m_paddw(
                                                 _m_paddw(
                                                   _m_paddw(result[3], _m_punpcklbw(_m_psrlqi(v41, 8u), 0)),
                                                   (__m64)0x7000700070007LL),
                                                 _m_pmullw(v50, (__m64)0x3000300030003LL)),
                                               4u),
                                             8u));
        v43 = v49 + 1;
        ++v40;
        ++v39;
        result += 4;
      }
      v43->m64_u64 = (unsigned __int64)_m_paddw(
                                         _m_psrlwi(
                                           _m_paddw(
                                             _m_paddw((__m64)result->m64_u64, (__m64)0x8000800080008LL),
                                             _m_paddw(
                                               _m_punpckhbw(_m_psllqi(v41, 8u), 0),
                                               _m_pmullw(_m_punpckhbw(v41, 0), (__m64)0x3000300030003LL))),
                                           4u),
                                         _m_psllqi(
                                           _m_psrlwi(
                                             _m_paddw(
                                               _m_paddw(
                                                 result[1],
                                                 _m_paddw(
                                                   _m_punpckhbw(
                                                     _m_paddb(
                                                       _m_psrlqi(v41, 8u),
                                                       _m_pand(v41, (__m64)0xFF00000000000000uLL)),
                                                     0),
                                                   (__m64)0x7000700070007LL)),
                                               _m_pmullw(_m_punpckhbw(v41, 0), (__m64)0x3000300030003LL)),
                                             4u),
                                           8u));
      ++v60;
      if ( v6 >= *(_DWORD *)(a3 + 316) )
        break;
      v7 = v60;
      v4 = v58;
    }
  }
  _m_empty();
  return result;
}
