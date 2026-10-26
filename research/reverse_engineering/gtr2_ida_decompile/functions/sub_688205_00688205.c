BOOL __thiscall sub_688205(_DWORD *this)
{
  _DWORD *v1; // esi
  unsigned int v2; // edi
  int *v3; // ebx
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // edi
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int *v19; // ebx
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // eax
  int v27; // ecx
  int v28; // edx
  int v29; // edi
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  int v33; // edi
  _DWORD *v34; // ecx
  int v35; // edi
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  _DWORD *v39; // eax
  int v40; // edx
  int v41; // edx
  _DWORD *v42; // edi
  int v43; // ecx
  int v44; // ecx
  unsigned int v45; // edx
  int v46; // eax
  void *v47; // edi
  int v48; // edi
  bool v49; // zf
  int v50; // eax
  int v51; // ecx
  int *v52; // eax
  double *v53; // edx
  double v54; // st7
  int v55; // eax
  int v56; // edi
  unsigned int v58; // [esp+14h] [ebp-38h]
  unsigned int k; // [esp+14h] [ebp-38h]
  int v60; // [esp+14h] [ebp-38h]
  int v62; // [esp+1Ch] [ebp-30h]
  unsigned int v63; // [esp+1Ch] [ebp-30h]
  int v64; // [esp+1Ch] [ebp-30h]
  unsigned int v65; // [esp+1Ch] [ebp-30h]
  _DWORD *v66; // [esp+1Ch] [ebp-30h]
  int v67; // [esp+20h] [ebp-2Ch]
  int v68; // [esp+20h] [ebp-2Ch]
  int v69; // [esp+24h] [ebp-28h]
  int v70; // [esp+28h] [ebp-24h]
  int v71; // [esp+2Ch] [ebp-20h]
  int v72; // [esp+2Ch] [ebp-20h]
  int v73; // [esp+30h] [ebp-1Ch]
  int v74; // [esp+30h] [ebp-1Ch]
  int v75; // [esp+30h] [ebp-1Ch]
  unsigned int v76; // [esp+30h] [ebp-1Ch]
  int v77; // [esp+30h] [ebp-1Ch]
  double *v78; // [esp+30h] [ebp-1Ch]
  _DWORD *v79; // [esp+34h] [ebp-18h]
  unsigned int v80; // [esp+34h] [ebp-18h]
  unsigned int i; // [esp+38h] [ebp-14h]
  int v82; // [esp+38h] [ebp-14h]
  unsigned int v83; // [esp+38h] [ebp-14h]
  unsigned int v84; // [esp+38h] [ebp-14h]
  unsigned int v85; // [esp+38h] [ebp-14h]
  unsigned int v86; // [esp+38h] [ebp-14h]
  unsigned int v87; // [esp+38h] [ebp-14h]
  unsigned int v88; // [esp+3Ch] [ebp-10h]
  unsigned int j; // [esp+3Ch] [ebp-10h]
  unsigned int v90; // [esp+40h] [ebp-Ch]
  unsigned int v91; // [esp+40h] [ebp-Ch]
  int v92; // [esp+40h] [ebp-Ch]
  unsigned int v93; // [esp+44h] [ebp-8h]
  int v94; // [esp+44h] [ebp-8h]
  int v95; // [esp+44h] [ebp-8h]
  int v96; // [esp+48h] [ebp-4h]

  v1 = this;
  sub_686074((int)this);
  v67 = -1;
  v62 = -1;
  v2 = 0;
  v96 = 0;
  for ( i = 0; i < v1[3]; ++i )
  {
    v3 = *(int **)(v1[6] + 4 * i);
    v4 = *v3;
    if ( (*v3 & 0xFFF00000) != 0 && (v4 & 0xF0000000) >= 0x10000000 && (v4 & 0xF0000000) <= 0x40000000 )
    {
      v93 = 0;
      v58 = v3[1] / (v4 & 0xFFFFFu);
      if ( v58 )
      {
        do
        {
          v5 = v3[3];
          v73 = 0;
          v88 = 0;
          if ( v5 )
          {
            do
            {
              v6 = *(_DWORD *)(v3[2] + 4 * (v88 + v93 * v5));
              v7 = v1[5];
              v8 = *(_DWORD *)(v7 + 4 * *(_DWORD *)(v3[4] + 4 * v88));
              v71 = v6;
              v69 = v8;
              if ( (**(_BYTE **)(v7 + 4 * v6) & 1) != 0 )
              {
                v9 = *(_DWORD *)(v8 + 20);
                v70 = *(_DWORD *)(v8 + 24);
                while ( v9 != -1 )
                {
                  v90 = 0;
                  v10 = 4 * v9;
                  v11 = *(_DWORD **)(v1[6] + 4 * *(_DWORD *)(*(_DWORD *)(v1[5] + 4 * v9) + 72));
                  if ( v11[3] )
                  {
                    v79 = (_DWORD *)v11[4];
                    do
                    {
                      if ( *v79 == v9 )
                        break;
                      ++v90;
                      ++v79;
                    }
                    while ( v90 < v11[3] );
                  }
                  v12 = v11[2];
                  if ( v70 )
                  {
                    if ( sub_683158(v1, v71, *(_DWORD *)(v12 + 4 * v90)) )
                    {
                      *(_DWORD *)(v69 + 64) = 1;
LABEL_21:
                      ++v73;
                      break;
                    }
                  }
                  else if ( sub_683158(v1, *(_DWORD *)(v12 + 4 * v90), v71) )
                  {
                    *(_DWORD *)(v69 + 64) = 0;
                    goto LABEL_21;
                  }
                  v13 = *(_DWORD *)(v10 + v1[5]);
                  v70 = *(_DWORD *)(v13 + 24);
                  v9 = *(_DWORD *)(v13 + 20);
                }
              }
              ++v88;
              v5 = v3[3];
            }
            while ( v88 < v5 );
            v2 = 0;
          }
          v14 = v3[3];
          if ( v73 == v14 )
          {
            if ( v14 )
            {
              do
              {
                v15 = v1[5];
                v16 = *(_DWORD *)(v15 + 4 * *(_DWORD *)(v3[2] + 4 * (v2 + v93 * v14)));
                v49 = *(_DWORD *)(*(_DWORD *)(v15 + 4 * *(_DWORD *)(v3[4] + 4 * v2)) + 64) == 0;
                v17 = *(_DWORD *)(v1[4] + 4 * *(_DWORD *)(v16 + 4));
                if ( v49 )
                {
                  if ( (*(_BYTE *)(v17 + 5) & 1) != 0 && 0.0 == *(double *)(v16 + 32) )
                    goto LABEL_36;
                  v18 = v62;
                  if ( v62 == -1 )
                  {
                    v18 = sub_681AAA(v1, v1[30], 0, 0, 0.0);
                    v62 = v18;
                  }
                }
                else
                {
                  if ( (*(_BYTE *)(v17 + 5) & 1) != 0 && 1.0 == *(double *)(v16 + 32) )
                    goto LABEL_36;
                  v18 = v67;
                  if ( v67 == -1 )
                  {
                    v18 = sub_681AAA(v1, v1[30], 0, 0, 1.0);
                    v67 = v18;
                  }
                }
                *(_DWORD *)(v3[2] + 4 * (v2 + v93 * v3[3])) = v18;
                v96 = 1;
LABEL_36:
                v14 = v3[3];
                ++v2;
              }
              while ( v2 < v14 );
            }
            v2 = 0;
          }
          ++v93;
        }
        while ( v93 < v58 );
      }
    }
  }
  v72 = 0;
  sub_686606(v1);
  v80 = 0;
  if ( !v1[3] )
    return v96 == 0;
  do
  {
    v19 = *(int **)(v1[6] + 4 * v80);
    if ( (*((_WORD *)v19 + 1) & 0xFFF0) == 0 )
      goto LABEL_123;
    for ( j = 0; j < v19[3]; *(_DWORD *)(v21 + 24) = v82 )
    {
      v20 = v1[5];
      v21 = *(_DWORD *)(v20 + 4 * *(_DWORD *)(v19[4] + 4 * j));
      v22 = *(_DWORD *)(v21 + 20);
      v82 = *(_DWORD *)(v21 + 24);
      while ( v22 != -1 )
      {
        v23 = *(_DWORD *)(v20 + 4 * v22);
        if ( *(char *)v23 >= 0 )
          break;
        if ( v82 )
        {
          if ( 0.0 == *(double *)(v23 + 32) )
          {
LABEL_47:
            v82 = 0;
            v22 = -1;
            goto LABEL_48;
          }
        }
        else if ( 0.0 != *(double *)(v23 + 32) )
        {
          goto LABEL_47;
        }
        v32 = *(_DWORD *)(4 * v22 + v1[5]);
        v33 = *(_DWORD *)(v32 + 24);
        v22 = *(_DWORD *)(v32 + 20);
        v82 = v33;
LABEL_48:
        v96 = 1;
      }
      ++j;
      *(_DWORD *)(v21 + 20) = v22;
    }
    v24 = *v19;
    v25 = *v19 & 0xFFF00000;
    if ( v25 != 284164096 && v25 != 289406976 )
    {
      if ( v25 != 544210944 && v25 != 545259520 )
      {
        if ( (v24 & 0xF0000000) < 0x10000000 || (v24 & 0xF0000000) > 0x40000000 )
        {
          if ( v19[3] )
          {
            v75 = 0;
            v34 = (_DWORD *)v19[4];
            v35 = v19[3];
            do
            {
              v36 = *(_DWORD *)(v1[5] + 4 * *v34);
              if ( *(_DWORD *)(v36 + 20) != -1 || *(_DWORD *)(v36 + 24) )
                ++v75;
              ++v34;
              --v35;
            }
            while ( v35 );
            if ( !v75 )
            {
              v37 = 0;
              v19[1] = 0;
              v19[3] = 0;
              goto LABEL_121;
            }
          }
          goto LABEL_123;
        }
        v26 = v19[1] / (v24 & 0xFFFFFu);
        v94 = 0;
        v91 = 0;
        for ( k = v26; v91 < v19[3]; ++v91 )
        {
          v27 = v19[4];
          v28 = *(_DWORD *)(v27 + 4 * v91);
          v29 = *(_DWORD *)(v1[5] + 4 * v28);
          if ( *(_DWORD *)(v29 + 20) != -1 || *(_DWORD *)(v29 + 24) )
          {
            v83 = 0;
            *(_DWORD *)(v27 + 4 * v94) = v28;
            if ( v26 )
            {
              do
              {
                v30 = v83 * v19[3];
                ++v83;
                *(_DWORD *)(v19[2] + 4 * (v94 + v30)) = *(_DWORD *)(v19[2] + 4 * (v30 + v91));
                v26 = k;
              }
              while ( v83 < k );
            }
            ++v94;
          }
        }
        if ( v94 == v19[3] )
          goto LABEL_123;
        v84 = 0;
        if ( v26 )
        {
          v74 = 0;
          v63 = 4 * v94;
          do
          {
            qmemcpy((void *)(v19[2] + v74), (const void *)(v19[2] + 4 * v84 * v19[3]), v63);
            ++v84;
            v74 += v63;
          }
          while ( v84 < v26 );
        }
        if ( v94 )
          v31 = *v19 ^ (v94 ^ *v19) & 0xFFFFF;
        else
          v31 = 0;
        v1 = this;
        *v19 = v31;
        v19[3] = v94;
        v19[1] = v94 * v26;
LABEL_122:
        v96 = 1;
        goto LABEL_123;
      }
      v92 = 0;
      v95 = 0;
      v76 = v19[1] / (v24 & 0xFFFFFu);
      if ( !v19[3] )
      {
LABEL_96:
        if ( v92 == v19[3] )
          goto LABEL_123;
        v45 = v76;
        v86 = 0;
        if ( v76 )
        {
          v77 = 0;
          v65 = 4 * v92;
          do
          {
            v46 = v19[2];
            v47 = (void *)(v46 + v77);
            v77 += v65;
            qmemcpy(v47, (const void *)(v46 + 4 * v86 * v19[3]), v65);
            ++v86;
          }
          while ( v86 < v45 );
        }
        if ( v92 )
          v37 = *v19 ^ (v92 ^ *v19) & 0xFFFFF;
        else
          v37 = 0;
        v1 = this;
        v19[3] = v92;
        v19[1] = v92 * v45;
LABEL_121:
        *v19 = v37;
        goto LABEL_122;
      }
      while ( 1 )
      {
        v38 = v1[5];
        v60 = *(_DWORD *)(4 * v95 + v19[4]);
        v39 = *(_DWORD **)(v38 + 4 * v60);
        if ( v39[5] != -1 || v39[6] )
        {
          v40 = v19[2];
          v64 = *(_DWORD *)(4 * v95 + v40);
          v41 = *(_DWORD *)(v40 + 4 * (v95 + v19[3]));
          v42 = *(_DWORD **)(v38 + 4 * v64);
          if ( v42[5] != -1 || v42[6] )
          {
            v43 = *(_DWORD *)(v38 + 4 * v41);
            if ( *(_DWORD *)(v43 + 20) != -1 || *(_DWORD *)(v43 + 24) )
            {
              v85 = 0;
              for ( *(_DWORD *)(v19[4] + 4 * v92) = v60;
                    v85 < v76;
                    *(_DWORD *)(v19[2] + 4 * (v92 + v44)) = *(_DWORD *)(v19[2] + 4 * (v44 + v95)) )
              {
                v44 = v85 * v19[3];
                ++v85;
              }
              ++v92;
              goto LABEL_95;
            }
            v42[1] = v1[34];
            v39[12] = v64;
          }
          else
          {
            *(_DWORD *)(*(_DWORD *)(v38 + 4 * v41) + 4) = v1[34];
            v39[12] = v41;
          }
          v72 = 1;
        }
LABEL_95:
        if ( ++v95 >= (unsigned int)v19[3] )
          goto LABEL_96;
      }
    }
    v48 = 0;
    v49 = v19[3] == 0;
    v68 = 0;
    v87 = 0;
    if ( !v19[3] )
      goto LABEL_119;
    do
    {
      v50 = v1[5];
      v51 = 4 * v87;
      v78 = *(double **)(v50 + 4 * *(_DWORD *)(4 * v87 + v19[4]));
      v52 = *(int **)(v50 + 4 * *(_DWORD *)(4 * v87 + v19[2]));
      v66 = v52;
      if ( (*(_BYTE *)(*(_DWORD *)(v1[4] + 4 * v52[1]) + 5) & 1) != 0 && v52[2] == -1 )
      {
        v53 = v78;
        *(_BYTE *)v78 |= 0x80u;
        if ( 0.0 != *((double *)v52 + 4) )
        {
          v54 = 1.0;
LABEL_110:
          v53[4] = v54;
          goto LABEL_115;
        }
LABEL_109:
        v54 = 0.0;
        goto LABEL_110;
      }
      v55 = *v52;
      if ( (*v66 & 4) != 0 && (v55 & 8) != 0 )
      {
        v53 = v78;
        *(_BYTE *)v78 |= 0x80u;
        goto LABEL_109;
      }
      v53 = v78;
      *(_BYTE *)v78 &= ~0x80u;
LABEL_115:
      if ( *(char *)v53 >= 0 )
      {
        v56 = 4 * v48;
        *(_DWORD *)(v56 + v19[4]) = *(_DWORD *)(v51 + v19[4]);
        *(_DWORD *)(v56 + v19[2]) = *(_DWORD *)(v51 + v19[2]);
        v48 = ++v68;
      }
      ++v87;
    }
    while ( v87 < v19[3] );
    v49 = v48 == v19[3];
LABEL_119:
    if ( !v49 )
    {
      v37 = v48 != 0 ? v48 & 0xFFFFF | 0x10F00000 : 0;
      v19[1] = v48;
      v19[3] = v48;
      goto LABEL_121;
    }
LABEL_123:
    ++v80;
  }
  while ( v80 < v1[3] );
  if ( v72 )
    sub_68661F(v1);
  return v96 == 0;
}
