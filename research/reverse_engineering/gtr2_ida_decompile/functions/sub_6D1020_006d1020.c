_DWORD *__stdcall sub_6D1020(_DWORD *a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6, int a7)
{
  int v8; // ebx
  int v9; // eax
  int v10; // ecx
  int v11; // esi
  bool v12; // cc
  unsigned int v13; // esi
  int v14; // edx
  _DWORD *result; // eax
  signed int v16; // ecx
  int v17; // [esp+Ch] [ebp-4h]
  int v18; // [esp+18h] [ebp+8h]

  v8 = a1[114];
  if ( *(_DWORD *)(v8 + 92) >= a1[79] )
  {
    v9 = a1[9];
    v10 = a1[55];
    v18 = 0;
    v17 = v10;
    if ( v9 > 0 )
    {
      v11 = v8 + 12;
      do
      {
        (*(void (__stdcall **)(_DWORD *, int, int, int))(v11 + 40))(
          a1,
          v17,
          *(_DWORD *)(a2 + 4 * v18) + 4 * *a3 * *(_DWORD *)(v11 + 88),
          v11);
        v11 += 4;
        v12 = ++v18 < a1[9];
        v17 += 84;
      }
      while ( v12 );
    }
    *(_DWORD *)(v8 + 92) = 0;
  }
  v13 = a1[79] - *(_DWORD *)(v8 + 92);
  if ( v13 > *(_DWORD *)(v8 + 96) )
    v13 = *(_DWORD *)(v8 + 96);
  if ( v13 > a7 - *a6 )
    v13 = a7 - *a6;
  (*(void (__stdcall **)(_DWORD *, int, _DWORD, int, unsigned int))(a1[115] + 4))(
    a1,
    v8 + 12,
    *(_DWORD *)(v8 + 92),
    a5 + 4 * *a6,
    v13);
  v14 = *(_DWORD *)(v8 + 96);
  *a6 += v13;
  result = (_DWORD *)a1[79];
  v16 = v13 + *(_DWORD *)(v8 + 92);
  *(_DWORD *)(v8 + 96) = v14 - v13;
  *(_DWORD *)(v8 + 92) = v16;
  if ( v16 >= (int)result )
  {
    result = a3;
    ++*a3;
  }
  return result;
}
