int __thiscall sub_69A4A9(void *this, int a2, double *a3)
{
  int v4; // eax
  _DWORD *v5; // eax
  int v6; // esi
  _DWORD *v7; // ebx
  _DWORD *v8; // eax
  int v9; // esi
  int v11; // eax
  int v12; // eax
  int v13; // ebx
  double *v14; // edi
  int v15; // eax
  double *v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // ebx
  double *v20; // edi
  int v21; // ebx
  int v22; // edi
  int v23; // edi
  double *v24; // ebx
  double *v25; // edi
  int v26; // ebx
  double *v27; // edi
  unsigned int v28; // ecx
  unsigned int v29; // eax
  int v30; // ebx
  double *v31; // edi
  int v32; // eax
  double *v33; // eax
  int v34; // ebx
  int v35; // eax
  double *v36; // eax
  double *v37; // edx
  _DWORD *v38; // edx
  unsigned int v39; // eax
  double *v40; // edx
  _DWORD *v41; // edx
  unsigned int v42; // eax
  double *v43; // esi
  long double v44; // st7
  double v45; // st6
  int v46; // eax
  long double v47; // st6
  bool v48; // pf
  bool v49; // zf
  unsigned __int8 v51; // c2
  bool v52; // c3
  int v53; // ebx
  double *v54; // edi
  unsigned int v55; // [esp+18h] [ebp-28h] BYREF
  int v56; // [esp+1Ch] [ebp-24h]
  unsigned int v57; // [esp+20h] [ebp-20h]
  long double v58; // [esp+24h] [ebp-1Ch] BYREF
  long double v59; // [esp+2Ch] [ebp-14h]
  void *Block; // [esp+34h] [ebp-Ch]
  void *v61; // [esp+38h] [ebp-8h]
  int v62; // [esp+3Ch] [ebp-4h]
  unsigned int v63; // [esp+48h] [ebp+8h]
  double *v64; // [esp+48h] [ebp+8h]
  int v65; // [esp+48h] [ebp+8h]

  v62 = (int)this;
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 4) == 13 )
    {
      v63 = *(_DWORD *)(a2 + 20) * *(_DWORD *)(a2 + 24);
      if ( v63 == sub_6958A1(*(_DWORD **)(a2 + 16), (int *)a3) )
      {
        v4 = *(_DWORD *)(a2 + 28);
        if ( v4 < 2 )
          goto LABEL_11;
        if ( v4 > 3 )
        {
          if ( v4 <= 19 )
            goto LABEL_11;
          if ( v4 > 21 && v4 != 25 )
          {
            if ( v4 == 26 )
              return sub_69835C((void *)v62, (_DWORD *)a2, a3);
            if ( v4 != 27 )
            {
LABEL_11:
              v5 = *(_DWORD **)(a2 + 32);
              v6 = 0;
              v7 = 0;
              v55 = 0;
              HIDWORD(v58) = 0;
              v61 = 0;
              Block = 0;
              HIDWORD(v59) = 0;
              v57 = 0;
              if ( v5 )
              {
                if ( v5[1] == 13 )
                {
                  v7 = v5;
                  HIDWORD(v59) = v5[5] * v5[6];
                  v55 = (unsigned int)v5;
                  v61 = operator new(16 * HIDWORD(v59));
                  if ( !v61 )
                    goto LABEL_17;
                }
              }
              v8 = *(_DWORD **)(a2 + 36);
              if ( v8 )
              {
                if ( v8[1] == 13 )
                {
                  v6 = *(_DWORD *)(a2 + 36);
                  v57 = v8[5] * v8[6];
                  HIDWORD(v58) = v6;
                  Block = operator new(16 * v57);
                  if ( !Block )
                  {
LABEL_17:
                    v9 = -2147024882;
LABEL_159:
                    j__free(Block);
                    j__free(v61);
                    return v9;
                  }
                }
              }
              if ( *(_DWORD *)(a2 + 40) )
              {
                if ( v7 )
                {
                  v9 = sub_69A4A9(v7, v61);
                  if ( v9 < 0 )
                    goto LABEL_159;
                  v6 = HIDWORD(v58);
                }
                if ( !v6 )
                {
LABEL_30:
                  v12 = *(_DWORD *)(a2 + 28);
                  if ( v12 < 0 )
                    goto LABEL_104;
                  if ( v12 <= 1 )
                  {
                    if ( v7 )
                    {
                      if ( HIDWORD(v59) == 1 )
                      {
                        v57 = 0;
                        if ( v63 )
                        {
                          v26 = a2 + 48;
                          v27 = a3;
                          do
                          {
                            v9 = sub_697F07(v27, (double *)v61, v26);
                            if ( v9 < 0 )
                              goto LABEL_159;
                            ++v57;
                            v27 += 2;
                          }
                          while ( v57 < v63 );
                        }
                      }
                      else if ( v63 == HIDWORD(v59)
                             || (v28 = *(_DWORD *)(a2 + 20), v28 > v7[5])
                             || (v29 = *(_DWORD *)(a2 + 24), v29 > v7[6]) )
                      {
                        v57 = 0;
                        if ( v63 )
                        {
                          HIDWORD(v58) = a2 + 48;
                          v31 = a3;
                          do
                          {
                            v9 = sub_697F07(v31, (double *)((char *)v31 + (_BYTE *)v61 - (_BYTE *)a3), SHIDWORD(v58));
                            if ( v9 < 0 )
                              goto LABEL_159;
                            ++v57;
                            v31 += 2;
                          }
                          while ( v57 < v63 );
                        }
                      }
                      else
                      {
                        v65 = 0;
                        if ( v28 )
                        {
                          while ( 1 )
                          {
                            v30 = 0;
                            if ( v29 )
                              break;
LABEL_80:
                            if ( (unsigned int)++v65 >= *(_DWORD *)(a2 + 20) )
                              goto LABEL_158;
                          }
                          while ( 1 )
                          {
                            v9 = sub_697F07(
                                   &a3[2 * v30 + 2 * v65 * v29],
                                   (double *)v61 + 2 * v30 + 2 * v65 * *(_DWORD *)(v55 + 24),
                                   a2 + 48);
                            if ( v9 < 0 )
                              goto LABEL_159;
                            v29 = *(_DWORD *)(a2 + 24);
                            if ( ++v30 >= v29 )
                              goto LABEL_80;
                          }
                        }
                      }
                    }
                    else
                    {
                      v32 = *(_DWORD *)(a2 + 32);
                      if ( !v32 )
                        goto LABEL_160;
                      if ( *(_DWORD *)(v32 + 4) != 14 )
                      {
                        if ( *(_DWORD *)(v32 + 4) == 1 )
                        {
                          v34 = *(_DWORD *)(a2 + 32);
                          while ( 1 )
                          {
                            v35 = *(_DWORD *)(v34 + 8);
                            if ( v35 )
                            {
                              if ( *(_DWORD *)(v35 + 4) == 14 )
                              {
                                v36 = (double *)(v35 + 16);
                                if ( *(_DWORD *)v36 == 6 )
                                  goto LABEL_160;
                                v9 = sub_697F07(a3, v36, a2 + 48);
                                if ( v9 < 0 )
                                  goto LABEL_159;
                                a3 += 2;
                              }
                              else if ( *(_DWORD *)(v35 + 4) == 13 )
                              {
                                v9 = sub_69A4A9(v35, a3);
                                if ( v9 < 0 )
                                  goto LABEL_159;
                                a3 += 2
                                    * *(_DWORD *)(*(_DWORD *)(v34 + 8) + 20)
                                    * *(_DWORD *)(*(_DWORD *)(v34 + 8) + 24);
                              }
                            }
                            v34 = *(_DWORD *)(v34 + 12);
                            if ( !v34 )
                              goto LABEL_158;
                          }
                        }
                        goto LABEL_160;
                      }
                      v33 = (double *)(v32 + 16);
                      if ( *(_DWORD *)v33 == 6 )
                      {
LABEL_160:
                        v9 = -2147467259;
                        goto LABEL_159;
                      }
                      v9 = sub_697F07(a3, v33, a2 + 48);
                      if ( v9 < 0 )
                        goto LABEL_159;
                    }
                  }
                  else
                  {
                    switch ( v12 )
                    {
                      case 22:
                        v23 = a2 + 48;
                        HIDWORD(v58) = v23;
                        v9 = sub_698043(&v55, (double *)Block, v23);
                        if ( v9 < 0 )
                          goto LABEL_159;
                        if ( v63 * v55 >= HIDWORD(v59) )
                        {
                          sub_694B97(v62, v23, 3030, "array index out of bounds");
                          goto LABEL_160;
                        }
                        v57 = 0;
                        if ( v63 )
                        {
                          v24 = a3;
                          v25 = (double *)((char *)v61 + 16 * v63 * v55);
                          while ( 1 )
                          {
                            v9 = sub_697F07(v24, v25, SHIDWORD(v58));
                            if ( v9 < 0 )
                              goto LABEL_159;
                            ++v57;
                            v25 += 2;
                            v24 += 2;
                            if ( v57 >= v63 )
                              goto LABEL_158;
                          }
                        }
                        break;
                      case 23:
                        v17 = *(_DWORD *)(a2 + 36);
                        v18 = *(_DWORD *)(v17 + 4);
                        if ( v18 == 14 )
                        {
                          v19 = a2 + 48;
                          v9 = sub_698043(&v55, (double *)(v17 + 16), a2 + 48);
                          if ( v9 < 0 )
                            goto LABEL_159;
                          v57 = 0;
                          if ( v63 )
                          {
                            v20 = (double *)((char *)v61 + 16 * v55);
                            while ( 1 )
                            {
                              v9 = sub_697F07(a3, v20, v19);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              ++v57;
                              a3 += 2;
                              v20 += 2;
                              if ( v57 >= v63 )
                                goto LABEL_158;
                            }
                          }
                        }
                        else
                        {
                          if ( v18 != 1 )
                            goto LABEL_160;
                          v57 = 0;
                          v21 = v17;
                          if ( v63 )
                          {
                            v22 = a2 + 48;
                            while ( 1 )
                            {
                              v9 = sub_698043(&v55, (double *)(*(_DWORD *)(v21 + 8) + 16), v22);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              v9 = sub_697F07(a3, (double *)v61 + 2 * v55, v22);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              ++v57;
                              a3 += 2;
                              v21 = *(_DWORD *)(v21 + 12);
                              if ( v57 >= v63 )
                                goto LABEL_158;
                            }
                          }
                        }
                        break;
                      case 24:
                        v57 = 0;
                        if ( HIDWORD(v59) )
                        {
                          v13 = a2 + 48;
                          v14 = (double *)Block;
                          v64 = (double *)((char *)Block + 16 * v63);
                          v15 = (_BYTE *)v61 - (_BYTE *)Block;
                          v55 = (_BYTE *)v61 - (_BYTE *)Block;
                          v56 = (char *)a3 - (_BYTE *)Block;
                          while ( 1 )
                          {
                            v9 = sub_6959E6(&v58, (double *)((char *)v14 + v15), v13);
                            if ( v9 < 0 )
                              goto LABEL_159;
                            v16 = v14;
                            if ( v58 == 0.0 )
                              v16 = v64;
                            v9 = sub_697F07((double *)((char *)v14 + v56), v16, v13);
                            if ( v9 < 0 )
                              goto LABEL_159;
                            ++v57;
                            v64 += 2;
                            v14 += 2;
                            if ( v57 >= HIDWORD(v59) )
                              goto LABEL_158;
                            v15 = v55;
                          }
                        }
                        break;
                      default:
LABEL_104:
                        v56 = 0;
                        if ( HIDWORD(v59) )
                        {
                          v37 = (double *)v61;
                          do
                          {
                            v9 = sub_6959E6(v37 + 1, v37, a2 + 48);
                            if ( v9 < 0 )
                              goto LABEL_159;
                            v39 = ++v56;
                            *v38 = 3;
                            v37 = (double *)(v38 + 4);
                          }
                          while ( v39 < HIDWORD(v59) );
                        }
                        v56 = 0;
                        if ( v57 )
                        {
                          v40 = (double *)Block;
                          while ( 1 )
                          {
                            v9 = sub_6959E6(v40 + 1, v40, a2 + 48);
                            if ( v9 < 0 )
                              goto LABEL_159;
                            v42 = ++v56;
                            *v41 = 3;
                            v40 = (double *)(v41 + 4);
                            if ( v42 >= v57 )
                            {
                              v7 = (_DWORD *)v55;
                              break;
                            }
                          }
                        }
                        if ( (!v7 || HIDWORD(v59) == v63) && (!HIDWORD(v58) || v57 == v63) )
                        {
                          v57 = 0;
                          if ( v63 )
                          {
                            v55 = (_BYTE *)v61 - (_BYTE *)Block;
                            v43 = (double *)((char *)Block + 8);
                            v56 = (char *)a3 - (_BYTE *)Block;
                            while ( 2 )
                            {
                              if ( v61 )
                                v44 = *(double *)((char *)v43 + v55);
                              else
                                v44 = 0.0;
                              v59 = v44;
                              if ( Block )
                                v45 = *v43;
                              else
                                v45 = 0.0;
                              v46 = *(_DWORD *)(a2 + 28);
                              v58 = v45;
                              switch ( v46 )
                              {
                                case 4:
                                  v47 = 0.0;
                                  goto LABEL_127;
                                case 5:
                                  v44 = -v44;
                                  goto LABEL_153;
                                case 6:
                                  goto LABEL_153;
                                case 7:
                                  v44 = v44 * v58;
                                  goto LABEL_153;
                                case 8:
                                  if ( 0.0 == v58 )
                                  {
                                    sub_694B97(v62, a2 + 48, 3033, "division by zero");
                                    v44 = v59;
                                  }
                                  v44 = v44 / v58;
                                  goto LABEL_153;
                                case 9:
                                  if ( 0.0 == v58 )
                                    sub_694B97(v62, a2 + 48, 3033, "division by zero");
                                  v44 = fmod(v59, v58);
                                  goto LABEL_153;
                                case 10:
                                  v44 = v44 + v58;
                                  goto LABEL_153;
                                case 11:
                                  v44 = v44 - v58;
                                  goto LABEL_153;
                                case 12:
                                  v48 = v44 >= v58;
                                  goto LABEL_128;
                                case 13:
                                  v49 = v44 > v58;
                                  goto LABEL_144;
                                case 14:
                                  v48 = v44 > v58;
                                  goto LABEL_128;
                                case 15:
                                  v49 = v44 >= v58;
LABEL_144:
                                  if ( !v49 )
                                    goto LABEL_129;
                                  goto LABEL_152;
                                case 16:
                                  v47 = v58;
LABEL_127:
                                  v48 = v44 != v47;
LABEL_128:
                                  if ( v48 )
                                    goto LABEL_129;
                                  goto LABEL_152;
                                case 17:
                                  goto LABEL_151;
                                case 18:
                                  if ( v44 != 0.0 )
                                    goto LABEL_150;
                                  goto LABEL_129;
                                case 19:
                                  if ( v44 != 0.0 )
                                    goto LABEL_152;
LABEL_150:
                                  v51 = 0;
                                  v52 = v58 == 0.0;
LABEL_151:
                                  if ( v52 | v51 )
LABEL_129:
                                    v44 = 0.0;
                                  else
LABEL_152:
                                    v44 = 1.0;
LABEL_153:
                                  ++v57;
                                  *(double *)((char *)v43 + v56) = v44;
                                  v43 += 2;
                                  if ( v57 >= v63 )
                                    break;
                                  continue;
                                default:
                                  goto LABEL_160;
                              }
                              break;
                            }
                          }
                          v55 = 0;
                          if ( v63 )
                          {
                            v53 = a2 + 48;
                            v54 = a3;
                            while ( 1 )
                            {
                              v9 = sub_6980A2(v54, v54[1], v53);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              ++v55;
                              v54 += 2;
                              if ( v55 >= v63 )
                                goto LABEL_158;
                            }
                          }
                          break;
                        }
                        goto LABEL_160;
                    }
                  }
LABEL_158:
                  v9 = 0;
                  goto LABEL_159;
                }
                v11 = sub_69A4A9(HIDWORD(v58), Block);
              }
              else
              {
                if ( v6 )
                {
                  v9 = sub_69A4A9(HIDWORD(v58), Block);
                  if ( v9 < 0 )
                    goto LABEL_159;
                }
                if ( !v7 )
                  goto LABEL_30;
                v11 = sub_69A4A9(v7, v61);
              }
              v9 = v11;
              if ( v11 < 0 )
                goto LABEL_159;
              goto LABEL_30;
            }
          }
        }
      }
    }
  }
  return -2147467259;
}
