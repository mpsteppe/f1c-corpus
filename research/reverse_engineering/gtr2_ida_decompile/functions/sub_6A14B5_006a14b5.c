int __thiscall sub_6A14B5(int this)
{
  int v2; // edi
  unsigned int v3; // ecx
  int v4; // eax
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  _DWORD *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // eax
  _DWORD *v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  int v21; // ecx
  _DWORD *v22; // eax
  unsigned int v23; // eax
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // eax
  _DWORD *v27; // eax
  int v28; // ecx
  int v29; // eax
  _DWORD *v30; // eax
  unsigned int v31; // eax
  int v32; // eax
  unsigned int v33; // ecx
  int v34; // eax
  _DWORD *v35; // eax
  unsigned int v36; // eax
  int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  _DWORD *v40; // eax
  unsigned int v41; // ecx
  int v42; // eax
  _DWORD *v43; // eax
  unsigned int v44; // eax
  unsigned int k; // edi
  int v46; // eax
  _DWORD *v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // ecx
  int v50; // eax
  _DWORD *v51; // eax
  unsigned int v52; // ecx
  int v53; // eax
  _DWORD *v54; // eax
  unsigned int v55; // ecx
  int v56; // eax
  _DWORD *v57; // eax
  unsigned int v58; // ecx
  int v59; // eax
  _DWORD *v60; // eax
  unsigned int v61; // ecx
  int v62; // eax
  _DWORD *v63; // eax
  unsigned int v64; // eax
  int v65; // eax
  int v67; // [esp+8h] [ebp-8h]
  unsigned int v68; // [esp+8h] [ebp-8h]
  int mm; // [esp+8h] [ebp-8h]
  unsigned int nn; // [esp+8h] [ebp-8h]
  int j; // [esp+8h] [ebp-8h]
  unsigned int m; // [esp+8h] [ebp-8h]
  unsigned int n; // [esp+8h] [ebp-8h]
  unsigned int ii; // [esp+8h] [ebp-8h]
  unsigned int jj; // [esp+8h] [ebp-8h]
  int v76; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]
  int v78; // [esp+Ch] [ebp-4h]
  int v79; // [esp+Ch] [ebp-4h]
  int kk; // [esp+Ch] [ebp-4h]
  int v81; // [esp+Ch] [ebp-4h]
  int v82; // [esp+Ch] [ebp-4h]
  int v83; // [esp+Ch] [ebp-4h]

  if ( (*(_BYTE *)(this + 112) & 0x40) != 0 )
  {
    v2 = v67;
  }
  else
  {
    v2 = sub_6A0FA0((_DWORD *)this);
    if ( v2 < 0 )
      return v2;
  }
  v3 = 0;
  for ( i = 0; v3 < *(_DWORD *)(this + 12); i = v3 )
  {
    v4 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 252) = v3;
    v5 = *(_DWORD **)(v4 + 4 * v3);
    *(_DWORD *)(this + 256) = v5;
    if ( (*v5 & 0xFFF00000) == 0x11400000 )
    {
      v2 = sub_6C09A6(this);
      if ( v2 < 0 )
        return v2;
      v3 = i;
    }
    else
    {
      v2 = 1;
    }
    ++v3;
  }
  if ( (*(_BYTE *)(this + 204) & 4) != 0 )
  {
    sub_686606((_DWORD *)this);
    v78 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      v6 = 0;
      do
      {
        v7 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v6;
        v8 = *(_DWORD **)(v7 + 4 * v6);
        *(_DWORD *)(this + 256) = v8;
        if ( (*v8 & 0xFFF00000) == 0x10000000 )
        {
          sub_6BD2A2(this);
          v6 = v78;
        }
        v78 = ++v6;
      }
      while ( v6 < *(_DWORD *)(this + 12) );
    }
    sub_68661F((_DWORD *)this);
    if ( (*(_BYTE *)(this + 204) & 4) != 0 )
    {
LABEL_118:
      sub_6BC1A9(this);
      v41 = 0;
      for ( j = 0; v41 < *(_DWORD *)(this + 12); j = ++v41 )
      {
        v42 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v41;
        v43 = *(_DWORD **)(v42 + 4 * v41);
        *(_DWORD *)(this + 256) = v43;
        v44 = *v43 & 0xFFF00000;
        if ( v44 == 1952448512 || v44 == 1953497088 )
        {
          v2 = sub_6C1B55(this);
          if ( v2 < 0 )
            return v2;
          v2 = sub_6C1CA3(this);
          if ( v2 < 0 )
            return v2;
          v41 = j;
        }
      }
      for ( k = 0; k < *(_DWORD *)(this + 12); ++k )
      {
        v46 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = k;
        v47 = *(_DWORD **)(v46 + 4 * k);
        *(_DWORD *)(this + 256) = v47;
        v48 = *v47 & 0xFFF00000;
        if ( v48 == 1950351360 || v48 == 1951399936 || v48 == 1952448512 || v48 == 1953497088 )
          sub_6C1E05(this);
      }
      v49 = 0;
      for ( m = 0; v49 < *(_DWORD *)(this + 12); m = v49 )
      {
        v50 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v49;
        v51 = *(_DWORD **)(v50 + 4 * v49);
        *(_DWORD *)(this + 256) = v51;
        if ( (*v51 & 0xFFF00000) == 0x20900000 )
        {
          v2 = sub_6C1337(this);
          if ( v2 < 0 )
            return v2;
          v49 = m;
        }
        ++v49;
      }
      sub_6BC1A9(this);
      v52 = 0;
      for ( n = 0; v52 < *(_DWORD *)(this + 12); n = v52 )
      {
        v53 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v52;
        v54 = *(_DWORD **)(v53 + 4 * v52);
        *(_DWORD *)(this + 256) = v54;
        if ( (*v54 & 0xFFF00000) == 0x20900000 )
        {
          v2 = sub_6C0E5D(this);
          if ( v2 < 0 )
            return v2;
          v52 = n;
        }
        ++v52;
      }
      v55 = 0;
      for ( ii = 0; v55 < *(_DWORD *)(this + 12); ii = v55 )
      {
        v56 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v55;
        v57 = *(_DWORD **)(v56 + 4 * v55);
        *(_DWORD *)(this + 256) = v57;
        if ( (*v57 & 0xFFF00000) == 0x11400000 )
        {
          v2 = sub_6BC4F5(this);
          if ( v2 < 0 )
            return v2;
          v55 = ii;
        }
        ++v55;
      }
      v58 = 0;
      for ( jj = 0; v58 < *(_DWORD *)(this + 12); jj = v58 )
      {
        v59 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v58;
        v60 = *(_DWORD **)(v59 + 4 * v58);
        *(_DWORD *)(this + 256) = v60;
        if ( (*v60 & 0xFFF00000) == 0x70300000 )
        {
          v2 = sub_6C3319(this, 0);
          if ( v2 < 0 )
            return v2;
          v58 = jj;
        }
        ++v58;
      }
      sub_6BC1A9(this);
      v61 = 0;
      v76 = 0;
      if ( *(_DWORD *)(this + 12) )
      {
        while ( 1 )
        {
          v62 = *(_DWORD *)(this + 24);
          *(_DWORD *)(this + 252) = v61;
          v63 = *(_DWORD **)(v62 + 4 * v61);
          *(_DWORD *)(this + 256) = v63;
          v64 = *v63 & 0xFFF00000;
          if ( v64 == 271581184 || v64 == 273678336 || v64 == 274726912 || v64 == 275775488 || v64 == 1342177280 )
            break;
          if ( v64 == 1882193920 )
          {
            v65 = sub_6C8EAA(this);
LABEL_161:
            v2 = v65;
            if ( v65 < 0 )
              return v2;
            v61 = v76;
          }
          v76 = ++v61;
          if ( v61 >= *(_DWORD *)(this + 12) )
            goto LABEL_164;
        }
        v65 = sub_6BFAB9(this);
        goto LABEL_161;
      }
LABEL_164:
      sub_6BC1A9(this);
      v2 = sub_6875A0((_DWORD *)this);
      if ( v2 >= 0 )
      {
        v2 = sub_68FECA((_DWORD *)this);
        if ( v2 >= 0 )
        {
          v2 = sub_6825A9((_DWORD *)this);
          if ( v2 >= 0 )
          {
            v2 = sub_688BDF((_DWORD *)this);
            if ( v2 >= 0 )
            {
              sub_6BC1A9(this);
              return 0;
            }
          }
        }
      }
      return v2;
    }
  }
  v9 = 0;
  v79 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    while ( 1 )
    {
      v10 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v9;
      v11 = *(_DWORD **)(v10 + 4 * v9);
      *(_DWORD *)(this + 256) = v11;
      v12 = *v11 & 0xFFF00000;
      if ( v12 == 269484032 )
        break;
      if ( v12 == 0x20000000 || v12 == 537919488 || v12 == 805306368 )
      {
        v2 = sub_6BDC80(this);
        sub_6BC1A9(this);
LABEL_26:
        if ( v2 < 0 )
          return v2;
        v9 = v79;
        goto LABEL_28;
      }
      v2 = 1;
LABEL_28:
      v79 = ++v9;
      if ( v9 >= *(_DWORD *)(this + 12) )
        goto LABEL_29;
    }
    v2 = sub_6C7940(1);
    goto LABEL_26;
  }
