char __cdecl sub_510F89(int a1)
{
  int v1; // eax
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int16 v5; // cx
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int16 v10; // cx
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // edi
  int v14; // [esp+Ch] [ebp-4h]
  int v15; // [esp+Ch] [ebp-4h]
  int v16; // [esp+Ch] [ebp-4h]
  int v17; // [esp+Ch] [ebp-4h]

  v1 = a1;
  v2 = *(unsigned __int8 ***)(a1 + 20);
  v3 = v2[1];
  v4 = *v2;
  if ( !v3 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v2[3])(a1) )
      return 0;
    v4 = *v2;
    v3 = v2[1];
    v1 = a1;
  }
  LOBYTE(v5) = 0;
  HIBYTE(v5) = *v4;
  v6 = v3 - 1;
  v7 = v4 + 1;
  v14 = v5;
  if ( !v6 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v2[3])(v1) )
      return 0;
    v7 = *v2;
    v6 = v2[1];
    v1 = a1;
  }
  v15 = *v7 + v14;
  v8 = v6 - 1;
  v9 = v7 + 1;
  if ( v15 != 4 )
  {
    *(_DWORD *)(*(_DWORD *)v1 + 20) = 9;
    (**(void (__cdecl ***)(int))v1)(v1);
    v1 = a1;
  }
  if ( !v8 )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v2[3])(v1) )
    {
      v9 = *v2;
      v8 = v2[1];
      v1 = a1;
      goto LABEL_12;
    }
    return 0;
  }
LABEL_12:
  LOBYTE(v10) = 0;
  HIBYTE(v10) = *v9;
  v11 = v8 - 1;
  v12 = v9 + 1;
  v16 = v10;
  if ( !v11 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v2[3])(v1) )
      return 0;
    v12 = *v2;
    v11 = v2[1];
    v1 = a1;
  }
  v17 = *v12 + v16;
  *(_DWORD *)(*(_DWORD *)v1 + 20) = 81;
  *(_DWORD *)(*(_DWORD *)v1 + 24) = v17;
  (*(void (__cdecl **)(int, int))(*(_DWORD *)v1 + 4))(v1, 1);
  *(_DWORD *)(a1 + 252) = v17;
  *v2 = v12 + 1;
  v2[1] = v11 - 1;
  return 1;
}

