int __thiscall sub_5AB3E0(int this, int a2, _DWORD *a3)
{
  int v4; // eax
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  _DWORD *v10; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // esi
  int *v14; // edi
  int v15; // ebx
  int v16; // eax
  int v17; // edi
  char *v18; // edi
  int v19; // ebx
  int v20; // esi
  int v21; // edx
  int v22; // eax
  bool v23; // cc
  char *v24; // edi
  int v25; // esi
  int v26; // eax
  int v27; // ebx
  int j; // edi
  int v29; // eax
  int v30; // edx
  int v31; // eax
  int v32; // eax
  bool v33; // zf
  _DWORD *v34; // esi
  _DWORD *v35; // edi
  int v36; // ebx
  int v37; // eax
  int v38; // eax
  double v39; // st7
  int v40; // eax
  int v42; // [esp+FCh] [ebp-214h]
  int v43; // [esp+FCh] [ebp-214h]
  int *v44; // [esp+110h] [ebp-200h]
  float *v45; // [esp+114h] [ebp-1FCh]
  int v46; // [esp+114h] [ebp-1FCh]
  int v47; // [esp+114h] [ebp-1FCh]
  int v48; // [esp+118h] [ebp-1F8h]
  int v49; // [esp+118h] [ebp-1F8h]
  _DWORD *v50; // [esp+11Ch] [ebp-1F4h]
  int v51; // [esp+120h] [ebp-1F0h]
  int v52; // [esp+120h] [ebp-1F0h]
  int *v53; // [esp+124h] [ebp-1ECh]
  int v54; // [esp+128h] [ebp-1E8h]
  _DWORD *k; // [esp+128h] [ebp-1E8h]
  int v56; // [esp+12Ch] [ebp-1E4h]
  int v57; // [esp+130h] [ebp-1E0h] BYREF
  int v58; // [esp+134h] [ebp-1DCh] BYREF
  int i; // [esp+138h] [ebp-1D8h]
  int v60; // [esp+13Ch] [ebp-1D4h]
  float *v61; // [esp+140h] [ebp-1D0h]
  int v62; // [esp+144h] [ebp-1CCh]
  int v63; // [esp+148h] [ebp-1C8h] BYREF
  int v64; // [esp+14Ch] [ebp-1C4h] BYREF
  _DWORD v65[16]; // [esp+150h] [ebp-1C0h] BYREF
  _BYTE v66[64]; // [esp+190h] [ebp-180h] BYREF
  _BYTE v67[64]; // [esp+1D0h] [ebp-140h] BYREF
  _BYTE v68[64]; // [esp+210h] [ebp-100h] BYREF
  _DWORD v69[16]; // [esp+250h] [ebp-C0h] BYREF
  _BYTE v70[64]; // [esp+290h] [ebp-80h] BYREF
  _BYTE v71[64]; // [esp+2D0h] [ebp-40h] BYREF

  *(_DWORD *)(this + 5168) = 0;
  sub_593EF0(a3, &v58, &v57);
  sub_593E40(a3, &v64, &v63);
  if ( *(_DWORD *)(this + 5160) != 1 )
  {
    v4 = *(_DWORD *)(this + 4448);
    *(_DWORD *)(this + 5160) = 1;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v4 + 200))(v4, 136, 1);
  }
  if ( sub_5B4BE0(this) )
  {
    if ( (BYTE1(*(_DWORD *)(a2 + 240)) & 0x80u) == 0 )
    {
      v5 = *(_DWORD **)(a2 + 360);
      if ( v5 )
      {
        if ( *(int *)(a2 + 328) > 0 )
        {
          do
          {
            if ( (*(_BYTE *)(*v5 + 40) & 2) != 0 )
              sub_5B8990(0, 0);
            v5 = (_DWORD *)v5[1];
          }
          while ( v5 );
          sub_5932C0((int)a3, 14);
        }
      }
    }
  }
  sub_5AACC0((int *)this, (int)a3, 0);
  sub_5AA8A0((int *)this, 0);
  v6 = *(_DWORD *)(a2 + 240);
  if ( (v6 & 0x10000) != 0 )
  {
    *(_DWORD *)(a2 + 240) = v6 & 0xFFFEFFFF;
    sub_5AC380(a2);
  }
  if ( *(_DWORD *)(this + 8540) )
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                        *(_DWORD *)(this + 4448),
                        28,
                        1);
  v7 = (__int64)(*(float *)(a2 + 400) * -255.0)
     - (((unsigned int)(__int64)(*(float *)(a2 + 396) * 255.0)
       - ((unsigned int)(__int64)(*(float *)(a2 + 392) * -255.0) << 8)) << 8)
     + 0xFFFFFF;
  *(_DWORD *)(a2 + 352) = v7;
  if ( *(_DWORD *)(this + 5164) != v7 )
  {
    v8 = *(_DWORD *)(this + 4448);
    *(_DWORD *)(this + 5164) = v7;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v8 + 200))(v8, 60, v7);
  }
  for ( i = 0; i < 4; ++i )
  {
    switch ( i )
    {
      case 0:
        v56 = *(_DWORD *)(a2 + 452);
        v44 = *(int **)(a2 + 456);
        sub_5AAD80((int *)this, 1);
        v9 = (int)a3;
        sub_593D20((int)a3, 1065353216, 1176256512);
        goto LABEL_24;
      case 1:
        v56 = *(_DWORD *)(a2 + 468);
        v44 = *(int **)(a2 + 472);
        goto LABEL_26;
      case 2:
        v9 = (int)a3;
        if ( *(_DWORD *)(a2 + 452) + *(_DWORD *)(a2 + 468) > 0 )
          sub_5AACC0((int *)this, (int)a3, 1);
        v56 = *(_DWORD *)(a2 + 460);
        v44 = *(int **)(a2 + 464);
        sub_5AAD80((int *)this, 1);
        sub_593D20((int)a3, v58, v57);
LABEL_24:
        sub_5932C0(v9, 4);
        break;
      case 3:
        v56 = *(_DWORD *)(a2 + 476);
        v44 = *(int **)(a2 + 480);
LABEL_26:
        sub_5AAD80((int *)this, 0);
        break;
      default:
        break;
    }
    if ( v56 > 0 )
    {
      v53 = v44 + 130;
      v54 = v56;
      do
      {
        if ( *v53 > 0 )
        {
          v10 = *(_DWORD **)(v53[1] + 12);
          v50 = v10;
          if ( (v10[39] & 0x400) != 0 )
          {
            v47 = 0;
            v52 = v53[1];
            if ( *v53 > 0 )
            {
              do
              {
                v24 = *(char **)v52;
                v25 = *(_DWORD *)(v52 + 8);
                v26 = *(_DWORD *)(this + 5172);
                v60 = *(_DWORD *)(v52 + 4);
                if ( v26 )
                  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                                      *(_DWORD *)(this + 4448),
                                      23,
                                      2);
                sub_5AA930((int *)this, *v44, v50[45], *(_DWORD *)(v50[44] + 132));
                if ( v24 != *(char **)(this + 5168) )
                {
                  *(_DWORD *)(this + 5168) = v24;
                  sub_59E670(v24);
                }
                if ( (v24[60] & 0x10) == 0x10 )
                  sub_5B5DC0(a3, 1);
                sub_5AA8A0((int *)this, *(_DWORD **)(v25 + 28));
                v27 = 0;
                for ( j = 0; v27 < v50[43]; j = 0 )
                {
                  v61 = (float *)(this + 4568);
                  v49 = (int)&v44[16 * v27 + 1];
                  do
                  {
                    if ( j >= *(_DWORD *)(this + 5136) )
                      break;
                    v62 = sub_5A2870(v50, *(_DWORD *)(v25 + 52), v27);
                    if ( sub_5AB250(this, (_DWORD *)a2, v62) )
                    {
                      *(_DWORD *)(v49 + 44) = v62;
                      sub_5AA830(v61, v49, j);
                    }
                    ++v27;
                    v49 += 64;
                    v29 = v50[43];
                    ++j;
                    v61 += 17;
                  }
                  while ( v27 < v29 );
                  sub_5AA130((_DWORD *)(68 * j + this + 4568), j);
                  if ( (*(_DWORD *)(v25 + 56) & 0x1000) != 0 )
                    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                                        *(_DWORD *)(this + 4448),
                                        47,
                                        *(_DWORD *)(v25 + 60));
                  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4448) + 340))(
                                      *(_DWORD *)(this + 4448),
                                      *(_DWORD *)(*(_DWORD *)(v25 + 36) + 24),
                                      *(_DWORD *)(v25 + 44));
                  v30 = *(_DWORD *)(v25 + 16);
                  if ( (BYTE1(*(_DWORD *)(v60 + 20)) & 0x80u) == 0 )
                    v31 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4448)
                                                                                         + 284))(
                            *(_DWORD *)(this + 4448),
                            5,
                            0,
                            *(_DWORD *)(v25 + 8),
                            *(_DWORD *)(v25 + 48),
                            v30 - 2);
                  else
                    v31 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4448)
                                                                                         + 284))(
                            *(_DWORD *)(this + 4448),
                            4,
                            0,
                            *(_DWORD *)(v25 + 8),
                            *(_DWORD *)(v25 + 48),
                            v30 / 3);
                  *(_DWORD *)this = v31;
                  if ( (*(_DWORD *)(v25 + 56) & 0x1000) != 0 )
                    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                                        *(_DWORD *)(this + 4448),
                                        47,
                                        0);
                  if ( !*(_DWORD *)(this + 5172) )
                    break;
                  v32 = v44[16 * v27 + 9];
                  if ( v32 == 4 )
                  {
                    sub_5AA930((int *)this, *v44 | 0x800, 65545, 0);
                  }
                  else if ( v32 == 2 )
                  {
                    sub_5AA930((int *)this, *v44 | 0x800, 131074, 0);
                  }
                  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                                      *(_DWORD *)(this + 4448),
                                      23,
                                      4);
                }
                v23 = v47 + 1 < *v53;
                v52 += 16;
                ++v47;
              }
              while ( v23 );
            }
          }
          else
          {
            sub_5AA930((int *)this, *v44, v10[45], *(_DWORD *)(v10[44] + 132));
            v11 = v10[43];
            v12 = 0;
            v13 = 0;
            v48 = 0;
            if ( v11 > 0 )
            {
              v14 = v44;
              while ( 1 )
              {
                if ( v12 < v11 )
                {
                  v45 = (float *)(this + 4568);
                  v15 = (int)&v14[16 * v12 + 1];
                  do
                  {
                    if ( v13 >= *(_DWORD *)(this + 5136) )
                      break;
                    v16 = sub_5A2870(v50, 0, v48);
                    v17 = v16;
                    if ( v16 )
                    {
                      if ( sub_5AB250(this, (_DWORD *)a2, v16) )
                      {
                        *(_DWORD *)(v15 + 44) = v17;
                        sub_5AA830(v45, v15, v13);
                      }
                    }
                    else
                    {
                      sub_5AA130(v45, v13);
                    }
                    v45 += 17;
                    v15 += 64;
                    ++v13;
                    ++v48;
                  }
                  while ( v48 < v50[43] );
                }
                sub_5AA130((_DWORD *)(68 * v13 + this + 4568), v13);
                v51 = v53[1];
                v46 = 0;
                if ( *v53 > 0 )
                {
                  do
                  {
                    v18 = *(char **)v51;
                    v19 = *(_DWORD *)(v51 + 4);
                    v20 = *(_DWORD *)(v51 + 8);
                    if ( *(_DWORD *)v51 != *(_DWORD *)(this + 5168) )
                    {
                      *(_DWORD *)(this + 5168) = v18;
                      sub_59E670(v18);
                    }
                    if ( (v18[60] & 0x10) == 0x10 )
                      sub_5B5DC0(a3, 1);
                    sub_5AA8A0((int *)this, *(_DWORD **)(v20 + 28));
                    if ( (*(_DWORD *)(v20 + 56) & 0x1000) != 0 )
                      *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                                          *(_DWORD *)(this + 4448),
                                          47,
                                          *(_DWORD *)(v20 + 60));
                    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4448) + 340))(
                                        *(_DWORD *)(this + 4448),
                                        *(_DWORD *)(*(_DWORD *)(v20 + 36) + 24),
                                        *(_DWORD *)(v20 + 44));
                    v21 = *(_DWORD *)(v20 + 16);
                    if ( (BYTE1(*(_DWORD *)(v19 + 20)) & 0x80u) == 0 )
                      v22 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4448)
                                                                                           + 284))(
                              *(_DWORD *)(this + 4448),
                              5,
                              0,
                              *(_DWORD *)(v20 + 8),
                              *(_DWORD *)(v20 + 48),
                              v21 - 2);
                    else
                      v22 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4448)
                                                                                           + 284))(
                              *(_DWORD *)(this + 4448),
                              4,
                              0,
                              *(_DWORD *)(v20 + 8),
                              *(_DWORD *)(v20 + 48),
                              v21 / 3);
                    *(_DWORD *)this = v22;
                    if ( (*(_DWORD *)(v20 + 56) & 0x1000) != 0 )
                      *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                                          *(_DWORD *)(this + 4448),
                                          47,
                                          0);
                    v23 = v46 + 1 < *v53;
                    v51 += 16;
                    ++v46;
                  }
                  while ( v23 );
                }
                if ( !*(_DWORD *)(this + 5172) )
                  goto LABEL_87;
                v14 = v44;
                sub_5AA930((int *)this, *v44 | 0x800, 65545, 0);
                *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                                    *(_DWORD *)(this + 4448),
                                    23,
                                    4);
                v11 = v50[43];
                v13 = 0;
                if ( v48 >= v11 )
                  break;
                v12 = v48;
              }
            }
          }
          if ( *(_DWORD *)(this + 5172) )
            *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                                *(_DWORD *)(this + 4448),
                                23,
                                2);
        }
