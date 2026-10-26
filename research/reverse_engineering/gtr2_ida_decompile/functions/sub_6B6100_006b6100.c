int __userpurge sub_6B6100@<eax>(int *a1@<esi>, int a2)
{
  int v2; // edi
  int v3; // eax
  _WORD *v4; // eax
  int v5; // ebx
  int v6; // eax
  _BYTE *v7; // ecx
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  _BYTE *v11; // ecx
  int v12; // eax
  int v13; // eax
  _BYTE *v14; // edi
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  _BYTE *v18; // ecx
  int v19; // eax
  int v20; // eax
  _BYTE *v21; // ecx
  int v22; // eax
  int *v23; // edi
  __int16 v24; // bx
  int v25; // eax
  _BYTE *v26; // ecx
  int v27; // eax
  int v28; // eax
  _BYTE *v29; // ecx
  int v30; // eax
  int v32; // [esp+8h] [ebp-8h]
  int v33; // [esp+Ch] [ebp-4h]

  v2 = a1[a2 + 18];
  v32 = v2;
  if ( !v2 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 52;
    *(_DWORD *)(v3 + 24) = a2;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  v33 = 0;
  v4 = (_WORD *)(v2 + 4);
  v5 = 16;
  do
  {
    if ( *(v4 - 2) > 0xFFu )
      v33 = 1;
    if ( *(v4 - 1) > 0xFFu )
      v33 = 1;
    if ( *v4 > 0xFFu )
      v33 = 1;
    if ( v4[1] > 0xFFu )
      v33 = 1;
    v4 += 4;
    --v5;
  }
  while ( v5 );
  if ( !*(_DWORD *)(v2 + 128) )
  {
    v6 = a1[6];
    v7 = *(_BYTE **)v6;
    *v7 = -1;
    *(_DWORD *)v6 = v7 + 1;
    v8 = (*(_DWORD *)(v6 + 4))-- == 1;
    if ( v8 && !(*(int (__stdcall **)(int *))(v6 + 12))(a1) )
    {
      v9 = *a1;
      *(_DWORD *)(v9 + 20) = 24;
      (*(void (__stdcall **)(int *))v9)(a1);
    }
    v10 = a1[6];
    v11 = *(_BYTE **)v10;
    *v11 = -37;
    *(_DWORD *)v10 = v11 + 1;
    v8 = (*(_DWORD *)(v10 + 4))-- == 1;
    if ( v8 && !(*(int (__stdcall **)(int *))(v10 + 12))(a1) )
    {
      v12 = *a1;
      *(_DWORD *)(v12 + 20) = 24;
      (*(void (__stdcall **)(int *))v12)(a1);
    }
    v13 = a1[6];
    v14 = *(_BYTE **)v13;
    *v14 = (unsigned __int16)(v33 != 0 ? 131 : 67) >> 8;
    v15 = *(_DWORD *)(v13 + 4) - 1;
    *(_DWORD *)v13 = v14 + 1;
    *(_DWORD *)(v13 + 4) = v15;
    if ( !v15 && !(*(int (__stdcall **)(int *))(v13 + 12))(a1) )
    {
      v16 = *a1;
      *(_DWORD *)(v16 + 20) = 24;
      (*(void (__stdcall **)(int *))v16)(a1);
    }
    v17 = a1[6];
    v18 = *(_BYTE **)v17;
    *v18 = v33 != 0 ? -125 : 67;
    *(_DWORD *)v17 = v18 + 1;
    v8 = (*(_DWORD *)(v17 + 4))-- == 1;
    if ( v8 && !(*(int (__stdcall **)(int *))(v17 + 12))(a1) )
    {
      v19 = *a1;
      *(_DWORD *)(v19 + 20) = 24;
      (*(void (__stdcall **)(int *))v19)(a1);
    }
    v20 = a1[6];
    v21 = *(_BYTE **)v20;
    *v21 = a2 + 16 * v33;
    *(_DWORD *)v20 = v21 + 1;
    v8 = (*(_DWORD *)(v20 + 4))-- == 1;
    if ( v8 && !(*(int (__stdcall **)(int *))(v20 + 12))(a1) )
    {
      v22 = *a1;
      *(_DWORD *)(v22 + 20) = 24;
      (*(void (__stdcall **)(int *))v22)(a1);
    }
    v23 = &dword_744A70;
    do
    {
      v24 = *(_WORD *)(v32 + 2 * *v23);
      if ( v33 )
      {
        v25 = a1[6];
        v26 = *(_BYTE **)v25;
        *v26 = HIBYTE(v24);
        *(_DWORD *)v25 = v26 + 1;
        v8 = (*(_DWORD *)(v25 + 4))-- == 1;
        if ( v8 && !(*(int (__stdcall **)(int *))(v25 + 12))(a1) )
        {
          v27 = *a1;
          *(_DWORD *)(v27 + 20) = 24;
          (*(void (__stdcall **)(int *))v27)(a1);
        }
      }
      v28 = a1[6];
      v29 = *(_BYTE **)v28;
      *v29 = v24;
      *(_DWORD *)v28 = v29 + 1;
      v8 = (*(_DWORD *)(v28 + 4))-- == 1;
      if ( v8 && !(*(int (__stdcall **)(int *))(v28 + 12))(a1) )
      {
        v30 = *a1;
        *(_DWORD *)(v30 + 20) = 24;
        (*(void (__stdcall **)(int *))v30)(a1);
      }
      ++v23;
    }
    while ( (int)v23 < (int)dword_744B70 );
    *(_DWORD *)(v32 + 128) = 1;
  }
  return v33;
}
