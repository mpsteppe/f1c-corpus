int __usercall sub_6B6510@<eax>(char a1@<al>, int a2@<ecx>)
{
  int v3; // ebx
  int v4; // eax
  _BYTE *v5; // ecx
  bool v6; // zf
  int v7; // eax
  int v8; // eax
  _BYTE *v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  _BYTE *v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  _BYTE *v17; // ecx
  int v18; // eax
  int v19; // eax
  _BYTE *v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  _BYTE *v24; // ecx
  int v25; // eax
  int v26; // eax
  _BYTE *v27; // ecx
  int v28; // eax
  int v29; // eax
  _BYTE *v30; // ecx
  int v31; // eax
  int result; // eax
  _BYTE *v33; // edi
  int v34; // eax
  _BYTE *v35; // ecx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  _BYTE *v41; // ecx
  int v42; // eax
  int v43; // [esp+Ch] [ebp-4h]

  sub_6B60A0((int *)a2, a1);
  v3 = 3 * *(_DWORD *)(a2 + 60) + 8;
  v4 = *(_DWORD *)(a2 + 24);
  v5 = *(_BYTE **)v4;
  *v5 = (unsigned __int16)(3 * *(_WORD *)(a2 + 60) + 8) >> 8;
  *(_DWORD *)v4 = v5 + 1;
  v6 = (*(_DWORD *)(v4 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v4 + 12))(a2) )
  {
    v7 = *(_DWORD *)a2;
    *(_DWORD *)(v7 + 20) = 24;
    (*(void (__stdcall **)(int))v7)(a2);
  }
  v8 = *(_DWORD *)(a2 + 24);
  v9 = *(_BYTE **)v8;
  *v9 = v3;
  *(_DWORD *)v8 = v9 + 1;
  v6 = (*(_DWORD *)(v8 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v8 + 12))(a2) )
  {
    v10 = *(_DWORD *)a2;
    *(_DWORD *)(v10 + 20) = 24;
    (*(void (__stdcall **)(int))v10)(a2);
  }
  if ( *(int *)(a2 + 32) > 0xFFFF || *(int *)(a2 + 28) > 0xFFFF )
  {
    v11 = *(_DWORD *)a2;
    *(_DWORD *)(v11 + 20) = 41;
    *(_DWORD *)(v11 + 24) = 0xFFFF;
    (*(void (__stdcall **)(int))v11)(a2);
  }
  v12 = *(_DWORD *)(a2 + 24);
  v13 = *(_BYTE **)v12;
  *v13 = *(_BYTE *)(a2 + 56);
  *(_DWORD *)v12 = v13 + 1;
  v6 = (*(_DWORD *)(v12 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v12 + 12))(a2) )
  {
    v14 = *(_DWORD *)a2;
    *(_DWORD *)(v14 + 20) = 24;
    (*(void (__stdcall **)(int))v14)(a2);
  }
  v15 = *(_DWORD *)(a2 + 24);
  v16 = *(_DWORD *)(a2 + 32);
  v17 = *(_BYTE **)v15;
  *v17 = BYTE1(v16);
  *(_DWORD *)v15 = v17 + 1;
  v6 = (*(_DWORD *)(v15 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v15 + 12))(a2) )
  {
    v18 = *(_DWORD *)a2;
    *(_DWORD *)(v18 + 20) = 24;
    (*(void (__stdcall **)(int))v18)(a2);
  }
  v19 = *(_DWORD *)(a2 + 24);
  v20 = *(_BYTE **)v19;
  *v20 = v16;
  *(_DWORD *)v19 = v20 + 1;
  v6 = (*(_DWORD *)(v19 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v19 + 12))(a2) )
  {
    v21 = *(_DWORD *)a2;
    *(_DWORD *)(v21 + 20) = 24;
    (*(void (__stdcall **)(int))v21)(a2);
  }
  v22 = *(_DWORD *)(a2 + 24);
  v23 = *(_DWORD *)(a2 + 28);
  v24 = *(_BYTE **)v22;
  *v24 = BYTE1(v23);
  *(_DWORD *)v22 = v24 + 1;
  v6 = (*(_DWORD *)(v22 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v22 + 12))(a2) )
  {
    v25 = *(_DWORD *)a2;
    *(_DWORD *)(v25 + 20) = 24;
    (*(void (__stdcall **)(int))v25)(a2);
  }
  v26 = *(_DWORD *)(a2 + 24);
  v27 = *(_BYTE **)v26;
  *v27 = v23;
  *(_DWORD *)v26 = v27 + 1;
  v6 = (*(_DWORD *)(v26 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v26 + 12))(a2) )
  {
    v28 = *(_DWORD *)a2;
    *(_DWORD *)(v28 + 20) = 24;
    (*(void (__stdcall **)(int))v28)(a2);
  }
  v29 = *(_DWORD *)(a2 + 24);
  v30 = *(_BYTE **)v29;
  *v30 = *(_BYTE *)(a2 + 60);
  *(_DWORD *)v29 = v30 + 1;
  v6 = (*(_DWORD *)(v29 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int))(v29 + 12))(a2) )
  {
    v31 = *(_DWORD *)a2;
    *(_DWORD *)(v31 + 20) = 24;
    (*(void (__stdcall **)(int))v31)(a2);
  }
  result = *(_DWORD *)(a2 + 60);
  v33 = *(_BYTE **)(a2 + 68);
  v43 = 0;
  if ( result > 0 )
  {
    do
    {
      v34 = *(_DWORD *)(a2 + 24);
      v35 = *(_BYTE **)v34;
      *v35 = *v33;
      *(_DWORD *)v34 = v35 + 1;
      v6 = (*(_DWORD *)(v34 + 4))-- == 1;
      if ( v6 && !(*(int (__stdcall **)(int))(v34 + 12))(a2) )
      {
        v36 = *(_DWORD *)a2;
        *(_DWORD *)(v36 + 20) = 24;
        (*(void (__stdcall **)(int))v36)(a2);
      }
      v37 = *(_DWORD *)(a2 + 24);
      v38 = *(_DWORD *)v37 + 1;
      *(_BYTE *)(v38 - 1) = v33[12] + 16 * v33[8];
      *(_DWORD *)v37 = v38;
      v6 = (*(_DWORD *)(v37 + 4))-- == 1;
      if ( v6 && !(*(int (__stdcall **)(int))(v37 + 12))(a2) )
      {
        v39 = *(_DWORD *)a2;
        *(_DWORD *)(v39 + 20) = 24;
        (*(void (__stdcall **)(int))v39)(a2);
      }
      v40 = *(_DWORD *)(a2 + 24);
      v41 = *(_BYTE **)v40;
      *v41 = v33[16];
      *(_DWORD *)v40 = v41 + 1;
      v6 = (*(_DWORD *)(v40 + 4))-- == 1;
      if ( v6 && !(*(int (__stdcall **)(int))(v40 + 12))(a2) )
      {
        v42 = *(_DWORD *)a2;
        *(_DWORD *)(v42 + 20) = 24;
        (*(void (__stdcall **)(int))v42)(a2);
      }
      result = v43 + 1;
      v33 += 84;
      ++v43;
    }
    while ( v43 < *(_DWORD *)(a2 + 60) );
  }
  return result;
}
