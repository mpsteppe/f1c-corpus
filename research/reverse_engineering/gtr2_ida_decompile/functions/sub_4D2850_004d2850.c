int __userpurge sub_4D2850@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5,
        int a6,
        int a7,
        int a8)
{
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  _DWORD *v14; // ecx
  const char *v15; // eax
  const char *v16; // ebx
  int v17; // eax
  const CHAR *v18; // eax
  const CHAR *v19; // edi
  char *v20; // eax
  int v21; // eax
  const CHAR *v22; // eax
  char v23; // al
  int v24; // ebx
  int v25; // edi
  int v26; // ebx
  const char ***v27; // eax
  const char *v28; // ebp
  int v29; // eax
  const CHAR *v30; // eax
  const CHAR *v31; // edi
  char *v32; // eax
  int v33; // ecx
  int v34; // eax
  const CHAR *v35; // eax
  int v36; // eax
  const CHAR *v37; // eax
  int v38; // eax
  int v41; // [esp+8h] [ebp-44h]
  int v42; // [esp+Ch] [ebp-40h]
  int v43; // [esp+10h] [ebp-3Ch]
  int v44; // [esp+14h] [ebp-38h] BYREF
  int v45; // [esp+18h] [ebp-34h]
  int v46; // [esp+1Ch] [ebp-30h]
  int v47; // [esp+20h] [ebp-2Ch] BYREF
  int v48; // [esp+24h] [ebp-28h]
  char v49[4]; // [esp+2Ch] [ebp-20h] BYREF
  char v50[4]; // [esp+30h] [ebp-1Ch] BYREF
  int v51; // [esp+34h] [ebp-18h]
  char v52[16]; // [esp+38h] [ebp-14h] BYREF
  const char *v53; // [esp+48h] [ebp-4h]

  v9 = *(_DWORD **)(a1 + 280);
  *(_DWORD *)(a1 + 288) = v9;
  if ( !v9 || !*v9 )
    return 0;
  v10 = *(_DWORD *)(a1 + 300);
  v11 = *(_DWORD *)(a1 + 296) - 1;
  v51 = 0;
  if ( v10 > v11 )
    *(_DWORD *)(a1 + 300) = v11;
  v12 = *(_DWORD *)(a1 + 300);
  v13 = v12;
  v48 = a2;
  v47 = a4;
  if ( v12 < 0 || v12 >= *(_DWORD *)(a1 + 292) )
    goto LABEL_15;
  v14 = *(_DWORD **)(a1 + 280);
  if ( v12 > 0 )
  {
    while ( v14 )
    {
      v14 = (_DWORD *)v14[1];
      if ( --v13 <= 0 )
        goto LABEL_10;
    }
    goto LABEL_15;
  }
LABEL_10:
  if ( !v14 || !*v14 )
  {
LABEL_15:
    v16 = v53;
    goto LABEL_16;
  }
  v15 = *(const char **)sub_5F6B50(v12);
  if ( v15 )
    v16 = v15;
  else
    v16 = WindowName;
LABEL_16:
  v17 = *(_DWORD *)(a1 + 244);
  if ( v17 )
  {
    v18 = *(const CHAR **)(v17 + 64);
    if ( !v18 )
      v18 = WindowName;
    v19 = v18;
  }
  else
  {
    v19 = 0;
  }
  v46 = 1;
  v20 = sub_41D840(&byte_91CC38, v16);
  sub_4DF1D0(v19, v20, v52, v49);
  if ( v16 )
  {
    v21 = *(_DWORD *)(a1 + 244);
    if ( v21 )
    {
      v22 = *(const CHAR **)(v21 + 64);
      if ( !v22 )
        v22 = WindowName;
    }
    else
    {
      v22 = 0;
    }
    sub_4DF290(v22, v16, *(_DWORD *)(a1 + 312), *(_DWORD *)(a1 + 316), 0, 1);
  }
  sub_4DE540(v50, v49);
  v23 = *(_BYTE *)(a1 + 132);
  if ( v23 == 3 || v23 == 5 || v23 == 4 || v23 == 8 || v23 == 9 )
  {
    v24 = sub_4E3D00(*(_DWORD *)(a1 + 244) + 108);
    v41 = *(_DWORD *)(a1 + 304);
    v51 = v24;
    sub_47F6E0((void *)(a1 + 280), v41);
    v25 = 12;
    *(_DWORD *)(a1 + 308) = *(_DWORD *)(a1 + 300);
    v45 = 12;
    if ( v24 > 12 )
    {
      while ( 1 )
      {
        v48 = sub_4CFCC0((_DWORD *)a1, v25);
        v26 = sub_4CFD30((_DWORD *)a1, v25);
        if ( v26 > v46 )
          v46 = v26 + v44;
        v27 = *(const char ****)(a1 + 288);
        if ( !v27 || !*v27 )
          goto LABEL_61;
        v28 = **v27;
        if ( !v28 )
          v28 = WindowName;
        v29 = *(_DWORD *)(a1 + 244);
        if ( v29 )
        {
          v30 = *(const CHAR **)(v29 + 64);
          if ( !v30 )
            v30 = WindowName;
          v31 = v30;
        }
        else
        {
          v31 = 0;
        }
        v32 = sub_41D840(&byte_91CC38, v28);
        sub_4DF1D0(v31, v32, &v47, &v44);
        if ( v44 <= v26 || v44 >= v26 + 1 )
          break;
        v33 = v43;
        if ( v45 <= v43 || v45 >= v43 + v42 )
          goto LABEL_54;
        v34 = *(_DWORD *)(a1 + 244);
        if ( v34 )
        {
          v35 = *(const CHAR **)(v34 + 72);
          if ( !v35 )
            v35 = WindowName;
        }
        else
        {
          v35 = 0;
        }
        sub_4DF290(v35, v28, v43, v26, 0, 1);
        *(_DWORD *)(a1 + 308) = sub_4CF820((int *)(a1 + 280));
LABEL_59:
        v38 = *(_DWORD *)(a1 + 288);
        v25 = a3;
        if ( v38 )
          *(_DWORD *)(a1 + 288) = *(_DWORD *)(v38 + 4);
LABEL_61:
        a3 = ++v25;
        if ( v25 >= v46 )
          return 0;
      }
      v33 = v43;
LABEL_54:
      v36 = *(_DWORD *)(a1 + 244);
      if ( v36 )
      {
        v37 = *(const CHAR **)(v36 + 64);
        if ( !v37 )
          v37 = WindowName;
      }
      else
      {
        v37 = 0;
      }
      sub_4DF290(v37, v28, v33, v26, 0, 1);
      goto LABEL_59;
    }
  }
  return 0;
}
