int __thiscall sub_6A7376(_DWORD *this, _DWORD *a2)
{
  int v3; // eax
  bool v4; // zf
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  int v8; // edx
  unsigned int v9; // edi
  int v10; // edx
  int v11; // ecx
  _DWORD *v12; // ecx
  int *v13; // eax
  int v14; // eax
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // edx
  unsigned int *v18; // eax
  int v19; // edi
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  int v22; // eax
  unsigned int v23; // edx
  int *v24; // ecx
  int v25; // eax
  unsigned int v26; // edi
  unsigned int j; // edx
  _DWORD *v28; // eax
  int v29; // edi
  char *v30; // edx
  unsigned int v31; // eax
  int v32; // ecx
  int v33; // edi
  int v34; // eax
  int v35; // eax
  unsigned int v36; // ebx
  int v37; // eax
  unsigned int v38; // edx
  int v39; // ecx
  unsigned int v40; // eax
  _DWORD *v41; // eax
  int v42; // edi
  unsigned int v43; // eax
  unsigned int v44; // edi
  _DWORD *v45; // eax
  int v46; // eax
  unsigned int v47; // ecx
  bool v48; // cc
  _DWORD **v49; // edx
  _DWORD *v50; // eax
  int v51; // ecx
  _DWORD *v52; // eax
  _DWORD *v53; // eax
  unsigned int v54; // edi
  _DWORD *v55; // eax
  _DWORD *v56; // eax
  char *v57; // edi
  _DWORD *v58; // eax
  unsigned int v59; // eax
  unsigned int v60; // ecx
  int v61; // ebx
  _DWORD *v62; // eax
  _DWORD *v63; // eax
  int v64; // eax
  int v65; // edx
  int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // edx
  unsigned int v69; // eax
  int v70; // ecx
  unsigned int v71; // edx
  int v72; // edi
  int v74; // ecx
  int v75; // edx
  int v76; // eax
  _BYTE v77[152]; // [esp-Ch] [ebp-E4h]
  _DWORD v78[4]; // [esp+8Ch] [ebp-4Ch] BYREF
  unsigned int v79; // [esp+9Ch] [ebp-3Ch]
  unsigned int v80; // [esp+A0h] [ebp-38h]
  unsigned int v81; // [esp+A4h] [ebp-34h]
  int v82; // [esp+A8h] [ebp-30h]
  unsigned int v83; // [esp+ACh] [ebp-2Ch]
  unsigned int i; // [esp+B0h] [ebp-28h]
  unsigned int k; // [esp+B4h] [ebp-24h]
  int v86; // [esp+B8h] [ebp-20h]
  char *v87; // [esp+BCh] [ebp-1Ch]
  unsigned int v88; // [esp+C0h] [ebp-18h]
  unsigned int n; // [esp+C4h] [ebp-14h]
  _DWORD *v90; // [esp+C8h] [ebp-10h]
  unsigned int m; // [esp+CCh] [ebp-Ch]
  unsigned int v92; // [esp+D0h] [ebp-8h]
  unsigned int v93; // [esp+D4h] [ebp-4h]

  v82 = 0;
  v87 = 0;
  for ( i = 0; i < 6; ++i )
  {
    v3 = *(_DWORD *)(this[139] + 4 * i);
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 + 12) )
      {
        v4 = this[137] == 0;
        m = 0;
        if ( !v4 )
        {
          do
          {
            n = *(_DWORD *)(this[140] + 4 * m);
            v5 = n;
            if ( n )
            {
              v6 = *(_DWORD *)n;
              if ( *(_DWORD *)n )
              {
                k = 0;
                v7 = m < 6;
                v79 = v7;
                v92 = v6 & 0xFFFFF;
                if ( (v6 & 0xFFFFF) != 0 )
                {
                  v8 = this[139];
                  v9 = *(_DWORD *)(v8 + 4 * i);
                  v80 = *(_DWORD *)(n + 4) / v92;
                  v4 = *(_DWORD *)(v9 + 12) == 0;
                  v86 = 0;
                  v88 = 0;
                  if ( !v4 )
                  {
                    v83 = *(_DWORD *)(*(_DWORD *)(v8 + 4 * i) + 12);
                    do
                    {
                      if ( v7 < v80 )
                      {
                        v10 = 4 * v7 * v92;
                        v81 = v80 - v7;
                        do
                        {
                          v11 = *(_DWORD *)(v5 + 8);
                          v90 = *(_DWORD **)(*(_DWORD *)(v9 + 16) + 4 * v88);
                          v12 = (_DWORD *)(v10 + v11);
                          v93 = v92;
                          do
                          {
                            if ( ((_DWORD *)*v12 == v90 || *(_DWORD **)(*(_DWORD *)(this[5] + 4 * *v12) + 56) == v90)
                              && m > i )
                            {
                              v13 = *(int **)(this[140] + 4 * i);
                              if ( v13 )
                              {
                                v14 = *v13;
                                if ( v14 )
                                {
                                  if ( (v14 & 0xFFF00000) != 0x11000000 )
                                  {
                                    v86 = 1;
                                    k = v9;
                                  }
                                }
                              }
                            }
                            ++v12;
                            --v93;
                          }
                          while ( v93 );
                          v5 = n;
                          v7 = v79;
                          v10 += 4 * v92;
                          --v81;
                        }
                        while ( v81 );
                      }
                      ++v88;
                    }
                    while ( v88 < v83 );
                    if ( v86 )
                    {
                      if ( a2 )
                      {
                        ++*a2;
                        ++*a2;
                      }
                      else
                      {
                        memset(v78, 255, sizeof(v78));
                        v4 = *(_DWORD *)(v5 + 4) == 0;
                        v93 = 0;
                        v92 = 0;
                        if ( !v4 )
                        {
                          do
                          {
                            v22 = *(_DWORD *)(k + 12);
                            if ( v22 )
                            {
                              v23 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + 4 * v92);
                              v24 = *(int **)(k + 16);
                              v83 = v23;
                              v86 = v22;
                              while ( 1 )
                              {
                                v25 = *v24;
                                if ( *v24 == v23 || v25 == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v23) + 56) )
                                {
                                  v26 = v93;
                                  for ( j = 0; j < v93; ++j )
                                  {
                                    if ( v78[j] == v25 )
                                      break;
                                  }
                                  if ( j == v93 )
                                  {
                                    v78[v93] = v25;
                                    v93 = v26 + 1;
                                  }
                                }
                                ++v24;
                                if ( !--v86 )
                                  break;
                                v23 = v83;
                              }
                            }
                            ++v92;
                          }
                          while ( v92 < *(_DWORD *)(v5 + 4) );
                        }
                        v28 = (_DWORD *)sub_681186(116);
                        if ( v28 )
                          v87 = (char *)sub_680CEC(v28);
                        else
                          v87 = 0;
                        if ( !v87 )
                          goto LABEL_71;
                        v29 = sub_6811D1(v87, v93 & 0xFFFFF | 0x10000000, v93, v93, 0);
                        v90 = (_DWORD *)v29;
                        if ( v29 < 0 )
                          goto LABEL_140;
                        v30 = v87;
                        memset(*((void **)v87 + 4), 0xFFu, 4 * v93);
                        v4 = *(_DWORD *)(v5 + 4) == 0;
                        v88 = 0;
                        if ( !v4 )
                        {
                          v31 = k;
                          do
                          {
                            v4 = *(_DWORD *)(v31 + 12) == 0;
                            v92 = 0;
                            if ( !v4 )
                            {
                              do
                              {
                                v32 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + 4 * v88);
                                v33 = this[5];
                                v34 = *(_DWORD *)(v31 + 16);
                                v90 = *(_DWORD **)(v33 + 4 * v32);
                                v35 = *(_DWORD *)(v34 + 4 * v92);
                                if ( v35 == v32 || v35 == v90[14] )
                                {
                                  v36 = *(_DWORD *)(v33 + 4 * v35);
                                  v37 = *((_DWORD *)v87 + 4);
                                  v83 = v36;
                                  v38 = 4 * (v88 % v93);
                                  v39 = *(_DWORD *)(v38 + v37);
                                  if ( v39 == -1 )
                                  {
                                    v40 = this[258];
                                    if ( v40 >= 0x40 )
                                      goto LABEL_71;
                                    v39 = this[v40 + 193];
                                    this[258] = v40 + 1;
                                    v41 = *(_DWORD **)(v33 + 4 * v39);
                                    v42 = this[34];
                                    v41[15] = 0;
                                    v41[14] = -1;
                                    v36 = v83;
                                    v41[1] = v42;
                                    v41[4] = *(_DWORD *)(v36 + 16);
                                    if ( v39 == -1 )
                                      goto LABEL_71;
                                  }
                                  if ( *(_DWORD *)(*(_DWORD *)(k + 16) + 4 * v92) == v90[14] )
                                  {
                                    v43 = this[258];
                                    if ( v43 >= 0x40 )
                                      goto LABEL_71;
                                    v44 = this[v43 + 193];
                                    this[258] = v43 + 1;
                                    v45 = *(_DWORD **)(this[5] + 4 * v44);
                                    v45[4] = *(_DWORD *)(v36 + 16);
                                    v45[15] = v90[15];
                                    v45[14] = v39;
                                    v45[1] = this[34];
                                    v46 = *(_DWORD *)(n + 8);
                                    v83 = v44;
                                    *(_DWORD *)(v46 + 4 * v88) = v44;
                                  }
                                  else
                                  {
                                    *(_DWORD *)(*(_DWORD *)(n + 8) + 4 * v88) = v39;
                                  }
                                  v5 = n;
                                  *(_DWORD *)(v38 + *((_DWORD *)v87 + 2)) = *(_DWORD *)(*(_DWORD *)(k + 16) + 4 * v92);
                                  *(_DWORD *)(v38 + *((_DWORD *)v87 + 4)) = v39;
                                  *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v39) + 60) = 0;
                                }
                                ++v92;
                                v31 = k;
                              }
                              while ( v92 < *(_DWORD *)(k + 12) );
                              v30 = v87;
                            }
                            ++v88;
                          }
                          while ( v88 < *(_DWORD *)(v5 + 4) );
                        }
                        *(_DWORD *)(this[139] + 4 * this[136]++) = v30;
                        v47 = this[257];
                        if ( v47 >= 0xC )
                        {
LABEL_71:
                          v29 = -2147024882;
LABEL_140:
                          if ( v87 )
                            sub_66238F(v87, 1);
                          return v29;
                        }
                        this[v47 + 177] = v30;
                        ++this[257];
                        v87 = 0;
                      }
                    }
                  }
                }
              }
            }
            ++m;
          }
          while ( m < this[137] );
        }
      }
    }
  }
  for ( k = 0; k < this[136]; ++k )
  {
    v15 = *(_DWORD **)(this[139] + 4 * k);
    if ( v15 )
    {
      if ( *v15 )
      {
        v16 = v15[3];
        v86 = 0;
        if ( v16 )
        {
          v17 = this[5];
          v18 = (unsigned int *)v15[4];
          v19 = v16;
          do
          {
            v20 = *v18;
            if ( *(_DWORD *)(*(_DWORD *)(v17 + 4 * *v18) + 16) == 3 )
            {
              v21 = *v18;
              v86 = 1;
              i = v20;
            }
            else
            {
              v21 = i;
            }
            ++v18;
            --v19;
          }
          while ( v19 );
          if ( v86 )
          {
            v93 = 0;
            v48 = this[137] <= 6u;
            m = 6;
            if ( !v48 )
            {
              v49 = (_DWORD **)(this[140] + 24);
              do
              {
                v50 = *v49;
                if ( *v49 )
                {
                  if ( *v50 )
                  {
                    v4 = v50[1] == 0;
                    n = 0;
                    if ( !v4 )
                    {
                      v90 = (_DWORD *)v50[2];
                      do
                      {
                        if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v90) + 56) == v21 || *v90 == v21 )
                        {
                          if ( v93 >= 0x10 )
                            return -2147467259;
                          v51 = v93++;
                          *(_DWORD *)&v77[4 * v51 + 88] = v50;
                        }
                        ++n;
                        ++v90;
                      }
                      while ( n < v50[1] );
                    }
                  }
                }
                ++m;
                ++v49;
              }
              while ( m < this[137] );
            }
            v52 = a2;
            if ( a2 )
            {
              m = 0;
              if ( this[3] )
              {
                n = this[6];
                do
                {
                  v53 = *(_DWORD **)n;
                  if ( *(_DWORD *)n )
                  {
                    if ( *v53 )
                    {
                      if ( v53[10] != 1 )
                      {
                        v54 = v53[1];
                        v90 = 0;
                        if ( v54 )
                        {
                          v55 = (_DWORD *)v53[2];
                          do
                          {
                            if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v55) + 56) == v21 || *v55 == v21 )
                            {
                              if ( v93 >= 0x10 )
                                return -2147467259;
                              ++v93;
                            }
                            v90 = (_DWORD *)((char *)v90 + 1);
                            ++v55;
                          }
                          while ( (unsigned int)v90 < v54 );
                        }
                      }
                    }
                  }
                  ++m;
                  n += 4;
                }
                while ( m < this[3] );
                v52 = a2;
              }
              if ( !v93 )
                continue;
              ++*v52;
            }
            if ( v93 && !v52 )
            {
              if ( this[257] >= 0xCu )
                return 1;
              v56 = (_DWORD *)sub_681186(116);
              if ( v56 )
                v57 = (char *)sub_680CEC(v56);
              else
                v57 = 0;
              v58 = (_DWORD *)sub_681186(116);
              if ( v58 )
                v92 = (unsigned int)sub_680CEC(v58);
              else
                v92 = 0;
              if ( !v57 )
                return -2147024882;
              if ( !v92 )
                return -2147024882;
              v59 = this[258];
              if ( v59 > 0x40 )
                return -2147024882;
              v60 = this[v59 + 194];
              v61 = this[v59 + 193];
              v62 = *(_DWORD **)(this[5] + 4 * v60);
              v62[14] = -1;
              v62[4] = 3;
              v62[15] = 0;
              v63 = *(_DWORD **)(this[5] + 4 * v61);
              v63[14] = -1;
              v63[4] = 4;
              v63[15] = 0;
              this[258] += 2;
              v83 = v60;
              for ( m = 0; m < v93; ++m )
              {
                v64 = *(_DWORD *)&v77[4 * m + 88];
                for ( n = 0; n < *(_DWORD *)(v64 + 4); v64 = *(_DWORD *)&v77[4 * m + 88] )
                {
                  v65 = this[5];
                  v86 = *(_DWORD *)(v64 + 8) + 4 * n;
                  v66 = *(_DWORD *)(v65 + 4 * *(_DWORD *)v86);
                  if ( *(_DWORD *)(v66 + 56) == i )
                  {
                    *(_DWORD *)(v66 + 56) = v60;
                  }
                  else if ( *(_DWORD *)v86 == i )
                  {
                    *(_DWORD *)v86 = v60;
                  }
                  ++n;
                }
              }
              v90 = (_DWORD *)sub_6811D1(v57, 268435457, 1, 1, 0);
              if ( (int)v90 < 0 )
                return (int)v90;
              v90 = (_DWORD *)sub_6811D1((char *)v92, 268435457, 1, 1, 0);
              if ( (int)v90 < 0 )
                return (int)v90;
              v67 = i;
              v68 = v83;
              **((_DWORD **)v57 + 4) = v61;
              **((_DWORD **)v57 + 2) = v67;
              v69 = v92;
              *((_DWORD *)v57 + 10) = 1;
              **(_DWORD **)(v69 + 16) = v68;
              **(_DWORD **)(v69 + 8) = v61;
              *((_DWORD *)v57 + 10) = 2;
              this[this[257] + 177] = v57;
              this[this[257] + 178] = v69;
              this[257] += 2;
              *(_DWORD *)(this[139] + 4 * this[136]) = v57;
              v70 = v82;
              ++this[136];
              ++v82;
              *(_DWORD *)&v77[4 * v70 + 24] = v69;
            }
          }
        }
      }
    }
  }
  v71 = this[137];
  v72 = v82;
  if ( v71 + v82 <= 0x200 )
  {
    if ( v71 >= 6 )
    {
      v74 = 4 * (v71 + v82);
      do
      {
        *(_DWORD *)(this[140] + v74) = *(_DWORD *)(this[140] + 4 * v71--);
        v74 -= 4;
      }
      while ( v71 >= 6 );
    }
    if ( v72 )
    {
      v75 = v82;
      v76 = 24;
      do
      {
        *(_DWORD *)(v76 + this[140]) = *(_DWORD *)&v77[v76];
        v76 += 4;
        --v75;
      }
      while ( v75 );
    }
    this[137] += v82;
    v29 = 0;
    goto LABEL_140;
  }
  return -2147467259;
}
