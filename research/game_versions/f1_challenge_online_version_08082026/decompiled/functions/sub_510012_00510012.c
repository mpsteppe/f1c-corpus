char __usercall sub_510012@<al>(char a1@<cl>, int a2@<esi>, char a3)
{
  unsigned __int8 **v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi
  unsigned __int16 v6; // ax
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // edi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int16 v11; // ax
  unsigned __int8 *v12; // edi
  unsigned __int8 *v13; // edi
  unsigned __int16 v14; // ax
  unsigned __int8 *v15; // edi
  unsigned __int8 *v16; // edi
  int v17; // ecx
  _DWORD *v18; // eax
  unsigned __int8 *v19; // edi
  _DWORD *v20; // eax
  int v22; // ecx
  unsigned __int8 *v23; // edi
  int v24; // ecx
  unsigned __int8 *v25; // edi
  int v26; // edx
  _DWORD *v27; // ecx
  int v28; // [esp+8h] [ebp-8h]
  unsigned __int8 *v29; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v30; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v31; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v32; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v33; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v34; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v35; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v36; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v37; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v38; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v39; // [esp+Ch] [ebp-4h]
  int v40; // [esp+18h] [ebp+8h]
  int v41; // [esp+18h] [ebp+8h]
  int v42; // [esp+18h] [ebp+8h]
  _DWORD *v43; // [esp+18h] [ebp+8h]

  v3 = *(unsigned __int8 ***)(a2 + 20);
  v4 = v3[1];
  v5 = *v3;
  *(_BYTE *)(a2 + 200) = a1;
  v29 = v4;
  *(_BYTE *)(a2 + 201) = a3;
  if ( !v4 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
      return 0;
    v5 = *v3;
    v29 = v3[1];
  }
  v30 = v29 - 1;
  LOBYTE(v6) = 0;
  HIBYTE(v6) = *v5;
  v7 = v5 + 1;
  v40 = v6;
  if ( !v30 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
      return 0;
    v7 = *v3;
    v30 = v3[1];
  }
  v31 = v30 - 1;
  v41 = *v7 + v40;
  v8 = v7 + 1;
  if ( !v31 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
      return 0;
    v8 = *v3;
    v31 = v3[1];
  }
  v9 = *v8;
  v32 = v31 - 1;
  v10 = v8 + 1;
  *(_DWORD *)(a2 + 192) = v9;
  if ( !v32 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
      return 0;
    v10 = *v3;
    v32 = v3[1];
  }
  v33 = v32 - 1;
  LOBYTE(v11) = 0;
  HIBYTE(v11) = *v10;
  v12 = v10 + 1;
  *(_DWORD *)(a2 + 28) = v11;
  if ( !v33 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
      return 0;
    v12 = *v3;
    v33 = v3[1];
  }
  v34 = v33 - 1;
  *(_DWORD *)(a2 + 28) += *v12;
  v13 = v12 + 1;
  if ( !v34 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
      return 0;
    v13 = *v3;
    v34 = v3[1];
  }
  v35 = v34 - 1;
  LOBYTE(v14) = 0;
  HIBYTE(v14) = *v13;
  v15 = v13 + 1;
  *(_DWORD *)(a2 + 24) = v14;
  if ( !v35 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
      return 0;
    v15 = *v3;
    v35 = v3[1];
  }
  v36 = v35 - 1;
  *(_DWORD *)(a2 + 24) += *v15;
  v16 = v15 + 1;
  if ( !v36 )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
    {
      v16 = *v3;
      v36 = v3[1];
      goto LABEL_25;
    }
    return 0;
  }
LABEL_25:
  v17 = *(_DWORD *)(a2 + 376);
  v37 = v36 - 1;
  v42 = v41 - 8;
  *(_DWORD *)(a2 + 32) = *v16;
  v18 = (_DWORD *)(*(_DWORD *)a2 + 24);
  *v18 = v17;
  v18[1] = *(_DWORD *)(a2 + 24);
  v18[2] = *(_DWORD *)(a2 + 28);
  v18[3] = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(*(_DWORD *)a2 + 20) = 99;
  v19 = v16 + 1;
  (*(void (__cdecl **)(int, int))(*(_DWORD *)a2 + 4))(a2, 1);
  if ( *(_BYTE *)(*(_DWORD *)(a2 + 400) + 81) )
  {
    *(_DWORD *)(*(_DWORD *)a2 + 20) = 57;
    (**(void (__cdecl ***)(int))a2)(a2);
  }
  if ( !*(_DWORD *)(a2 + 28) || !*(_DWORD *)(a2 + 24) || *(int *)(a2 + 32) <= 0 )
  {
    *(_DWORD *)(*(_DWORD *)a2 + 20) = 31;
    (**(void (__cdecl ***)(int))a2)(a2);
  }
  if ( v42 != 3 * *(_DWORD *)(a2 + 32) )
  {
    *(_DWORD *)(*(_DWORD *)a2 + 20) = 9;
    (**(void (__cdecl ***)(int))a2)(a2);
  }
  if ( !*(_DWORD *)(a2 + 196) )
    *(_DWORD *)(a2 + 196) = (**(int (__cdecl ***)(int, int, int))(a2 + 4))(a2, 1, 84 * *(_DWORD *)(a2 + 32));
  v28 = 0;
  v20 = *(_DWORD **)(a2 + 196);
  v43 = v20;
  if ( *(int *)(a2 + 32) > 0 )
  {
    while ( 1 )
    {
      v20[1] = v28;
      if ( !v37 )
      {
        if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
          return 0;
        v19 = *v3;
        v37 = v3[1];
        v20 = v43;
      }
      v22 = *v19;
      v38 = v37 - 1;
      v23 = v19 + 1;
      *v20 = v22;
      if ( !v38 )
      {
        if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
          return 0;
        v23 = *v3;
        v38 = v3[1];
        v20 = v43;
      }
      v24 = *v23;
      v39 = v38 - 1;
      v25 = v23 + 1;
      v20[2] = (v24 >> 4) & 0xF;
      v20[3] = v24 & 0xF;
      if ( !v39 )
      {
        if ( !((unsigned __int8 (__cdecl *)(int))v3[3])(a2) )
          return 0;
        v25 = *v3;
        v39 = v3[1];
        v20 = v43;
      }
      v26 = *v20;
      v37 = v39 - 1;
      v20[4] = *v25;
      v27 = (_DWORD *)(*(_DWORD *)a2 + 24);
      *v27 = v26;
      v27[1] = v20[2];
      v27[2] = v20[3];
      v27[3] = v20[4];
      *(_DWORD *)(*(_DWORD *)a2 + 20) = 100;
      v19 = v25 + 1;
      (*(void (__cdecl **)(int, int))(*(_DWORD *)a2 + 4))(a2, 1);
      ++v28;
      v43 += 21;
      if ( v28 >= *(_DWORD *)(a2 + 32) )
        break;
      v20 = v43;
    }
  }
  *(_BYTE *)(*(_DWORD *)(a2 + 400) + 81) = 1;
  v3[1] = v37;
  *v3 = v19;
  return 1;
}
