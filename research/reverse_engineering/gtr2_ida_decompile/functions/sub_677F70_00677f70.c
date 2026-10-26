int __stdcall sub_677F70(int *a1)
{
  int *v1; // esi
  unsigned __int8 **v2; // eax
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v5; // ecx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // edi
  int v9; // ecx
  unsigned __int8 *v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned __int8 **v15; // edi
  unsigned __int8 v16; // dl
  int v17; // ecx
  int v18; // eax
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  unsigned __int8 **v36; // edi
  unsigned __int8 v37; // dl
  unsigned int v38; // eax
  int *v39; // edi
  int v40; // ecx
  int v41; // ecx
  int v42; // eax
  bool v43; // cc
  int v44; // eax
  _BYTE v46[256]; // [esp+Ch] [ebp-12Ch] BYREF
  unsigned int v47; // [esp+10Ch] [ebp-2Ch]
  int v48; // [esp+110h] [ebp-28h]
  int v49; // [esp+114h] [ebp-24h]
  int v50; // [esp+118h] [ebp-20h]
  int v51; // [esp+11Ch] [ebp-1Ch]
  unsigned __int8 v52; // [esp+120h] [ebp-18h]
  int i; // [esp+124h] [ebp-14h]
  int v54; // [esp+128h] [ebp-10h]
  int v55; // [esp+12Ch] [ebp-Ch]
  unsigned __int8 **v56; // [esp+130h] [ebp-8h]
  unsigned __int8 *v57; // [esp+134h] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = *v2;
  v4 = v2[1];
  v56 = v2;
  if ( !v4 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(a1) )
      return 0;
    v3 = *v56;
    v57 = v56[1];
    v4 = v57;
    v2 = v56;
  }
  v5 = 0;
  BYTE1(v5) = *v3;
  v6 = v4 - 1;
  v7 = v3 + 1;
  v55 = (unsigned __int16)v5;
  if ( !v6 )
  {
    if ( ((int (__stdcall *)(int *))v2[3])(a1) )
    {
      v2 = v56;
      v7 = *v56;
      v57 = v56[1];
      v6 = v57;
      v5 = v55;
      goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  v8 = v6 - 1;
  v9 = *v7 + v5 - 2;
  v10 = v7 + 1;
  v55 = v9;
  if ( v9 > 16 )
  {
    do
    {
      if ( !v8 )
      {
        if ( !((int (__stdcall *)(int *))v2[3])(v1) )
          return 0;
        v10 = *v56;
        v57 = v56[1];
        v8 = v57;
      }
      v11 = *v10;
      v12 = *v1;
      v13 = v8 - 1;
      *(_DWORD *)(v12 + 20) = 80;
      v47 = v11;
      ++v10;
      *(_DWORD *)(v12 + 24) = v11;
      (*(void (__stdcall **)(int *, int))(v12 + 4))(v1, 1);
      v14 = 1;
      LOBYTE(v48) = 0;
      v54 = 0;
      i = 1;
      do
      {
        if ( !v13 )
        {
          v15 = v56;
          if ( !((int (__stdcall *)(int *))v56[3])(v1) )
            return 0;
          v10 = *v15;
          v14 = i;
          v57 = v15[1];
          v13 = v57;
        }
        v16 = *v10;
        *((_BYTE *)&v48 + v14) = *v10;
        --v13;
        ++v10;
        ++v14;
        v57 = v13;
        v54 += v16;
        i = v14;
      }
      while ( v14 <= 16 );
      v17 = BYTE2(v48);
      v55 -= 17;
      v18 = *v1;
      *(_DWORD *)(v18 + 24) = BYTE1(v48);
      v19 = HIBYTE(v48);
      *(_DWORD *)(v18 + 28) = v17;
      v20 = (unsigned __int8)v49;
      *(_DWORD *)(v18 + 32) = v19;
      v21 = BYTE1(v49);
      *(_DWORD *)(v18 + 36) = v20;
      v22 = BYTE2(v49);
      *(_DWORD *)(v18 + 40) = v21;
      v23 = HIBYTE(v49);
      *(_DWORD *)(v18 + 44) = v22;
      v24 = (unsigned __int8)v50;
      *(_DWORD *)(v18 + 48) = v23;
      *(_DWORD *)(v18 + 52) = v24;
      *(_DWORD *)(v18 + 20) = 86;
      (*(void (__stdcall **)(int *, int))(v18 + 4))(v1, 2);
      v25 = *v1;
      v26 = BYTE2(v50);
      *(_DWORD *)(v25 + 24) = BYTE1(v50);
      v27 = HIBYTE(v50);
      *(_DWORD *)(v25 + 28) = v26;
      v28 = (unsigned __int8)v51;
      *(_DWORD *)(v25 + 32) = v27;
      v29 = BYTE1(v51);
      *(_DWORD *)(v25 + 36) = v28;
      v30 = BYTE2(v51);
      *(_DWORD *)(v25 + 40) = v29;
      v31 = HIBYTE(v51);
      *(_DWORD *)(v25 + 44) = v30;
      v32 = v52;
      *(_DWORD *)(v25 + 48) = v31;
      *(_DWORD *)(v25 + 52) = v32;
      *(_DWORD *)(v25 + 20) = 86;
      (*(void (__stdcall **)(int *, int))(v25 + 4))(v1, 2);
      v33 = v54;
      if ( v54 > 256 || v54 > v55 )
      {
        v34 = *v1;
        *(_DWORD *)(v34 + 20) = 8;
        (*(void (__stdcall **)(int *))v34)(v1);
        v33 = v54;
      }
      v35 = 0;
      for ( i = 0; v35 < v33; i = v35 )
      {
        if ( !v13 )
        {
          v36 = v56;
          if ( !((int (__stdcall *)(int *))v56[3])(v1) )
            return 0;
          v10 = *v36;
          v35 = i;
          v33 = v54;
          v57 = v36[1];
          v13 = v57;
        }
        v37 = *v10;
        --v13;
        ++v10;
        v46[v35++] = v37;
        v57 = v13;
      }
      v38 = v47;
      v55 -= v33;
      if ( (v47 & 0x10) != 0 )
      {
        v38 = v47 - 16;
        v39 = &v1[v47 + 34];
      }
      else
      {
        v39 = &v1[v47 + 46];
      }
      if ( v38 >= 4 )
      {
        v40 = *v1;
        *(_DWORD *)(v40 + 20) = 30;
        *(_DWORD *)(v40 + 24) = v38;
        (*(void (__stdcall **)(int *))v40)(v1);
      }
      if ( !*v39 )
        *v39 = sub_6B5F80(v1);
      v41 = *v39;
      *(_DWORD *)v41 = v48;
      *(_DWORD *)(v41 + 4) = v49;
      *(_DWORD *)(v41 + 8) = v50;
      *(_DWORD *)(v41 + 12) = v51;
      v42 = v55;
      *(_BYTE *)(v41 + 16) = v52;
      qmemcpy((void *)(v41 + 17), v46, 0x100u);
      v8 = v57;
      v1 = a1;
      v43 = v42 <= 16;
      v2 = v56;
    }
    while ( !v43 );
    v9 = v55;
  }
  if ( v9 )
  {
    v44 = *v1;
    *(_DWORD *)(v44 + 20) = 11;
    (*(void (__stdcall **)(int *))v44)(v1);
    v2 = v56;
  }
  v2[1] = v8;
  *v2 = v10;
  return 1;
}
