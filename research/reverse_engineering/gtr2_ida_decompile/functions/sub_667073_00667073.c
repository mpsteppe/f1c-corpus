BOOL __thiscall sub_667073(_DWORD *this, unsigned int a2, unsigned int a3, _DWORD *a4, unsigned int *a5)
{
  unsigned int i; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  unsigned int *v11; // ebx
  int v12; // esi
  int v13; // ecx
  unsigned int v14; // edx
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // eax
  int *v20; // edi
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  _DWORD *v26; // ecx
  _DWORD *v27; // ecx
  unsigned int v28; // eax
  unsigned int v29; // eax
  _DWORD *v30; // edx
  int v31; // eax
  int v32; // edi
  int v33; // ecx
  int v34; // ebx
  int v35; // ecx
  _DWORD *v36; // edx
  _DWORD *v37; // ecx
  _DWORD *v38; // edx
  int v39; // edi
  unsigned int v40; // ebx
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  double v44; // [esp+Ch] [ebp-24h] BYREF
  double v45; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD *v46; // [esp+1Ch] [ebp-14h]
  int v47; // [esp+20h] [ebp-10h]
  unsigned int v48; // [esp+24h] [ebp-Ch] BYREF
  unsigned int v49; // [esp+28h] [ebp-8h]
  unsigned int v50; // [esp+2Ch] [ebp-4h]

  for ( i = a2; ; i = *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4) )
  {
    while ( 1 )
    {
      if ( i == -1 )
        return 0;
      v7 = this[2];
      v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v7 + 20) + 4 * i) + 72);
      if ( v8 == -1 )
        return 0;
      v9 = *(_DWORD *)(*(_DWORD *)(v7 + 24) + 4 * v8);
      if ( *(_DWORD *)v9 != 268435457 )
        break;
