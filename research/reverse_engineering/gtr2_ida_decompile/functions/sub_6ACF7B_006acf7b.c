int __thiscall sub_6ACF7B(_DWORD *this, int a2, unsigned int a3)
{
  unsigned int i; // ebx
  int v5; // eax
  int v6; // eax
  int *v7; // edi
  int v8; // ecx
  int v9; // edx
  unsigned int v10; // eax
  int result; // eax
  int v12; // ecx
  int v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // eax
  int v16; // edi
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  bool v21; // zf

  for ( i = 0; i < a3; ++i )
  {
    this[63] = i;
    v5 = *(_DWORD *)(a2 + 4 * i);
    this[64] = v5;
    if ( !v5 )
      continue;
    v6 = *(_DWORD *)(v5 + 60);
    if ( v6 && *(_DWORD *)(v6 + 4) == 13 )
      this[65] = v6 + 48;
    v7 = (int *)this[64];
    v8 = *v7;
    if ( !*v7 )
      continue;
    v9 = this[5];
    if ( *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v7[2]) + 8) != -1 )
    {
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4511, "relative addressing not allowed for pixel shaders");
      return -2147467259;
    }
    v10 = v8 & 0xFFF00000;
    if ( (v8 & 0xFFF00000) > 0x70300000 )
    {
      if ( v10 > 0x72600000 )
      {
        switch ( v10 )
        {
          case 0x72700000u:
            result = sub_6AAAA9(this, 69);
            break;
          case 0x72800000u:
            result = sub_6AAAA9(this, 70);
            break;
          case 0x72900000u:
            result = sub_6AAAA9(this, 77);
            break;
          case 0x72A00000u:
            result = sub_6AAAA9(this, 76);
            break;
          case 0x72B00000u:
            result = sub_6AAAA9(this, 83);
            break;
          case 0x72E00000u:
            result = sub_6AABEE(this);
            break;
          default:
            goto LABEL_90;
        }
        goto LABEL_84;
      }
      if ( v10 == 1918894080 )
      {
        result = sub_6AAAA9(this, 82);
        goto LABEL_84;
      }
      if ( v10 != 1883242496 )
      {
        switch ( v10 )
        {
          case 0x70F00000u:
            result = sub_6CD12F(this);
            break;
          case 0x72100000u:
            result = sub_6AAEEC(this);
            break;
          case 0x72200000u:
            result = sub_6AAAA9(this, 71);
            break;
          case 0x72300000u:
            result = sub_6AAAA9(this, 72);
            break;
          case 0x72400000u:
            result = sub_6AAAA9(this, 73);
            break;
          case 0x72500000u:
            result = sub_6AAAA9(this, 74);
            break;
          default:
            goto LABEL_90;
        }
        goto LABEL_84;
      }
LABEL_70:
      result = sub_6CC79D(this);
      goto LABEL_84;
    }
    if ( (v8 & 0xFFF00000) == 0x70300000 )
      goto LABEL_70;
    if ( v10 > 0x50000000 )
    {
      if ( v10 == 1610612736 || v10 == 1615855616 )
        goto LABEL_54;
      if ( v10 != 1617952768 )
      {
        if ( v10 != 1621098496 && v10 != 1626341376 )
        {
          if ( v10 != 1880096768 )
            goto LABEL_90;
          result = sub_6CC5DC(this);
          goto LABEL_84;
        }
LABEL_54:
        result = sub_6AAD9B(this);
        goto LABEL_84;
      }
      result = sub_6AACC9(this);
    }
    else
    {
      switch ( v10 )
      {
        case 0x50000000u:
          v12 = v8 & 0xFFFFF;
          if ( v12 == 2 )
            goto LABEL_90;
          if ( v12 != 4 || (unsigned __int16)this[50] != 257 )
          {
            v13 = (unsigned __int16)this[50];
            if ( v13 != 258 && v13 != 259 || v12 != 4 )
            {
LABEL_45:
              result = sub_6CD068(this);
              break;
            }
            v14 = *(_DWORD **)(v9 + 4 * *(_DWORD *)v7[4]);
            v15 = (_DWORD *)v7[2];
            v16 = *(_DWORD *)(v9 + 4 * *v15);
            v17 = *(_DWORD *)(v9 + 4 * v15[4]);
            v18 = v14[1];
            if ( v18 == this[33] )
            {
              v19 = this[34];
              v20 = (unsigned __int8)v14[27];
              if ( (*(_DWORD *)(v16 + 4) != v19 || *(_DWORD *)(v16 + 12))
                && (*(_DWORD *)(v17 + 4) != v19 || *(_DWORD *)(v17 + 12)) )
              {
                goto LABEL_45;
              }
              v21 = v20 == 1;
LABEL_43:
              if ( !v21 )
                goto LABEL_45;
            }
            else if ( *(_DWORD *)(v16 + 4) != v18 || *(_DWORD *)(v16 + 12) != v14[3] )
            {
              if ( *(_DWORD *)(v17 + 4) != v18 )
                goto LABEL_45;
              v21 = *(_DWORD *)(v17 + 12) == v14[3];
              goto LABEL_43;
            }
          }
          result = sub_6AA95C(this);
          break;
        case 0u:
          continue;
        case 0x10000000u:
          result = sub_6CCE53(this);
          break;
        case 0x10100000u:
          result = sub_6CC45D(this);
          break;
        case 0x11000000u:
          result = sub_6CBC69((int)this);
          break;
        case 0x20400000u:
          result = sub_6CD04A(this);
          break;
        case 0x20500000u:
          result = sub_6CD054(this);
          break;
        case 0x30000000u:
          if ( (unsigned __int16)this[50] == 260 )
            result = sub_6CD125(this);
          else
            result = -2147467263;
          break;
        default:
          goto LABEL_90;
      }
    }
LABEL_84:
    if ( result == dword_16C9A6C )
    {
LABEL_90:
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4532, "cannot map expression to pixel shader instruction set");
      return -2147467263;
    }
    if ( result < 0 )
      return result;
  }
  return 0;
}
