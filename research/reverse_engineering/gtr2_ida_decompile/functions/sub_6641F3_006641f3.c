int __thiscall sub_6641F3(_DWORD *this, unsigned int a2, int a3, int a4, _DWORD *a5, __int64 a6)
{
  int v6; // edx
  unsigned int v8; // eax
  _DWORD *v9; // esi
  int v10; // edi
  int result; // eax
  unsigned int v12; // eax
  int v13; // esi
  char *v14; // ecx
  unsigned int j; // eax
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // edi
  int v20; // eax
  int v21; // edi
  int v22; // esi
  unsigned int v23; // eax
  int v24; // ebx
  bool v25; // cf
  unsigned int *v26; // ebx
  int v27; // eax
  void *v28; // edi
  int v29; // edx
  _DWORD *v30; // esi
  unsigned int k; // edx
  unsigned int v32; // eax
  int v33; // ecx
  int v34; // eax
  int v35; // edi
  unsigned int v36; // eax
  int v37; // ecx
  _DWORD *v38; // eax
  unsigned int v39; // eax
  int v40; // ecx
  int *v41; // ecx
  int v42; // edx
  unsigned int m; // edi
  unsigned int v44; // edi
  bool v45; // zf
  int v46; // eax
  int v47; // edi
  unsigned int v48; // eax
  int v49; // eax
  unsigned int v50; // eax
  unsigned int v51; // edx
  int v52; // eax
  _DWORD *v53; // ecx
  unsigned int v54; // eax
  int v55; // ecx
  int v56; // edx
  int v57; // eax
  int v58; // edx
  int v59; // ecx
  _DWORD *v60; // edi
  unsigned int v61; // edi
  int v62; // eax
  int v63; // eax
  int v64; // eax
  int v65; // eax
  void *v66; // [esp+14h] [ebp-20h]
  void *v67; // [esp+18h] [ebp-1Ch]
  _DWORD *v68; // [esp+1Ch] [ebp-18h]
  int v69; // [esp+20h] [ebp-14h]
  double v70; // [esp+24h] [ebp-10h] BYREF
  void *Block; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]
  unsigned int v73; // [esp+40h] [ebp+Ch]
  char *v74; // [esp+40h] [ebp+Ch]
  unsigned int v75; // [esp+40h] [ebp+Ch]
  _DWORD *v76; // [esp+48h] [ebp+14h]
  _DWORD *v77; // [esp+48h] [ebp+14h]
  _DWORD *v78; // [esp+48h] [ebp+14h]
  unsigned int n; // [esp+48h] [ebp+14h]
  _DWORD *v80; // [esp+48h] [ebp+14h]
  __int64 v81; // [esp+4Ch] [ebp+18h]
  unsigned int kk; // [esp+50h] [ebp+1Ch]
  unsigned int jj; // [esp+50h] [ebp+1Ch]
  unsigned int ii; // [esp+50h] [ebp+1Ch]
  _DWORD *v85; // [esp+50h] [ebp+1Ch]
  unsigned int mm; // [esp+50h] [ebp+1Ch]

  v6 = a3;
  Block = this;
  if ( (a3 & 0xFFF00000) == 0x20500000 && (a6 & 0x400000000LL) != 0 )
  {
    v8 = a3 & 0xFFFFF;
    v73 = 0;
    if ( (v6 & 0xFFFFF) != 0 )
    {
      v9 = a5;
      v10 = a6 - (_DWORD)a5;
      for ( i = a6 - (_DWORD)a5; *v9 == *(_DWORD *)((char *)v9 + v10); v10 = i )
      {
        if ( (**(_BYTE **)(*(_DWORD *)(this[2] + 20) + 4 * *v9) & 1) == 0 )
          break;
        ++v73;
        ++v9;
        if ( v73 >= v8 )
          break;
      }
    }
    if ( v73 == v8 )
      v6 = v6 & 0xFFFFF | 0x10000000;
  }
  if ( v6 == 1342177281 )
  {
    result = sub_6641F3(a2, 542113793, a4, a5, a6, HIDWORD(a6));
    goto LABEL_18;
  }
  if ( v6 != 1342177282 || (*(_BYTE *)(this[2] + 108) & 0x20) != 0 )
  {
    if ( *(char *)(this[2] + 108) < 0 )
    {
      v12 = v6 & 0xFFF00000;
      HIDWORD(v70) = v6 & 0xFFF00000;
      if ( (v6 & 0xFFF00000) == 0x20000000 || v12 == 537919488 || v12 == 538968064 || v12 == 540016640 )
      {
        v13 = v6 & 0xFFFFF;
        v14 = (char *)operator new(16 * (v6 & 0xFFFFF));
        Block = v14;
        if ( v14 )
        {
          for ( j = 0; j < 4; ++j )
          {
            *(&v66 + j) = v14;
            v14 += 4 * v13;
          }
          if ( !v13 )
          {
LABEL_40:
            v20 = sub_6624CC(v66, v13);
            if ( v20 < 0
              || (v20 = sub_6624CC(v67, v13), v20 < 0)
              || (v21 = v13 & 0xFFFFF,
                  v20 = sub_6641F3(a2, v13 & 0xFFFFF | 0x10100000, v66, a6, 0, BYTE4(a6) & 0x40),
                  v20 < 0)
              || (v20 = sub_6641F3(a2, v21 | 0x20400000, v67, a5, v66, BYTE4(a6) & 0x40), v20 < 0)
              || (v20 = sub_6641F3(a2, v21 | 0x30000000, a4, v67, (char *)Block + 8 * v13, HIDWORD(a6)), v20 < 0) )
            {
              v22 = v20;
            }
            else
            {
              v22 = 0;
            }
            j__free(Block);
            return v22;
          }
          v16 = v68;
          v74 = (char *)((char *)a5 - (char *)v68);
          v17 = a6 - (_DWORD)v68;
          v18 = v69 - (_DWORD)v68;
          i = v13;
          while ( 1 )
          {
            if ( HIDWORD(v70) == 0x20000000 )
            {
              *v16 = *(_DWORD *)((char *)v16 + v17);
              v19 = *(_DWORD *)((char *)v16 + (_DWORD)v74);
              goto LABEL_38;
            }
            if ( HIDWORD(v70) == 537919488 )
            {
              *v16 = *(_DWORD *)((char *)v16 + (_DWORD)v74);
              v19 = *(_DWORD *)((char *)v16 + v17);
              goto LABEL_38;
            }
            if ( HIDWORD(v70) == 538968064 )
              break;
            if ( HIDWORD(v70) == 540016640 )
            {
              *v16 = this[8];
              v19 = this[9];
LABEL_38:
              *(_DWORD *)((char *)v16 + v18) = v19;
            }
            ++v16;
            if ( !--i )
              goto LABEL_40;
          }
          *v16 = this[9];
          v19 = this[8];
          goto LABEL_38;
        }
        return -2147024882;
      }
    }
    v23 = sub_681B0A(v6, -1, -1);
    v24 = this[2];
    v25 = v23 < *(_DWORD *)(v24 + 12);
    i = v23;
    if ( v25 )
      v26 = *(unsigned int **)(*(_DWORD *)(v24 + 24) + 4 * v23);
    else
      v26 = 0;
    if ( !v26 )
      return -2147024882;
    if ( !v26[3] && !v26[1] )
    {
      *v26 = 0;
      return 0;
    }
    v75 = sub_6814E4(0, 0);
    v27 = sub_680D41(0, 0);
    v28 = (void *)v26[2];
    v29 = v26[1] - v27;
    HIDWORD(v70) = 4 * v27;
    qmemcpy(v28, a5, 4 * ((unsigned int)(4 * v27) >> 2));
    qmemcpy((void *)(4 * v27 + v26[2]), (const void *)a6, 4 * v29);
    v30 = Block;
    for ( k = 0; k < v26[1]; ++k )
    {
      v32 = *(_DWORD *)(v26[2] + 4 * k);
      v33 = v30[2];
      if ( v32 >= *(_DWORD *)(v33 + 8) )
        v34 = 0;
      else
        v34 = *(_DWORD *)(*(_DWORD *)(v33 + 20) + 4 * v32);
      if ( v34 )
        ++*(_DWORD *)(v34 + 92);
    }
    v35 = 0;
    LODWORD(a6) = 0;
    if ( v75 )
    {
      while ( 1 )
      {
        v76 = 0;
        if ( a4 )
        {
          v36 = *(_DWORD *)(a4 + 4 * v35);
          if ( v36 != -1 )
          {
            v37 = v30[2];
            v38 = v36 >= *(_DWORD *)(v37 + 8) ? 0 : *(_DWORD **)(*(_DWORD *)(v37 + 20) + 4 * v36);
            v76 = v38;
            if ( !v38 )
              break;
          }
        }
        v39 = sub_681AAA(*(_DWORD *)(v30[2] + 136), 0, 0, 0.0);
        HIDWORD(v70) = v39;
        if ( v39 == -1 )
          return -2147024882;
        v40 = v30[2];
        v41 = v39 >= *(_DWORD *)(v40 + 8) ? 0 : *(int **)(*(_DWORD *)(v40 + 20) + 4 * v39);
        if ( !v41 )
          return -2147024882;
        *v41 = HIDWORD(a6);
        v41[18] = i;
        v41[4] = v35;
        if ( (a6 & 0xE00000000000000LL) == 0 )
        {
          v35 = a6;
          *v41 = HIDWORD(a6) | v30[25];
        }
        v41[5] = v30[12];
        v41[6] = v30[13];
        v42 = 4 * v35;
        *(_DWORD *)(4 * v35 + v26[4]) = v39;
        if ( a4 )
          *(_DWORD *)(v42 + a4) = v39;
        if ( v76 )
        {
          v41[12] = v76[12];
          v41[24] = v76[24];
          v41[25] = v76[25];
        }
        if ( v41[12] != -1 )
        {
          *(_DWORD *)(v30[6] + 4 * v41[12]) = *(_DWORD *)(v42 + v26[4]);
          if ( !v41[24] )
            sub_663C07(v30, 0, 0, "internal error: argument missing context (A%u)", HIDWORD(v70));
        }
        v35 = a6 + 1;
        LODWORD(a6) = a6 + 1;
        if ( (unsigned int)a6 >= v75 )
          goto LABEL_84;
      }
      sub_663C07(v30, 0, 0, "internal error: result register invalid");
      return -2147467259;
    }
LABEL_84:
    for ( m = 0; m < v75; ++m )
      sub_662830((int)v30, *(_DWORD *)(v26[4] + 4 * m), 0);
    if ( (v30[5] & 4) == 0 && !sub_680F76(v26) )
    {
      v44 = 0;
      v45 = v75 == 0;
      if ( v75 )
      {
        do
        {
          v46 = *(_DWORD *)(v26[4] + 4 * v44);
          if ( (**(_BYTE **)(*(_DWORD *)(v30[2] + 20) + 4 * v46) & 0x40) != 0 )
            break;
          if ( sub_6640D2(v30, v46, &v70) < 0 )
            break;
          ++v44;
        }
        while ( v44 < v75 );
        v45 = v44 == v75;
      }
      if ( v45 )
      {
        *v26 = v75 & 0xFFFFF | 0x10000000;
        v47 = 0;
        v26[1] = v26[3];
        if ( v75 )
        {
          do
          {
            *(_DWORD *)(v26[2] + 4 * v47) = sub_681AAA(
                                              *(_DWORD *)(v30[2] + 120),
                                              0,
                                              0,
                                              *(double *)(*(_DWORD *)(*(_DWORD *)(v30[2] + 20)
                                                                    + 4 * *(_DWORD *)(v26[4] + 4 * v47))
                                                        + 32));
            if ( *(_DWORD *)(v26[2] + 4 * v47) == -1 )
              return -2147024882;
          }
          while ( ++v47 < v75 );
        }
      }
    }
    v48 = *v26 & 0xFFF00000;
    if ( v48 > 0x20500000 )
    {
      if ( v48 != 544210944 && v48 != 545259520 )
      {
        if ( v48 == 805306368 )
        {
          v61 = 0;
          for ( n = 0; v61 < v75; n = v61 )
          {
            v62 = *(_DWORD *)(v30[2] + 20);
            v85 = *(_DWORD **)(v62 + 4 * *(_DWORD *)(v26[4] + 4 * v61));
            v63 = **(_DWORD **)(v62 + 4 * *(_DWORD *)(v26[2] + 4 * (v26[3] + v61)))
                & **(_DWORD **)(v62 + 4 * *(_DWORD *)(v26[2] + 4 * (n + 2 * v26[3])));
            if ( (v63 & 1) != 0 )
            {
              *v85 |= 0x17u;
            }
            else if ( (v63 & 2) != 0 )
            {
              *v85 |= 2u;
            }
            v61 = n + 1;
          }
        }
        else if ( v48 == 1342177280 )
        {
          v81 = *(unsigned int *)(*(_DWORD *)(v30[2] + 20) + 4 * *(_DWORD *)v26[4]);
          if ( v75 )
          {
            v78 = (_DWORD *)v26[2];
            v60 = &v78[v26[3]];
            do
            {
              if ( (**(_BYTE **)(*(_DWORD *)(v30[2] + 20) + 4 * *v60)
                  & **(_BYTE **)(*(_DWORD *)(v30[2] + 20) + 4 * *v78)
                  & 2) == 0 )
                break;
              ++HIDWORD(v81);
              ++v78;
              ++v60;
            }
            while ( HIDWORD(v81) < v75 );
          }
          if ( HIDWORD(v81) == v75 )
            *(_DWORD *)v81 |= 2u;
        }
        goto LABEL_138;
      }
    }
    else if ( v48 != 542113792 )
    {
      if ( v48 == 0x10000000 )
      {
        v54 = 0;
        for ( ii = 0; ii < v75; ++ii )
        {
          v55 = *(_DWORD *)(v30[2] + 20);
          v56 = 4 * v54;
          v57 = *(_DWORD *)(v55 + 4 * *(_DWORD *)(4 * v54 + v26[4]));
          v58 = *(_DWORD *)(v56 + v26[2]);
          v59 = *(_DWORD *)(v55 + 4 * v58);
          *(_DWORD *)(v57 + 52) = v58;
          *(_DWORD *)v57 |= *(_DWORD *)v59;
          *(double *)(v57 + 32) = *(double *)(v59 + 32);
          *(double *)(v57 + 40) = *(double *)(v59 + 40);
          v54 = ii + 1;
        }
        goto LABEL_138;
      }
      if ( v48 == 269484032 )
      {
        v50 = 0;
        for ( jj = 0; jj < v75; ++jj )
        {
          v51 = v50;
          v52 = *(_DWORD *)(v30[2] + 20);
          v51 *= 4;
          v53 = *(_DWORD **)(v52 + 4 * *(_DWORD *)(v51 + v26[4]));
          *v53 |= **(_DWORD **)(v52 + 4 * *(_DWORD *)(v51 + v26[2])) & 2;
          v50 = jj + 1;
        }
        goto LABEL_138;
      }
      if ( v48 != 0x20000000 && v48 != 537919488 )
      {
        if ( v48 == 541065216 )
        {
          for ( kk = 0; kk < v75; ++kk )
          {
            v49 = *(_DWORD *)(v30[2] + 20);
            v77 = *(_DWORD **)(v49 + 4 * *(_DWORD *)(4 * kk + v26[4]));
            *v77 |= **(_DWORD **)(v49 + 4 * *(_DWORD *)(4 * kk + v26[2]))
                  & **(_DWORD **)(v49 + 4 * *(_DWORD *)(v26[2] + 4 * (kk + v26[3])))
                  & 2;
          }
        }
LABEL_138:
        v26[15] = a2;
        v26[14] = v30[14];
        return 0;
      }
    }
    for ( mm = 0; mm < v75; ++mm )
    {
      v64 = *(_DWORD *)(v30[2] + 20);
      v80 = *(_DWORD **)(v64 + 4 * *(_DWORD *)(4 * mm + v26[4]));
      v65 = **(_DWORD **)(v64 + 4 * *(_DWORD *)(4 * mm + v26[2]))
          & **(_DWORD **)(v64 + 4 * *(_DWORD *)(v26[2] + 4 * (mm + v26[3])));
      if ( (v65 & 1) != 0 )
      {
        *v80 |= 0x17u;
      }
      else if ( (v65 & 2) != 0 )
      {
        *v80 |= 2u;
      }
    }
    goto LABEL_138;
  }
  v70 = NAN;
  result = sub_6641F3(a2, 542113793, &v70, a5, a6, BYTE4(a6) & 0x40);
  if ( result >= 0 )
  {
    result = sub_6641F3(a2, 542113793, (char *)&v70 + 4, a5 + 1, a6 + 4, BYTE4(a6) & 0x40);
    if ( result >= 0 )
    {
      result = sub_6641F3(a2, 541065217, a4, &v70, (char *)&v70 + 4, HIDWORD(a6));
LABEL_18:
      if ( result < 0 )
        return result;
      return 0;
    }
  }
  return result;
}
