int __thiscall sub_465AC0(int this)
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
  bool v20; // al
  double v21; // st7
  float *v22; // ebx
  int i; // edx
  float v24; // ecx
  int v25; // ecx
  int result; // eax
  int v27; // ebp
  int v28; // edx
  int v29; // edi
  long double v30; // st7
  char v31; // cl
  double v32; // st7
  double v33; // st7
  double v34; // st6
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  char v39; // bl
  double v40; // st7
  int v41; // ebx
  unsigned __int64 v42; // rax
  unsigned __int64 v43; // rax
  int v44; // ebx
  unsigned __int64 v45; // rax
  int v46; // edi
  unsigned __int64 v47; // rax
  double v48; // st7
  int v49; // edi
  double v50; // st7
  unsigned __int64 v51; // rax
  bool v52; // zf
  unsigned __int64 v53; // rax
  int v54; // ebx
  unsigned __int64 v55; // rax
  double v56; // st7
  unsigned __int64 v57; // rax
  int v58; // edi
  bool v59; // zf
  unsigned __int64 v60; // rax
  int v61; // ebx
  unsigned __int64 v62; // rax
  int v63; // ecx
  int v64; // edx
  int v65; // eax
  int v66; // ecx
  unsigned __int64 v67; // rax
  int v68; // ecx
  int v69; // eax
  int v70; // edi
  double v71; // st7
  int v72; // ebx
  double v73; // st7
  unsigned __int64 v74; // rax
  double v75; // st7
  unsigned __int64 v76; // rax
  int v77; // edi
  unsigned __int64 v78; // rax
  unsigned __int64 v79; // rax
  double v80; // st7
  int v81; // ecx
  int v82; // edx
  unsigned int v83; // kr00_4
  __int32 v84; // eax
  __int32 v85; // eax
  __int32 v86[6]; // [esp+20h] [ebp-74h] BYREF
  bool v87; // [esp+3Ah] [ebp-5Ah]
  char v88; // [esp+3Bh] [ebp-59h]
  float v89; // [esp+3Ch] [ebp-58h] BYREF
  float v90; // [esp+40h] [ebp-54h]
  float v91; // [esp+44h] [ebp-50h]
  float v92; // [esp+48h] [ebp-4Ch]
  int v93; // [esp+4Ch] [ebp-48h]
  float v94; // [esp+50h] [ebp-44h]
  float v95; // [esp+54h] [ebp-40h]
  int v96; // [esp+58h] [ebp-3Ch]
  double v97[3]; // [esp+5Ch] [ebp-38h] BYREF
  int v98; // [esp+74h] [ebp-20h] BYREF
  int v99; // [esp+78h] [ebp-1Ch]

  v2 = *(_BYTE *)(this + 1152);
  if ( byte_B6413C )
  {
    if ( !v2 )
    {
      v3 = *(_DWORD *)(this + 1312);
      if ( v3 )
      {
        v4 = *(_DWORD *)(v3 + 128);
        if ( v4 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v4 + 88))(v4, 32);
      }
      v5 = *(_DWORD *)(this + 1316);
      if ( v5 )
      {
        v6 = *(_DWORD *)(v5 + 128);
        if ( v6 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v6 + 88))(v6, 32);
      }
      v7 = *(_DWORD *)(this + 1320);
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 128);
        if ( v8 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v8 + 88))(v8, 32);
      }
      v9 = *(_DWORD *)(this + 1324);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 128);
        if ( v10 )
          (*(void (__stdcall **)(int, int))(*(_DWORD *)v10 + 88))(v10, 32);
      }
      *(_BYTE *)(this + 1152) = 1;
    }
  }
  else if ( v2 )
  {
    v11 = *(_DWORD *)(this + 1312);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 128);
      if ( v12 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v12 + 88))(v12, 16);
    }
    v13 = *(_DWORD *)(this + 1316);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 128);
      if ( v14 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v14 + 88))(v14, 16);
    }
    v15 = *(_DWORD *)(this + 1320);
    if ( v15 )
    {
      v16 = *(_DWORD *)(v15 + 128);
      if ( v16 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v16 + 88))(v16, 16);
    }
    v17 = *(_DWORD *)(this + 1324);
    if ( v17 )
    {
      v18 = *(_DWORD *)(v17 + 128);
      if ( v18 )
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v18 + 88))(v18, 16);
    }
    *(_BYTE *)(this + 1152) = 0;
  }
  if ( dword_91E07C[3528] )
  {
    v90 = fabs(*((float *)dword_91E07C + 4116));
  }
  else if ( dword_91E07C[3232] )
  {
    v90 = fabs(*((float *)dword_91E07C + 4053));
  }
  else
  {
    v90 = 0.0;
  }
  v94 = fabs(*((float *)dword_91E07C + 4179));
  v19 = fabs(*((float *)dword_91E07C + 4242));
  if ( v19 > v94 )
    v94 = v19;
  v91 = 0.0;
  *(_DWORD *)(this + 1288) = 0;
  *(_DWORD *)(this + 1296) = 0;
  *(_DWORD *)(this + 1304) = 0;
  v92 = 0.2;
  v20 = sub_45F420();
  v21 = 0.2;
  v22 = (float *)dword_91E07C;
  v87 = v20;
  for ( i = 0; i < 4; ++i )
  {
    v24 = v22[63 * i + 4100];
    if ( v24 != 0.0 )
    {
      v25 = *(_DWORD *)(LODWORD(v24) + 84);
      if ( v25 )
      {
        *(_DWORD *)(this + 1304) += *(_DWORD *)(v25 + 44);
        v22 = (float *)dword_91E07C;
        switch ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&dword_91E07C[252 * i + 16400] + 84) + 44) )
        {
          case 0x12:
          case 0x13:
            if ( (unsigned int)i <= 1 )
              v21 = v21 + flt_B75168;
            break;
          case 0x15:
          case 0x16:
            *(_DWORD *)(this + 1296) = 1;
            goto LABEL_49;
          case 0x17:
            *(_DWORD *)(this + 1288) = 1;
            switch ( i )
            {
              case 0:
                v91 = v91 + 1.0;
                break;
              case 1:
                v91 = v91 - 1.0;
                break;
              case 2:
                v91 = v91 + 0.25;
                break;
              case 3:
                v91 = v91 - 0.25;
                break;
              default:
                break;
            }
LABEL_49:
            v22 = (float *)dword_91E07C;
            break;
          default:
            continue;
        }
      }
    }
  }
  if ( v87 )
  {
    v91 = 0.0;
    if ( !byte_B739F0 )
    {
      *(_DWORD *)(this + 1288) = 0;
      *(_DWORD *)(this + 1296) = 0;
      v22 = (float *)dword_91E07C;
    }
  }
  result = 0;
  v96 = 0;
  v27 = 0;
  v92 = flt_B75144 * v21;
  while ( 1 )
  {
    v28 = dword_B74F70;
    v29 = this + 104 * result;
    v52 = *(_BYTE *)(v29 + 4) == 0;
    v93 = v29;
    if ( !v52 && *(_DWORD *)(v29 + 100) )
    {
      switch ( result )
      {
        case 0:
          v88 = 0;
          if ( flt_B750FC == 0.0 || flt_B750D8 == 0.0 )
            goto LABEL_91;
          if ( !v87 )
          {
            v36 = 0.0;
            if ( *(_BYTE *)(dword_91E084 + 3232) == 1 )
              v36 = dbl_B66450;
            if ( *(_BYTE *)(dword_91E084 + 3528) == 1 )
              v36 = v36 + dbl_B66950;
            v37 = v36 * 0.5;
            v92 = (1.2 - v37) * v92;
            v95 = v37 * v92 + 1.0 - v92;
            v38 = dbl_B67960 * dbl_B67958 / flt_B750FC * v95;
            v89 = v38;
            if ( v38 <= 0.0 )
            {
              v39 = 0;
              v89 = v89 * -1.0;
            }
            else
            {
              v39 = 1;
            }
            if ( flt_B750D8 == 0.5 )
            {
              v40 = sqrt(v89);
            }
            else if ( flt_B750D8 == 2.0 )
            {
              v40 = v89 * v89;
            }
            else
            {
              v40 = pow(v89, flt_B750D8);
            }
            if ( v39 == 1 )
              v40 = v40 * -1.0;
            v89 = v40 * (flt_B75120 * v95) * flt_B750B4 + (1.0 - flt_B750B4) * flt_B6C4F4;
            flt_B6C4F4 = v89;
            sub_401760(&v89, -1.0, 1.0);
            v35 = v89 * 10000.0;
            goto LABEL_87;
          }
          if ( !byte_B739F0 )
          {
LABEL_91:
            v89 = 0.0;
            goto LABEL_92;
          }
          v30 = v22[4038];
          v31 = 0;
          if ( v30 < 0.0 )
          {
            v30 = v30 * -1.0;
            v31 = 1;
          }
          v32 = sqrt(v30);
          if ( v31 == 1 )
            v32 = v32 * -1.0;
          v33 = (v32 + 1.0) * 0.5;
          if ( flt_B6B674 <= 0.0 )
            v34 = flt_B6B6A0 * 0.5 + 0.5;
          else
            v34 = (1.0 - flt_B6B674) * 0.5;
          v89 = (v34 - v33) * 20000.0;
          sub_401760(&v89, -5000.0, 5000.0);
          if ( flt_B750FC < 0.0 )
          {
            v35 = v89 * -1.0;
LABEL_87:
            v89 = v35;
          }
          v41 = *(_DWORD *)(this + 1160) - (unsigned __int64)v89;
          v42 = (unsigned __int64)flt_B7518C;
          if ( v41 > 10000 * (int)v42 || v41 < -10000 * (int)v42 )
            v88 = 1;
LABEL_92:
          if ( v90 == 0.0
            || flt_B75024 == 0.0
            || dword_B74F94 < 4
            || v87 && !byte_B739F0
            || (v43 = (unsigned __int64)(*(float *)(this + 1272) / v90), v44 = v43, (int)v43 <= 0)
            || (int)v43 > 2000000 )
          {
            v44 = 1000000;
LABEL_103:
            v27 = 0;
            goto LABEL_104;
          }
          v45 = (unsigned __int64)(flt_B7506C * v90 + flt_B75048 * 10000.0);
          v27 = v45;
          if ( (v45 & 0x80000000) != 0LL )
            goto LABEL_103;
          if ( (int)v45 > 10000 )
            v27 = 10000;
LABEL_104:
          v46 = *(_DWORD *)(this + 1168) - v44;
          v47 = (unsigned __int64)flt_B7518C;
          if ( v46 > 10000 * (int)v47
            || v46 < -10000 * (int)v47
            || !v27 && *(_DWORD *)(this + 1156)
            || v88 == 1
            || flt_B7518C == 0.0 )
          {
            if ( *(_BYTE *)(this + 1152) )
            {
LABEL_113:
              *(_DWORD *)(this + 1156) = 0;
              *(_DWORD *)(this + 1168) = 1;
              *(_DWORD *)(this + 1160) = 0;
              goto LABEL_169;
            }
            v48 = v89;
            *(_DWORD *)(this + 1156) = v27;
            *(_DWORD *)(this + 1168) = v44;
            *(_DWORD *)(this + 1160) = (unsigned __int64)v48;
LABEL_169:
            v63 = v93;
            v64 = **(_DWORD **)(v93 + 100);
            v86[0] = *(_DWORD *)(v93 + 100);
            v83 = __readeflags();
            v84 = dword_16C6D3C - (_DWORD)off_16F2FD9;
            __writeeflags(v83);
            v85 = _InterlockedExchange(v86, v84);
            (*(void (__stdcall **)(__int32, int, __int32))(v64 + 24))(v85, v63 + 8, v86[0]);
          }
          else if ( *(_BYTE *)(this + 1152) )
          {
            goto LABEL_113;
          }
          break;
        case 6:
          if ( v22[4307] <= 0.0
            || *(_BYTE *)(this + 1152)
            || v22[4039] != 0.0
            && v94 != 0.0
            && *(_DWORD *)(this + 828)
            && *(_DWORD *)(this + 1352) == *(_DWORD *)(this + 1356)
            && *(_DWORD *)(this + 1320) == *(_DWORD *)(this + 1324)
            || v87 && byte_B739F0 != 1 )
          {
            v27 = 0;
            v49 = 1000000;
            v89 = 0.0;
          }
          else if ( dword_B74F70 == 3 )
          {
            v49 = (unsigned __int64)((v22[4307] - 400.0) * 6.8965516);
            v95 = *(float *)&v49;
            if ( v49 < 0 )
            {
              *(float *)&v49 = 0.0;
              v95 = 0.0;
            }
            v27 = 0;
            v89 = (double)SLODWORD(v95) * flt_B75264;
            if ( v89 >= -10000.0 )
            {
              if ( v89 > 10000.0 )
                v89 = 10000.0;
            }
            else
            {
              v89 = -10000.0;
            }
          }
          else
          {
            v50 = *(float *)(this + 1276);
            v89 = 0.0;
            v51 = (unsigned __int64)(v50 / v22[4307]);
            v49 = v51;
            v52 = (_DWORD)v51 == 0;
            if ( (v51 & 0x80000000) != 0LL )
            {
              v49 = -(int)v51;
              v52 = (_DWORD)v51 == 0;
            }
            if ( v52 || v49 > 1000000 )
            {
              v27 = 0;
              v49 = 1000000;
            }
            else
            {
              v53 = (unsigned __int64)(flt_B75288 * v22[4307] + flt_B75264 * 10000.0);
              v27 = v53;
              if ( (v53 & 0x80000000) == 0LL )
              {
                if ( (int)v53 > 10000 )
                  v27 = 10000;
              }
              else
              {
                v27 = 0;
              }
            }
          }
          if ( flt_B752D0 != 0.0 && !*(_BYTE *)(this + 1152) )
          {
            v54 = *(_DWORD *)(this + 1232) - v49;
            v55 = (unsigned __int64)flt_B752D0;
            if ( v54 <= 10000 * (int)v55 && v54 >= -10000 * (int)v55 && (v27 || !*(_DWORD *)(this + 1220)) )
              break;
          }
          v56 = v89;
          *(float *)(this + 1232) = *(float *)&v49;
          *(_DWORD *)(this + 1220) = v27;
          *(_DWORD *)(this + 1224) = (unsigned __int64)v56;
          goto LABEL_169;
        case 7:
          if ( v22[4039] <= 0.0 || v94 == 0.0 || *(_BYTE *)(this + 1152) || v87 && byte_B739F0 != 1 )
            goto LABEL_160;
          v57 = (unsigned __int64)(*(float *)(this + 1280) / v94);
          v58 = v57;
          v59 = (_DWORD)v57 == 0;
          if ( (v57 & 0x80000000) != 0LL )
          {
            v58 = -(int)v57;
            v59 = (_DWORD)v57 == 0;
          }
          if ( v59 || v58 > 2000000 )
          {
LABEL_160:
            v58 = 1000000;
LABEL_161:
            v27 = 0;
            goto LABEL_162;
          }
          v60 = (unsigned __int64)(flt_B7533C * v22[4039] * 10000.0 + flt_B75318 * 10000.0);
          v27 = v60;
          if ( (v60 & 0x80000000) != 0LL )
            goto LABEL_161;
          if ( (int)v60 > 10000 )
            v27 = 10000;
LABEL_162:
          if ( flt_B75384 != 0.0 && !*(_BYTE *)(this + 1152) )
          {
            v61 = *(_DWORD *)(this + 1248) - v58;
            v62 = (unsigned __int64)flt_B75384;
            if ( v61 <= 10000 * (int)v62 && v61 >= -10000 * (int)v62 && (v27 || !*(_DWORD *)(this + 1236)) )
              break;
          }
          *(_DWORD *)(this + 1248) = v58;
          *(_DWORD *)(this + 1236) = v27;
          goto LABEL_169;
        case 8:
          if ( v87 || *(_BYTE *)(this + 1152) )
            break;
          if ( dword_B74F70 == 3 )
          {
            v65 = *(_DWORD *)(this + 1304);
            v66 = *(_DWORD *)(this + 1308);
            if ( v65 != v66 )
            {
              *(_DWORD *)(this + 1308) = v65;
              if ( v66 )
                *(double *)(this + 1472) = v90 * 0.0033333334 * 40000.0 + *(double *)(this + 1472);
              v28 = dword_B74F70;
            }
          }
          if ( *(double *)(this + 1488) == 0.0 && *(double *)(this + 1472) == 0.0 && *(double *)(this + 1480) == 0.0 )
            break;
          v98 = 0;
          if ( dword_B678E8 )
          {
            sub_43A310((double *)(dword_B678E8 + 32), (double *)(this + 1472), v97);
            v28 = dword_B74F70;
          }
          if ( v28 == 3 && *(_DWORD *)(this + 1312) )
          {
            v99 = 1;
LABEL_185:
            v98 = 1;
            goto LABEL_186;
          }
          v68 = *(_DWORD *)(this + 1312);
          if ( !v68 )
            goto LABEL_185;
          v69 = *(_DWORD *)(this + 1324);
          if ( !v69 || dword_B75000 || v69 != v68 )
            goto LABEL_185;
          v98 = (unsigned __int64)v97[0];
          v99 = (unsigned __int64)-v97[2];
LABEL_186:
          v67 = (unsigned __int64)(sqrt(
                                     *(double *)(this + 1480) * *(double *)(this + 1480)
                                   + *(double *)(this + 1488) * *(double *)(this + 1488)
                                   + *(double *)(this + 1472) * *(double *)(this + 1472))
                                 * (flt_B7545C
                                  * 0.1));
          *(_DWORD *)(this + 1252) = v67;
          if ( (int)v67 >= -10000 )
          {
            if ( (int)v67 > 10000 )
              *(_DWORD *)(this + 1252) = 10000;
          }
          else
          {
            *(_DWORD *)(this + 1252) = -10000;
          }
          v86[0] = 1073742144;
          *(_DWORD *)(v29 + 44) = &v98;
          (*(void (__stdcall **)(_DWORD, int, __int32))(**(_DWORD **)(v29 + 100) + 24))(
            *(_DWORD *)(v29 + 100),
            v29 + 8,
            v86[0]);
          (*(void (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(v29 + 100) + 28))(*(_DWORD *)(v29 + 100), 1, 0);
          break;
        case 9:
          if ( v90 == 0.0 )
            goto LABEL_232;
          v70 = *(_DWORD *)(this + 1288);
          if ( v70 )
            goto LABEL_200;
          if ( dword_B74F70 != 3 )
            goto LABEL_233;
          if ( !*(_DWORD *)(this + 1296) )
            goto LABEL_236;
LABEL_200:
          if ( !v87 || byte_B739F0 == 1 )
          {
            if ( dword_B74F70 == 3 )
            {
              v71 = v90 * 0.0033333334;
              v72 = (unsigned __int64)(10000.0 * v71);
              if ( v70 )
              {
                v27 = 0;
                v89 = v71 * flt_B753A8 * 10000.0;
              }
              else if ( *(_DWORD *)(this + 1296) )
              {
                v73 = v71 * flt_B753A8 * 8000.0;
                v89 = v73;
                v74 = (unsigned __int64)(v73 * 0.75);
                v75 = *(float *)(this + 1284) / v90;
                v27 = v74;
                v72 = (unsigned __int64)(v75 + v75);
              }
              goto LABEL_213;
            }
            v72 = (unsigned __int64)(*(float *)(this + 1284) / v90);
            if ( v72 <= 2000000 )
            {
              v76 = (unsigned __int64)(flt_B753A8 * 10000.0);
              v27 = v76;
              v89 = (double)*(int *)(this + 1256) * flt_B75414 * v91;
              if ( (int)v76 <= 10000 )
              {
                if ( (v76 & 0x80000000) != 0LL )
                  v27 = 0;
              }
              else
              {
                v27 = 10000;
              }
LABEL_213:
              if ( v89 <= 10000.0 )
              {
                if ( v89 < -10000.0 )
                  v89 = -10000.0;
              }
              else
              {
                v89 = 10000.0;
              }
            }
            else
            {
              v27 = 0;
              v72 = 1000000;
              v89 = 0.0;
            }
            if ( !*(_DWORD *)(this + 1292) && !*(_DWORD *)(this + 1300) )
            {
              v86[0] = 536871168;
              goto LABEL_230;
            }
            if ( flt_B75438 == 0.0 )
            {
LABEL_226:
              if ( *(_BYTE *)(this + 1152) )
                goto LABEL_227;
              v80 = v89;
              *(_DWORD *)(this + 1256) = v27;
              v79 = (unsigned __int64)v80;
              *(_DWORD *)(this + 1268) = v72;
            }
            else
            {
              if ( !*(_BYTE *)(this + 1152) )
              {
                v77 = *(_DWORD *)(this + 1268) - v72;
                v78 = (unsigned __int64)flt_B75438;
                if ( v77 > 10000 * (int)v78 || v77 < -10000 * (int)v78 || !v27 && *(_DWORD *)(this + 1256) )
                  goto LABEL_226;
LABEL_231:
                v81 = *(_DWORD *)(this + 1296);
                *(_DWORD *)(this + 1292) = *(_DWORD *)(this + 1288);
                *(_DWORD *)(this + 1300) = v81;
                break;
              }
LABEL_227:
              LODWORD(v79) = 0;
              *(_DWORD *)(this + 1256) = 0;
              *(_DWORD *)(this + 1268) = 1000000;
            }
            *(_DWORD *)(this + 1260) = v79;
            v86[0] = 1073742080;
LABEL_230:
            (*(void (__stdcall **)(_DWORD, int, __int32))(**(_DWORD **)(v93 + 100) + 24))(
              *(_DWORD *)(v93 + 100),
              v93 + 8,
              v86[0]);
            goto LABEL_231;
          }
LABEL_232:
          if ( dword_B74F70 == 3 )
            goto LABEL_236;
LABEL_233:
          if ( !*(_DWORD *)(this + 1288) && *(_DWORD *)(this + 1292) )
            goto LABEL_240;
          if ( dword_B74F70 == 3 )
          {
LABEL_236:
            if ( !*(_DWORD *)(this + 1288)
              && !*(_DWORD *)(this + 1296)
              && (*(_DWORD *)(this + 1292) || *(_DWORD *)(this + 1300)) )
            {
LABEL_240:
              v82 = v93;
              *(_DWORD *)(this + 1288) = 0;
              *(_DWORD *)(this + 1292) = 0;
              *(_DWORD *)(this + 1296) = 0;
              *(_DWORD *)(this + 1300) = 0;
              (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v82 + 100) + 32))(*(_DWORD *)(v82 + 100));
            }
          }
          break;
        default:
          break;
      }
    }
    result = ++v96;
    if ( v96 >= 11 )
      break;
    v22 = (float *)dword_91E07C;
  }
  *(double *)(this + 1472) = 0.0;
  *(double *)(this + 1480) = 0.0;
  *(double *)(this + 1488) = 0.0;
  return result;
}
