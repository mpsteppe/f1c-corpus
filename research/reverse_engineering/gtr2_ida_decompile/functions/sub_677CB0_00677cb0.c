int __usercall sub_677CB0@<eax>(int *a1@<esi>)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // ebx
  int v4; // eax
  unsigned __int16 v5; // cx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebx
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ebx
  int v11; // ecx
  int v12; // eax
  unsigned __int8 *v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  unsigned __int8 *v17; // ebx
  bool v18; // zf
  _DWORD *v19; // edi
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  bool v25; // cc
  unsigned __int8 *v26; // eax
  int v27; // ecx
  unsigned __int8 *v28; // eax
  unsigned __int8 *v29; // ebx
  int v30; // ecx
  unsigned __int8 *v31; // ebx
  int v33; // edx
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // eax
  int v38; // edx
  int v39; // edx
  int v40; // [esp+8h] [ebp-1Ch]
  int v41; // [esp+8h] [ebp-1Ch]
  unsigned __int8 **v42; // [esp+Ch] [ebp-18h]
  int v43; // [esp+10h] [ebp-14h]
  int v44; // [esp+14h] [ebp-10h]
  _DWORD *v45; // [esp+18h] [ebp-Ch]
  int v46; // [esp+1Ch] [ebp-8h]
  int v47; // [esp+1Ch] [ebp-8h]
  int v48; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v49; // [esp+20h] [ebp-4h]
  unsigned __int8 *v50; // [esp+20h] [ebp-4h]
  unsigned __int8 *v51; // [esp+20h] [ebp-4h]
  unsigned __int8 *v52; // [esp+20h] [ebp-4h]

  v1 = (unsigned __int8 **)a1[6];
  v2 = v1[1];
  v3 = *v1;
  v42 = v1;
  v49 = v2;
  if ( !*(_DWORD *)(a1[111] + 16) )
  {
    v4 = *a1;
    *(_DWORD *)(v4 + 20) = 62;
    (*(void (__stdcall **)(int *))v4)(a1);
    v2 = v49;
  }
  if ( !v2 )
  {
    if ( !((int (__stdcall *)(int *))v1[3])(a1) )
      return 0;
    v3 = *v1;
    v2 = v1[1];
  }
  LOBYTE(v5) = 0;
  HIBYTE(v5) = *v3;
  v6 = v2 - 1;
  v7 = v3 + 1;
  v46 = v5;
  if ( !v6 )
  {
    if ( !((int (__stdcall *)(int *))v1[3])(a1) )
      return 0;
    v7 = *v1;
    v6 = v1[1];
  }
  v8 = *v7 + v46;
  v9 = v6 - 1;
  v10 = v7 + 1;
  v47 = v8;
  if ( !v9 )
  {
    if ( !((int (__stdcall *)(int *))v1[3])(a1) )
      return 0;
    v10 = *v1;
    v9 = v1[1];
  }
  v11 = *v10;
  v50 = v9 - 1;
  v12 = *a1;
  *(_DWORD *)(v12 + 20) = 103;
  v44 = v11;
  v13 = v10 + 1;
  *(_DWORD *)(v12 + 24) = v11;
  (*(void (__stdcall **)(int *, int))(v12 + 4))(a1, 1);
  v14 = v44;
  if ( v47 != 2 * v44 + 6 || v44 < 1 || v44 > 4 )
  {
    v15 = *a1;
    *(_DWORD *)(v15 + 20) = 11;
    (*(void (__stdcall **)(int *))v15)(a1);
    v14 = v44;
  }
  a1[83] = v14;
  v43 = 0;
  if ( v14 > 0 )
  {
    v45 = a1 + 84;
    do
    {
      if ( !v50 )
      {
        if ( !((int (__stdcall *)(int *))v1[3])(a1) )
          return 0;
        v13 = *v1;
        v50 = v1[1];
      }
      v16 = *v13;
      v17 = v13 + 1;
      v18 = v50 == (unsigned __int8 *)1;
      v51 = v50 - 1;
      v48 = v16;
      if ( v18 )
      {
        if ( !((int (__stdcall *)(int *))v1[3])(a1) )
          return 0;
        v17 = *v1;
        v51 = v1[1];
      }
      v19 = (_DWORD *)a1[55];
      v50 = v51 - 1;
      v20 = *v17;
      v13 = v17 + 1;
      v21 = 0;
      v40 = v20;
      if ( a1[9] <= 0 )
      {
LABEL_27:
        v22 = *a1;
        *(_DWORD *)(v22 + 20) = 5;
        *(_DWORD *)(v22 + 24) = v48;
        (*(void (__stdcall **)(int *))v22)(a1);
        v20 = v40;
      }
      else
      {
        while ( v48 != *v19 )
        {
          ++v21;
          v19 += 21;
          if ( v21 >= a1[9] )
            goto LABEL_27;
        }
      }
      v23 = v20 >> 4;
      v19[6] = v20 & 0xF;
      *v45 = v19;
      v24 = *a1;
      v19[5] = v23 & 0xF;
      *(_DWORD *)(v24 + 24) = v48;
      *(_DWORD *)(v24 + 28) = v19[5];
      *(_DWORD *)(v24 + 32) = v19[6];
      *(_DWORD *)(v24 + 20) = 104;
      (*(void (__stdcall **)(int *, int))(v24 + 4))(a1, 1);
      v1 = v42;
      v25 = ++v43 < v44;
      ++v45;
    }
    while ( v25 );
  }
  v26 = v50;
  if ( !v50 )
  {
    if ( !((int (__stdcall *)(int *))v1[3])(a1) )
      return 0;
    v26 = v1[1];
    v13 = *v1;
  }
  v27 = *v13;
  v28 = v26 - 1;
  v29 = v13 + 1;
  a1[101] = v27;
  if ( v28 )
    goto LABEL_35;
  if ( !((int (__stdcall *)(int *))v1[3])(a1) )
    return 0;
  v29 = *v1;
  v28 = v1[1];
LABEL_35:
  v30 = *v29;
  v31 = v29 + 1;
  v52 = v28 - 1;
  a1[102] = v30;
  if ( v28 == (unsigned __int8 *)1 )
  {
    if ( !((int (__stdcall *)(int *))v1[3])(a1) )
      return 0;
    v31 = *v1;
    v52 = v1[1];
  }
  v33 = a1[101];
  v34 = *v31;
  v35 = v34 & 0xF;
  v36 = (v34 >> 4) & 0xF;
  v41 = v35;
  a1[104] = v35;
  v37 = *a1;
  *(_DWORD *)(v37 + 24) = v33;
  v38 = a1[102];
  *(_DWORD *)(v37 + 32) = v36;
  a1[103] = v36;
  *(_DWORD *)(v37 + 28) = v38;
  *(_DWORD *)(v37 + 36) = v41;
  *(_DWORD *)(v37 + 20) = 105;
  (*(void (__stdcall **)(int *, int))(v37 + 4))(a1, 1);
  v39 = a1[111];
  ++a1[37];
  *(_DWORD *)(v39 + 20) = 0;
  *v1 = v31 + 1;
  v1[1] = v52 - 1;
  return 1;
}
