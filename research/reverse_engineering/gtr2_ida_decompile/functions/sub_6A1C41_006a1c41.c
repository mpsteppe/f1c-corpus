int __thiscall sub_6A1C41(int this)
{
  unsigned int i; // edi
  int v3; // eax
  unsigned int j; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int result; // eax
  unsigned int v9; // eax
  int v10; // eax
  bool v11; // zf
  bool v12; // zf
  int v13; // [esp+0h] [ebp-Ch]

  for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
  {
    v3 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 252) = i;
    *(_DWORD *)(this + 256) = *(_DWORD *)(v3 + 4 * i);
    sub_6BCA61(this);
  }
  for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
  {
    v5 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 252) = j;
    v6 = *(_DWORD *)(v5 + 4 * j);
    *(_DWORD *)(this + 256) = v6;
    v7 = *(_DWORD *)(v6 + 60);
    if ( v7 && *(_DWORD *)(v7 + 4) == 13 )
      *(_DWORD *)(this + 260) = v7 + 48;
    result = sub_6A1459((_DWORD *)this);
    if ( result < 0 )
      return result;
    v9 = **(_DWORD **)(this + 256) & 0xFFF00000;
    if ( v9 > 0x60F00000 )
    {
      if ( v9 > 0x73400000 )
      {
        if ( v9 <= 0x73F00000 )
        {
          if ( v9 == 1945108480 )
            goto LABEL_132;
          if ( v9 > 0x73A00000 )
          {
            if ( v9 != 1940914176 && v9 != 1941962752 )
            {
              if ( v9 != 1943011328 )
              {
                v12 = v9 == 1944059904;
                goto LABEL_131;
              }
LABEL_132:
              v10 = sub_6CC409(this);
              goto LABEL_158;
            }
            goto LABEL_145;
          }
          if ( v9 == 1939865600 )
            goto LABEL_145;
          if ( v9 != 1934622720 && v9 != 1935671296 && v9 != 1936719872 && v9 != 1937768448 )
          {
            if ( v9 != 1938817024 )
              goto LABEL_170;
LABEL_145:
            v10 = sub_6CC234(this);
            goto LABEL_158;
          }
LABEL_146:
          v10 = sub_6CBE5C(this);
          goto LABEL_158;
        }
        if ( v9 > 0x74500000 )
        {
          if ( v9 != 1952448512 && v9 != 1953497088 )
          {
            if ( v9 == 1956642816 )
            {
              v10 = sub_6CB6FE(this);
            }
            else
            {
              if ( v9 != 1957691392 )
              {
LABEL_170:
                if ( (*(_BYTE *)(this + 112) & 0x40) != 0 )
LABEL_171:
                  sub_686791(
                    this,
                    *(_DWORD *)(*(_DWORD *)(this + 256) + 60),
                    4532,
                    "cannot map expression to vertex shader instruction set");
                else
                  sub_686791(
                    this,
                    *(_DWORD *)(*(_DWORD *)(this + 256) + 60),
                    4532,
                    "cannot map expression to pixel shader instruction set");
                return -2147467263;
              }
              v10 = sub_6CB6D4(this);
            }
            goto LABEL_158;
          }
          goto LABEL_157;
        }
        switch ( v9 )
        {
          case 0x74500000u:
            goto LABEL_157;
          case 0x74000000u:
            goto LABEL_132;
          case 0x74100000u:
            v10 = sub_6CCDCF(this);
            break;
          case 0x74200000u:
            v10 = sub_6CCD65(this);
            break;
          case 0x74400000u:
LABEL_157:
            v10 = sub_6CB728(this);
            break;
          default:
            goto LABEL_170;
        }
      }
      else
      {
        if ( v9 == 1933574144 )
        {
          v10 = sub_6CC433(this);
          goto LABEL_158;
        }
        if ( v9 > 0x70600000 )
        {
          if ( v9 > 0x70D00000 )
          {
            switch ( v9 )
            {
              case 0x73000000u:
                v10 = sub_6CC38F(0);
                break;
              case 0x73100000u:
                goto LABEL_132;
              case 0x73200000u:
                v10 = sub_6CC38F(1);
                break;
              default:
                v12 = v9 == 1932525568;
LABEL_131:
                if ( !v12 )
                  goto LABEL_170;
                goto LABEL_132;
            }
          }
          else
          {
            switch ( v9 )
            {
              case 0x70D00000u:
                v10 = sub_6CC56A(this);
                break;
              case 0x70700000u:
                goto LABEL_113;
              case 0x70800000u:
                v10 = sub_6CBC33(this);
                break;
              case 0x70900000u:
                v10 = sub_6CD05E(this);
                break;
              case 0x70B00000u:
                goto LABEL_44;
              case 0x70C00000u:
LABEL_123:
                v10 = sub_6CD02C(this);
                break;
              default:
                goto LABEL_170;
            }
          }
        }
        else
        {
          if ( v9 == 1885339648 )
            goto LABEL_113;
          if ( v9 > 0x70100000 )
          {
            switch ( v9 )
            {
              case 0x70200000u:
                v10 = sub_6CC6F7(this);
                break;
              case 0x70300000u:
              case 0x70400000u:
                v10 = sub_6CC79D(this);
                break;
              case 0x70500000u:
LABEL_113:
                v10 = sub_6CC8DB(this);
                break;
              default:
                goto LABEL_170;
            }
          }
          else
          {
            switch ( v9 )
            {
              case 0x70100000u:
                v10 = sub_6CC5DC(this);
                goto LABEL_158;
              case 0x61000000u:
LABEL_107:
                v10 = sub_6CB8D2(this);
                goto LABEL_158;
              case 0x61100000u:
                goto LABEL_105;
              case 0x61200000u:
                goto LABEL_75;
              case 0x61300000u:
                goto LABEL_89;
            }
            if ( v9 != 1879048192 )
              goto LABEL_170;
            v10 = sub_6CD139(this);
          }
        }
      }
    }
    else
    {
      if ( v9 == 1626341376 )
        goto LABEL_91;
      if ( v9 > 0x20700000 )
      {
        if ( v9 > 0x60400000 )
        {
          if ( v9 > 0x60A00000 )
          {
            if ( v9 == 1622147072 )
              goto LABEL_107;
            if ( v9 != 1623195648 )
            {
              if ( v9 == 1624244224 )
                goto LABEL_75;
              v11 = v9 == 1625292800;
              goto LABEL_88;
            }
          }
          else
          {
            if ( v9 == 1621098496 || v9 == 1615855616 )
            {
LABEL_91:
              if ( (*(_BYTE *)(this + 112) & 0x40) != 0 )
                goto LABEL_171;
              v10 = sub_6CB86E(this);
              goto LABEL_158;
            }
            if ( v9 == 1616904192 )
              goto LABEL_107;
            if ( v9 != 1617952768 )
            {
              if ( v9 == 1619001344 )
                goto LABEL_75;
              v11 = v9 == 1620049920;
LABEL_88:
              if ( !v11 )
                goto LABEL_170;
LABEL_89:
              if ( (*(_BYTE *)(this + 112) & 0x20) == 0 )
                goto LABEL_170;
              v10 = sub_6CBBCF(this);
              goto LABEL_158;
            }
          }
          goto LABEL_105;
        }
        if ( v9 == 1614807040 )
          goto LABEL_89;
        if ( v9 > 0x50300000 )
        {
          if ( v9 == 1610612736 )
            goto LABEL_91;
          if ( v9 == 1611661312 )
            goto LABEL_107;
          if ( v9 != 1612709888 )
          {
            if ( v9 != 1613758464 )
              goto LABEL_170;
LABEL_75:
            if ( (*(_BYTE *)(this + 112) & 0x40) != 0 )
              goto LABEL_171;
            v10 = sub_6CBB68(this);
            goto LABEL_158;
          }
LABEL_105:
          if ( (*(_BYTE *)(this + 112) & 0x40) != 0 )
            goto LABEL_171;
          v10 = sub_6CBB01(this);
          goto LABEL_158;
        }
        switch ( v9 )
        {
          case 0x50300000u:
            v10 = sub_6CBDBE(this);
            break;
          case 0x20800000u:
            continue;
          case 0x20900000u:
            goto LABEL_45;
          case 0x30000000u:
            if ( (*(_BYTE *)(this + 112) & 0x40) != 0 )
              goto LABEL_171;
            v10 = sub_6CD125(this);
            break;
          case 0x50000000u:
            v10 = sub_6CD068(this);
            break;
          case 0x50100000u:
            v10 = sub_6CD11B(this);
            break;
          default:
            goto LABEL_170;
        }
      }
      else
      {
        if ( v9 == 544210944 )
        {
          v10 = sub_6CC065(this);
          goto LABEL_158;
        }
        if ( v9 > 0x10F00000 )
        {
          if ( v9 > 0x20100000 )
          {
            switch ( v9 )
            {
              case 0x20200000u:
                v10 = sub_6CD036(this);
                break;
              case 0x20300000u:
                v10 = sub_6CD040(this);
                break;
              case 0x20400000u:
                v10 = sub_6CD04A(this);
                break;
              case 0x20500000u:
                v10 = sub_6CD054(this);
                break;
              default:
                goto LABEL_170;
            }
          }
          else
          {
            if ( v9 == 537919488 )
              goto LABEL_123;
            if ( v9 != 285212672 )
            {
              if ( v9 != 287309824 )
              {
                if ( v9 == 288358400 )
                  continue;
                if ( v9 != 290455552 )
                {
                  if ( v9 != 0x20000000 )
                    goto LABEL_170;
LABEL_44:
                  v10 = sub_6CD022(this);
                  goto LABEL_158;
                }
              }
LABEL_45:
              v10 = sub_6CCE53(this);
              goto LABEL_158;
            }
            if ( (*(_BYTE *)(this + 112) & 0x40) != 0 )
              goto LABEL_171;
            v10 = sub_6CBC69(this);
          }
        }
        else
        {
          if ( v9 == 284164096 )
            goto LABEL_146;
          if ( v9 > 0x10500000 )
          {
            switch ( v9 )
            {
              case 0x10600000u:
                v10 = sub_6CCFE6(this);
                break;
              case 0x10700000u:
                v10 = sub_6CD004(this);
                break;
              case 0x10D00000u:
                if ( (*(_BYTE *)(this + 112) & 0x10) == 0 )
                  goto LABEL_32;
                v10 = sub_6CCF8C(this);
                break;
              case 0x10E00000u:
                if ( (*(_BYTE *)(this + 112) & 0x10) != 0 )
                {
                  v10 = sub_6CCF96(this);
                  break;
                }
LABEL_32:
                v10 = -2147467263;
                break;
              default:
                goto LABEL_170;
            }
          }
          else
          {
            switch ( v9 )
            {
              case 0x10500000u:
                v10 = sub_6CCFC8(this);
                break;
              case 0u:
                v10 = sub_6AB05A(v13);
                break;
              case 0x10000000u:
                goto LABEL_45;
              case 0x10100000u:
                v10 = sub_6CC45D(this);
                break;
              case 0x10300000u:
                v10 = sub_6CCFA0(this);
                break;
              case 0x10400000u:
                v10 = sub_6CCFBE(this);
                break;
              default:
                goto LABEL_170;
            }
          }
        }
      }
    }
LABEL_158:
    if ( v10 == -2147467263 )
      goto LABEL_170;
  }
  return 0;
}
