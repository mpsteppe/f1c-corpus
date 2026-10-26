int __thiscall sub_452530(int *this)
{
  int result; // eax
  _DWORD *v3; // eax
  int *v4; // ecx
  int *v5; // esi
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // edx
  int *v12; // eax
  int *v13; // eax
  _DWORD *v14; // ecx
  int v15; // ecx
  int *v16; // eax
  _DWORD *v17; // ecx
  int *v18; // eax
  _DWORD *v19; // ecx
  int *v20; // eax
  _DWORD *v21; // ecx
  int v22; // eax
  char *v23; // esi
  int *v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // eax
  _DWORD *v28; // ecx
  float *v29; // edi
  bool v30; // cf
  double v31; // st7
  __int64 v32; // rax
  double v33; // st7
  __int64 v34; // rax
  double v35; // st7
  double v36; // st7
  float v37; // eax
  bool v38; // c0
  bool v39; // c3
  double v40; // st7
  float v41; // eax
  bool v42; // c0
  bool v43; // c3
  double v44; // st7
  float v45; // eax
  bool v46; // c0
  bool v47; // c3
  double v48; // st7
  float v49; // eax
  bool v50; // c0
  bool v51; // c3
  bool v52; // zf
  unsigned int j; // eax
  _DWORD *v54; // ecx
  float *v55; // edi
  double v56; // st7
  __int64 v57; // rax
  double v58; // st7
  double v59; // st7
  float v60; // edx
  bool v61; // c0
  bool v62; // c3
  double v63; // st7
  float v64; // edx
  bool v65; // c0
  bool v66; // c3
  double v67; // st7
  float v68; // edx
  bool v69; // c0
  bool v70; // c3
  double v71; // st7
  float v72; // edx
  bool v73; // c0
  bool v74; // c3
  unsigned int k; // eax
  int v76; // ecx
  int *v77; // edx
  int v78; // eax
  int v79; // eax
  int v80; // eax
  int v81; // edx
  int v82; // ecx
  int v83; // ecx
  int v84; // eax
  int v85; // eax
  int v86; // edx
  int v87; // eax
  int v88; // ecx
  int v89; // edi
  double v90; // st7
  int v91; // [esp+74h] [ebp-1E0h]
  _DWORD *v92; // [esp+74h] [ebp-1E0h]
  unsigned int v93; // [esp+74h] [ebp-1E0h]
  int v94; // [esp+78h] [ebp-1DCh]
  int v95; // [esp+7Ch] [ebp-1D8h] BYREF
  int v96; // [esp+80h] [ebp-1D4h]
  int v97; // [esp+84h] [ebp-1D0h]
  int v98; // [esp+88h] [ebp-1CCh]
  char v99; // [esp+8Eh] [ebp-1C6h]
  char v100; // [esp+8Fh] [ebp-1C5h]
  int v101; // [esp+90h] [ebp-1C4h]
  int i; // [esp+94h] [ebp-1C0h]
  int *v103; // [esp+98h] [ebp-1BCh]
  int v104; // [esp+9Ch] [ebp-1B8h]
  float v105; // [esp+A0h] [ebp-1B4h]
  float v106; // [esp+A4h] [ebp-1B0h]
  float v107; // [esp+A8h] [ebp-1ACh]
  float v108; // [esp+ACh] [ebp-1A8h]
  float v109; // [esp+B0h] [ebp-1A4h]
  float v110; // [esp+B4h] [ebp-1A0h]
  float v111; // [esp+B8h] [ebp-19Ch]
  int v112; // [esp+BCh] [ebp-198h] BYREF
  int v113; // [esp+C0h] [ebp-194h]
  int v114; // [esp+C4h] [ebp-190h]
  int v115; // [esp+C8h] [ebp-18Ch]
  int v116; // [esp+CCh] [ebp-188h]
  int v117; // [esp+D0h] [ebp-184h]
  int v118; // [esp+D4h] [ebp-180h]
  int v119; // [esp+D8h] [ebp-17Ch] BYREF
  int v120; // [esp+DCh] [ebp-178h]
  int v121; // [esp+F8h] [ebp-15Ch] BYREF
  int v122; // [esp+FCh] [ebp-158h]
  _DWORD v123[79]; // [esp+118h] [ebp-13Ch] BYREF

  result = *this;
  if ( !*this )
    goto LABEL_267;
  v100 = 0;
  v99 = 0;
  this[261] = 0;
  v103 = 0;
  this[322] = 0;
  this[324] = 0;
  this[325] = 0;
  this[314] = 0;
  this[316] = 0;
  this[317] = 0;
  this[318] = 0;
  this[320] = 0;
  this[321] = 0;
  for ( i = 0; i < 3; ++i )
  {
    if ( i )
    {
      if ( i == 1 )
      {
        v101 = 0;
      }
      else if ( i == 2 )
      {
        v101 = 1;
      }
      else if ( v101 < 0 )
      {
        continue;
      }
    }
    else
    {
      v101 = 2;
    }
    v3 = (_DWORD *)*this;
    if ( *(_DWORD *)(44 * (v101 + 158) + *this) == 2 )
    {
      v4 = (int *)v3[11 * v101 + 1746];
      if ( v4 )
      {
        if ( (v3[1047] & 0x100) == 0 )
          goto LABEL_39;
        if ( v4 == &dword_761C78 )
        {
          v94 = 0;
          v91 = 1;
          goto LABEL_38;
        }
        if ( v4 == &dword_7645A8 )
        {
          v94 = 0;
        }
        else
        {
          if ( v4 == &dword_761BD0 )
          {
            v94 = 4;
            v91 = 1;
            goto LABEL_38;
          }
          if ( v4 == &dword_761C58 )
          {
            v94 = 4;
          }
          else
          {
            if ( v4 == &dword_764CF8 )
            {
              v94 = 8;
              v91 = 1;
              goto LABEL_38;
            }
            if ( v4 == &dword_761BB0 )
            {
              v94 = 8;
            }
            else
            {
              if ( v4 == &dword_764714 )
              {
                v94 = 12;
                v91 = 1;
                goto LABEL_38;
              }
              if ( v4 == &dword_764B10 )
              {
                v94 = 12;
              }
              else
              {
                if ( v4 == &dword_7645D0 )
                {
                  v94 = 16;
                  v91 = 1;
                  goto LABEL_38;
                }
                if ( v4 == &dword_764AE0 )
                {
                  v94 = 16;
                }
                else
                {
                  if ( v4 == &dword_764810 )
                  {
                    v94 = 20;
                    v91 = 1;
                    goto LABEL_38;
                  }
                  if ( v4 != &dword_7645E0 )
                    goto LABEL_39;
                  v94 = 20;
                }
              }
            }
          }
        }
        v91 = -1;
LABEL_38:
        v5 = v3 + 868;
        if ( v3 != (_DWORD *)-3472 )
        {
LABEL_66:
          v6 = v5[32];
          if ( v6 )
          {
            if ( !i )
              v103 = v5;
            memset(v123, 0, sizeof(v123));
            v123[0] = 316;
            if ( (*(int (__stdcall **)(int, _DWORD *, int, int))(*(_DWORD *)v6 + 56))(v6, v123, v94, 1) >= 0
              && (v123[7] & 1) != 0 )
            {
              if ( i )
              {
                if ( i == 1 )
                {
                  this[324] = v94;
                  this[316] = (int)v5;
                  this[320] = v91;
                }
                else if ( i == 2 )
                {
                  this[325] = v94;
                  this[317] = (int)v5;
                  this[321] = v91;
                }
              }
              else
              {
                this[322] = v94;
                this[314] = (int)v5;
                this[318] = v91;
              }
            }
          }
          continue;
        }
LABEL_39:
        if ( (v3[1302] & 0x100) == 0 )
          continue;
        if ( v4 == &dword_761BA0 )
        {
          v94 = 0;
          v91 = 1;
          goto LABEL_65;
        }
        if ( v4 == &dword_764520 )
        {
          v94 = 0;
        }
        else
        {
          if ( v4 == &dword_764CB8 )
          {
            v94 = 4;
            v91 = 1;
            goto LABEL_65;
          }
          if ( v4 == &dword_761CF4 )
          {
            v94 = 4;
          }
          else
          {
            if ( v4 == &dword_764C58 )
            {
              v94 = 8;
              v91 = 1;
              goto LABEL_65;
            }
            if ( v4 == &dword_761C20 )
            {
              v94 = 8;
            }
            else
            {
              if ( v4 == &dword_761C30 )
              {
                v94 = 12;
                v91 = 1;
                goto LABEL_65;
              }
              if ( v4 == &dword_764758 )
              {
                v94 = 12;
              }
              else
              {
                if ( v4 == &dword_761B90 )
                {
                  v94 = 16;
                  v91 = 1;
                  goto LABEL_65;
                }
                if ( v4 == &dword_761C68 )
                {
                  v94 = 16;
                }
                else
                {
                  if ( v4 == &dword_764550 )
                  {
                    v94 = 20;
                    v91 = 1;
                    goto LABEL_65;
                  }
                  if ( v4 != &dword_761BC0 )
                    continue;
                  v94 = 20;
                }
              }
            }
          }
        }
        v91 = -1;
LABEL_65:
        v5 = v3 + 1123;
        if ( v3 == (_DWORD *)-4492 )
          continue;
        goto LABEL_66;
      }
    }
  }
  v7 = this[314];
  if ( v7 )
  {
    v8 = this[318];
    if ( v8 )
    {
      if ( !this[316] || dword_76AD94 )
      {
        this[324] = this[322];
        this[316] = v7;
        this[320] = v8;
        dword_76AD94 = 1;
        if ( dword_76AD9C <= 1 )
        {
          if ( dword_76ADA0 < 1 )
            dword_76AD94 = dword_76ADA0;
        }
        else
        {
          dword_76AD94 = dword_76AD9C;
        }
      }
      if ( !this[317] || dword_76ADB8 )
      {
        v9 = this[314];
        v10 = this[318];
        this[325] = this[322];
        this[317] = v9;
        this[321] = v10;
        dword_76ADB8 = 1;
        if ( dword_76ADC0 <= 1 )
        {
          if ( dword_76ADC4 < 1 )
            dword_76ADB8 = dword_76ADC4;
        }
        else
        {
          dword_76ADB8 = dword_76ADC0;
        }
      }
    }
  }
  if ( dword_76AD28 == 3 )
  {
    if ( v103 )
    {
      v11 = v103[32];
      if ( v11 )
      {
        memset(v123, 0, sizeof(v123));
        v123[0] = 316;
        if ( (*(int (__stdcall **)(int, _DWORD *, int, int))(*(_DWORD *)v11 + 56))(v11, v123, 4, 1) >= 0
          && (v123[7] & 1) != 0 )
        {
          v12 = v103;
          this[314] = (int)v103;
          this[322] = 4;
          this[318] = 1;
          this[316] = (int)v12;
          this[324] = 4;
          this[320] = 1;
          this[317] = (int)v12;
          this[325] = 4;
          this[321] = 1;
          if ( (*(int (__stdcall **)(int, _DWORD *, _DWORD, int))(*(_DWORD *)v12[32] + 56))(v12[32], v123, 0, 1) >= 0
            && (v123[7] & 1) != 0 )
          {
            if ( !dword_76AD94 )
              this[324] = 0;
            if ( !dword_76ADB8 )
              this[325] = 0;
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(*this + 3600) )
  {
    v13 = &dword_764530;
    v14 = this + 328;
    do
    {
      *v13 = 0;
      *v14 = 0;
      ++v13;
      ++v14;
    }
    while ( (int)v13 < (int)&dword_764550 );
    dword_764BDC = 0;
    v15 = *this;
    this[326] = 0;
    if ( (*(int (__stdcall **)(_DWORD, int (__stdcall *)(int, int), _DWORD, int))(**(_DWORD **)(v15 + 3600) + 16))(
           *(_DWORD *)(v15 + 3600),
           sub_451210,
           0,
           3) >= 0 )
    {
      this[326] = dword_764BDC;
      v16 = &dword_764530;
      v17 = this + 328;
      do
        *v17++ = *v16++;
      while ( (int)v16 < (int)&dword_764550 );
    }
  }
  if ( *(_DWORD *)(*this + 4620) )
  {
    dword_764BDC = 0;
    this[327] = 0;
    v18 = &dword_764530;
    v19 = this + 336;
    do
    {
      *v18 = 0;
      *v19 = 0;
      ++v18;
      ++v19;
    }
    while ( (int)v18 < (int)&dword_764550 );
    if ( (*(int (__stdcall **)(_DWORD, int (__stdcall *)(int, int), _DWORD, int))(**(_DWORD **)(*this + 4620) + 16))(
           *(_DWORD *)(*this + 4620),
           sub_451210,
           0,
           3) >= 0 )
    {
      this[327] = dword_764BDC;
      v20 = &dword_764530;
      v21 = this + 336;
      do
        *v21++ = *v20++;
      while ( (int)v20 < (int)&dword_764550 );
    }
  }
  v22 = 0;
  for ( i = 0; ; v22 = i )
  {
    v118 = v22 + 1;
    v23 = (char *)&this[26 * v22];
    v24 = &this[26 * v22 + 26];
    v23[4] = 0;
    *((_DWORD *)v23 + 25) = 0;
    *v24 = 0;
    v103 = v24;
    if ( dword_76AD4C && flt_76AD70 != 0.0 )
    {
      switch ( i )
      {
        case 0:
          if ( flt_76AE90 != 0.0 && flt_76AEB4 != 0.0 )
          {
            v25 = this[314];
            if ( v25 )
            {
              if ( this[318] && dword_76AD4C >= 1 )
              {
                *v24 = v25;
                this[263] = 0;
                this[264] = 0;
                this[265] = 0;
                this[266] = 0;
                *((_DWORD *)v23 + 4) = -1;
                *((_DWORD *)v23 + 7) = -1;
                *((_DWORD *)v23 + 2) = 56;
                *((_DWORD *)v23 + 3) = 18;
                *((_DWORD *)v23 + 5) = 0;
                *((_DWORD *)v23 + 6) = 10000;
                *((_DWORD *)v23 + 8) = 0;
                *((_DWORD *)v23 + 9) = 1;
                *((_DWORD *)v23 + 10) = this + 322;
                *((_DWORD *)v23 + 11) = this + 318;
                *((_DWORD *)v23 + 12) = 0;
                *((_DWORD *)v23 + 13) = 16;
                *((_DWORD *)v23 + 14) = this + 263;
                *((_DWORD *)v23 + 15) = 0;
                switch ( dword_76AE48 )
                {
                  case 0:
                    goto LABEL_207;
                  case 1:
                    goto LABEL_237;
                  case 2:
                    goto LABEL_238;
                  case 3:
                    goto LABEL_239;
                  case 4:
                    goto LABEL_240;
                  default:
                    goto LABEL_241;
                }
              }
            }
          }
          goto LABEL_242;
        case 1:
          if ( flt_76AF44 == 0.0 )
            goto LABEL_242;
          if ( flt_76AF68 == 0.0 )
            goto LABEL_242;
          v26 = this[314];
          if ( !v26 || !this[318] || dword_76AD4C < 2 )
            goto LABEL_242;
          *v24 = v26;
          this[268] = (__int64)(flt_76AF44 * 10000.0);
          this[270] = (__int64)(flt_76AF68 * 10000.0);
          this[269] = (__int64)(flt_76AF44 * 10000.0);
          this[271] = (__int64)(flt_76AF68 * 10000.0);
          this[267] = 0;
          this[272] = 0;
          *((_DWORD *)v23 + 4) = -1;
          *((_DWORD *)v23 + 7) = -1;
          *((_DWORD *)v23 + 10) = this + 322;
          *((_DWORD *)v23 + 2) = 56;
          *((_DWORD *)v23 + 3) = 18;
          *((_DWORD *)v23 + 5) = 0;
          *((_DWORD *)v23 + 6) = 10000;
          *((_DWORD *)v23 + 8) = 0;
          *((_DWORD *)v23 + 9) = 1;
          *((_DWORD *)v23 + 11) = this + 318;
          *((_DWORD *)v23 + 12) = 0;
          *((_DWORD *)v23 + 13) = 24;
          *((_DWORD *)v23 + 14) = this + 267;
          *((_DWORD *)v23 + 15) = 0;
          v95 = 324279338;
          v96 = 298880563;
          v97 = -1610559334;
          v98 = 896442569;
          goto LABEL_243;
        case 2:
          if ( flt_76AF8C == 0.0 )
            goto LABEL_242;
          if ( flt_76AFB0 == 0.0 )
            goto LABEL_242;
          v27 = this[314];
          if ( !v27 || !this[318] || dword_76AD4C < 2 )
            goto LABEL_242;
          *v24 = v27;
          this[274] = (__int64)(flt_76AF8C * 10000.0);
          this[276] = (__int64)(flt_76AFB0 * 10000.0);
          this[275] = (__int64)(flt_76AF8C * 10000.0);
          this[277] = (__int64)(flt_76AFB0 * 10000.0);
          this[273] = 0;
          this[278] = 0;
          *((_DWORD *)v23 + 4) = -1;
          *((_DWORD *)v23 + 7) = -1;
          *((_DWORD *)v23 + 10) = this + 322;
          *((_DWORD *)v23 + 2) = 56;
          *((_DWORD *)v23 + 3) = 18;
          *((_DWORD *)v23 + 5) = 0;
          *((_DWORD *)v23 + 6) = 10000;
          *((_DWORD *)v23 + 8) = 0;
          *((_DWORD *)v23 + 9) = 1;
          *((_DWORD *)v23 + 11) = this + 318;
          *((_DWORD *)v23 + 12) = 0;
          *((_DWORD *)v23 + 13) = 24;
          *((_DWORD *)v23 + 14) = this + 273;
          *((_DWORD *)v23 + 15) = 0;
          v95 = 324279336;
          v96 = 298880563;
          v97 = -1610559334;
          v98 = 896442569;
          goto LABEL_243;
        case 3:
          if ( dword_76AD4C >= 3 && (*(_DWORD *)(*this + 4188) & 0x100) != 0 && this[326] )
          {
            v28 = v123;
            v101 = 0;
            v92 = v123;
            v29 = (float *)&unk_76B238;
            v104 = 8;
            do
            {
              v30 = v101 < (unsigned int)this[326];
              v28[5] = 0;
              *v28 = 0;
              if ( v30 )
              {
                v31 = v29[144] * 10000.0;
                v92[3] = (__int64)(*v29 * 10000.0);
                v32 = (__int64)v31;
                v33 = v29[288] * 10000.0;
                v92[1] = v32;
                v34 = (__int64)v33;
                v35 = v29[432] * 10000.0;
                v92[4] = v34;
                v92[2] = (__int64)v35;
                v28 = v92;
              }
              else
              {
                v36 = v29[2];
                v37 = v29[3];
                *v29 = 0.0;
                v38 = v36 < *v29;
                v39 = v36 == *v29;
                v28[2] = 0;
                v28[1] = 0;
                if ( v38 || v39 )
                {
                  if ( *v29 > (double)v37 )
                    *v29 = v37;
                }
                else
                {
                  *v29 = v36;
                }
                v40 = v29[146];
                v41 = v29[147];
                v29[144] = 0.0;
                v42 = v40 < v29[144];
                v43 = v40 == v29[144];
                v107 = v41;
                if ( v42 || v43 )
                {
                  if ( v29[144] > (double)v107 )
                    v29[144] = v107;
                }
                else
                {
                  v29[144] = v40;
                }
                v44 = v29[290];
                v45 = v29[291];
                v29[288] = 0.0;
                v46 = v44 < v29[288];
                v47 = v44 == v29[288];
                v110 = v45;
                if ( v46 || v47 )
                {
                  if ( v29[288] > (double)v110 )
                    v29[288] = v110;
                }
                else
                {
                  v29[288] = v44;
                }
                v48 = v29[434];
                v49 = v29[435];
                v29[432] = 0.0;
                v50 = v48 < v29[432];
                v51 = v48 == v29[432];
                v111 = v49;
                if ( v50 || v51 )
                {
                  if ( v29[432] > (double)v111 )
                    v29[432] = v111;
                }
                else
                {
                  v29[432] = v48;
                }
              }
              v28 += 6;
              v29 += 9;
              v52 = v104 == 1;
              ++v101;
              v92 = v28;
              --v104;
            }
            while ( !v52 );
            for ( j = 0; j < 8; ++j )
            {
              if ( j )
                *(&v119 + j) = 0;
              else
                v119 = 1;
            }
            v24 = v103;
            *v103 = *this + 3472;
            *((_DWORD *)v23 + 4) = -1;
            *((_DWORD *)v23 + 7) = -1;
            *((_DWORD *)v23 + 2) = 56;
            *((_DWORD *)v23 + 3) = 17;
            *((_DWORD *)v23 + 5) = 0;
            *((_DWORD *)v23 + 6) = 10000;
            *((_DWORD *)v23 + 8) = 0;
            *((_DWORD *)v23 + 9) = this[326];
            *((_DWORD *)v23 + 12) = 0;
            *((_DWORD *)v23 + 10) = this + 328;
            *((_DWORD *)v23 + 11) = &v119;
            *((_DWORD *)v23 + 13) = 24 * this[326];
            *((_DWORD *)v23 + 14) = v123;
            *((_DWORD *)v23 + 15) = 0;
            v95 = 324279335;
            v96 = 298880563;
            v97 = -1610559334;
            v98 = 896442569;
          }
          goto LABEL_243;
        case 4:
          if ( dword_76AD4C >= 3 && (*(_DWORD *)(*this + 5208) & 0x100) != 0 && this[327] )
          {
            v54 = &v123[3];
            v93 = 0;
            v101 = (int)&v123[3];
            v55 = (float *)&unk_76B358;
            v104 = 8;
            do
            {
              if ( v93 >= this[327] )
              {
                v59 = v55[2];
                v60 = v55[3];
                *v55 = 0.0;
                v61 = v59 < *v55;
                v62 = v59 == *v55;
                v54[1] = 0;
                *v54 = 0;
                v54[2] = 0;
                *(v54 - 1) = 0;
                *(v54 - 3) = 0;
                *(v54 - 2) = 0;
                v109 = v60;
                if ( v61 || v62 )
                {
                  if ( *v55 > (double)v109 )
                    *v55 = v109;
                }
                else
                {
                  *v55 = v59;
                }
                v63 = v55[146];
                v64 = v55[147];
                v55[144] = 0.0;
                v65 = v63 < v55[144];
                v66 = v63 == v55[144];
                v105 = v64;
                if ( v65 || v66 )
                {
                  if ( v55[144] > (double)v105 )
                    v55[144] = v105;
                }
                else
                {
                  v55[144] = v63;
                }
                v67 = v55[290];
                v68 = v55[291];
                v55[288] = 0.0;
                v69 = v67 < v55[288];
                v70 = v67 == v55[288];
                v106 = v68;
                if ( v69 || v70 )
                {
                  if ( v55[288] > (double)v106 )
                    v55[288] = v106;
                }
                else
                {
                  v55[288] = v67;
                }
                v71 = v55[434];
                v72 = v55[435];
                v55[432] = 0.0;
                v73 = v71 < v55[432];
                v74 = v71 == v55[432];
                v108 = v72;
                if ( v73 || v74 )
                {
                  if ( v55[432] > (double)v108 )
                    v55[432] = v108;
                }
                else
                {
                  v55[432] = v71;
                }
              }
              else
              {
                v56 = v55[432] * 10000.0;
                *(_DWORD *)v101 = (__int64)(*v55 * 10000.0);
                v57 = (__int64)v56;
                v58 = v55[288] * 10000.0;
                v117 = v57;
                *(_DWORD *)(v101 - 8) = v57;
                v54 = (_DWORD *)v101;
                *(_DWORD *)(v101 + 4) = (__int64)v58;
                *(v54 - 1) = v117;
                v54[2] = 0;
                *(v54 - 3) = 0;
              }
              v54 += 6;
              v55 += 9;
              v52 = v104 == 1;
              ++v93;
              v101 = (int)v54;
              --v104;
            }
            while ( !v52 );
            for ( k = 0; k < 8; ++k )
            {
              if ( k )
                *(&v119 + k) = 0;
              else
                v119 = 1;
            }
            v76 = *this;
            v77 = v103;
            v24 = v103;
            *((_DWORD *)v23 + 4) = -1;
            *((_DWORD *)v23 + 7) = -1;
            *v77 = v76 + 4492;
            *((_DWORD *)v23 + 2) = 56;
            *((_DWORD *)v23 + 3) = 17;
            *((_DWORD *)v23 + 5) = 0;
            *((_DWORD *)v23 + 6) = 10000;
            *((_DWORD *)v23 + 8) = 0;
            *((_DWORD *)v23 + 9) = this[326];
            *((_DWORD *)v23 + 12) = 0;
            *((_DWORD *)v23 + 10) = this + 328;
            *((_DWORD *)v23 + 11) = &v119;
            *((_DWORD *)v23 + 13) = 24 * this[327];
            *((_DWORD *)v23 + 14) = v123;
            *((_DWORD *)v23 + 15) = 0;
            v95 = 324279335;
            v96 = 298880563;
            v97 = -1610559334;
            v98 = 896442569;
          }
          goto LABEL_243;
        case 5:
          if ( flt_76AFF8 != 0.0 && (flt_76B01C != 0.0 || flt_76B040 != 0.0) )
          {
            v78 = this[316];
            if ( v78 )
            {
              if ( dword_76AD4C >= 4 )
              {
                *v24 = v78;
                this[291] = 0;
                this[292] = 0;
                this[293] = 0;
                this[294] = 0;
                *((_DWORD *)v23 + 4) = -1;
                *((_DWORD *)v23 + 7) = -1;
                *((_DWORD *)v23 + 10) = this + 324;
                *((_DWORD *)v23 + 2) = 56;
                *((_DWORD *)v23 + 3) = 18;
                *((_DWORD *)v23 + 5) = 0;
                *((_DWORD *)v23 + 6) = 10000;
                *((_DWORD *)v23 + 8) = 0;
                *((_DWORD *)v23 + 9) = 1;
                *((_DWORD *)v23 + 11) = this + 320;
                *((_DWORD *)v23 + 12) = 0;
                *((_DWORD *)v23 + 13) = 16;
                *((_DWORD *)v23 + 14) = this + 291;
                *((_DWORD *)v23 + 15) = 0;
                switch ( dword_76B064 )
                {
                  case 0:
                    goto LABEL_202;
                  case 1:
                    goto LABEL_203;
                  case 2:
                    goto LABEL_204;
                  case 3:
                    goto LABEL_205;
                  case 4:
                    goto LABEL_206;
                  default:
                    goto LABEL_207;
                }
              }
            }
          }
          goto LABEL_242;
        case 6:
          if ( flt_76B0AC == 0.0 || flt_76B0D0 == 0.0 && flt_76B0F4 == 0.0 )
            goto LABEL_242;
          v79 = this[317];
          if ( !v79 || dword_76AD4C < 3 )
            goto LABEL_242;
          *v24 = v79;
          this[295] = 0;
          this[296] = 0;
          this[297] = 0;
          this[298] = 0;
          *((_DWORD *)v23 + 4) = -1;
          *((_DWORD *)v23 + 7) = -1;
          *((_DWORD *)v23 + 10) = this + 325;
          *((_DWORD *)v23 + 2) = 56;
          *((_DWORD *)v23 + 3) = 18;
          *((_DWORD *)v23 + 5) = 0;
          *((_DWORD *)v23 + 6) = 10000;
          *((_DWORD *)v23 + 8) = 0;
          *((_DWORD *)v23 + 9) = 1;
          *((_DWORD *)v23 + 11) = this + 321;
          *((_DWORD *)v23 + 12) = 0;
          *((_DWORD *)v23 + 13) = 16;
          *((_DWORD *)v23 + 14) = this + 295;
          *((_DWORD *)v23 + 15) = 0;
          switch ( dword_76B118 )
          {
            case 0:
LABEL_202:
              v95 = 324279331;
              v96 = 298880563;
              v97 = -1610559334;
              v98 = 896442569;
              break;
            case 1:
LABEL_203:
              v95 = 324279330;
              v96 = 298880563;
              v97 = -1610559334;
              v98 = 896442569;
              break;
            case 2:
LABEL_204:
              v95 = 324279332;
              v96 = 298880563;
              v97 = -1610559334;
              v98 = 896442569;
              break;
            case 3:
LABEL_205:
              v95 = 324279333;
              v96 = 298880563;
              v97 = -1610559334;
              v98 = 896442569;
              break;
            case 4:
LABEL_206:
              v95 = 324279334;
              v96 = 298880563;
              v97 = -1610559334;
              v98 = 896442569;
              break;
            default:
              goto LABEL_207;
          }
          goto LABEL_243;
        case 7:
          if ( flt_76B214 == 0.0 )
            goto LABEL_242;
          v80 = this[314];
          if ( !v80 && !this[317] )
            goto LABEL_242;
          if ( dword_76AD4C < 2 )
            goto LABEL_242;
          if ( dword_76AD28 == 3 )
          {
            if ( !v80 )
              goto LABEL_222;
            v81 = 2;
            v121 = 0;
            v119 = 1;
            v122 = 4;
            v120 = 1;
          }
          else
          {
            if ( !v80 )
            {
LABEL_222:
              v82 = this[317];
              v81 = 1;
              v121 = this[325];
              v119 = 1;
              *v24 = v82;
              goto LABEL_230;
            }
            v83 = this[317];
            if ( v83 && !dword_76ADB8 && v83 == v80 )
            {
              v121 = this[322];
              v81 = 2;
              v122 = this[325];
              v120 = 1;
            }
            else
            {
              v81 = 1;
              v121 = this[322];
            }
            v119 = 1;
          }
          *v24 = v80;
LABEL_230:
          v52 = dword_76AD28 == 3;
          *((_DWORD *)v23 + 23) = 100000;
          *((_DWORD *)v23 + 22) = 0;
          *((_DWORD *)v23 + 21) = 0;
          *((_DWORD *)v23 + 20) = 10000;
          *((_DWORD *)v23 + 19) = 20;
          if ( v52 )
            *((_DWORD *)v23 + 4) = 300000;
          else
            *((_DWORD *)v23 + 4) = 150000;
          this[299] = 0;
          *((_DWORD *)v23 + 9) = v81;
          *((_DWORD *)v23 + 10) = &v121;
          *((_DWORD *)v23 + 2) = 56;
          *((_DWORD *)v23 + 3) = 18;
          *((_DWORD *)v23 + 5) = 0;
          *((_DWORD *)v23 + 6) = 10000;
          *((_DWORD *)v23 + 7) = -1;
          *((_DWORD *)v23 + 8) = 0;
          *((_DWORD *)v23 + 11) = &v119;
          *((_DWORD *)v23 + 12) = v23 + 76;
          *((_DWORD *)v23 + 13) = 4;
          *((_DWORD *)v23 + 14) = this + 299;
          *((_DWORD *)v23 + 15) = 0;
          v95 = 324279328;
          v96 = 298880563;
          v97 = -1610559334;
          v98 = 896442569;
LABEL_243:
          if ( !*v24 )
            break;
          v84 = *(_DWORD *)(*v24 + 128);
          if ( !v84
            || (*(int (__stdcall **)(int, int *, char *, char *, _DWORD))(*(_DWORD *)v84 + 72))(
                 v84,
                 &v95,
                 v23 + 8,
                 v23 + 100,
                 0) < 0
            || !*((_DWORD *)v23 + 25) )
          {
            break;
          }
          v85 = *v24;
          if ( *v24 == *this + 3472 && !v100 || v85 == *this + 4492 && !v99 )
          {
            (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v85 + 128) + 32))(*(_DWORD *)(v85 + 128));
            v112 = 20;
            v113 = 16;
            v114 = 0;
            v115 = 0;
            v86 = *v24;
            v116 = (__int64)(flt_76AD70 * 10000.0);
            (*(void (__stdcall **)(_DWORD, int, int *))(**(_DWORD **)(v86 + 128) + 24))(
              *(_DWORD *)(v86 + 128),
              7,
              &v112);
            v87 = *v24;
            v112 = 20;
            v113 = 16;
            v114 = 0;
            v115 = 0;
            v116 = 0;
            if ( (*(int (__stdcall **)(_DWORD, int, int *))(**(_DWORD **)(v87 + 128) + 24))(
                   *(_DWORD *)(v87 + 128),
                   9,
                   &v112) >= 0 )
            {
              v88 = *v24;
              if ( *v24 == *this + 3472 )
              {
                v100 = 1;
              }
              else if ( v88 == *this + 4492 )
              {
                v99 = 1;
              }
              (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v88 + 128) + 28))(*(_DWORD *)(v88 + 128));
            }
          }
          v89 = *v24;
          if ( (v89 != *this + 3472 || !v100) && (v89 != *this + 4492 || !v99) )
            break;
          (*(void (__stdcall **)(_DWORD))(**((_DWORD **)v23 + 25) + 40))(*((_DWORD *)v23 + 25));
          if ( i == 7 )
          {
            *((_BYTE *)this + 732) = 1;
          }
          else
          {
            if ( (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)v23 + 25) + 28))(
                   *((_DWORD *)v23 + 25),
                   -1,
                   0) < 0 )
              break;
            v23[4] = 1;
          }
          this[261] = 1;
          break;
        case 8:
          if ( flt_76B160 == 0.0 || dword_76AD4C < 2 )
          {
LABEL_242:
            *v24 = 0;
          }
          else
          {
            *v24 = this[314];
            this[300] = 0;
            this[301] = 0;
            this[302] = 0;
            this[303] = 0;
            *((_DWORD *)v23 + 4) = -1;
            *((_DWORD *)v23 + 7) = -1;
            *((_DWORD *)v23 + 10) = this + 322;
            *((_DWORD *)v23 + 2) = 56;
            *((_DWORD *)v23 + 3) = 18;
            *((_DWORD *)v23 + 5) = 0;
            *((_DWORD *)v23 + 6) = 10000;
            *((_DWORD *)v23 + 8) = 0;
            *((_DWORD *)v23 + 9) = 1;
            *((_DWORD *)v23 + 11) = this + 318;
            *((_DWORD *)v23 + 12) = 0;
            *((_DWORD *)v23 + 13) = 16;
            *((_DWORD *)v23 + 14) = this + 300;
            *((_DWORD *)v23 + 15) = 0;
            switch ( dword_76B1A8 )
            {
              case 0:
LABEL_207:
                v95 = 324279331;
                v96 = 298880563;
                v97 = -1610559334;
                v98 = 896442569;
                break;
              case 1:
LABEL_237:
                v95 = 324279330;
                v96 = 298880563;
                v97 = -1610559334;
                v98 = 896442569;
                break;
              case 2:
LABEL_238:
                v95 = 324279332;
                v96 = 298880563;
                v97 = -1610559334;
                v98 = 896442569;
                break;
              case 3:
LABEL_239:
                v95 = 324279333;
                v96 = 298880563;
                v97 = -1610559334;
                v98 = 896442569;
                break;
              case 4:
LABEL_240:
                v95 = 324279334;
                v96 = 298880563;
                v97 = -1610559334;
                v98 = 896442569;
                break;
              default:
LABEL_241:
                v95 = 324279331;
                v96 = 298880563;
                v97 = -1610559334;
                v98 = 896442569;
                break;
            }
          }
          goto LABEL_243;
        default:
          goto LABEL_243;
      }
    }
    result = v118;
    i = v118;
    if ( v118 >= 10 )
      break;
  }
LABEL_267:
  *((float *)this + 304) = 6283185.5 / flt_76ADDC;
  *((float *)this + 305) = 6283185.5 / flt_76AFF8;
  *((float *)this + 306) = 6283185.5 / flt_76B0AC;
  v90 = 6283185.5 / flt_76B184;
  this[308] = 0;
  this[309] = 0;
  *((_BYTE *)this + 1048) = 0;
  *((float *)this + 307) = v90;
  return result;
}
