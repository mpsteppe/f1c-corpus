int __thiscall sub_44FF50(int *this)
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
  int v31; // eax
  double v32; // st7
  int v33; // eax
  double v34; // st7
  int v35; // eax
  double v36; // st7
  double v37; // st7
  float v38; // eax
  bool v39; // c0
  bool v40; // c3
  double v41; // st7
  float v42; // eax
  bool v43; // c0
  bool v44; // c3
  double v45; // st7
  float v46; // eax
  bool v47; // c0
  bool v48; // c3
  double v49; // st7
  float v50; // eax
  bool v51; // c0
  bool v52; // c3
  bool v53; // zf
  unsigned int j; // eax
  int *v55; // ecx
  float *v56; // edi
  int v57; // eax
  double v58; // st7
  int v59; // eax
  double v60; // st7
  int v61; // eax
  double v62; // st7
  float v63; // edx
  bool v64; // c0
  bool v65; // c3
  double v66; // st7
  float v67; // edx
  bool v68; // c0
  bool v69; // c3
  double v70; // st7
  float v71; // edx
  bool v72; // c0
  bool v73; // c3
  double v74; // st7
  float v75; // edx
  bool v76; // c0
  bool v77; // c3
  unsigned int k; // eax
  int v79; // ecx
  int *v80; // edx
  int v81; // eax
  int v82; // eax
  int v83; // eax
  int v84; // edx
  int v85; // ecx
  int v86; // ecx
  int v87; // eax
  int v88; // eax
  int v89; // eax
  int v90; // edx
  int v91; // eax
  int v92; // ecx
  int v93; // edi
  double v94; // st7
  int v95; // [esp+74h] [ebp-1E0h]
  _DWORD *v96; // [esp+74h] [ebp-1E0h]
  int *v97; // [esp+74h] [ebp-1E0h]
  int v98; // [esp+78h] [ebp-1DCh]
  int v99; // [esp+7Ch] [ebp-1D8h] BYREF
  int v100; // [esp+80h] [ebp-1D4h]
  int v101; // [esp+84h] [ebp-1D0h]
  int v102; // [esp+88h] [ebp-1CCh]
  char v103; // [esp+8Eh] [ebp-1C6h]
  char v104; // [esp+8Fh] [ebp-1C5h]
  int v105; // [esp+90h] [ebp-1C4h]
  int i; // [esp+94h] [ebp-1C0h]
  int *v107; // [esp+98h] [ebp-1BCh]
  int v108; // [esp+9Ch] [ebp-1B8h]
  float v109; // [esp+A0h] [ebp-1B4h]
  float v110; // [esp+A4h] [ebp-1B0h]
  float v111; // [esp+A8h] [ebp-1ACh]
  float v112; // [esp+ACh] [ebp-1A8h]
  float v113; // [esp+B0h] [ebp-1A4h]
  float v114; // [esp+B4h] [ebp-1A0h]
  float v115; // [esp+B8h] [ebp-19Ch]
  int v116; // [esp+BCh] [ebp-198h] BYREF
  int v117; // [esp+C0h] [ebp-194h]
  int v118; // [esp+C4h] [ebp-190h]
  int v119; // [esp+C8h] [ebp-18Ch]
  int v120; // [esp+CCh] [ebp-188h]
  int v121; // [esp+D0h] [ebp-184h]
  int v122; // [esp+D4h] [ebp-180h]
  int v123; // [esp+D8h] [ebp-17Ch] BYREF
  int v124; // [esp+DCh] [ebp-178h]
  int v125; // [esp+F8h] [ebp-15Ch] BYREF
  int v126; // [esp+FCh] [ebp-158h]
  _DWORD v127[79]; // [esp+118h] [ebp-13Ch] BYREF

  result = *this;
  if ( !*this )
    goto LABEL_267;
  v104 = 0;
  v103 = 0;
  this[261] = 0;
  v107 = 0;
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
        v105 = 0;
      }
      else if ( i == 2 )
      {
        v105 = 1;
      }
      else if ( v105 < 0 )
      {
        continue;
      }
    }
    else
    {
      v105 = 2;
    }
    v3 = (_DWORD *)*this;
    if ( *(_DWORD *)(44 * v105 + *this + 6944) == 2 )
    {
      v4 = *(int **)(*this + 44 * v105 + 6976);
      if ( v4 )
      {
        if ( (v3[1045] & 0x100) == 0 )
          goto LABEL_39;
        if ( v4 == &dword_7CA490 )
        {
          v98 = 0;
          v95 = 1;
          goto LABEL_38;
        }
        if ( v4 == &dword_7CCA44 )
        {
          v98 = 0;
        }
        else
        {
          if ( v4 == &dword_7CA3E8 )
          {
            v98 = 4;
            v95 = 1;
            goto LABEL_38;
          }
          if ( v4 == &dword_7CA470 )
          {
            v98 = 4;
          }
          else
          {
            if ( v4 == &dword_7CD198 )
            {
              v98 = 8;
              v95 = 1;
              goto LABEL_38;
            }
            if ( v4 == &dword_7CA3C8 )
            {
              v98 = 8;
            }
            else
            {
              if ( v4 == &dword_7CCBB0 )
              {
                v98 = 12;
                v95 = 1;
                goto LABEL_38;
              }
              if ( v4 == &dword_7CCFB0 )
              {
                v98 = 12;
              }
              else
              {
                if ( v4 == &dword_7CCA6C )
                {
                  v98 = 16;
                  v95 = 1;
                  goto LABEL_38;
                }
                if ( v4 == &dword_7CCF80 )
                {
                  v98 = 16;
                }
                else
                {
                  if ( v4 == &dword_7CCCB0 )
                  {
                    v98 = 20;
                    v95 = 1;
                    goto LABEL_38;
                  }
                  if ( v4 != &dword_7CCA7C )
                    goto LABEL_39;
                  v98 = 20;
                }
              }
            }
          }
        }
        v95 = -1;
LABEL_38:
        v5 = v3 + 866;
        if ( v3 != (_DWORD *)-3464 )
        {
LABEL_66:
          v6 = v5[32];
          if ( v6 )
          {
            if ( !i )
              v107 = v5;
            memset(v127, 0, sizeof(v127));
            v127[0] = 316;
            if ( (*(int (__stdcall **)(int, _DWORD *, int, int))(*(_DWORD *)v6 + 56))(v6, v127, v98, 1) >= 0
              && (v127[7] & 1) != 0 )
            {
              if ( i )
              {
                if ( i == 1 )
                {
                  this[324] = v98;
                  this[316] = (int)v5;
                  this[320] = v95;
                }
                else if ( i == 2 )
                {
                  this[325] = v98;
                  this[317] = (int)v5;
                  this[321] = v95;
                }
              }
              else
              {
                this[322] = v98;
                this[314] = (int)v5;
                this[318] = v95;
              }
            }
          }
          continue;
        }
LABEL_39:
        if ( (v3[1300] & 0x100) == 0 )
          continue;
        if ( v4 == &dword_7CA3B8 )
        {
          v98 = 0;
          v95 = 1;
          goto LABEL_65;
        }
        if ( v4 == &dword_7CC9BC )
        {
          v98 = 0;
        }
        else
        {
          if ( v4 == &dword_7CD158 )
          {
            v98 = 4;
            v95 = 1;
            goto LABEL_65;
          }
          if ( v4 == &dword_7CA50C )
          {
            v98 = 4;
          }
          else
          {
            if ( v4 == &dword_7CD0F8 )
            {
              v98 = 8;
              v95 = 1;
              goto LABEL_65;
            }
            if ( v4 == &dword_7CA438 )
            {
              v98 = 8;
            }
            else
            {
              if ( v4 == &dword_7CA448 )
              {
                v98 = 12;
                v95 = 1;
                goto LABEL_65;
              }
              if ( v4 == &dword_7CCBF4 )
              {
                v98 = 12;
              }
              else
              {
                if ( v4 == &dword_7CA3A8 )
                {
                  v98 = 16;
                  v95 = 1;
                  goto LABEL_65;
                }
                if ( v4 == &dword_7CA480 )
                {
                  v98 = 16;
                }
                else
                {
                  if ( v4 == &dword_7CC9EC )
                  {
                    v98 = 20;
                    v95 = 1;
                    goto LABEL_65;
                  }
                  if ( v4 != &dword_7CA3D8 )
                    continue;
                  v98 = 20;
                }
              }
            }
          }
        }
        v95 = -1;
LABEL_65:
        v5 = v3 + 1121;
        if ( v3 == (_DWORD *)-4484 )
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
      if ( !this[316] || dword_7D2044 )
      {
        this[324] = this[322];
        this[316] = v7;
        this[320] = v8;
        dword_7D2044 = 1;
        if ( dword_7D204C <= 1 )
        {
          if ( dword_7D2050 < 1 )
            dword_7D2044 = dword_7D2050;
        }
        else
        {
          dword_7D2044 = dword_7D204C;
        }
      }
      if ( !this[317] || dword_7D2068 )
      {
        v9 = this[314];
        v10 = this[318];
        this[325] = this[322];
        this[317] = v9;
        this[321] = v10;
        dword_7D2068 = 1;
        if ( dword_7D2070 <= 1 )
        {
          if ( dword_7D2074 < 1 )
            dword_7D2068 = dword_7D2074;
        }
        else
        {
          dword_7D2068 = dword_7D2070;
        }
      }
    }
  }
  if ( dword_7D1FD8 == 3 )
  {
    if ( v107 )
    {
      v11 = v107[32];
      if ( v11 )
      {
        memset(v127, 0, sizeof(v127));
        v127[0] = 316;
        if ( (*(int (__stdcall **)(int, _DWORD *, int, int))(*(_DWORD *)v11 + 56))(v11, v127, 4, 1) >= 0
          && (v127[7] & 1) != 0 )
        {
          v12 = v107;
          this[314] = (int)v107;
          this[322] = 4;
          this[318] = 1;
          this[316] = (int)v12;
          this[324] = 4;
          this[320] = 1;
          this[317] = (int)v12;
          this[325] = 4;
          this[321] = 1;
          if ( (*(int (__stdcall **)(int, _DWORD *, _DWORD, int))(*(_DWORD *)v12[32] + 56))(v12[32], v127, 0, 1) >= 0
            && (v127[7] & 1) != 0 )
          {
            if ( !dword_7D2044 )
              this[324] = 0;
            if ( !dword_7D2068 )
              this[325] = 0;
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(*this + 3592) )
  {
    v13 = &dword_7CC9CC;
    v14 = this + 328;
    do
    {
      *v13 = 0;
      *v14 = 0;
      ++v13;
      ++v14;
    }
    while ( (int)v13 < (int)&dword_7CC9EC );
    dword_7CD07C = 0;
    v15 = *this;
    this[326] = 0;
    if ( (*(int (__stdcall **)(_DWORD, int (__stdcall *)(int, int), _DWORD, int))(**(_DWORD **)(v15 + 3592) + 16))(
           *(_DWORD *)(v15 + 3592),
           sub_44EDD0,
           0,
           3) >= 0 )
    {
      this[326] = dword_7CD07C;
      v16 = &dword_7CC9CC;
      v17 = this + 328;
      do
        *v17++ = *v16++;
      while ( (int)v16 < (int)&dword_7CC9EC );
    }
  }
  if ( *(_DWORD *)(*this + 4612) )
  {
    dword_7CD07C = 0;
    this[327] = 0;
    v18 = &dword_7CC9CC;
    v19 = this + 336;
    do
    {
      *v18 = 0;
      *v19 = 0;
      ++v18;
      ++v19;
    }
    while ( (int)v18 < (int)&dword_7CC9EC );
    if ( (*(int (__stdcall **)(_DWORD, int (__stdcall *)(int, int), _DWORD, int))(**(_DWORD **)(*this + 4612) + 16))(
           *(_DWORD *)(*this + 4612),
           sub_44EDD0,
           0,
           3) >= 0 )
    {
      this[327] = dword_7CD07C;
      v20 = &dword_7CC9CC;
      v21 = this + 336;
      do
        *v21++ = *v20++;
      while ( (int)v20 < (int)&dword_7CC9EC );
    }
  }
  v22 = 0;
  for ( i = 0; ; v22 = i )
  {
    v122 = v22 + 1;
    v23 = (char *)&this[26 * v22];
    v24 = &this[26 * v22 + 26];
    v23[4] = 0;
    *((_DWORD *)v23 + 25) = 0;
    *v24 = 0;
    v107 = v24;
    if ( dword_7D1FFC && flt_7D2020 != 0.0 )
    {
      switch ( i )
      {
        case 0:
          if ( flt_7D2140 != 0.0 && flt_7D2164 != 0.0 )
          {
            v25 = this[314];
            if ( v25 )
            {
              if ( this[318] && dword_7D1FFC >= 1 )
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
                switch ( dword_7D20F8 )
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
          if ( flt_7D21F4 == 0.0 )
            goto LABEL_242;
          if ( flt_7D2218 == 0.0 )
            goto LABEL_242;
          v26 = this[314];
          if ( !v26 || !this[318] || dword_7D1FFC < 2 )
            goto LABEL_242;
          *v24 = v26;
          this[268] = sub_587BDC(flt_7D21F4 * 10000.0);
          this[270] = sub_587BDC(flt_7D2218 * 10000.0);
          this[269] = sub_587BDC(flt_7D21F4 * 10000.0);
          this[271] = sub_587BDC(flt_7D2218 * 10000.0);
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
          v99 = 324279338;
          v100 = 298880563;
          v101 = -1610559334;
          v102 = 896442569;
          goto LABEL_243;
        case 2:
          if ( flt_7D223C == 0.0 )
            goto LABEL_242;
          if ( flt_7D2260 == 0.0 )
            goto LABEL_242;
          v27 = this[314];
          if ( !v27 || !this[318] || dword_7D1FFC < 2 )
            goto LABEL_242;
          *v24 = v27;
          this[274] = sub_587BDC(flt_7D223C * 10000.0);
          this[276] = sub_587BDC(flt_7D2260 * 10000.0);
          this[275] = sub_587BDC(flt_7D223C * 10000.0);
          this[277] = sub_587BDC(flt_7D2260 * 10000.0);
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
          v99 = 324279336;
          v100 = 298880563;
          v101 = -1610559334;
          v102 = 896442569;
          goto LABEL_243;
        case 3:
          if ( dword_7D1FFC >= 3 && (*(_DWORD *)(*this + 4180) & 0x100) != 0 && this[326] )
          {
            v28 = v127;
            v105 = 0;
            v96 = v127;
            v29 = (float *)&unk_7D24C4;
            v108 = 8;
            do
            {
              v30 = v105 < (unsigned int)this[326];
              v28[5] = 0;
              *v28 = 0;
              if ( v30 )
              {
                v31 = sub_587BDC(*v29 * 10000.0);
                v32 = v29[144] * 10000.0;
                v96[3] = v31;
                v33 = sub_587BDC(v32);
                v34 = v29[288] * 10000.0;
                v96[1] = v33;
                v35 = sub_587BDC(v34);
                v36 = v29[432] * 10000.0;
                v96[4] = v35;
                v96[2] = sub_587BDC(v36);
                v28 = v96;
              }
              else
              {
                v37 = v29[2];
                v38 = v29[3];
                *v29 = 0.0;
                v39 = v37 < *v29;
                v40 = v37 == *v29;
                v28[2] = 0;
                v28[1] = 0;
                if ( v39 || v40 )
                {
                  if ( *v29 > (double)v38 )
                    *v29 = v38;
                }
                else
                {
                  *v29 = v37;
                }
                v41 = v29[146];
                v42 = v29[147];
                v29[144] = 0.0;
                v43 = v41 < v29[144];
                v44 = v41 == v29[144];
                v111 = v42;
                if ( v43 || v44 )
                {
                  if ( v29[144] > (double)v111 )
                    v29[144] = v111;
                }
                else
                {
                  v29[144] = v41;
                }
                v45 = v29[290];
                v46 = v29[291];
                v29[288] = 0.0;
                v47 = v45 < v29[288];
                v48 = v45 == v29[288];
                v114 = v46;
                if ( v47 || v48 )
                {
                  if ( v29[288] > (double)v114 )
                    v29[288] = v114;
                }
                else
                {
                  v29[288] = v45;
                }
                v49 = v29[434];
                v50 = v29[435];
                v29[432] = 0.0;
                v51 = v49 < v29[432];
                v52 = v49 == v29[432];
                v115 = v50;
                if ( v51 || v52 )
                {
                  if ( v29[432] > (double)v115 )
                    v29[432] = v115;
                }
                else
                {
                  v29[432] = v49;
                }
              }
              v28 += 6;
              v29 += 9;
              v53 = v108 == 1;
              ++v105;
              v96 = v28;
              --v108;
            }
            while ( !v53 );
            for ( j = 0; j < 8; ++j )
            {
              if ( j )
                *(&v123 + j) = 0;
              else
                v123 = 1;
            }
            v24 = v107;
            *v107 = *this + 3464;
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
            *((_DWORD *)v23 + 11) = &v123;
            *((_DWORD *)v23 + 13) = 24 * this[326];
            *((_DWORD *)v23 + 14) = v127;
            *((_DWORD *)v23 + 15) = 0;
            v99 = 324279335;
            v100 = 298880563;
            v101 = -1610559334;
            v102 = 896442569;
          }
          goto LABEL_243;
        case 4:
          if ( dword_7D1FFC >= 3 && (*(_DWORD *)(*this + 5200) & 0x100) != 0 && this[327] )
          {
            v55 = &v127[3];
            v105 = 0;
            v97 = &v127[3];
            v56 = (float *)&unk_7D25E4;
            v108 = 8;
            do
            {
              if ( v105 >= (unsigned int)this[327] )
              {
                v62 = v56[2];
                v63 = v56[3];
                *v56 = 0.0;
                v64 = v62 < *v56;
                v65 = v62 == *v56;
                v55[1] = 0;
                *v55 = 0;
                v55[2] = 0;
                *(v55 - 1) = 0;
                *(v55 - 3) = 0;
                *(v55 - 2) = 0;
                v113 = v63;
                if ( v64 || v65 )
                {
                  if ( *v56 > (double)v113 )
                    *v56 = v113;
                }
                else
                {
                  *v56 = v62;
                }
                v66 = v56[146];
                v67 = v56[147];
                v56[144] = 0.0;
                v68 = v66 < v56[144];
                v69 = v66 == v56[144];
                v109 = v67;
                if ( v68 || v69 )
                {
                  if ( v56[144] > (double)v109 )
                    v56[144] = v109;
                }
                else
                {
                  v56[144] = v66;
                }
                v70 = v56[290];
                v71 = v56[291];
                v56[288] = 0.0;
                v72 = v70 < v56[288];
                v73 = v70 == v56[288];
                v110 = v71;
                if ( v72 || v73 )
                {
                  if ( v56[288] > (double)v110 )
                    v56[288] = v110;
                }
                else
                {
                  v56[288] = v70;
                }
                v74 = v56[434];
                v75 = v56[435];
                v56[432] = 0.0;
                v76 = v74 < v56[432];
                v77 = v74 == v56[432];
                v112 = v75;
                if ( v76 || v77 )
                {
                  if ( v56[432] > (double)v112 )
                    v56[432] = v112;
                }
                else
                {
                  v56[432] = v74;
                }
              }
              else
              {
                v57 = sub_587BDC(*v56 * 10000.0);
                v58 = v56[432] * 10000.0;
                *v97 = v57;
                v59 = sub_587BDC(v58);
                v60 = v56[288] * 10000.0;
                v121 = v59;
                *(v97 - 2) = v59;
                v61 = sub_587BDC(v60);
                v55 = v97;
                v97[1] = v61;
                *(v97 - 1) = v121;
                v97[2] = 0;
                *(v97 - 3) = 0;
              }
              v55 += 6;
              v56 += 9;
              v53 = v108 == 1;
              ++v105;
              v97 = v55;
              --v108;
            }
            while ( !v53 );
            for ( k = 0; k < 8; ++k )
            {
              if ( k )
                *(&v123 + k) = 0;
              else
                v123 = 1;
            }
            v79 = *this;
            v80 = v107;
            v24 = v107;
            *((_DWORD *)v23 + 4) = -1;
            *((_DWORD *)v23 + 7) = -1;
            *v80 = v79 + 4484;
            *((_DWORD *)v23 + 2) = 56;
            *((_DWORD *)v23 + 3) = 17;
            *((_DWORD *)v23 + 5) = 0;
            *((_DWORD *)v23 + 6) = 10000;
            *((_DWORD *)v23 + 8) = 0;
            *((_DWORD *)v23 + 9) = this[326];
            *((_DWORD *)v23 + 12) = 0;
            *((_DWORD *)v23 + 10) = this + 328;
            *((_DWORD *)v23 + 11) = &v123;
            *((_DWORD *)v23 + 13) = 24 * this[327];
            *((_DWORD *)v23 + 14) = v127;
            *((_DWORD *)v23 + 15) = 0;
            v99 = 324279335;
            v100 = 298880563;
            v101 = -1610559334;
            v102 = 896442569;
          }
          goto LABEL_243;
        case 5:
          if ( flt_7D2284 != 0.0 && (flt_7D22A8 != 0.0 || flt_7D22CC != 0.0) )
          {
            v81 = this[316];
            if ( v81 )
            {
              if ( dword_7D1FFC >= 4 )
              {
                *v24 = v81;
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
                switch ( dword_7D22F0 )
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
          if ( flt_7D2338 == 0.0 || flt_7D235C == 0.0 && flt_7D2380 == 0.0 )
            goto LABEL_242;
          v82 = this[317];
          if ( !v82 || dword_7D1FFC < 3 )
            goto LABEL_242;
          *v24 = v82;
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
          switch ( dword_7D23A4 )
          {
            case 0:
LABEL_202:
              v99 = 324279331;
              v100 = 298880563;
              v101 = -1610559334;
              v102 = 896442569;
              break;
            case 1:
LABEL_203:
              v99 = 324279330;
              v100 = 298880563;
              v101 = -1610559334;
              v102 = 896442569;
              break;
            case 2:
LABEL_204:
              v99 = 324279332;
              v100 = 298880563;
              v101 = -1610559334;
              v102 = 896442569;
              break;
            case 3:
LABEL_205:
              v99 = 324279333;
              v100 = 298880563;
              v101 = -1610559334;
              v102 = 896442569;
              break;
            case 4:
LABEL_206:
              v99 = 324279334;
              v100 = 298880563;
              v101 = -1610559334;
              v102 = 896442569;
              break;
            default:
              goto LABEL_207;
          }
          goto LABEL_243;
        case 7:
          if ( flt_7D24A0 == 0.0 )
            goto LABEL_242;
          v83 = this[314];
          if ( !v83 && !this[317] )
            goto LABEL_242;
          if ( dword_7D1FFC < 2 )
            goto LABEL_242;
          if ( dword_7D1FD8 == 3 )
          {
            if ( !v83 )
              goto LABEL_222;
            v84 = 2;
            v125 = 0;
            v123 = 1;
            v126 = 4;
            v124 = 1;
          }
          else
          {
            if ( !v83 )
            {
LABEL_222:
              v85 = this[317];
              v84 = 1;
              v125 = this[325];
              v123 = 1;
              *v24 = v85;
              goto LABEL_230;
            }
            v86 = this[317];
            if ( v86 && !dword_7D2068 && v86 == v83 )
            {
              v125 = this[322];
              v84 = 2;
              v126 = this[325];
              v124 = 1;
            }
            else
            {
              v84 = 1;
              v125 = this[322];
            }
            v123 = 1;
          }
          *v24 = v83;
LABEL_230:
          v53 = dword_7D1FD8 == 3;
          *((_DWORD *)v23 + 23) = 100000;
          *((_DWORD *)v23 + 22) = 0;
          *((_DWORD *)v23 + 21) = 0;
          *((_DWORD *)v23 + 20) = 10000;
          *((_DWORD *)v23 + 19) = 20;
          if ( v53 )
            *((_DWORD *)v23 + 4) = 300000;
          else
            *((_DWORD *)v23 + 4) = 150000;
          this[299] = 0;
          *((_DWORD *)v23 + 9) = v84;
          *((_DWORD *)v23 + 10) = &v125;
          *((_DWORD *)v23 + 2) = 56;
          *((_DWORD *)v23 + 3) = 18;
          *((_DWORD *)v23 + 5) = 0;
          *((_DWORD *)v23 + 6) = 10000;
          *((_DWORD *)v23 + 7) = -1;
          *((_DWORD *)v23 + 8) = 0;
          *((_DWORD *)v23 + 11) = &v123;
          *((_DWORD *)v23 + 12) = v23 + 76;
          *((_DWORD *)v23 + 13) = 4;
          *((_DWORD *)v23 + 14) = this + 299;
          *((_DWORD *)v23 + 15) = 0;
          v99 = 324279328;
          v100 = 298880563;
          v101 = -1610559334;
          v102 = 896442569;
LABEL_243:
          if ( !*v24 )
            break;
          v87 = *(_DWORD *)(*v24 + 128);
          if ( !v87
            || (*(int (__stdcall **)(int, int *, char *, char *, _DWORD))(*(_DWORD *)v87 + 72))(
                 v87,
                 &v99,
                 v23 + 8,
                 v23 + 100,
                 0) < 0
            || !*((_DWORD *)v23 + 25) )
          {
            break;
          }
          v88 = *v24;
          if ( *v24 == *this + 3464 && !v104 || v88 == *this + 4484 && !v103 )
          {
            (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v88 + 128) + 32))(*(_DWORD *)(v88 + 128));
            v116 = 20;
            v117 = 16;
            v118 = 0;
            v119 = 0;
            v89 = sub_587BDC(flt_7D2020 * 10000.0);
            v90 = *v24;
            v120 = v89;
            (*(void (__stdcall **)(_DWORD, int, int *))(**(_DWORD **)(v90 + 128) + 24))(
              *(_DWORD *)(v90 + 128),
              7,
              &v116);
            v91 = *v24;
            v116 = 20;
            v117 = 16;
            v118 = 0;
            v119 = 0;
            v120 = 0;
            if ( (*(int (__stdcall **)(_DWORD, int, int *))(**(_DWORD **)(v91 + 128) + 24))(
                   *(_DWORD *)(v91 + 128),
                   9,
                   &v116) >= 0 )
            {
              v92 = *v24;
              if ( *v24 == *this + 3464 )
              {
                v104 = 1;
              }
              else if ( v92 == *this + 4484 )
              {
                v103 = 1;
              }
              (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v92 + 128) + 28))(*(_DWORD *)(v92 + 128));
            }
          }
          v93 = *v24;
          if ( (v93 != *this + 3464 || !v104) && (v93 != *this + 4484 || !v103) )
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
          if ( flt_7D23EC == 0.0 || dword_7D1FFC < 2 )
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
            switch ( dword_7D2434 )
            {
              case 0:
LABEL_207:
                v99 = 324279331;
                v100 = 298880563;
                v101 = -1610559334;
                v102 = 896442569;
                break;
              case 1:
LABEL_237:
                v99 = 324279330;
                v100 = 298880563;
                v101 = -1610559334;
                v102 = 896442569;
                break;
              case 2:
LABEL_238:
                v99 = 324279332;
                v100 = 298880563;
                v101 = -1610559334;
                v102 = 896442569;
                break;
              case 3:
LABEL_239:
                v99 = 324279333;
                v100 = 298880563;
                v101 = -1610559334;
                v102 = 896442569;
                break;
              case 4:
LABEL_240:
                v99 = 324279334;
                v100 = 298880563;
                v101 = -1610559334;
                v102 = 896442569;
                break;
              default:
LABEL_241:
                v99 = 324279331;
                v100 = 298880563;
                v101 = -1610559334;
                v102 = 896442569;
                break;
            }
          }
          goto LABEL_243;
        default:
          goto LABEL_243;
      }
    }
    result = v122;
    i = v122;
    if ( v122 >= 10 )
      break;
  }
LABEL_267:
  *((float *)this + 304) = 6283185.5 / flt_7D208C;
  *((float *)this + 305) = 6283185.5 / flt_7D2284;
  *((float *)this + 306) = 6283185.5 / flt_7D2338;
  v94 = 6283185.5 / flt_7D2410;
  this[308] = 0;
  this[309] = 0;
  *((_BYTE *)this + 1048) = 0;
  *((float *)this + 307) = v94;
  return result;
}
