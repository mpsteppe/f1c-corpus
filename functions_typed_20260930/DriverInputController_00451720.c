int __thiscall sub_451720(int this)
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
  int v45; // eax
  int v46; // eax
  int v47; // edi
  int v48; // eax
  int v49; // eax
  int v50; // ecx
  int v51; // edi
  int v52; // ebx
  int v53; // eax
  bool v54; // zf
  int v55; // eax
  int v56; // eax
  int v57; // ecx
  int v58; // eax
  int v59; // edi
  bool v60; // zf
  int v61; // eax
  int v62; // eax
  int v63; // ecx
  int v64; // eax
  int v65; // ecx
  int v66; // ecx
  int v67; // eax
  int v68; // eax
  int v69; // ebx
  double v70; // st7
  int v71; // edi
  int v72; // eax
  double v73; // st7
  int v74; // eax
  int v75; // eax
  int v76; // ecx
  int v77; // ecx
  int result; // eax
  bool v79; // [esp+20h] [ebp-5Ah]
  char v80; // [esp+21h] [ebp-59h]
  float v81; // [esp+22h] [ebp-58h]
  float v82; // [esp+22h] [ebp-58h]
  float v83; // [esp+26h] [ebp-54h]
  float v84; // [esp+2Ah] [ebp-50h]
  float v85; // [esp+2Eh] [ebp-4Ch]
  int v86; // [esp+32h] [ebp-48h]
  float v87; // [esp+36h] [ebp-44h]
  int v88; // [esp+3Ah] [ebp-40h]
  float v89; // [esp+3Ah] [ebp-40h]
  int v90; // [esp+3Ah] [ebp-40h]
  int v91; // [esp+3Eh] [ebp-3Ch]
  double v92; // [esp+42h] [ebp-38h]
  double v93; // [esp+52h] [ebp-28h]
  int v94; // [esp+5Ah] [ebp-20h] BYREF
  int v95; // [esp+5Eh] [ebp-1Ch]

  v2 = *(_BYTE *)(this + 1048);
  if ( byte_7C56AC )
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
  if ( *(_DWORD *)(dword_7C54E0 + 2396) && *(_BYTE *)(dword_7C54E0 + 2460) )
  {
    v83 = fabs(*(float *)(dword_7C54E0 + 14004));
  }
  else if ( *(_DWORD *)(dword_7C54E0 + 2100) && *(_BYTE *)(dword_7C54E0 + 2164) )
  {
    v83 = fabs(*(float *)(dword_7C54E0 + 13756));
  }
  else
  {
    v83 = 0.0;
  }
  v85 = fabs(*(float *)(dword_7C54E0 + 14252));
  v19 = fabs(*(float *)(dword_7C54E0 + 14500));
  if ( v19 > v85 )
    v85 = v19;
  v20 = 0.2;
  *(_DWORD *)(this + 1232) = 0;
  *(_DWORD *)(this + 1240) = 0;
  *(_DWORD *)(this + 1248) = 0;
  v84 = 0.0;
  v79 = dword_7C54E8 != dword_7C54E0
     || *(_DWORD *)(dword_7C54E8 + 13000)
     || *(_BYTE *)(dword_7C54E8 + 13388) && dword_7CE7A8;
  for ( i = 0; i < 4; ++i )
  {
    v22 = *(_DWORD *)(248 * i + dword_7C54E0 + 13940);
    if ( v22 )
    {
      v23 = *(_DWORD *)(v22 + 84);
      if ( v23 )
      {
        *(_DWORD *)(this + 1248) += *(_DWORD *)(v23 + 48);
        switch ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(248 * i + dword_7C54E0 + 13940) + 84) + 48) )
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
                v84 = v84 + 1.0;
                break;
              case 1:
                v84 = v84 - 1.0;
                break;
              case 2:
                v84 = v84 + 0.25;
                break;
              case 3:
                v84 = v84 - 0.25;
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
  v24 = byte_7D1358;
  if ( v79 )
  {
    v84 = 0.0;
    if ( !byte_7D1358 )
    {
      *(_DWORD *)(this + 1232) = 0;
      *(_DWORD *)(this + 1240) = 0;
      v24 = byte_7D1358;
    }
  }
  v25 = 0;
  v91 = 0;
  v26 = 0;
  v87 = flt_7D21AC * v20;
  while ( 1 )
  {
    v27 = dword_7D1FD8;
    v28 = 104 * v25 + this;
    v86 = v28;
    if ( *(_BYTE *)(v28 + 4) )
    {
      v88 = *(_DWORD *)(v28 + 100);
      if ( v88 )
      {
        switch ( v25 )
        {
          case 0:
            v80 = 0;
            if ( flt_7D2164 == 0.0 || flt_7D2140 == 0.0 )
              goto LABEL_108;
            if ( !v79 )
            {
              v35 = 0.0;
              if ( *(_DWORD *)(dword_7C54E8 + 2100) && *(_BYTE *)(dword_7C54E8 + 2164) )
                v35 = dbl_7C77F8;
              if ( *(_DWORD *)(dword_7C54E8 + 2396) && *(_BYTE *)(dword_7C54E8 + 2460) )
                v35 = v35 + dbl_7C7C5C;
              v89 = v35 * 0.5 * v87 + 1.0 - v87;
              v36 = dbl_7C8A80 / flt_7D2164 * v89;
              v82 = v36;
              if ( v36 <= 0.0 )
              {
                v37 = 0;
                v82 = v82 * -1.0;
              }
              else
              {
                v37 = 1;
              }
              if ( flt_7D2140 == 0.5 )
              {
                v38 = sqrt(v82);
              }
              else if ( flt_7D2140 == 2.0 )
              {
                v38 = v82 * v82;
              }
              else
              {
                v38 = v82;
                sub_5881F0(v82);
              }
              if ( v37 == 1 )
                v38 = v38 * -1.0;
              v39 = v38 * (flt_7D2188 * v89) * flt_7D211C + (1.0 - flt_7D211C) * flt_7CD1F8;
              flt_7CD1F8 = v39;
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
              goto LABEL_104;
            }
            if ( !v24 )
            {
LABEL_108:
              v81 = 0.0;
              goto LABEL_109;
            }
            v29 = *(float *)(dword_7C54E0 + 13696);
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
            if ( flt_7CC130 <= 0.0 )
              v33 = flt_7CC15C * 0.5 + 0.5;
            else
              v33 = (1.0 - flt_7CC130) * 0.5;
            v81 = (v33 - v32) * 20000.0;
            if ( v81 >= -5000.0 )
            {
              if ( v81 > 5000.0 )
                v81 = 5000.0;
            }
            else
            {
              v81 = -5000.0;
            }
            if ( flt_7D2164 < 0.0 )
            {
              v34 = v81 * -1.0;
LABEL_104:
              v81 = v34;
            }
            v44 = *(_DWORD *)(this + 1056) - CRTFtol(v81);
            v45 = CRTFtol(flt_7D21D0);
            if ( v44 > 10000 * v45 || v44 < -10000 * v45 )
              v80 = 1;
LABEL_109:
            if ( v83 == 0.0
              || flt_7D208C == 0.0
              || dword_7D1FFC < 4
              || v79 && !byte_7D1358
              || (v46 = CRTFtol(*(float *)(this + 1216) / v83), v47 = v46, v46 <= 0)
              || v46 > 2000000 )
            {
              v47 = 1000000;
LABEL_120:
              v26 = 0;
              goto LABEL_121;
            }
            v48 = CRTFtol(flt_7D20D4 * v83 + flt_7D20B0 * 10000.0);
            v26 = v48;
            if ( v48 < 0 )
              goto LABEL_120;
            if ( v48 > 10000 )
              v26 = 10000;
LABEL_121:
            v49 = CRTFtol(flt_7D21D0);
            v50 = *(_DWORD *)(this + 1064) - v47;
            if ( v50 > 10000 * v49
              || v50 < -10000 * v49
              || !v26 && *(_DWORD *)(this + 1052)
              || v80 == 1
              || flt_7D21D0 == 0.0 )
            {
              if ( *(_BYTE *)(this + 1048) )
              {
LABEL_130:
                *(_DWORD *)(this + 1052) = 0;
                *(_DWORD *)(this + 1064) = 1;
                *(_DWORD *)(this + 1056) = 0;
                goto LABEL_186;
              }
              *(_DWORD *)(this + 1052) = v26;
              *(_DWORD *)(this + 1064) = v47;
              *(_DWORD *)(this + 1056) = CRTFtol(v81);
LABEL_186:
              (*(void (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(v86 + 100) + 24))(
                *(_DWORD *)(v86 + 100),
                v86 + 8,
                1073742080);
            }
            else if ( *(_BYTE *)(this + 1048) )
            {
              goto LABEL_130;
            }
            break;
          case 5:
            if ( *(float *)(dword_7C54E0 + 14752) <= 0.0
              || *(_BYTE *)(this + 1048)
              || *(float *)(dword_7C54E0 + 13700) != 0.0
              && v85 != 0.0
              && *(_DWORD *)(this + 724)
              && *(_DWORD *)(this + 1296) == *(_DWORD *)(this + 1300)
              && *(_DWORD *)(this + 1264) == *(_DWORD *)(this + 1268)
              || v79 && v24 != 1 )
            {
              v26 = 0;
              v51 = 1000000;
              v81 = 0.0;
            }
            else if ( dword_7D1FD8 == 3 )
            {
              v51 = CRTFtol((*(float *)(dword_7C54E0 + 14752) - 400.0) * 6.8965516);
              v90 = v51;
              if ( v51 < 0 )
              {
                v51 = 0;
                v90 = 0;
              }
              v26 = 0;
              v81 = (double)v90 * flt_7D22A8;
              if ( v81 >= -10000.0 )
              {
                if ( v81 > 10000.0 )
                  v81 = 10000.0;
              }
              else
              {
                v81 = -10000.0;
              }
            }
            else
            {
              v52 = dword_7C54E0;
              v81 = 0.0;
              v53 = CRTFtol(*(float *)(this + 1220) / *(float *)(dword_7C54E0 + 14752));
              v51 = v53;
              v54 = v53 == 0;
              if ( v53 < 0 )
              {
                v51 = -v53;
                v54 = v53 == 0;
              }
              if ( v54 || v51 > 1000000 )
              {
                v26 = 0;
                v51 = 1000000;
              }
              else
              {
                v55 = CRTFtol(*(float *)(v52 + 14752) * flt_7D22CC + flt_7D22A8 * 10000.0);
                v26 = v55;
                if ( v55 >= 0 )
                {
                  if ( v55 > 10000 )
                    v26 = 10000;
                }
                else
                {
                  v26 = 0;
                }
              }
            }
            if ( flt_7D2314 != 0.0 && !*(_BYTE *)(this + 1048) )
            {
              v56 = CRTFtol(flt_7D2314);
              v57 = *(_DWORD *)(this + 1176) - v51;
              if ( v57 <= 10000 * v56 && v57 >= -10000 * v56 && (v26 || !*(_DWORD *)(this + 1164)) )
                break;
            }
            *(_DWORD *)(this + 1176) = v51;
            *(_DWORD *)(this + 1164) = v26;
            *(_DWORD *)(this + 1168) = CRTFtol(v81);
            goto LABEL_186;
          case 6:
            if ( *(float *)(dword_7C54E0 + 13700) <= 0.0 || v85 == 0.0 || *(_BYTE *)(this + 1048) || v79 && v24 != 1 )
              goto LABEL_177;
            v58 = CRTFtol(*(float *)(this + 1224) / v85);
            v59 = v58;
            v60 = v58 == 0;
            if ( v58 < 0 )
            {
              v59 = -v58;
              v60 = v58 == 0;
            }
            if ( v60 || v59 > 2000000 )
            {
LABEL_177:
              v59 = 1000000;
LABEL_178:
              v26 = 0;
              goto LABEL_179;
            }
            v61 = CRTFtol(*(float *)(dword_7C54E0 + 13700) * flt_7D2380 * 10000.0 + flt_7D235C * 10000.0);
            v26 = v61;
            if ( v61 < 0 )
              goto LABEL_178;
            if ( v61 > 10000 )
              v26 = 10000;
LABEL_179:
            if ( flt_7D23C8 != 0.0 && !*(_BYTE *)(this + 1048) )
            {
              v62 = CRTFtol(flt_7D23C8);
              v63 = *(_DWORD *)(this + 1192) - v59;
              if ( v63 <= 10000 * v62 && v63 >= -10000 * v62 && (v26 || !*(_DWORD *)(this + 1180)) )
                break;
            }
            *(_DWORD *)(this + 1192) = v59;
            *(_DWORD *)(this + 1180) = v26;
            goto LABEL_186;
          case 7:
            if ( !v79 && !*(_BYTE *)(this + 1048) )
            {
              if ( dword_7D1FD8 == 3 )
              {
                v64 = *(_DWORD *)(this + 1248);
                v65 = *(_DWORD *)(this + 1252);
                if ( v64 != v65 )
                {
                  *(_DWORD *)(this + 1252) = v64;
                  if ( v65 )
                    *(double *)(this + 1376) = v83 * 0.0033333334 * 40000.0 + *(double *)(this + 1376);
                  v27 = dword_7D1FD8;
                }
              }
              if ( *(double *)(this + 1392) != 0.0 || *(double *)(this + 1376) != 0.0 || *(double *)(this + 1384) != 0.0 )
              {
                v94 = 0;
                if ( dword_7C8A18 )
                {
                  v92 = *(double *)(dword_7C8A18 + 76) * *(double *)(this + 1392)
                      + *(double *)(dword_7C8A18 + 52) * *(double *)(this + 1384)
                      + *(double *)(dword_7C8A18 + 28) * *(double *)(this + 1376);
                  v93 = *(double *)(dword_7C8A18 + 44) * *(double *)(this + 1376)
                      + *(double *)(dword_7C8A18 + 92) * *(double *)(this + 1392)
                      + *(double *)(dword_7C8A18 + 68) * *(double *)(this + 1384);
                }
                if ( v27 == 3 && *(_DWORD *)(this + 1256) )
                {
                  v94 = 1;
                  v95 = 1;
                }
                else
                {
                  v66 = *(_DWORD *)(this + 1256);
                  if ( v66 && (v67 = *(_DWORD *)(this + 1268)) != 0 && !dword_7D2068 && v67 == v66 )
                  {
                    v94 = CRTFtol(v92);
                    v95 = CRTFtol(-v93);
                  }
                  else
                  {
                    v94 = 1;
                  }
                }
                v68 = CRTFtol(*(double *)(this + 1392));
                *(_DWORD *)(this + 1196) = v68;
                if ( v68 >= -10000 )
                {
                  if ( v68 > 10000 )
                    *(_DWORD *)(this + 1196) = 10000;
                }
                else
                {
                  *(_DWORD *)(this + 1196) = -10000;
                }
                *(_DWORD *)(v28 + 44) = &v94;
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
            if ( v83 == 0.0 )
              goto LABEL_248;
            v69 = *(_DWORD *)(this + 1232);
            if ( v69 )
              goto LABEL_217;
            if ( dword_7D1FD8 != 3 )
              goto LABEL_249;
            if ( !*(_DWORD *)(this + 1240) )
              goto LABEL_254;
LABEL_217:
            if ( !v79 || byte_7D1358 == 1 )
            {
              if ( dword_7D1FD8 == 3 )
              {
                v70 = v83 * 0.0033333334;
                v71 = CRTFtol(v70);
                if ( v69 )
                {
                  v26 = 0;
                  v81 = flt_7D23EC * v70 * 10000.0;
                }
                else if ( *(_DWORD *)(this + 1240) )
                {
                  v81 = flt_7D23EC * v70 * 8000.0;
                  v72 = CRTFtol(v81 * 0.75);
                  v73 = *(float *)(this + 1228) / v83;
                  v26 = v72;
                  v71 = CRTFtol(v73 + v73);
                }
                goto LABEL_222;
              }
              v71 = CRTFtol(*(float *)(this + 1228) / v83);
              if ( v71 <= 2000000 )
              {
                v74 = CRTFtol(flt_7D23EC * 10000.0);
                v26 = v74;
                v81 = (double)*(int *)(this + 1200) * flt_7D2458 * v84;
                if ( v74 <= 10000 )
                {
                  if ( v74 < 0 )
                    v26 = 0;
                }
                else
                {
                  v26 = 10000;
                }
LABEL_222:
                if ( v81 <= 10000.0 )
                {
                  if ( v81 < -10000.0 )
                    v81 = -10000.0;
                }
                else
                {
                  v81 = 10000.0;
                }
              }
              else
              {
                v26 = 0;
                v71 = 1000000;
                v81 = 0.0;
              }
              if ( !*(_DWORD *)(this + 1236) && !*(_DWORD *)(this + 1244) )
              {
                (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v88 + 24))(v88, v86 + 8, 536871168);
LABEL_247:
                v77 = *(_DWORD *)(this + 1240);
                *(_DWORD *)(this + 1236) = *(_DWORD *)(this + 1232);
                *(_DWORD *)(this + 1244) = v77;
                break;
              }
              if ( flt_7D247C == 0.0 )
              {
LABEL_243:
                if ( *(_BYTE *)(this + 1048) )
                  goto LABEL_244;
                *(_DWORD *)(this + 1200) = v26;
                *(_DWORD *)(this + 1204) = CRTFtol(v81);
                *(_DWORD *)(this + 1212) = v71;
              }
              else
              {
                if ( !*(_BYTE *)(this + 1048) )
                {
                  v75 = CRTFtol(flt_7D247C);
                  v76 = *(_DWORD *)(this + 1212) - v71;
                  if ( v76 <= 10000 * v75 && v76 >= -10000 * v75 && (v26 || !*(_DWORD *)(this + 1200)) )
                    goto LABEL_247;
                  goto LABEL_243;
                }
LABEL_244:
                *(_DWORD *)(this + 1200) = 0;
                *(_DWORD *)(this + 1204) = 0;
                *(_DWORD *)(this + 1212) = 1000000;
              }
              (*(void (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(v86 + 100) + 24))(
                *(_DWORD *)(v86 + 100),
                v86 + 8,
                1073742080);
              goto LABEL_247;
            }
LABEL_248:
            if ( dword_7D1FD8 == 3 )
            {
LABEL_254:
              if ( !*(_DWORD *)(this + 1232)
                && !*(_DWORD *)(this + 1240)
                && (*(_DWORD *)(this + 1236) || *(_DWORD *)(this + 1244)) )
              {
LABEL_251:
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
LABEL_249:
              if ( !*(_DWORD *)(this + 1232) && *(_DWORD *)(this + 1236) )
                goto LABEL_251;
            }
            break;
          default:
            break;
        }
      }
    }
    v25 = ++v91;
    if ( v91 >= 10 )
      break;
    v24 = byte_7D1358;
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

