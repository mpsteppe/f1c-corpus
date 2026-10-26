int __usercall sub_6B6710@<eax>(int a1@<eax>)
{
  int v2; // eax
  _BYTE *v3; // ecx
  int v4; // ebx
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  _BYTE *v8; // ecx
  int v9; // eax
  int v10; // eax
  _BYTE *v11; // ecx
  int v12; // eax
  _BYTE **v13; // ebx
  int v14; // eax
  _BYTE *v15; // edi
  _BYTE *v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // eax
  _BYTE *v21; // edi
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  _BYTE *v25; // ecx
  int v26; // eax
  int v27; // eax
  _BYTE *v28; // ecx
  int v29; // eax
  int result; // eax
  _BYTE *v31; // ecx
  int v32; // eax
  int v33; // [esp+Ch] [ebp-4h]

  sub_6B60A0((int *)a1, 218);
  v2 = *(_DWORD *)(a1 + 24);
  v3 = *(_BYTE **)v2;
  v4 = 2 * *(_DWORD *)(a1 + 252) + 6;
  *v3 = (unsigned __int16)(2 * *(_WORD *)(a1 + 252) + 6) >> 8;
  *(_DWORD *)v2 = v3 + 1;
  v5 = (*(_DWORD *)(v2 + 4))-- == 1;
  if ( v5 && !(*(int (__stdcall **)(int))(v2 + 12))(a1) )
  {
    v6 = *(_DWORD *)a1;
    *(_DWORD *)(v6 + 20) = 24;
    (*(void (__stdcall **)(int))v6)(a1);
  }
  v7 = *(_DWORD *)(a1 + 24);
  v8 = *(_BYTE **)v7;
  *v8 = v4;
  *(_DWORD *)v7 = v8 + 1;
  v5 = (*(_DWORD *)(v7 + 4))-- == 1;
  if ( v5 && !(*(int (__stdcall **)(int))(v7 + 12))(a1) )
  {
    v9 = *(_DWORD *)a1;
    *(_DWORD *)(v9 + 20) = 24;
    (*(void (__stdcall **)(int))v9)(a1);
  }
  v10 = *(_DWORD *)(a1 + 24);
  v11 = *(_BYTE **)v10;
  *v11 = *(_BYTE *)(a1 + 252);
  *(_DWORD *)v10 = v11 + 1;
  v5 = (*(_DWORD *)(v10 + 4))-- == 1;
  if ( v5 && !(*(int (__stdcall **)(int))(v10 + 12))(a1) )
  {
    v12 = *(_DWORD *)a1;
    *(_DWORD *)(v12 + 20) = 24;
    (*(void (__stdcall **)(int))v12)(a1);
  }
  v33 = 0;
  if ( *(int *)(a1 + 252) > 0 )
  {
    v13 = (_BYTE **)(a1 + 256);
    do
    {
      v14 = *(_DWORD *)(a1 + 24);
      v15 = *v13;
      v16 = *(_BYTE **)v14;
      *v16 = **v13;
      *(_DWORD *)v14 = v16 + 1;
      v5 = (*(_DWORD *)(v14 + 4))-- == 1;
      if ( v5 && !(*(int (__stdcall **)(int))(v14 + 12))(a1) )
      {
        v17 = *(_DWORD *)a1;
        *(_DWORD *)(v17 + 20) = 24;
        (*(void (__stdcall **)(int))v17)(a1);
      }
      v18 = *((_DWORD *)v15 + 5);
      v19 = *((_DWORD *)v15 + 6);
      if ( *(_DWORD *)(a1 + 236) )
      {
        if ( *(_DWORD *)(a1 + 324) || (LOBYTE(v19) = 0, *(_DWORD *)(a1 + 332)) && !*(_DWORD *)(a1 + 180) )
          LOBYTE(v18) = 0;
      }
      v20 = *(_DWORD *)(a1 + 24);
      v21 = *(_BYTE **)v20;
      *v21 = v19 + 16 * v18;
      v22 = *(_DWORD *)(v20 + 4) - 1;
      *(_DWORD *)v20 = v21 + 1;
      *(_DWORD *)(v20 + 4) = v22;
      if ( !v22 && !(*(int (__stdcall **)(int))(v20 + 12))(a1) )
      {
        v23 = *(_DWORD *)a1;
        *(_DWORD *)(v23 + 20) = 24;
        (*(void (__stdcall **)(int))v23)(a1);
      }
      ++v13;
      ++v33;
    }
    while ( v33 < *(_DWORD *)(a1 + 252) );
  }
  v24 = *(_DWORD *)(a1 + 24);
  v25 = *(_BYTE **)v24;
  *v25 = *(_BYTE *)(a1 + 324);
  *(_DWORD *)v24 = v25 + 1;
  v5 = (*(_DWORD *)(v24 + 4))-- == 1;
  if ( v5 && !(*(int (__stdcall **)(int))(v24 + 12))(a1) )
  {
    v26 = *(_DWORD *)a1;
    *(_DWORD *)(v26 + 20) = 24;
    (*(void (__stdcall **)(int))v26)(a1);
  }
  v27 = *(_DWORD *)(a1 + 24);
  v28 = *(_BYTE **)v27;
  *v28 = *(_BYTE *)(a1 + 328);
  *(_DWORD *)v27 = v28 + 1;
  v5 = (*(_DWORD *)(v27 + 4))-- == 1;
  if ( v5 && !(*(int (__stdcall **)(int))(v27 + 12))(a1) )
  {
    v29 = *(_DWORD *)a1;
    *(_DWORD *)(v29 + 20) = 24;
    (*(void (__stdcall **)(int))v29)(a1);
  }
  result = *(_DWORD *)(a1 + 24);
  v31 = *(_BYTE **)result;
  *v31 = *(_BYTE *)(a1 + 336) + 16 * *(_BYTE *)(a1 + 332);
  *(_DWORD *)result = v31 + 1;
  v5 = (*(_DWORD *)(result + 4))-- == 1;
  if ( v5 )
  {
    result = (*(int (__stdcall **)(int))(result + 12))(a1);
    if ( !result )
    {
      v32 = *(_DWORD *)a1;
      *(_DWORD *)(v32 + 20) = 24;
      return (*(int (__stdcall **)(int))v32)(a1);
    }
  }
  return result;
}
