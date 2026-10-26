int __thiscall sub_68A6CE(_DWORD *this, _DWORD *a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // ebx
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // ecx
  _DWORD *v10; // edi
  unsigned int *v11; // ecx
  int v12; // esi
  unsigned int v13; // eax
  int v14; // edx
  _DWORD *v15; // edi
  int v16; // edx
  unsigned int v17; // eax
  int v18; // edi
  _DWORD *v19; // eax
  int v20; // eax
  unsigned int v21; // edx
  int v22; // eax
  unsigned int v23; // edx
  _DWORD *v25; // edx
  unsigned int v26; // esi
  _DWORD *v27; // eax
  int v28; // eax
  int v29; // esi
  int v30; // edx
  int v31; // edi
  _DWORD *v32; // edx
  _DWORD *v33; // edx
  bool v34; // zf
  _DWORD *v35; // ecx
  unsigned int v36; // esi
  unsigned int v37; // edx
  _DWORD *v38; // eax
  int v39; // eax
  int v40; // ecx
  int v41; // esi
  _DWORD *v42; // edi
  _DWORD *v43; // ecx
  int v44; // eax
  int v45; // ecx
  int v46; // edx
  _DWORD *v47; // eax
  _DWORD *v48; // eax
  int v49; // ecx
  _DWORD *i; // edi
  bool v51; // cf
  int v52; // edi
  int v53; // eax
  int v54; // esi
  int v55; // [esp-8h] [ebp-B4h]
  unsigned int v56[2]; // [esp+Ch] [ebp-A0h] BYREF
  _DWORD *v57; // [esp+14h] [ebp-98h]
  int *v58; // [esp+1Ch] [ebp-90h]
  int v59; // [esp+80h] [ebp-2Ch]
  _DWORD *v60; // [esp+84h] [ebp-28h]
  int v61; // [esp+88h] [ebp-24h]
  _DWORD *v62; // [esp+8Ch] [ebp-20h]
  int v63; // [esp+90h] [ebp-1Ch]
  _DWORD *v64; // [esp+94h] [ebp-18h]
  int v65; // [esp+98h] [ebp-14h]
  int v66; // [esp+9Ch] [ebp-10h]
  int v67; // [esp+A0h] [ebp-Ch]
  _DWORD *v68; // [esp+A4h] [ebp-8h]
  unsigned int v69; // [esp+A8h] [ebp-4h]
  _DWORD *v70; // [esp+BCh] [ebp+10h]
  unsigned int v71; // [esp+BCh] [ebp+10h]
  _DWORD *v72; // [esp+C0h] [ebp+14h]
  _DWORD *v73; // [esp+C4h] [ebp+18h]

  v6 = this;
  v62 = this;
  v7 = this[5];
  v8 = *(_DWORD **)(*(_DWORD *)(v7 + 4 * a5) + 48);
  v9 = *(_DWORD *)(v7 + 4 * a6);
  v70 = *(_DWORD **)(*(_DWORD *)(v7 + 4 * a4) + 48);
  v63 = *(_DWORD *)(v7 + 4 * (_DWORD)v70);
  v10 = *(_DWORD **)(v9 + 48);
  v11 = *(unsigned int **)(v7 + 4 * a3);
  v67 = *(_DWORD *)(v7 + 4 * (_DWORD)v8);
  v72 = v8;
  v12 = *(_DWORD *)(v7 + 4 * (_DWORD)v10);
  v13 = *v11;
  v68 = (_DWORD *)(*v11 & 0x40);
  v73 = v10;
  v14 = *(_DWORD *)(*(_DWORD *)(v62[4] + 4 * v11[1]) + 4);
  v61 = v12;
  if ( (v14 & 1) == 0 || (v14 & 0x1000) != 0 )
    return 0;
  if ( (v13 & 0xE000000) == 0 && (*a2 & 0xFFF00000) == 0x30000000 )
  {
    v15 = (_DWORD *)v67;
    v16 = *(_DWORD *)v67 | *(_DWORD *)v12;
    if ( (v16 & 0x8000000) != 0 )
    {
      v17 = v13 | 0x8000000;
    }
    else if ( (v16 & 0x4000000) != 0 )
    {
      v17 = v13 | 0x4000000;
    }
    else
    {
      if ( ((unsigned int)&dword_2000000 & v16) == 0 )
      {
LABEL_12:
        *v11 |= *v15 & *(_DWORD *)v12 & 0x1F;
        goto LABEL_14;
      }
      v17 = (unsigned int)&dword_2000000 | v13;
    }
    *v11 = v17;
    goto LABEL_12;
  }
  v15 = (_DWORD *)v67;
LABEL_14:
  if ( ((*(_BYTE *)v15 | *(_BYTE *)v12) & 0x40) != 0 && (*a2 & 0xFFF00000) == 0x30000000 )
    *v11 |= 0x40u;
  if ( (*a2 & 0xFFF00000) == 0x30000000 )
  {
    *v11 |= *v15 & *(_DWORD *)v12 & 0x1F;
    if ( v70 == v72 && (*(_BYTE *)v12 & 4) != 0 )
      *v11 |= 4u;
    if ( v70 == v73 && (*(_BYTE *)v15 & 8) != 0 )
      *v11 |= 8u;
  }
  if ( (*a2 & 0xFFF00000) != 0x30000000 )
    return 0;
  v18 = v63;
  if ( !v68 && (*(_BYTE *)v63 & 4) != 0 )
    goto LABEL_27;
  v66 = *(_DWORD *)(*(_DWORD *)(v6[4] + 4 * *(_DWORD *)(v63 + 4)) + 4);
  if ( (v66 & 0x100) != 0 && *(_DWORD *)(v63 + 8) == -1 )
  {
    v19 = v72;
    if ( *(double *)(v63 + 32) < 0.0 )
      v19 = v73;
    goto LABEL_88;
  }
  v19 = v72;
  if ( v72 == v73 )
  {
LABEL_88:
    v11[12] = (unsigned int)v19;
    return 0;
  }
  v20 = v6[4];
  v65 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v67 + 4)) + 4) & 0x100;
  if ( v65 )
  {
    if ( *(_DWORD *)(v67 + 8) == -1
      && (*(_BYTE *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
      && *(_DWORD *)(v12 + 8) == -1
      && *(double *)(v67 + 32) == *(double *)(v12 + 32) )
    {
LABEL_27:
      v19 = v72;
      goto LABEL_88;
    }
  }
  if ( v68 )
    return 0;
  if ( *(_DWORD *)(v63 + 8) == -1 && (v66 & 2) != 0 )
  {
    v68 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v63 + 72));
    if ( (*v68 & 0xFFF00000) == 0x10100000
      && v65
      && *(_DWORD *)(v67 + 8) == -1
      && 0.0 == *(double *)(v67 + 32)
      && (*(_BYTE *)(*(_DWORD *)(v6[4] + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
      && *(_DWORD *)(v12 + 8) == -1
      && 1.0 == *(double *)(v12 + 32) )
    {
      v21 = 0;
      if ( v68[3] )
      {
        v69 = v68[4];
        do
        {
          if ( *(_DWORD **)v69 == v70 )
            break;
          v69 += 4;
          ++v21;
        }
        while ( v21 < v68[3] );
      }
      v22 = v6[5];
      v23 = *(_DWORD *)(*(_DWORD *)(v22 + 4 * *(_DWORD *)(v68[2] + 4 * v21)) + 48);
      if ( (**(_BYTE **)(v22 + 4 * v23) & 1) != 0 )
      {
        v11[12] = v23;
        return 0;
      }
      v18 = v63;
    }
  }
  if ( *(_DWORD *)(v18 + 8) != -1 )
    return 0;
  if ( (v66 & 2) != 0 )
  {
    v25 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v18 + 72));
    if ( (*v25 & 0xFFF00000) == 0x20500000 && v65 && *(_DWORD *)(v67 + 8) == -1 && 0.0 == *(double *)(v67 + 32) )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v6[4] + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
        && *(_DWORD *)(v12 + 8) == -1
        && 1.0 == *(double *)(v12 + 32) )
      {
        v26 = v25[3];
        v69 = 0;
        if ( v26 )
        {
          v27 = (_DWORD *)v25[4];
          do
          {
            if ( (_DWORD *)*v27 == v70 )
              break;
            ++v69;
            ++v27;
          }
          while ( v69 < v26 );
        }
        v28 = v25[3];
        v29 = v6[5];
        v30 = v25[2];
        v68 = 0;
        v59 = 4 * v28;
        v64 = (_DWORD *)(v30 + 4 * v69);
        v31 = -4 * v28;
        v6 = v62;
        v32 = (_DWORD *)(v30 + 4 * (v69 + v28));
        v69 = (unsigned int)v32;
        while ( 1 )
        {
          v33 = *(_DWORD **)(v29 + 4 * *(_DWORD *)(*(_DWORD *)(v29 + 4 * *v32) + 48));
          v60 = *(_DWORD **)(*(_DWORD *)(v29 + 4 * *v64) + 48);
          v34 = (**(_BYTE **)(v29 + 4 * (_DWORD)v60) & 1) == 0;
          v62 = v33;
          if ( !v34
            && (*(_BYTE *)(*(_DWORD *)(v6[4] + 4 * v33[1]) + 5) & 1) != 0
            && v62[2] == -1
            && *((double *)v62 + 4) < 0.0 )
          {
            break;
          }
          v68 = (_DWORD *)((char *)v68 + 1);
          v64 = (_DWORD *)((char *)v64 + v59);
          v32 = (_DWORD *)(v31 + v69);
          v69 += v31;
          if ( (unsigned int)v68 >= 2 )
          {
            v12 = v61;
            goto LABEL_76;
          }
        }
        v19 = v60;
        goto LABEL_88;
      }
LABEL_76:
      v18 = v63;
    }
  }
  if ( *(_DWORD *)(v18 + 8) != -1 )
    return 0;
  if ( (v66 & 2) == 0 )
    return 0;
  v35 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v18 + 72));
  if ( (*v35 & 0xFFF00000) != 0x20400000 )
    return 0;
  v66 = -1;
  if ( v65
    && *(_DWORD *)(v67 + 8) == -1
    && (*(_BYTE *)(*(_DWORD *)(v6[4] + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
    && *(_DWORD *)(v12 + 8) == -1 )
  {
    if ( 0.0 == *(double *)(v67 + 32) && 1.0 == *(double *)(v12 + 32) )
    {
      v66 = 538968065;
    }
    else if ( 1.0 == *(double *)(v67 + 32) && 0.0 == *(double *)(v12 + 32) )
    {
      v66 = 540016641;
    }
  }
  v36 = v35[3];
  v37 = 0;
  if ( v36 )
  {
    v38 = (_DWORD *)v35[4];
    do
    {
      if ( (_DWORD *)*v38 == v70 )
        break;
      ++v37;
      ++v38;
    }
    while ( v37 < v36 );
  }
  v39 = v35[3];
  v40 = v35[2];
  v71 = 0;
  v61 = 4 * v39;
  v41 = -4 * v39;
  v42 = (_DWORD *)(v40 + 4 * v37);
  v43 = (_DWORD *)(v40 + 4 * (v37 + v39));
  v64 = v42;
  v69 = (unsigned int)v43;
  while ( 1 )
  {
    v44 = v6[5];
    v45 = *(_DWORD *)(v44 + 4 * *v43);
    v68 = *(_DWORD **)(*(_DWORD *)(v44 + 4 * *v42) + 48);
    v46 = *(_DWORD *)(v45 + 48);
    v47 = *(_DWORD **)(v44 + 4 * v46);
    if ( v47[2] == -1 && (*(_BYTE *)(*(_DWORD *)(v6[4] + 4 * v47[1]) + 4) & 2) != 0 )
    {
      v48 = *(_DWORD **)(v6[6] + 4 * v47[18]);
      if ( (*v48 & 0xFFF00000) == 0x10100000 )
      {
        v49 = 0;
        if ( v48[3] )
        {
          for ( i = (_DWORD *)v48[4]; *i != v46; i = v60 )
          {
            v51 = (unsigned int)++v49 < v48[3];
            v60 = i + 1;
            if ( !v51 )
              break;
          }
        }
        v52 = *(_DWORD *)(*(_DWORD *)(v6[5] + 4 * *(_DWORD *)(v48[2] + 4 * v49)) + 48);
        v65 = v66;
        if ( v66 != -1 )
          goto LABEL_114;
        if ( v72 == (_DWORD *)v52 && v73 == v68 )
        {
          v65 = 536870913;
          goto LABEL_114;
        }
        if ( v72 == v68 && v73 == (_DWORD *)v52 )
          break;
      }
    }
    v42 = (_DWORD *)((char *)v64 + v61);
    ++v71;
    v43 = (_DWORD *)(v41 + v69);
    v64 = (_DWORD *)((char *)v64 + v61);
    v69 += v41;
    if ( v71 >= 2 )
      return 0;
  }
  v65 = 537919489;
LABEL_114:
  sub_680CEC(v56);
  v53 = sub_6811D1((char *)v56, v65, 2, 1, 0);
  if ( v53 >= 0 )
  {
    v53 = sub_680D22(v56, (int)a2);
    if ( v53 >= 0 )
    {
      *v58 = a3;
      v55 = (int)v68;
      *v57 = v68;
      v57[1] = v52;
      v53 = sub_689751(v6, v56, a3, v55, v52);
    }
  }
  v54 = v53;
  nullsub_9();
  return v54;
}
