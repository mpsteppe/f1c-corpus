unsigned int __cdecl sub_558CF0(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  _DWORD *v7; // esi
  unsigned int *v8; // edi
  unsigned int v9; // ecx
  unsigned int result; // eax
  unsigned int v11; // [esp+14h] [ebp+8h]
  unsigned int v12; // [esp+14h] [ebp+8h]

  v7 = (_DWORD *)a1[98];
  v8 = v7 + 6;
  if ( !v7[6] )
    v7[3] = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, _DWORD, int))(a1[1] + 28))(a1, v7[2], v7[5], v7[4], 1);
  v11 = *v8;
  (*(void (__cdecl **)(_DWORD *, int, int, int, _DWORD, _DWORD *, _DWORD))(a1[103] + 4))(
    a1,
    a2,
    a3,
    a4,
    v7[3],
    v7 + 6,
    v7[4]);
  v9 = v11;
  if ( *v8 > v11 )
  {
    v12 = *v8 - v11;
    (*(void (__cdecl **)(_DWORD *, unsigned int, _DWORD, unsigned int))(a1[105] + 4))(a1, v7[3] + 4 * v9, 0, v12);
    *a6 += v12;
  }
  result = v7[4];
  if ( *v8 >= result )
  {
    v7[5] += result;
    *v8 = 0;
  }
  return result;
}
