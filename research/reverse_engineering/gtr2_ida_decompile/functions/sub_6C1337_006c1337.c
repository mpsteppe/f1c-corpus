int __thiscall sub_6C1337(int this)
{
  int *v2; // edi
  int v3; // ebx
  unsigned int v4; // eax
  _DWORD *v6; // eax
  int *v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edi
  int v14; // ecx
  unsigned int v15; // ebx
  unsigned int *v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // edi
  int v19; // eax
  int v20; // eax
  _DWORD *v21; // ebx
  int v22; // ecx
  int v23; // eax
  int v24; // edx
  bool v25; // zf
  int v26; // eax
  int v27; // eax
  unsigned int v28; // ebx
  int v29; // ecx
  int v30; // eax
  int *v31; // eax
  int v32; // edi
  _DWORD *i; // edi
  int v34; // ecx
  int v35; // eax
  int v36; // edi
  _DWORD *v37; // eax
  int v38; // ecx
  _DWORD *v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  bool v42; // cc
  unsigned int v43; // ebx
  int v44; // ecx
  int v45; // edi
  int v46; // edx
  int v47; // ecx
  int *v48; // ecx
  int v49; // eax
  _DWORD *v50; // ebx
  int v51; // eax
  int v52; // eax
  int v53; // edi
  int v54; // edi
  int v55; // eax
  int v56; // ecx
  int v57; // edi
  int v58; // ebx
  _DWORD *v59; // eax
  int v60; // ebx
  int v61; // ebx
  int *v62; // ecx
  unsigned int v63; // edi
  int v64; // eax
  int v65; // ecx
  unsigned int k; // ecx
  int v67; // eax
  _DWORD v68[40]; // [esp+14h] [ebp-214h] BYREF
  _DWORD v69[40]; // [esp+B4h] [ebp-174h] BYREF
  char v70[64]; // [esp+154h] [ebp-D4h] BYREF
  char v71[64]; // [esp+194h] [ebp-94h] BYREF
  int v72[4]; // [esp+1D4h] [ebp-54h] BYREF
  int v73[4]; // [esp+1E4h] [ebp-44h] BYREF
  unsigned int v74; // [esp+1F4h] [ebp-34h]
  unsigned int *v75; // [esp+1F8h] [ebp-30h]
  int *v76; // [esp+1FCh] [ebp-2Ch]
  int v77; // [esp+200h] [ebp-28h]
  unsigned int v78; // [esp+204h] [ebp-24h]
  unsigned int v79; // [esp+208h] [ebp-20h]
  unsigned int v80; // [esp+20Ch] [ebp-1Ch]
  unsigned int v81; // [esp+210h] [ebp-18h]
  unsigned int v82; // [esp+214h] [ebp-14h]
  unsigned int v83; // [esp+218h] [ebp-10h] BYREF
  int j; // [esp+21Ch] [ebp-Ch]
  int v85; // [esp+220h] [ebp-8h]
  unsigned int v86; // [esp+224h] [ebp-4h] BYREF

  memset(&v73[1], 255, 12);
  memset(&v72[1], 255, 12);
  v2 = 0;
  v3 = **(_DWORD **)(this + 256) & 0xFFFFF;
  v4 = **(_DWORD **)(this + 256) & 0xFFF00000;
  v73[0] = 0;
  v72[0] = 0;
  v74 = v3;
  if ( v4 != 546308096 )
    return 1;
  v6 = (_DWORD *)sub_681186(116);
  if ( v6 )
    v2 = sub_680CEC(v6);
  v76 = v2;
  if ( !v2 )
    return -2147024882;
  v85 = sub_681430((char *)v2, *(_DWORD **)(this + 256));
  if ( v85 < 0 )
  {
LABEL_101:
    v62 = v2;
LABEL_114:
    sub_66238F(v62, 1);
    return v85;
  }
  v79 = 0;
  v2[3] = 1;
  v2[1] = 2;
  *v2 = 546308097;
  if ( !v3 )
    goto LABEL_113;
  v77 = 4 * v74;
  while ( 1 )
  {
    v7 = v76;
    v8 = 4 * v79;
    *(_DWORD *)v76[4] = *(_DWORD *)(4 * v79 + *(_DWORD *)(*(_DWORD *)(this + 256) + 16));
    *(_DWORD *)v7[2] = *(_DWORD *)(v8 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8));
    *(_DWORD *)(v7[2] + 4) = *(_DWORD *)(v77 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8));
    memset(v69, 0xFFu, sizeof(v69));
    v86 = 0;
    v82 = 0;
    v78 = 0;
    j = 0;
    v85 = sub_6BB35B((_DWORD *)this, v7, dword_7468F0, v71, &v86, (int)v69, v73, 1u, 1);
    if ( v85 )
    {
      v86 = 0;
      v85 = sub_6BB35B((_DWORD *)this, v7, dword_746A50, v71, &v86, (int)v69, v73, 1u, 1);
      if ( v85 )
      {
        v86 = 0;
        v85 = sub_6BB35B((_DWORD *)this, v7, dword_746BF0, v71, &v86, (int)v69, v73, 1u, 1);
        if ( v85 )
        {
          v86 = 0;
          v85 = sub_6BB35B((_DWORD *)this, v7, dword_746D90, v71, &v86, (int)v69, v73, 1u, 1);
          if ( !v85 )
            j = 1;
        }
        else
        {
          v78 = 1;
        }
      }
      else
      {
        v82 = 1;
      }
    }
    if ( v69[4] != v69[8] )
      goto LABEL_63;
    if ( v85 )
      goto LABEL_63;
    v9 = *(_DWORD *)(this + 20);
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * **(_DWORD **)(*(_DWORD *)v71 + 16)) + 20);
    if ( v10 == -1 )
      goto LABEL_63;
    v11 = *(_DWORD *)(this + 24);
    v12 = *(_DWORD *)(v11 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * v10) + 72));
    v86 = 0;
    if ( *(_DWORD *)v12 != 286261249 )
      goto LABEL_63;
    v13 = **(_DWORD **)(v12 + 16);
    v14 = *(_DWORD *)(v9 + 4 * v13);
    v15 = *(_DWORD *)(v14 + 84);
    v81 = *(_DWORD *)(v14 + 88);
    if ( v15 > v81 )
      goto LABEL_63;
    v16 = (unsigned int *)(v11 + 4 * v15);
    v75 = v16;
    do
    {
      v17 = *v16;
      if ( *(_DWORD *)(*(_DWORD *)(v9 + 4 * **(_DWORD **)(v17 + 16)) + 20) == v13 && *(_DWORD *)v17 == 1953497089 )
      {
        if ( v86 )
        {
          sub_686791(this, 0, 4835, "internal error: multiple breaks found");
          return -2147467259;
        }
        v86 = v17;
      }
      ++v15;
      v16 = ++v75;
    }
    while ( v15 <= v81 );
    v18 = v86;
    if ( v86 )
    {
      v83 = 0;
      if ( j )
      {
        v19 = sub_6BB35B((_DWORD *)this, v76, dword_746EB0, v70, &v83, (int)v68, v73, 1u, 1);
      }
      else if ( v78 )
      {
        v19 = sub_6BB35B((_DWORD *)this, v76, dword_746CF0, v70, &v83, (int)v68, v73, 1u, 1);
      }
      else if ( v82 )
      {
        v19 = sub_6BB35B((_DWORD *)this, v76, dword_746B50, v70, &v83, (int)v68, v73, 1u, 1);
      }
      else
      {
        v19 = sub_6BB35B((_DWORD *)this, v76, dword_7469D0, v70, &v83, (int)v68, v72, 1u, 1);
      }
      v85 = v19;
      v20 = v69[0];
      if ( v68[0] == v69[0] )
        v20 = v68[4];
      if ( v20 != -1 )
      {
        v21 = *(_DWORD **)(v18 + 8);
        if ( *v21 == v20 )
        {
          v22 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v18 + 16)) + 20);
          if ( v22 != -1 )
          {
            v23 = *(_DWORD *)(this + 20);
            v24 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(*(_DWORD *)(v23 + 4 * v22) + 72));
            v25 = *(_DWORD *)v24 == 286261249;
            v26 = *(_DWORD *)(v23 + 4 * **(_DWORD **)(v24 + 8));
            v75 = (unsigned int *)v24;
            if ( v25
              && (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v26 + 4)) + 5) & 1) != 0
              && *(double *)(v26 + 32) == (double)*(unsigned int *)(this + 104) )
            {
              v27 = *(_DWORD *)(this + 20);
              v28 = *(_DWORD *)(v27 + 4 * v21[1]);
              v83 = *(_DWORD *)(v27 + 4 * v69[0]);
              v29 = *(_DWORD *)(v27 + 4 * v69[4]);
              v30 = *(_DWORD *)(v29 + 72);
              v81 = v28;
              j = v69[4];
              if ( v30 != -1 )
              {
                while ( 2 )
                {
                  if ( *(_DWORD *)(v29 + 8) == -1 )
                  {
                    v31 = *(int **)(*(_DWORD *)(this + 24) + 4 * v30);
                    if ( (*v31 & 0xFFF00000) == 0x10000000 )
                    {
                      v32 = *v31;
                      v80 = 0;
                      v82 = v32 & 0xFFFFF;
                      if ( (v32 & 0xFFFFF) != 0 )
                      {
                        for ( i = (_DWORD *)v31[4]; *i != j; i = (_DWORD *)v78 )
                        {
                          ++v80;
                          v78 = (unsigned int)(i + 1);
                          if ( v80 >= v82 )
                            goto LABEL_54;
                        }
                        v34 = *(_DWORD *)(v31[2] + 4 * v80);
                        v35 = *(_DWORD *)(this + 20);
                        j = v34;
                        v29 = *(_DWORD *)(v35 + 4 * v34);
                        v30 = *(_DWORD *)(v29 + 72);
                        if ( v30 != -1 )
                        {
                          v28 = v81;
                          continue;
                        }
LABEL_54:
                        v28 = v81;
                      }
                    }
                  }
                  break;
                }
              }
              v36 = *(_DWORD *)(this + 16);
              if ( (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v83 + 4)) + 5) & 1) != 0
                && (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v29 + 4)) + 5) & 1) != 0
                && *(double *)(v83 + 32) == 1.0
                && *(double *)(v29 + 32) == 0.0
                && (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v28 + 4)) + 5) & 2) != 0
                && (*(_BYTE *)v28 & 2) != 0
                && !*(_DWORD *)(v28 + 16)
                && *(_DWORD *)(v28 + 8) == -1 )
              {
                break;
              }
            }
          }
        }
      }
    }
