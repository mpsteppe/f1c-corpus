double __usercall start_3@<st0>(__m128d a1@<xmm0>, double a2)
{
  __m128d v2; // xmm0
  int v3; // eax
  __m128d v4; // xmm7
  __m128d v5; // xmm1
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  __m128d v9; // xmm0
  __m128d v10; // xmm2
  __m128d v11; // xmm4
  __m128d v12; // xmm0
  __m128d v13; // xmm0
  __m128i v14; // xmm2
  int v16; // edx
  int v17; // eax
  unsigned int v18; // ecx
  int v19; // edx
  unsigned int v20; // eax
  _TBYTE v21; // [esp+10h] [ebp-Ch] BYREF

  v2 = _mm_unpacklo_pd(a1, a1);
  v3 = _mm_extract_epi16((__m128i)v2, 3) & 0x7FFF;
  if ( ((v3 - 15504) | (unsigned int)(16527 - v3)) < 0x80000000 )
  {
    v4 = _mm_add_pd(_mm_mul_pd((__m128d)xmmword_748E60, v2), (__m128d)xmmword_748E40);
    v5 = _mm_sub_pd(v4, (__m128d)xmmword_748E40);
    v6 = _mm_cvtsi128_si32((__m128i)v4);
    v7 = 16 * (v6 & 0x3F);
    v8 = v6 >> 6;
    v9 = _mm_sub_pd(_mm_sub_pd(v2, _mm_mul_pd((__m128d)xmmword_748E70, v5)), _mm_mul_pd((__m128d)xmmword_748E80, v5));
    v10 = *(__m128d *)(v7 + 7638704);
    v11 = _mm_mul_pd((__m128d)xmmword_748E90, v9);
    v5.m128d_f64[0] = v9.m128d_f64[0];
    v12 = _mm_mul_pd(v9, v9);
    v12.m128d_f64[0] = v12.m128d_f64[0] * v12.m128d_f64[0];
    v13 = _mm_mul_pd(v12, _mm_add_pd((__m128d)xmmword_748EA0, v11));
    v5.m128d_f64[0] = v5.m128d_f64[0] + v10.m128d_f64[0] + v13.m128d_f64[0];
    v14 = (__m128i)_mm_or_pd(
                     _mm_unpackhi_pd(v10, v10),
                     (__m128d)_mm_slli_epi64(
                                _mm_add_epi64(
                                  _mm_and_si128((__m128i)v4, _mm_load_si128((const __m128i *)&xmmword_748E20)),
                                  _mm_load_si128((const __m128i *)&xmmword_748E30)),
                                0x2Eu));
    v2 = _mm_unpackhi_pd(v13, v13);
    v2.m128d_f64[0] = v2.m128d_f64[0] + v5.m128d_f64[0];
    if ( (unsigned int)(v8 + 894) <= 0x77C )
      return v2.m128d_f64[0] * *(double *)v14.m128i_i64 + *(double *)v14.m128i_i64;
    v16 = v8;
    v17 = v8 >> 1;
    *(_QWORD *)((char *)&v21 + 2) = _mm_andnot_si128(_mm_load_si128((const __m128i *)&xmmword_748E10), v14).m128i_u64[0]
                                  | (_mm_cvtsi32_si128(v17 + 1023).m128i_u64[0] << 52);
    v2.m128d_f64[0] = (v2.m128d_f64[0] * *(double *)((char *)&v21 + 2) + *(double *)((char *)&v21 + 2))
                    * COERCE_DOUBLE(_mm_cvtsi32_si128(v16 - v17 + 1023).m128i_u64[0] << 52);
    v18 = _mm_extract_epi16((__m128i)v2, 3) & 0x7FF0;
    if ( v18 >= 0x7FF0 )
    {
      v19 = 14;
    }
    else
    {
      if ( v18 )
        goto RETURN;
      v19 = 15;
    }
CALL_LIBM_ERROR_0:
    *(double *)&v21 = v2.m128d_f64[0];
    sub_63C1AB(&a2, (int)&a2, (double *)&v21, v19);
    v2.m128d_f64[0] = *(double *)&v21;
RETURN:
    *(double *)&v21 = v2.m128d_f64[0];
    return v2.m128d_f64[0];
  }
  v20 = HIDWORD(a2) & 0x7FFFFFFF;
  if ( (HIDWORD(a2) & 0x7FFFFFFFu) < 0x40900000 )
    return a2 + 1.0;
  if ( v20 < 0x7FF00000 )
  {
    if ( HIDWORD(a2) >= 0x80000000 )
    {
      v2.m128d_f64[0] = 2.225073858507201e-308 * 2.225073858507201e-308;
      v19 = 15;
    }
    else
    {
      v2.m128d_f64[0] = 1.797693134862316e308 * 1.797693134862316e308;
      v19 = 14;
    }
    goto CALL_LIBM_ERROR_0;
  }
  if ( v20 > 0x7FF00000 || LODWORD(a2) )
  {
    v19 = 1002;
    goto CALL_LIBM_ERROR_0;
  }
  if ( HIDWORD(a2) == 2146435072 )
    return INFINITY;
  else
    return 0.0;
}
