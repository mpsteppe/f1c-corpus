int __thiscall sub_68E712(int this, int a2, int a3)
{
  unsigned int i; // ecx
  _DWORD *v6; // eax
  unsigned int v7; // edx
  unsigned int j; // ecx
  _DWORD *v9; // eax
  unsigned int v10; // ecx
  int v11; // edx
  _DWORD *v12; // eax
  int v13; // edi
  int v14; // edi
  unsigned int v15; // eax
  int v16; // eax
  _DWORD *v17; // eax
  unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int *v20; // ecx
  unsigned int v21; // eax
  int v22; // edi
  unsigned int v23; // eax
  int *v24; // edi
  unsigned int v25; // ecx
  int v26; // eax
  unsigned int v27; // ecx
  unsigned int kk; // eax
  int v29; // eax
  int v30; // eax
  _DWORD *v31; // edi
  int v32; // eax
  int result; // eax
  int v34; // eax
  int v35; // ecx
  unsigned int v36; // edx
  _DWORD *v37; // ecx
  int v38; // edi
  unsigned int v39; // ecx
  int v40; // edx
  _DWORD *v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  bool v45; // zf
  int v46; // eax
  _DWORD *v47; // eax
  int v48; // ecx
  int v49; // [esp-8h] [ebp-30h]
  int v50; // [esp+Ch] [ebp-1Ch]
  unsigned int v51; // [esp+10h] [ebp-18h]
  int v52; // [esp+14h] [ebp-14h]
  int v53; // [esp+14h] [ebp-14h]
  int v54; // [esp+14h] [ebp-14h]
  _DWORD *v55; // [esp+18h] [ebp-10h]
  int v56; // [esp+1Ch] [ebp-Ch]
  unsigned int v57; // [esp+1Ch] [ebp-Ch]
  _DWORD *v58; // [esp+1Ch] [ebp-Ch]
  int v59; // [esp+1Ch] [ebp-Ch]
  int v60; // [esp+20h] [ebp-8h]
  int v61; // [esp+20h] [ebp-8h]
  int v62; // [esp+20h] [ebp-8h]
  unsigned int k; // [esp+24h] [ebp-4h]
  unsigned int jj; // [esp+24h] [ebp-4h]
  int v65; // [esp+24h] [ebp-4h]
  int v66; // [esp+30h] [ebp+8h]
  unsigned int v67; // [esp+30h] [ebp+8h]
  unsigned int v68; // [esp+30h] [ebp+8h]
  unsigned int v69; // [esp+30h] [ebp+8h]
  unsigned int v70; // [esp+30h] [ebp+8h]
  int v71; // [esp+30h] [ebp+8h]
  int v72; // [esp+30h] [ebp+8h]
  unsigned int mm; // [esp+30h] [ebp+8h]
  int v74; // [esp+34h] [ebp+Ch]
  unsigned int m; // [esp+34h] [ebp+Ch]
  unsigned int n; // [esp+34h] [ebp+Ch]
  unsigned int ii; // [esp+34h] [ebp+Ch]
  unsigned int v78; // [esp+34h] [ebp+Ch]
  unsigned int v79; // [esp+34h] [ebp+Ch]
  int v80; // [esp+34h] [ebp+Ch]
  int v81; // [esp+34h] [ebp+Ch]

  *(_DWORD *)(this + 188) = a2;
  *(_DWORD *)(a2 + 96) ^= (*(_DWORD *)(a2 + 96) ^ (2 * a3)) & 2;
  sub_686074(this);
  for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
  {
    v6 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * i);
    if ( *(_DWORD *)a2 == v6[1] && v6[14] == -1 )
    {
      v7 = v6[18];
      if ( v6[22] <= v7 )
        v6[22] = v7 + 1;
    }
  }
  memset(*(void **)(a2 + 16), 0xFFu, 4 * *(_DWORD *)(a2 + 40));
  memset(*(void **)(a2 + 20), 0xFFu, 16 * *(_DWORD *)(a2 + 40));
  memset(*(void **)(a2 + 24), 0xFFu, 16 * *(_DWORD *)(a2 + 40));
  for ( j = 0; j < *(_DWORD *)(this + 8); ++j )
  {
    v9 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * j);
    v9[12] = -1;
    if ( *(_DWORD *)a2 == v9[1] && v9[14] == -1 )
      *(_DWORD *)(*(_DWORD *)(a2 + 24) + 4 * (v9[4] + 4 * v9[3])) = j;
  }
  memset(*(void **)(a2 + 8), 0, 4 * *(_DWORD *)(a2 + 40));
  v10 = 0;
  if ( *(_DWORD *)(a2 + 40) )
  {
    v66 = 0;
    do
    {
      v11 = 0;
      v12 = (_DWORD *)(v66 + *(_DWORD *)(a2 + 24));
      v13 = 4;
      do
      {
        if ( *v12 != -1 )
          ++v11;
        ++v12;
        --v13;
      }
      while ( v13 );
      v66 += 16;
      *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v10++) = v11;
    }
    while ( v10 < *(_DWORD *)(a2 + 40) );
  }
  v67 = 0;
  memset(*(void **)(a2 + 12), 0, 4 * *(_DWORD *)(a2 + 40));
  if ( *(_DWORD *)(this + 12) )
  {
    do
    {
      v14 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v67);
      v60 = v14;
      if ( sub_680E0C((_DWORD *)v14) )
      {
        v74 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v14 + 16));
        if ( *(_DWORD *)a2 == *(_DWORD *)(v74 + 4) )
        {
          v56 = 2;
          do
          {
            v15 = 0;
            for ( k = 0; k < *(_DWORD *)(v14 + 4); v15 = k )
            {
              v16 = *(_DWORD *)(*(_DWORD *)(v14 + 8) + 4 * v15);
              if ( v16 != -1 && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v16) + 56) != -1 )
                v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v16) + 56);
              v17 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * v16);
              if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v17[1]) + 6) & 2) != 0 )
                v17 = *(_DWORD **)(*(_DWORD *)(this + 20)
                                 + 4 * **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v17[18]) + 8));
              if ( *(_DWORD *)a2 == v17[1] )
              {
                v18 = (unsigned int *)(*(_DWORD *)(a2 + 12) + 4 * v17[3]);
                v19 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * *(_DWORD *)(v74 + 12));
                if ( *v18 < v19 )
                  *v18 = v19;
                v14 = v60;
                v20 = (unsigned int *)(*(_DWORD *)(a2 + 12) + 4 * *(_DWORD *)(v74 + 12));
                v21 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v17[3]);
                if ( *v20 < v21 )
                  *v20 = v21;
              }
              k += *(_DWORD *)(v14 + 12);
            }
            --v56;
          }
          while ( v56 );
        }
      }
      ++v67;
    }
    while ( v67 < *(_DWORD *)(this + 12) );
  }
  v68 = 0;
  memset(*(void **)(a2 + 76), 0, 4 * *(_DWORD *)(a2 + 72));
  if ( *(_DWORD *)(this + 12) )
  {
    do
    {
      v22 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v68);
      if ( (*(_WORD *)(v22 + 2) & 0xFFF0) != 0 )
      {
        for ( m = 0; m < *(_DWORD *)(v22 + 12); ++m )
          sub_685D41((_DWORD *)this, (_DWORD *)a2, *(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * m), v68);
        for ( n = 0; n < *(_DWORD *)(v22 + 4); ++n )
          sub_685BBE((_DWORD *)this, (_DWORD *)a2, *(_DWORD *)(*(_DWORD *)(v22 + 8) + 4 * n), v68);
        if ( sub_680D7E((_DWORD *)v22) )
        {
          for ( ii = 0; ii < *(_DWORD *)(v22 + 12); ++ii )
            sub_685BBE((_DWORD *)this, (_DWORD *)a2, *(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * ii), v68);
        }
      }
      ++v68;
    }
    while ( v68 < *(_DWORD *)(this + 12) );
  }
  v23 = 0;
  for ( jj = 0; v23 < *(_DWORD *)(a2 + 72); jj = v23 )
  {
    v24 = (int *)(*(_DWORD *)(a2 + 84) + 4 * *(_DWORD *)(*(_DWORD *)(a2 + 80) + 4 * v23));
    v25 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 4 * v23);
    v78 = v25;
    if ( v25 > 1 )
    {
      sub_682274(sub_682225, v24, v25, this);
      v26 = 1;
      v69 = 1;
      v57 = 1;
      do
      {
        v52 = v24[v26];
        if ( sub_6821AC(this, v52, v24[v69 - 1]) )
        {
          v27 = v69++;
          v24[v27] = v52;
        }
        v26 = ++v57;
      }
      while ( v57 < v78 );
      *(_DWORD *)(*(_DWORD *)(a2 + 76) + 4 * jj) = v69;
      sub_682274(sub_6821ED, v24, v69, this);
      v23 = jj;
    }
    ++v23;
  }
  memset(*(void **)(a2 + 28), 0xFFu, 16 * *(_DWORD *)(a2 + 44));
  for ( kk = 0; kk < *(_DWORD *)(a2 + 44); ++kk )
    *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * kk) = kk;
  v29 = *(_DWORD *)(a2 + 44) >> 1;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 36) = v29;
  v30 = *(_DWORD *)(this + 12);
  while ( v30 )
  {
    --v30;
    v31 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v30);
    v53 = v30;
    if ( (*v31 & 0xFFF00000) == 0x20900000 )
    {
      v70 = 0;
      if ( v31[3] )
      {
        do
        {
          *(_DWORD *)(a2 + 92) = v31;
          v32 = *(_DWORD *)(v31[2] + 4 * v70);
          if ( v32 != -1 && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v32) + 56) != -1 )
            v32 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v32) + 56);
          result = sub_68DD50((_DWORD *)this, a2, v32, 0, -1, -1);
          if ( result < 0 )
            return result;
          v34 = *(_DWORD *)(v31[2] + 4 * (v70 + v31[3]));
          v35 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v34) + 72));
          v36 = *(_DWORD *)(v35 + 12);
          v79 = 0;
          v61 = v35;
          if ( v36 )
          {
            v37 = *(_DWORD **)(v35 + 16);
            v58 = v37;
            do
            {
              if ( *v37 == v34 )
                break;
              ++v79;
              v37 = ++v58;
            }
            while ( v79 < v36 );
          }
          *(_DWORD *)(a2 + 92) = v61;
          v49 = *(_DWORD *)(4 * v79 + *(_DWORD *)(v61 + 8));
          v80 = 4 * v79;
          result = sub_68DD50((_DWORD *)this, a2, *(_DWORD *)(v31[4] + 4 * v70), 0, v49, -1);
          if ( result < 0 )
            return result;
          result = sub_68DD50(
                     (_DWORD *)this,
                     a2,
                     *(_DWORD *)(v80 + *(_DWORD *)(v61 + 8)),
                     0,
                     *(_DWORD *)(v31[4] + 4 * v70),
                     -1);
          if ( result < 0 )
            return result;
          ++v70;
        }
        while ( v70 < v31[3] );
        v30 = v53;
      }
    }
  }
  v62 = 4;
  while ( 1 )
  {
    *(_DWORD *)(a2 + 4) = v62;
    v65 = *(_DWORD *)(this + 12);
    if ( v65 )
      break;
LABEL_100:
    if ( !--v62 )
    {
      if ( (*(_BYTE *)(a2 + 96) & 2) != 0 )
      {
        for ( mm = 0; mm < *(_DWORD *)(this + 8); ++mm )
        {
          v47 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * mm);
          if ( *(_DWORD *)a2 == v47[1] )
          {
            v48 = 4 * v47[3];
            v47[4] = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * (v48 + v47[4]));
            v47[3] = *(_DWORD *)(v48 + *(_DWORD *)(a2 + 16));
          }
        }
      }
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)a2) + 8) = -1;
      return 0;
    }
  }
  while ( 1 )
  {
    --v65;
    v38 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v65);
    *(_DWORD *)(a2 + 92) = v38;
    if ( (*(_WORD *)(v38 + 2) & 0xFFF0) == 0 )
      goto LABEL_99;
    v71 = 0;
    if ( *(_DWORD *)(v38 + 12) )
      break;