LABEL_29:
  if ( *(char *)(this + 108) < 0 && (*(_BYTE *)(this + 113) & 1) != 0 )
  {
    v13 = 0;
    for ( kk = 0; v13 < *(_DWORD *)(this + 12); kk = ++v13 )
    {
      v14 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v13;
      v15 = *(_DWORD **)(v14 + 4 * v13);
      *(_DWORD *)(this + 256) = v15;
      if ( (*v15 & 0xFFF00000) == 0x30000000 )
      {
        if ( v2 < 0 )
          return v2;
        v2 = sub_6BD325(0, 0, 0);
        if ( v2 < 0 )
          return v2;
        v2 = sub_6BD921(0, 0, 0);
        if ( v2 < 0 )
          return v2;
        v13 = kk;
      }
      else
      {
        v2 = 1;
      }
    }
    v2 = sub_6875A0((_DWORD *)this);
    if ( v2 < 0 )
      return v2;
    sub_6BC1A9(this);
    v81 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v16 = v81;
        v17 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v81;
        v18 = *(_DWORD **)(v17 + 4 * v81);
        *(_DWORD *)(this + 256) = v18;
        v19 = *v18 & 0xFFF00000;
        if ( v19 == 0x20000000 )
          break;
        if ( v19 == 805306368 )
        {
          v2 = sub_6C2C9E(this);
          if ( v2 < 0 )
            return v2;
          v2 = sub_6C2D70(this);
          goto LABEL_48;
        }
        if ( v19 == 1890582528 )
          break;
        v2 = 1;
LABEL_50:
        v81 = v16 + 1;
        if ( (unsigned int)(v16 + 1) >= *(_DWORD *)(this + 12) )
          goto LABEL_51;
      }
      v2 = sub_6BDC80(this);
      sub_6BC1A9(this);
