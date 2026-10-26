char __cdecl sub_54D78E(_DWORD *a1)
{
  unsigned __int8 **v2; // edi
  unsigned __int8 *v3; // ebx
  unsigned __int16 v4; // ax
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // ebx
  unsigned __int8 v7; // al
  int v8; // ecx
  bool v9; // cc
  int v10; // edx
  _DWORD *v11; // eax
  int v12; // ecx
  int v13; // edx
  unsigned __int8 v14; // al
  int v16; // ecx
  _BYTE v17[11]; // [esp+Ch] [ebp-14h]
  unsigned __int8 v18; // [esp+17h] [ebp-9h]
  int v19; // [esp+18h] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *v21; // [esp+28h] [ebp+8h]
  unsigned __int8 *v22; // [esp+28h] [ebp+8h]
  unsigned __int8 *v23; // [esp+28h] [ebp+8h]

  v2 = (unsigned __int8 **)a1[5];
  v3 = *v2;
  v21 = v2[1];
  if ( !v21 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v3 = *v2;
    v21 = v2[1];
  }
  v22 = v21 - 1;
  LOBYTE(v4) = 0;
  HIBYTE(v4) = *v3;
  v5 = v3 + 1;
  v20 = v4;
  if ( v22 )
    goto LABEL_7;
  if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
    return 0;
  v5 = *v2;
  v22 = v2[1];
LABEL_7:
  v23 = v22 - 1;
  v20 = *v5 + v20 - 2;
  v6 = v5 + 1;
  if ( v20 < 12 )
  {
    v16 = v20;
    *(_DWORD *)(*a1 + 20) = 77;
    *(_DWORD *)(*a1 + 24) = v16;
    goto LABEL_22;
  }
  v19 = 0;
  do
  {
    if ( !v23 )
    {
      if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
        return 0;
      v6 = *v2;
      v23 = v2[1];
    }
    --v23;
    v7 = *v6;
    v8 = v19;
    ++v6;
    v9 = ++v19 < 12;
    v17[v8] = v7;
  }
  while ( v9 );
  v20 -= 12;
  if ( v17[0] != 65 || v17[1] != 100 || v17[2] != 111 || v17[3] != 98 || v17[4] != 101 )
  {
    *(_DWORD *)(*a1 + 20) = 77;
    *(_DWORD *)(*a1 + 24) = v20 + 12;
LABEL_22:
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
    goto LABEL_23;
  }
  v10 = v17[8];
  v11 = (_DWORD *)(*a1 + 24);
  *v11 = v17[6] + (v17[5] << 8);
  v12 = v10 + (v17[7] << 8);
  v13 = v17[10];
  v11[1] = v12;
  v11[2] = v13 + (v17[9] << 8);
  v11[3] = v18;
  *(_DWORD *)(*a1 + 20) = 75;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  v14 = v18;
  *((_BYTE *)a1 + 262) = 1;
  *((_BYTE *)a1 + 263) = v14;
LABEL_23:
  v9 = v20 <= 0;
  *v2 = v6;
  v2[1] = v23;
  if ( !v9 )
    (*(void (__cdecl **)(_DWORD *, int))(a1[5] + 16))(a1, v20);
  return 1;
}
