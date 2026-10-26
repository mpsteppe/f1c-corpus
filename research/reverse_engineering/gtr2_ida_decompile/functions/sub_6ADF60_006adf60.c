int __thiscall sub_6ADF60(int this)
{
  unsigned int v2; // edi
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // ebx
  int v6; // eax
  _DWORD *v7; // eax
  unsigned int v8; // eax
  int v9; // edi
  unsigned int i; // ebx
  int v11; // eax
  _DWORD *v12; // eax
  int v13; // ebx
  int v14; // eax
  _DWORD *v15; // eax
  unsigned int v16; // eax
  int v17; // ebx
  int v18; // eax
  _DWORD *v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  _DWORD *v24; // eax
  unsigned int v25; // eax
  int v26; // eax
  unsigned int j; // edi
  int v28; // eax
  _DWORD *v29; // eax
  int v30; // ebx
  int v31; // eax
  _DWORD *v32; // eax
  unsigned int v33; // eax
  int v34; // eax
  int v35; // ebx
  int v36; // eax
  _DWORD *v37; // eax
  int v39; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( (*(_BYTE *)(this + 204) & 4) != 0 )
  {
    sub_686606((_DWORD *)this);
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v3 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v2;
        v4 = *(_DWORD **)(v3 + 4 * v2);
        *(_DWORD *)(this + 256) = v4;
        if ( (*v4 & 0xFFF00000) == 0x10000000 )
          sub_6BD2A2(this);
        ++v2;
      }
      while ( v2 < *(_DWORD *)(this + 12) );
    }
    sub_68661F((_DWORD *)this);
    if ( (*(_BYTE *)(this + 204) & 4) != 0 )
      goto LABEL_72;
  }
  v5 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v5;
      v7 = *(_DWORD **)(v6 + 4 * v5);
      *(_DWORD *)(this + 256) = v7;
      v8 = *v7 & 0xFFF00000;
      if ( v8 == 269484032 )
        break;
      if ( v8 == 0x20000000 || v8 == 537919488 || v8 == 805306368 )
      {
        v9 = sub_6BDC80(this);
        sub_6BC1A9(this);
        goto LABEL_15;
      }
      v9 = 1;
LABEL_16:
      if ( (unsigned int)++v5 >= *(_DWORD *)(this + 12) )
        goto LABEL_19;
    }
    v9 = sub_6C7940(1);
LABEL_15:
    if ( v9 < 0 )
      return v9;
    goto LABEL_16;
  }
  v9 = v39;
LABEL_19:
  for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
  {
    v11 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 252) = i;
    v12 = *(_DWORD **)(v11 + 4 * i);
    *(_DWORD *)(this + 256) = v12;
    if ( (*v12 & 0xFFF00000) == 0x30000000 )
    {
      if ( v9 < 0 )
        return v9;
      v9 = sub_6BD325(0, 0, 0);
      if ( v9 < 0 )
        return v9;
      v9 = sub_6BD921(0, 0, 0);
      if ( v9 < 0 )
        return v9;
    }
    else
    {
      v9 = 1;
    }
  }
  v9 = sub_6875A0((_DWORD *)this);
  if ( v9 >= 0 )
  {
    sub_6BC1A9(this);
    v13 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v14 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v13;
        v15 = *(_DWORD **)(v14 + 4 * v13);
        *(_DWORD *)(this + 256) = v15;
        v16 = *v15 & 0xFFF00000;
        if ( v16 == 0x20000000 || v16 == 1890582528 )
        {
          v9 = sub_6BDC80(this);
          sub_6BC1A9(this);
          if ( v9 < 0 )
            return v9;
        }
      }
      while ( (unsigned int)++v13 < *(_DWORD *)(this + 12) );
    }
    v17 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v18 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v17;
        v19 = *(_DWORD **)(v18 + 4 * v17);
        *(_DWORD *)(this + 256) = v19;
        v20 = *v19 & 0xFFF00000;
        if ( v20 == 273678336 )
          break;
        if ( v20 == 284164096 )
        {
          v21 = sub_6C019D(this);
          goto LABEL_43;
        }
        if ( v20 == 541065216 )
        {
          if ( sub_6C2620(this) )
          {
            v21 = sub_6C79FA(1);
            goto LABEL_43;
          }
        }
        else if ( v20 == 805306368 && sub_6C2C9E(this) )
        {
          v21 = sub_6C2D70(this);
          goto LABEL_43;
        }