LABEL_87:
        v33 = v54 == 1;
        v44 += 132;
        v53 += 132;
        --v54;
      }
      while ( !v33 );
    }
  }
  if ( *(_DWORD *)(this + 8540) )
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                        *(_DWORD *)(this + 4448),
                        28,
                        0);
  v34 = (_DWORD *)a2;
  if ( (BYTE1(*(_DWORD *)(a2 + 240)) & 0x80u) == 0 && *(_DWORD *)(a2 + 360) && *(int *)(a2 + 328) > 0 )
  {
    if ( (*(_DWORD *)(this + 5128) & 0x100) != 0 )
    {
      *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                          *(_DWORD *)(this + 4448),
                          47,
                          2);
    }
    else
    {
      *(float *)&v42 = *(float *)&v57 * 0.15000001 + *(float *)&v57;
      sub_593D20((int)a3, v58, v42);
    }
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                        *(_DWORD *)(this + 4448),
                        23,
                        4);
    sub_5AA130((_DWORD *)(this + 4636), 1);
    sub_5AA130((_DWORD *)(this + 4704), 2);
    sub_5AA130((_DWORD *)(this + 4772), 3);
    v35 = *(_DWORD **)(a2 + 360);
    for ( k = v35; v35; k = v35 )
    {
      v36 = *v35;
      if ( (*(_BYTE *)(*v35 + 40) & 2) != 0 )
      {
        if ( !sub_5B4BE0(this) )
        {
          sub_5B8990(0, 0);
          if ( (*(_BYTE *)(v36 + 40) & 8) != 0 )
            sub_5932C0((int)a3, 14);
        }
        v37 = *(_DWORD *)(v36 + 40);
        if ( (v37 & 8) != 0 )
        {
          v43 = *(_DWORD *)(v36 + 20);
          *(_DWORD *)(v36 + 40) = v37 & 0xFFFFFFF7;
          if ( sub_5AB250(this, v34, v43) )
          {
            sub_5A9F40(v65);
            v65[11] = *(_DWORD *)(v36 + 20);
            v65[8] = 12;
            v65[9] = 2;
            v65[13] = 1;
            v65[14] = 1;
            sub_5AA830((float *)(this + 4568), (int)v65, 0);
            sub_5AA930((int *)this, 2304, 262145, 0);
            sub_5B8C10(v36);
            *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 148))(
                                *(_DWORD *)(this + 4448),
                                256,
                                this + 8312);
            *(_DWORD *)(this + 5168) = 0;
            if ( *(_DWORD *)(v36 + 4) )
            {
              v65[10] = 1;
              sub_5AA830((float *)(this + 4568), (int)v65, 0);
              *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, int, int))(**(_DWORD **)(this + 4448) + 252))(
                                  *(_DWORD *)(this + 4448),
                                  0,
                                  11,
                                  0x20000);
              *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, int, int))(**(_DWORD **)(this + 4448) + 252))(
                                  *(_DWORD *)(this + 4448),
                                  0,
                                  24,
                                  259);
              v38 = *(_DWORD *)(v36 + 16);
              v39 = (double)*(int *)(v38 + 84);
              v60 = v38;
              flt_61BBF8 = 0.5 / v39 + 0.5;
              flt_61BBFC = 0.5 / (double)*(int *)(v38 + 88) + 0.5;
              sub_54992B();
              qmemcpy(v66, v68, sizeof(v66));
              sub_54992B();
              qmemcpy(v67, v70, sizeof(v67));
              sub_54992B();
              v40 = *(_DWORD *)(this + 4448);
              qmemcpy(v71, v69, sizeof(v71));
              (*(void (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)v40 + 148))(v40, 16, v71);
              sub_5AA8A0((int *)this, *(_DWORD **)(v36 + 12));
              *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)(this + 4448) + 280))(
                                  *(_DWORD *)(this + 4448),
                                  4,
                                  0,
                                  *(_DWORD *)(v36 + 4) / 3);
              *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 148))(
                                  *(_DWORD *)(this + 4448),
                                  16,
                                  this + 8312);
              v35 = k;
              *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 252))(
                                  *(_DWORD *)(this + 4448),
                                  0,
                                  24,
                                  0);
            }
            v34 = (_DWORD *)a2;
          }
        }
      }
      v35 = (_DWORD *)v35[1];
    }
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 4448) + 200))(
                        *(_DWORD *)(this + 4448),
                        23,
                        2);
    if ( (*(_DWORD *)(this + 5128) & 0x100) != 0 )
      *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 200))(
                          *(_DWORD *)(this + 4448),
                          47,
                          0);
    else
      sub_593D20((int)a3, v58, v57);
  }
  return sub_5932C0((int)a3, 14);
}
