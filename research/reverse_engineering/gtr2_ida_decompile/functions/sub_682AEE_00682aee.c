int __thiscall sub_682AEE(int this, int a2, int a3)
{
  int v5; // eax
  int v6; // esi
  int *v7; // ecx
  int v8; // esi
  int v9; // eax
  int *v10; // edi
  int v11; // esi
  int *v12; // esi
  int v13; // ecx
  int v14; // esi
  _DWORD *v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int result; // eax
  int *v20; // esi
  int v21; // eax
  int v22; // edi
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  int v26; // ecx
  int v27; // esi
  int v28; // eax
  int v29; // edi
  int v30; // eax
  int v31; // edi
  unsigned int v32; // eax
  int v33; // esi
  int v34; // eax
  BOOL v35; // eax
  int v36; // esi
  int v37; // edi
  int v38; // eax
  int v39; // ecx
  int v40; // esi
  int v41; // ecx
  int v42; // ecx
  int v43; // eax
  int v44; // edi
  bool v45; // cf
  unsigned int v46; // eax
  int v47; // ecx
  _DWORD *v48; // esi
  int v49; // eax
  double v50; // [esp+14h] [ebp-38h]
  _DWORD *v51; // [esp+24h] [ebp-28h]
  unsigned int v52; // [esp+24h] [ebp-28h]
  unsigned int v53; // [esp+24h] [ebp-28h]
  int v54; // [esp+24h] [ebp-28h]
  _DWORD *v55; // [esp+28h] [ebp-24h]
  int v56; // [esp+28h] [ebp-24h]
  int v57; // [esp+28h] [ebp-24h]
  int v58; // [esp+28h] [ebp-24h]
  int v59; // [esp+2Ch] [ebp-20h]
  int v60; // [esp+2Ch] [ebp-20h]
  int v61; // [esp+2Ch] [ebp-20h]
  unsigned int v62; // [esp+30h] [ebp-1Ch]
  _DWORD *v63; // [esp+34h] [ebp-18h]
  int v64; // [esp+38h] [ebp-14h]
  BOOL v65; // [esp+38h] [ebp-14h]
  int *v66; // [esp+3Ch] [ebp-10h]
  BOOL v67; // [esp+3Ch] [ebp-10h]
  _DWORD *v68; // [esp+3Ch] [ebp-10h]
  int v69; // [esp+3Ch] [ebp-10h]
  int v70; // [esp+40h] [ebp-Ch]
  int v71; // [esp+40h] [ebp-Ch]
  int v72; // [esp+40h] [ebp-Ch]
  int v73; // [esp+44h] [ebp-8h]
  int v74; // [esp+44h] [ebp-8h]
  int v75; // [esp+44h] [ebp-8h]
  unsigned int v76; // [esp+44h] [ebp-8h]
  int v77; // [esp+44h] [ebp-8h]
  unsigned int v78; // [esp+44h] [ebp-8h]
  int v79; // [esp+48h] [ebp-4h]
  int v80; // [esp+48h] [ebp-4h]
  unsigned int v81; // [esp+54h] [ebp+8h]

  if ( (*(_DWORD *)a2 & 0xFFF00000) != 0x50000000 )
    return 1;
  v55 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(a2 + 16));
  v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v55[1]) + 4);
  if ( (v5 & 1) == 0 || (v5 & 0x1000) != 0 )
    return 1;
  v6 = *(_DWORD *)a2 & 0xFFFFF;
  v81 = v6;
  v64 = 14;
  if ( v6 )
  {
    v7 = *(int **)(a2 + 8);
    v66 = &v7[v6];
    v59 = v6;
    do
    {
      v8 = *v7;
      v9 = *(_DWORD *)(this + 20);
      if ( a3 )
      {
        v10 = *(int **)(v9 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * v8) + 48));
        v11 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * *v66) + 48);
      }
      else
      {
        v10 = *(int **)(v9 + 4 * v8);
        v11 = *v66;
      }
      v12 = *(int **)(v9 + 4 * v11);
      v73 = 0;
      v79 = *v10;
      if ( (*v10 & 4) != 0 && (*(_BYTE *)v12 & 4) != 0 || (v79 & 8) != 0 && (*(_BYTE *)v12 & 8) != 0 || v10 == v12 )
        v73 = 4;
      if ( (*v10 & 4) != 0 && (*(_BYTE *)v12 & 8) != 0 || (v79 & 8) != 0 && (*(_BYTE *)v12 & 4) != 0 )
        v73 |= 8u;
      if ( (v79 & 2) != 0 && (*(_BYTE *)v12 & 2) != 0 )
        v73 |= 2u;
      v64 &= v73;
      ++v66;
      ++v7;
      --v59;
    }
    while ( v59 );
  }
  *v55 |= v64;
  if ( !a3 )
    goto LABEL_57;
  v60 = -1;
  v50 = 0.0;
  v74 = 0;
  v70 = 0;
  v62 = 0;
  if ( !v81 )
    goto LABEL_54;
  v13 = *(_DWORD *)(this + 20);
  v14 = *(_DWORD *)(this + 16);
  v63 = *(_DWORD **)(a2 + 8);
  v15 = &v63[v81];
  v51 = v15;
  while ( 1 )
  {
    v16 = *(_DWORD *)(v13 + 4 * *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v63) + 48));
    v80 = *(_DWORD *)(v13 + 4 * *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v15) + 48));
    v65 = (*(_BYTE *)(*(_DWORD *)(v14 + 4 * *(_DWORD *)(v16 + 4)) + 5) & 1) != 0 && *(_DWORD *)(v16 + 8) == -1;
    v67 = (*(_BYTE *)(*(_DWORD *)(v14 + 4 * *(_DWORD *)(v80 + 4)) + 5) & 1) != 0 && *(_DWORD *)(v80 + 8) == -1;
    if ( v65 && 0.0 == *(double *)(v16 + 32) || v67 && 0.0 == *(double *)(v80 + 32) )
      goto LABEL_42;
    if ( !v65 )
      break;
    if ( !v67 )
    {
      if ( 1.0 != *(double *)(v16 + 32) )
        goto LABEL_50;
      v17 = *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v15) + 48);
      goto LABEL_48;
    }
    v50 = *(double *)(v80 + 32) * *(double *)(v16 + 32) + v50;
