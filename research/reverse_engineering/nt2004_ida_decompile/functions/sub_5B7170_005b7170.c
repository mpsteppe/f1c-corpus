int __thiscall sub_5B7170(_DWORD *this)
{
  int v1; // edx
  unsigned int *v2; // edx
  int result; // eax
  int v4; // edi
  int v5; // esi
  int v6; // [esp+Ch] [ebp-4h]

  v1 = this[3];
  if ( ((unsigned int)&unk_800000 & *(_DWORD *)(this[6] + 20)) != 0 )
  {
    v2 = (unsigned int *)(v1 + 40);
    result = 16;
  }
  else
  {
    v2 = (unsigned int *)(v1 + 24);
    result = 12;
  }
  v4 = 0;
  if ( (int)this[2] > 0 )
  {
    v6 = 4 * result;
    v5 = 0;
    do
    {
      *(_DWORD *)(this[8] + v5 + 24) = _mm_cvtsi64_si32(
                                         _m_packuswb(
                                           _m_psrlwi(
                                             _m_pmullw(
                                               _m_paddw(
                                                 _m_punpcklbw(_mm_cvtsi32_si64(*v2), (__m64)qword_7E5EB0),
                                                 (__m64)qword_7E8D68),
                                               _m_punpcklbw(
                                                 _mm_cvtsi32_si64(*(_DWORD *)(this[8] + v5 + 24)),
                                                 (__m64)qword_7E5EB0)),
                                             8u),
                                           (__m64)qword_7E5EB0));
      result = this[2];
      v2 = (unsigned int *)((char *)v2 + v6);
      ++v4;
      v5 += 64;
    }
    while ( v4 < result );
  }
  _m_empty();
  return result;
}