LABEL_44:
        if ( (unsigned int)++v17 >= *(_DWORD *)(this + 12) )
          goto LABEL_45;
      }
      v21 = sub_6BCE19(this);
LABEL_43:
      v9 = v21;
      if ( v21 < 0 )
        return v9;
      goto LABEL_44;
    }
LABEL_45:
    v9 = sub_6875A0((_DWORD *)this);
    if ( v9 < 0 )
      return v9;
    sub_6BC1A9(this);
    v22 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v23 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v22;
        v24 = *(_DWORD **)(v23 + 4 * v22);
        *(_DWORD *)(this + 256) = v24;
        v25 = *v24 & 0xFFF00000;
        if ( v25 == 542113792 )
          break;
        switch ( v25 )
        {
          case 0x50000000u:
            v26 = sub_6C28E0(this);
            goto LABEL_56;
          case 0x70300000u:
            v26 = sub_6C3319(this, 0);
            goto LABEL_56;
          case 0x73500000u:
          case 0x73600000u:
            v26 = sub_6C04DE(this);
            goto LABEL_56;
        }
LABEL_57:
        if ( (unsigned int)++v22 >= *(_DWORD *)(this + 12) )
          goto LABEL_58;
      }
      v26 = sub_6C201D(this);
LABEL_56:
      v9 = v26;
      if ( v26 < 0 )
        return v9;
      goto LABEL_57;
    }
LABEL_58:
    sub_6BC1A9(this);
    for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
    {
      v28 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = j;
      v29 = *(_DWORD **)(v28 + 4 * j);
      *(_DWORD *)(this + 256) = v29;
      if ( (*v29 & 0xFFF00000) == 0x70300000 )
        sub_6C8EAA(this);
    }
    sub_6BC1A9(this);
    v30 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v31 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v30;
        v32 = *(_DWORD **)(v31 + 4 * v30);
        *(_DWORD *)(this + 256) = v32;
        v33 = *v32 & 0xFFF00000;
        if ( v33 == 1882193920 )
          break;
        if ( v33 == 1934622720 || v33 == 1935671296 || v33 == 1936719872 || v33 == 1937768448 )
        {
          v34 = sub_6C078E(this);
          goto LABEL_70;
        }
LABEL_71:
        if ( (unsigned int)++v30 >= *(_DWORD *)(this + 12) )
          goto LABEL_72;
      }
      v34 = sub_6C3319(this, 0);
LABEL_70:
      v9 = v34;
      if ( v34 < 0 )
        return v9;
      goto LABEL_71;
    }
LABEL_72:
    v35 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v36 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v35;
        v37 = *(_DWORD **)(v36 + 4 * v35);
        *(_DWORD *)(this + 256) = v37;
        if ( (*v37 & 0xFFF00000) == 0x50300000 )
        {
          v9 = sub_6BC856(this);
          if ( v9 < 0 )
            break;
        }
        if ( (unsigned int)++v35 >= *(_DWORD *)(this + 12) )
          goto LABEL_76;
      }
    }
    else
    {
LABEL_76:
      v9 = sub_6875A0((_DWORD *)this);
      if ( v9 >= 0 )
      {
        v9 = sub_68FECA((_DWORD *)this);
        if ( v9 >= 0 )
        {
          v9 = sub_6825A9((_DWORD *)this);
          if ( v9 >= 0 )
          {
            v9 = sub_688BDF((_DWORD *)this);
            if ( v9 >= 0 )
            {
              sub_6BC1A9(this);
              return 0;
            }
          }
        }
      }
    }
  }
  return v9;
}