LABEL_63:
    ++v79;
    v77 += 4;
    if ( v79 >= v74 )
      goto LABEL_113;
  }
  v37 = (_DWORD *)v86;
  v38 = *(_DWORD *)(*(_DWORD *)(v86 + 8) + 4);
  v39 = *(_DWORD **)(v24 + 8);
  v82 = -1;
  *v39 = v38;
  *v37 = 0;
  v40 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v24 + 16));
  v41 = *(_DWORD *)(v40 + 84);
  v42 = v41 <= *(_DWORD *)(v40 + 88);
  v83 = v40;
  v81 = v41;
  if ( !v42 )
    goto LABEL_103;
  while ( 1 )
  {
    v43 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v41);
    v25 = *(_DWORD *)(v43 + 12) == 0;
    v80 = v43;
    if ( !v25
      && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v43 + 16)) + 20) == **(_DWORD **)(v86 + 16) )
    {
      v77 = 0;
      if ( *(_DWORD *)(v43 + 4) )
      {
        while ( 1 )
        {
          v44 = *(_DWORD *)(this + 20);
          v45 = *(_DWORD *)(v44 + 4 * *(_DWORD *)(*(_DWORD *)(v43 + 8) + 4 * v77));
          v46 = *(_DWORD *)(v45 + 8);
          j = -1;
          if ( v46 == -1 )
            goto LABEL_83;
          v47 = *(_DWORD *)(*(_DWORD *)(v44 + 4 * v46) + 72);
          if ( v47 != -1 )
            break;
LABEL_88:
          if ( (unsigned int)++v77 >= *(_DWORD *)(v43 + 4) )
            goto LABEL_89;
        }
        v48 = *(int **)(*(_DWORD *)(this + 24) + 4 * v47);
        v49 = *v48;
        if ( (*v48 & 0xFFF00000) == 0x10000000 )
        {
          v79 = 0;
          v78 = v49 & 0xFFFFF;
          if ( (v49 & 0xFFFFF) != 0 )
          {
            v50 = (_DWORD *)v48[4];
            while ( *v50 != v46 )
            {
              ++v79;
              ++v50;
              if ( v79 >= v78 )
                goto LABEL_82;
            }
            j = *(_DWORD *)(v48[2] + 4 * v79);
          }
        }
        else
        {
          j = v46;
        }
LABEL_82:
        v43 = v80;
LABEL_83:
        if ( j == **(_DWORD **)(v86 + 8) )
        {
          v51 = v82;
          if ( v82 == -1 )
          {
            v52 = sub_681A51((void *)this, (int)&unk_7474F8, 21, -1, 4);
            v51 = sub_681AAA((void *)this, v52, 0, 0, 0.0);
            v82 = v51;
            *(_DWORD *)(v45 + 8) = v51;
          }
          *(_DWORD *)(v45 + 8) = v51;
          v53 = *(_DWORD *)(v45 + 56);
          if ( v53 != -1 )
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v53) + 8) = v51;
        }
        goto LABEL_88;
      }
    }
