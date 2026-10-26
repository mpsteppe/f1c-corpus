double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  __m128i v3; // xmm7
  __m128d v4; // xmm0
  int v5; // eax
  __m128i v6; // xmm2
  __m128i v7; // xmm1
  double v8; // xmm1_8
  double result; // st7
  __m128d v10; // xmm1
  __m128d v11; // xmm3
  __int64 v12; // xmm0_8
  char v13; // [esp+8h] [ebp-8h]

  if ( !dword_FBB5E0 )
    goto _floor;
  v1 = _mm_getcsr() & 0x1F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v13 & 0x7F) == 127;
  if ( v2 )
  {
    v3 = _mm_loadl_epi64((const __m128i *)&X);
    v4 = (__m128d)_mm_srli_epi64(v3, 0x34u);
    v5 = _mm_cvtsi128_si32((__m128i)v4);
    v6 = _mm_sub_epi32((__m128i)xmmword_7304A0, (__m128i)_mm_and_pd(v4, (__m128d)xmmword_7304D0));
    v7 = _mm_srl_epi64(v3, v6);
    if ( (v5 & 0x800) != 0 )
    {
      v10 = (__m128d)_mm_sll_epi64(v7, v6);
      v11 = (__m128d)_mm_loadl_epi64((const __m128i *)&X);
      v12 = *(_OWORD *)&_mm_cmplt_pd(v11, v10);
      if ( v5 < 3071 )
      {
        *(_QWORD *)&X = *(_OWORD *)&_mm_cmplt_pd(v11, (__m128d)xmmword_7304C0) & 0x3FF0000000000000LL
                      | 0x8000000000000000uLL;
        return X;
      }
      else
      {
        if ( v5 > 3122 )
          return X;
        return v10.m128d_f64[0] - COERCE_DOUBLE(v12 & 0x3FF0000000000000LL);
      }
    }
    else
    {
      if ( v5 >= 1023 )
      {
        *(_QWORD *)&v8 = v7.m128i_i64[0] << v6.m128i_i8[0];
        if ( v5 <= 1074 )
        {
          X = v8;
          return v8;
        }
        return X;
      }
      return 0.0;
    }
  }
  else
  {
_floor:
    _floor_default(X);
  }
  return result;
}
