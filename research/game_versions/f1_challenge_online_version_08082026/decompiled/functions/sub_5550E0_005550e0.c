int __thiscall sub_5550E0(int *this, int a2, _DWORD *a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // edi
  int v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int *v13; // eax
  _DWORD *v14; // ebx
  int v15; // ebp
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  int v23; // eax
  int v24; // edx
  int v25; // ecx
  int v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ebx
  int v33; // edi
  int v34; // ebx
  _DWORD *v35; // ebx
  int v36; // ebp
  int v37; // edi
  int v38; // eax
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int v44; // edx
  bool v45; // cc
  _DWORD *v46; // ebp
  int v47; // ebx
  int v48; // edi
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // ebp
  int j; // edi
  int v54; // ebx
  int *v55; // ecx
  int v56; // eax
  int v57; // edi
  int v58; // edx
  int v59; // eax
  int v60; // eax
  bool v61; // zf
  _DWORD *v62; // ebp
  int k; // edi
  int v64; // eax
  int v65; // eax
  int v67; // [esp+80h] [ebp-A0h]
  int v68; // [esp+84h] [ebp-9Ch]
  int v69; // [esp+88h] [ebp-98h]
  int v70; // [esp+88h] [ebp-98h]
  int v71; // [esp+88h] [ebp-98h]
  int v72; // [esp+88h] [ebp-98h]
  int v73; // [esp+9Ch] [ebp-84h]
  int *v74; // [esp+9Ch] [ebp-84h]
  int *v75; // [esp+9Ch] [ebp-84h]
  int *v76; // [esp+A0h] [ebp-80h]
  _DWORD *v77; // [esp+A4h] [ebp-7Ch]
  int v78; // [esp+A4h] [ebp-7Ch]
  int v79; // [esp+A4h] [ebp-7Ch]
  _DWORD *v80; // [esp+A8h] [ebp-78h]
  int *v81; // [esp+ACh] [ebp-74h]
  int *v82; // [esp+B0h] [ebp-70h]
  int *v83; // [esp+B0h] [ebp-70h]
  int v84; // [esp+B4h] [ebp-6Ch] BYREF
  int v85; // [esp+B8h] [ebp-68h]
  int v86; // [esp+BCh] [ebp-64h] BYREF
  int i; // [esp+C0h] [ebp-60h]
  _DWORD *v88; // [esp+C4h] [ebp-5Ch]
  int v89; // [esp+C8h] [ebp-58h]
  int *v90; // [esp+CCh] [ebp-54h]
  int v91; // [esp+D0h] [ebp-50h]
  int v92[8]; // [esp+D4h] [ebp-4Ch] BYREF
  int v93; // [esp+F4h] [ebp-2Ch]
  int v94; // [esp+F8h] [ebp-28h]
  int v95; // [esp+FCh] [ebp-24h]
  int v96; // [esp+100h] [ebp-20h]
  int v97; // [esp+104h] [ebp-1Ch]
  int v98; // [esp+108h] [ebp-18h]
  int v99; // [esp+10Ch] [ebp-14h]
  int v100; // [esp+110h] [ebp-10h]
  int v101; // [esp+114h] [ebp-Ch]
  int v102; // [esp+118h] [ebp-8h] BYREF
  int v103; // [esp+11Ch] [ebp-4h] BYREF

  this[1267] = 0;
  sub_542520(a3, &v86, &v84);
  sub_5424C0(a3, &v102, &v103);
  if ( this[1265] != 1 )
  {
    v4 = this[1088];
    this[1265] = 1;
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v4 + 200))(v4, 136, 1);
  }
  if ( sub_55C9B0(this) )
  {
    if ( (BYTE1(*(_DWORD *)(a2 + 236)) & 0x80u) == 0 )
    {
      v5 = *(_DWORD *)(a2 + 348);
      if ( v5 )
      {
        if ( *(int *)(a2 + 316) > 0 )
        {
          do
          {
            if ( (*(_BYTE *)(v5 + 36) & 2) != 0 )
              sub_560FE0(0, 0);
            v5 = *(_DWORD *)(v5 + 52);
          }
          while ( v5 );
          sub_541B70((int)a3, 14);
        }
      }
    }
  }
  sub_554B20(this, (int)a3, 0);
  sub_554700(this, 0);
  v6 = *(_DWORD *)(a2 + 236);
  if ( (v6 & 0x10000) != 0 )
  {
    *(_DWORD *)(a2 + 236) = v6 & 0xFFFEFFFF;
    sub_556040(a2);
  }
  if ( this[1340] )
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 28, 1);
  v7 = -256 * sub_587BDC(*(float *)(a2 + 380) * -255.0);
  v8 = (sub_587BDC(*(float *)(a2 + 384) * 255.0) + v7) << 8;
  v9 = sub_587BDC(*(float *)(a2 + 388) * -255.0) - v8 + 0xFFFFFF;
  *(_DWORD *)(a2 + 340) = v9;
  if ( this[1266] != v9 )
  {
    v10 = this[1088];
    this[1266] = v9;
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v10 + 200))(v10, 60, v9);
  }
  for ( i = 0; i < 4; ++i )
  {
    switch ( i )
    {
      case 0:
        v11 = *(_DWORD *)(a2 + 436);
        v12 = *(int **)(a2 + 440);
        v69 = 1;
        goto LABEL_26;
      case 1:
        v11 = *(_DWORD *)(a2 + 452);
        v12 = *(int **)(a2 + 456);
        goto LABEL_25;
      case 2:
        if ( *(_DWORD *)(a2 + 436) + *(_DWORD *)(a2 + 452) > 0 )
          sub_554B20(this, (int)a3, 1);
        v13 = *(int **)(a2 + 448);
        v85 = *(_DWORD *)(a2 + 444);
        v76 = v13;
        sub_554BE0(this, 1);
        break;
      case 3:
        v11 = *(_DWORD *)(a2 + 460);
        v12 = *(int **)(a2 + 464);
LABEL_25:
        v69 = 0;
LABEL_26:
        v85 = v11;
        v76 = v12;
        sub_554BE0(this, v69);
        break;
      default:
        break;
    }
    if ( v85 > 0 )
    {
      v81 = v76 + 130;
      v91 = v85;
      do
      {
        if ( *v81 > 0 )
        {
          v14 = *(_DWORD **)(v81[1] + 12);
          v15 = 0;
          v80 = v14;
          if ( this[1270] )
          {
            v16 = v14[21];
            v17 = v14[23];
            v92[5] = v14[22];
            v92[0] = v14[17];
            v18 = v14[20];
            v92[4] = v16;
            v19 = v14[24];
            v92[6] = v17;
            v20 = v14[18];
            v92[3] = v18;
            v21 = v14[27];
            v92[7] = v19;
            v22 = v14[19];
            v92[1] = v20;
            v23 = v14[25];
            v95 = v21;
            v24 = v14[30];
            v92[2] = v22;
            v25 = v14[26];
            v93 = v23;
            v26 = v14[28];
            v98 = v24;
            v27 = v14[44];
            v94 = v25;
            v28 = v14[29];
            v96 = v26;
            v29 = v14[31];
            v101 = v27;
            v97 = v28;
            v30 = v14[32];
            v99 = v29;
            v31 = this[1088];
            v100 = v30;
            *this = (*(int (__stdcall **)(int, int *))(*(_DWORD *)v31 + 168))(v31, v92);
          }
          if ( (v14[39] & 0x400) != 0 )
          {
            v79 = 0;
            v83 = (int *)v81[1];
            if ( *v81 > 0 )
            {
              do
              {
                v46 = (_DWORD *)v83[1];
                v47 = v83[2];
                v48 = *v83;
                v49 = this[1268];
                v88 = v46;
                v89 = v47;
                if ( v49 )
                  *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 2);
                sub_554790(this, *v76, v80[43], *(_DWORD *)(v80[42] + 132));
                if ( v48 != this[1267] )
                {
                  this[1267] = v48;
                  sub_54B9E0((char *)v48);
                }
                v50 = *(_DWORD *)(v48 + 60);
                if ( this[1270] )
                {
                  if ( (v50 & 0x10) == 0x10 )
                  {
                    sub_541810(this, v46[67], v46[68]);
                    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 137, 1);
                    v51 = this[1088];
                    if ( (v46[5] & 0x400000) != 0 )
                      *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v51 + 200))(v51, 141, 1);
                    else
                      *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v51 + 200))(v51, 141, 0);
                  }
                  else
                  {
                    sub_541810(this, 0, 0);
                    *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], 137, 0);
                  }
                }
                else if ( (v50 & 0x10) == 0x10 )
                {
                  sub_55D720(a3, 1);
                }
                sub_554700(this, *(_DWORD **)(v47 + 28));
                v52 = 0;
                for ( j = 0; v52 < v80[41]; j = 0 )
                {
                  v90 = this + 1118;
                  v75 = &v76[16 * v52 + 1];
                  do
                  {
                    if ( j >= this[1260] )
                      break;
                    v54 = sub_5504D0(v80, *(_DWORD *)(v89 + 52), v52);
                    if ( sub_554F80((int)this, (_DWORD *)a2, v54) )
                    {
                      v55 = v90;
                      v75[11] = v54;
                      sub_5546A0(v55, v75, j);
                    }
                    v56 = v80[41];
                    ++v52;
                    ++j;
                    v75 += 16;
                    v47 = v89;
                    v90 += 17;
                  }
                  while ( v52 < v56 );
                  sub_553FA0(&this[17 * j + 1118], j);
                  v57 = (int)a3;
                  if ( (int)v88[63] <= 4 )
                  {
                    sub_5423C0((int)a3, 1065353216, 1176256512);
                    sub_541B70((int)a3, 4);
                  }
                  *this = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 340))(
                            this[1088],
                            *(_DWORD *)(*(_DWORD *)(v47 + 36) + 24),
                            *(_DWORD *)(v47 + 44));
                  v58 = *(_DWORD *)(v47 + 16);
                  if ( (BYTE1(v88[5]) & 0x80u) == 0 )
                  {
                    v59 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)this[1088] + 284))(
                            this[1088],
                            5,
                            0,
                            *(_DWORD *)(v47 + 8),
                            *(_DWORD *)(v47 + 48),
                            v58 - 2);
                  }
                  else
                  {
                    v59 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)this[1088] + 284))(
                            this[1088],
                            4,
                            0,
                            *(_DWORD *)(v47 + 8),
                            *(_DWORD *)(v47 + 48),
                            v58 / 3);
                    v57 = (int)a3;
                  }
                  *this = v59;
                  if ( (int)v88[63] <= 4 )
                  {
                    sub_5423C0(v57, v86, v84);
                    sub_541B70(v57, 4);
                  }
                  if ( !this[1268] )
                    break;
                  v60 = v76[16 * v52 + 9];
                  if ( v60 == 4 )
                  {
                    sub_554790(this, *v76 | 0x800, 65545, 0);
                  }
                  else if ( v60 == 2 )
                  {
                    sub_554790(this, *v76 | 0x800, 131074, 0);
                  }
                  *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 4);
                }
                v45 = v79 + 1 < *v81;
                v83 += 4;
                ++v79;
              }
              while ( v45 );
            }
          }
          else
          {
            sub_554790(this, *v76, v14[43], *(_DWORD *)(v14[42] + 132));
            v32 = v14[41];
            v33 = 0;
            v73 = 0;
            if ( v32 > 0 )
            {
              while ( 1 )
              {
                if ( v15 < v32 )
                {
                  v77 = this + 1118;
                  v74 = &v76[16 * v15 + 1];
                  do
                  {
                    if ( v33 >= this[1260] )
                      break;
                    v34 = sub_5504D0(v80, 0, v15);
                    if ( v34 )
                    {
                      if ( sub_554F80((int)this, (_DWORD *)a2, v34) )
                      {
                        v74[11] = v34;
                        sub_5546A0(v77, v74, v33);
                      }
                    }
                    else
                    {
                      sub_553FA0(v77, v33);
                    }
                    v77 += 17;
                    ++v15;
                    ++v33;
                    v74 += 16;
                  }
                  while ( v15 < v80[41] );
                  v73 = v15;
                }
                sub_553FA0(&this[17 * v33 + 1118], v33);
                v78 = 0;
                v82 = (int *)v81[1];
                if ( *v81 > 0 )
                {
                  do
                  {
                    v35 = (_DWORD *)v82[1];
                    v36 = *v82;
                    v37 = v82[2];
                    if ( (int)v35[63] <= 4 )
                    {
                      sub_5423C0((int)a3, 1065353216, 1176256512);
                      sub_541B70((int)a3, 4);
                    }
                    if ( v36 != this[1267] )
                    {
                      this[1267] = v36;
                      sub_54B9E0((char *)v36);
                    }
                    v38 = *(_DWORD *)(v36 + 60);
                    if ( this[1270] )
                    {
                      if ( (v38 & 0x10) == 0x10 )
                      {
                        sub_541810(this, v35[67], v35[68]);
                        *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 137, 1);
                        v39 = this[1088];
                        if ( (v35[5] & 0x400000) != 0 )
                          *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v39 + 200))(v39, 141, 1);
                        else
                          *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v39 + 200))(v39, 141, 0);
                      }
                      else
                      {
                        sub_541810(this, 0, 0);
                        *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(
                                  this[1088],
                                  137,
                                  0);
                      }
                    }
                    else if ( (v38 & 0x10) == 0x10 )
                    {
                      sub_55D720(a3, 1);
                    }
                    sub_554700(this, *(_DWORD **)(v37 + 28));
                    v70 = *(_DWORD *)(v37 + 44);
                    v40 = *(_DWORD *)this[1088];
                    v68 = *(_DWORD *)(*(_DWORD *)(v37 + 36) + 24);
                    v67 = this[1088];
                    if ( (v35[5] & 0x800) != 0 )
                    {
                      *this = (*(int (__stdcall **)(int, int, int))(v40 + 340))(v67, v68, v70);
                      *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 4);
                      *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 8, 2);
                      v41 = *(_DWORD *)(v37 + 16);
                      if ( (BYTE1(v35[5]) & 0x80u) == 0 )
                        v42 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)this[1088] + 284))(
                                this[1088],
                                5,
                                0,
                                *(_DWORD *)(v37 + 8),
                                *(_DWORD *)(v37 + 48),
                                v41 - 2);
                      else
                        v42 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)this[1088] + 284))(
                                this[1088],
                                4,
                                0,
                                *(_DWORD *)(v37 + 8),
                                *(_DWORD *)(v37 + 48),
                                v41 / 3);
                      *this = v42;
                      *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 2);
                      v43 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 8, 3);
                    }
                    else
                    {
                      *this = (*(int (__stdcall **)(int, int, int))(v40 + 340))(v67, v68, v70);
                      v44 = *(_DWORD *)(v37 + 16);
                      if ( (BYTE1(v35[5]) & 0x80u) == 0 )
                        v43 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)this[1088] + 284))(
                                this[1088],
                                5,
                                0,
                                *(_DWORD *)(v37 + 8),
                                *(_DWORD *)(v37 + 48),
                                v44 - 2);
                      else
                        v43 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)this[1088] + 284))(
                                this[1088],
                                4,
                                0,
                                *(_DWORD *)(v37 + 8),
                                *(_DWORD *)(v37 + 48),
                                v44 / 3);
                    }
                    *this = v43;
                    if ( (int)v35[63] <= 4 )
                    {
                      sub_5423C0((int)a3, v86, v84);
                      sub_541B70((int)a3, 4);
                    }
                    v45 = v78 + 1 < *v81;
                    v82 += 4;
                    ++v78;
                  }
                  while ( v45 );
                }
                if ( !this[1268] )
                  goto LABEL_107;
                sub_554790(this, *v76 | 0x800, 65545, 0);
                *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 4);
                v32 = v80[41];
                v33 = 0;
                if ( v73 >= v32 )
                  break;
                v15 = v73;
              }
            }
          }
          if ( this[1268] )
            *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 2);
        }
