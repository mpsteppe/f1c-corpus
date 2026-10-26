_DWORD *__cdecl sub_558F4F(_DWORD *a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6, int a7)
{
  int v8; // esi
  int v9; // edi
  unsigned int v10; // edi
  _DWORD *result; // eax
  int v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+18h] [ebp+8h]
  unsigned int v14; // [esp+30h] [ebp+20h]

  v8 = a1[103];
  if ( *(_DWORD *)(v8 + 92) >= a1[68] )
  {
    v13 = 0;
    v12 = a1[49];
    if ( (int)a1[8] > 0 )
    {
      v9 = v8 + 12;
      do
      {
        (*(void (__cdecl **)(_DWORD *, int, int, int))(v9 + 40))(
          a1,
          v12,
          *(_DWORD *)(a2 + 4 * v13) + 4 * *a3 * *(_DWORD *)(v9 + 88),
          v9);
        v12 += 84;
        ++v13;
        v9 += 4;
      }
      while ( v13 < a1[8] );
    }
    *(_DWORD *)(v8 + 92) = 0;
  }
  v10 = a1[68] - *(_DWORD *)(v8 + 92);
  if ( v10 > *(_DWORD *)(v8 + 96) )
    v10 = *(_DWORD *)(v8 + 96);
  v14 = a7 - *a6;
  if ( v10 > v14 )
    v10 = v14;
  (*(void (__cdecl **)(_DWORD *, int, _DWORD, int, unsigned int))(a1[104] + 4))(
    a1,
    v8 + 12,
    *(_DWORD *)(v8 + 92),
    a5 + 4 * *a6,
    v10);
  result = a6;
  *a6 += v10;
  *(_DWORD *)(v8 + 96) -= v10;
  *(_DWORD *)(v8 + 92) += v10;
  if ( *(_DWORD *)(v8 + 92) >= a1[68] )
  {
    result = a3;
    ++*a3;
  }
  return result;
}
