int __thiscall sub_6AD36C(int this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // edi
  bool v8; // zf
  _DWORD *v9; // eax
  _DWORD *v10; // edx
  int v11; // ecx
  int v12; // ebx
  _DWORD *v13; // eax
  unsigned int v14; // ecx
  unsigned int i; // ecx
  int v16; // eax
  int v17; // eax
  unsigned int j; // ecx
  int v19; // eax
  _DWORD *v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // edx
  int v23; // ebx
  int v24; // eax
  _DWORD *v25; // eax
  unsigned int v26; // eax
  int v27; // ebx
  int v28; // eax
  _DWORD *v29; // eax
  unsigned int v30; // eax
  int v31; // eax
  int v32; // ebx
  int v33; // eax
  _DWORD *v34; // eax
  unsigned int v35; // eax
  int v36; // eax
  int v37; // ebx
  int v38; // eax
  _DWORD *v39; // eax
  unsigned int v40; // eax
  int v41; // ebx
  int v42; // eax
  _DWORD *v43; // eax
  int v44; // ebx
  int v45; // eax
  _DWORD *v46; // eax
  int v47; // ebx
  int v48; // eax
  _DWORD *v49; // eax
  int v50; // ebx
  int v51; // eax
  int v52; // eax
  void *v53; // eax
  void *v54; // eax
  void *v56; // edi
  int *v57; // edi
  int v58; // eax
  int v59; // eax
  bool v60; // cf
  void **v61; // edi
  int v62; // eax
  _DWORD *v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // ecx
  int v67; // edi
  unsigned int v68; // eax
  void **v69; // edi
  _DWORD *v70; // eax
  unsigned int m; // ecx
  _DWORD *v72; // ecx
  int v73; // [esp-8h] [ebp-3Ch]
  int v74; // [esp+0h] [ebp-34h]
  int v75; // [esp+4h] [ebp-30h]
  char *v76; // [esp+4h] [ebp-30h]
  unsigned int v77; // [esp+14h] [ebp-20h]
  unsigned int v78; // [esp+14h] [ebp-20h]
  int v79; // [esp+14h] [ebp-20h]
  unsigned int v80; // [esp+18h] [ebp-1Ch]
  unsigned int v81; // [esp+1Ch] [ebp-18h] BYREF
  int v82; // [esp+20h] [ebp-14h]
  unsigned int v83; // [esp+24h] [ebp-10h]
  unsigned int v84; // [esp+28h] [ebp-Ch] BYREF
  unsigned int v85; // [esp+2Ch] [ebp-8h]
  unsigned int k; // [esp+30h] [ebp-4h]

  v2 = sub_681A51((void *)this, (int)"c", 785, 1, 4);
  *(_DWORD *)(this + 1088) = sub_681AAA((void *)this, v2, 0, 0, 0.0);
  *(_DWORD *)(this + 1092) = sub_681AAA((void *)this, v2, 0, 1, 1.0);
  v3 = (unsigned __int16)*(_DWORD *)(this + 200);
  *(_DWORD *)(this + 1100) = 0;
  if ( v3 == 260 )
  {
    v4 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v5 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v4;
        v6 = *(_DWORD **)(v5 + 4 * v4);
        *(_DWORD *)(this + 256) = v6;
        if ( (*v6 & 0xFFF00000) == 0x60700000 )
        {
          v7 = sub_6A251E((_DWORD *)this);
          if ( v7 < 0 )
            return v7;
        }
      }
      while ( (unsigned int)++v4 < *(_DWORD *)(this + 12) );
    }
    sub_6BC1A9(this);
    sub_6875A0((_DWORD *)this);
  }
  v8 = *(_DWORD *)(this + 12) == 0;
  v84 = 0;
  v85 = 0;
  if ( !v8 )
  {
    do
    {
      v9 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v85);
      *(_DWORD *)(this + 256) = v9;
      v8 = v9[1] == 0;
      k = 0;
      if ( !v8 )
      {
        v10 = (_DWORD *)v9[2];
        while ( 1 )
        {
          v11 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v10);
          v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v11 + 4)) + 4);
          if ( (v12 & 0x10) != 0
            && (v12 & 0x200) == 0
            && *(_DWORD *)(v11 + 16) == 3
            && *(_BYTE *)(v11 + 108) == 3
            && ((*v9 & 0xFFF00000) != 0x60700000 || k != 7) )
          {
            break;
          }
          ++k;
          ++v10;
          if ( k >= *(_DWORD *)(*(_DWORD *)(this + 256) + 4) )
            goto LABEL_19;
        }
        v75 = (unsigned __int8)*(_DWORD *)(this + 200);
        v73 = v9[15];
        v84 = 1;
        sub_686791(this, v73, 4512, "cannot access texture coordinate w-component in a general way in ps_1_%i", v75);
      }
