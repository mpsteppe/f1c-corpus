double __usercall _pow_pentium4@<st0>(
        __m128d a1@<xmm0>,
        __m128d a2@<xmm1>,
        __m128d a3@<xmm2>,
        __m128d a4@<xmm3>,
        __m128d a5@<xmm4>,
        __m128d a6@<xmm5>,
        __m128d a7@<xmm7>,
        double a8,
        double a9)
{
  __m128d v9; // xmm7
  __m128d inserted; // xmm0
  int epi16; // ecx
  int v12; // eax
  __m128d v13; // xmm7
  __m128d v14; // xmm6
  int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // edx
  __m128d v18; // xmm1
  __m128d v19; // xmm0
  __m128d v20; // xmm7
  int v21; // eax
  __m128d v22; // xmm6
  double v23; // xmm2_8
  int v24; // eax
  double v25; // xmm2_8
  double v26; // xmm5_8
  double v27; // xmm2_8
  double v28; // xmm2_8
  __m128i v29; // xmm1
  int v30; // edx
  double v31; // xmm2_8
  __m128d v32; // xmm0
  __m128d v33; // xmm6
  __m128d v34; // xmm7
  unsigned int v35; // eax
  double v36; // xmm2_8
  double v37; // xmm4_8
  double v38; // xmm3_8
  double v39; // xmm1_8
  double v40; // xmm3_8
  double v41; // xmm5_8
  double v42; // xmm5_8
  double v43; // xmm4_8
  double v44; // xmm5_8
  int v45; // eax
  __m128d v46; // xmm2
  __m128d v47; // xmm7
  __m128i v48; // xmm2
  __m128i v49; // xmm3
  __m128d v50; // xmm0
  __m128d v51; // xmm6
  double v52; // xmm4_8
  __m128d v53; // xmm0
  __m128i v54; // xmm7
  double result; // st7
  int v56; // eax
  __m128i v57; // xmm1
  unsigned int v58; // ecx
  __m128i v59; // xmm2
  __m128d v60; // xmm1
  __m128i v61; // xmm2
  unsigned __int8 v62; // al
  unsigned int v63; // edx
  __m128i v64; // xmm1
  int v65; // edx
  int v66; // eax
  __m128d v67; // xmm7
  int v68; // eax
  __m128d v69; // xmm0
  int v70; // edx
  __m128d v71; // xmm1
  int v72; // eax
  int v73; // eax
  int v74; // eax
  __m128i v75; // xmm4
  int v76; // ecx
  unsigned int v77; // eax
  int v78; // eax
  unsigned int v79; // ecx
  unsigned int v80; // edx
  unsigned int v81; // edi
  double v82; // xmm4_8
  __m128d v83; // xmm2
  __m128d v84; // xmm7
  __m128i v85; // xmm2
  __m128i v86; // xmm3
  __m128d v87; // xmm0
  __m128d v88; // xmm6
  double v89; // xmm4_8
  __m128i v90; // xmm7
  double v91; // xmm7_8
  double v92; // xmm1_8
  __int64 v93; // xmm4_8
  double v94; // xmm1_8
  double v95; // xmm6_8
  int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // edx
  unsigned int v100; // eax
  int v101; // [esp+0h] [ebp-1Ch] BYREF
  double v102; // [esp+10h] [ebp-Ch] BYREF

  a1.m128d_f64[0] = a8;
  a7.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
  a3.m128d_f64[0] = 1.0;
  v9 = _mm_and_pd(a7, a1);
  a5.m128d_f64[0] = a8;
  inserted = (__m128d)_mm_srli_epi64((__m128i)a1, 0x2Cu);
  v13 = _mm_or_pd(v9, a3);
  epi16 = _mm_extract_epi16((__m128i)a5, 3);
  v12 = ((unsigned __int8)_mm_extract_epi16((__m128i)inserted, 0) + 1) & 0x1FE;
  v13.m128d_f64[0] = v13.m128d_f64[0] * *(double *)((char *)&qword_731E00 + 4 * v12);
  a6.m128d_f64[0] = *(double *)((char *)&qword_731E00 + 4 * v12);
  v14 = *(__m128d *)((char *)&xmmword_732210 + 8 * v12);
  v15 = 32751 - epi16;
  if ( ((32751 - epi16) | (unsigned int)(epi16 - 16)) < 0x80000000 )
  {
    v16 = 0;
    v17 = 261759;
    goto BACK_MAIN;
  }
  a2.m128d_f64[0] = a9;
  a4.m128d_f64[0] = NAN;
  v56 = _mm_cvtsi128_si32((__m128i)a2);
  a3.m128d_f64[0] = a9;
  v57 = _mm_srli_epi64((__m128i)_mm_and_pd(a2, a4), 0x20u);
  v58 = _mm_cvtsi128_si32(v57);
  if ( v58 >= 0x7FF00000 )
  {
    v13.m128d_f64[0] = a8;
    a5.m128d_f64[0] = a8;
    v30 = _mm_cvtsi128_si32((__m128i)v13);
    v16 = _mm_cvtsi128_si32(_mm_srli_epi64((__m128i)v13, 0x20u));
    if ( (v16 & 0x7FFFFFFF) < 0x7FF00000 || (v16 & 0x7FFFFFFF) <= 0x7FF00000 && !v30 )
      goto Y_INF_NAN;
    goto X_NAN;
  }
  if ( !(v58 | v56) )
  {
    v74 = _mm_cvtsi128_si32((__m128i)a5);
    v75 = _mm_srli_epi64((__m128i)a5, 0x20u);
    v76 = v74;
    v69.m128d_f64[0] = 1.0;
    v70 = 26;
    if ( _mm_cvtsi128_si32(v75) & 0x7FFFFFFF | v74 )
    {
      v70 = 29;
      v77 = _mm_cvtsi128_si32(v75) & 0x7FFFFFFF;
      if ( v77 <= 0x7FF00000 && (v77 < 0x7FF00000 || !v76) )
      {
        v102 = 1.0;
        return 1.0;
      }
    }
    goto CALL_LIBM_ERROR;
  }
  if ( v15 >= 0 )
  {
    v16 = 0;
    goto DENORMAL_X;
  }
  v59 = (__m128i)_mm_or_pd(a3, (__m128d)_mm_slli_epi64((__m128i)a4, 0x34u));
  a4 = 0;
  v60 = (__m128d)_mm_max_epi16(_mm_sub_epi32(_mm_srli_epi64(v57, 0x14u), _mm_cvtsi32_si128(0x3F3u)), (__m128i)0LL);
  v61 = _mm_cmpeq_epi32(_mm_sll_epi64(v59, (__m128i)v60), (__m128i)0LL);
  v62 = _mm_movemask_epi8(v61);
  v63 = (32751 - v15) & 0x7FFF;
  if ( v63 >= 0x7FF0 )
  {
    a4.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
    v71 = (__m128d)_mm_cmpeq_epi32((__m128i)0LL, (__m128i)_mm_and_pd(a4, a5));
    if ( (unsigned __int8)_mm_movemask_epi8((__m128i)v71) == 255 )
    {
      if ( (_mm_extract_epi16((__m128i)a5, 3) & 0x8000) != 0 )
      {
        if ( v62 == 255 )
        {
          v71.m128d_f64[0] = a9;
          *(double *)v61.m128i_i64 = a9;
          v71 = (__m128d)_mm_sub_epi32(
                           _mm_srli_epi64((__m128i)_mm_and_pd(v71, (__m128d)xmmword_7356B0), 0x34u),
                           _mm_cvtsi32_si128(0x3F4u));
          if ( (unsigned __int8)_mm_movemask_epi8(_mm_cmpeq_epi32(_mm_sll_epi64(v61, (__m128i)v71), (__m128i)0LL)) != 255 )
          {
            v71.m128d_f64[0] = a9;
            if ( (_mm_extract_epi16((__m128i)v71, 3) & 0x8000) == 0 )
              return -INFINITY;
            return -0.0;
          }
        }
        v71.m128d_f64[0] = a9;
        if ( (_mm_extract_epi16((__m128i)v71, 3) & 0x8000) != 0 )
          return 0.0;
      }
      else
      {
        v71.m128d_f64[0] = a9;
        if ( (_mm_extract_epi16((__m128i)v71, 3) & 0x8000) != 0 )
          return 0.0;
      }
      return INFINITY;
    }
X_NAN:
    v69.m128d_f64[0] = a5.m128d_f64[0] + a5.m128d_f64[0];
    v70 = 1006;
    goto CALL_LIBM_ERROR;
  }
  if ( v62 != 255 )
  {
    *(double *)v61.m128i_i64 = a8;
    v72 = _mm_cvtsi128_si32(v61);
    a3 = (__m128d)_mm_srli_epi64(v61, 0x20u);
    v66 = _mm_cvtsi128_si32((__m128i)a3) & 0x7FFFFFFF | v72;
    v16 = 0;
    if ( v66 )
    {
      v69.m128d_f64[0] = NAN;
      v70 = 28;
      goto CALL_LIBM_ERROR;
    }
    goto ZERO_X;
  }
  v60.m128d_f64[0] = a9;
  *(double *)v61.m128i_i64 = a9;
  a4 = (__m128d)_mm_cvtsi32_si128(0x3F4u);
  v64 = _mm_sub_epi32(_mm_srli_epi64((__m128i)_mm_and_pd(v60, (__m128d)xmmword_7356B0), 0x34u), (__m128i)a4);
  a4.m128d_f64[0] = -0.0;
  a3 = (__m128d)_mm_cmpeq_epi32(_mm_sll_epi64(v61, v64), (__m128i)a4);
  v16 = ((unsigned __int8)_mm_movemask_epi8((__m128i)a3) + 261889) & 0x40000;
  if ( v63 >= 0x10 )
  {
    v17 = 786047;
    goto BACK_MAIN;
  }
DENORMAL_X:
  inserted = (__m128d)_mm_insert_epi16((__m128i)0LL, 0x43F0u, 3);
  v13.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
  a3.m128d_f64[0] = 1.0;
  inserted.m128d_f64[0] = inserted.m128d_f64[0] * a8;
  v65 = _mm_cvtsi128_si32((__m128i)a5);
  a5 = (__m128d)_mm_srli_epi64((__m128i)a5, 0x20u);
  v66 = _mm_cvtsi128_si32((__m128i)a5);
  if ( !v65 )
  {
ZERO_X:
    if ( (v66 & 0x7FFFFFFF) != 0 )
      goto BACK_DEN;
    if ( a9 < 0.0 )
    {
      *(_QWORD *)&v69.m128d_f64[0] = _mm_cvtsi32_si128((v16 << 13) & v66 | 0x7FF00000).m128i_u64[0] << 32;
      v70 = 27;
      goto CALL_LIBM_ERROR;
    }
    if ( ((v16 << 13) & v66) == 0 )
      return 0.0;
    return -0.0;
  }
BACK_DEN:
  v67 = _mm_and_pd(v13, inserted);
  a5.m128d_f64[0] = inserted.m128d_f64[0];
  inserted = (__m128d)_mm_srli_epi64((__m128i)_mm_and_pd(inserted, (__m128d)xmmword_7356B0), 0x2Cu);
  v13 = _mm_or_pd(v67, a3);
  v68 = ((unsigned __int8)_mm_extract_epi16((__m128i)inserted, 0) + 1) & 0x1FE;
  v13.m128d_f64[0] = v13.m128d_f64[0] * *(double *)((char *)&qword_731E00 + 4 * v68);
  a6.m128d_f64[0] = *(double *)((char *)&qword_731E00 + 4 * v68);
  v14 = *(__m128d *)((char *)&xmmword_732210 + 8 * v68);
  v17 = 278143;
BACK_MAIN:
  v18 = (__m128d)_mm_cvtsi32_si128(v17);
  v19 = _mm_cvtepi32_pd(_mm_srli_epi64(_mm_sub_epi64((__m128i)inserted, (__m128i)v18), 8u));
  v18.m128d_f64[0] = NAN;
  a4.m128d_f64[0] = v13.m128d_f64[0];
  v20 = (__m128d)_mm_srli_epi64((__m128i)v13, 0x26u);
  v21 = ((unsigned __int8)_mm_extract_epi16((__m128i)v20, 0) + 1) & 0x1FE;
  a4.m128d_f64[0] = a4.m128d_f64[0] * *(double *)((char *)&qword_732A20 + 4 * v21);
  a6.m128d_f64[0] = a6.m128d_f64[0] * *(double *)((char *)&qword_732A20 + 4 * v21);
  v22 = _mm_add_pd(v14, *(__m128d *)((char *)&xmmword_732E30 + 8 * v21));
  a5 = _mm_or_pd(_mm_and_pd(a5, (__m128d)xmmword_735690), (__m128d)xmmword_7356A0);
  v22.m128d_f64[0] = v22.m128d_f64[0] + v19.m128d_f64[0];
  v29 = (__m128i)_mm_and_pd(v18, a5);
  v23 = a4.m128d_f64[0];
  a4 = (__m128d)_mm_srli_epi64((__m128i)a4, 0x1Fu);
  v19.m128d_f64[0] = NAN;
  a5.m128d_f64[0] = a5.m128d_f64[0] - *(double *)v29.m128i_i64;
  v24 = ((_mm_extract_epi16((__m128i)a4, 0) & 0x1FF) + 1) & 0x3FE;
  a6.m128d_f64[0] = a6.m128d_f64[0] * *(double *)((char *)&qword_733640 + 4 * v24);
  v25 = v23 * *(double *)((char *)&qword_733640 + 4 * v24);
  v33 = _mm_add_pd(v22, *(__m128d *)((char *)&xmmword_733E50 + 8 * v24));
  v32 = _mm_and_pd(v19, a6);
  v26 = a6.m128d_f64[0] - v32.m128d_f64[0];
  v20.m128d_f64[0] = v25 + -1.442694902420044;
  a4.m128d_f64[0] = v32.m128d_f64[0];
  v27 = v25 - v32.m128d_f64[0] * *(double *)v29.m128i_i64;
  v32.m128d_f64[0] = v33.m128d_f64[0];
  v28 = v27 - *(double *)v29.m128i_i64 * v26;
  v33.m128d_f64[0] = v33.m128d_f64[0] + v20.m128d_f64[0];
  *(double *)v29.m128i_i64 = a9;
  v30 = _mm_extract_epi16((__m128i)v33, 3);
  v31 = v28 - a4.m128d_f64[0] * a5.m128d_f64[0] - a5.m128d_f64[0] * v26;
  a5.m128d_f64[0] = v33.m128d_f64[0];
  v32.m128d_f64[0] = v32.m128d_f64[0] - v33.m128d_f64[0] + v20.m128d_f64[0];
  v20.m128d_f64[0] = v20.m128d_f64[0] - v31;
  v33.m128d_f64[0] = v33.m128d_f64[0] - v31;
  v34 = _mm_unpacklo_pd(v20, v20);
  v35 = _mm_extract_epi16(v29, 3) & 0x7FF0;
  if ( v35 >= 0x7FF0 )
  {
    a5.m128d_f64[0] = a8;
    a3.m128d_f64[0] = a9;
    if ( !_mm_cvtsi128_si32((__m128i)a5) )
    {
      a5 = (__m128d)_mm_srli_epi64((__m128i)a5, 0x20u);
      v30 = _mm_cvtsi128_si32((__m128i)a5);
      if ( v30 == 1072693248 )
        goto RET_ONE;
      if ( v30 == -1074790400 )
      {
        a4.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
        if ( _mm_movemask_epi8(_mm_cmpeq_epi32((__m128i)0LL, (__m128i)_mm_and_pd(a4, a3))) == 255 )
          return 1.0;
        goto RET_Y_NAN;
      }
    }
Y_INF_NAN:
    a4.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
    if ( (unsigned __int8)_mm_movemask_epi8(_mm_cmpeq_epi32((__m128i)0LL, (__m128i)_mm_and_pd(a4, a3))) != 255 )
    {
RET_Y_NAN:
      v69.m128d_f64[0] = a3.m128d_f64[0] + a3.m128d_f64[0];
      v70 = 1006;
      goto CALL_LIBM_ERROR;
    }
    a5.m128d_f64[0] = a8;
    v73 = _mm_extract_epi16((__m128i)a3, 3) & 0x8000;
    if ( v16 ^ 0xBFF00000 | v30 )
    {
      if ( v73 )
      {
        if ( (_mm_extract_epi16((__m128i)a5, 3) & 0x7FF0u) >= 0x3FF0 )
          return 0.0;
      }
      else if ( (_mm_extract_epi16((__m128i)a5, 3) & 0x7FF0u) < 0x3FF0 )
      {
        return 0.0;
      }
      return INFINITY;
    }
RET_ONE:
    v69.m128d_f64[0] = a9 + NAN;
    v70 = 28;
    goto CALL_LIBM_ERROR;
  }
  if ( (((v30 & 0x7FF0) + v35 - 16368 - 15472) | (16544 - ((v30 & 0x7FF0) + v35 - 16368))) < 0x80000000
    || (a5 = _mm_mul_pd((__m128d)_mm_shuffle_epi32(v29, 68), v33),
        v98 = _mm_extract_epi16((__m128i)a5, 3) & 0x7FF0,
        v99 = 16544 - v98,
        v100 = v98 - 15472,
        (v100 | v99) < 0x80000000) )
  {
    v36 = v31 - (a5.m128d_f64[0] - v33.m128d_f64[0]);
    *(_QWORD *)&v37 = COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&v33.m128d_f64[0];
    v32.m128d_f64[0] = v32.m128d_f64[0] - v36;
    v38 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&a9)
        * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&v33.m128d_f64[0]);
    v33.m128d_f64[0] = v33.m128d_f64[0] - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&v33.m128d_f64[0]);
    v39 = a9 - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&a9);
    v40 = v38 * *(double *)_mm_insert_epi16((__m128i)0LL, 0x4060u, 3).m128i_i64;
    v41 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&a9) * v33.m128d_f64[0];
    v33.m128d_f64[0] = v33.m128d_f64[0] * v39;
    v42 = v41 + v37 * v39;
    *(_QWORD *)&v43 = _mm_shuffle_epi32((__m128i)v33, 238).m128i_u64[0];
    v44 = v42 + v33.m128d_f64[0];
    v45 = (int)v40;
    if ( (((int)v40 + 123391) | (130943 - (int)v40)) > 0 )
    {
      v46 = _mm_mul_pd((__m128d)xmmword_734E60, v34);
      v47 = _mm_mul_pd(v34, v34);
      v48 = (__m128i)_mm_add_pd(v46, _mm_mul_pd((__m128d)xmmword_734E70, v47));
      *(double *)v48.m128i_i64 = *(double *)v48.m128i_i64 * v47.m128d_f64[0]
                               + *(double *)_mm_shuffle_epi32(v48, 238).m128i_i64
                               + v43
                               + v32.m128d_f64[0];
      v32.m128d_f64[0] = (v40 - (v40 + 6.755399441055744e15 - 6.755399441055744e15))
                       * *(double *)_mm_insert_epi16((__m128i)0LL, 0x3F80u, 3).m128i_i64;
      v49 = (__m128i)_mm_mul_pd(
                       *((__m128d *)&unk_734E80 + ((int)v40 & 0x7F)),
                       (__m128d)_mm_shuffle_epi32(
                                  _mm_slli_epi64(_mm_cvtsi32_si128((((int)v40 + v16) & 0xFFFFFF80) + 130944), 0x2Du),
                                  68));
      v32.m128d_f64[0] = v32.m128d_f64[0] + v44 + *(double *)v48.m128i_i64 * a9;
      v50 = _mm_unpacklo_pd(v32, v32);
      v51 = _mm_mul_pd((__m128d)xmmword_7356C0, v50);
      v52 = 0.6931471805599453 * v50.m128d_f64[0];
      v53 = _mm_mul_pd(v50, v50);
      v54 = (__m128i)_mm_mul_pd(_mm_add_pd((__m128d)xmmword_7356D0, v51), v53);
      return v53.m128d_f64[0] * *(double *)v49.m128i_i64 * *(double *)v54.m128i_i64
           + *(double *)_mm_shuffle_epi32(v49, 238).m128i_i64
           + *(double *)_mm_shuffle_epi32(v54, 238).m128i_i64 * *(double *)v49.m128i_i64
           + v52 * *(double *)v49.m128i_i64
           + *(double *)v49.m128i_i64;
    }
    if ( v45 <= 0 )
    {
      if ( v45 <= -261632 )
      {
RET_ZERO_UF:
        *(_QWORD *)&v69.m128d_f64[0] = COERCE_UNSIGNED_INT64(2.225073858507201e-308 * 2.225073858507201e-308)
                                     | (_mm_cvtsi32_si128(v16).m128i_u64[0] << 45);
        v70 = 25;
        goto CALL_LIBM_ERROR;
      }
      v78 = (int)v40 & 0x7F;
      v79 = v16 + 128;
      v80 = ((int)v40 & 0xFFFFFF80) + 261760;
      v81 = 0;
    }
    else
    {
      if ( (unsigned int)v45 >= 0x40000 )
        goto RET_INF_OF;
      v78 = (int)v40 & 0x7F;
      v79 = v16 + 261888;
      v80 = ((int)v40 - 128) & 0xFFFFFF80;
      v81 = 16368;
    }
    v82 = v43 + v32.m128d_f64[0];
    v83 = _mm_mul_pd((__m128d)xmmword_734E60, v34);
    v84 = _mm_mul_pd(v34, v34);
    v32.m128d_f64[0] = v40 - (v40 + 6.755399441055744e15 - 6.755399441055744e15);
    v85 = (__m128i)_mm_add_pd(v83, _mm_mul_pd((__m128d)xmmword_734E70, v84));
    v86 = (__m128i)_mm_mul_pd(
                     *((__m128d *)&unk_734E80 + v78),
                     (__m128d)_mm_shuffle_epi32(_mm_slli_epi64(_mm_cvtsi32_si128(v80), 0x2Du), 68));
    v32.m128d_f64[0] = v32.m128d_f64[0] * *(double *)_mm_insert_epi16((__m128i)0LL, 0x3F80u, 3).m128i_i64
                     + v44
                     + (*(double *)v85.m128i_i64 * v84.m128d_f64[0]
                      + *(double *)_mm_shuffle_epi32(v85, 238).m128i_i64
                      + v82)
                     * a9;
    v87 = _mm_unpacklo_pd(v32, v32);
    v88 = _mm_mul_pd((__m128d)xmmword_7356C0, v87);
    v89 = 0.6931471805599453 * v87.m128d_f64[0];
    v69 = _mm_mul_pd(v87, v87);
    v90 = (__m128i)_mm_mul_pd(_mm_add_pd((__m128d)xmmword_7356D0, v88), v69);
    v88.m128d_f64[0] = *(double *)_mm_shuffle_epi32(v90, 238).m128i_i64;
    v69.m128d_f64[0] = v69.m128d_f64[0] * *(double *)v86.m128i_i64 * *(double *)v90.m128i_i64;
    *(_QWORD *)&v91 = _mm_cvtsi32_si128(v79).m128i_u64[0] << 45;
    v85.m128i_i8[0] = _mm_cvtsi32_si128((((unsigned __int8)((int)(130944 - v80) >> 7) + 2) & 0x20u) + ((int)(130944 - v80) >> 7) + 2).m128i_u8[0];
    *(_QWORD *)&v92 = (-1LL << v85.m128i_i8[0]) & v86.m128i_i64[0];
    v69.m128d_f64[0] = v69.m128d_f64[0]
                     + *(double *)_mm_shuffle_epi32(v86, 238).m128i_i64
                     + v88.m128d_f64[0] * *(double *)v86.m128i_i64
                     + v89 * *(double *)v86.m128i_i64;
    v93 = -1LL << v85.m128i_i8[0];
    *(double *)v86.m128i_i64 = *(double *)v86.m128i_i64 - v92;
    *(double *)v85.m128i_i64 = v92;
    *(_QWORD *)&v94 = COERCE_UNSIGNED_INT64(v92 + v69.m128d_f64[0]) & v93;
    *(_QWORD *)&v95 = _mm_insert_epi16((__m128i)0LL, v81, 3).m128i_u64[0];
    v69.m128d_f64[0] = v69.m128d_f64[0] + *(double *)v85.m128i_i64 - v94 + *(double *)v86.m128i_i64;
    if ( (int)(v80 - 130944) > 0 )
    {
      v69.m128d_f64[0] = (v69.m128d_f64[0] + v94) * v91 + v95 * ((v69.m128d_f64[0] + v94) * v91);
      v97 = _mm_extract_epi16((__m128i)v69, 3) & 0x7FF0;
      v70 = 24;
      if ( v97 != 32752 )
      {
        v70 = 25;
        if ( v97 )
        {
          v102 = v69.m128d_f64[0];
          return v69.m128d_f64[0];
        }
      }
    }
    else
    {
      v69.m128d_f64[0] = v69.m128d_f64[0] * v91 + v94 * v91 + v95 * (v69.m128d_f64[0] * v91 + v94 * v91);
      v96 = _mm_extract_epi16((__m128i)v69, 3) & 0x7FF0;
      v70 = 24;
      if ( v96 != 32752 )
      {
        v70 = 25;
        if ( v96 )
        {
          v102 = v69.m128d_f64[0];
          return v69.m128d_f64[0];
        }
      }
    }
CALL_LIBM_ERROR:
    v102 = v69.m128d_f64[0];
    sub_63C1AB((double *)&v101 + 4, (int)&a9, &v102, v70);
    return v102;
  }
  if ( v100 < 0x80000000 )
  {
    a5.m128d_f64[0] = a8;
    if ( (((unsigned __int16)((_mm_extract_epi16((__m128i)a5, 3) & 0x7FF0) - 16368)
         ^ (unsigned __int16)_mm_extract_epi16(v29, 3))
        & 0x8000) == 0 )
    {
RET_INF_OF:
      v70 = 24;
      if ( v16 )
        v69.m128d_f64[0] = -INFINITY;
      else
        v69.m128d_f64[0] = INFINITY;
      goto CALL_LIBM_ERROR;
    }
    goto RET_ZERO_UF;
  }
  *(_QWORD *)&result = _mm_cvtsi32_si128(v16 | 0x1FF80).m128i_u64[0] << 45;
  return result;
}
