void __thiscall sub_463CE0(float *this)
{
  _DWORD *v2; // eax
  void *v3; // ecx
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // edx
  _DWORD *v13; // ecx
  int v14; // edx
  float *v15; // esi
  int v16; // eax
  int v17; // eax
  int v18; // eax
  _DWORD *v19; // ecx
  float *v20; // edi
  bool v21; // cf
  double v22; // st7
  unsigned __int64 v23; // rax
  double v24; // st7
  unsigned __int64 v25; // rax
  double v26; // st7
  double v27; // st7
  float v28; // eax
  bool v29; // c0
  bool v30; // c3
  double v31; // st7
  float v32; // eax
  double v33; // st7
  float v34; // eax
  double v35; // st7
  float v36; // eax
  bool v37; // zf
  unsigned int i; // eax
  _DWORD *v39; // ecx
  float *v40; // edi
  double v41; // st7
  unsigned __int64 v42; // rax
  double v43; // st7
  unsigned __int64 v44; // rax
  double v45; // st7
  double v46; // st7
  float v47; // edx
  bool v48; // c0
  bool v49; // c3
  double v50; // st7
  float v51; // edx
  double v52; // st7
  float v53; // edx
  double v54; // st7
  float v55; // edx
  unsigned int j; // eax
  int v57; // eax
  _DWORD *v58; // ecx
  float *v59; // edi
  double v60; // st7
  unsigned __int64 v61; // rax
  double v62; // st7
  unsigned __int64 v63; // rax
  double v64; // st7
  double v65; // st7
  float v66; // edx
  bool v67; // c0
  bool v68; // c3
  double v69; // st7
  float v70; // edx
  double v71; // st7
  float v72; // edx
  double v73; // st7
  float v74; // edx
  unsigned int k; // eax
  int v76; // eax
  int v77; // eax
  int v78; // eax
  int v79; // edx
  int v80; // ecx
  int v81; // ecx
  int v82; // edi
  double v83; // st7
  _DWORD *v84; // [esp+1Ch] [ebp-248h]
  _DWORD *v85; // [esp+1Ch] [ebp-248h]
  _DWORD *v86; // [esp+1Ch] [ebp-248h]
  unsigned int v87; // [esp+34h] [ebp-230h]
  unsigned int v88; // [esp+34h] [ebp-230h]
  unsigned int v89; // [esp+34h] [ebp-230h]
  int v90; // [esp+3Ch] [ebp-228h]
  int v91; // [esp+40h] [ebp-224h]
  int v92; // [esp+40h] [ebp-224h]
  int v93; // [esp+40h] [ebp-224h]
  int v94; // [esp+6Ch] [ebp-1F8h]
  int v95; // [esp+70h] [ebp-1F4h]
  int v96; // [esp+74h] [ebp-1F0h]
  int v97; // [esp+80h] [ebp-1E4h]
  int v98; // [esp+84h] [ebp-1E0h] BYREF
  int v99; // [esp+88h] [ebp-1DCh]
  int v100; // [esp+8Ch] [ebp-1D8h]
  _DWORD *v101; // [esp+94h] [ebp-1D0h]
  char v102; // [esp+99h] [ebp-1CBh]
  char v103; // [esp+9Ah] [ebp-1CAh]
  char v104; // [esp+9Bh] [ebp-1C9h]
  int v105; // [esp+9Ch] [ebp-1C8h]
  int v106; // [esp+A4h] [ebp-1C0h] BYREF
  int v107; // [esp+A8h] [ebp-1BCh]
  _BYTE v108[12]; // [esp+C4h] [ebp-1A0h] BYREF
  _BYTE v109[52]; // [esp+D0h] [ebp-194h] BYREF
  _BYTE v110[16]; // [esp+104h] [ebp-160h] BYREF
  _DWORD v111[84]; // [esp+114h] [ebp-150h] BYREF

  if ( *(_DWORD *)this )
  {
    v104 = 0;
    v103 = 0;
    v102 = 0;
    this[287] = 0.0;
    v101 = 0;
    this[336] = 0.0;
    this[338] = 0.0;
    this[339] = 0.0;
    this[328] = 0.0;
    this[330] = 0.0;
    this[331] = 0.0;
    this[332] = 0.0;
    this[334] = 0.0;
    this[335] = 0.0;
    v105 = 0;
    while ( 1 )
    {
      if ( v105 )
      {
        if ( v105 == 1 )
        {
          v106 = 0;
        }
        else if ( v105 == 2 )
        {
          v106 = 1;
        }
        else if ( v106 < 0 )
        {
          goto LABEL_96;
        }
      }
      else
      {
        v106 = 2;
      }
      v2 = *(_DWORD **)this;
      if ( *(_DWORD *)(44 * v106 + *(_DWORD *)this + 8076) != 2 )
        goto LABEL_96;
      v3 = *(void **)(*(_DWORD *)this + 44 * v106 + 8108);
      if ( !v3 )
        goto LABEL_96;
      if ( (v2[1046] & 0x100) != 0 )
      {
        if ( v3 == &unk_758F48 )
        {
          v97 = 0;
        }
        else
        {
          if ( v3 == &unk_758F58 )
            goto LABEL_31;
          if ( v3 == &unk_758F68 )
          {
            v97 = 4;
          }
          else
          {
            if ( v3 == &unk_758F78 )
              goto LABEL_31;
            if ( v3 == &unk_758F88 )
            {
              v97 = 8;
            }
            else
            {
              if ( v3 == &unk_758F98 )
                goto LABEL_31;
              if ( v3 == &unk_758FA8 )
              {
                v97 = 12;
              }
              else
              {
                if ( v3 == &unk_758FB8 )
                  goto LABEL_31;
                if ( v3 == &unk_758FC8 )
                {
                  v97 = 16;
                }
                else
                {
                  if ( v3 == &unk_758FD8 )
                    goto LABEL_31;
                  if ( v3 != &unk_758FE8 )
                  {
                    if ( v3 == &unk_758FF8 )
                    {
LABEL_31:
                      off_16C93D8();
                      return;
                    }
                    goto LABEL_33;
                  }
                  v97 = 20;
                }
              }
            }
          }
        }
        v4 = v2 + 867;
        if ( v2 != (_DWORD *)-3468 )
          goto LABEL_85;
      }
LABEL_33:
      if ( (v2[1303] & 0x100) == 0 )
        goto LABEL_59;
      if ( v3 == &unk_759048 )
      {
        v97 = 0;
      }
      else if ( v3 == &unk_759058 )
      {
        v97 = 0;
      }
      else if ( v3 == &unk_759068 )
      {
        v97 = 4;
      }
      else if ( v3 == &unk_759078 )
      {
        v97 = 4;
      }
      else if ( v3 == &unk_759088 )
      {
        v97 = 8;
      }
      else if ( v3 == &unk_759098 )
      {
        v97 = 8;
      }
      else if ( v3 == &unk_7590A8 )
      {
        v97 = 12;
      }
      else if ( v3 == &unk_7590B8 )
      {
        v97 = 12;
      }
      else if ( v3 == &unk_7590C8 )
      {
        v97 = 16;
      }
      else if ( v3 == &unk_7590D8 )
      {
        v97 = 16;
      }
      else if ( v3 == &unk_7590E8 )
      {
        v97 = 20;
      }
      else
      {
        if ( v3 != &unk_7590F8 )
          goto LABEL_59;
        v97 = 20;
      }
      v4 = v2 + 1124;
      if ( v2 != (_DWORD *)-4496 )
        goto LABEL_85;
LABEL_59:
      if ( (v2[1560] & 0x100) != 0 )
      {
        if ( v3 == &unk_759148 )
        {
          v97 = 0;
        }
        else if ( v3 == &unk_759158 )
        {
          v97 = 0;
        }
        else if ( v3 == &unk_759168 )
        {
          v97 = 4;
        }
        else if ( v3 == &unk_759178 )
        {
          v97 = 4;
        }
        else if ( v3 == &unk_759188 )
        {
          v97 = 8;
        }
        else if ( v3 == &unk_759198 )
        {
          v97 = 8;
        }
        else if ( v3 == &unk_7591A8 )
        {
          v97 = 12;
        }
        else if ( v3 == &unk_7591B8 )
        {
          v97 = 12;
        }
        else if ( v3 == &unk_7591C8 )
        {
          v97 = 16;
        }
        else if ( v3 == &unk_7591D8 )
        {
          v97 = 16;
        }
        else if ( v3 == &unk_7591E8 )
        {
          v97 = 20;
        }
        else
        {
          if ( v3 != &unk_7591F8 )
            goto LABEL_96;
          v97 = 20;
        }
        v4 = v2 + 1381;
        if ( v2 != (_DWORD *)-5524 )
        {
LABEL_85:
          v5 = v4[32];
          if ( v5 )
          {
            if ( !v105 )
              v101 = v4;
            memset(&v111[4], 0, 0x13Cu);
            v111[4] = 316;
            if ( (*(int (__cdecl **)(int, _DWORD *, int, int))(*(_DWORD *)v5 + 56))(v5, &v111[4], v97, 1) >= 0
              && (v111[7] & 1) != 0 )
            {
              if ( v100 )
              {
                if ( v100 == 1 )
                {
                  *((_DWORD *)this + 338) = v95;
                  *((_DWORD *)this + 330) = v4;
                  *((_DWORD *)this + 334) = v94;
                }
                else if ( v100 == 2 )
                {
                  *((_DWORD *)this + 339) = v95;
                  *((_DWORD *)this + 331) = v4;
                  *((_DWORD *)this + 335) = v94;
                }
              }
              else
              {
                *((_DWORD *)this + 336) = v95;
                *((_DWORD *)this + 328) = v4;
                *((_DWORD *)this + 332) = v94;
              }
            }
          }
        }
      }
LABEL_96:
      if ( ++v100 >= 3 )
      {
        v6 = *((_DWORD *)this + 328);
        if ( v6 )
        {
          v7 = *((_DWORD *)this + 332);
          if ( v7 )
          {
            if ( !*((_DWORD *)this + 330) || dword_B74FDC )
            {
              this[338] = this[336];
              *((_DWORD *)this + 330) = v6;
              *((_DWORD *)this + 334) = v7;
              v8 = dword_B74FE4;
              dword_B74FDC = 1;
              if ( dword_B74FE4 > 1 || (v8 = dword_B74FE8, dword_B74FE8 < 1) )
                dword_B74FDC = v8;
            }
            if ( !*((_DWORD *)this + 331) || dword_B75000 )
            {
              v9 = *((_DWORD *)this + 328);
              v10 = *((_DWORD *)this + 332);
              this[339] = this[336];
              *((_DWORD *)this + 331) = v9;
              *((_DWORD *)this + 335) = v10;
              v11 = dword_B75008;
              dword_B75000 = 1;
              if ( dword_B75008 > 1 || (v11 = dword_B7500C, dword_B7500C < 1) )
                dword_B75000 = v11;
            }
          }
        }
        if ( dword_B74F70 == 3 )
        {
          if ( v98 )
          {
            v12 = *(_DWORD *)(v98 + 128);
            if ( v12 )
            {
              memset(v111, 0, 0x13Cu);
              v111[0] = 316;
              if ( (*(int (__cdecl **)(int, _DWORD *, int, int))(*(_DWORD *)v12 + 56))(v12, v111, 4, 1) >= 0
                && (v111[3] & 1) != 0 )
              {
                *((_DWORD *)this + 328) = v96;
                *((_DWORD *)this + 336) = 4;
                *((_DWORD *)this + 332) = 1;
                *((_DWORD *)this + 330) = v96;
                *((_DWORD *)this + 338) = 4;
                *((_DWORD *)this + 334) = 1;
                *((_DWORD *)this + 331) = v96;
                *((_DWORD *)this + 339) = 4;
                *((_DWORD *)this + 335) = 1;
                if ( (*(int (__cdecl **)(_DWORD, _BYTE *, _DWORD, int))(**(_DWORD **)(v96 + 128) + 56))(
                       *(_DWORD *)(v96 + 128),
                       v110,
                       0,
                       1) >= 0
                  && (v110[12] & 1) != 0 )
                {
                  if ( !dword_B74FDC )
                    this[338] = 0.0;
                  if ( !dword_B75000 )
                    this[339] = 0.0;
                }
              }
            }
          }
        }
        if ( *(_DWORD *)(*(_DWORD *)this + 3596) )
        {
          dword_B69640[0] = 0;
          this[343] = 0.0;
          dword_B69644 = 0;
          this[344] = 0.0;
          dword_B69648 = 0;
          this[345] = 0.0;
          dword_B6964C = 0;
          this[346] = 0.0;
          dword_B69650 = 0;
          this[347] = 0.0;
          dword_B69654 = 0;
          this[348] = 0.0;
          dword_B69658 = 0;
          this[349] = 0.0;
          dword_B6965C = 0;
          this[350] = 0.0;
          dword_B69660 = 0;
          v13 = *(_DWORD **)this;
          this[340] = 0.0;
          if ( (*(int (__cdecl **)(_DWORD, BOOL (__stdcall *)(int, int), _DWORD, int))(*(_DWORD *)v13[899] + 16))(
                 v13[899],
                 sub_45DC30,
                 0,
                 3) >= 0 )
          {
            *((_DWORD *)this + 340) = dword_B69660;
            this[343] = *(float *)dword_B69640;
            *((_DWORD *)this + 344) = dword_B69644;
            *((_DWORD *)this + 345) = dword_B69648;
            *((_DWORD *)this + 346) = dword_B6964C;
            *((_DWORD *)this + 347) = dword_B69650;
            *((_DWORD *)this + 348) = dword_B69654;
            *((_DWORD *)this + 349) = dword_B69658;
            *((_DWORD *)this + 350) = dword_B6965C;
          }
        }
        if ( *(_DWORD *)(*(_DWORD *)this + 4624) )
        {
          dword_B69660 = 0;
          this[341] = 0.0;
          dword_B69640[0] = 0;
          this[351] = 0.0;
          dword_B69644 = 0;
          this[352] = 0.0;
          dword_B69648 = 0;
          this[353] = 0.0;
          dword_B6964C = 0;
          this[354] = 0.0;
          dword_B69650 = 0;
          this[355] = 0.0;
          dword_B69654 = 0;
          this[356] = 0.0;
          dword_B69658 = 0;
          this[357] = 0.0;
          dword_B6965C = 0;
          this[358] = 0.0;
          if ( (*(int (__cdecl **)(_DWORD, BOOL (__stdcall *)(int, int), _DWORD, int))(**(_DWORD **)(*(_DWORD *)this + 4624)
                                                                                     + 16))(
                 *(_DWORD *)(*(_DWORD *)this + 4624),
                 sub_45DC30,
                 0,
                 3) >= 0 )
          {
            *((_DWORD *)this + 341) = dword_B69660;
            this[351] = *(float *)dword_B69640;
            *((_DWORD *)this + 352) = dword_B69644;
            *((_DWORD *)this + 353) = dword_B69648;
            *((_DWORD *)this + 354) = dword_B6964C;
            *((_DWORD *)this + 355) = dword_B69650;
            *((_DWORD *)this + 356) = dword_B69654;
            *((_DWORD *)this + 357) = dword_B69658;
            *((_DWORD *)this + 358) = dword_B6965C;
          }
        }
        if ( *(_DWORD *)(*(_DWORD *)this + 5652) )
        {
          dword_B69660 = 0;
          this[342] = 0.0;
          dword_B69640[0] = 0;
          this[359] = 0.0;
          dword_B69644 = 0;
          this[360] = 0.0;
          dword_B69648 = 0;
          this[361] = 0.0;
          dword_B6964C = 0;
          this[362] = 0.0;
          dword_B69650 = 0;
          this[363] = 0.0;
          dword_B69654 = 0;
          this[364] = 0.0;
          dword_B69658 = 0;
          this[365] = 0.0;
          dword_B6965C = 0;
          this[366] = 0.0;
          if ( (*(int (__cdecl **)(_DWORD, BOOL (__stdcall *)(int, int), _DWORD, int))(**(_DWORD **)(*(_DWORD *)this + 5652)
                                                                                     + 16))(
                 *(_DWORD *)(*(_DWORD *)this + 5652),
                 sub_45DC30,
                 0,
                 3) >= 0 )
          {
            *((_DWORD *)this + 342) = dword_B69660;
            this[359] = *(float *)dword_B69640;
            *((_DWORD *)this + 360) = dword_B69644;
            *((_DWORD *)this + 361) = dword_B69648;
            *((_DWORD *)this + 362) = dword_B6964C;
            *((_DWORD *)this + 363) = dword_B69650;
            *((_DWORD *)this + 364) = dword_B69654;
            *((_DWORD *)this + 365) = dword_B69658;
            *((_DWORD *)this + 366) = dword_B6965C;
          }
        }
        v14 = 0;
        v90 = 0;
        while ( 1 )
        {
          v15 = &this[26 * v14];
          *((_BYTE *)v15 + 4) = 0;
          v15[25] = 0.0;
          v15[26] = 0.0;
          if ( !dword_B74F94 || flt_B74FB8 == 0.0 )
            goto LABEL_276;
          switch ( v14 )
          {
            case 0:
              if ( flt_B750D8 == 0.0 )
                goto LABEL_273;
              if ( flt_B750FC == 0.0 )
                goto LABEL_273;
              v16 = *((_DWORD *)this + 328);
              if ( !v16 || !*((_DWORD *)this + 332) || dword_B74F94 < 1 )
                goto LABEL_273;
              *((_DWORD *)v15 + 26) = v16;
              this[289] = 0.0;
              this[290] = 0.0;
              this[291] = 0.0;
              this[292] = 0.0;
              v15[4] = NAN;
              v15[7] = NAN;
              *((_DWORD *)v15 + 2) = 56;
              *((_DWORD *)v15 + 3) = 18;
              v15[5] = 0.0;
              *((_DWORD *)v15 + 6) = 10000;
              v15[8] = 0.0;
              *((_DWORD *)v15 + 9) = 1;
              *((_DWORD *)v15 + 10) = this + 336;
              *((_DWORD *)v15 + 11) = this + 332;
              v15[12] = 0.0;
              *((_DWORD *)v15 + 13) = 16;
              *((_DWORD *)v15 + 14) = this + 289;
              v15[15] = 0.0;
              goto LABEL_274;
            case 1:
              if ( flt_B751B0 == 0.0 )
                goto LABEL_273;
              if ( flt_B751D4 == 0.0 )
                goto LABEL_273;
              v17 = *((_DWORD *)this + 328);
              if ( !v17 || !*((_DWORD *)this + 332) || dword_B74F94 < 2 )
                goto LABEL_273;
              *((_DWORD *)v15 + 26) = v17;
              *((_DWORD *)this + 294) = (unsigned __int64)(flt_B751B0 * 10000.0);
              *((_DWORD *)this + 296) = (unsigned __int64)(flt_B751D4 * 10000.0);
              *((_DWORD *)this + 295) = (unsigned __int64)(flt_B751B0 * 10000.0);
              *((_DWORD *)this + 297) = (unsigned __int64)(flt_B751D4 * 10000.0);
              this[293] = 0.0;
              this[298] = 0.0;
              v15[4] = NAN;
              v15[7] = NAN;
              *((_DWORD *)v15 + 2) = 56;
              *((_DWORD *)v15 + 3) = 18;
              v15[5] = 0.0;
              *((_DWORD *)v15 + 6) = 10000;
              v15[8] = 0.0;
              *((_DWORD *)v15 + 9) = 1;
              *((_DWORD *)v15 + 10) = this + 336;
              *((_DWORD *)v15 + 11) = this + 332;
              v15[12] = 0.0;
              *((_DWORD *)v15 + 13) = 24;
              *((_DWORD *)v15 + 14) = this + 293;
              v15[15] = 0.0;
              goto LABEL_274;
            case 2:
              if ( flt_B751F8 == 0.0 )
                goto LABEL_273;
              if ( flt_B7521C == 0.0 )
                goto LABEL_273;
              v18 = *((_DWORD *)this + 328);
              if ( !v18 || !*((_DWORD *)this + 332) || dword_B74F94 < 2 )
                goto LABEL_273;
              *((_DWORD *)v15 + 26) = v18;
              *((_DWORD *)this + 300) = (unsigned __int64)(flt_B751F8 * 10000.0);
              *((_DWORD *)this + 302) = (unsigned __int64)(flt_B7521C * 10000.0);
              *((_DWORD *)this + 301) = (unsigned __int64)(flt_B751F8 * 10000.0);
              *((_DWORD *)this + 303) = (unsigned __int64)(flt_B7521C * 10000.0);
              this[299] = 0.0;
              this[304] = 0.0;
              v15[4] = NAN;
              v15[7] = NAN;
              *((_DWORD *)v15 + 2) = 56;
              *((_DWORD *)v15 + 3) = 18;
              v15[5] = 0.0;
              *((_DWORD *)v15 + 6) = 10000;
              v15[8] = 0.0;
              *((_DWORD *)v15 + 9) = 1;
              *((_DWORD *)v15 + 10) = this + 336;
              *((_DWORD *)v15 + 11) = this + 332;
              v15[12] = 0.0;
              *((_DWORD *)v15 + 13) = 24;
              *((_DWORD *)v15 + 14) = this + 299;
              v15[15] = 0.0;
              goto LABEL_274;
            case 3:
              if ( dword_B74F94 >= 3 && (*(_DWORD *)(*(_DWORD *)this + 4184) & 0x100) != 0 && *((_DWORD *)this + 340) )
              {
                v19 = v108;
                v87 = 0;
                v84 = v108;
                v20 = (float *)&unk_B75480;
                v91 = 8;
                do
                {
                  v21 = v87 < *((_DWORD *)this + 340);
                  v19[5] = 0;
                  *v19 = 0;
                  if ( v21 )
                  {
                    v22 = v20[216] * 10000.0;
                    v84[3] = (unsigned __int64)(*v20 * 10000.0);
                    v23 = (unsigned __int64)v22;
                    v24 = v20[432] * 10000.0;
                    v84[1] = v23;
                    v25 = (unsigned __int64)v24;
                    v26 = v20[648] * 10000.0;
                    v84[4] = v25;
                    v84[2] = (unsigned __int64)v26;
                    v19 = v84;
                  }
                  else
                  {
                    v27 = v20[2];
                    v28 = v20[3];
                    *v20 = 0.0;
                    v29 = v27 < *v20;
                    v30 = v27 == *v20;
                    v19[2] = 0;
                    v19[1] = 0;
                    if ( v29 || v30 )
                    {
                      if ( *v20 > (double)v28 )
                        *v20 = v28;
                    }
                    else
                    {
                      *v20 = v27;
                    }
                    v31 = v20[218];
                    v32 = v20[219];
                    v20[216] = 0.0;
                    if ( v31 <= v20[216] )
                    {
                      if ( v20[216] > (double)v32 )
                        v20[216] = v32;
                    }
                    else
                    {
                      v20[216] = v31;
                    }
                    v33 = v20[434];
                    v34 = v20[435];
                    v20[432] = 0.0;
                    if ( v33 <= v20[432] )
                    {
                      if ( v20[432] > (double)v34 )
                        v20[432] = v34;
                    }
                    else
                    {
                      v20[432] = v33;
                    }
                    v35 = v20[650];
                    v36 = v20[651];
                    v20[648] = 0.0;
                    if ( v35 <= v20[648] )
                    {
                      if ( v20[648] > (double)v36 )
                        v20[648] = v36;
                    }
                    else
                    {
                      v20[648] = v35;
                    }
                  }
                  v19 += 6;
                  v20 += 9;
                  v37 = v91 == 1;
                  ++v87;
                  v84 = v19;
                  --v91;
                }
                while ( !v37 );
                for ( i = 0; i < 8; ++i )
                {
                  if ( i )
                    *(&v98 + i) = 0;
                  else
                    v98 = 1;
                }
                *((_DWORD *)v15 + 26) = *(_DWORD *)this + 3468;
                v15[4] = NAN;
                v15[7] = NAN;
                *((_DWORD *)v15 + 2) = 56;
                *((_DWORD *)v15 + 3) = 17;
                v15[5] = 0.0;
                *((_DWORD *)v15 + 6) = 10000;
                v15[8] = 0.0;
                v15[9] = this[340];
                v15[12] = 0.0;
                *((_DWORD *)v15 + 10) = this + 343;
                *((_DWORD *)v15 + 11) = &v98;
                *((_DWORD *)v15 + 13) = 24 * *((_DWORD *)this + 340);
                *((_DWORD *)v15 + 14) = v108;
                v15[15] = 0.0;
              }
              goto LABEL_274;
            case 4:
              if ( dword_B74F94 >= 3 && (*(_DWORD *)(*(_DWORD *)this + 5212) & 0x100) != 0 && *((_DWORD *)this + 341) )
              {
                v39 = v109;
                v88 = 0;
                v85 = v109;
                v40 = (float *)&unk_B755A0;
                v92 = 8;
                do
                {
                  if ( v88 >= *((_DWORD *)this + 341) )
                  {
                    v46 = v40[2];
                    v47 = v40[3];
                    *v40 = 0.0;
                    v48 = v46 < *v40;
                    v49 = v46 == *v40;
                    v39[1] = 0;
                    *v39 = 0;
                    v39[2] = 0;
                    *(v39 - 1) = 0;
                    *(v39 - 3) = 0;
                    *(v39 - 2) = 0;
                    if ( v48 || v49 )
                    {
                      if ( *v40 > (double)v47 )
                        *v40 = v47;
                    }
                    else
                    {
                      *v40 = v46;
                    }
                    v50 = v40[218];
                    v51 = v40[219];
                    v40[216] = 0.0;
                    if ( v50 <= v40[216] )
                    {
                      if ( v40[216] > (double)v51 )
                        v40[216] = v51;
                    }
                    else
                    {
                      v40[216] = v50;
                    }
                    v52 = v40[434];
                    v53 = v40[435];
                    v40[432] = 0.0;
                    if ( v52 <= v40[432] )
                    {
                      if ( v40[432] > (double)v53 )
                        v40[432] = v53;
                    }
                    else
                    {
                      v40[432] = v52;
                    }
                    v54 = v40[650];
                    v55 = v40[651];
                    v40[648] = 0.0;
                    if ( v54 <= v40[648] )
                    {
                      if ( v40[648] > (double)v55 )
                        v40[648] = v55;
                    }
                    else
                    {
                      v40[648] = v54;
                    }
                  }
                  else
                  {
                    v41 = v40[216] * 10000.0;
                    *v85 = (unsigned __int64)(*v40 * 10000.0);
                    v42 = (unsigned __int64)v41;
                    v43 = v40[432] * 10000.0;
                    *(v85 - 2) = v42;
                    v44 = (unsigned __int64)v43;
                    v45 = v40[648] * 10000.0;
                    v85[1] = v44;
                    v39 = v85;
                    *(v85 - 1) = (unsigned __int64)v45;
                    v85[2] = 0;
                    *(v85 - 3) = 0;
                  }
                  v39 += 6;
                  v40 += 9;
                  v37 = v92 == 1;
                  ++v88;
                  v85 = v39;
                  --v92;
                }
                while ( !v37 );
                for ( j = 0; j < 8; ++j )
                {
                  if ( j )
                    *(&v98 + j) = 0;
                  else
                    v98 = 1;
                }
                *((_DWORD *)v15 + 26) = *(_DWORD *)this + 4496;
                v15[4] = NAN;
                v15[7] = NAN;
                *((_DWORD *)v15 + 2) = 56;
                *((_DWORD *)v15 + 3) = 17;
                v15[5] = 0.0;
                *((_DWORD *)v15 + 6) = 10000;
                v15[8] = 0.0;
                v15[9] = this[340];
                *((_DWORD *)v15 + 10) = this + 343;
                *((_DWORD *)v15 + 11) = &v98;
                v15[12] = 0.0;
                v57 = *((_DWORD *)this + 341);
                goto LABEL_209;
              }
              goto LABEL_274;
            case 5:
              if ( dword_B74F94 >= 3 && (*(_DWORD *)(*(_DWORD *)this + 6240) & 0x100) != 0 && *((_DWORD *)this + 342) )
              {
                v58 = v109;
                v89 = 0;
                v86 = v109;
                v59 = (float *)&unk_B756C0;
                v93 = 8;
                do
                {
                  if ( v89 >= *((_DWORD *)this + 342) )
                  {
                    v65 = v59[2];
                    v66 = v59[3];
                    *v59 = 0.0;
                    v67 = v65 < *v59;
                    v68 = v65 == *v59;
                    v58[1] = 0;
                    *v58 = 0;
                    v58[2] = 0;
                    *(v58 - 1) = 0;
                    *(v58 - 3) = 0;
                    *(v58 - 2) = 0;
                    if ( v67 || v68 )
                    {
                      if ( *v59 > (double)v66 )
                        *v59 = v66;
                    }
                    else
                    {
                      *v59 = v65;
                    }
                    v69 = v59[218];
                    v70 = v59[219];
                    v59[216] = 0.0;
                    if ( v69 <= v59[216] )
                    {
                      if ( v59[216] > (double)v70 )
                        v59[216] = v70;
                    }
                    else
                    {
                      v59[216] = v69;
                    }
                    v71 = v59[434];
                    v72 = v59[435];
                    v59[432] = 0.0;
                    if ( v71 <= v59[432] )
                    {
                      if ( v59[432] > (double)v72 )
                        v59[432] = v72;
                    }
                    else
                    {
                      v59[432] = v71;
                    }
                    v73 = v59[650];
                    v74 = v59[651];
                    v59[648] = 0.0;
                    if ( v73 <= v59[648] )
                    {
                      if ( v59[648] > (double)v74 )
                        v59[648] = v74;
                    }
                    else
                    {
                      v59[648] = v73;
                    }
                  }
                  else
                  {
                    v60 = v59[216] * 10000.0;
                    *v86 = (unsigned __int64)(*v59 * 10000.0);
                    v61 = (unsigned __int64)v60;
                    v62 = v59[432] * 10000.0;
                    *(v86 - 2) = v61;
                    v63 = (unsigned __int64)v62;
                    v64 = v59[648] * 10000.0;
                    v86[1] = v63;
                    v58 = v86;
                    *(v86 - 1) = (unsigned __int64)v64;
                    v86[2] = 0;
                    *(v86 - 3) = 0;
                  }
                  v58 += 6;
                  v59 += 9;
                  v37 = v93 == 1;
                  ++v89;
                  v86 = v58;
                  --v93;
                }
                while ( !v37 );
                for ( k = 0; k < 8; ++k )
                {
                  if ( k )
                    *(&v98 + k) = 0;
                  else
                    v98 = 1;
                }
                *((_DWORD *)v15 + 26) = *(_DWORD *)this + 5524;
                v15[4] = NAN;
                v15[7] = NAN;
                *((_DWORD *)v15 + 2) = 56;
                *((_DWORD *)v15 + 3) = 17;
                v15[5] = 0.0;
                *((_DWORD *)v15 + 6) = 10000;
                v15[8] = 0.0;
                v15[9] = this[340];
                *((_DWORD *)v15 + 10) = this + 343;
                *((_DWORD *)v15 + 11) = &v98;
                v15[12] = 0.0;
                v57 = *((_DWORD *)this + 342);
LABEL_209:
                *((_DWORD *)v15 + 13) = 24 * v57;
                *((_DWORD *)v15 + 14) = v108;
                v15[15] = 0.0;
              }
              goto LABEL_274;
            case 6:
              if ( flt_B75240 == 0.0 || flt_B75264 == 0.0 && flt_B75288 == 0.0 )
                goto LABEL_273;
              v76 = *((_DWORD *)this + 330);
              if ( !v76 || dword_B74F94 < 4 )
                goto LABEL_273;
              *((_DWORD *)v15 + 26) = v76;
              this[305] = 0.0;
              this[306] = 0.0;
              this[307] = 0.0;
              this[308] = 0.0;
              v15[4] = NAN;
              v15[7] = NAN;
              *((_DWORD *)v15 + 10) = this + 338;
              *((_DWORD *)v15 + 2) = 56;
              *((_DWORD *)v15 + 3) = 18;
              v15[5] = 0.0;
              *((_DWORD *)v15 + 6) = 10000;
              v15[8] = 0.0;
              *((_DWORD *)v15 + 9) = 1;
              *((_DWORD *)v15 + 11) = this + 334;
              v15[12] = 0.0;
              *((_DWORD *)v15 + 13) = 16;
              *((_DWORD *)v15 + 14) = this + 305;
              v15[15] = 0.0;
              goto LABEL_274;
            case 7:
              if ( flt_B752F4 == 0.0 || flt_B75318 == 0.0 && flt_B7533C == 0.0 )
                goto LABEL_273;
              v77 = *((_DWORD *)this + 331);
              if ( !v77 || dword_B74F94 < 3 )
                goto LABEL_273;
              *((_DWORD *)v15 + 26) = v77;
              this[309] = 0.0;
              this[310] = 0.0;
              this[311] = 0.0;
              this[312] = 0.0;
              v15[4] = NAN;
              v15[7] = NAN;
              *((_DWORD *)v15 + 10) = this + 339;
              *((_DWORD *)v15 + 2) = 56;
              *((_DWORD *)v15 + 3) = 18;
              v15[5] = 0.0;
              *((_DWORD *)v15 + 6) = 10000;
              v15[8] = 0.0;
              *((_DWORD *)v15 + 9) = 1;
              *((_DWORD *)v15 + 11) = this + 335;
              v15[12] = 0.0;
              *((_DWORD *)v15 + 13) = 16;
              *((_DWORD *)v15 + 14) = this + 309;
              v15[15] = 0.0;
              goto LABEL_274;
            case 8:
              if ( flt_B7545C == 0.0 )
                goto LABEL_273;
              v78 = *((_DWORD *)this + 328);
              if ( !v78 && !*((_DWORD *)this + 331) )
                goto LABEL_273;
              if ( dword_B74F94 < 2 )
                goto LABEL_273;
              if ( dword_B74F70 == 3 )
              {
                if ( !v78 )
                  goto LABEL_259;
                v79 = 2;
                v106 = 0;
                v98 = 1;
                v107 = 4;
                v99 = 1;
              }
              else
              {
                if ( !v78 )
                {
LABEL_259:
                  v80 = *((_DWORD *)this + 331);
                  v79 = 1;
                  v106 = *((_DWORD *)this + 339);
                  v98 = 1;
                  *((_DWORD *)v15 + 26) = v80;
                  goto LABEL_266;
                }
                v81 = *((_DWORD *)this + 331);
                if ( v81 && !dword_B75000 && v81 == v78 )
                {
                  v82 = *((_DWORD *)this + 339);
                  v106 = *((_DWORD *)this + 336);
                  v107 = v82;
                  v79 = 2;
                  v98 = 1;
                  v99 = 1;
                }
                else
                {
                  v79 = 1;
                  v106 = *((_DWORD *)this + 336);
                  v98 = 1;
                }
              }
              *((_DWORD *)v15 + 26) = v78;
LABEL_266:
              v37 = dword_B74F70 == 3;
              *((_DWORD *)v15 + 23) = 100000;
              v15[22] = 0.0;
              v15[21] = 0.0;
              *((_DWORD *)v15 + 20) = 10000;
              *((_DWORD *)v15 + 19) = 20;
              if ( v37 )
                *((_DWORD *)v15 + 4) = 300000;
              else
                *((_DWORD *)v15 + 4) = 150000;
              this[313] = 0.0;
              *((_DWORD *)v15 + 9) = v79;
              *((_DWORD *)v15 + 10) = &v106;
              *((_DWORD *)v15 + 2) = 56;
              *((_DWORD *)v15 + 3) = 18;
              v15[5] = 0.0;
              *((_DWORD *)v15 + 6) = 10000;
              v15[7] = NAN;
              v15[8] = 0.0;
              *((_DWORD *)v15 + 11) = &v98;
              *((_DWORD *)v15 + 12) = v15 + 19;
              *((_DWORD *)v15 + 13) = 4;
              *((_DWORD *)v15 + 14) = this + 313;
              v15[15] = 0.0;
LABEL_274:
              if ( *((_DWORD *)v15 + 26) )
              {
                off_16C9220();
                return;
              }
LABEL_276:
              v14 = ++v90;
              if ( v90 >= 11 )
                goto LABEL_277;
              break;
            case 9:
              if ( flt_B753A8 == 0.0 || dword_B74F94 < 2 )
              {
LABEL_273:
                v15[26] = 0.0;
              }
              else
              {
                v15[26] = this[328];
                this[314] = 0.0;
                this[315] = 0.0;
                this[316] = 0.0;
                this[317] = 0.0;
                v15[4] = NAN;
                v15[7] = NAN;
                *((_DWORD *)v15 + 10) = this + 336;
                *((_DWORD *)v15 + 2) = 56;
                *((_DWORD *)v15 + 3) = 18;
                v15[5] = 0.0;
                *((_DWORD *)v15 + 6) = 10000;
                v15[8] = 0.0;
                *((_DWORD *)v15 + 9) = 1;
                *((_DWORD *)v15 + 11) = this + 332;
                v15[12] = 0.0;
                *((_DWORD *)v15 + 13) = 16;
                *((_DWORD *)v15 + 14) = this + 314;
                v15[15] = 0.0;
              }
              goto LABEL_274;
            default:
              goto LABEL_274;
          }
        }
      }
    }
  }
LABEL_277:
  this[318] = 6283185.5 / flt_B75024;
  this[319] = 6283185.5 / flt_B75240;
  this[320] = 6283185.5 / flt_B752F4;
  v83 = 6283185.5 / flt_B753CC;
  this[322] = 0.0;
  this[323] = 0.0;
  *((_BYTE *)this + 1152) = 0;
  this[321] = v83;
}
