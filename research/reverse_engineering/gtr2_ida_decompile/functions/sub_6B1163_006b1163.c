int __thiscall sub_6B1163(int this)
{
  int v2; // edi
  int v3; // eax
  int *v4; // ecx
  unsigned int v5; // eax
  int result; // eax
  int v7; // edi
  int v8; // eax
  _DWORD *v9; // eax
  unsigned int v10; // eax
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // eax
  unsigned int v14; // eax
  unsigned int j; // edi
  int v16; // eax
  _DWORD *v17; // eax
  unsigned int v18; // eax
  int v19; // edi
  int v20; // eax
  _DWORD *v21; // eax
  int v22; // edi
  int v23; // eax
  _DWORD *v24; // eax
  unsigned int v25; // eax
  unsigned int i; // edi
  int v27; // eax
  _DWORD *v28; // eax
  unsigned int v29; // eax
  int v30; // edi
  int v31; // eax
  _DWORD *v32; // eax
  int v33; // edi
  int v34; // eax
  _DWORD *v35; // eax
  int v36; // edi
  int v37; // eax
  _DWORD *v38; // eax
  int v39; // edi
  int v40; // eax
  _DWORD *v41; // eax
  unsigned int v42; // eax
  int v43; // edi
  int v44; // eax
  _DWORD *v45; // eax

  v2 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    while ( 1 )
    {
      v3 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v2;
      v4 = *(int **)(v3 + 4 * v2);
      *(_DWORD *)(this + 256) = v4;
      v5 = *v4 & 0xFFF00000;
      if ( v5 == 272629760 )
        break;
      if ( v5 == 289406976 )
      {
        result = sub_6C09A6(this);
        goto LABEL_8;
      }
LABEL_9:
      if ( (unsigned int)++v2 >= *(_DWORD *)(this + 12) )
        goto LABEL_10;
    }
    if ( (*(_BYTE *)(this + 113) & 0x20) != 0 )
      *v4 = v4[3] & 0xFFFFF | 0x71000000;
    result = 0;
LABEL_8:
    if ( result < 0 )
      return result;
    goto LABEL_9;
  }
LABEL_10:
  if ( (*(_BYTE *)(this + 204) & 4) != 0 )
  {
LABEL_66:
    sub_6BC1A9(this);
    v22 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v23 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v22;
        v24 = *(_DWORD **)(v23 + 4 * v22);
        *(_DWORD *)(this + 256) = v24;
        v25 = *v24 & 0xFFF00000;
        if ( v25 == 1952448512 || v25 == 1953497088 )
        {
          result = sub_6C1B55(this);
          if ( result < 0 )
            return result;
          result = sub_6C1CA3(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v22 < *(_DWORD *)(this + 12) );
    }
    for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
    {
      v27 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = i;
      v28 = *(_DWORD **)(v27 + 4 * i);
      *(_DWORD *)(this + 256) = v28;
      v29 = *v28 & 0xFFF00000;
      if ( v29 == 1950351360 || v29 == 1951399936 || v29 == 1952448512 || v29 == 1953497088 )
        sub_6C1E05(this);
    }
    v30 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v31 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v30;
        v32 = *(_DWORD **)(v31 + 4 * v30);
        *(_DWORD *)(this + 256) = v32;
        if ( (*v32 & 0xFFF00000) == 0x20900000 )
        {
          result = sub_6C1337(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v30 < *(_DWORD *)(this + 12) );
    }
    v33 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v34 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v33;
        v35 = *(_DWORD **)(v34 + 4 * v33);
        *(_DWORD *)(this + 256) = v35;
        if ( (*v35 & 0xFFF00000) == 0x11400000 )
        {
          result = sub_6BC4F5(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v33 < *(_DWORD *)(this + 12) );
    }
    v36 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v37 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v36;
        v38 = *(_DWORD **)(v37 + 4 * v36);
        *(_DWORD *)(this + 256) = v38;
        if ( (*v38 & 0xFFF00000) == 0x70300000 )
        {
          result = (unsigned __int16)*(_DWORD *)(this + 200) < 0x200u ? 1 : sub_6C3319(this, 0);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v36 < *(_DWORD *)(this + 12) );
    }
    sub_6BC1A9(this);
    v39 = 0;
    if ( !*(_DWORD *)(this + 12) )
    {
LABEL_107:
      sub_6BC1A9(this);
      v43 = 0;
      if ( *(_DWORD *)(this + 12) )
      {
        while ( 1 )
        {
          v44 = *(_DWORD *)(this + 24);
          *(_DWORD *)(this + 252) = v43;
          v45 = *(_DWORD **)(v44 + 4 * v43);
          *(_DWORD *)(this + 256) = v45;
          if ( (*v45 & 0xFFF00000) == 0x50300000 )
          {
            result = sub_6BC856(this);
            if ( result < 0 )
              break;
          }
          if ( (unsigned int)++v43 >= *(_DWORD *)(this + 12) )
            goto LABEL_111;
        }
      }
      else
      {
LABEL_111:
        result = sub_6875A0((_DWORD *)this);
        if ( result >= 0 )
        {
          result = sub_68FECA((_DWORD *)this);
          if ( result >= 0 )
          {
            result = sub_6825A9((_DWORD *)this);
            if ( result >= 0 )
            {
              result = sub_688BDF((_DWORD *)this);
              if ( result >= 0 )
              {
                sub_6BC1A9(this);
                return 0;
              }
            }
          }
        }
      }
      return result;
    }
    while ( 1 )
    {
      v40 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v39;
      v41 = *(_DWORD **)(v40 + 4 * v39);
      *(_DWORD *)(this + 256) = v41;
      v42 = *v41 & 0xFFF00000;
      if ( v42 == 271581184 || v42 == 273678336 || v42 == 274726912 || v42 == 275775488 || v42 == 1342177280 )
        break;
      if ( v42 == 1882193920 )
      {
        if ( (unsigned __int16)*(_DWORD *)(this + 200) < 0x200u )
          result = 1;
        else
          result = sub_6C8EAA(this);
LABEL_105:
        if ( result < 0 )
          return result;
      }
      if ( (unsigned int)++v39 >= *(_DWORD *)(this + 12) )
        goto LABEL_107;
    }
    result = sub_6BFAB9(this);
    goto LABEL_105;
  }
  v7 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = v7;
      v9 = *(_DWORD **)(v8 + 4 * v7);
      *(_DWORD *)(this + 256) = v9;
      v10 = *v9 & 0xFFF00000;
      if ( v10 == 269484032 )
      {
        result = sub_6C7940(1);
        goto LABEL_27;
      }
      if ( v10 == 273678336 )
        break;
      switch ( v10 )
      {
        case 0x10F00000u:
          result = sub_6BFDA7(this);
          goto LABEL_27;
        case 0x11400000u:
          result = sub_6C09A6(this);
          goto LABEL_27;
        case 0x20100000u:
          if ( (unsigned __int16)*(_DWORD *)(this + 200) >= 0x200u )
          {
            result = sub_6C2BAB(this);
            goto LABEL_27;
          }
LABEL_21:
          result = 1;
          goto LABEL_27;
        case 0x20400000u:
          result = sub_6C79FA(1);
          goto LABEL_27;
      }