LABEL_42:
    ++v74;
LABEL_49:
    ++v62;
    ++v63;
    v15 = ++v51;
    if ( v62 >= v81 )
      goto LABEL_50;
  }
  if ( v67 && 1.0 == *(double *)(v80 + 32) )
  {
    v17 = *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v63) + 48);
LABEL_48:
    ++v70;
    v60 = v17;
    goto LABEL_49;
  }
LABEL_50:
  if ( v70 == 1 && v81 - 1 == v74 && 0.0 == v50 )
  {
    *(_DWORD *)a2 = 0;
    v55[12] = v60;
    return 0;
  }
LABEL_54:
  if ( v81 == v74 )
  {
    *(_DWORD *)a2 = 0;
    v18 = sub_681AAA((void *)this, *(_DWORD *)(this + 120), 0, 0, v50);
    v55[12] = v18;
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v18) + 48) = v18;
    return 0;
  }
LABEL_57:
  v56 = 0;
  v75 = 0;
  v71 = 0;
  v61 = 0;
  if ( v81 )
  {
    v68 = *(_DWORD **)(a2 + 8);
    v20 = &v68[v81];
    v52 = v81;
    do
    {
      v21 = *(_DWORD *)(this + 20);
      v22 = *v20;
      v23 = *(_DWORD *)(v21 + 4 * *v68);
      if ( a3 )
      {
        v23 = *(_DWORD *)(v21 + 4 * *(_DWORD *)(v23 + 48));
        v22 = *(_DWORD *)(*(_DWORD *)(v21 + 4 * v22) + 48);
      }
      v24 = *(_DWORD *)(v21 + 4 * v22);
      v25 = *(_DWORD *)(this + 16);
      if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v23 + 4)) + 5) & 1) != 0
        && *(_DWORD *)(v23 + 8) == -1
        && 0.0 == *(double *)(v23 + 32)
        || (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v24 + 4)) + 5) & 1) != 0
        && *(_DWORD *)(v24 + 8) == -1
        && 0.0 == *(double *)(v24 + 32) )
      {
        ++v56;
        ++v71;
      }
      else
      {
        ++v75;
        v71 = 0;
      }
      ++v68;
      ++v20;
      --v52;
    }
    while ( v52 );
    if ( v56
      && (v75 != 2 || (*(_BYTE *)(this + 108) & 0x20) != 0)
      && (v75 == 1 || v56 == v71 || (*(_BYTE *)(this + 108) & 6) == 0) )
    {
      result = 0;
      if ( !v75 )
      {
        *(_DWORD *)a2 = 0;
        return result;
      }
      v76 = 0;
      v53 = 0;
      v57 = 4 * v81;
      v69 = 4 * v81;
      do
      {
        v26 = *(_DWORD *)(a2 + 8);
        v27 = *(_DWORD *)(v26 + 4 * result);
        v28 = *(_DWORD *)(this + 20);
        if ( a3 )
        {
          v72 = *(_DWORD *)(v28 + 4 * *(_DWORD *)(*(_DWORD *)(v28 + 4 * v27) + 48));
          v29 = *(_DWORD *)(*(_DWORD *)(v28 + 4 * *(_DWORD *)(v69 + v26)) + 48);
        }
        else
        {
          v72 = *(_DWORD *)(v28 + 4 * v27);
          v29 = *(_DWORD *)(v69 + v26);
        }
        v30 = *(_DWORD *)(v28 + 4 * v29);
        v31 = *(_DWORD *)(this + 16);
        if ( ((*(_BYTE *)(*(_DWORD *)(v31 + 4 * *(_DWORD *)(v72 + 4)) + 5) & 1) == 0
           || *(_DWORD *)(v72 + 8) != -1
           || 0.0 != *(double *)(v72 + 32))
          && ((*(_BYTE *)(*(_DWORD *)(v31 + 4 * *(_DWORD *)(v30 + 4)) + 5) & 1) == 0
           || *(_DWORD *)(v30 + 8) != -1
           || 0.0 != *(double *)(v30 + 32)) )
        {
          v32 = v76++;
          *(_DWORD *)(v26 + 4 * v32) = v27;
          v33 = v57;
          v57 += 4;
          *(_DWORD *)(v33 + *(_DWORD *)(a2 + 8)) = *(_DWORD *)(v69 + *(_DWORD *)(a2 + 8));
        }
        v69 += 4;
        result = ++v53;
      }
      while ( v53 < v81 );
      qmemcpy(
        (void *)(*(_DWORD *)(a2 + 8) + 4 * v76),
        (const void *)(*(_DWORD *)(a2 + 8) + 4 * v81),
        4 * ((4 * v76) >> 2));
      if ( v76 == 1 )
        v34 = 542113793;
      else
        v34 = v76 & 0xFFFFF | 0x50000000;
      *(_DWORD *)a2 = v34;
      *(_DWORD *)(a2 + 4) = 2 * v76;
      *(_DWORD *)(a2 + 12) = 1;
      v35 = v81 != v76;
      v81 = v76;
      v61 = v35;
    }
  }
  if ( v81 <= 1 || v81 == 2 && (*(_BYTE *)(this + 108) & 0x20) == 0 )
  {
    v36 = 0;
    v77 = 0;
    if ( v81 )
    {
      v37 = 4 * v81;
      v54 = 4 * v81;
      do
      {
        if ( a3 )
        {
          v42 = *(_DWORD *)(a2 + 8);
          v43 = *(_DWORD *)(this + 20);
          v40 = *(_DWORD *)(v43 + 4 * *(_DWORD *)(*(_DWORD *)(v43 + 4 * *(_DWORD *)(v42 + 4 * v36)) + 48));
          v41 = *(_DWORD *)(v43 + 4 * *(_DWORD *)(*(_DWORD *)(v43 + 4 * *(_DWORD *)(v37 + v42)) + 48));
        }
        else
        {
          v38 = *(_DWORD *)(a2 + 8);
          v39 = *(_DWORD *)(this + 20);
          v40 = *(_DWORD *)(v39 + 4 * *(_DWORD *)(v38 + 4 * v36));
          v41 = *(_DWORD *)(v39 + 4 * *(_DWORD *)(v37 + v38));
        }
        v44 = *(_DWORD *)(this + 16);
        if ( ((*(_BYTE *)(*(_DWORD *)(v44 + 4 * *(_DWORD *)(v40 + 4)) + 5) & 1) == 0
           || *(_DWORD *)(v40 + 8) != -1
           || 1.0 != *(double *)(v40 + 32))
          && ((*(_BYTE *)(*(_DWORD *)(v44 + 4 * *(_DWORD *)(v41 + 4)) + 5) & 1) == 0
           || *(_DWORD *)(v41 + 8) != -1
           || 1.0 != *(double *)(v41 + 32)) )
        {
          break;
        }
        v36 = v77 + 1;
        v37 = v54 + 4;
        v45 = ++v77 < v81;
        v54 += 4;
      }
      while ( v45 );
    }
    if ( v77 == v81 )
    {
      v46 = 0;
      v78 = 0;
      if ( v81 )
      {
        v58 = 4 * v81;
        do
        {
          v47 = *(_DWORD *)(a2 + 8);
          v48 = (_DWORD *)(v47 + 4 * v46);
          if ( a3 )
            v49 = *(_DWORD *)(*(_DWORD *)(this + 20)
                            + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v48) + 48));
          else
            v49 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v48);
          if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v49 + 4)) + 5) & 1) != 0
            && *(_DWORD *)(v49 + 8) == -1
            && 1.0 == *(double *)(v49 + 32) )
          {
            *v48 = *(_DWORD *)(v47 + v58);
          }
          v58 += 4;
          v46 = ++v78;
        }
        while ( v78 < v81 );
      }
      if ( v81 == 2 )
      {
        *(_DWORD *)a2 = 541065217;
        *(_DWORD *)(a2 + 4) = 2;
      }
      else
      {
        *(_DWORD *)a2 = 268435457;
        *(_DWORD *)(a2 + 4) = 1;
      }
      v61 = 1;
    }
  }
  return v61 == 0;
}
