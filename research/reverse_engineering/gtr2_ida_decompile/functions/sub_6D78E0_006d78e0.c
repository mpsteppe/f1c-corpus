int __userpurge sub_6D78E0@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<ebx>, int a4, int a5)
{
  int v5; // eax
  int result; // eax
  int v7; // edx
  __m64 *v8; // esi
  __m64 *v9; // edi
  __m64 v10; // mm1
  int v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

  v5 = *(_DWORD *)(a2 + 28);
  v11 = 8 * v5;
  v12 = *(_DWORD *)(a2 + 12);
  sub_6D75E0(16 * v5, a3, a4, *(_DWORD *)(a1 + 244), *(_DWORD *)(a1 + 28));
  result = 0;
  do
  {
    v7 = v11;
    v8 = *(__m64 **)(a5 + 4 * result);
    v9 = *(__m64 **)(a4 + 4 * result);
    do
    {
      v7 -= 8;
      v10 = _m_packuswb(
              _m_psrlwi(
                _m_paddw(
                  _m_paddw(_m_psrlwi((__m64)v9->m64_u64, 8u), _m_pand((__m64)v9->m64_u64, (__m64)0xFF00FF00FF00FFLL)),
                  (__m64)0x1000000010000LL),
                1u),
              _m_psrlwi(
                _m_paddw(
                  _m_paddw(_m_psrlwi(v9[1], 8u), _m_pand(v9[1], (__m64)0xFF00FF00FF00FFLL)),
                  (__m64)0x1000000010000LL),
                1u));
      v9 += 2;
      v8->m64_u64 = (unsigned __int64)v10;
      ++v8;
    }
    while ( v7 >= 8 );
    ++result;
  }
  while ( result < v12 );
  _m_empty();
  return result;
}