LABEL_79:
    v39 = *(_DWORD *)v38 & 0xFFFFF;
    v81 = 0;
    v51 = v39;
    v59 = *(_DWORD *)(v38 + 4) / v39;
    if ( *(_DWORD *)(v38 + 4) )
    {
      while ( 1 )
      {
        v72 = 0;
        if ( (*(_BYTE *)(this + 112) & 1) != 0 && v59 )
        {
          v40 = *(_DWORD *)(this + 20);
          v50 = v39;
          v41 = *(_DWORD **)(v38 + 8);
          v55 = v41;
          v54 = v59;
          do
          {
            v42 = *v41;
            if ( v42 != -1 && *(_DWORD *)(*(_DWORD *)(v40 + 4 * v42) + 56) != -1 )
              v42 = *(_DWORD *)(*(_DWORD *)(v40 + 4 * v42) + 56);
            v43 = *(_DWORD *)(v40 + 4 * v42);
            if ( *(_DWORD *)a2 == *(_DWORD *)(v43 + 4) )
            {
              v44 = *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4 * *(_DWORD *)(v43 + 12));
              if ( v44 != -1 )
              {
                if ( (v44 & 1) != 0 )
                  --v72;
                else
                  ++v72;
              }
            }
            v41 = &v55[v50];
            v45 = v54-- == 1;
            v55 = (_DWORD *)((char *)v55 + v50 * 4);
          }
          while ( !v45 );
        }
        v46 = *(_DWORD *)(*(_DWORD *)(v38 + 8) + 4 * v81);
        if ( v46 != -1 && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v46) + 56) != -1 )
          v46 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v46) + 56);
        result = sub_68DD50((_DWORD *)this, a2, v46, v72, -1, -1);
        if ( result < 0 )
          return result;
        if ( (unsigned int)++v81 >= *(_DWORD *)(v38 + 4) )
          break;
        v39 = v51;
      }
    }
LABEL_99:
    if ( !v65 )
      goto LABEL_100;
  }
  while ( 1 )
  {
    result = sub_68E018((_DWORD *)this, a2, *(_DWORD *)(*(_DWORD *)(v38 + 16) + 4 * v71));
    if ( result < 0 )
      return result;
    if ( (unsigned int)++v71 >= *(_DWORD *)(v38 + 12) )
      goto LABEL_79;
  }
}
