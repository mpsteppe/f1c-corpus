int __thiscall sub_6B26DB(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // eax
  unsigned int v3; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // eax
  unsigned int v13; // edx
  _DWORD *v14; // edi
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  _DWORD *v19; // edx
  int v20; // eax
  unsigned int v21; // edx
  _DWORD *v22; // edi
  int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ecx
  unsigned int v26; // eax
  _DWORD *v27; // edx
  int v28; // eax
  unsigned int v29; // edx
  BOOL v30; // ecx
  _DWORD *v31; // eax
  _DWORD *v32; // eax
  int *v33; // eax
  int v34; // edx
  unsigned int v35; // edx
  int v36; // eax
  int v37; // edx
  unsigned int v38; // esi
  _DWORD *v39; // eax
  _DWORD *v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  int v44; // edx
  _DWORD *v45; // eax
  int v46; // edi
  int v47; // ecx
  unsigned int v48; // esi
  int v49; // edi
  _DWORD *v50; // eax
  char *v51; // esi
  int v52; // eax
  int v53; // edi
  unsigned int v54; // ecx
  int v55; // eax
  int v56; // edx
  int v57; // edx
  unsigned int v58; // edi
  int v59; // eax
  int v60; // ecx
  unsigned int v61; // eax
  int v62; // eax
  int v63; // ecx
  int v64; // edi
  int v65; // ecx
  int v66; // eax
  unsigned int *v67; // edx
  unsigned int v68; // ebx
  unsigned int j; // ecx
  int v70; // eax
  _DWORD *v71; // ecx
  _DWORD *v72; // eax
  _DWORD *v73; // ecx
  _DWORD *v74; // eax
  int v75; // edx
  int v76; // edi
  void *v77; // ecx
  _DWORD v78[4]; // [esp+4h] [ebp-60h]
  _DWORD v79[4]; // [esp+14h] [ebp-50h] BYREF
  unsigned int v80; // [esp+24h] [ebp-40h]
  unsigned int v81; // [esp+28h] [ebp-3Ch]
  unsigned int v82; // [esp+2Ch] [ebp-38h]
  unsigned int v83; // [esp+30h] [ebp-34h]
  unsigned int v84; // [esp+34h] [ebp-30h]
  unsigned int i; // [esp+38h] [ebp-2Ch]
  _DWORD *v86; // [esp+3Ch] [ebp-28h]
  _DWORD *v87; // [esp+40h] [ebp-24h]
  _DWORD *v88; // [esp+44h] [ebp-20h]
  unsigned int v89; // [esp+48h] [ebp-1Ch]
  _DWORD *v90; // [esp+4Ch] [ebp-18h]
  int v91; // [esp+50h] [ebp-14h]
  unsigned int v92; // [esp+54h] [ebp-10h]
  int v93; // [esp+58h] [ebp-Ch]
  int v94; // [esp+5Ch] [ebp-8h]
  unsigned int v95; // [esp+60h] [ebp-4h]

  v1 = this;
  v2 = (_DWORD *)this[64];
  v3 = *v2 & 0xFFFFF;
  v88 = v1;
  v92 = v3;
  if ( !v3 )
    return 1;
  v5 = v2[1] / v3;
  v81 = 0;
  v80 = v5;
  if ( !v5 )
    return 1;
  v84 = 0;
  while ( 1 )
  {
    v6 = -1;
    memset(v79, 255, sizeof(v79));
    v95 = 0;
    v89 = 0;
    v90 = 0;
    v87 = 0;
    v86 = 0;
    v93 = -1;
    v94 = -1;
    if ( v92 )
    {
      i = v84 + *(_DWORD *)(v1[64] + 8);
      v82 = v92;
      while ( 1 )
      {
        v7 = *(_DWORD *)i;
        v8 = *(_DWORD *)(v1[5] + 4 * *(_DWORD *)i);
        v9 = *(_DWORD *)(v8 + 16);
        if ( !v9 )
          break;
        v10 = v9 - 1;
        if ( !v10 )
        {
          if ( *(_DWORD *)(v8 + 72) == -1 || v90 )
            goto LABEL_39;
          v28 = *(_DWORD *)(v8 + 72);
          v90 = *(_DWORD **)(v1[6] + 4 * v28);
          goto LABEL_37;
        }
        v11 = v10 - 1;
        if ( v11 )
        {
          if ( v11 != 1 || v94 != -1 )
            goto LABEL_39;
          v12 = *(_DWORD *)(v8 + 72);
          v13 = v95;
          v79[v13] = -1;
          v94 = v7;
          v78[v13] = v7;
          if ( v12 != -1 )
          {
            v14 = *(_DWORD **)(v1[6] + 4 * v12);
            v15 = *v14;
            v16 = *v14 & 0xFFF00000;
            v86 = v14;
            if ( v16 == 0x10000000 )
            {
              v17 = 0;
              v18 = v15 & 0xFFFFF;
              if ( v18 )
              {
                v19 = (_DWORD *)v14[4];
                while ( *v19 != v94 )
                {
                  ++v17;
                  ++v19;
                  if ( v17 >= v18 )
                    goto LABEL_18;
                }
                v94 = *(_DWORD *)(v14[2] + 4 * v17);
LABEL_18:
                v6 = v93;
              }
            }
            else
            {
              v86 = 0;
            }
          }
          goto LABEL_38;
        }
        if ( v6 == -1 )
        {
          v20 = *(_DWORD *)(v8 + 72);
          v21 = v95;
          v79[v21] = -1;
          v6 = v7;
          v93 = v7;
          v78[v21] = v7;
          if ( v20 != -1 )
          {
            v22 = *(_DWORD **)(v1[6] + 4 * v20);
            v23 = *v22;
            v24 = *v22 & 0xFFF00000;
            v87 = v22;
            if ( v24 == 0x10000000 )
            {
              v25 = 0;
              v26 = v23 & 0xFFFFF;
              if ( v26 )
              {
                v27 = (_DWORD *)v22[4];
                while ( *v27 != v6 )
                {
                  ++v25;
                  ++v27;
                  if ( v25 >= v26 )
                    goto LABEL_38;
                }
                v6 = *(_DWORD *)(v22[2] + 4 * v25);
                v93 = v6;
              }
            }
            else
            {
              v87 = 0;
            }
          }
          goto LABEL_38;
        }
LABEL_39:
        i += 4;
        if ( !--v82 )
          goto LABEL_40;
      }
      if ( *(_DWORD *)(v8 + 72) == -1 || v89 )
        goto LABEL_39;
      v28 = *(_DWORD *)(v8 + 72);
      v89 = *(_DWORD *)(v1[6] + 4 * v28);
LABEL_37:
      v29 = v95;
      v79[v29] = v28;
      v78[v29] = v7;
LABEL_38:
      ++v95;
      goto LABEL_39;
    }
LABEL_40:
    if ( v95 != v92 || v95 <= 1 )
      goto LABEL_96;
    v30 = 0;
    if ( v90 )
    {
      if ( *v90 != 542113793 )
        goto LABEL_56;
      if ( v6 != -1 )
      {
        v31 = (_DWORD *)v90[2];
        if ( v6 != *v31 )
          v30 = v6 != v31[1];
      }
      if ( v94 != -1 )
      {
        v32 = (_DWORD *)v90[2];
        if ( v94 != *v32 && v94 != v32[1] )
          v30 = 1;
        if ( v6 != -1 )
        {
          v33 = (int *)v90[2];
          v34 = *v33;
          if ( v94 == v6 )
          {
            if ( v34 == v33[1] )
              goto LABEL_57;
          }
          else if ( v34 != v33[1] )
          {
            goto LABEL_57;
          }
LABEL_56:
          v30 = 1;
        }
      }
    }
LABEL_57:
    v35 = 0;
    if ( !v89 )
      goto LABEL_62;
    if ( *(_DWORD *)v89 == 268435457 )
      break;
LABEL_96:
    ++v81;
    v84 += 4 * v92;
    if ( v81 >= v80 )
      return 1;
  }
  v36 = *(_DWORD *)(v1[5] + 4 * **(_DWORD **)(v89 + 8));
  if ( (*(_BYTE *)(*(_DWORD *)(v1[4] + 4 * *(_DWORD *)(v36 + 4)) + 5) & 1) == 0 || *(double *)(v36 + 32) != 1.0 )
    v30 = 1;
LABEL_62:
  if ( v30 )
    goto LABEL_96;
  v82 = 0;
  while ( 1 )
  {
    v83 = v79[v35];
    if ( v83 != -1 )
    {
      v91 = 1;
      v89 = v92;
      if ( v92 )
      {
        v37 = v1[5];
        v38 = v1[63];
        v39 = (_DWORD *)(v84 + *(_DWORD *)(v1[64] + 8));
        i = v92;
        do
        {
          v40 = *(_DWORD **)(v37 + 4 * *v39);
          if ( v40[20] < v38 )
            v91 = 0;
          if ( v40[19] > v83 )
            v91 = 0;
          if ( (v87 || v40[4] != 2) && (v86 || v40[4] != 3) )
          {
            if ( v40[21] < v83 )
              v91 = 0;
          }
          else
          {
            --v89;
          }
          ++v39;
          --i;
        }
        while ( i );
        v35 = v82;
      }
      for ( i = 0; i < v95; ++i )
      {
        v41 = v79[i];
        if ( v41 != -1 )
        {
          v42 = *(_DWORD *)(v1[6] + 4 * v41);
          v43 = *(_DWORD *)(v42 + 4);
          if ( v43 )
          {
            v44 = v1[5];
            v45 = *(_DWORD **)(v42 + 8);
            v46 = v43;
            do
            {
              v47 = *(_DWORD *)(v44 + 4 * *v45);
              v48 = *(_DWORD *)(v47 + 72);
              if ( v48 > v83 && v48 != -1 || *(_DWORD *)(v47 + 80) < v83 )
                v91 = 0;
              ++v45;
              --v46;
            }
            while ( v46 );
            v35 = v82;
            v1 = v88;
          }
        }
      }
      if ( v91 )
        break;
    }
    v82 = ++v35;
    if ( v35 >= v95 )
      goto LABEL_96;
  }
  v82 = v79[v35];
  if ( v82 == -1 )
    goto LABEL_96;
  v49 = v89;
  if ( v89 < 2 )
    goto LABEL_96;
  v50 = (_DWORD *)sub_681186(116);
  if ( v50 )
    v51 = (char *)sub_680CEC(v50);
  else
    v51 = 0;
  if ( !v51 )
    return -2147024882;
  v52 = sub_6811D1(v51, v49 & 0xFFFFF | 0x70900000, 2 * v49, v49, 0);
  if ( v52 < 0 || (v52 = sub_680D22(v51, v1[64]), v52 < 0) )
  {
    v53 = v52;
    goto LABEL_142;
  }
  v54 = 0;
  if ( v49 )
  {
    v55 = 4 * v49;
    do
    {
      if ( v90 )
      {
        *(_DWORD *)(*((_DWORD *)v51 + 2) + 4 * v54) = *(_DWORD *)v90[2];
        v56 = *(_DWORD *)(v90[2] + 4);
      }
      else
      {
        v56 = v94;
        if ( v94 == -1 )
        {
          v56 = v93;
          if ( v93 == -1 )
            goto LABEL_112;
        }
        else if ( v93 != -1 )
        {
LABEL_112:
          sub_686791((int)v1, *(_DWORD *)(v1[64] + 60), 4825, "internal error: DST test failure");
          goto LABEL_113;
        }
        *(_DWORD *)(*((_DWORD *)v51 + 2) + 4 * v54) = v56;
      }
      *(_DWORD *)(v55 + *((_DWORD *)v51 + 2)) = v56;
      ++v54;
      v55 += 4;
    }
    while ( v54 < v89 );
  }
  v57 = 0;
  v58 = 0;
  if ( v95 )
  {
    while ( 1 )
    {
      v59 = v78[v57];
      v60 = *(_DWORD *)(v1[5] + 4 * v59);
      if ( (v87 || *(_DWORD *)(v60 + 16) != 2) && (v86 || *(_DWORD *)(v60 + 16) != 3) )
        *(_DWORD *)(*((_DWORD *)v51 + 4) + 4 * v58++) = v59;
      if ( v58 > v89 )
        break;
      v1 = v88;
      if ( ++v57 >= v95 )
        goto LABEL_125;
    }
    sub_686791((int)v88, *(_DWORD *)(v88[64] + 60), 4826, "internal error: DST test failure");
LABEL_113:
    v53 = 1;
LABEL_142:
    sub_66238F(v51, 1);
    return v53;
  }
  else
  {
LABEL_125:
    v61 = *((_DWORD *)v51 + 3);
    v92 = 0;
    if ( v61 )
    {
      v81 = 1;
      while ( 1 )
      {
        v84 = v81;
        if ( v81 < v61 )
          break;
LABEL_132:
        ++v92;
        v61 = *((_DWORD *)v51 + 3);
        ++v81;
        if ( v92 >= v61 )
          goto LABEL_133;
      }
      while ( 1 )
      {
        v62 = *((_DWORD *)v51 + 4);
        v63 = v1[5];
        v64 = *(_DWORD *)(v63 + 4 * *(_DWORD *)(v62 + 4 * v92));
        v65 = *(_DWORD *)(v63 + 4 * *(_DWORD *)(4 * v84 + v62));
        if ( *(_DWORD *)(v64 + 16) > *(_DWORD *)(v65 + 16) )
        {
          v66 = *((_DWORD *)v51 + 4);
          v67 = (unsigned int *)(v66 + 4 * v84);
          v80 = *v67;
          v68 = v92;
          *v67 = *(_DWORD *)(v66 + 4 * v92);
          *(_DWORD *)(*((_DWORD *)v51 + 4) + 4 * v68) = v80;
          v1 = v88;
        }
        if ( *(_DWORD *)(v64 + 16) == *(_DWORD *)(v65 + 16) )
          break;
        if ( ++v84 >= *((_DWORD *)v51 + 3) )
          goto LABEL_132;
      }
      sub_686791((int)v1, *(_DWORD *)(v1[64] + 60), 4827, "internal error: multiple write to same output");
      v53 = -2147467259;
      goto LABEL_142;
    }
LABEL_133:
    for ( j = 0; j < v95; ++j )
    {
      v70 = v79[j];
      if ( v70 != -1 )
        **(_DWORD **)(v1[6] + 4 * v70) = 0;
    }
    v71 = v87;
    if ( v87 )
    {
      if ( *v87 == 268435457 )
      {
        *v87 = 0;
      }
      else if ( *v87 == 268435458 )
      {
        v72 = (_DWORD *)v87[2];
        if ( *v72 == v93 && v72[1] == v94 )
          *v87 = 0;
        if ( v72[1] == v93 && *v72 == v94 )
          *v71 = 0;
      }
    }
    v73 = v86;
    if ( v86 )
    {
      if ( *v86 == 268435457 )
        goto LABEL_158;
      if ( *v86 == 268435458 )
      {
        v74 = (_DWORD *)v86[2];
        v75 = v93;
        if ( *v74 == v93 && v74[1] == v94 )
          *v86 = 0;
        if ( v74[1] == v75 && *v74 == v94 )
LABEL_158:
          *v73 = 0;
      }
    }
    v76 = 4 * v82;
    v77 = *(void **)(4 * v82 + v1[6]);
    if ( v77 )
      sub_66238F(v77, 1);
    *(_DWORD *)(v76 + v1[6]) = v51;
    return 0;
  }
}
