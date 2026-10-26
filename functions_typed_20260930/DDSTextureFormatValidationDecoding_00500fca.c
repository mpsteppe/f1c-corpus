int __thiscall sub_500FCA(int *this, int a2, unsigned int a3)
{
  int *v3; // esi
  int v5; // edi
  unsigned int v6; // ebx
  int v7; // eax
  unsigned __int16 v8; // dx
  int v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  _BYTE *v17; // eax
  int v18; // ecx
  unsigned int i; // edx
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // ecx
  unsigned int v24; // eax
  bool v25; // zf
  unsigned int v26; // ecx
  char *v27; // edx
  int v28; // eax
  unsigned int v29; // ebx
  int v30; // eax
  int v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // eax
  char *v37; // edi
  char v38; // si
  unsigned int v39; // ecx
  int v40; // eax
  __int16 v41; // di
  unsigned int j; // ecx
  unsigned int v43; // eax
  char *v44; // esi
  char *v45; // edi
  unsigned int v46; // [esp+4h] [ebp-1Ch]
  unsigned int v47; // [esp+4h] [ebp-1Ch]
  unsigned int v48; // [esp+8h] [ebp-18h]
  int v49; // [esp+8h] [ebp-18h]
  unsigned int v51; // [esp+10h] [ebp-10h]
  unsigned int v52; // [esp+14h] [ebp-Ch]
  int v53; // [esp+18h] [ebp-8h]
  unsigned int v54; // [esp+18h] [ebp-8h]
  unsigned int v55; // [esp+1Ch] [ebp-4h]
  unsigned int v56; // [esp+28h] [ebp+8h]
  unsigned int v57; // [esp+28h] [ebp+8h]
  unsigned int v58; // [esp+28h] [ebp+8h]
  int v59; // [esp+2Ch] [ebp+Ch]
  int v60; // [esp+2Ch] [ebp+Ch]
  unsigned int v61; // [esp+2Ch] [ebp+Ch]

  v3 = this;
  if ( a3 < 0x28 )
    return -2147467259;
  v5 = a2;
  v6 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 < 0x28u )
    return -2147467259;
  v55 = *(_DWORD *)(a2 + 4);
  v7 = *(_DWORD *)(a2 + 8);
  if ( v7 <= 0 )
    v7 = -v7;
  v8 = *(_WORD *)(a2 + 14);
  v53 = v7;
  v9 = *(_DWORD *)(a2 + 32);
  if ( v8 <= 8u && !v9 )
    v9 = 1 << v8;
  v48 = v6 + 4 * v9;
  if ( v48 > a3 )
    return -2147467259;
  if ( *(_WORD *)(a2 + 12) != 1 )
    return -2147467259;
  if ( *(int *)(a2 + 8) < 0 )
  {
    v10 = *(_DWORD *)(a2 + 16);
    if ( v10 )
    {
      if ( v10 != 3 )
        return -2147467259;
    }
  }
  v11 = *(_DWORD *)(a2 + 16);
  if ( v11 <= 2 )
  {
    LOBYTE(a2) = *(_WORD *)(a2 + 14);
    if ( v8 == 1 || v8 == 4 || v8 == 8 )
    {
      v60 = 41;
      goto LABEL_80;
    }
    if ( v8 != 16 )
    {
      if ( v8 != 24 )
      {
        if ( v8 != 32 )
          return -2147467259;
        goto LABEL_77;
      }
LABEL_43:
      v60 = 20;
      goto LABEL_80;
    }
LABEL_78:
    v60 = 24;
    goto LABEL_80;
  }
  if ( v11 == 3 )
  {
    if ( v6 >= 0x6C )
    {
      v12 = *(_DWORD *)(a2 + 48);
      v13 = *(_DWORD *)(a2 + 44);
      v14 = *(_DWORD *)(a2 + 40);
      v59 = *(_DWORD *)(a2 + 52);
    }
    else
    {
      v59 = 0;
      v12 = *(_DWORD *)(v6 + a2 + 8);
      v13 = *(_DWORD *)(v6 + a2 + 4);
      v14 = *(_DWORD *)(v6 + a2);
    }
    LOWORD(a2) = *(_WORD *)(a2 + 14);
    if ( (unsigned __int16)a2 != 16 )
    {
      if ( (unsigned __int16)a2 != 24 )
      {
        if ( (unsigned __int16)a2 != 32 )
          return -2147467259;
        if ( v12 != 255 )
        {
          if ( v12 == 1072693248 )
          {
            if ( v13 == 1047552 && v14 == 1023 && v59 == -1073741824 )
            {
              v60 = 31;
              goto LABEL_80;
            }
          }
          else if ( !v12 && v13 == -65536 && v14 == 0xFFFF && !v59 )
          {
            v60 = 34;
            goto LABEL_80;
          }
          return -2147467259;
        }
        if ( v13 != 65280 || v14 != 16711680 )
          return -2147467259;
        if ( v59 )
        {
          if ( v59 == -16777216 )
          {
            v60 = 21;
LABEL_80:
            if ( v3[16] && v60 == 41 )
            {
              v15 = *(_DWORD *)(v5 + 32);
              v46 = v15;
              if ( !v15 )
              {
                v15 = 1 << a2;
                v46 = 1 << a2;
              }
              v3[15] = 1;
              v16 = OperatorNewNhMallocWrapper(1024);
              v3[2] = v16;
              if ( !v16 )
                return -2147024882;
              v56 = 0;
              v17 = (_BYTE *)(v5 + *(_DWORD *)v5);
              if ( v15 )
              {
                do
                {
                  v18 = 4 * v56;
                  *(_BYTE *)(v18 + v3[2]) = v17[2];
                  *(_BYTE *)(v18 + v3[2] + 1) = v17[1];
                  *(_BYTE *)(v18 + v3[2] + 2) = *v17;
                  *(_BYTE *)(v18 + v3[2] + 3) = -1;
                  ++v56;
                  v15 = v46;
                  v17 += 4;
                }
                while ( v56 < v46 );
              }
              for ( i = v15; i < 0x100; ++i )
              {
                v20 = 4 * i;
                *(_BYTE *)(v20 + v3[2]) = -1;
                *(_BYTE *)(v20 + v3[2] + 1) = -1;
                *(_BYTE *)(v20 + v3[2] + 2) = -1;
                *(_BYTE *)(v20 + v3[2] + 3) = -1;
              }
            }
            if ( *(_WORD *)(v5 + 14) == 1 )
            {
              v23 = (v55 + 7) >> 3;
            }
            else
            {
              if ( *(_WORD *)(v5 + 14) != 4 )
              {
                v21 = v55 * (*(unsigned __int16 *)(v5 + 14) >> 3);
                v22 = v21 + 3;
LABEL_96:
                v52 = v22 & 0xFFFFFFFC;
                v47 = v21;
                *v3 = v60;
                v24 = (v21 + 3) & 0xFFFFFFFC;
                v25 = v3[16] == 0;
                v3[3] = v55;
                v3[12] = v24;
                v3[13] = 0;
                v3[4] = v53;
                v3[5] = 1;
                if ( v25 )
                  return 0;
                if ( *(int *)(v5 + 8) < 0 && *(_WORD *)(v5 + 14) >= 8u )
                {
                  v3[14] = 0;
                  v3[1] = v5 + v48;
                  return 0;
                }
                v3[14] = 1;
                v26 = OperatorNewNhMallocWrapper(v53 * v24);
                v61 = v26;
                v3[1] = v26;
                if ( !v26 )
                  return -2147024882;
                v27 = (char *)(v48 + v5);
                v28 = v3[12];
                if ( *(int *)(v5 + 8) >= 0 )
                {
                  v49 = -v28;
                  v29 = v26 + v28 * (v53 - 1);
                }
                else
                {
                  v49 = v3[12];
                  v29 = v26;
                }
                v54 = v26 + v53 * v28;
                v30 = *(_DWORD *)(v5 + 16);
                v57 = v29;
                v51 = v29;
                if ( v30 == 2 )
                {
                  if ( v29 >= v26 )
                  {
                    do
                    {
                      if ( *v27 )
                      {
                        v34 = 0;
                        do
                        {
                          if ( (v34 & 1) != 0 )
                            LOBYTE(v35) = v27[1] & 0xF;
                          else
                            v35 = (unsigned __int8)v27[1] >> 4;
                          *(_BYTE *)(v34 + v29) = v35;
                          ++v34;
                        }
                        while ( v34 < (unsigned __int8)*v27 );
                        v3 = this;
                        v29 += (unsigned __int8)*v27;
                      }
                      else if ( v27[1] )
                      {
                        if ( v27[1] == 1 )
                        {
                          v29 = v61 - v3[12];
                        }
                        else if ( v27[1] == 2 )
                        {
                          v29 += (unsigned __int8)v27[2] - v3[12] * (unsigned __int8)v27[3];
                          v27 += 2;
                        }
                        else
                        {
                          v31 = 0;
                          if ( v27[1] )
                          {
                            do
                            {
                              v32 = (unsigned __int8)v27[(v31 >> 1) + 2];
                              if ( (v31 & 1) != 0 )
                                LOBYTE(v32) = v32 & 0xF;
                              else
                                v32 >>= 4;
                              *(_BYTE *)(v31 + v29) = v32;
                              ++v31;
                            }
                            while ( v31 < (unsigned __int8)v27[1] );
                            v3 = this;
                          }
                          v33 = (unsigned __int8)v27[1];
                          v29 += v33;
                          v27 += ((v33 >> 1) + 1) & 0xFFFFFFFE;
                        }
                      }
                      else
                      {
                        v29 = v51 - v3[12];
                        v51 = v29;
                      }
                      v27 += 2;
                    }
                    while ( v29 >= v61 );
                  }
                  return 0;
                }
                if ( v30 != 1 )
                {
                  v41 = *(_WORD *)(v5 + 14);
                  if ( v41 == 1 )
                  {
                    while ( v29 >= v26 && v29 < v54 )
                    {
                      v58 = 0;
                      if ( v55 )
                      {
                        do
                        {
                          *(_BYTE *)(v58 + v29) = ((unsigned __int8)v27[v58 >> 3] >> (7 - (v58 & 7))) & 1;
                          ++v58;
                        }
                        while ( v58 < v55 );
                        v26 = v61;
                      }
                      v29 += v49;
                      v27 += v52;
                    }
                  }
                  else if ( v41 == 4 )
                  {
                    if ( v29 >= v26 )
                    {
                      do
                      {
                        if ( v29 >= v54 )
                          break;
                        for ( j = 0; j < v55; ++j )
                        {
                          v43 = (unsigned __int8)v27[j >> 1];
                          if ( (j & 1) != 0 )
                            LOBYTE(v43) = v43 & 0xF;
                          else
                            v43 >>= 4;
                          *(_BYTE *)(j + v29) = v43;
                        }
                        v29 += v49;
                        v27 += v52;
                      }
                      while ( v29 >= v61 );
                    }
                  }
                  else
                  {
                    while ( v29 >= v26 )
                    {
                      if ( v29 >= v54 )
                        break;
                      v44 = v27;
                      v27 += v52;
                      v45 = (char *)v29;
                      v29 += v49;
                      qmemcpy(v45, v44, v47);
                    }
                  }
                  return 0;
                }
                if ( v29 < v26 )
                  return 0;
                while ( !*v27 )
                {
                  if ( v27[1] )
                  {
                    if ( v27[1] == 1 )
                    {
                      v29 = v61 - v3[12];
                    }
                    else
                    {
                      if ( v27[1] != 2 )
                      {
                        qmemcpy((void *)v29, v27 + 2, (unsigned __int8)v27[1]);
                        v36 = (unsigned __int8)v27[1];
                        v29 += v36;
                        v27 += (v36 + 1) & 0xFFFFFFFE;
LABEL_140:
                        v3 = this;
                        goto LABEL_141;
                      }
                      v29 += (unsigned __int8)v27[2] - v3[12] * (unsigned __int8)v27[3];
                      v27 += 2;
                    }
                  }
                  else
                  {
                    v29 = v51 - v3[12];
                    v51 = v29;
                  }
LABEL_141:
                  v27 += 2;
                  v57 = v29;
                  if ( v29 < v61 )
                    return 0;
                }
                v37 = (char *)v29;
                LOBYTE(v29) = v27[1];
                BYTE1(v29) = v29;
                v38 = *v27;
                v39 = (unsigned __int8)*v27 >> 2;
                v40 = v29 << 16;
                LOWORD(v40) = v29;
                memset32(v37, v40, v39);
                memset(&v37[4 * v39], v29, v38 & 3);
                v29 = (unsigned __int8)*v27 + v57;
                goto LABEL_140;
              }
              v23 = (v55 + 1) >> 1;
            }
            v21 = v55;
            v22 = v23 + 3;
            goto LABEL_96;
          }
          return -2147467259;
        }
LABEL_77:
        v60 = 22;
        goto LABEL_80;
      }
      if ( v12 != 255 || v13 != 65280 || v14 != 16711680 || v59 )
        return -2147467259;
      goto LABEL_43;
    }
    if ( v12 == 255 )
    {
      if ( v13 == 255 && v14 == 255 && v59 == 65280 )
      {
        v60 = 51;
        goto LABEL_80;
      }
      return -2147467259;
    }
    if ( v12 != 31 )
    {
      if ( v12 == 15 )
      {
        if ( v13 == 240 && v14 == 3840 )
        {
          if ( v59 == 61440 )
          {
            v60 = 26;
            goto LABEL_80;
          }
          if ( !v59 )
          {
            v60 = 30;
            goto LABEL_80;
          }
        }
      }
      else if ( v12 == 3 && v13 == 28 && v14 == 224 && v59 == 65280 )
      {
        v60 = 29;
        goto LABEL_80;
      }
      return -2147467259;
    }
    if ( v13 == 2016 )
    {
      if ( v14 == 63488 && !v59 )
      {
        v60 = 23;
        goto LABEL_80;
      }
      return -2147467259;
    }
    if ( v13 != 992 || v14 != 31744 )
      return -2147467259;
    if ( v59 )
    {
      if ( v59 == 0x8000 )
      {
        v60 = 25;
        goto LABEL_80;
      }
      return -2147467259;
    }
    goto LABEL_78;
  }
  return -2147467263;
}

