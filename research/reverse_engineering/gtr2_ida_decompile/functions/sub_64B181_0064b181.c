int __stdcall sub_64B181(unsigned int *a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  __m64 *v7; // eax
  unsigned int *v8; // edx
  __m64 *v9; // edi
  __m64 *v10; // esi
  int v11; // ebx
  __m64 *i; // eax
  __m64 v13; // mm5
  __m64 v14; // mm7
  __m64 v15; // mm2
  __m64 v16; // mm3
  __m64 *v17; // ecx
  __m64 v18; // mm0
  __m64 *v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+28h] [ebp+10h]
  signed int v21; // [esp+2Ch] [ebp+14h]

  if ( (a3 & 3) != 0 )
    return sub_64AF49(a1, a2, a3, a4, a5, a6);
  v21 = a2 + a5 * a4;
  _m_empty();
  v20 = 4 * a3;
  v7 = (__m64 *)a2;
  v8 = a1;
  if ( (int)a2 < v21 )
  {
    do
    {
      v9 = v7;
      v10 = (__m64 *)((char *)v7 + a5);
      v11 = (int)v7 + v20;
      v19 = v7;
      for ( i = (__m64 *)v8;
            (int)v9 < v11;
            v17->m64_u64 = (unsigned __int64)_m_packuswb(
                                               _m_psrawi(
                                                 _m_paddw(_m_paddw(_m_paddw(v18, v15), v16), (__m64)0x2000200020002LL),
                                                 2u),
                                               _m_psrawi(
                                                 _m_paddw(
                                                   _m_paddw(
                                                     _m_paddw(
                                                       _m_paddw(_m_punpcklbw(v13, 0), _m_punpckhbw(v13, 0)),
                                                       _m_punpcklbw(v14, 0)),
                                                     _m_punpckhbw(v14, 0)),
                                                   (__m64)0x2000200020002LL),
                                                 2u)) )
      {
        v13 = v9[1];
        v14 = v10[1];
        v15 = _m_punpcklbw((__m64)v10->m64_u64, 0);
        v16 = _m_punpckhbw((__m64)v10->m64_u64, 0);
        v17 = i;
        v18 = _m_paddw(_m_punpcklbw((__m64)v9->m64_u64, 0), _m_punpckhbw((__m64)v9->m64_u64, 0));
        v9 += 2;
        v10 += 2;
        ++i;
      }
      v7 = (__m64 *)((char *)v19 + a5 + a5);
      v8 = (unsigned int *)((char *)v8 + a6);
    }
    while ( (int)v7 < v21 );
  }
  _m_empty();
  return 0;
}
