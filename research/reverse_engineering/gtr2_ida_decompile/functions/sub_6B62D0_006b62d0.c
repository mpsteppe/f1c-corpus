int __userpurge sub_6B62D0@<eax>(int a1@<eax>, int *a2@<ecx>, int a3)
{
  int v4; // edi
  int v5; // eax
  int result; // eax
  unsigned __int8 *v7; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  _BYTE *v11; // ecx
  bool v12; // zf
  int v13; // eax
  int v14; // eax
  _BYTE *v15; // ecx
  int v16; // eax
  int v17; // eax
  _BYTE *v18; // ecx
  int v19; // eax
  int i; // edi
  int v21; // eax
  _BYTE *v22; // ecx
  int v23; // eax
  int j; // edi
  int v25; // eax
  _BYTE *v26; // ecx
  int v27; // eax
  int v28; // [esp+8h] [ebp-8h]
  int v29; // [esp+Ch] [ebp-4h]

  if ( a1 )
  {
    v4 = a2[a3 + 26];
    v28 = v4;
    a3 += 16;
  }
  else
  {
    v28 = a2[a3 + 22];
    v4 = v28;
  }
  if ( !v4 )
  {
    v5 = *a2;
    *(_DWORD *)(v5 + 20) = 50;
    *(_DWORD *)(v5 + 24) = a3;
    (*(void (__stdcall **)(int *))v5)(a2);
  }
  result = *(_DWORD *)(v4 + 276);
  if ( !result )
  {
    sub_6B60A0(a2, 196);
    v29 = 0;
    v7 = (unsigned __int8 *)(v4 + 3);
    v8 = 4;
    do
    {
      v9 = v7[1] + *(v7 - 1) + *(v7 - 2) + v29 + *v7;
      v7 += 4;
      --v8;
      v29 = v9;
    }
    while ( v8 );
    v10 = a2[6];
    v11 = *(_BYTE **)v10;
    *v11 = (unsigned __int16)(v9 + 19) >> 8;
    *(_DWORD *)v10 = v11 + 1;
    v12 = (*(_DWORD *)(v10 + 4))-- == 1;
    if ( v12 && !(*(int (__stdcall **)(int *))(v10 + 12))(a2) )
    {
      v13 = *a2;
      *(_DWORD *)(v13 + 20) = 24;
      (*(void (__stdcall **)(int *))v13)(a2);
    }
    v14 = a2[6];
    v15 = *(_BYTE **)v14;
    *v15 = v9 + 19;
    *(_DWORD *)v14 = v15 + 1;
    v12 = (*(_DWORD *)(v14 + 4))-- == 1;
    if ( v12 && !(*(int (__stdcall **)(int *))(v14 + 12))(a2) )
    {
      v16 = *a2;
      *(_DWORD *)(v16 + 20) = 24;
      (*(void (__stdcall **)(int *))v16)(a2);
    }
    v17 = a2[6];
    v18 = *(_BYTE **)v17;
    *v18 = a3;
    *(_DWORD *)v17 = v18 + 1;
    v12 = (*(_DWORD *)(v17 + 4))-- == 1;
    if ( v12 && !(*(int (__stdcall **)(int *))(v17 + 12))(a2) )
    {
      v19 = *a2;
      *(_DWORD *)(v19 + 20) = 24;
      (*(void (__stdcall **)(int *))v19)(a2);
    }
    for ( i = 1; i <= 16; ++i )
    {
      v21 = a2[6];
      v22 = *(_BYTE **)v21;
      *v22 = *(_BYTE *)(i + v28);
      *(_DWORD *)v21 = v22 + 1;
      v12 = (*(_DWORD *)(v21 + 4))-- == 1;
      if ( v12 && !(*(int (__stdcall **)(int *))(v21 + 12))(a2) )
      {
        v23 = *a2;
        *(_DWORD *)(v23 + 20) = 24;
        (*(void (__stdcall **)(int *))v23)(a2);
      }
    }
    result = v29;
    for ( j = 0; j < v29; ++j )
    {
      v25 = a2[6];
      v26 = *(_BYTE **)v25;
      *v26 = *(_BYTE *)(v28 + j + 17);
      *(_DWORD *)v25 = v26 + 1;
      v12 = (*(_DWORD *)(v25 + 4))-- == 1;
      if ( v12 && !(*(int (__stdcall **)(int *))(v25 + 12))(a2) )
      {
        v27 = *a2;
        *(_DWORD *)(v27 + 20) = 24;
        (*(void (__stdcall **)(int *))v27)(a2);
      }
      result = v29;
    }
    *(_DWORD *)(v28 + 276) = 1;
  }
  return result;
}
