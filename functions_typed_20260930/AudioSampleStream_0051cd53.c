const void **__cdecl sub_51CD53(int a1, int a2, const void **a3, int a4, int a5, _DWORD *a6, int a7)
{
  int v7; // esi
  _DWORD *v8; // ebx
  unsigned int v9; // edi
  const void **result; // eax
  int *v11; // eax
  int v12; // [esp+Ch] [ebp-8h] BYREF
  int v13; // [esp+10h] [ebp-4h]
  unsigned int v14; // [esp+34h] [ebp+20h]

  v7 = *(_DWORD *)(a1 + 412);
  if ( *(_BYTE *)(v7 + 36) )
  {
    v8 = a6;
    v9 = 1;
    result = F_2DArrayBlockCopy(v7 + 32, 0, a5 + 4 * *a6, 0, 1, *(_DWORD *)(v7 + 40));
    *(_BYTE *)(v7 + 36) = 0;
  }
  else
  {
    v9 = 2;
    if ( *(_DWORD *)(v7 + 44) < 2u )
      v9 = *(_DWORD *)(v7 + 44);
    v8 = a6;
    v14 = a7 - *a6;
    if ( v9 > v14 )
      v9 = v14;
    v11 = (int *)(a5 + 4 * *a6);
    v12 = *v11;
    if ( v9 <= 1 )
    {
      v13 = *(_DWORD *)(v7 + 32);
      *(_BYTE *)(v7 + 36) = 1;
    }
    else
    {
      v13 = v11[1];
    }
    result = (const void **)(*(int (__cdecl **)(int, int, const void *, int *))(v7 + 12))(a1, a2, *a3, &v12);
  }
  *v8 += v9;
  *(_DWORD *)(v7 + 44) -= v9;
  if ( !*(_BYTE *)(v7 + 36) )
  {
    result = a3;
    *a3 = (char *)*a3 + 1;
  }
  return result;
}