LABEL_48:
      if ( v2 < 0 )
        return v2;
      v16 = v81;
      goto LABEL_50;
    }
  }
LABEL_51:
  v20 = 0;
  v68 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    while ( 1 )
    {
      v21 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v20;
      v22 = *(_DWORD **)(v21 + 4 * v20);
      *(_DWORD *)(this + 256) = v22;
      v23 = *v22 & 0xFFF00000;
      if ( v23 == 273678336 )
        break;
      switch ( v23 )
      {
        case 0x10F00000u:
          v24 = sub_6BFDA7(this);
          goto LABEL_65;
        case 0x11400000u:
          v24 = sub_6C09A6(this);
          goto LABEL_65;
        case 0x20100000u:
          if ( (unsigned __int16)*(_DWORD *)(this + 200) >= 0x200u )
          {
            v24 = sub_6C2BAB(this);
            goto LABEL_65;
          }
          goto LABEL_68;
      }
      if ( v23 != 541065216 )
        goto LABEL_68;
      if ( (*(_BYTE *)(this + 108) & 0x20) != 0 )
        v2 = sub_6C2620(this);
      if ( v2 == 1 )
      {
        v24 = sub_6C79FA(1);
LABEL_65:
        v2 = v24;
      }
LABEL_69:
      v25 = 0;
      v82 = 0;
      if ( *(_DWORD *)(this + 12) )
      {
        v2 = 1;
        do
        {
          v26 = *(_DWORD *)(this + 24);
          *(_DWORD *)(this + 252) = v25;
          v27 = *(_DWORD **)(v26 + 4 * v25);
          *(_DWORD *)(this + 256) = v27;
          if ( (*v27 & 0xFFF00000) == 0x70000000 )
          {
            sub_6C7980(this);
            v25 = v82;
          }
          v82 = ++v25;
        }
        while ( v25 < *(_DWORD *)(this + 12) );
      }
      if ( v2 < 0 )
        return v2;
      v20 = ++v68;
      if ( v68 >= *(_DWORD *)(this + 12) )
        goto LABEL_76;
    }
    if ( (unsigned __int16)*(_DWORD *)(this + 200) >= 0x200u )
    {
      v24 = sub_6BCE19(this);
      goto LABEL_65;
    }
