int __thiscall sub_453D00(int this)
{
  char v2; // al
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  long double v19; // st7
  double v20; // st7
  int i; // edx
  int v22; // ecx
  int v23; // ecx
  char v24; // bl
  int v25; // ecx
  int v26; // ebp
  int v27; // edx
  int v28; // edi
  long double v29; // st7
  char v30; // cl
  double v31; // st7
  double v32; // st7
  double v33; // st6
  double v34; // st7
  double v35; // st7
  double v36; // st7
  char v37; // bl
  double v38; // st7
  double v39; // st6
  double v41; // st7
  unsigned __int8 v42; // c0
  unsigned __int8 v43; // c2
  int v44; // edi
  __int64 v45; // rax
  __int64 v46; // rax
  int v47; // edi
  __int64 v48; // rax
  __int64 v49; // rax
  int v50; // ecx
  int v51; // edi
  __int64 v52; // rax
  bool v53; // zf
  __int64 v54; // rax
  __int64 v55; // rax
  int v56; // ecx
  __int64 v57; // rax
  int v58; // edi
  bool v59; // zf
  __int64 v60; // rax
  __int64 v61; // rax
  int v62; // ecx
  int v63; // eax
  int v64; // ecx
  int v65; // ecx
  int v66; // eax
  __int64 v67; // rax
  int v68; // ebx
  double v69; // st7
  int v70; // edi
  double v71; // st7
  __int64 v72; // rax
  __int64 v73; // rax
  int v74; // ecx
  int v75; // ecx
  int result; // eax
  bool v77; // [esp+20h] [ebp-5Ah]
  char v78; // [esp+21h] [ebp-59h]
  float v79; // [esp+22h] [ebp-58h]
  float v80; // [esp+22h] [ebp-58h]
  float v81; // [esp+26h] [ebp-54h]
  float v82; // [esp+2Ah] [ebp-50h]
  float v83; // [esp+2Eh] [ebp-4Ch]
  int v84; // [esp+32h] [ebp-48h]
  float v85; // [esp+36h] [ebp-44h]
  int v86; // [esp+3Ah] [ebp-40h]
  float v87; // [esp+3Ah] [ebp-40h]
  int v88; // [esp+3Ah] [ebp-40h]
  int v89; // [esp+3Eh] [ebp-3Ch]
  double v90; // [esp+42h] [ebp-38h]
  double v91; // [esp+52h] [ebp-28h]
  int v92; // [esp+5Ah] [ebp-20h] BYREF
  int v93; // [esp+5Eh] [ebp-1Ch]

  v2 = *(_BYTE *)(this + 1048);
  if ( byte_75CBB8 )
  {
    if ( !v2 )
    {
      v3 = *(_DWORD *)(this + 1256);
      if ( v3 )
      {
        v4 = *(_DWORD *)(v3 + 128);
        if ( v4 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v4 + 88))(v4, 32);
      }
      v5 = *(_DWORD *)(this + 1260);
      if ( v5 )
      {
        v6 = *(_DWORD *)(v5 + 128);
        if ( v6 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v6 + 88))(v6, 32);
      }
      v7 = *(_DWORD *)(this + 1264);
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 128);
        if ( v8 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v8 + 88))(v8, 32);
      }
      v9 = *(_DWORD *)(this + 1268);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 128);
        if ( v10 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v10 + 88))(v10, 32);
      }
      *(_BYTE *)(this + 1048) = 1;
    }
  }
  else if ( v2 )
  {
    v11 = *(_DWORD *)(this + 1256);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 128);
      if ( v12 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v12 + 88))(v12, 16);
    }
    v13 = *(_DWORD *)(this + 1260);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 128);
      if ( v14 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v14 + 88))(v14, 16);
    }
    v15 = *(_DWORD *)(this + 1264);
    if ( v15 )
    {
      v16 = *(_DWORD *)(v15 + 128);
      if ( v16 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v16 + 88))(v16, 16);
    }
    v17 = *(_DWORD *)(this + 1268);
    if ( v17 )
    {
      v18 = *(_DWORD *)(v17 + 128);
      if ( v18 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v18 + 88))(v18, 16);
    }
    *(_BYTE *)(this + 1048) = 0;
  }
  if ( *(_BYTE *)(dword_75AAC4 + 2600) )
  {
    v81 = fabs(*(float *)(dword_75AAC4 + 18072));
  }
  else if ( *(_BYTE *)(dword_75AAC4 + 2296) )
  {
    v81 = fabs(*(float *)(dword_75AAC4 + 17824));
  }
  else
  {
    v81 = 0.0;
  }
  v83 = fabs(*(float *)(dword_75AAC4 + 18320));
  v19 = fabs(*(float *)(dword_75AAC4 + 18568));
  if ( v19 > v83 )
    v83 = v19;
  v82 = 0.0;
  *(_DWORD *)(this + 1232) = 0;
  *(_DWORD *)(this + 1240) = 0;
  *(_DWORD *)(this + 1248) = 0;
  v77 = (sub_42DBA0() ? dword_75AACC : 0) != dword_75AAC4
     || *(_DWORD *)(dword_75AACC + 16584)
     || *(_BYTE *)(dword_75AACC + 17412) && *(_DWORD *)dword_7668AC;
  v20 = 0.2;
  for ( i = 0; i < 4; ++i )
  {
    v22 = *(_DWORD *)(248 * i + dword_75AAC4 + 18008);
    if ( v22 )
    {
      v23 = *(_DWORD *)(v22 + 84);
      if ( v23 )
      {
        *(_DWORD *)(this + 1248) += *(_DWORD *)(v23 + 44);
        switch ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(248 * i + dword_75AAC4 + 18008) + 84) + 44) )
        {
          case 6:
          case 7:
            if ( (unsigned int)i <= 1 )
              v20 = v20 + 0.40000001;
            break;
          case 9:
          case 0xA:
            *(_DWORD *)(this + 1240) = 1;
            break;
          case 0xB:
            *(_DWORD *)(this + 1232) = 1;
            switch ( i )
            {
              case 0:
                v82 = v82 + 1.0;
                break;
              case 1:
                v82 = v82 - 1.0;
                break;
              case 2:
                v82 = v82 + 0.25;
                break;
              case 3:
                v82 = v82 - 0.25;
                break;
              default:
                continue;
            }
            break;
          default:
            continue;
        }
      }
    }
  }
  v24 = byte_769DAC;
  if ( v77 )
  {
    v82 = 0.0;
    if ( !byte_769DAC )
    {
      *(_DWORD *)(this + 1232) = 0;
      *(_DWORD *)(this + 1240) = 0;
      v24 = byte_769DAC;
    }
  }
  v25 = 0;
  v89 = 0;
  v26 = 0;
  v85 = flt_76AEFC * v20;
  while ( 1 )
  {
    v27 = dword_76AD28;
    v28 = 104 * v25 + this;
    v84 = v28;
    if ( *(_BYTE *)(v28 + 4) )
    {
      v86 = *(_DWORD *)(v28 + 100);
      if ( v86 )
      {
        switch ( v25 )
        {
          case 0:
            v78 = 0;
            if ( flt_76AEB4 == 0.0 || flt_76AE90 == 0.0 )
              goto LABEL_104;
            if ( !v77 )
            {
              v35 = 0.0;
              if ( *(_BYTE *)(dword_75AACC + 2296) == 1 )
                v35 = dbl_75ED10;
              if ( *(_BYTE *)(dword_75AACC + 2600) == 1 )
                v35 = v35 + dbl_75F1F8;
              v87 = v35 * 0.5 * v85 + 1.0 - v85;
              v36 = dbl_7601AC / flt_76AEB4 * v87;
              v80 = v36;
              if ( v36 <= 0.0 )
              {
                v37 = 0;
                v80 = v80 * -1.0;
              }
              else
              {
                v37 = 1;
              }
              if ( flt_76AE90 == 0.5 )
              {
                v38 = sqrt(v80);
              }
              else if ( flt_76AE90 == 2.0 )
              {
                v38 = v80 * v80;
              }
              else
              {
                v38 = pow(v80, flt_76AE90);
              }
              if ( v37 == 1 )
                v38 = v38 * -1.0;
              v39 = v38 * (flt_76AED8 * v87) * flt_76AE6C + (1.0 - flt_76AE6C) * flt_764D5C;
              flt_764D5C = v39;
              v41 = v39;
              if ( v42 | v43 )
              {
                v41 = -1.0;
              }
              else if ( v39 > 1.0 )
              {
                v41 = 1.0;
              }
              v34 = v41 * 10000.0;
              goto LABEL_100;
            }
            if ( !v24 )
            {
LABEL_104:
              v79 = 0.0;
              goto LABEL_105;
            }
            v29 = *(float *)(dword_75AAC4 + 4716);
            v30 = 0;
            if ( v29 < 0.0 )
            {
              v29 = v29 * -1.0;
              v30 = 1;
            }
            v31 = sqrt(v29);
            if ( v30 == 1 )
              v31 = v31 * -1.0;
            v32 = (v31 + 1.0) * 0.5;
            if ( flt_763920 <= 0.0 )
              v33 = flt_76394C * 0.5 + 0.5;
            else
              v33 = (1.0 - flt_763920) * 0.5;
            v79 = (v33 - v32) * 20000.0;
            if ( v79 >= -5000.0 )
            {
              if ( v79 > 5000.0 )
                v79 = 5000.0;
            }
            else
            {
              v79 = -5000.0;
            }
            if ( flt_76AEB4 < 0.0 )
            {
              v34 = v79 * -1.0;
LABEL_100:
              v79 = v34;
            }
            v44 = *(_DWORD *)(this + 1056) - (__int64)v79;
            v45 = (__int64)flt_76AF20;
            if ( v44 > 10000 * (int)v45 || v44 < -10000 * (int)v45 )
              v78 = 1;
LABEL_105:
            if ( v81 == 0.0
              || flt_76ADDC == 0.0
              || dword_76AD4C < 4
              || v77 && !byte_769DAC
              || (v46 = (__int64)(*(float *)(this + 1216) / v81), v47 = v46, (int)v46 <= 0)
              || (int)v46 > 2000000 )
            {
              v47 = 1000000;
LABEL_116:
              v26 = 0;
              goto LABEL_117;
            }
            v48 = (__int64)(flt_76AE24 * v81 + flt_76AE00 * 10000.0);
            v26 = v48;
            if ( (int)v48 < 0 )
              goto LABEL_116;
            if ( (int)v48 > 10000 )
              v26 = 10000;
LABEL_117:
            v49 = (__int64)flt_76AF20;
            v50 = *(_DWORD *)(this + 1064) - v47;
            if ( v50 > 10000 * (int)v49
              || v50 < -10000 * (int)v49
              || !v26 && *(_DWORD *)(this + 1052)
              || v78 == 1
              || flt_76AF20 == 0.0 )
            {
              if ( *(_BYTE *)(this + 1048) )
              {
LABEL_126:
                *(_DWORD *)(this + 1052) = 0;
                *(_DWORD *)(this + 1064) = 1;
                *(_DWORD *)(this + 1056) = 0;
                goto LABEL_182;
              }
              *(_DWORD *)(this + 1052) = v26;
              *(_DWORD *)(this + 1064) = v47;
              *(_DWORD *)(this + 1056) = (__int64)v79;
LABEL_182:
              (*(void (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(v84 + 100) + 24))(
                *(_DWORD *)(v84 + 100),
                v84 + 8,
                1073742080);
            }
            else if ( *(_BYTE *)(this + 1048) )
            {
              goto LABEL_126;
            }
            break;
          case 5:
            if ( *(float *)(dword_75AAC4 + 18820) <= 0.0
              || *(_BYTE *)(this + 1048)
              || *(float *)(dword_75AAC4 + 17768) != 0.0
              && v83 != 0.0
              && *(_DWORD *)(this + 724)
              && *(_DWORD *)(this + 1296) == *(_DWORD *)(this + 1300)
              && *(_DWORD *)(this + 1264) == *(_DWORD *)(this + 1268)
              || v77 && v24 != 1 )
            {
              v26 = 0;
              v51 = 1000000;
              v79 = 0.0;
            }
            else if ( dword_76AD28 == 3 )
            {
              v51 = (__int64)((*(float *)(dword_75AAC4 + 18820) - 400.0) * 6.8965516);
              v88 = v51;
              if ( v51 < 0 )
              {
                v51 = 0;
                v88 = 0;
              }
              v26 = 0;
              v79 = (double)v88 * flt_76B01C;
              if ( v79 >= -10000.0 )
              {
                if ( v79 > 10000.0 )
                  v79 = 10000.0;
              }
              else
              {
                v79 = -10000.0;
              }
            }
            else
            {
              v79 = 0.0;
              v52 = (__int64)(*(float *)(this + 1220) / *(float *)(dword_75AAC4 + 18820));
              v51 = v52;
              v53 = (_DWORD)v52 == 0;
              if ( (int)v52 < 0 )
              {
                v51 = -(int)v52;
                v53 = (_DWORD)v52 == 0;
              }
              if ( v53 || v51 > 1000000 )
              {
                v26 = 0;
                v51 = 1000000;
              }
              else
              {
                v54 = (__int64)(*(float *)(dword_75AAC4 + 18820) * flt_76B040 + flt_76B01C * 10000.0);
                v26 = v54;
                if ( (int)v54 >= 0 )
                {
                  if ( (int)v54 > 10000 )
                    v26 = 10000;
                }
                else
                {
                  v26 = 0;
                }
              }
            }
            if ( flt_76B088 != 0.0 && !*(_BYTE *)(this + 1048) )
            {
              v55 = (__int64)flt_76B088;
              v56 = *(_DWORD *)(this + 1176) - v51;
              if ( v56 <= 10000 * (int)v55 && v56 >= -10000 * (int)v55 && (v26 || !*(_DWORD *)(this + 1164)) )
                break;
            }
            *(_DWORD *)(this + 1176) = v51;
            *(_DWORD *)(this + 1164) = v26;
            *(_DWORD *)(this + 1168) = (__int64)v79;
            goto LABEL_182;
          case 6:
            if ( *(float *)(dword_75AAC4 + 17768) <= 0.0 || v83 == 0.0 || *(_BYTE *)(this + 1048) || v77 && v24 != 1 )
              goto LABEL_173;
            v57 = (__int64)(*(float *)(this + 1224) / v83);
            v58 = v57;
            v59 = (_DWORD)v57 == 0;
            if ( (int)v57 < 0 )
            {
              v58 = -(int)v57;
              v59 = (_DWORD)v57 == 0;
            }
            if ( v59 || v58 > 2000000 )
            {
LABEL_173:
              v58 = 1000000;
LABEL_174:
              v26 = 0;
              goto LABEL_175;
            }
            v60 = (__int64)(*(float *)(dword_75AAC4 + 17768) * flt_76B0F4 * 10000.0 + flt_76B0D0 * 10000.0);
            v26 = v60;
            if ( (int)v60 < 0 )
              goto LABEL_174;
            if ( (int)v60 > 10000 )
              v26 = 10000;
LABEL_175:
            if ( flt_76B13C != 0.0 && !*(_BYTE *)(this + 1048) )
            {
              v61 = (__int64)flt_76B13C;
              v62 = *(_DWORD *)(this + 1192) - v58;
              if ( v62 <= 10000 * (int)v61 && v62 >= -10000 * (int)v61 && (v26 || !*(_DWORD *)(this + 1180)) )
                break;
            }
            *(_DWORD *)(this + 1192) = v58;
            *(_DWORD *)(this + 1180) = v26;
            goto LABEL_182;
          case 7:
            if ( !v77 && !*(_BYTE *)(this + 1048) )
            {
              if ( dword_76AD28 == 3 )
              {
                v63 = *(_DWORD *)(this + 1248);
                v64 = *(_DWORD *)(this + 1252);
                if ( v63 != v64 )
                {
                  *(_DWORD *)(this + 1252) = v63;
                  if ( v64 )
                    *(double *)(this + 1376) = v81 * 0.0033333334 * 40000.0 + *(double *)(this + 1376);
                  v27 = dword_76AD28;
                }
              }
              if ( *(double *)(this + 1392) != 0.0 || *(double *)(this + 1376) != 0.0 || *(double *)(this + 1384) != 0.0 )
              {
                v92 = 0;
                if ( dword_760144 )
                {
                  v90 = *(double *)(dword_760144 + 76) * *(double *)(this + 1392)
                      + *(double *)(dword_760144 + 52) * *(double *)(this + 1384)
                      + *(double *)(dword_760144 + 28) * *(double *)(this + 1376);
                  v91 = *(double *)(dword_760144 + 92) * *(double *)(this + 1392)
                      + *(double *)(dword_760144 + 44) * *(double *)(this + 1376)
                      + *(double *)(dword_760144 + 68) * *(double *)(this + 1384);
                }
                if ( v27 == 3 && *(_DWORD *)(this + 1256) )
                {
                  v92 = 1;
                  v93 = 1;
                }
                else
                {
                  v65 = *(_DWORD *)(this + 1256);
                  if ( v65 && (v66 = *(_DWORD *)(this + 1268)) != 0 && !dword_76ADB8 && v66 == v65 )
                  {
                    v92 = (__int64)v90;
                    v93 = (__int64)-v91;
                  }
                  else
                  {
                    v92 = 1;
                  }
                }
                v67 = (__int64)(sqrt(
                                  *(double *)(this + 1384) * *(double *)(this + 1384)
                                + *(double *)(this + 1392) * *(double *)(this + 1392)
                                + *(double *)(this + 1376) * *(double *)(this + 1376))
                              * (flt_76B214
                               * 0.1));
                *(_DWORD *)(this + 1196) = v67;
                if ( (int)v67 >= -10000 )
                {
                  if ( (int)v67 > 10000 )
                    *(_DWORD *)(this + 1196) = 10000;
                }
                else
                {
                  *(_DWORD *)(this + 1196) = -10000;
                }
                *(_DWORD *)(v28 + 44) = &v92;
                (*(void (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(v28 + 100) + 24))(
                  *(_DWORD *)(v28 + 100),
                  v28 + 8,
                  1073742144);
                (*(void (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(v28 + 100) + 28))(
                  *(_DWORD *)(v28 + 100),
                  1,
                  0);
              }
            }
            break;
          case 8:
            if ( v81 == 0.0 )
              goto LABEL_244;
            v68 = *(_DWORD *)(this + 1232);
            if ( v68 )
              goto LABEL_213;
            if ( dword_76AD28 != 3 )
              goto LABEL_245;
            if ( !*(_DWORD *)(this + 1240) )
              goto LABEL_250;
LABEL_213:
            if ( !v77 || byte_769DAC == 1 )
            {
              if ( dword_76AD28 == 3 )
              {
                v69 = v81 * 0.0033333334;
                v70 = (__int64)(10000.0 * v69);
                if ( v68 )
                {
                  v26 = 0;
                  v79 = flt_76B160 * v69 * 10000.0;
                }
                else if ( *(_DWORD *)(this + 1240) )
                {
                  v79 = flt_76B160 * v69 * 8000.0;
                  v71 = *(float *)(this + 1228) / v81;
                  v26 = (__int64)(v79 * 0.75);
                  v70 = (__int64)(v71 + v71);
                }
                goto LABEL_218;
              }
              v70 = (__int64)(*(float *)(this + 1228) / v81);
              if ( v70 <= 2000000 )
              {
                v72 = (__int64)(flt_76B160 * 10000.0);
                v26 = v72;
                v79 = (double)*(int *)(this + 1200) * flt_76B1CC * v82;
                if ( (int)v72 <= 10000 )
                {
                  if ( (int)v72 < 0 )
                    v26 = 0;
                }
                else
                {
                  v26 = 10000;
                }
LABEL_218:
                if ( v79 <= 10000.0 )
                {
                  if ( v79 < -10000.0 )
                    v79 = -10000.0;
                }
                else
                {
                  v79 = 10000.0;
                }
              }
              else
              {
                v26 = 0;
                v70 = 1000000;
                v79 = 0.0;
              }
              if ( !*(_DWORD *)(this + 1236) && !*(_DWORD *)(this + 1244) )
              {
                (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v86 + 24))(v86, v84 + 8, 536871168);
LABEL_243:
                v75 = *(_DWORD *)(this + 1240);
                *(_DWORD *)(this + 1236) = *(_DWORD *)(this + 1232);
                *(_DWORD *)(this + 1244) = v75;
                break;
              }
              if ( flt_76B1F0 == 0.0 )
              {
LABEL_239:
                if ( *(_BYTE *)(this + 1048) )
                  goto LABEL_240;
                *(_DWORD *)(this + 1200) = v26;
                *(_DWORD *)(this + 1204) = (__int64)v79;
                *(_DWORD *)(this + 1212) = v70;
              }
              else
              {
                if ( !*(_BYTE *)(this + 1048) )
                {
                  v73 = (__int64)flt_76B1F0;
                  v74 = *(_DWORD *)(this + 1212) - v70;
                  if ( v74 <= 10000 * (int)v73 && v74 >= -10000 * (int)v73 && (v26 || !*(_DWORD *)(this + 1200)) )
                    goto LABEL_243;
                  goto LABEL_239;
                }
LABEL_240:
                *(_DWORD *)(this + 1200) = 0;
                *(_DWORD *)(this + 1204) = 0;
                *(_DWORD *)(this + 1212) = 1000000;
              }
              (*(void (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(v84 + 100) + 24))(
                *(_DWORD *)(v84 + 100),
                v84 + 8,
                1073742080);
              goto LABEL_243;
            }
LABEL_244:
            if ( dword_76AD28 == 3 )
            {
LABEL_250:
              if ( !*(_DWORD *)(this + 1232)
                && !*(_DWORD *)(this + 1240)
                && (*(_DWORD *)(this + 1236) || *(_DWORD *)(this + 1244)) )
              {
LABEL_247:
                *(_DWORD *)(this + 1232) = 0;
                *(_DWORD *)(this + 1236) = 0;
                *(_DWORD *)(this + 1240) = 0;
                *(_DWORD *)(this + 1244) = 0;
                (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v28 + 100) + 32))(*(_DWORD *)(v28 + 100));
                break;
              }
            }
            else
            {
LABEL_245:
              if ( !*(_DWORD *)(this + 1232) && *(_DWORD *)(this + 1236) )
                goto LABEL_247;
            }
            break;
          default:
            break;
        }
      }
    }
    v25 = ++v89;
    if ( v89 >= 10 )
      break;
    v24 = byte_769DAC;
  }
  result = 0;
  *(_DWORD *)(this + 1376) = 0;
  *(_DWORD *)(this + 1380) = 0;
  *(_DWORD *)(this + 1384) = 0;
  *(_DWORD *)(this + 1388) = 0;
  *(_DWORD *)(this + 1392) = 0;
  *(_DWORD *)(this + 1396) = 0;
  return result;
}
