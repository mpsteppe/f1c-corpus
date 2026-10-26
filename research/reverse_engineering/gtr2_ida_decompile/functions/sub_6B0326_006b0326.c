int __thiscall sub_6B0326(int this)
{
  unsigned int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int *v6; // eax
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned int v10; // esi
  int v11; // edi
  int v12; // eax
  int v13; // ecx
  bool v14; // zf
  _DWORD *v15; // eax
  char *v16; // esi
  _DWORD *v17; // eax
  char *v18; // esi
  int v19; // eax
  char *v20; // ecx
  unsigned int i; // eax
  int v22; // eax
  int v23; // ecx
  const void *v24; // esi
  unsigned int v25; // eax
  void *v26; // ecx
  _DWORD *v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // edi
  unsigned int v31; // eax
  int *v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  unsigned int v36; // eax
  _DWORD *v38; // [esp+1Ch] [ebp-44h]
  _DWORD v39[4]; // [esp+2Ch] [ebp-34h] BYREF
  _DWORD v40[4]; // [esp+3Ch] [ebp-24h] BYREF
  unsigned int v41; // [esp+4Ch] [ebp-14h]
  unsigned int v42; // [esp+50h] [ebp-10h]
  int v43; // [esp+54h] [ebp-Ch]
  unsigned int v44; // [esp+58h] [ebp-8h]
  char *v45; // [esp+5Ch] [ebp-4h]

  v2 = 0;
  v41 = *(_DWORD *)(this + 12);
  v45 = 0;
  if ( v41 )
  {
    do
    {
      v3 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v2;
      *(_DWORD *)(this + 256) = *(_DWORD *)(v3 + 4 * v2);
      sub_6BCA61(this);
      ++v2;
    }
    while ( v2 < *(_DWORD *)(this + 12) );
  }
  v4 = 0;
  v42 = 0;
  if ( v41 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v4;
      v6 = *(int **)(v5 + 4 * v4);
      *(_DWORD *)(this + 256) = v6;
      v7 = *v6 & 0xFFF00000;
      if ( v7 == 1615855616
        || v7 == 1626341376
        || v7 == 1621098496
        || v7 == 1612709888
        || v7 == 1617952768
        || v7 == 1623195648
        || v7 == 1628438528
        || v7 == 1613758464
        || v7 == 1619001344
        || v7 == 1624244224
        || v7 == 1629487104
        || v7 == 1610612736
        || v7 == 285212672 )
      {
        break;
      }
      v8 = sub_681C03((void *)this, v6);
LABEL_64:
      if ( v8 < 0 )
        return 0;
      **(_DWORD **)(this + 256) = 0;
      v4 = ++v42;
      if ( v42 >= v41 )
        goto LABEL_66;
    }
    v9 = *v6;
    v10 = v9 & 0xFFFFF;
    v43 = v9 & 0xFFFFF;
    if ( (v9 & 0xFFF00000) == 0x11000000 )
      v43 = 0;
    v44 = 0;
    if ( v10 )
    {
      v11 = 4 * v43;
      do
      {
        v12 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v11 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8)));
        if ( *(_DWORD *)(v12 + 16) != v44 || (*(_BYTE *)(v12 + 62) & 0x1F) != 0 )
          break;
        v13 = *(_DWORD *)(v12 + 4);
        if ( v13 == *(_DWORD *)(this + 128) )
        {
          v38 = *(_DWORD **)(v12 + 108);
          v14 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 84))(this) == 6;
        }
        else
        {
          v14 = v13 == *(_DWORD *)(this + 136);
        }
        if ( !v14 )
          break;
        ++v44;
        v11 += 4;
      }
      while ( v44 < v10 );
    }
    if ( (**(_DWORD **)(this + 256) & 0xFFF00000) == 0x60000000 && v10 == 1 )
    {
      if ( (*(int (__thiscall **)(int, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             this,
             *(_DWORD *)(this + 252),
             v40,
             4,
             0,
             0) < 0 )
        return 0;
      v15 = (_DWORD *)sub_681186(116);
      if ( v15 )
        v16 = (char *)sub_680CEC(v15);
      else
        v16 = 0;
      v45 = v16;
      if ( !v16 )
        return -2147024882;
      if ( sub_6811D1(v16, 268435458, 2, 2, 0) < 0 )
        goto LABEL_177;
      if ( sub_680D22(v16, *(_DWORD *)(this + 256)) < 0 )
        goto LABEL_177;
      **((_DWORD **)v16 + 2) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + 4);
      *(_DWORD *)(*((_DWORD *)v16 + 2) + 4) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + 4);
      **((_DWORD **)v16 + 4) = v40[0];
      *(_DWORD *)(*((_DWORD *)v16 + 4) + 4) = v40[1];
      if ( sub_681997(this, v16) < 0 )
        goto LABEL_177;
      v17 = (_DWORD *)sub_681186(116);
      if ( v17 )
        v18 = (char *)sub_680CEC(v17);
      else
        v18 = 0;
      v44 = (unsigned int)v18;
      if ( !v18 )
        return 0;
      v19 = sub_6811D1(v18, 1615855618, 4, *(_DWORD *)(*(_DWORD *)(this + 256) + 12), 0);
      v20 = v18;
      if ( v19 < 0 )
        goto LABEL_178;
      if ( sub_680D22(v18, *(_DWORD *)(this + 256)) < 0 )
      {
        v20 = v18;
        goto LABEL_178;
      }
      for ( i = 2; i < 4; ++i )
      {
        *(_DWORD *)(i * 4 + *((_DWORD *)v18 + 2) - 8) = **(_DWORD **)(*(_DWORD *)(this + 256) + 8);
        *(_DWORD *)(i * 4 + *((_DWORD *)v18 + 2)) = v39[i + 2];
      }
      v22 = *(_DWORD *)(this + 256);
      v23 = *(_DWORD *)(v22 + 12);
      v24 = *(const void **)(v22 + 16);
      v25 = v44;
      qmemcpy(*(void **)(v44 + 16), v24, 4 * v23);
      v26 = *(void **)(this + 256);
      if ( v26 )
      {
        sub_66238F(v26, 1);
        v25 = v44;
      }
      *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v42) = v25;
      *(_DWORD *)(this + 256) = v25;
    }
    else
    {
      if ( v44 == v10 )
      {
LABEL_63:
        v8 = sub_681C03((void *)this, v38);
        goto LABEL_64;
      }
      if ( (*(int (__thiscall **)(int, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             this,
             *(_DWORD *)(this + 252),
             v39,
             4,
             0,
             0) < 0 )
        return 0;
      v27 = (_DWORD *)sub_681186(116);
      if ( v27 )
        v45 = (char *)sub_680CEC(v27);
      else
        v45 = 0;
      if ( !v45 )
        return -2147024882;
      if ( sub_6811D1(v45, v10 & 0xFFFFF | 0x10000000, v10, v10, 0) < 0 || sub_680D22(v45, *(_DWORD *)(this + 256)) < 0 )
        goto LABEL_177;
      v44 = 0;
      if ( v10 )
      {
        v28 = 4 * v43;
        do
        {
          v29 = *(_DWORD *)(v28 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8));
          v30 = *((_DWORD *)v45 + 2);
          v31 = 4 * v44++;
          *(_DWORD *)(v31 + v30) = v29;
          *(_DWORD *)(v31 + *((_DWORD *)v45 + 4)) = v39[v31 / 4];
          *(_DWORD *)(v28 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8)) = *(_DWORD *)(v31 + *((_DWORD *)v45 + 4));
          v28 += 4;
        }
        while ( v44 < v10 );
      }
      if ( sub_681997(this, v45) < 0 )
        goto LABEL_177;
    }
    v45 = 0;
    goto LABEL_63;
  }
