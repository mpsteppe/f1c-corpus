int __thiscall sub_55EB30(_DWORD *this)
{
  int result; // eax
  int v2; // edi
  int v3; // esi
  int v4; // edx

  result = this[2];
  v2 = 0;
  if ( result > 0 )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      *(_DWORD *)(v3 + this[8] + 24) = _mm_cvtsi64_si32(
                                         _m_packuswb(
                                           _m_psrlwi(
                                             _m_pmullw(
                                               _m_paddw(
                                                 _m_punpcklbw(
                                                   _mm_cvtsi32_si64(*(_DWORD *)(this[3] + v4 + 24)),
                                                   (__m64)qword_8B6C20),
                                                 (__m64)qword_8B8E40),
                                               _m_punpcklbw(
                                                 _mm_cvtsi32_si64(*(_DWORD *)(v3 + this[8] + 24)),
                                                 (__m64)qword_8B6C20)),
                                             8u),
                                           (__m64)qword_8B6C20));
      result = this[2];
      ++v2;
      v4 += 48;
      v3 += 64;
    }
    while ( v2 < result );
  }
  _m_empty();
  return result;
}
