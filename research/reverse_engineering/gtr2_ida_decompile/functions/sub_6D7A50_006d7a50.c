int __userpurge sub_6D7A50@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<ebx>, int a4, int a5)
{
  int v5; // eax
  int result; // eax
  int v7; // edx
  __m64 *v8; // esi
  __m64 *v9; // edi
  __m64 *v10; // ebx
  __m64 v11; // mm1
  __m64 v12; // mm5
  int v13; // [esp-4h] [ebp-18h]
  int v14; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]

  v5 = *(_DWORD *)(a2 + 28);
  v14 = 8 * v5;
  v15 = *(_DWORD *)(a2 + 12);
  sub_6D75E0(16 * v5, a3, a4, *(_DWORD *)(a1 + 244), *(_DWORD *)(a1 + 28));
  result = 0;
  do
  {
    v7 = v14;
    v8 = *(__m64 **)(a5 + 4 * result);
    v9 = *(__m64 **)(a4 + 4 * result);
    v13 = result;
    v10 = *(__m64 **)(a4 + 4 * (result + 1));
    do
    {
      v11 = _m_psrlwi(
              _m_paddw(
                _m_paddw(
                  _m_paddw(_m_psrlwi((__m64)v9->m64_u64, 8u), _m_pand((__m64)v9->m64_u64, (__m64)0xFF00FF00FF00FFLL)),
                  _m_paddw(_m_pand((__m64)v10->m64_u64, (__m64)0xFF00FF00FF00FFLL), _m_psrlwi((__m64)v10->m64_u64, 8u))),
                (__m64)0x2000100020001LL),
              2u);
      v12 = _m_psrlwi(
              _m_paddw(
                _m_paddw(
                  _m_paddw(_m_psrlwi(v9[1], 8u), _m_pand(v9[1], (__m64)0xFF00FF00FF00FFLL)),
                  _m_paddw(_m_psrlwi(v10[1], 8u), _m_pand(v10[1], (__m64)0xFF00FF00FF00FFLL))),
                (__m64)0x2000100020001LL),
              2u);
      v9 += 2;
      v10 += 2;
      v7 -= 8;
      v8->m64_u64 = (unsigned __int64)_m_packuswb(v11, v12);
      ++v8;
    }
    while ( v7 >= 8 );
    ++result;
  }
  while ( v13 + 1 < v15 );
  _m_empty();
  return result;
}
