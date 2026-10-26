int __thiscall sub_68EDC5(int this)
{
  int v2; // eax
  int result; // eax
  void *v4; // eax
  void **v5; // eax
  unsigned int i; // eax
  int *v7; // edi
  int v8; // eax
  int v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // edi
  int v20; // ecx
  _DWORD *v21; // ebx
  int v22; // eax
  int v23; // edi
  int v24; // eax
  _DWORD *v25; // ebx
  int v26; // eax
  unsigned int v27; // [esp+14h] [ebp-38h]
  int v28; // [esp+18h] [ebp-34h]
  _DWORD *v29; // [esp+18h] [ebp-34h]
  int *v30; // [esp+1Ch] [ebp-30h]
  int v31; // [esp+1Ch] [ebp-30h]
  _DWORD *v32; // [esp+20h] [ebp-2Ch]
  unsigned int v33; // [esp+24h] [ebp-28h]
  _DWORD *v34; // [esp+24h] [ebp-28h]
  int v35; // [esp+28h] [ebp-24h]
  int v36; // [esp+28h] [ebp-24h]
  unsigned int v37; // [esp+2Ch] [ebp-20h]
  int v38; // [esp+30h] [ebp-1Ch]
  _DWORD *v39; // [esp+30h] [ebp-1Ch]
  unsigned int v40; // [esp+34h] [ebp-18h]
  unsigned int j; // [esp+38h] [ebp-14h]
  unsigned int k; // [esp+38h] [ebp-14h]
  int v43; // [esp+3Ch] [ebp-10h]
  int v44; // [esp+40h] [ebp-Ch]
  int v45; // [esp+44h] [ebp-8h]
  int v46; // [esp+48h] [ebp-4h]
  int v47; // [esp+48h] [ebp-4h]

  v2 = *(_DWORD *)(this + 204);
  if ( (v2 & 0x100) != 0 || (v2 & 4) != 0 )
    return 1;
  result = sub_688CD8((_DWORD *)this);
  if ( result >= 0 )
  {
    v4 = operator new(0x1FCu);
    if ( v4 )
      v5 = (void **)sub_6B3690(v4);
    else
      v5 = 0;
    *(_DWORD *)(this + 224) = v5;
    if ( v5 )
    {
      result = sub_686CB0(v5, (_DWORD *)this, (void *)0x46580201, (void *)(*(_DWORD *)(this + 204) | 0x100));
      if ( result >= 0 )
      {
        result = sub_682643(*(_DWORD **)(this + 224));
        if ( result >= 0 )
        {
          result = sub_682854((_DWORD *)this);
          if ( result >= 0 )
          {
            for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
            {
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i) + 48) = -1;
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i) + 68) = -1;
            }
            v44 = -1;
            v45 = 0;
            for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
            {
              v7 = *(int **)(*(_DWORD *)(this + 24) + 4 * j);
              v8 = *v7;
              if ( (*v7 & 0xFFF00000) != 0 )
              {
                v9 = v8 & 0xFFFFF;
                v33 = v8 & 0xFFFFF;
                v37 = 0;
                v27 = v7[1] / (v8 & 0xFFFFFu);
                if ( v27 )
                {
                  v43 = 0;
                  do
                  {
                    v46 = 0;
                    if ( v9 )
                    {
                      v10 = (int *)(v43 + v7[2]);
                      v38 = v9;
                      do
                      {
                        if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16)
                                                   + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v10) + 4))
                                       + 4)
                            & 2) != 0
                          && !sub_682608((_DWORD *)this, *v10) )
                        {
                          ++v46;
                        }
                        ++v10;
                        --v38;
                      }
                      while ( v38 );
                      if ( v46 )
                      {
                        if ( v44 == -1 )
                        {
                          v44 = sub_681A51((void *)this, (int)"c", 524881, -1, 4);
                          if ( v44 == -1 )
                            return -2147024882;
                        }
                        v11 = sub_681B0A(*(void **)(this + 224), v46 & 0xFFFFF | 0x10000000, v46, v46);
                        if ( v11 == -1 )
                          return -2147024882;
                        v39 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 224) + 24) + 4 * v11);
                        sub_680D22(v39, (int)v7);
                        v47 = 0;
                        v40 = 0;
                        v12 = v43;
                        do
                        {
                          v30 = (int *)(v12 + v7[2]);
                          v35 = 4 * *v30;
                          v32 = *(_DWORD **)(v35 + *(_DWORD *)(this + 20));
                          v28 = *v30;
                          if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v32[1]) + 4) & 2) != 0
                            && !sub_682608((_DWORD *)this, *v30) )
                          {
                            v13 = v32[18];
                            if ( v13 == -1
                              || (**(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v13) & 0xFFF00000) != 0x10100000 )
                            {
                              v14 = v32[12];
                              if ( v14 == -1 )
                              {
                                v15 = sub_681AAA(
                                        *(void **)(this + 224),
                                        *(_DWORD *)(*(_DWORD *)(this + 224) + 132),
                                        v45,
                                        v47,
                                        0.0);
                                v31 = v15;
                                if ( v15 == -1 )
                                  return -2147024882;
                                v16 = 4 * v47;
                                *(_DWORD *)(v16 + v39[4]) = v15;
                                *(_DWORD *)(v16 + v39[2]) = v28;
                                *(_DWORD *)(v12 + v7[2]) = sub_681AAA((void *)this, v44, v45, v47, 0.0);
                                if ( *(_DWORD *)(v12 + v7[2]) == -1 )
                                  return -2147024882;
                                v17 = *(_DWORD *)(this + 20);
                                v29 = *(_DWORD **)(v17 + 4 * *(_DWORD *)(v12 + v7[2]));
                                sub_681692(v29, *(_DWORD **)(v35 + v17));
                                v29[24] = 0;
                                v29[25] = 0;
                                ++v47;
                                v29[17] = v31;
                                *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + v35) + 48) = *(_DWORD *)(v12 + v7[2]);
                              }
                              else
                              {
                                *v30 = v14;
                              }
                            }
                          }
                          ++v40;
                          v12 += 4;
                        }
                        while ( v40 < v33 );
                        ++v45;
                        *v39 = v47 != 0 ? v47 & 0xFFFFF | 0x10000000 : 0;
                        v39[3] = v47;
                        v39[1] = v47;
                      }
                    }
                    v9 = v33;
                    ++v37;
                    v43 += 4 * v33;
                  }
                  while ( v37 < v27 );
                }
              }
            }
            for ( k = 0; k < *(_DWORD *)(this + 8); ++k )
            {
              v18 = *(_DWORD *)(this + 20);
              v19 = *(_DWORD *)(v18 + 4 * k);
              v20 = *(_DWORD *)(v19 + 8);
              v36 = v19;
              if ( v20 != -1 )
              {
                v21 = *(_DWORD **)(v18 + 4 * v20);
                v34 = v21;
                if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v21[1]) + 4) & 2) != 0
                  && !sub_682608((_DWORD *)this, v20) )
                {
                  if ( v21[12] == -1 )
                  {
                    if ( v44 == -1 )
                    {
                      v44 = sub_681A51((void *)this, (int)"c", 524881, -1, 4);
                      if ( v44 == -1 )
                        return -2147024882;
                    }
                    v22 = sub_681B0A(*(void **)(this + 224), 268435457, 1, 1);
                    if ( v22 == -1 )
                      return -2147024882;
                    v23 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 224) + 24) + 4 * v22);
                    sub_680D22((_DWORD *)v23, *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v21[18]));
                    **(_DWORD **)(v23 + 8) = *(_DWORD *)(v36 + 8);
                    **(_DWORD **)(v23 + 16) = sub_681AAA(
                                                *(void **)(this + 224),
                                                *(_DWORD *)(*(_DWORD *)(this + 224) + 132),
                                                v45,
                                                0,
                                                0.0);
                    if ( **(_DWORD **)(v23 + 16) == -1 )
                      return -2147024882;
                    v24 = sub_681AAA((void *)this, v44, v45, 0, 0.0);
                    v21[12] = v24;
                    if ( v24 == -1 )
                      return -2147024882;
                    v25 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * v24);
                    sub_681692(v25, v34);
                    v26 = **(_DWORD **)(v23 + 16);
                    v25[24] = 0;
                    v25[25] = 0;
                    ++v45;
                    v19 = v36;
                    v25[17] = v26;
                    v21 = v34;
                  }
                  *(_DWORD *)(v19 + 8) = v21[12];
                }
              }
            }
            result = sub_6875A0(*(_DWORD **)(this + 224));
            if ( result >= 0 )
            {
              result = sub_6825A9(*(_DWORD **)(this + 224));
              if ( result >= 0 )
              {
                sub_686074(*(_DWORD *)(this + 224));
                result = sub_6875A0((_DWORD *)this);
                if ( result >= 0 )
                {
                  result = sub_6825A9((_DWORD *)this);
                  if ( result >= 0 )
                  {
                    result = sub_688BDF((_DWORD *)this);
                    if ( result >= 0 )
                      return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      return -2147024882;
    }
  }
  return result;
}
