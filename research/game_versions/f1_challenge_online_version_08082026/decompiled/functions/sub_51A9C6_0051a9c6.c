char __cdecl sub_51A9C6(_DWORD *a1, int a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // ebx
  char result; // al
  int v5; // eax
  unsigned __int8 *v6; // edx
  int v7; // eax
  bool v8; // cc
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // esi
  int v13; // edi
  int v14; // ecx
  int v15; // ecx
  int v16; // esi
  int v17; // ecx
  int v18; // esi
  int v19; // esi
  int v20; // ecx
  int *v21; // ecx
  int v22; // ecx
  int v23; // esi
  int v24; // esi
  int v25; // edi
  int v26; // edi
  int v27; // ecx
  int v28; // edi
  int v29; // esi
  __int16 v30; // cx
  int v31; // ecx
  int v32; // esi
  int v33; // esi
  int v34; // edi
  int v35; // esi
  int v36; // ecx
  int v37; // esi
  unsigned __int8 *v38; // [esp+4h] [ebp-54h] BYREF
  int v39; // [esp+8h] [ebp-50h]
  int v40; // [esp+Ch] [ebp-4Ch]
  int v41; // [esp+10h] [ebp-48h]
  int v42; // [esp+1Ch] [ebp-3Ch]
  _DWORD *v43; // [esp+20h] [ebp-38h]
  _DWORD *v44; // [esp+24h] [ebp-34h]
  int v45; // [esp+2Ch] [ebp-2Ch] BYREF
  int v46; // [esp+30h] [ebp-28h]
  int v47; // [esp+34h] [ebp-24h]
  int v48; // [esp+38h] [ebp-20h]
  int v49; // [esp+3Ch] [ebp-1Ch]
  _WORD *v50; // [esp+40h] [ebp-18h]
  int v51; // [esp+44h] [ebp-14h]
  int *v52; // [esp+48h] [ebp-10h]
  int v53; // [esp+4Ch] [ebp-Ch]
  int v54; // [esp+50h] [ebp-8h]
  int i; // [esp+54h] [ebp-4h]

  v2 = a1;
  v3 = (_DWORD *)a1[101];
  if ( a1[63] && !v3[12] )
  {
    result = sub_51A968(a1);
    if ( !result )
      return result;
    v2 = a1;
  }
  v5 = v2[5];
  v6 = *(unsigned __int8 **)v5;
  v7 = *(_DWORD *)(v5 + 4);
  v53 = 0;
  v8 = v2[79] <= 0;
  v44 = v3 + 6;
  v45 = v3[8];
  v46 = v3[9];
  v39 = v7;
  v9 = v2[94];
  v47 = v3[10];
  v38 = v6;
  v10 = v3[4];
  v40 = v9;
  v11 = v3[5];
  v43 = v2;
  v48 = v3[11];
  if ( v8 )
    goto LABEL_66;
  v52 = v2 + 80;
  do
  {
    v50 = *(_WORD **)(a2 + 4 * v53);
    v12 = *v52;
    v13 = v2[*v52 + 73];
    i = v3[*(_DWORD *)(v13 + 20) + 13];
    v14 = v3[*(_DWORD *)(v13 + 24) + 17];
    v49 = v12;
    v51 = v13;
    v54 = v14;
    if ( v11 < 8 )
    {
      if ( !sub_51A794(&v38, v10, v11, 0) )
        return 0;
      v11 = v42;
      v10 = v41;
      if ( v42 < 8 )
      {
        v15 = 1;
LABEL_14:
        v18 = sub_51A87E((int)&v38, v10, v11, i, v15);
        if ( v18 < 0 )
          return 0;
        v10 = v41;
        v11 = v42;
        goto LABEL_16;
      }
    }
    v16 = (unsigned __int8)(v10 >> (v11 - 8));
    v17 = *(_DWORD *)(i + 4 * v16 + 212);
    if ( !v17 )
    {
      v15 = 9;
      goto LABEL_14;
    }
    v11 -= v17;
    v18 = *(unsigned __int8 *)(v16 + i + 1236);
LABEL_16:
    if ( v18 )
    {
      if ( v11 < v18 )
      {
        if ( !sub_51A794(&v38, v10, v11, v18) )
          return 0;
        v10 = v41;
        v11 = v42;
      }
      v11 -= v18;
      i = (1 << v18) - 1;
      v19 = v18;
      v20 = (v10 >> v11) & i;
      v13 = v51;
      if ( v20 >= dword_5B03A0[v19] )
        v18 = (v10 >> v11) & i;
      else
        v18 = v20 + dword_5B03E0[v19];
    }
    if ( *(_BYTE *)(v13 + 48) )
    {
      v21 = &v45 + v49;
      *v21 += v18;
      *v50 = *v21;
      if ( *(int *)(v13 + 36) > 1 )
      {
        i = 1;
        while ( 1 )
        {
          if ( v11 < 8 )
          {
            if ( !sub_51A794(&v38, v10, v11, 0) )
              return 0;
            v11 = v42;
            v10 = v41;
            if ( v42 < 8 )
              break;
          }
          v22 = v54;
          v24 = (unsigned __int8)(v10 >> (v11 - 8));
          v25 = *(_DWORD *)(v54 + 4 * v24 + 212);
          if ( !v25 )
          {
            v23 = 9;
            goto LABEL_33;
          }
          v11 -= v25;
          v26 = *(unsigned __int8 *)(v24 + v54 + 1236);
LABEL_35:
          v27 = v26 >> 4;
          v28 = v26 & 0xF;
          v49 = v28;
          if ( v28 )
          {
            i += v27;
            if ( v11 < v28 )
            {
              if ( !sub_51A794(&v38, v10, v11, v28) )
                return 0;
              v10 = v41;
              v11 = v42;
            }
            v11 -= v28;
            v29 = (v10 >> v11) & ((1 << v28) - 1);
            if ( v29 >= dword_5B03A0[v49] )
              v30 = (v10 >> v11) & ((1 << v28) - 1);
            else
              v30 = v29 + dword_5B03E0[v49];
            v50[dword_5AF778[i]] = v30;
          }
          else
          {
            if ( v27 != 15 )
              goto LABEL_65;
            i += 15;
          }
          if ( ++i >= 64 )
            goto LABEL_65;
        }
        v22 = v54;
        v23 = 1;
LABEL_33:
        v26 = sub_51A87E((int)&v38, v10, v11, v22, v23);
        if ( v26 < 0 )
          return 0;
        v10 = v41;
        v11 = v42;
        goto LABEL_35;
      }
    }
    for ( i = 1; i < 64; ++i )
    {
      if ( v11 >= 8 )
        goto LABEL_52;
      if ( !sub_51A794(&v38, v10, v11, 0) )
        return 0;
      v11 = v42;
      v10 = v41;
      if ( v42 >= 8 )
      {
LABEL_52:
        v31 = v54;
        v33 = (unsigned __int8)(v10 >> (v11 - 8));
        v34 = *(_DWORD *)(v54 + 4 * v33 + 212);
        if ( v34 )
        {
          v35 = *(unsigned __int8 *)(v33 + v54 + 1236);
          v11 -= v34;
          goto LABEL_57;
        }
        v32 = 9;
      }
      else
      {
        v31 = v54;
        v32 = 1;
      }
      v35 = sub_51A87E((int)&v38, v10, v11, v31, v32);
      if ( v35 < 0 )
        return 0;
      v10 = v41;
      v11 = v42;
LABEL_57:
      v36 = v35 >> 4;
      v37 = v35 & 0xF;
      if ( v37 )
      {
        i += v36;
        if ( v11 < v37 )
        {
          if ( !sub_51A794(&v38, v10, v11, v37) )
            return 0;
          v10 = v41;
          v11 = v42;
        }
        v11 -= v37;
      }
      else
      {
        if ( v36 != 15 )
          break;
        i += 15;
      }
    }
LABEL_65:
    ++v53;
    v2 = a1;
    ++v52;
  }
  while ( v53 < a1[79] );
LABEL_66:
  *(_DWORD *)v2[5] = v38;
  *(_DWORD *)(v2[5] + 4) = v39;
  v2[94] = v40;
  --v3[12];
  v3[8] = v45;
  v3[9] = v46;
  v3[10] = v47;
  v3[5] = v11;
  v3[4] = v10;
  v3[11] = v48;
  return 1;
}