LABEL_19:
      v13 = *(_DWORD **)(this + 256);
      v14 = *v13 & 0xFFF00000;
      if ( v14 == 1616904192 || v14 == 1622147072 || v14 == 1611661312 || v14 == 1627389952 )
      {
        sub_686791(this, v13[15], 4532, "cannot map expression to pixel shader instruction set");
        v84 = 1;
      }
      ++v85;
    }
    while ( v85 < *(_DWORD *)(this + 12) );
    if ( v84 )
      return -2147467259;
  }
  for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
  {
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i) + 56) = -1;
    v16 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i);
    if ( *(_DWORD *)(v16 + 4) == *(_DWORD *)(this + 128) )
    {
      if ( *(_BYTE *)(v16 + 108) == 1 )
        *(_DWORD *)v16 = 20;
      if ( (unsigned __int16)*(_DWORD *)(this + 200) < 0x104u )
      {
        v17 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i);
        if ( *(_BYTE *)(v17 + 108) == 3 )
          *(_DWORD *)v17 = 20;
      }
    }
  }
  for ( j = 0; j < *(_DWORD *)(this + 12); *(_DWORD *)(*(_DWORD *)(this + 256) + 36) = 0 )
  {
    v19 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 252) = j;
    v20 = *(_DWORD **)(v19 + 4 * j);
    *(_DWORD *)(this + 256) = v20;
    v21 = *v20 & 0xFFF00000;
    if ( v21 == 1610612736 || v21 == 1615855616 || v21 == 1621098496 || v21 == 1626341376 )
    {
      v22 = 0;
      if ( v20[3] )
      {
        do
          **(_DWORD **)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 16) + 4 * v22++)) = 20;
        while ( v22 < *(_DWORD *)(*(_DWORD *)(this + 256) + 12) );
      }
    }
    ++j;
  }
  v23 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    do
    {
      v24 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v23;
      v25 = *(_DWORD **)(v24 + 4 * v23);
      *(_DWORD *)(this + 256) = v25;
      v26 = *v25 & 0xFFF00000;
      if ( v26 == 0x20000000 || v26 == 537919488 || v26 == 805306368 )
      {
        v7 = sub_6BDC80(this);
        if ( v7 < 0 )
          return v7;
      }
    }
    while ( (unsigned int)++v23 < *(_DWORD *)(this + 12) );
  }
  v27 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    while ( 1 )
    {
      v28 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v27;
      v29 = *(_DWORD **)(v28 + 4 * v27);
      *(_DWORD *)(this + 256) = v29;
      v30 = *v29 & 0xFFF00000;
      if ( v30 == 0x10000000 )
        break;
      if ( v30 == 269484032 )
      {
        v31 = sub_6A2AAC(this);
        goto LABEL_54;
      }
LABEL_55:
      if ( (unsigned int)++v27 >= *(_DWORD *)(this + 12) )
        goto LABEL_56;
    }
    v31 = sub_6A2980((_DWORD *)this);
LABEL_54:
    v7 = v31;
    if ( v31 < 0 )
      return v7;
    goto LABEL_55;
  }