LABEL_28:
      if ( (unsigned int)++v7 >= *(_DWORD *)(this + 12) )
        goto LABEL_29;
    }
    if ( (unsigned __int16)*(_DWORD *)(this + 200) < 0x200u )
      goto LABEL_21;
    result = sub_6BCE19(this);
LABEL_27:
    if ( result < 0 )
      return result;
    goto LABEL_28;
  }
LABEL_29:
  result = sub_6875A0((_DWORD *)this);
  if ( result >= 0 )
  {
    sub_6BC1A9(this);
    v11 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v12 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v11;
        v13 = *(_DWORD **)(v12 + 4 * v11);
        *(_DWORD *)(this + 256) = v13;
        v14 = *v13 & 0xFFF00000;
        if ( v14 == 542113792 )
          break;
        switch ( v14 )
        {
          case 0x70300000u:
            if ( (unsigned __int16)*(_DWORD *)(this + 200) >= 0x200u )
            {
              result = sub_6C3319(this, 1);
              goto LABEL_46;
            }
LABEL_45:
            result = 1;
            goto LABEL_46;
          case 0x73500000u:
          case 0x73600000u:
            result = sub_6C04DE(this);
            if ( result < 0 )
              return result;
            result = sub_6C062C(this);
LABEL_46:
            if ( result < 0 )
              return result;
            break;
          case 0x74600000u:
          case 0x74700000u:
            result = sub_6C1B55(this);
            if ( result < 0 )
              return result;
            result = sub_6C1CA3(this);
            goto LABEL_46;
        }
        if ( (unsigned int)++v11 >= *(_DWORD *)(this + 12) )
          goto LABEL_48;
      }
      if ( (unsigned __int16)*(_DWORD *)(this + 200) >= 0x200u )
      {
        result = sub_6C201D(this);
        goto LABEL_46;
      }
      goto LABEL_45;
    }
LABEL_48:
    for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
    {
      v16 = *(_DWORD *)(this + 24);
      *(_DWORD *)(this + 252) = j;
      v17 = *(_DWORD **)(v16 + 4 * j);
      *(_DWORD *)(this + 256) = v17;
      v18 = *v17 & 0xFFF00000;
      if ( v18 > 0x74400000 )
      {
        if ( v18 == 1951399936 || v18 == 1952448512 || v18 == 1953497088 )
        {
LABEL_59:
          result = sub_6C1E05(this);
LABEL_60:
          if ( result < 0 )
            return result;
        }
      }
      else
      {
        if ( v18 == 1950351360 )
          goto LABEL_59;
        if ( v18 == 1934622720 || v18 == 1935671296 || v18 == 1936719872 || v18 == 1937768448 )
        {
          result = sub_6C078E(this);
          goto LABEL_60;
        }
      }
    }
    v19 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v20 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v19;
        v21 = *(_DWORD **)(v20 + 4 * v19);
        *(_DWORD *)(this + 256) = v21;
        if ( (*v21 & 0xFFF00000) == 0x73700000 )
        {
          result = sub_6C03F7(this);
          if ( result < 0 )
            return result;
        }
        if ( (unsigned int)++v19 >= *(_DWORD *)(this + 12) )
          goto LABEL_66;
      }
    }
    goto LABEL_66;
  }
  return result;
}
