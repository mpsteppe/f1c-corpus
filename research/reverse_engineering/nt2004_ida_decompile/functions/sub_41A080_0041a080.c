void __thiscall sub_41A080(int this)
{
  double v2; // st7
  bool v3; // dl
  bool v4; // cl
  int v5; // esi
  bool v6; // bl
  char v7; // al
  int v8; // esi
  int v9; // eax
  int v10; // eax
  float v11; // eax
  float v12; // ecx
  int v13; // ebp
  float *v14; // edi
  signed int v15; // esi
  float *v16; // ebx
  int v17; // edx
  int v18; // ecx
  double v19; // st7
  float *v20; // edx
  double v21; // st7
  int v22; // eax
  double v23; // st7
  double v24; // st6
  double v25; // st5
  int v26; // esi
  int v27; // ecx
  char v28; // dl
  double v29; // st7
  int v30; // eax
  int v31; // ebx
  int v32; // ebp
  float *v33; // edi
  signed int v34; // esi
  float *v35; // ebx
  int v36; // edx
  int v37; // ecx
  double v38; // st7
  float *v39; // edx
  double v40; // st7
  int v41; // eax
  double v42; // st7
  double v43; // st6
  double v44; // st5
  int v45; // esi
  int v46; // ecx
  char v47; // dl
  double v48; // st7
  int v49; // eax
  int v50; // ebx
  int v51; // ebx
  unsigned __int8 v52; // [esp+12h] [ebp-4Eh]
  unsigned __int8 v53; // [esp+12h] [ebp-4Eh]
  char v54; // [esp+13h] [ebp-4Dh]
  char v55; // [esp+13h] [ebp-4Dh]
  int v57; // [esp+18h] [ebp-48h]
  int *v58; // [esp+1Ch] [ebp-44h]
  int *v59; // [esp+1Ch] [ebp-44h]
  char v60; // [esp+20h] [ebp-40h]
  int v61; // [esp+20h] [ebp-40h]
  int v62; // [esp+24h] [ebp-3Ch] BYREF
  float v63; // [esp+28h] [ebp-38h]
  float v64; // [esp+2Ch] [ebp-34h]
  int v65; // [esp+30h] [ebp-30h] BYREF
  _DWORD v66[3]; // [esp+34h] [ebp-2Ch] BYREF
  int v67; // [esp+40h] [ebp-20h] BYREF
  _DWORD v68[2]; // [esp+44h] [ebp-1Ch]
  _DWORD v69[5]; // [esp+4Ch] [ebp-14h]

  if ( !dword_7688A0 || flt_7678BC == 0.0 || !byte_6292D8 || sub_4633A0(&unk_764D70) == 1 )
    return;
  v2 = sub_51C7A0(dword_75AACC + 84);
  v63 = v2;
  v64 = *(float *)&dword_5FC88C;
  sub_501380(v63, (int)&v62);
  *(float *)&dword_5FC88C = v2;
  if ( v2 < 0.25 || (v54 = 1, v64 >= 0.25) )
    v54 = 0;
  v3 = *(float *)&dword_5FC88C >= 0.5 && v64 < 0.5;
  v4 = *(float *)&dword_5FC88C >= 0.75 && v64 < 0.75;
  v5 = *(_DWORD *)(this + 2580);
  v6 = v62 != v5;
  if ( v62 == v5 )
  {
    if ( !v54 && !v3 )
    {
      v55 = 0;
      if ( !v4 )
        goto LABEL_22;
    }
  }
  else
  {
    *(_DWORD *)(this + 2580) = v62;
  }
  v55 = 1;
LABEL_22:
  if ( dword_75CBB0 == 5
    && (unsigned __int8)sub_42DBA0(&unk_62BF64)
    && dword_75AACC
    && (dword_7D7928 == 1 || dword_7D7928 == 2 || !dword_7D7928)
    && v6 )
  {
    if ( v62 != 5 )
      goto LABEL_35;
    if ( v5 != 4 )
      return;
    if ( *(_DWORD *)((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC + 0x5170 : 20848) )
    {
LABEL_35:
      if ( !v62
        && v5 == 5
        && *(_DWORD *)((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC + 0x5170 : 20848) == 2
        && dword_7D74B8 == 3 )
      {
        sub_4194D0(16);
      }
    }
    else
    {
      sub_4194D0(2);
    }
    return;
  }
  if ( dword_75CBB0 != 7 )
    return;
  if ( !dword_7D7540 )
    goto LABEL_62;
  v7 = sub_42DBA0(&unk_62BF64);
  if ( !(unsigned __int8)sub_4DEB10(v7 != 0 ? dword_75AACC + 20836 : 20836) && v62 == 5 && v5 == 4 )
  {
    if ( *(_DWORD *)((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC + 0x5194 : 20884) == 1
      || (v8 = *(_DWORD *)((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC + 0x5170 : 20848),
          v8 == dword_6310D8[6326 * sub_4FA870(0)])
      || (v9 = sub_4FA870(0), (unsigned __int8)sub_4DEB10((char *)&unk_6310CC + 25304 * v9) == 1) )
    {
      sub_419480(64);
      return;
    }
  }
  if ( dword_75CBB0 == 7 )
  {
LABEL_62:
    if ( dword_75CBB4 == 5 )
    {
      if ( (unsigned __int8)sub_42DBA0(&unk_62BF64) )
      {
        if ( dword_75AACC )
        {
          if ( !*(_DWORD *)(dword_75AACC + 20892) )
          {
            v10 = *(_DWORD *)(dword_75AACC + 20896);
            if ( (!v10 || v10 == 4)
              && *(_BYTE *)((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC + 0x4404 : 17412) != 1
              && (unsigned int)dword_7D7540 <= 1
              && dword_7D5DA4 != 2
              && flt_7D74BC > 0.0
              && dbl_7DA9D0 - flt_7D74BC > 15.0
              && (unsigned int)dword_7D7928 <= 2
              && (v55 || *(_DWORD *)(this + 2588) != -1 || *(_DWORD *)(this + 2584) != -1) )
            {
              v11 = *(float *)(this + 2588);
              v12 = *(float *)(this + 2584);
              v68[0] = -1;
              v68[1] = -1;
              v69[0] = -1;
              memset(v66, 255, sizeof(v66));
              v64 = v11;
              v63 = v12;
              if ( v11 != NAN || (v60 = 0, v12 != NAN) )
                v60 = 1;
              sub_419FE0((float *)this, v60);
              *(_DWORD *)(this + 2588) = -1;
              *(_DWORD *)(this + 2584) = -1;
              v65 = *(_DWORD *)(dword_75AACC + 25248);
              v67 = v65;
              v57 = 1;
              v61 = 1;
              v13 = 0;
              v58 = &v67;
              do
              {
                if ( *v58 < 0 )
                  break;
                v14 = *(float **)(dword_75AAD0[*v58] + 19084);
                if ( !v14 )
                  break;
                v15 = 0;
                v52 = 0;
                if ( (int)NumOfElements <= 0 )
                  break;
                v16 = (float *)(this + 592);
                do
                {
                  v17 = *v58;
                  if ( v15 != *v58 )
                  {
                    v18 = dword_75AAD0[v15];
                    v19 = *(_DWORD *)(v18 + 25256) == LODWORD(v63) ? 6.0 : 4.0;
                    if ( fabs(*v16 - *(float *)(this + 4 * v17 + 592)) < v19 )
                    {
                      v20 = (float *)dword_75AAD0[v17];
                      v21 = v20[4407] * v20[4407] + v20[4408] * v20[4408] + v20[4409] * v20[4409];
                      if ( fabs(
                             v21
                           - (*(float *)(v18 + 17628) * *(float *)(v18 + 17628)
                            + *(float *)(v18 + 17632) * *(float *)(v18 + 17632)
                            + *(float *)(v18 + 17636) * *(float *)(v18 + 17636)))
                         / v21 <= 0.2 )
                      {
                        v22 = 0;
                        if ( v13 > 0 )
                        {
                          while ( v68[v22 - 1] != v15 )
                          {
                            if ( ++v22 >= v13 )
                              goto LABEL_80;
                          }
                          goto LABEL_82;
                        }
LABEL_80:
                        v23 = *(float *)(v18 + 17604) - v20[4401];
                        v24 = *(float *)(v18 + 17608) - v20[4402];
                        v25 = *(float *)(v18 + 17612) - v20[4403];
                        if ( v25 * v14[13] + v24 * v14[12] + v23 * v14[11] > 0.0 )
                        {
                          ++v52;
                          v68[v61++ - 1] = v15;
                          *(float *)&v69[v61] = v25 * v25 + v24 * v24 + v23 * v23;
                          if ( v61 >= 4 )
                            break;
                        }
                      }
                    }
                  }
LABEL_82:
                  ++v15;
                  ++v16;
                }
                while ( v15 < (int)NumOfElements );
                if ( !v52 )
                  break;
                if ( v52 <= 1u )
                  goto LABEL_93;
                v26 = v61 - 1;
                do
                {
                  v27 = v13 + 1;
                  v28 = 1;
                  if ( v13 + 1 >= v26 )
                    break;
                  do
                  {
                    if ( *(float *)&v69[v27 + 1] > (double)*(float *)&v69[v27 + 2] )
                    {
                      v29 = *(float *)&v69[v27 + 1];
                      v30 = v68[v27 - 1];
                      v68[v27 - 1] = v68[v27];
                      v31 = v69[v27 + 2];
                      *(float *)&v69[v27 + 2] = v29;
                      v28 = 0;
                      v69[v27 + 1] = v31;
                      v68[v27] = v30;
                    }
                    ++v27;
                  }
                  while ( v27 < v26 );
                }
                while ( !v28 );
                if ( v13 >= 2 )
                  break;
                v58[2] = -1;
                v61 = v13 + 1;
LABEL_93:
                ++v13;
                ++v58;
              }
              while ( v13 < 3 );
              v32 = 0;
              v59 = &v65;
LABEL_95:
              if ( *v59 < 0 )
                goto LABEL_122;
              v33 = *(float **)(dword_75AAD0[*v59] + 19084);
              if ( !v33 )
                goto LABEL_122;
              v34 = 0;
              v53 = 0;
              if ( (int)NumOfElements <= 0 )
                goto LABEL_122;
              v35 = (float *)(this + 592);
              while ( 1 )
              {
                v36 = *v59;
                if ( v34 != *v59 )
                {
                  v37 = dword_75AAD0[v34];
                  v38 = *(_DWORD *)(v37 + 25256) == LODWORD(v64) ? 6.0 : 4.0;
                  if ( fabs(*v35 - *(float *)(this + 4 * v36 + 592)) < v38 )
                  {
                    v39 = (float *)dword_75AAD0[v36];
                    v40 = v39[4407] * v39[4407] + v39[4408] * v39[4408] + v39[4409] * v39[4409];
                    if ( fabs(
                           v40
                         - (*(float *)(v37 + 17628) * *(float *)(v37 + 17628)
                          + *(float *)(v37 + 17632) * *(float *)(v37 + 17632)
                          + *(float *)(v37 + 17636) * *(float *)(v37 + 17636)))
                       / v40 <= 0.2 )
                    {
                      v41 = 0;
                      if ( v32 <= 0 )
                      {
LABEL_108:
                        v42 = *(float *)(v37 + 17604) - v39[4401];
                        v43 = *(float *)(v37 + 17608) - v39[4402];
                        v44 = *(float *)(v37 + 17612) - v39[4403];
                        if ( v44 * v33[13] + v43 * v33[12] + v42 * v33[11] < 0.0 )
                        {
                          ++v53;
                          v66[v57++ - 1] = v34;
                          *(float *)&v69[v57] = v44 * v44 + v43 * v43 + v42 * v42;
                          if ( v57 >= 4 )
                          {
LABEL_111:
                            if ( !v53 )
                              goto LABEL_122;
                            if ( v53 <= 1u )
                              goto LABEL_121;
                            v45 = v57 - 1;
                            do
                            {
                              v46 = v32 + 1;
                              v47 = 1;
                              if ( v32 + 1 >= v45 )
                                break;
                              do
                              {
                                if ( *(float *)&v69[v46 + 1] > (double)*(float *)&v69[v46 + 2] )
                                {
                                  v48 = *(float *)&v69[v46 + 1];
                                  v49 = v66[v46 - 1];
                                  v66[v46 - 1] = v66[v46];
                                  v50 = v69[v46 + 2];
                                  *(float *)&v69[v46 + 2] = v48;
                                  v47 = 0;
                                  v69[v46 + 1] = v50;
                                  v66[v46] = v49;
                                }
                                ++v46;
                              }
                              while ( v46 < v45 );
                            }
                            while ( !v47 );
                            if ( v32 >= 2 )
                              goto LABEL_122;
                            v59[2] = -1;
                            v57 = v32 + 1;
LABEL_121:
                            ++v32;
                            ++v59;
                            if ( v32 >= 3 )
                            {
LABEL_122:
                              v51 = -1;
                              if ( v57 + v61 - 1 > 1 )
                              {
                                if ( v66[0] != -1 )
                                  *(_DWORD *)(this + 2588) = *(_DWORD *)(dword_75AAD0[v66[0]] + 25256);
                                if ( v68[0] != -1 )
                                  *(_DWORD *)(this + 2584) = *(_DWORD *)(dword_75AAD0[v68[0]] + 25256);
                                if ( v55 )
                                {
                                  if ( v57 + v61 != 3 )
                                    goto LABEL_139;
                                  if ( v61 > 1 )
                                  {
                                    v51 = *(_DWORD *)(this + 2584);
                                    if ( v51 != LODWORD(v63) || v64 != NAN )
                                    {
                                      switch ( *(_DWORD *)(this + 2580) )
                                      {
                                        case 0:
                                        case 1:
                                        case 2:
                                        case 3:
                                        case 4:
                                        case 5:
                                          goto LABEL_139;
                                        default:
                                          return;
                                      }
                                      return;
                                    }
                                  }
                                  else
                                  {
                                    v51 = *(_DWORD *)(this + 2588);
                                    if ( v51 != LODWORD(v64) || v63 != NAN )
                                    {
                                      switch ( *(_DWORD *)(this + 2580) )
                                      {
                                        case 0:
                                        case 1:
                                        case 2:
                                        case 3:
                                        case 4:
                                        case 5:
                                          goto LABEL_139;
                                        default:
                                          return;
                                      }
                                      return;
                                    }
                                  }
LABEL_139:
                                  sub_58DAB0();
                                  sub_4194A0(v51);
                                  return;
                                }
                              }
                              else if ( v64 != NAN || v63 != NAN )
                              {
                                goto LABEL_139;
                              }
                              return;
                            }
                            goto LABEL_95;
                          }
                        }
                      }
                      else
                      {
                        while ( v66[v41 - 1] != v34 )
                        {
                          if ( ++v41 >= v32 )
                            goto LABEL_108;
                        }
                      }
                    }
                  }
                }
                ++v34;
                ++v35;
                if ( v34 >= (int)NumOfElements )
                  goto LABEL_111;
              }
            }
          }
        }
      }
    }
  }
}