LABEL_68:
    v2 = 1;
    goto LABEL_69;
  }
LABEL_76:
  v2 = sub_6875A0((_DWORD *)this);
  if ( v2 >= 0 )
  {
    sub_6BC1A9(this);
    v83 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v28 = v83;
        v29 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v83;
        v30 = *(_DWORD **)(v29 + 4 * v83);
        *(_DWORD *)(this + 256) = v30;
        v31 = *v30 & 0xFFF00000;
        if ( v31 == 542113792 )
        {
          v32 = sub_6C201D(this);
          goto LABEL_94;
        }
        if ( v31 == 1342177280 )
          break;
        switch ( v31 )
        {
          case 0x70300000u:
            v32 = sub_6C3319(this, 1);
            goto LABEL_94;
          case 0x73500000u:
          case 0x73600000u:
            v2 = sub_6C04DE(this);
            if ( v2 < 0 )
              return v2;
            v32 = sub_6C062C(this);
LABEL_94:
            v2 = v32;
LABEL_95:
            if ( v2 < 0 )
              return v2;
            v28 = v83;
            goto LABEL_97;
          case 0x74600000u:
          case 0x74700000u:
            v2 = sub_6C1B55(this);
            if ( v2 < 0 )
              return v2;
            v32 = sub_6C1CA3(this);
            goto LABEL_94;
        }
        v2 = 1;
LABEL_97:
        v83 = v28 + 1;
        if ( (unsigned int)(v28 + 1) >= *(_DWORD *)(this + 12) )
          goto LABEL_98;
      }
      if ( (*(_BYTE *)(this + 108) & 0x20) != 0 )
      {
        v32 = sub_6C28E0(this);
        goto LABEL_94;
      }
      goto LABEL_95;
    }
LABEL_98:
    v33 = 0;
    for ( mm = 0; v33 < *(_DWORD *)(this + 12); mm = ++v33 )
    {
      v34 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v33;
      v35 = *(_DWORD **)(v34 + 4 * v33);
      *(_DWORD *)(this + 256) = v35;
      v36 = *v35 & 0xFFF00000;
      if ( v36 > 0x74400000 )
      {
        if ( v36 == 1951399936 || v36 == 1952448512 || v36 == 1953497088 )
        {
LABEL_109:
          v37 = sub_6C1E05(this);
          goto LABEL_110;
        }
      }
      else
      {
        if ( v36 == 1950351360 )
          goto LABEL_109;
        if ( v36 == 1934622720 || v36 == 1935671296 || v36 == 1936719872 || v36 == 1937768448 )
        {
          v37 = sub_6C078E(this);
LABEL_110:
          v2 = v37;
          if ( v37 < 0 )
            return v2;
          v33 = mm;
        }
      }
    }
    v38 = 0;
    for ( nn = 0; v38 < *(_DWORD *)(this + 12); nn = v38 )
    {
      v39 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v38;
      v40 = *(_DWORD **)(v39 + 4 * v38);
      *(_DWORD *)(this + 256) = v40;
      if ( (*v40 & 0xFFF00000) == 0x73700000 )
      {
        v2 = sub_6C03F7(this);
        if ( v2 < 0 )
          return v2;
        v38 = nn;
      }
      ++v38;
    }
    goto LABEL_118;
  }
  return v2;
}
