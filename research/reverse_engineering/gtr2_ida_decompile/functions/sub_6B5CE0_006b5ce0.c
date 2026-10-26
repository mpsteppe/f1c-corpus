_DWORD *__stdcall sub_6B5CE0(int *a1, unsigned int a2)
{
  _DWORD *v2; // esi
  unsigned int v3; // edi
  int v4; // eax
  int i; // edi
  int v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  int v9; // ebx
  _DWORD *result; // eax
  _DWORD *v11; // edi
  int v12; // ebx

  v2 = (_DWORD *)a1[1];
  v3 = a2;
  if ( a2 >= 2 )
  {
    v4 = *a1;
    *(_DWORD *)(v4 + 20) = 14;
    *(_DWORD *)(v4 + 24) = a2;
    (*(void (__stdcall **)(int *))v4)(a1);
  }
  if ( a2 == 1 )
  {
    for ( i = v2[17]; i; i = *(_DWORD *)(i + 44) )
    {
      if ( *(_DWORD *)(i + 40) )
      {
        *(_DWORD *)(i + 40) = 0;
        (*(void (__stdcall **)(int *, int))(i + 56))(a1, i + 48);
      }
    }
    v6 = v2[18];
    for ( v2[17] = 0; v6; v6 = *(_DWORD *)(v6 + 44) )
    {
      if ( *(_DWORD *)(v6 + 40) )
      {
        *(_DWORD *)(v6 + 40) = 0;
        (*(void (__stdcall **)(int *, int))(v6 + 56))(a1, v6 + 48);
      }
    }
    v3 = a2;
    v2[18] = 0;
  }
  v7 = (_DWORD *)v2[v3 + 15];
  v2[v3 + 15] = 0;
  if ( v7 )
  {
    do
    {
      v8 = (_DWORD *)*v7;
      v9 = v7[2] + v7[1] + 16;
      sub_6D3B30(a1, v7, v9);
      v2[19] -= v9;
      v7 = v8;
    }
    while ( v8 );
    v3 = a2;
  }
  result = (_DWORD *)v2[v3 + 13];
  v2[v3 + 13] = 0;
  if ( result )
  {
    do
    {
      v11 = (_DWORD *)*result;
      v12 = result[2] + result[1] + 16;
      sub_6D3B30(a1, result, v12);
      v2[19] -= v12;
      result = v11;
    }
    while ( v11 );
  }
  return result;
}
