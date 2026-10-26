int __thiscall sub_68E047(char *this, _DWORD *a2, int a3, int a4)
{
  char *v4; // ebx
  unsigned int v7; // edi
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  void *v13; // eax
  void *v14; // eax
  void *v15; // eax
  void *v16; // eax
  void *v17; // eax
  void *v18; // eax
  void *v19; // eax
  void *v20; // eax
  void *v21; // eax
  void *v22; // eax
  _DWORD *v23; // edi
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int v31; // edi
  _DWORD *v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  unsigned int k; // ecx
  void *v37; // eax
  int v38; // edi
  unsigned int v39; // ecx
  int v40; // edx
  int v41; // edi
  int v42; // eax
  int v43; // eax
  _DWORD *v44; // eax
  bool v45; // zf
  unsigned int v46; // ecx
  int v47; // eax
  void *v48; // eax
  int v49; // edi
  unsigned int v50; // eax
  int kk; // edi
  void *v52; // eax
  void *v53; // eax
  int v55; // [esp+8h] [ebp-24h]
  unsigned int v56; // [esp+Ch] [ebp-20h]
  int v57; // [esp+Ch] [ebp-20h]
  int v58; // [esp+10h] [ebp-1Ch]
  int v59; // [esp+10h] [ebp-1Ch]
  int v60; // [esp+14h] [ebp-18h]
  int v61; // [esp+14h] [ebp-18h]
  int v62; // [esp+18h] [ebp-14h]
  int v63; // [esp+18h] [ebp-14h]
  unsigned int i; // [esp+1Ch] [ebp-10h]
  _DWORD *v65; // [esp+20h] [ebp-Ch]
  int v66; // [esp+20h] [ebp-Ch]
  int v67; // [esp+24h] [ebp-8h]
  _DWORD *v68; // [esp+28h] [ebp-4h]
  unsigned int v69; // [esp+34h] [ebp+8h]
  int v70; // [esp+34h] [ebp+8h]
  unsigned int n; // [esp+34h] [ebp+8h]
  unsigned int ii; // [esp+34h] [ebp+8h]
  unsigned int jj; // [esp+34h] [ebp+8h]
  unsigned int v74; // [esp+38h] [ebp+Ch]
  int v75; // [esp+3Ch] [ebp+10h]
  unsigned int v76; // [esp+3Ch] [ebp+10h]
  unsigned int j; // [esp+3Ch] [ebp+10h]
  unsigned int m; // [esp+3Ch] [ebp+10h]

  v4 = this;
  sub_686074((int)this);
  if ( !a2 )
    return -2147467259;
  memset(a2, 0, 0x64u);
  a2[11] = a4;
  *a2 = a3;
  v7 = 0;
  a2[24] ^= (a2[24] ^ ((2 * *((_DWORD *)v4 + 27)) >> 31)) & 1;
  if ( *((_DWORD *)v4 + 2) )
  {
    do
    {
      v8 = *(_DWORD **)(*((_DWORD *)v4 + 5) + 4 * v7);
      if ( a3 == v8[1] && v8[14] == -1 )
      {
        v9 = v8[3];
        if ( v9 >= a2[10] )
          a2[10] = v9 + 1;
        v8[29] = a2[18]++;
      }
      ++v7;
    }
    while ( v7 < *((_DWORD *)v4 + 2) );
  }
  v10 = operator new(4 * a2[10]);
  a2[4] = v10;
  if ( v10 )
  {
    v11 = operator new(16 * a2[10]);
    a2[5] = v11;
    if ( v11 )
    {
      v12 = operator new(16 * a2[10]);
      a2[6] = v12;
      if ( v12 )
      {
        v13 = operator new(4 * a2[10]);
        a2[2] = v13;
        if ( v13 )
        {
          v14 = operator new(4 * a2[10]);
          a2[3] = v14;
          if ( v14 )
          {
            v15 = operator new(16 * a2[11]);
            a2[7] = v15;
            if ( v15 )
            {
              v16 = operator new(4 * a2[11]);
              a2[8] = v16;
              if ( v16 )
              {
                v17 = operator new(16 * a2[10]);
                a2[12] = v17;
                if ( v17 )
                {
                  v18 = operator new(16 * a2[10]);
                  a2[13] = v18;
                  if ( v18 )
                  {
                    v19 = operator new(4 * a2[10]);
                    a2[15] = v19;
                    if ( v19 )
                    {
                      v20 = operator new(4 * a2[10]);
                      a2[16] = v20;
                      if ( v20 )
                      {
                        v21 = operator new(4 * a2[18]);
                        a2[19] = v21;
                        if ( v21 )
                        {
                          v22 = operator new(4 * a2[18]);
                          a2[20] = v22;
                          if ( v22 )
                          {
                            v67 = 0;
                            while ( 1 )
                            {
                              memset((void *)a2[12], 0, 16 * a2[10]);
                              v58 = 0;
                              for ( i = 0; i < *((_DWORD *)v4 + 3); ++i )
                              {
                                v65 = *(_DWORD **)(*((_DWORD *)v4 + 6) + 4 * i);
                                if ( sub_680E0C(v65) )
                                {
                                  if ( a3 == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * *(_DWORD *)v65[4]) + 4) )
                                  {
                                    v69 = *v65 & 0xFFFFF;
                                    if ( v65[1] / v69 )
                                    {
                                      v60 = 0;
                                      v56 = v65[1] / (*v65 & 0xFFFFFu);
                                      do
                                      {
                                        v23 = (_DWORD *)(v60 + v65[2]);
                                        v68 = v23;
                                        v75 = *v23;
                                        if ( *v23 == -1
                                          || (v24 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * *v23) + 56),
                                              v24 == -1) )
                                        {
                                          v24 = *v23;
                                        }
                                        v25 = *((_DWORD *)v4 + 5);
                                        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v4 + 4)
                                                                   + 4 * *(_DWORD *)(*(_DWORD *)(v25 + 4 * v24) + 4))
                                                       + 6)
                                            & 2) != 0 )
                                        {
                                          if ( v75 == -1
                                            || (v26 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * v75) + 56), v26 == -1) )
                                          {
                                            v26 = *v23;
                                          }
                                          v23 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)v4 + 6)
                                                                       + 4
                                                                       * *(_DWORD *)(*(_DWORD *)(v25 + 4 * v26) + 72))
                                                           + 8);
                                          v68 = v23;
                                        }
                                        v27 = *v23;
                                        if ( *v23 != -1 && *(_DWORD *)(*(_DWORD *)(v25 + 4 * v27) + 56) != -1 )
                                          v27 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * v27) + 56);
                                        if ( a3 == *(_DWORD *)(*(_DWORD *)(v25 + 4 * v27) + 4) )
                                        {
                                          v62 = 0;
                                          v76 = 0;
                                          if ( !v69 )
                                            goto LABEL_48;
                                          do
                                          {
                                            v28 = v23[v76];
                                            if ( v28 != -1 && *(_DWORD *)(*(_DWORD *)(v25 + 4 * v28) + 56) != -1 )
                                              v28 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * v28) + 56);
                                            v29 = 1 << *(_DWORD *)(*(_DWORD *)(v25 + 4 * v28) + 16);
                                            if ( (v29 & v62) != 0 )
                                              break;
                                            v62 |= v29;
                                            ++v76;
                                          }
                                          while ( v76 < v69 );
                                          if ( v76 >= v69 )
                                          {
LABEL_48:
                                            for ( j = 0; j < v69; v23 = v68 )
                                            {
                                              v30 = *((_DWORD *)v4 + 5);
                                              v31 = v23[j];
                                              v32 = *(_DWORD **)(v30 + 4 * *(_DWORD *)(4 * j + v65[4]));
                                              if ( v31 != -1 && *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 56) != -1 )
                                                v31 = *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 56);
                                              v33 = v32[4] + 4 * v32[3];
                                              v34 = *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 16)
                                                  + 4 * *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 12);
                                              if ( v33 != v34 && !v32[15] )
                                              {
                                                if ( v67 == 1 )
                                                {
                                                  v4 = this;
                                                  *(_DWORD *)(a2[14]
                                                            + 4
                                                            * (*(_DWORD *)(a2[13] + 4 * v33)
                                                             + *(_DWORD *)(a2[12] + 4 * v33))) = v34;
                                                  *(_DWORD *)(a2[14]
                                                            + 4
                                                            * (*(_DWORD *)(a2[13] + 4 * v34)
                                                             + *(_DWORD *)(a2[12] + 4 * v34))) = v33;
                                                }
                                                ++*(_DWORD *)(a2[12] + 4 * v33);
                                                ++*(_DWORD *)(a2[12] + 4 * v34);
                                                v58 += 2;
                                              }
                                              ++j;
                                            }
                                          }
                                        }
                                        v60 += 4 * v69;
                                        --v56;
                                      }
                                      while ( v56 );
                                    }
                                  }
                                }
                              }
                              if ( !v67 )
                              {
                                v35 = 0;
                                for ( k = 0; k < 4 * a2[10]; ++k )
                                {
                                  *(_DWORD *)(a2[13] + 4 * k) = v35;
                                  v35 += *(_DWORD *)(a2[12] + 4 * k);
                                }
                                v37 = operator new(4 * v58);
                                a2[14] = v37;
                                if ( !v37 )
                                  break;
                              }
                              if ( (unsigned int)++v67 >= 2 )
                              {
                                v70 = 0;
                                while ( 1 )
                                {
                                  memset((void *)a2[15], 0, 4 * a2[10]);
                                  v61 = 0;
                                  for ( m = 0; m < *((_DWORD *)v4 + 3); ++m )
                                  {
                                    v59 = *(_DWORD *)(*((_DWORD *)v4 + 6) + 4 * m);
                                    if ( sub_680E44((_DWORD *)v59) || v4[111] < 0 )
                                    {
                                      v38 = *(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * **(_DWORD **)(v59 + 16));
                                      if ( a3 == *(_DWORD *)(v38 + 4) )
                                      {
                                        v39 = *(_DWORD *)v59 & 0xFFFFF;
                                        v40 = *(_DWORD *)(v38 + 12);
                                        v55 = v40;
                                        if ( *(_DWORD *)(v59 + 4) / v39 )
                                        {
                                          v41 = 0;
                                          v57 = 0;
                                          v66 = 4 * v39;
                                          v63 = *(_DWORD *)(v59 + 4) / v39;
                                          do
                                          {
                                            v42 = *(_DWORD *)(v41 + *(_DWORD *)(v59 + 8));
                                            if ( v42 != -1
                                              && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * v42) + 56) != -1 )
                                            {
                                              v42 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * v42) + 56);
                                            }
                                            v43 = *(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * v42);
                                            if ( a3 == *(_DWORD *)(v43 + 4) && v40 != *(_DWORD *)(v43 + 12) )
                                            {
                                              if ( v70 == 1 )
                                              {
                                                *(_DWORD *)(a2[17]
                                                          + 4
                                                          * (*(_DWORD *)(a2[15] + 4 * v40)
                                                           + *(_DWORD *)(4 * v40 + a2[16]))) = *(_DWORD *)(v43 + 12);
                                                v40 = v55;
                                                *(_DWORD *)(a2[17]
                                                          + 4
                                                          * (*(_DWORD *)(a2[15] + 4 * *(_DWORD *)(v43 + 12))
                                                           + *(_DWORD *)(4 * *(_DWORD *)(v43 + 12) + a2[16]))) = v55;
                                              }
                                              ++*(_DWORD *)(a2[15] + 4 * v40);
                                              v44 = (_DWORD *)(a2[15] + 4 * *(_DWORD *)(v43 + 12));
                                              ++*v44;
                                              v61 += 2;
                                            }
                                            v41 = v66 + v57;
                                            v45 = v63-- == 1;
                                            v57 += v66;
                                          }
                                          while ( !v45 );
                                        }
                                      }
                                    }
                                  }
                                  v46 = 0;
                                  if ( !v70 )
                                  {
                                    v47 = 0;
                                    if ( a2[10] )
                                    {
                                      do
                                      {
                                        *(_DWORD *)(a2[16] + 4 * v46) = v47;
                                        v47 += *(_DWORD *)(a2[15] + 4 * v46++);
                                      }
                                      while ( v46 < a2[10] );
                                    }
                                    v48 = operator new(4 * v61);
                                    a2[17] = v48;
                                    if ( !v48 )
                                      break;
                                  }
                                  if ( (unsigned int)++v70 >= 2 )
                                  {
                                    v74 = 0;
                                    memset((void *)a2[19], 0, 4 * a2[18]);
                                    if ( *((_DWORD *)v4 + 3) )
                                    {
                                      do
                                      {
                                        v49 = *(_DWORD *)(*((_DWORD *)v4 + 6) + 4 * v74);
                                        if ( (*(_WORD *)(v49 + 2) & 0xFFF0) != 0 )
                                        {
                                          for ( n = 0; n < *(_DWORD *)(v49 + 12); ++n )
                                            sub_685D41(v4, a2, *(_DWORD *)(*(_DWORD *)(v49 + 16) + 4 * n), v74);
                                          for ( ii = 0; ii < *(_DWORD *)(v49 + 4); ++ii )
                                            sub_685BBE(v4, a2, *(_DWORD *)(*(_DWORD *)(v49 + 8) + 4 * ii), v74);
                                          if ( sub_680D7E((_DWORD *)v49) )
                                          {
                                            for ( jj = 0; jj < *(_DWORD *)(v49 + 12); ++jj )
                                              sub_685BBE(v4, a2, *(_DWORD *)(*(_DWORD *)(v49 + 16) + 4 * jj), v74);
                                          }
                                        }
                                        ++v74;
                                      }
                                      while ( v74 < *((_DWORD *)v4 + 3) );
                                    }
                                    v50 = 0;
                                    for ( kk = 0; v50 < a2[18]; ++v50 )
                                    {
                                      *(_DWORD *)(a2[20] + 4 * v50) = kk;
                                      kk += *(_DWORD *)(a2[19] + 4 * v50);
                                    }
                                    v52 = operator new(4 * kk);
                                    a2[21] = v52;
                                    if ( v52 )
                                    {
                                      v53 = operator new(12 * kk);
                                      a2[22] = v53;
                                      if ( v53 )
                                        return 0;
                                    }
                                    return -2147024882;
                                  }
                                }
                                return -2147024882;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -2147024882;
}