LABEL_56:
  sub_6BC1A9(this);
  v32 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    while ( 1 )
    {
      v33 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v32;
      v34 = *(_DWORD **)(v33 + 4 * v32);
      *(_DWORD *)(this + 256) = v34;
      v35 = *v34 & 0xFFF00000;
      if ( v35 == 269484032 )
        break;
      switch ( v35 )
      {
        case 0x20400000u:
          sub_6C8D0D(this);
          sub_6C8686(this);
          sub_6C8AE5(this, 0);
          v36 = sub_6C8983(this);
          goto LABEL_66;
        case 0x20500000u:
          sub_6C8983(this);
          goto LABEL_65;
        case 0x50000000u:
          v36 = sub_6BFAB9(this);
          goto LABEL_66;
      }
LABEL_67:
      if ( (unsigned int)++v32 >= *(_DWORD *)(this + 12) )
        goto LABEL_68;
    }
    sub_6C7940(0);
LABEL_65:
    v36 = sub_6C8C6D(this);
LABEL_66:
    v7 = v36;
    if ( v36 < 0 )
      return v7;
    goto LABEL_67;
  }
LABEL_68:
  sub_6BC1A9(this);
  v37 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    do
    {
      v38 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v37;
      v39 = *(_DWORD **)(v38 + 4 * v37);
      *(_DWORD *)(this + 256) = v39;
      v40 = *v39 & 0xFFF00000;
      if ( v40 == 541065216 || v40 == 542113792 )
      {
        v7 = sub_6A4CFF((_DWORD *)this);
        if ( v7 < 0 )
          return v7;
      }
    }
    while ( (unsigned int)++v37 < *(_DWORD *)(this + 12) );
  }
  sub_6BC1A9(this);
  v41 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    do
    {
      v42 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v41;
      v43 = *(_DWORD **)(v42 + 4 * v41);
      *(_DWORD *)(this + 256) = v43;
      if ( (*v43 & 0xFFF00000) == 0x60F00000 )
      {
        v7 = sub_6A4247((_DWORD *)this, 1);
        if ( v7 < 0 )
          return v7;
        v7 = sub_6A4247((_DWORD *)this, 0);
        if ( v7 < 0 )
          return v7;
      }
    }
    while ( (unsigned int)++v41 < *(_DWORD *)(this + 12) );
  }
  sub_6BC1A9(this);
  v44 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    do
    {
      v45 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v44;
      v46 = *(_DWORD **)(v45 + 4 * v44);
      *(_DWORD *)(this + 256) = v46;
      if ( (*v46 & 0xFFF00000) == 0x20400000 )
      {
        v7 = sub_6A4923((_DWORD *)this);
        if ( v7 < 0 )
          return v7;
      }
    }
    while ( (unsigned int)++v44 < *(_DWORD *)(this + 12) );
  }
  sub_6BC1A9(this);
  v47 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    do
    {
      v48 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v47;
      v49 = *(_DWORD **)(v48 + 4 * v47);
      *(_DWORD *)(this + 256) = v49;
      if ( (*v49 & 0xFFF00000) == 0x70300000 )
      {
        sub_6C8EAA(this);
        v7 = sub_6C3319(this, 0);
        if ( v7 < 0 )
          return v7;
      }
    }
    while ( (unsigned int)++v47 < *(_DWORD *)(this + 12) );
  }
  v50 = 0;
  v77 = *(_DWORD *)(this + 12);
  if ( v77 )
  {
    do
    {
      v51 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v50;
      *(_DWORD *)(this + 256) = *(_DWORD *)(v51 + 4 * v50);
      v7 = sub_6A3C8C((_DWORD *)this);
      if ( v7 < 0 )
        return v7;
    }
    while ( ++v50 < v77 );
  }
  sub_6BC1A9(this);
  v7 = sub_6C3EEA(this);
  if ( v7 >= 0 )
  {
    v7 = sub_6A46D4((_DWORD *)this);
    if ( v7 >= 0 )
    {
      v7 = sub_6A309B((_DWORD *)this);
      if ( v7 >= 0 )
      {
        v52 = *(_DWORD *)(this + 200);
        if ( (unsigned __int16)v52 != 260 )
        {
          if ( *(_DWORD *)(this + 12) <= 0x80u )
          {
            v7 = sub_6A5ECA((_DWORD *)this);
            if ( v7 < 0 )
              return v7;
            if ( *(_DWORD *)(this + 556) )
            {
              v7 = sub_6A2EE8((_DWORD *)this);
              if ( v7 < 0 )
                return v7;
              if ( *(_DWORD *)(this + 556) )
              {
                if ( (unsigned __int16)*(_DWORD *)(this + 200) != 260 )
                {
                  v7 = sub_6ACD31(this);
                  if ( v7 < 0 )
                    return v7;
                }
              }
            }
            if ( *(_DWORD *)(this + 560) )
            {
              if ( (unsigned __int16)*(_DWORD *)(this + 200) != 260 )
              {
                v7 = sub_6A333F((_DWORD *)this);
                if ( v7 < 0 )
                  return v7;
                v7 = sub_6AC040((_DWORD *)this);
                if ( v7 < 0 )
                  return v7;
                v7 = sub_6A3714((int *)this);
                if ( v7 < 0 )
                  return v7;
              }
            }
            *(_DWORD *)(this + 220) = 0;
            v7 = sub_6A8B00((_DWORD *)this, 0, 0);
            if ( v7 < 0 )
              return v7;
            goto LABEL_162;
          }
          sub_686791(
            this,
            0,
            4500,
            "program is order of magnitude too large to compile to ps_1_%i",
            (unsigned __int8)v52);
          return -2147467259;
        }
        v53 = operator new(0x800u);
        *(_DWORD *)(this + 556) = v53;
        if ( !v53 )
          return -2147024882;
        v54 = operator new(0x800u);
        *(_DWORD *)(this + 560) = v54;
        if ( !v54 )
          return -2147024882;
        v56 = *(void **)(this + 556);
        *(_DWORD *)(this + 548) = 0;
        *(_DWORD *)(this + 544) = 0;
        memset(v56, 0, 0x800u);
        memset(*(void **)(this + 560), 0, 0x800u);
        v7 = sub_6A6626((_DWORD *)this);
        if ( v7 >= 0 )
        {
          v7 = sub_6A6B86((_DWORD *)this);
          if ( v7 >= 0 )
          {
            if ( !sub_6A6CEE((_DWORD *)this) )
            {
              v78 = sub_6A6C14((_DWORD *)this);
              if ( v78 == -1 )
              {
                v76 = "shader too complex. Try reducing number of texture loads used";
LABEL_101:
                v7 = -2147467259;
                sub_686791(this, 0, 4500, v76);
                return v7;
              }
              sub_6A6480((_DWORD *)this);
              v84 = 0;
              v57 = (int *)(this + 772);
              do
              {
                v58 = sub_681AAA((void *)this, *(_DWORD *)(this + 136), 0, 0, 0.0);
                *v57 = v58;
                if ( v58 == -1 )
                  return -2147024882;
                v59 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v58);
                ++v84;
                ++v57;
                v60 = v84 < 0x40;
                *(_DWORD *)(v59 + 60) = 0;
              }
              while ( v60 );
              v83 = -1;
              v80 = -1;
              memset((void *)(this + 708), 0, 0x40u);
              for ( k = 0; k < v78; ++k )
              {
                memset(*(void **)(this + 556), 0, 0x800u);
                memset(*(void **)(this + 560), 0, 0x800u);
                v74 = k;
                *(_DWORD *)(this + 544) = 0;
                *(_DWORD *)(this + 548) = 0;
                if ( sub_6A6F97(this, v74, 1) )
                {
                  *(_DWORD *)(this + 1032) = 0;
                  *(_DWORD *)(this + 1028) = 0;
                  sub_6A6579((_DWORD *)this);
                  sub_6AB8A9((_DWORD *)this, *(_DWORD *)(this + 556), 6u, *(_DWORD *)(this + 544), &v81);
                  sub_6AB8A9((_DWORD *)this, *(_DWORD *)(this + 560), 6u, *(_DWORD *)(this + 548), &v84);
                  v61 = (void **)(this + 708);
                  v85 = 16;
                  do
                  {
                    if ( *v61 )
                      sub_66238F(*v61, 1);
                    *v61++ = 0;
                    --v85;
                  }
                  while ( v85 );
                  v62 = sub_6AC94E((_DWORD *)this);
                  v7 = v62;
                  if ( v62 < 0 )
                    return v7;
                  if ( v62 != 1 && sub_6A7376((_DWORD *)this, 0) >= 0 && sub_6A8B00((_DWORD *)this, 1, 1) >= 0 )
                  {
                    sub_6AB8A9((_DWORD *)this, *(_DWORD *)(this + 556), 6u, *(_DWORD *)(this + 544), &v81);
                    sub_6AB8A9((_DWORD *)this, *(_DWORD *)(this + 560), 6u, *(_DWORD *)(this + 548), &v84);
                    v63 = *(_DWORD **)(this + 560);
                    v64 = *(_DWORD *)(this + 556);
                    v65 = 0;
                    v85 = 0;
                    v66 = v64 - (_DWORD)v63;
                    v82 = 6;
                    do
                    {
                      if ( *(_DWORD *)((char *)v63 + v66) )
                        ++v65;
                      if ( *v63 )
                        ++v85;
                      ++v63;
                      --v82;
                    }
                    while ( v82 );
                    v82 = v81;
                    if ( v81 <= 2 * v65 )
                      v82 = 2 * v65;
                    v67 = v84;
                    if ( v84 <= 2 * v85 )
                      v67 = 2 * v85;
                    v68 = v82 + v67 + (v65 + v81 != 0 ? 0xA : 0);
                    if ( v81 > 8 )
                      v68 += 20;
                    if ( v84 > 8 )
                      v68 += 20;
                    if ( v68 < v80 )
                    {
                      v83 = k;
                      v80 = v68;
                    }
                    *(_DWORD *)(this + 1028) = 0;
                  }
                }
              }
              memset(*(void **)(this + 556), 0, 0x800u);
              memset(*(void **)(this + 560), 0, 0x800u);
              *(_DWORD *)(this + 544) = 0;
              *(_DWORD *)(this + 548) = 0;
              v69 = (void **)(this + 708);
              v79 = 12;
              do
              {
                if ( *v69 )
                  sub_66238F(*v69, 1);
                *v69++ = 0;
                --v79;
              }
              while ( v79 );
              if ( v83 == -1 )
              {
                v76 = "program too complex to compile to ps_1_4";
                goto LABEL_101;
              }
              sub_6A6F97(this, v83, 0);
              sub_6A6579((_DWORD *)this);
              sub_6AC94E((_DWORD *)this);
              v7 = sub_6A7376((_DWORD *)this, 0);
              if ( v7 < 0 )
                return v7;
              v7 = sub_6A8B00((_DWORD *)this, 0, 0);
              if ( v7 < 0 )
                return v7;
              v70 = *(_DWORD **)(this + 556);
              for ( m = 0; m < 6; ++m )
              {
                if ( *v70 )
                  break;
                ++v70;
              }
              if ( *(_DWORD *)(this + 544) == 6 && m == 6 )
                *(_DWORD *)(this + 544) = 0;
LABEL_162:
              *(_DWORD *)(this + 220) = 1;
              v7 = sub_6A800A((_DWORD *)this);
              if ( v7 >= 0 )
              {
                v7 = sub_6AB8A9((_DWORD *)this, *(_DWORD *)(this + 556), 0, *(_DWORD *)(this + 544), 0);
                if ( v7 >= 0 )
                {
                  v7 = sub_6AB8A9((_DWORD *)this, *(_DWORD *)(this + 560), 0, *(_DWORD *)(this + 548), 0);
                  if ( v7 >= 0 )
                  {
                    v7 = sub_6A2CA6((_DWORD *)this);
                    if ( v7 >= 0 )
                    {
                      if ( !*(_DWORD *)(this + 560) )
                        return 0;
                      if ( (unsigned __int16)*(_DWORD *)(this + 200) == 260 )
                        return 0;
                      v7 = sub_6A243F(v72);
                      if ( v7 >= 0 )
                        return 0;
                    }
                  }
                }
              }
              return v7;
            }
            return -2147467259;
          }
        }
      }
    }
  }
  return v7;
}