LABEL_107:
        v61 = v91 == 1;
        v76 += 132;
        v81 += 132;
        --v91;
      }
      while ( !v61 );
    }
  }
  if ( this[1340] )
    *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], 28, 0);
  v62 = (_DWORD *)a2;
  if ( (BYTE1(*(_DWORD *)(a2 + 236)) & 0x80u) == 0 && *(_DWORD *)(a2 + 348) && *(int *)(a2 + 316) > 0 )
  {
    if ( (this[1258] & 0x100) != 0 )
    {
      *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 47, 1);
    }
    else
    {
      *(float *)&v71 = *(float *)&v84 * 0.15000001 + *(float *)&v84;
      sub_5423C0((int)a3, v86, v71);
    }
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 4);
    sub_553FA0(this + 1135, 1);
    sub_553FA0(this + 1152, 2);
    sub_553FA0(this + 1169, 3);
    for ( k = *(_DWORD *)(a2 + 348); k; k = *(_DWORD *)(k + 52) )
    {
      if ( (*(_BYTE *)(k + 36) & 2) != 0 )
      {
        if ( !sub_55C9B0(this) )
        {
          sub_560FE0(0, 0);
          if ( (*(_BYTE *)(k + 36) & 8) != 0 )
            sub_541B70((int)a3, 14);
        }
        v64 = *(_DWORD *)(k + 36);
        if ( (v64 & 8) != 0 )
        {
          v72 = *(_DWORD *)(k + 16);
          *(_DWORD *)(k + 36) = v64 & 0xFFFFFFF7;
          if ( sub_554F80((int)this, v62, v72) )
          {
            sub_553DB0(v92);
            v65 = *(_DWORD *)(k + 16);
            v93 = 12;
            v94 = 2;
            v96 = v65;
            v98 = 1;
            v99 = 1;
            sub_5546A0(this + 1118, v92, 0);
            sub_554790(this, 2304, 262145, 0);
            sub_5613E0(k);
            *this = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)this[1088] + 148))(this[1088], 256, this + 1283);
            this[1267] = 0;
            if ( *(_DWORD *)(k + 4) )
            {
              sub_554700(this, (_DWORD *)(this[1107] + 36 * this[1106]));
              v62 = (_DWORD *)a2;
              *this = (*(int (__stdcall **)(int, int, _DWORD, int))(*(_DWORD *)this[1088] + 280))(
                        this[1088],
                        4,
                        0,
                        *(_DWORD *)(k + 4) / 3);
            }
          }
        }
      }
    }
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 23, 2);
    if ( (this[1258] & 0x100) != 0 )
      *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], 47, 0);
    else
      sub_5423C0((int)a3, v86, v84);
  }
  return sub_541B70((int)a3, 14);
}
