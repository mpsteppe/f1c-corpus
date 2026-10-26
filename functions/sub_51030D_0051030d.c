char __usercall sub_51030D@<al>(_DWORD *a1@<esi>)
{
  unsigned __int8 **v1; // ebx
  unsigned __int8 *v2; // edi
  unsigned __int16 v3; // ax
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // edi
  int v6; // eax
  unsigned __int8 *v7; // edi
  int v8; // eax
  unsigned __int8 *v9; // edi
  int v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v12; // eax
  int v13; // eax
  unsigned __int8 *v14; // edi
  int v15; // eax
  unsigned __int8 *v16; // edi
  int v18; // ecx
  _DWORD *v19; // eax
  int v20; // [esp+8h] [ebp-20h]
  _DWORD *v21; // [esp+Ch] [ebp-1Ch]
  int v22; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  _DWORD *v24; // [esp+18h] [ebp-10h]
  int v25; // [esp+1Ch] [ebp-Ch]
  int v26; // [esp+20h] [ebp-8h]
  int v27; // [esp+20h] [ebp-8h]
  int v28; // [esp+20h] [ebp-8h]
  unsigned __int8 *v29; // [esp+24h] [ebp-4h]
  unsigned __int8 *v30; // [esp+24h] [ebp-4h]
  unsigned __int8 *v31; // [esp+24h] [ebp-4h]
  unsigned __int8 *v32; // [esp+24h] [ebp-4h]
  unsigned __int8 *v33; // [esp+24h] [ebp-4h]
  unsigned __int8 *v34; // [esp+24h] [ebp-4h]
  unsigned __int8 *v35; // [esp+24h] [ebp-4h]

  v1 = (unsigned __int8 **)a1[5];
  v29 = v1[1];
  v2 = *v1;
  if ( !*(_BYTE *)(a1[100] + 81) )
  {
    *(_DWORD *)(*a1 + 20) = 61;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( !v29 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v2 = *v1;
    v29 = v1[1];
  }
  v30 = v29 - 1;
  LOBYTE(v3) = 0;
  HIBYTE(v3) = *v2;
  v4 = v2 + 1;
  v26 = v3;
  if ( !v30 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v4 = *v1;
    v30 = v1[1];
  }
  v31 = v30 - 1;
  v27 = *v4 + v26;
  v5 = v4 + 1;
  if ( !v31 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v5 = *v1;
    v31 = v1[1];
  }
  v6 = *v5;
  v32 = v31 - 1;
  v7 = v5 + 1;
  v22 = v6;
  if ( v27 != 2 * v6 + 6 || v6 < 1 || v6 > 4 )
  {
    *(_DWORD *)(*a1 + 20) = 9;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    v6 = v22;
  }
  *(_DWORD *)(*a1 + 20) = 102;
  *(_DWORD *)(*a1 + 24) = v6;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  v23 = 0;
  a1[72] = v22;
  if ( v22 > 0 )
  {
    v24 = a1 + 73;
    do
    {
      if ( !v32 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
          return 0;
        v7 = *v1;
        v32 = v1[1];
      }
      v8 = *v7;
      v33 = v32 - 1;
      v9 = v7 + 1;
      v25 = v8;
      if ( !v33 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
          return 0;
        v9 = *v1;
        v33 = v1[1];
      }
      v10 = *v9;
      v32 = v33 - 1;
      v28 = 0;
      v11 = (_DWORD *)a1[49];
      v7 = v9 + 1;
      v20 = v10;
      v21 = v11;
      if ( (int)a1[8] <= 0 )
      {
LABEL_27:
        *(_DWORD *)(*a1 + 20) = 5;
        *(_DWORD *)(*a1 + 24) = v25;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
        v10 = v20;
        v11 = v21;
      }
      else
      {
        while ( v25 != *v11 )
        {
          ++v28;
          v11 += 21;
          v21 = v11;
          if ( v28 >= a1[8] )
            goto LABEL_27;
        }
      }
      *v24 = v11;
      v11[6] = v10 & 0xF;
      v11[5] = (v10 >> 4) & 0xF;
      v12 = (_DWORD *)(*a1 + 24);
      *v12 = v25;
      v12[1] = v11[5];
      v12[2] = v11[6];
      *(_DWORD *)(*a1 + 20) = 103;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
      ++v23;
      ++v24;
    }
    while ( v23 < v22 );
  }
  if ( !v32 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v7 = *v1;
    v32 = v1[1];
  }
  v13 = *v7;
  v34 = v32 - 1;
  v14 = v7 + 1;
  a1[90] = v13;
  if ( v34 )
    goto LABEL_35;
  if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
    return 0;
  v14 = *v1;
  v34 = v1[1];
LABEL_35:
  v15 = *v14;
  v35 = v34 - 1;
  v16 = v14 + 1;
  a1[91] = v15;
  if ( !v35 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v16 = *v1;
    v35 = v1[1];
  }
  v18 = (int)*v16 >> 4;
  a1[93] = *v16 & 0xF;
  v19 = (_DWORD *)*a1;
  a1[92] = v18 & 0xF;
  v19 += 6;
  *v19 = a1[90];
  v19[1] = a1[91];
  v19[2] = a1[92];
  v19[3] = a1[93];
  *(_DWORD *)(*a1 + 20) = 104;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  *(_DWORD *)(a1[100] + 84) = 0;
  ++a1[31];
  v1[1] = v35 - 1;
  *v1 = v16 + 1;
  return 1;
}