LABEL_89:
    if ( ++v81 > *(_DWORD *)(v83 + 88) )
      break;
    v41 = v81;
  }
  if ( v82 == -1 )
    goto LABEL_103;
  v54 = sub_681AAA((void *)this, 0, 0, 0, 0.0);
  v55 = sub_681AAA((void *)this, 0, 0, 0, 0.0);
  if ( v54 == -1 || v55 == -1 )
    return -2147024882;
  v56 = *(_DWORD *)(this + 20);
  v57 = *(_DWORD *)(v56 + 4 * v54);
  v58 = *(_DWORD *)(v56 + 4 * v55);
  v74 = *(_DWORD *)(v56 + 4 * *(_DWORD *)v75[2]);
  sub_6815D6((double *)v57, v74);
  sub_6815D6((double *)v58, v74);
  *(_DWORD *)(v57 + 16) = 1;
  *(_DWORD *)(v58 + 16) = 2;
  v59 = (_DWORD *)sub_681186(116);
  v2 = v59 ? sub_680CEC(v59) : 0;
  if ( !v2 )
    return -2147024882;
  v60 = sub_6811D1((char *)v2, 1947205633, 3, 1, 0);
  if ( v60 < 0 )
  {
    sub_66238F(v2, 1);
    return v60;
  }
  v61 = (int)v75;
  v85 = sub_680D22(v2, (int)v75);
  if ( v85 < 0 )
    goto LABEL_101;
  *(_DWORD *)v2[4] = **(_DWORD **)(v61 + 16);
  *(_DWORD *)v2[2] = **(_DWORD **)(v61 + 8);
  *(_DWORD *)(v2[2] + 4) = **(_DWORD **)(v61 + 8);
  *(_DWORD *)(v2[2] + 8) = **(_DWORD **)(v61 + 8);
  v85 = sub_681430((char *)v61, v2);
  sub_66238F(v2, 1);
  if ( v85 >= 0 )
  {
LABEL_103:
    v63 = *(_DWORD *)(v83 + 84);
    v42 = v63 <= *(_DWORD *)(v83 + 88);
    for ( j = v63; v42; j = v63 )
    {
      v64 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v63);
      if ( (*(_DWORD *)v64 & 0xFFF00000) == 0x20800000 )
      {
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v64 + 8)) + 20) == **(_DWORD **)(v86 + 16) )
        {
          v65 = *(_DWORD *)v64 & 0xFFFFF;
          *(_DWORD *)v64 = v65 | 0x10000000;
          *(_DWORD *)(v64 + 12) = v65;
          *(_DWORD *)(v64 + 4) = v65;
        }
        v63 = j;
      }
      v42 = ++v63 <= *(_DWORD *)(v83 + 88);
    }
    for ( k = 0; k < *(_DWORD *)(this + 8); ++k )
    {
      v67 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * k);
      if ( *(_DWORD *)(v67 + 20) == **(_DWORD **)(v86 + 16) )
        *(_DWORD *)(v67 + 20) = *(_DWORD *)v75[4];
    }
LABEL_113:
    v62 = v76;
    goto LABEL_114;
  }
  return v85;
}
