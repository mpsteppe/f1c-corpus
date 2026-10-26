int __stdcall sub_6CF8F0(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // eax
  _DWORD *v4; // edi
  int result; // eax
  int v6; // eax
  unsigned __int8 *v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // ebx
  int v11; // ecx
  int v12; // edx
  int *v13; // ecx
  int v14; // ebx
  int v15; // esi
  int v16; // ecx
  int v17; // edi
  int v18; // ecx
  int v19; // edi
  int v20; // esi
  int *v21; // esi
  int v22; // ecx
  int v23; // ecx
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // edi
  int v29; // ecx
  int v30; // edi
  int v31; // esi
  int v32; // esi
  int v33; // ecx
  int v34; // edi
  int v35; // ecx
  int v36; // edi
  int v37; // ecx
  int v38; // edi
  int v39; // esi
  bool v40; // cc
  _DWORD *v41; // ecx
  int v42; // esi
  int v43; // edx
  int v44; // eax
  int v45; // ecx
  unsigned __int8 *v46; // [esp+8h] [ebp-40h] BYREF
  int v47; // [esp+Ch] [ebp-3Ch]
  int v48; // [esp+10h] [ebp-38h]
  int v49; // [esp+14h] [ebp-34h]
  _DWORD *v50; // [esp+18h] [ebp-30h]
  int v51; // [esp+1Ch] [ebp-2Ch]
  int v52; // [esp+20h] [ebp-28h]
  int v53; // [esp+24h] [ebp-24h]
  int v54; // [esp+28h] [ebp-20h]
  _DWORD *v55; // [esp+2Ch] [ebp-1Ch]
  int v56; // [esp+30h] [ebp-18h]
  _WORD *v57; // [esp+34h] [ebp-14h]
  int *v58; // [esp+38h] [ebp-10h]
  int v59; // [esp+3Ch] [ebp-Ch]
  int v60; // [esp+40h] [ebp-8h]
  int *v61; // [esp+44h] [ebp-4h]

  v2 = a1;
  v3 = a1[70];
  v4 = (_DWORD *)a1[112];
  v55 = v4;
  if ( v3 )
  {
    if ( !v4[9] )
    {
      result = sub_6CF880(a1);
      if ( !result )
        return result;
    }
  }
  if ( v4[2] )
    goto LABEL_68;
  v6 = a1[6];
  v7 = *(unsigned __int8 **)v6;
  v8 = *(_DWORD *)(v6 + 4);
  v9 = v4[4];
  v46 = v7;
  v51 = v4[5];
  v52 = v4[6];
  v10 = v4[7];
  v54 = v4[8];
  v11 = a1[90];
  v47 = v8;
  v12 = v4[3];
  v50 = a1;
  v53 = v10;
  v59 = 0;
  if ( v11 <= 0 )
    goto LABEL_67;
  v13 = v4 + 28;
  v58 = a1 + 91;
  v61 = v4 + 28;
  while ( 2 )
  {
    v14 = *v13;
    v57 = *(_WORD **)(a2 + 4 * v59);
    v15 = *(v13 - 10);
    v60 = v14;
    if ( v9 >= 8 )
      goto LABEL_12;
    if ( !sub_6CF670(&v46, v12, v9, 0) )
      return 0;
    v9 = v49;
    v12 = v48;
    if ( v49 >= 8 )
    {
LABEL_12:
      v17 = (unsigned __int8)(v12 >> (v9 - 8));
      v18 = *(_DWORD *)(v15 + 4 * v17 + 144);
      if ( v18 )
      {
        v19 = *(unsigned __int8 *)(v17 + v15 + 1168);
        v9 -= v18;
        goto LABEL_17;
      }
      v16 = 9;
    }
    else
    {
      v16 = 1;
    }
    v19 = sub_6CF790((int)&v46, v12, v9, v15, v16);
    if ( v19 < 0 )
      return 0;
    v12 = v48;
    v9 = v49;
LABEL_17:
    if ( v19 )
    {
      if ( v9 < v19 )
      {
        if ( !sub_6CF670(&v46, v12, v9, v19) )
          return 0;
        v12 = v48;
        v9 = v49;
      }
      v9 -= v19;
      v20 = (v12 >> v9) & ((1 << v19) - 1);
      v14 = v60;
      if ( v20 >= dword_747CE8[v19] )
        v19 = (v12 >> v9) & ((1 << v19) - 1);
      else
        v19 = v20 + dword_747D28[v19];
    }
    v21 = v61;
    if ( v61[10] )
    {
      v22 = *v58;
      *(&v51 + v22) += v19;
      *v57 = *(&v51 + v22);
    }
    v23 = v21[20];
    v24 = 1;
    if ( v23 )
    {
      while ( 1 )
      {
        if ( v9 < 8 )
        {
          if ( !sub_6CF670(&v46, v12, v9, 0) )
            return 0;
          v9 = v49;
          v12 = v48;
          if ( v49 < 8 )
            break;
        }
        v26 = (unsigned __int8)(v12 >> (v9 - 8));
        v27 = *(_DWORD *)(v14 + 4 * v26 + 144);
        if ( !v27 )
        {
          v25 = 9;
          goto LABEL_34;
        }
        v28 = *(unsigned __int8 *)(v26 + v14 + 1168);
        v9 -= v27;
LABEL_36:
        v29 = v28 >> 4;
        v30 = v28 & 0xF;
        if ( v30 )
        {
          v56 = v29 + v24;
          if ( v9 < v30 )
          {
            if ( !sub_6CF670(&v46, v12, v9, v30) )
              return 0;
            v12 = v48;
            v9 = v49;
          }
          v9 -= v30;
          v31 = (v12 >> v9) & ((1 << v30) - 1);
          if ( v31 >= dword_747CE8[v30] )
            v30 = (v12 >> v9) & ((1 << v30) - 1);
          else
            LOWORD(v30) = v31 + dword_747D28[v30];
          v32 = v56;
          v57[dword_744A70[v56]] = v30;
          v14 = v60;
        }
        else
        {
          if ( v29 != 15 )
            goto LABEL_65;
          v32 = v24 + 15;
        }
        v24 = v32 + 1;
        if ( v24 >= 64 )
          goto LABEL_65;
      }
      v25 = 1;
LABEL_34:
      v28 = sub_6CF790((int)&v46, v12, v9, v14, v25);
      if ( v28 < 0 )
        return 0;
      v12 = v48;
      v9 = v49;
      goto LABEL_36;
    }
    do
    {
      if ( v9 >= 8 )
        goto LABEL_52;
      if ( !sub_6CF670(&v46, v12, v9, 0) )
        return 0;
      v9 = v49;
      v12 = v48;
      if ( v49 >= 8 )
      {
LABEL_52:
        v34 = (unsigned __int8)(v12 >> (v9 - 8));
        v35 = *(_DWORD *)(v14 + 4 * v34 + 144);
        if ( v35 )
        {
          v36 = *(unsigned __int8 *)(v34 + v14 + 1168);
          v9 -= v35;
          goto LABEL_57;
        }
        v33 = 9;
      }
      else
      {
        v33 = 1;
      }
      v36 = sub_6CF790((int)&v46, v12, v9, v14, v33);
      if ( v36 < 0 )
        return 0;
      v12 = v48;
      v9 = v49;
LABEL_57:
      v37 = v36 >> 4;
      v38 = v36 & 0xF;
      if ( v38 )
      {
        v39 = v37 + v24;
        if ( v9 < v38 )
        {
          if ( !sub_6CF670(&v46, v12, v9, v38) )
            return 0;
          v12 = v48;
          v9 = v49;
        }
        v9 -= v38;
      }
      else
      {
        if ( v37 != 15 )
          break;
        v39 = v24 + 15;
      }
      v24 = v39 + 1;
    }
    while ( v24 < 64 );
LABEL_65:
    v2 = a1;
    ++v61;
    v40 = ++v59 < a1[90];
    ++v58;
    if ( v40 )
    {
      v13 = v61;
      continue;
    }
    break;
  }
  v4 = v55;
LABEL_67:
  v41 = (_DWORD *)v2[6];
  *v41 = v46;
  v42 = v47;
  v4[3] = v12;
  v4[5] = v51;
  v43 = v54;
  v4[4] = v9;
  v44 = v52;
  v41[1] = v42;
  v45 = v53;
  v4[6] = v44;
  v4[7] = v45;
  v4[8] = v43;
LABEL_68:
  --v4[9];
  return 1;
}
