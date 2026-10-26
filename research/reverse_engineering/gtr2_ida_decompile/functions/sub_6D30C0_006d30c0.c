_DWORD *__stdcall sub_6D30C0(int a1, int a2, _DWORD *a3, int a4, int a5, unsigned int *a6, int a7)
{
  int v7; // esi
  unsigned int *v8; // ebx
  unsigned int v9; // edi
  unsigned int v10; // eax
  _DWORD *result; // eax
  unsigned int v12; // edx
  int v13; // [esp+Ch] [ebp-8h] BYREF
  int v14; // [esp+10h] [ebp-4h]

  v7 = *(_DWORD *)(a1 + 456);
  if ( *(_DWORD *)(v7 + 36) )
  {
    v8 = a6;
    sub_6B5FF0(v7 + 32, 0, a5 + 4 * *a6, 0, 1, *(_DWORD *)(v7 + 40));
    v9 = 1;
    *(_DWORD *)(v7 + 36) = 0;
  }
  else
  {
    v9 = 2;
    if ( *(_DWORD *)(v7 + 44) < 2u )
      v9 = *(_DWORD *)(v7 + 44);
    v8 = a6;
    v10 = *a6;
    if ( v9 > a7 - *a6 )
      v9 = a7 - *a6;
    v13 = *(_DWORD *)(a5 + 4 * v10);
    if ( v9 <= 1 )
    {
      v14 = *(_DWORD *)(v7 + 32);
      *(_DWORD *)(v7 + 36) = 1;
    }
    else
    {
      v14 = *(_DWORD *)(a5 + 4 * v10 + 4);
    }
    (*(void (__stdcall **)(int, int, _DWORD, int *))(v7 + 12))(a1, a2, *a3, &v13);
  }
  result = *(_DWORD **)(v7 + 36);
  v12 = v9 + *v8;
  *(_DWORD *)(v7 + 44) -= v9;
  *v8 = v12;
  if ( !result )
  {
    result = a3;
    ++*a3;
  }
  return result;
}
