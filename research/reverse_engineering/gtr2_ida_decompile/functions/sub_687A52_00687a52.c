int __thiscall sub_687A52(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // eax
  int *v6; // edi
  int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  bool v10; // zf
  _DWORD *v11; // edx
  unsigned int v12; // edx
  _DWORD *v13; // eax
  _DWORD *v14; // edi
  unsigned int v15; // ecx
  int v16; // edx
  _DWORD *v17; // ecx
  int v18; // edx
  _DWORD *v19; // eax
  unsigned int v20; // edx
  _DWORD *v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  int v25; // ebx
  unsigned int v26; // ebx
  int v27; // ecx
  unsigned int v28; // edi
  int v29; // eax
  int v30; // ecx
  unsigned int v32; // [esp+8h] [ebp-54h]
  int v33; // [esp+Ch] [ebp-50h]
  BOOL n; // [esp+10h] [ebp-4Ch]
  unsigned int v35; // [esp+10h] [ebp-4Ch]
  _DWORD *v36; // [esp+14h] [ebp-48h]
  _DWORD *v37; // [esp+14h] [ebp-48h]
  unsigned int v38; // [esp+18h] [ebp-44h]
  _DWORD *v39; // [esp+1Ch] [ebp-40h]
  int i; // [esp+20h] [ebp-3Ch]
  unsigned int v41; // [esp+24h] [ebp-38h]
  int v42; // [esp+24h] [ebp-38h]
  int *v43; // [esp+28h] [ebp-34h]
  _DWORD *v44; // [esp+2Ch] [ebp-30h]
  int *Block; // [esp+30h] [ebp-2Ch]
  int j; // [esp+34h] [ebp-28h]
  _DWORD *v47; // [esp+38h] [ebp-24h]
  BOOL v48; // [esp+3Ch] [ebp-20h]
  unsigned int v49; // [esp+40h] [ebp-1Ch]
  int v50; // [esp+40h] [ebp-1Ch]
  unsigned int m; // [esp+40h] [ebp-1Ch]
  unsigned int v52; // [esp+44h] [ebp-18h]
  unsigned int v53; // [esp+44h] [ebp-18h]
  unsigned int k; // [esp+44h] [ebp-18h]
  unsigned int v55; // [esp+48h] [ebp-14h]
  unsigned int v56; // [esp+4Ch] [ebp-10h]
  unsigned int v57; // [esp+50h] [ebp-Ch]
  int v58; // [esp+54h] [ebp-8h]
  int v59; // [esp+58h] [ebp-4h]
  int v60; // [esp+58h] [ebp-4h]
  int v61; // [esp+58h] [ebp-4h]

  Block = (int *)operator new(4 * this[2]);
  if ( Block )
  {
    for ( i = 0; ; ++i )
    {
      v33 = 0;
      v56 = 0;
      sub_686074((int)this);
      sub_686606(this);
      v59 = 0;
      if ( this[2] )
        break;
LABEL_30:
      sub_682274(sub_682246, Block, v56, (int)this);
      if ( !v56 )
        goto LABEL_88;
      v42 = 1;
      v43 = Block;
      v35 = v56;
      do
      {
        v13 = *(_DWORD **)(this[5] + 4 * *v43);
        v14 = *(_DWORD **)(this[6] + 4 * v13[18]);
        v47 = v13;
        v37 = v14;
        if ( v13[12] == *v43 )
        {
          v15 = v42;
          for ( j = v42; v15 < v56; v15 = j )
          {
            v16 = Block[j];
            v17 = *(_DWORD **)(this[5] + 4 * v16);
            v39 = v17;
            if ( v13[16] != v17[16] )
              break;
            if ( v17[12] == v16 )
            {
              v18 = v17[18];
              if ( v13[18] != v18
                && v13[1] == v17[1]
                && v13[5] == v17[5]
                && v13[6] == v17[6]
                && ((*v14 ^ **(_DWORD **)(this[6] + 4 * v18)) & 0xFFF00000) == 0 )
              {
                v57 = v14[1] / (*v14 & 0xFFFFFu);
                v50 = 0;
                v48 = sub_680DDB(v14);
                while ( 1 )
                {
                  v19 = v39;
                  if ( !v50 )
                    v19 = v47;
                  v20 = v19[18];
                  v21 = v47;
                  v38 = v20;
                  if ( !v50 )
                    v21 = v39;
                  v22 = v21[18];
                  v23 = this[6];
                  v24 = *(_DWORD **)(v23 + 4 * v22);
                  v25 = *(_DWORD *)(v23 + 4 * v20);
                  v53 = 0;
                  v58 = v25;
                  if ( v24[3] )
                  {
                    v44 = (_DWORD *)v24[4];
                    do
                    {
                      if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v44) + 84) <= v20 )
                        break;
                      v55 = 0;
                      if ( *(_DWORD *)(v25 + 12) )
                      {
                        do
                        {
                          v60 = 0;
                          if ( v57 )
                          {
                            while ( 1 )
                            {
                              v32 = sub_6824F1(this, (int)v24, v60, v53, v48);
                              if ( sub_6824F1(this, v25, v60, v55, v48) != v32 )
                                break;
                              if ( ++v60 >= v57 )
                                break;
                              v25 = v58;
                            }
                            v25 = v58;
                          }
                          if ( v60 == v57 )
                            break;
                          ++v55;
                        }
                        while ( v55 < *(_DWORD *)(v25 + 12) );
                        v20 = v38;
                      }
                      if ( v55 == *(_DWORD *)(v25 + 12) )
                        break;
                      ++v53;
                      ++v44;
                    }
                    while ( v53 < v24[3] );
                  }
                  if ( v53 >= v24[3] )
                    break;
                  if ( (unsigned int)++v50 >= 2 )
                    goto LABEL_76;
                }
                for ( k = 0; k < v24[3]; *(_DWORD *)(v27 + 48) = *(_DWORD *)(*(_DWORD *)(v25 + 16) + 4 * m) )
                {
                  for ( m = 0; m < *(_DWORD *)(v25 + 12); ++m )
                  {
                    v61 = 0;
                    if ( v57 )
                    {
                      while ( 1 )
                      {
                        v26 = sub_6824F1(this, v25, v61, m, v48);
                        if ( v26 != sub_6824F1(this, (int)v24, v61, k, v48) )
                          break;
                        if ( ++v61 >= v57 )
                          break;
                        v25 = v58;
                      }
                      v25 = v58;
                    }
                    if ( v61 == v57 )
                      break;
                  }
                  v27 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v24[4] + 4 * k++));
                }
                *v24 = 0;
                v33 = 1;
LABEL_76:
                v13 = v47;
                v14 = v37;
              }
            }
            ++j;
          }
        }
        ++v43;
        ++v42;
        --v35;
      }
      while ( v35 );
      if ( !v33 )
      {
LABEL_88:
        v2 = i == 0;
        goto LABEL_89;
      }
      v28 = 0;
      if ( this[2] )
      {
        v29 = this[5];
        do
        {
          v30 = *(_DWORD *)(v29 + 4 * v28);
          while ( *(_DWORD *)(v30 + 48) != *(_DWORD *)(*(_DWORD *)(v29 + 4 * *(_DWORD *)(v30 + 48)) + 48) )
          {
            *(_DWORD *)(v30 + 48) = *(_DWORD *)(*(_DWORD *)(v29 + 4 * *(_DWORD *)(v30 + 48)) + 48);
            v29 = this[5];
          }
          ++v28;
        }
        while ( v28 < this[2] );
      }
      sub_68661F(this);
    }
    while ( 1 )
    {
      v3 = *(_DWORD **)(this[5] + 4 * v59);
      v36 = v3;
      if ( v3[2] == -1 )
      {
        v4 = v3[18];
        if ( v4 != -1 )
        {
          v5 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v3[1]) + 4);
          if ( (v5 & 2) != 0 && (v5 & 0x20) == 0 )
          {
            v6 = *(int **)(this[6] + 4 * v4);
            v7 = *v6;
            v8 = *v6 & 0xF0000000;
            if ( v8 >= 0x10000000 && v8 <= 0x40000000 )
            {
              v9 = v7 & 0xFFF00000;
              if ( (v7 & 0xFFF00000) > 0x11400000 )
              {
                if ( v9 != 290455552 && v9 != 544210944 && v9 != 545259520 )
                {
                  v10 = v9 == 546308096;
LABEL_21:
                  if ( !v10 )
                  {
                    v49 = 0;
                    if ( v6[3] )
                    {
                      v11 = (_DWORD *)v6[4];
                      do
                      {
                        if ( v59 == *v11 )
                          break;
                        ++v49;
                        ++v11;
                      }
                      while ( v49 < v6[3] );
                    }
                    v41 = v6[1] / (v7 & 0xFFFFFu);
                    v52 = 0;
                    for ( n = sub_680DDB(v6); v52 < v41; ++v52 )
                      v9 = sub_6824F1(this, (int)v6, v52, v49, n) + 2111 * v9;
                    v12 = v56++;
                    v36[16] = v9;
                    Block[v12] = v59;
                  }
                }
              }
              else if ( (v7 & 0xFFF00000) != 0x11400000 && v9 != 284164096 && v9 != 286261248 && v9 != 287309824 )
              {
                v10 = v9 == 288358400;
                goto LABEL_21;
              }
            }
          }
        }
      }
      if ( (unsigned int)++v59 >= this[2] )
        goto LABEL_30;
    }
  }
  v2 = -2147024882;
LABEL_89:
  j__free(Block);
  return v2;
}
