int __thiscall sub_6811D1(char *this, int a2, int a3, int a4, int a5)
{
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // edx
  bool v11; // zf
  unsigned int v12; // edx
  int v13; // edx
  int v14; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp-4h] [ebp-10h]

  v6 = a3;
  v7 = a4;
  v8 = a2 & 0xFFFFF;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 3) = a4;
  if ( a5 )
    goto LABEL_60;
  v9 = a2 & 0xF0000000;
  if ( (a2 & 0xF0000000) != 0 )
  {
    if ( v9 != 0x10000000 )
    {
      switch ( v9 )
      {
        case 0x20000000u:
          v6 = 2 * v8;
          goto LABEL_43;
        case 0x30000000u:
          v6 = 3 * v8;
          goto LABEL_43;
        case 0x40000000u:
          v6 = 4 * v8;
          goto LABEL_43;
      }
      if ( v9 != 1342177280 )
      {
        if ( v9 != 1610612736 )
          goto LABEL_51;
        v10 = a2 & 0xFFF00000;
        if ( (a2 & 0xFFF00000) <= 0x60A00000 )
        {
          if ( v10 != 1621098496 )
          {
            if ( v10 <= 0x60500000 )
            {
              if ( v10 == 1615855616 || v10 == 1610612736 )
              {
                v7 = 4;
                v6 = 4;
                goto LABEL_51;
              }
              if ( v10 == 1611661312 || v10 == 1612709888 || v10 == 1613758464 )
                goto LABEL_19;
              v11 = v10 == 1614807040;
              goto LABEL_18;
            }
            if ( v10 != 1616904192 && v10 != 1617952768 && v10 != 1619001344 )
            {
              v11 = v10 == 1620049920;
              goto LABEL_18;
            }
LABEL_19:
            v18 = 8;
LABEL_37:
            v6 = v18;
            v7 = 4;
            goto LABEL_51;
          }
LABEL_25:
          v18 = 6;
          goto LABEL_37;
        }
        if ( v10 > 0x60F00000 )
        {
          if ( v10 != 1627389952 )
          {
            if ( v10 == 1628438528 || v10 == 1629487104 )
              goto LABEL_19;
            v11 = v10 == 1630535680;
            goto LABEL_18;
          }
        }
        else
        {
          if ( v10 == 1626341376 )
            goto LABEL_25;
          if ( v10 != 1622147072 )
          {
            if ( v10 == 1623195648 || v10 == 1624244224 )
              goto LABEL_19;
            v11 = v10 == 1625292800;
LABEL_18:
            if ( !v11 )
              goto LABEL_51;
            goto LABEL_19;
          }
        }
        v18 = 12;
        goto LABEL_37;
      }
      v12 = a2 & 0xFFF00000;
      if ( (a2 & 0xFFF00000) == 0x50000000 )
      {
        v6 = 2 * v8;
        if ( a4 != -1 )
          goto LABEL_51;
        goto LABEL_46;
      }
      if ( v12 != 1343225856 )
      {
        if ( v12 != 1344274432 )
        {
          if ( v12 != 1345323008 )
            goto LABEL_51;
          goto LABEL_42;
        }
        v6 = a2 & 0xFFFFF;
LABEL_46:
        v7 = 1;
        goto LABEL_51;
      }
    }
LABEL_42:
    v6 = a2 & 0xFFFFF;
LABEL_43:
    v7 = a2 & 0xFFFFF;
    goto LABEL_51;
  }
  v6 = 0;
  v7 = 0;
LABEL_51:
  if ( *((_DWORD *)this + 1) == -1 )
    *((_DWORD *)this + 1) = v6;
  if ( *((_DWORD *)this + 3) == -1 )
    *((_DWORD *)this + 3) = v7;
  v13 = *((_DWORD *)this + 1);
  if ( v13 != v6 )
    return -2147467259;
  v14 = *((_DWORD *)this + 3);
  if ( v14 != v7 || v13 == -1 || v14 == -1 )
    return -2147467259;
LABEL_60:
  if ( *((_DWORD *)this + 1) > 8u )
  {
    v16 = sub_681169(*((_DWORD *)this + 1));
    *((_DWORD *)this + 2) = v16;
    if ( !v16 )
      return -2147024882;
  }
  else
  {
    *((_DWORD *)this + 2) = this + 64;
  }
  if ( *((_DWORD *)this + 3) <= 4u )
  {
    *((_DWORD *)this + 4) = this + 96;
LABEL_65:
    memset(*((void **)this + 2), 0xFFu, 4 * *((_DWORD *)this + 1));
    memset(*((void **)this + 4), 0xFFu, 4 * *((_DWORD *)this + 3));
    *((_DWORD *)this + 9) = 0;
    *((_DWORD *)this + 10) = 0;
    *((_DWORD *)this + 11) = 0;
    *((_DWORD *)this + 14) = 0;
    *((_DWORD *)this + 15) = 0;
    return 0;
  }
  v17 = sub_681169(*((_DWORD *)this + 3));
  *((_DWORD *)this + 4) = v17;
  if ( v17 )
    goto LABEL_65;
  return -2147024882;
}
