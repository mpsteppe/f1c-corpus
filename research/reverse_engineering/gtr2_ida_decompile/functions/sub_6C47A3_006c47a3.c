int __thiscall sub_6C47A3(
        int *this,
        __int64 a2,
        unsigned int *a3,
        int a4,
        int a5,
        int *a6,
        unsigned int a7,
        char *a8,
        int a9,
        int a10,
        int a11)
{
  unsigned int v11; // eax
  bool v12; // cf
  int *v13; // edi
  int v14; // esi
  int v15; // ebx
  unsigned int v16; // ecx
  int v17; // eax
  bool v18; // zf
  _DWORD *v19; // edx
  int v20; // eax
  int v21; // ecx
  char *v22; // eax
  int result; // eax
  char *v24; // eax
  unsigned int v25; // eax
  _DWORD *v26; // eax
  char *v27; // edi
  char *v28; // ecx
  int v29; // ebx
  unsigned int v30; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // ecx
  int v34; // eax
  _DWORD *v35; // eax
  char *v36; // eax
  _DWORD *v37; // eax
  _DWORD *v38; // eax
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  int v42; // eax
  _DWORD *v43; // ecx
  _DWORD *v44; // eax
  int v45; // ecx
  int v46; // edx
  int v47; // ecx
  int v48; // edx
  _DWORD *v49; // eax
  int v50; // eax
  char *v51; // esi
  unsigned int v52; // eax
  char *v53; // edi
  char v54; // dl
  unsigned int v55; // ecx
  char *v56; // edi
  char *v57; // esi
  char v58; // cl
  char *v59; // edi
  char *v60; // esi
  char v61; // al
  unsigned int v62; // ecx
  int v63; // eax
  int v64; // ecx
  int v65; // eax
  _DWORD *v66; // ecx
  int v67; // esi
  int v68; // eax
  char *v69; // ecx
  int v70; // eax
  int v71; // ecx
  char *v72; // ecx
  int v73; // esi
  char *v74; // [esp+4h] [ebp-848h]
  char *v75; // [esp+4h] [ebp-848h]
  _BYTE v76[512]; // [esp+14h] [ebp-838h] BYREF
  _DWORD v77[128]; // [esp+214h] [ebp-638h] BYREF
  _BYTE v78[512]; // [esp+414h] [ebp-438h] BYREF
  _DWORD v79[128]; // [esp+614h] [ebp-238h] BYREF
  unsigned int v80; // [esp+814h] [ebp-38h] BYREF
  unsigned int v81; // [esp+818h] [ebp-34h] BYREF
  _DWORD *v82; // [esp+81Ch] [ebp-30h]
  int v83; // [esp+820h] [ebp-2Ch] BYREF
  int v84; // [esp+824h] [ebp-28h] BYREF
  int *v85; // [esp+828h] [ebp-24h]
  unsigned int v86; // [esp+82Ch] [ebp-20h]
  int v87; // [esp+830h] [ebp-1Ch]
  int v88; // [esp+834h] [ebp-18h] BYREF
  int v89; // [esp+838h] [ebp-14h]
  unsigned int v90; // [esp+83Ch] [ebp-10h]
  unsigned int v91; // [esp+840h] [ebp-Ch]
  unsigned int v92; // [esp+844h] [ebp-8h]
  char *v93; // [esp+848h] [ebp-4h]

  v11 = *a3;
  v12 = *a3 < a7;
  v13 = this;
  v85 = this;
  v92 = v11;
  if ( !v12 )
    return 0;
  v14 = 0;
  while ( 1 )
  {
    v15 = *(_DWORD *)(v13[6] + 4 * v11);
    v16 = *(_DWORD *)v15 & 0xFFF00000;
    v17 = *(_DWORD *)v15 & 0xFFFFF;
    v18 = *(_DWORD *)(v15 + 12) == 0;
    v89 = v16;
    v90 = v17;
    if ( v18 )
    {
      sub_686791((int)v13, *(_DWORD *)(v15 + 60), 4831, "internal error: instruction missing outputs");
      return -2147467259;
    }
    v19 = *(_DWORD **)(v13[5] + 4 * **(_DWORD **)(v15 + 16));
    v20 = v19[5];
    v91 = (unsigned int)v19;
    if ( v20 != (_DWORD)a2 )
      break;
    if ( a9 && v16 != 287309824 )
      goto LABEL_51;
    v93 = a8;
    if ( a8 && v19[6] != HIDWORD(a2) )
      v93 = 0;
    if ( sub_6C424F(v16) )
    {
      if ( v90 != 1 )
      {
        v74 = "internal error: IF with size greater then 1 found";
LABEL_132:
        sub_686791((int)v13, *(_DWORD *)(v15 + 60), 4832, v74);
        return -2147467259;
      }
      if ( v93 )
      {
        v22 = sub_6C42BB(v13, v15, 1);
        if ( !v22 )
          return -2147024882;
        result = sub_681997((int)v13, v22);
        if ( result < 0 )
          return result;
      }
      v83 = ++v92;
      v81 = 0;
      v88 = 0;
      result = sub_6C47A3(**(_DWORD **)(v15 + 16), 1, &v83, v78, v79, &v88, a7, v93, 0, 0, 0);
      if ( result < 0 )
        return result;
      if ( v93 )
      {
        v24 = sub_6C42BB(v13, v15, 0);
        if ( !v24 )
          return -2147024882;
        result = sub_681997((int)v13, v24);
        if ( result < 0 )
          return result;
      }
      v83 = v92;
      result = sub_6C47A3(**(_DWORD **)(v15 + 16), 0, &v83, v76, v77, &v81, a7, v93, 0, 0, 0);
      if ( result < 0 )
        return result;
      if ( v93 )
      {
        v89 = 1;
        if ( v88 != v81 )
          goto LABEL_125;
        v25 = 0;
        if ( v81 )
        {
          do
          {
            if ( v77[v25] != v79[v25] )
              v89 = 0;
            ++v25;
          }
          while ( v25 < v81 );
          if ( !v89 )
          {
LABEL_125:
            v75 = "internal error: endif mismatch";
            goto LABEL_126;
          }
        }
        v26 = (_DWORD *)sub_681186(116);
        if ( v26 )
          v27 = (char *)sub_680CEC(v26);
        else
          v27 = 0;
        v89 = (int)v27;
        if ( !v27 )
          return -2147024882;
        v93 = (char *)sub_6811D1(v27, v81 & 0xFFFFF | 0x73400000, 2 * v81, v81, 0);
        v28 = v27;
        if ( (int)v93 < 0 )
          goto LABEL_128;
        v29 = sub_680D22(v27, v15);
        if ( v29 < 0 )
        {
          v72 = v27;
LABEL_130:
          sub_66238F(v72, 1);
          return v29;
        }
        qmemcpy(*((void **)v27 + 4), v77, 4 * v88);
        qmemcpy(*((void **)v27 + 2), v78, 4 * v88);
        qmemcpy((void *)(4 * v88 + *((_DWORD *)v27 + 2)), v76, 4 * v88);
        result = sub_681997((int)v85, v27);
        if ( result < 0 )
          return result;
        v13 = v85;
        v14 = 0;
      }
      *(_DWORD *)(v91 + 4) = v13[29];
      v30 = v83;
    }
    else if ( sub_6C4285(v21) )
    {
      v80 = v92 + 1;
      v88 = 0;
      if ( v93 )
      {
        result = sub_681C03(v13, (_DWORD *)v15);
        if ( result < 0 )
          return result;
        *(_DWORD *)(v91 + 4) = v13[29];
      }
      result = sub_6C47A3(**(_DWORD **)(v15 + 16), 1, &v80, v78, v79, &v88, a7, v93, 0, 0, 0);
      if ( result < 0 )
        return result;
      v30 = v80;
    }
    else
    {
      if ( v32 != 286261248 && v32 != 1947205632 )
      {
        if ( v32 == 287309824 )
        {
          if ( v93 && a9 )
          {
            v33 = 0;
            if ( v90 )
            {
              do
              {
                v34 = *(_DWORD *)(v13[5] + 4 * *(_DWORD *)(*(_DWORD *)(v15 + 16) + 4 * v33));
                *(_DWORD *)(v34 + 52) = a11;
                v12 = ++v33 < v90;
                *(_DWORD *)(v34 + 48) = a10;
              }
              while ( v12 );
            }
            goto LABEL_50;
          }
        }
        else if ( a8 && *(_DWORD *)(v31 + 24) == HIDWORD(a2) )
        {
LABEL_50:
          result = sub_681C03(v13, (_DWORD *)v15);
          if ( result < 0 )
            return result;
        }
LABEL_51:
        ++v92;
        goto LABEL_121;
      }
      v84 = ++v92;
      v88 = 0;
      result = sub_6C47A3(**(_DWORD **)(v15 + 16), 1, &v84, v78, v79, &v88, a7, v93, 1, a2, HIDWORD(a2));
      if ( result < 0 )
        return result;
      if ( v93 )
      {
        if ( v89 == 286261248 )
        {
          v87 = v90 & 0xFFFFF;
          *(_DWORD *)v15 = v90 & 0xFFFFF | 0x74200000;
          result = sub_681C03(v13, (_DWORD *)v15);
          if ( result < 0 )
            return result;
          *(_DWORD *)v15 = v87 | 0x11100000;
        }
        else
        {
          result = sub_681C03(v13, (_DWORD *)v15);
          if ( result < 0 )
            return result;
        }
        *(_DWORD *)(v91 + 4) = v13[29];
      }
      v84 = v92;
      result = sub_6C47A3(**(_DWORD **)(v15 + 16), 1, &v84, v78, v79, &v88, a7, v93, 0, 0, 0);
      if ( result < 0 )
        return result;
      if ( v93 )
      {
        v87 = sub_681AAA(v13, v13[42], 0, 0, 0.0);
        if ( v87 == -1 )
          return -2147024882;
        v35 = (_DWORD *)sub_681186(116);
        v91 = v35 ? (unsigned int)sub_680CEC(v35) : 0;
        if ( !v91 )
          return -2147024882;
        if ( v89 == 286261248 )
          v36 = (char *)sub_6811D1((char *)v91, 1957691393, 0, 1, 0);
        else
          v36 = (char *)sub_6811D1((char *)v91, 1956642817, 0, 1, 0);
        v28 = (char *)v91;
        v93 = v36;
        if ( (int)v36 < 0 )
        {
LABEL_128:
          sub_66238F(v28, 1);
          return (int)v93;
        }
        v29 = sub_680D22((_DWORD *)v91, v15);
        if ( v29 < 0 )
        {
          v72 = (char *)v91;
          goto LABEL_130;
        }
        v37 = (_DWORD *)v91;
        **(_DWORD **)(v91 + 16) = v87;
        result = sub_681997((int)v13, v37);
        if ( result < 0 )
          return result;
      }
      v30 = v84;
    }
    v92 = v30;
LABEL_121:
    v11 = v92;
    if ( v92 >= a7 )
      return 0;
  }
  if ( v16 != 544210944 )
    goto LABEL_142;
  if ( a9 )
    goto LABEL_51;
  v38 = *(_DWORD **)(v15 + 8);
  v39 = v13[5];
  v89 = *(_DWORD *)(v39 + 4 * *v38);
  v40 = *(_DWORD *)(v39 + 4 * v38[v90]);
  v41 = *(_DWORD *)(v89 + 20);
  if ( v41 != *(_DWORD *)(v40 + 20) )
  {
    v74 = "internal error: if block with non matching predicates found";
    goto LABEL_132;
  }
  if ( !a4 || !a5 || !a6 )
  {
    v75 = "internal error: unexpected endif found";
LABEL_126:
    sub_686791((int)v13, *(_DWORD *)(v15 + 60), 4833, v75);
    return -2147467259;
  }
  if ( v41 != (_DWORD)a2 )
  {
LABEL_142:
    *a3 = v92;
    return 0;
  }
  if ( !a8 )
    goto LABEL_51;
  v18 = *(_DWORD *)(v89 + 24) == HIDWORD(a2);
  v87 = 1;
  v86 = 0;
  if ( !v18 )
    v86 = v90;
  if ( v90 )
  {
    v91 = *(_DWORD *)(v15 + 16);
    v93 = (char *)&v38[v86];
    v82 = (_DWORD *)v90;
    do
    {
      v42 = v13[5];
      v43 = *(_DWORD **)(v42 + 4 * *(_DWORD *)v91);
      v44 = *(_DWORD **)(v42 + 4 * *(_DWORD *)v93);
      if ( v43[3] != v44[3] || v43[4] != v44[4] || v43[2] != v44[2] || v43[1] != v44[1] || v43[15] != v44[15] )
        v87 = 0;
      v91 += 4;
      v93 += 4;
      v82 = (_DWORD *)((char *)v82 - 1);
    }
    while ( v82 );
  }
  if ( v90 + *a6 >= 0x80 )
  {
    sub_686791((int)v13, *(_DWORD *)(v15 + 60), 4500, "Conditional block too complex");
    return -2147467259;
  }
  if ( v87 )
  {
    if ( v90 )
    {
      v86 *= 4;
      do
      {
        v45 = *(_DWORD *)(v86 + *(_DWORD *)(v15 + 8));
        v46 = *a6;
        v86 += 4;
        *(_DWORD *)(a4 + 4 * (v14 + v46)) = v45;
        v47 = *(_DWORD *)(*(_DWORD *)(v15 + 16) + 4 * v14);
        v48 = v14 + *a6;
        v12 = ++v14 < v90;
        *(_DWORD *)(a5 + 4 * v48) = v47;
      }
      while ( v12 );
    }
LABEL_120:
    *a6 += v90;
    ++v92;
    v13 = v85;
    v14 = 0;
    goto LABEL_121;
  }
  v49 = (_DWORD *)sub_681186(116);
  if ( v49 )
    v93 = (char *)sub_680CEC(v49);
  else
    v93 = 0;
  if ( !v93 )
    return -2147024882;
  v50 = sub_6811D1(v93, v90 & 0xFFFFF | 0x10000000, v90, v90, 0);
  if ( v50 < 0 || (v50 = sub_680D22(v93, v15), v50 < 0) || (v50 = sub_681997((int)v13, v93), v50 < 0) )
  {
    v73 = v50;
LABEL_137:
    sub_66238F(v93, 1);
    return v73;
  }
  v51 = *(char **)(v15 + 8);
  if ( *(_DWORD *)(v89 + 24) == HIDWORD(a2) )
  {
    v52 = v90;
    v53 = (char *)*((_DWORD *)v93 + 2);
    v54 = 4 * v90;
    v55 = (4 * v90) >> 2;
    qmemcpy(v53, v51, 4 * v55);
    v57 = &v51[4 * v55];
    v56 = &v53[4 * v55];
    v58 = v54;
  }
  else
  {
    v59 = (char *)*((_DWORD *)v93 + 2);
    v60 = &v51[4 * v90];
    v61 = 4 * v90;
    v62 = (4 * v90) >> 2;
    qmemcpy(v59, v60, 4 * v62);
    v57 = &v60[4 * v62];
    v56 = &v59[4 * v62];
    v58 = v61;
    v52 = v90;
  }
  v91 = 0;
  qmemcpy(v56, v57, v58 & 3);
  if ( !v52 )
    goto LABEL_120;
  v89 = 4 * v52;
  while ( 1 )
  {
    v63 = sub_681AAA(v85, v85[34], 0, 0, 0.0);
    *(_DWORD *)(a4 + 4 * (v91 + *a6)) = v63;
    v64 = *(_DWORD *)(a4 + 4 * (v91 + *a6));
    if ( v64 == -1 )
    {
      v73 = -2147024882;
      goto LABEL_137;
    }
    v65 = v85[5];
    v66 = *(_DWORD **)(v65 + 4 * v64);
    v67 = 4 * v91;
    v87 = *(_DWORD *)(v65 + 4 * *(_DWORD *)(4 * v91 + *(_DWORD *)(v15 + 16)));
    v82 = v66;
    if ( sub_6815D6((double *)v66, v87) < 0 )
      break;
    v68 = sub_681692(v82, (_DWORD *)v87);
    v69 = v93;
    if ( v68 < 0 )
      goto LABEL_139;
    *(_DWORD *)(v67 + *((_DWORD *)v93 + 4)) = *(_DWORD *)(a4 + 4 * (v91 + *a6));
    *(_DWORD *)(a5 + 4 * (v91 + *a6)) = *(_DWORD *)(v67 + *(_DWORD *)(v15 + 16));
    v70 = *(_DWORD *)(v15 + 8);
    v71 = *(_DWORD *)(v70 + v67);
    if ( *(_DWORD *)(*(_DWORD *)(v85[5] + 4 * v71) + 24) == HIDWORD(a2) )
      *(_DWORD *)(v67 + *((_DWORD *)v93 + 2)) = v71;
    else
      *(_DWORD *)(v67 + *((_DWORD *)v93 + 2)) = *(_DWORD *)(v70 + v89);
    ++v91;
    v89 += 4;
    if ( v91 >= v90 )
      goto LABEL_120;
  }
  v69 = v93;
LABEL_139:
  sub_66238F(v69, 1);
  return -2147024882;
}
