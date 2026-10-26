int __thiscall sub_64F345(int this, unsigned int a2, unsigned int a3, int a4)
{
  int result; // eax
  unsigned int v6; // eax
  float *v7; // ebx
  int v8; // ecx
  unsigned __int16 *v9; // esi
  int v10; // ecx
  __int16 v11; // cx
  double v12; // st4
  double v13; // st3
  unsigned __int16 v14; // ax
  double v15; // st5
  unsigned __int16 v16; // ax
  double v17; // st5
  double v18; // st4
  double v19; // st4
  __int16 v20; // cx
  int v21; // ecx
  signed int v22; // eax
  bool v23; // sf
  double v24; // st3
  double v25; // st2
  double v26; // st4
  double v27; // st3
  double v28; // st3
  float v29; // [esp+4h] [ebp-Ch]
  float v30; // [esp+4h] [ebp-Ch]
  int v31; // [esp+8h] [ebp-8h]
  int v32; // [esp+Ch] [ebp-4h]
  float v33; // [esp+Ch] [ebp-4h]
  unsigned __int16 v34; // [esp+18h] [ebp+8h]
  int v35; // [esp+18h] [ebp+8h]
  float v36; // [esp+18h] [ebp+8h]
  float *v37; // [esp+1Ch] [ebp+Ch]
  unsigned int v38; // [esp+1Ch] [ebp+Ch]
  float v39; // [esp+1Ch] [ebp+Ch]
  unsigned int v40; // [esp+20h] [ebp+10h]
  int v41; // [esp+20h] [ebp+10h]

  if ( !*(_DWORD *)(this + 164) )
    return -2147024882;
  if ( a2 < *(_DWORD *)(this + 136)
    || a2 >= *(_DWORD *)(this + 144)
    || a3 < *(_DWORD *)(this + 148)
    || a3 >= *(_DWORD *)(this + 152) )
  {
    result = sub_64F042((_DWORD *)this);
    if ( result < 0 )
      return result;
    *(_DWORD *)(this + 144) = a2 + 1;
    *(_DWORD *)(this + 136) = a2;
    *(_DWORD *)(this + 148) = a3;
    *(_DWORD *)(this + 152) = a3 + 1;
    if ( a4 )
    {
      v6 = *(_DWORD *)(this + 132);
      v7 = *(float **)(this + 128);
      v8 = *(_DWORD *)(this + 104);
      v9 = (unsigned __int16 *)(*(_DWORD *)(this + 32)
                              + a3 * *(_DWORD *)(this + 100)
                              + a2 * *(_DWORD *)(this + 96)
                              + 2 * v6);
      v37 = v7;
      if ( (v8 & 1) != 0 )
        ++v8;
      v32 = v8;
      v10 = *(_DWORD *)(this + 4);
      switch ( v10 )
      {
        case 844715353:
LABEL_15:
          v40 = *(_DWORD *)(this + 132);
          if ( v6 < *(_DWORD *)(this + 140) )
          {
            while ( 1 )
            {
              v34 = *v9;
              if ( (v40 & 1) != 0 )
              {
                if ( (v40 & 1) == 1 && v32 == 2 )
                {
                  v20 = *(_WORD *)(this + 172);
                  v12 = (double)(unsigned __int8)(*(v9 - 1) >> v20) - 128.0;
                  v13 = (double)(unsigned __int8)(v34 >> v20);
                }
                else
                {
                  if ( v40 != 1 || v32 != 4 )
                  {
                    if ( v40 == v32 - 1 )
                    {
                      v12 = (double)((17 * (unsigned __int8)(*(v9 - 1) >> *(_WORD *)(this + 172))
                                    - (unsigned int)(unsigned __int8)(*(v9 - 3) >> *(_WORD *)(this + 172))
                                    + 8) >> 4)
                          - 128.0;
                      v22 = (17 * (unsigned __int8)(v34 >> *(_WORD *)(this + 172))
                           - (unsigned int)(unsigned __int8)(*(v9 - 2) >> *(_WORD *)(this + 172))
                           + 8) >> 4;
                      v13 = (double)v22;
                      goto LABEL_34;
                    }
                    if ( v40 == 1 )
                    {
                      v12 = (double)((9
                                    * ((unsigned __int8)(*(v9 - 1) >> *(_WORD *)(this + 172))
                                     + (unsigned __int8)(v9[1] >> *(_WORD *)(this + 172)))
                                    - (unsigned __int8)(v9[3] >> *(_WORD *)(this + 172))
                                    - (unsigned int)(unsigned __int8)(*(v9 - 1) >> *(_WORD *)(this + 172))
                                    + 8) >> 4)
                          - 128.0;
                      v22 = (9
                           * ((unsigned __int8)(v34 >> *(_WORD *)(this + 172))
                            + (unsigned __int8)(v9[2] >> *(_WORD *)(this + 172)))
                           - (unsigned __int8)(v9[4] >> *(_WORD *)(this + 172))
                           - (unsigned int)(unsigned __int8)(v34 >> *(_WORD *)(this + 172))
                           + 8) >> 4;
                      v13 = (double)v22;
                      goto LABEL_34;
                    }
                    if ( v40 == v32 - 3 )
                    {
                      v12 = (double)((9
                                    * ((unsigned __int8)(v9[1] >> *(_WORD *)(this + 172))
                                     + (unsigned __int8)(*(v9 - 1) >> *(_WORD *)(this + 172)))
                                    - (unsigned __int8)(*(v9 - 3) >> *(_WORD *)(this + 172))
                                    - (unsigned int)(unsigned __int8)(v9[1] >> *(_WORD *)(this + 172))
                                    + 8) >> 4)
                          - 128.0;
                      v13 = (double)((9 * (unsigned __int8)(v34 >> *(_WORD *)(this + 172))
                                    + 8 * (unsigned __int8)(v9[2] >> *(_WORD *)(this + 172))
                                    + 8
                                    - (unsigned int)(unsigned __int8)(*(v9 - 2) >> *(_WORD *)(this + 172))) >> 4);
                      v23 = 0;
                    }
                    else
                    {
                      v12 = (double)((9
                                    * ((unsigned __int8)(v9[1] >> *(_WORD *)(this + 172))
                                     + (unsigned __int8)(*(v9 - 1) >> *(_WORD *)(this + 172)))
                                    - (unsigned __int8)(*(v9 - 3) >> *(_WORD *)(this + 172))
                                    - (unsigned int)(unsigned __int8)(v9[3] >> *(_WORD *)(this + 172))
                                    + 8) >> 4)
                          - 128.0;
                      v22 = (9
                           * ((unsigned __int8)(v34 >> *(_WORD *)(this + 172))
                            + (unsigned __int8)(v9[2] >> *(_WORD *)(this + 172)))
                           - (unsigned __int8)(v9[4] >> *(_WORD *)(this + 172))
                           - (unsigned int)(unsigned __int8)(*(v9 - 2) >> *(_WORD *)(this + 172))
                           + 8) >> 4;
                      v13 = (double)v22;
LABEL_34:
                      v23 = v22 < 0;
                    }
                    if ( v23 )
                      v13 = v13 + 4294967300.0;
                    v7 = v37;
                    goto LABEL_38;
                  }
                  v21 = (unsigned __int8)(*(v9 - 1) >> *(_WORD *)(this + 172));
                  v31 = (unsigned __int8)(v9[1] >> *(_WORD *)(this + 172));
                  v12 = (double)((unsigned int)(9 * (v21 + v31) - v21 - v31 + 8) >> 4) - 128.0;
                  v35 = (unsigned __int8)(v34 >> *(_WORD *)(this + 172));
                  v13 = (double)((9 * v35
                                + 8 * (unsigned int)(unsigned __int8)(v9[2] >> *(_WORD *)(this + 172))
                                - v35
                                + 8) >> 4);
                }
              }
              else
              {
                v11 = *(_WORD *)(this + 172);
                v12 = (double)(unsigned __int8)(v34 >> v11) - 128.0;
                v13 = (double)(unsigned __int8)(v9[1] >> v11);
              }
LABEL_38:
              v24 = v13 - 128.0;
              v29 = (double)(unsigned __int8)(*v9 >> *(_WORD *)(this + 168)) - 16.0;
              v25 = v29 * 0.0045662099;
              v30 = v25;
              v36 = v24 * 0.0062589301 + v25;
              *v7 = v36;
              v39 = v25 - v12 * 0.00153632 - v24 * 0.00318811;
              v7[1] = v39;
              v26 = v12 * 0.0079107098 + v30;
              v7[2] = v26;
              v7[3] = 1.0;
              if ( v36 >= 0.0 )
              {
                if ( v36 <= 1.0 )
                  v27 = v36;
                else
                  v27 = 1.0;
              }
              else
              {
                v27 = 0.0;
              }
              *v7 = v27;
              if ( v39 >= 0.0 )
              {
                if ( v39 <= 1.0 )
                  v28 = v39;
                else
                  v28 = 1.0;
              }
              else
              {
                v28 = 0.0;
              }
              v7[1] = v28;
              if ( v26 >= 0.0 )
              {
                if ( v26 > 1.0 )
                  v26 = 1.0;
              }
              else
              {
                v26 = 0.0;
              }
              v7 += 4;
              *(v7 - 2) = v26;
              ++v9;
              ++v40;
              v37 = v7;
              if ( v40 >= *(_DWORD *)(this + 140) )
                return 0;
            }
          }
          return 0;
        case 1111970375:
        case 1195525970:
          v38 = *(_DWORD *)(this + 132);
          if ( v6 < *(_DWORD *)(this + 140) )
          {
            do
            {
              v14 = *v9;
              v38 += 2;
              v9 += 2;
              v41 = (unsigned __int8)(v14 >> *(_WORD *)(this + 168));
              v15 = (double)(unsigned __int8)(v14 >> *(_WORD *)(this + 172));
              v16 = *(v9 - 1);
              v17 = v15 * 0.0039215689;
              v33 = (double)(unsigned __int8)(v16 >> *(_WORD *)(this + 168)) * 0.0039215689;
              v18 = (double)(unsigned __int8)(v16 >> *(_WORD *)(this + 172));
              v7[5] = v33;
              v19 = v18 * 0.0039215689;
              *v7 = v17;
              v7 += 8;
              *(v7 - 7) = (double)v41 * 0.0039215689;
              *(v7 - 6) = v19;
              *(v7 - 5) = 1.0;
              *(v7 - 4) = v17;
              *(v7 - 2) = v19;
              *(v7 - 1) = 1.0;
            }
            while ( v38 < *(_DWORD *)(this + 140) );
          }
          break;
        case 1498831189:
          goto LABEL_15;
      }
    }
  }
  return 0;
}
