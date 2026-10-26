_DWORD *__cdecl sub_516772(_DWORD *a1, unsigned int a2)
{
  unsigned int v2; // ebx
  _DWORD *v3; // esi
  int i; // edi
  int j; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // ebx
  int v8; // edi
  _DWORD **v9; // ecx
  _DWORD *result; // eax
  _DWORD *v11; // ebx
  int v12; // edi

  v2 = a2;
  v3 = (_DWORD *)a1[1];
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*a1 + 20) = 12;
    *(_DWORD *)(*a1 + 24) = a2;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( a2 == 1 )
  {
    for ( i = v3[16]; i; i = *(_DWORD *)(i + 36) )
    {
      if ( *(_BYTE *)(i + 34) )
      {
        *(_BYTE *)(i + 34) = 0;
        (*(void (__cdecl **)(_DWORD *, int))(i + 48))(a1, i + 40);
      }
    }
    v3[16] = 0;
    for ( j = v3[17]; j; j = *(_DWORD *)(j + 36) )
    {
      if ( *(_BYTE *)(j + 34) )
      {
        *(_BYTE *)(j + 34) = 0;
        (*(void (__cdecl **)(_DWORD *, int))(j + 48))(a1, j + 40);
      }
    }
    v3[17] = 0;
  }
  v6 = (_DWORD *)v3[a2 + 14];
  v3[a2 + 14] = 0;
  if ( v6 )
  {
    do
    {
      v7 = (_DWORD *)*v6;
      v8 = v6[2] + v6[1] + 16;
      FreeWrapper_9351(a1, v6);
      v3[18] -= v8;
      v6 = v7;
    }
    while ( v7 );
    v2 = a2;
  }
  v9 = (_DWORD **)&v3[v2 + 12];
  result = *v9;
  *v9 = 0;
  if ( result )
  {
    do
    {
      v11 = (_DWORD *)*result;
      v12 = result[2] + result[1] + 16;
      FreeWrapper_9351(a1, result);
      v3[18] -= v12;
      result = v11;
    }
    while ( v11 );
  }
  return result;
}

