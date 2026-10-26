char __usercall sub_510ACC@<al>(_DWORD *a1@<ebx>)
{
  int v1; // esi
  int v2; // eax
  char *v3; // edi
  unsigned __int16 v4; // ax
  char *v5; // edi
  int v6; // eax
  char *v7; // edi
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  unsigned __int8 v12; // cl
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int i; // edi
  char v16; // al
  unsigned int v17; // eax
  int *v18; // edi
  int v19; // edi
  int v20; // eax
  _BYTE v22[256]; // [esp+8h] [ebp-130h] BYREF
  unsigned int v23; // [esp+108h] [ebp-30h]
  int v24; // [esp+10Ch] [ebp-2Ch]
  int v25; // [esp+110h] [ebp-28h]
  int v26; // [esp+114h] [ebp-24h]
  int v27; // [esp+118h] [ebp-20h]
  int v28; // [esp+11Ch] [ebp-1Ch]
  unsigned __int8 v29; // [esp+120h] [ebp-18h]
  int v30; // [esp+124h] [ebp-14h]
  int v31; // [esp+128h] [ebp-10h]
  int v32; // [esp+12Ch] [ebp-Ch]
  char *v33; // [esp+130h] [ebp-8h]
  int v34; // [esp+134h] [ebp-4h]

  v1 = a1[5];
  v2 = *(_DWORD *)(v1 + 4);
  v3 = *(char **)v1;
  v24 = v1;
  v34 = v2;
  if ( !v2 )
  {
    if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *))(v1 + 12))(a1) )
      return 0;
    v33 = *(char **)v1;
    v3 = v33;
    v34 = *(_DWORD *)(v1 + 4);
  }
  --v34;
  LOBYTE(v4) = 0;
  HIBYTE(v4) = *v3;
  v5 = v3 + 1;
  v32 = v4;
  if ( v34 )
    goto LABEL_7;
  if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *))(v1 + 12))(a1) )
    return 0;
  v33 = *(char **)v1;
  v5 = v33;
  v34 = *(_DWORD *)(v1 + 4);
LABEL_7:
  v6 = (unsigned __int8)*v5;
  --v34;
  v7 = v5 + 1;
  v32 = v6 + v32 - 2;
  while ( v32 > 0 )
  {
    if ( !v34 )
    {
      if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *))(v1 + 12))(a1) )
        return 0;
      v33 = *(char **)v1;
      v7 = v33;
      v34 = *(_DWORD *)(v1 + 4);
    }
    v8 = (unsigned __int8)*v7;
    v9 = *a1;
    --v34;
    *(_DWORD *)(v9 + 20) = 79;
    v10 = *a1;
    v23 = v8;
    *(_DWORD *)(v10 + 24) = v8;
    v11 = (unsigned __int8 *)(v7 + 1);
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
    LOBYTE(v25) = 0;
    v30 = 0;
    v31 = 1;
    do
    {
      if ( !v34 )
      {
        if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *))(v1 + 12))(a1) )
          return 0;
        v33 = *(char **)v1;
        v11 = (unsigned __int8 *)v33;
        v34 = *(_DWORD *)(v1 + 4);
      }
      v12 = *v11;
      --v34;
      *((_BYTE *)&v25 + v31) = v12;
      v30 += v12;
      ++v11;
      ++v31;
      v33 = (char *)v11;
    }
    while ( v31 <= 16 );
    v13 = (_DWORD *)(*a1 + 24);
    *v13 = BYTE1(v25);
    v13[1] = BYTE2(v25);
    v13[2] = HIBYTE(v25);
    v32 -= 17;
    v13[3] = (unsigned __int8)v26;
    v13[4] = BYTE1(v26);
    v13[5] = BYTE2(v26);
    v13[6] = HIBYTE(v26);
    v13[7] = (unsigned __int8)v27;
    *(_DWORD *)(*a1 + 20) = 85;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 2);
    v14 = (_DWORD *)(*a1 + 24);
    *v14 = BYTE1(v27);
    v14[1] = BYTE2(v27);
    v14[2] = HIBYTE(v27);
    v14[3] = (unsigned __int8)v28;
    v14[4] = BYTE1(v28);
    v14[5] = BYTE2(v28);
    v14[6] = HIBYTE(v28);
    v14[7] = v29;
    *(_DWORD *)(*a1 + 20) = 85;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 2);
    if ( v30 > 256 || v30 > v32 )
    {
      *(_DWORD *)(*a1 + 20) = 28;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    for ( i = 0; i < v30; ++i )
    {
      if ( !v34 )
      {
        if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *))(v1 + 12))(a1) )
          return 0;
        v33 = *(char **)v1;
        v34 = *(_DWORD *)(v1 + 4);
      }
      --v34;
      v16 = *v33++;
      v22[i] = v16;
    }
    v32 -= v30;
    v17 = v23;
    if ( (v23 & 0x10) != 0 )
    {
      v17 = v23 - 16;
      v18 = &a1[v23 + 28];
      v31 = (int)v18;
    }
    else
    {
      v31 = (int)&a1[v23 + 40];
      v18 = (int *)v31;
    }
    if ( v17 >= 4 )
    {
      *(_DWORD *)(*a1 + 20) = 29;
      *(_DWORD *)(*a1 + 24) = v17;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    if ( !*v18 )
      *v18 = sub_516990(a1);
    v19 = *v18;
    v20 = v31;
    *(_DWORD *)v19 = v25;
    v19 += 4;
    *(_DWORD *)v19 = v26;
    v19 += 4;
    *(_DWORD *)v19 = v27;
    v19 += 4;
    *(_DWORD *)v19 = v28;
    *(_BYTE *)(v19 + 4) = v29;
    qmemcpy((void *)(*(_DWORD *)v20 + 17), v22, 0x100u);
    v7 = v33;
    v1 = v24;
  }
  *(_DWORD *)(v1 + 4) = v34;
  *(_DWORD *)v1 = v7;
  return 1;
}
