int __usercall sub_6779D0@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<esi>)
{
  unsigned __int8 **v3; // eax
  unsigned __int8 *v4; // ebx
  unsigned __int8 *v5; // edi
  unsigned __int16 v6; // cx
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // edi
  int v9; // ecx
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // edi
  int v12; // ecx
  unsigned __int8 *v13; // ebx
  unsigned __int8 *v14; // edi
  unsigned __int16 v15; // dx
  unsigned __int8 *v16; // ebx
  unsigned __int8 *v17; // edi
  int v18; // edx
  unsigned __int8 *v19; // ebx
  unsigned __int8 *v20; // edi
  unsigned __int16 v21; // dx
  unsigned __int8 *v22; // ebx
  unsigned __int8 *v23; // edi
  int v24; // edx
  unsigned __int8 *v25; // ebx
  unsigned __int8 *v26; // edi
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  unsigned __int8 *v32; // ebx
  unsigned __int8 *v33; // edi
  int v34; // eax
  int v35; // eax
  int v36; // eax
  _DWORD *v37; // ecx
  int v39; // eax
  unsigned __int8 *v40; // ebx
  unsigned __int8 *v41; // edi
  unsigned __int8 *v42; // ebx
  int v43; // edx
  int v44; // eax
  unsigned __int8 *v45; // edi
  int v46; // edx
  int v47; // eax
  bool v48; // cc
  int v49; // [esp+8h] [ebp-Ch]
  int v50; // [esp+Ch] [ebp-8h]
  int v51; // [esp+Ch] [ebp-8h]
  int v52; // [esp+Ch] [ebp-8h]
  _DWORD *v53; // [esp+Ch] [ebp-8h]
  unsigned __int8 **v54; // [esp+10h] [ebp-4h]

  v3 = (unsigned __int8 **)a3[6];
  v4 = v3[1];
  v5 = *v3;
  v54 = v3;
  a3[56] = a2;
  a3[57] = a1;
  if ( !v4 )
  {
    if ( !((int (__stdcall *)(int *))v3[3])(a3) )
      return 0;
    v3 = v54;
    v5 = *v54;
    v4 = v54[1];
  }
  LOBYTE(v6) = 0;
  HIBYTE(v6) = *v5;
  v7 = v4 - 1;
  v8 = v5 + 1;
  v50 = v6;
  if ( !v7 )
  {
    if ( !((int (__stdcall *)(int *))v3[3])(a3) )
      return 0;
    v3 = v54;
    v8 = *v54;
    v7 = v54[1];
  }
  v9 = *v8 + v50;
  v10 = v7 - 1;
  v11 = v8 + 1;
  v51 = v9;
  if ( !v10 )
  {
    if ( !((int (__stdcall *)(int *))v3[3])(a3) )
      return 0;
    v3 = v54;
    v11 = *v54;
    v10 = v54[1];
  }
  v12 = *v11;
  v13 = v10 - 1;
  v14 = v11 + 1;
  a3[54] = v12;
  if ( !v13 )
  {
    if ( !((int (__stdcall *)(int *))v3[3])(a3) )
      return 0;
    v3 = v54;
    v14 = *v54;
    v13 = v54[1];
  }
  LOBYTE(v15) = 0;
  HIBYTE(v15) = *v14;
  v16 = v13 - 1;
  v17 = v14 + 1;
  a3[8] = v15;
  if ( !v16 )
  {
    if ( !((int (__stdcall *)(int *))v3[3])(a3) )
      return 0;
    v3 = v54;
    v17 = *v54;
    v16 = v54[1];
  }
  v18 = *v17 + a3[8];
  v19 = v16 - 1;
  v20 = v17 + 1;
  a3[8] = v18;
  if ( !v19 )
  {
    if ( !((int (__stdcall *)(int *))v3[3])(a3) )
      return 0;
    v3 = v54;
    v20 = *v54;
    v19 = v54[1];
  }
  LOBYTE(v21) = 0;
  HIBYTE(v21) = *v20;
  v22 = v19 - 1;
  v23 = v20 + 1;
  a3[7] = v21;
  if ( !v22 )
  {
    if ( !((int (__stdcall *)(int *))v3[3])(a3) )
      return 0;
    v3 = v54;
    v23 = *v54;
    v22 = v54[1];
  }
  v24 = *v23 + a3[7];
  v25 = v22 - 1;
  v26 = v23 + 1;
  a3[7] = v24;
  if ( !v25 )
  {
    if ( ((int (__stdcall *)(int *))v3[3])(a3) )
    {
      v26 = *v54;
      v25 = v54[1];
      goto LABEL_25;
    }
    return 0;
  }
LABEL_25:
  v27 = *a3;
  v28 = a3[105];
  a3[9] = *v26;
  v52 = v51 - 8;
  v29 = a3[7];
  *(_DWORD *)(v27 + 24) = v28;
  v30 = a3[8];
  *(_DWORD *)(v27 + 28) = v29;
  v31 = a3[9];
  *(_DWORD *)(v27 + 32) = v30;
  *(_DWORD *)(v27 + 36) = v31;
  v32 = v25 - 1;
  v33 = v26 + 1;
  *(_DWORD *)(v27 + 20) = 100;
  (*(void (__stdcall **)(int *, int))(v27 + 4))(a3, 1);
  if ( *(_DWORD *)(a3[111] + 16) )
  {
    v34 = *a3;
    *(_DWORD *)(v34 + 20) = 58;
    (*(void (__stdcall **)(int *))v34)(a3);
  }
  if ( !a3[8] || !a3[7] || a3[9] <= 0 )
  {
    v35 = *a3;
    *(_DWORD *)(v35 + 20) = 32;
    (*(void (__stdcall **)(int *))v35)(a3);
  }
  if ( v52 != 3 * a3[9] )
  {
    v36 = *a3;
    *(_DWORD *)(v36 + 20) = 11;
    (*(void (__stdcall **)(int *))v36)(a3);
  }
  if ( !a3[55] )
    a3[55] = (*(int (__stdcall **)(int *, int, int))a3[1])(a3, 1, 84 * a3[9]);
  v37 = (_DWORD *)a3[55];
  v49 = 0;
  v53 = v37;
  if ( a3[9] > 0 )
  {
    while ( 1 )
    {
      v37[1] = v49;
      if ( !v32 )
      {
        if ( !((int (__stdcall *)(int *))v54[3])(a3) )
          return 0;
        v33 = *v54;
        v32 = v54[1];
        v37 = v53;
      }
      v39 = *v33;
      v40 = v32 - 1;
      v41 = v33 + 1;
      *v37 = v39;
      if ( !v40 )
      {
        if ( !((int (__stdcall *)(int *))v54[3])(a3) )
          return 0;
        v41 = *v54;
        v40 = v54[1];
        v37 = v53;
      }
      v42 = v40 - 1;
      v43 = ((int)*v41 >> 4) & 0xF;
      v44 = *v41 & 0xF;
      v45 = v41 + 1;
      v37[2] = v43;
      v37[3] = v44;
      if ( !v42 )
      {
        if ( !((int (__stdcall *)(int *))v54[3])(a3) )
          return 0;
        v45 = *v54;
        v42 = v54[1];
        v37 = v53;
      }
      v46 = *v37;
      v37[4] = *v45;
      v47 = *a3;
      *(_DWORD *)(v47 + 24) = v46;
      *(_DWORD *)(v47 + 28) = v37[2];
      *(_DWORD *)(v47 + 32) = v37[3];
      *(_DWORD *)(v47 + 36) = v37[4];
      v32 = v42 - 1;
      v33 = v45 + 1;
      *(_DWORD *)(v47 + 20) = 101;
      (*(void (__stdcall **)(int *, int))(v47 + 4))(a3, 1);
      v48 = ++v49 < a3[9];
      v53 += 21;
      if ( !v48 )
        break;
      v37 = v53;
    }
  }
  *(_DWORD *)(a3[111] + 16) = 1;
  *v54 = v33;
  v54[1] = v32;
  return 1;
}
