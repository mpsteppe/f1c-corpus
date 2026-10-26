int __thiscall sub_6B321C(int this)
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
    result = sub_6B31BE((_DWORD *)this);
    if ( result < 0 )
      return result;
    v9 = **(_DWORD **)(this + 256) & 0xFFF00000;
    if ( v9 > 0x70600000 )
    {
      if ( v9 > 0x73A00000 )
      {
        if ( v9 > 0x74200000 )
        {
          switch ( v9 )
          {
            case 0x74400000u:
            case 0x74500000u:
            case 0x74600000u:
            case 0x74700000u:
              if ( (*(_BYTE *)(this + 112) & 4) != 0 )
                v10 = sub_6CB728(this);
              else
                v10 = -2147467263;
              break;
            case 0x74A00000u:
              v10 = sub_6CB6FE(this);
              break;
            case 0x74B00000u:
              v10 = sub_6CB6D4(this);
              break;
            default:
              goto LABEL_118;
          }
          goto LABEL_114;
        }
        switch ( v9 )
        {
          case 0x74200000u:
            v10 = sub_6CCD65(this);
            break;
          case 0x73B00000u:
          case 0x73C00000u:
            goto LABEL_88;
          case 0x73D00000u:
          case 0x73E00000u:
          case 0x73F00000u:
          case 0x74000000u:
LABEL_101:
            v10 = sub_6CC409(this);
            break;
          case 0x74100000u:
            v10 = sub_6CCDCF(this);
            break;
          default:
            goto LABEL_118;
        }
      }
      else
      {
        if ( v9 == 1939865600 )
          goto LABEL_88;
        if ( v9 > 0x73300000 )
        {
          if ( v9 != 1933574144 )
          {
            if ( v9 != 1934622720 && v9 != 1935671296 && v9 != 1936719872 && v9 != 1937768448 )
            {
              if ( v9 != 1938817024 )
                goto LABEL_118;
LABEL_88:
              v10 = sub_6CC234(this);
              goto LABEL_114;
            }
LABEL_89:
            v10 = sub_6CBE5C(this);
            goto LABEL_114;
          }
          v10 = sub_6CC433(this);
        }
        else
        {
          switch ( v9 )
          {
            case 0x73300000u:
              goto LABEL_101;
            case 0x70700000u:
              goto LABEL_61;
            case 0x70900000u:
              v10 = sub_6CD05E(this);
              goto LABEL_114;
            case 0x70D00000u:
              v10 = sub_6CC56A(this);
              goto LABEL_114;
            case 0x71000000u:
              v10 = sub_6B1E0E((_DWORD *)this);
              goto LABEL_114;
            case 0x73000000u:
              v10 = sub_6CC38F(0);
              goto LABEL_114;
            case 0x73100000u:
              goto LABEL_101;
          }
          if ( v9 != 1931476992 )
            goto LABEL_118;
          v10 = sub_6CC38F(1);
        }
      }
    }
    else
    {
      if ( v9 == 1885339648 )
        goto LABEL_61;
      if ( v9 > 0x20300000 )
      {
        if ( v9 > 0x50300000 )
        {
          switch ( v9 )
          {
            case 0x70000000u:
              v10 = sub_6CD139(this);
              break;
            case 0x70100000u:
              v10 = sub_6CC5DC(this);
              break;
            case 0x70200000u:
              v10 = sub_6CC6F7(this);
              break;
            case 0x70300000u:
            case 0x70400000u:
              v10 = sub_6CC79D(this);
              break;
            case 0x70500000u:
LABEL_61:
              v10 = sub_6CC8DB(this);
              break;
            default:
              goto LABEL_118;
          }
        }
        else
        {
          switch ( v9 )
          {
            case 0x50300000u:
              v10 = sub_6CBDBE(this);
              break;
            case 0x20400000u:
              v10 = sub_6CD04A(this);
              break;
            case 0x20500000u:
              v10 = sub_6CD054(this);
              break;
            case 0x20700000u:
              v10 = sub_6CC065(this);
              break;
            case 0x20800000u:
              continue;
            case 0x20900000u:
              goto LABEL_38;
            case 0x50000000u:
              v10 = sub_6CD068(this);
              break;
            case 0x50100000u:
              v10 = sub_6CD11B(this);
              break;
            default:
              goto LABEL_118;
          }
        }
      }
      else
      {
        if ( v9 == 540016640 )
        {
          v10 = sub_6CD040(this);
          goto LABEL_114;
        }
        if ( v9 > 0x10700000 )
        {
          switch ( v9 )
          {
            case 0x10F00000u:
              goto LABEL_89;
            case 0x11200000u:
              goto LABEL_38;
            case 0x11300000u:
              continue;
            case 0x11500000u:
              goto LABEL_38;
            case 0x20000000u:
              v10 = sub_6CD022(this);
              break;
            case 0x20100000u:
              v10 = sub_6CD02C(this);
              break;
            case 0x20200000u:
              v10 = sub_6CD036(this);
              break;
            default:
              goto LABEL_118;
          }
        }
        else
        {
          switch ( v9 )
          {
            case 0x10700000u:
              v10 = sub_6CD004(this);
              break;
            case 0u:
              v10 = sub_6AB05A();
              break;
            case 0x10000000u:
LABEL_38:
              v10 = sub_6CCE53(this);
              break;
            case 0x10100000u:
              v10 = sub_6CC45D(this);
              break;
            case 0x10300000u:
              v10 = sub_6CCFA0(this);
              break;
            case 0x10400000u:
              v10 = sub_6CCFBE(this);
              break;
            case 0x10500000u:
              v10 = sub_6B20D4((_DWORD *)this);
              break;
            case 0x10600000u:
              v10 = sub_6B230B((_DWORD *)this);
              break;
            default:
              goto LABEL_118;
          }
        }
      }
    }
LABEL_114:
    if ( v10 == dword_16C9AA8 )
    {
LABEL_118:
      sub_686791(
        this,
        *(_DWORD *)(*(_DWORD *)(this + 256) + 60),
        4532,
        "cannot map expression to vertex shader instruction set");
      return -2147467263;
    }
  }
  return 0;
}