LABEL_10:
      i = **(_DWORD **)(v9 + 8);
    }
    if ( *(_DWORD *)v9 != 542113793 )
      break;
    if ( sub_6640D2(this, **(_DWORD **)(v9 + 8), &v45) < 0 || 1.0 != v45 )
    {
      if ( sub_6640D2(this, *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4), &v45) < 0 || 1.0 != v45 )
        return 0;
      goto LABEL_10;
    }
  }
  if ( *(_DWORD *)v9 == 538968065 )
  {
    if ( sub_6640D2(this, **(_DWORD **)(v9 + 8), &v45) >= 0 && v45 == (double)a3 )
    {
      a2 = *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4);
      if ( sub_666F65(this, 0, &a2, 1u) >= 0 )
      {
        v11 = a5;
        if ( *a5 != -1 )
          return a2 == *a5;
        v12 = this[2];
        v13 = *(_DWORD *)(v12 + 20);
        v14 = a2;
        v15 = *(_DWORD *)(v13 + 4 * a2);
        if ( (*(_BYTE *)v15 & 2) != 0 )
        {
          v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * *(_DWORD *)(v15 + 4)) + 4);
          if ( (v16 & 0x100) == 0 && (v16 & 0x10) != 0 && (v16 & 0x200) != 0 )
          {
            v17 = a4;
            if ( a4 )
            {
              v18 = *(_DWORD *)(v13 + 4 * **(_DWORD **)(v9 + 8));
              goto LABEL_25;
            }
            goto LABEL_26;
          }
        }
      }
    }
    return 0;
  }
  if ( *(_DWORD *)v9 != 805306369 )
    return 0;
  v19 = this[2];
  v20 = *(int **)(v9 + 8);
  v21 = *(_DWORD *)(*(_DWORD *)(v19 + 20) + 4 * v20[1]);
  if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v19 + 16) + 4 * *(_DWORD *)(v21 + 4)) + 4) & 0x100) == 0 )
    return 0;
  if ( *(_DWORD *)(v21 + 8) != -1 )
    return 0;
  if ( 0.0 != *(double *)(v21 + 32) )
    return 0;
  v22 = this[2];
  v23 = *(_DWORD *)(*(_DWORD *)(v22 + 20) + 4 * v20[2]);
  if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * *(_DWORD *)(v23 + 4)) + 4) & 0x100) == 0 )
    return 0;
  if ( *(_DWORD *)(v23 + 8) != -1 )
    return 0;
  if ( 1.0 != *(double *)(v23 + 32) )
    return 0;
  v24 = this[2];
  v25 = *v20;
  v26 = *(_DWORD **)(*(_DWORD *)(v24 + 20) + 4 * v25);
  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v24 + 16) + 4 * v26[1]) + 4) & 2) == 0 )
    return 0;
  if ( v26[2] != -1 )
    return 0;
  v27 = *(_DWORD **)(*(_DWORD *)(this[2] + 24) + 4 * v26[18]);
  v28 = *v27 & 0xFFF00000;
  v46 = v27;
  if ( v28 != 541065216 )
    return 0;
  v29 = v27[3];
  a2 = 0;
  if ( v29 )
  {
    v30 = (_DWORD *)v27[4];
    do
    {
      if ( *v30 == v25 )
        break;
      ++a2;
      ++v30;
    }
    while ( a2 < v29 );
  }
  v49 = 0;
  v47 = 1;
  while ( 2 )
  {
    v31 = v27[3];
    v32 = v27[2];
    v33 = this[2];
    v34 = *(_DWORD *)(v33 + 20);
    v35 = *(_DWORD *)(v33 + 16);
    HIDWORD(v45) = *(_DWORD *)(v32 + 4 * (a2 + v49 * v31));
    v36 = *(_DWORD **)(v34 + 4 * HIDWORD(v45));
    if ( (*(_BYTE *)(*(_DWORD *)(v35 + 4 * v36[1]) + 4) & 2) == 0 )
      goto LABEL_61;
    if ( v36[2] != -1 )
      goto LABEL_61;
    v37 = *(_DWORD **)(*(_DWORD *)(this[2] + 24) + 4 * v36[18]);
    if ( (*v37 & 0xFFF00000) != 0x10100000 )
      goto LABEL_61;
    v50 = 0;
    if ( v37[3] )
    {
      v38 = (_DWORD *)v37[4];
      do
      {
        if ( *v38 == HIDWORD(v45) )
          break;
        ++v50;
        ++v38;
      }
      while ( v50 < v37[3] );
    }
    v39 = *(_DWORD *)(v32 + 4 * (a2 + v47 * v31));
    v40 = *(_DWORD *)(v37[2] + 4 * v50);
    if ( sub_6640D2(this, v39, &v44) < 0 )
      goto LABEL_61;
    if ( v44 != (double)a3 )
      goto LABEL_61;
    v48 = v40;
    if ( sub_666F65(this, 0, &v48, 1u) < 0 )
      goto LABEL_61;
    v11 = a5;
    if ( *a5 != -1 )
    {
      if ( v48 == *a5 )
        return 1;
      goto LABEL_61;
    }
    v41 = this[2];
    v14 = v48;
    v42 = *(_DWORD *)(*(_DWORD *)(v41 + 20) + 4 * v48);
    if ( (*(_BYTE *)v42 & 2) == 0
      || (v43 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v41 + 16) + 4 * *(_DWORD *)(v42 + 4)) + 4), (v43 & 0x100) != 0)
      || (v43 & 0x10) == 0
      || (v43 & 0x200) == 0 )
    {
LABEL_61:
      ++v49;
      --v47;
      if ( v49 >= 2 )
        return 0;
      v27 = v46;
      continue;
    }
    break;
  }
  v17 = a4;
  if ( a4 )
  {
    v18 = *(_DWORD *)(*(_DWORD *)(this[2] + 20) + 4 * v39);
LABEL_25:
    *v17 = *(_DWORD *)(v18 + 48);
  }
LABEL_26:
  *v11 = v14;
  return 1;
}