LABEL_66:
  sub_6BC1A9(this);
  v41 = *(_DWORD *)(this + 12);
  if ( !v41 )
    return 0;
  v32 = *(int **)(this + 24);
  *(_DWORD *)(this + 252) = 0;
  v33 = *v32;
  *(_DWORD *)(this + 256) = v33;
  v34 = *(_DWORD *)(v33 + 60);
  if ( v34 && *(_DWORD *)(v34 + 4) == 13 )
    *(_DWORD *)(this + 260) = v34 + 48;
  v35 = *(_DWORD *)(this + 256);
  v36 = *(_DWORD *)v35 & 0xFFF00000;
  if ( v36
    && *(_DWORD *)(v35 + 4)
    && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v35 + 8)) + 8) != -1 )
  {
    sub_686791(
      this,
      *(_DWORD *)(*(_DWORD *)(this + 256) + 60),
      4511,
      "relative addressing not allowed for pixel shaders");
    return 0;
  }
  if ( v36 <= 0x60500000 )
  {
    if ( v36 != 1615855616 )
    {
      if ( v36 <= 0x20100000 )
      {
        if ( v36 != 537919488 )
        {
          if ( v36 <= 0x10600000 )
          {
            switch ( v36 )
            {
              case 0x10600000u:
                sub_6CCFE6(this);
                return off_16C9848();
              case 0u:
                return off_16C9848();
              case 0x10000000u:
                sub_6CCE53(this);
                return off_16C9848();
              case 0x10100000u:
                sub_6CC45D(this);
                return off_16C9848();
              case 0x10300000u:
                sub_6CCFA0(this);
                return off_16C9848();
              case 0x10400000u:
                sub_6CCFBE(this);
                return off_16C9848();
              case 0x10500000u:
                sub_6CCFC8(this);
                return off_16C9848();
            }
            goto LABEL_176;
          }
          switch ( v36 )
          {
            case 0x10700000u:
              sub_6CD004(this);
              return off_16C9848();
            case 0x10D00000u:
              if ( (*(_BYTE *)(this + 112) & 0x10) != 0 )
                sub_6CCF8C(this);
              return off_16C9848();
            case 0x10E00000u:
              if ( (*(_BYTE *)(this + 112) & 0x10) != 0 )
                sub_6CCF96(this);
              return off_16C9848();
          }
          if ( v36 != 284164096 )
          {
            if ( v36 == 285212672 )
            {
              sub_6CBC69(this);
              return off_16C9848();
            }
            if ( v36 == 0x20000000 )
              goto LABEL_99;
            goto LABEL_176;
          }
LABEL_170:
          sub_6CBE5C(this);
          return off_16C9848();
        }
        goto LABEL_172;
      }
      if ( v36 <= 0x50000000 )
      {
        switch ( v36 )
        {
          case 0x50000000u:
            sub_6CD068(this);
            return off_16C9848();
          case 0x20200000u:
            sub_6AE8E4((_DWORD *)this);
            return off_16C9848();
          case 0x20300000u:
            sub_6AE808((_DWORD *)this);
            return off_16C9848();
          case 0x20400000u:
            sub_6CD04A(this);
            return off_16C9848();
          case 0x20500000u:
            sub_6CD054(this);
            return off_16C9848();
          case 0x20700000u:
            sub_6CC065(this);
            return off_16C9848();
          case 0x30000000u:
            sub_6CD125(this);
            return off_16C9848();
        }
        goto LABEL_176;
      }
      if ( v36 == 1345323008 )
      {
        sub_6CBDBE(this);
        return off_16C9848();
      }
      if ( v36 != 1610612736 )
      {
        if ( v36 != 1611661312 )
        {
          if ( v36 != 1612709888 )
          {
            if ( v36 != 1613758464 )
            {
              if ( v36 != 1614807040 )
                goto LABEL_176;
              goto LABEL_128;
            }
LABEL_148:
            sub_6CBB68(this);
            return off_16C9848();
          }
          goto LABEL_149;
        }
        goto LABEL_141;
      }
    }
    goto LABEL_150;
  }
  if ( v36 > 0x61300000 )
  {
    if ( v36 <= 0x70B00000 )
    {
      switch ( v36 )
      {
        case 0x70B00000u:
LABEL_99:
          sub_6AEAF6((_DWORD *)this);
          return off_16C9848();
        case 0x70000000u:
          sub_6CD139(this);
          return off_16C9848();
        case 0x70100000u:
          sub_6CC5DC(this);
          return off_16C9848();
        case 0x70200000u:
          sub_6CC6F7(this);
          return off_16C9848();
        case 0x70300000u:
        case 0x70400000u:
          sub_6CC79D(this);
          return off_16C9848();
        case 0x70800000u:
          sub_6CBC33(this);
          return off_16C9848();
      }
LABEL_176:
      sub_686791(
        this,
        *(_DWORD *)(*(_DWORD *)(this + 256) + 60),
        4532,
        "cannot map expression to pixel shader instruction set");
LABEL_177:
      v20 = v45;
      if ( v45 )
LABEL_178:
        sub_66238F(v20, 1);
      return 0;
    }
    if ( v36 != 1891631104 )
    {
      if ( v36 == 1892679680 )
      {
        sub_6CC56A(this);
        return off_16C9848();
      }
      if ( v36 != 1934622720 && v36 != 1935671296 && v36 != 1936719872 && v36 != 1937768448 )
        goto LABEL_176;
      goto LABEL_170;
    }
LABEL_172:
    sub_6AE9C0((_DWORD *)this);
    return off_16C9848();
  }
  if ( v36 == 1630535680 )
    goto LABEL_128;
  if ( v36 > 0x60C00000 )
  {
    if ( v36 == 1624244224 )
      goto LABEL_148;
    if ( v36 != 1625292800 )
    {
      if ( v36 != 1626341376 )
      {
        if ( v36 != 1627389952 )
        {
          if ( v36 != 1628438528 )
          {
            if ( v36 != 1629487104 )
              goto LABEL_176;
            goto LABEL_148;
          }
LABEL_149:
          sub_6CBB01(this);
          return off_16C9848();
        }
LABEL_141:
        sub_6CB8D2(this);
        return off_16C9848();
      }
LABEL_150:
      sub_6CB86E(this);
      return off_16C9848();
    }
  }
  else
  {
    switch ( v36 )
    {
      case 0x60C00000u:
        goto LABEL_149;
      case 0x60600000u:
        goto LABEL_141;
      case 0x60700000u:
        goto LABEL_149;
      case 0x60800000u:
        goto LABEL_148;
    }
    if ( v36 != 1620049920 )
    {
      if ( v36 != 1621098496 )
      {
        if ( v36 != 1622147072 )
          goto LABEL_176;
        goto LABEL_141;
      }
      goto LABEL_150;
    }
  }
LABEL_128:
  if ( (*(_BYTE *)(this + 112) & 0x20) != 0 )
  {
    sub_6CBBCF(this);
    return off_16C9848();
  }
  sub_686791(this, *(_DWORD *)(*(_DWORD *)(this + 256) + 60), 4532, "texlod not supported on this target");
  return 0;
}
