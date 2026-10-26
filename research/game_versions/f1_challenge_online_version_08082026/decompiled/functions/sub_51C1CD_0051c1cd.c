const void **__cdecl sub_51C1CD(int a1, int a2, char **a3, int *a4)
{
  const void **result; // eax
  int v5; // ebx
  int v6; // esi
  char *v7; // edx
  _BYTE *v8; // ecx
  _BYTE *v9; // eax
  char v10; // bl
  _BYTE *v11; // ecx
  int i; // [esp+Ch] [ebp-4h]

  result = (const void **)a4;
  v5 = *a4;
  v6 = 0;
  for ( i = *a4; v6 < *(_DWORD *)(a1 + 272); v6 += 2 )
  {
    v7 = *a3;
    v8 = *(_BYTE **)(v5 + 4 * v6);
    v9 = &v8[*(_DWORD *)(a1 + 92)];
    if ( v8 < v9 )
    {
      do
      {
        v10 = *v7++;
        *v8 = v10;
        v11 = v8 + 1;
        *v11 = v10;
        v8 = v11 + 1;
      }
      while ( v8 < v9 );
      v5 = i;
    }
    result = sub_51593F(v5, v6, v5, v6 + 1, 1, *(_DWORD *)(a1 + 92));
    ++a3;
  }
  return result;
}
