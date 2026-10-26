int __thiscall sub_660174(_DWORD *this)
{
  int v2; // edi
  _DWORD *v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // esi
  unsigned int v17; // esi
  int v18; // ecx
  size_t v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // esi
  int v22; // eax
  _DWORD v24[7]; // [esp+8h] [ebp-3Ch] BYREF
  int v25[4]; // [esp+24h] [ebp-20h] BYREF
  void *Block; // [esp+34h] [ebp-10h]
  size_t Size; // [esp+38h] [ebp-Ch]
  unsigned int v28; // [esp+3Ch] [ebp-8h]
  void *v29; // [esp+40h] [ebp-4h]

  v2 = 0;
  sub_6801F7(1179535686);
  v3 = (_DWORD *)this[30];
  v4 = v3[42] + v3[43];
  Block = 0;
  v5 = v3[41] + v4;
  v29 = 0;
  v6 = v3[39] + v3[40] + v5;
  if ( v6 )
  {
    v7 = operator new(4 * v6);
    v8 = (int)v7;
    Block = v7;
    if ( v7 )
    {
      sub_65EC22((_DWORD *)this[30], (int)v7);
      v9 = this[30];
      v10 = *(_DWORD *)(v9 + 172);
      sub_65EC22((_DWORD *)(v9 + 112), v8 + 4 * v10);
      v11 = this[30];
      v12 = *(_DWORD *)(v11 + 168) + v10;
      sub_65EC22((_DWORD *)(v11 + 28), v8 + 4 * v12);
      v13 = this[30];
      v14 = *(_DWORD *)(v13 + 156) + v12;
      sub_65EC22((_DWORD *)(v13 + 56), v8 + 4 * v14);
      v15 = this[30];
      v16 = *(_DWORD *)(v15 + 160) + v14;
      sub_65EC22((_DWORD *)(v15 + 84), v8 + 4 * v16);
      v17 = *(_DWORD *)(this[30] + 164) + v16;
      sub_632C60(v8, v17);
      Size = 20 * v17;
      v29 = operator new(20 * v17);
      if ( v29 )
      {
        memset(v24, 0, sizeof(v24));
        v18 = this[15];
        v24[2] = 0;
        v24[0] = 28;
        v24[5] = v18 | 4;
        v24[3] = v17;
        v2 = sub_68024C(v24, 0x1Cu, 1, 0);
        if ( v2 >= 0 )
        {
          v19 = Size;
          memset(v29, 0, Size);
          v2 = sub_68024C(v29, v19, 1, (int)&v24[4]);
          if ( v2 >= 0 )
          {
            v28 = 0;
            if ( v17 )
            {
              Size = (size_t)v29;
              while ( 1 )
              {
                v2 = sub_68076C(
                       (int)v25,
                       Size,
                       **((void ***)Block + v28),
                       *(_DWORD *)(*((_DWORD *)Block + v28) + 4),
                       *(_DWORD *)this[22]);
                if ( v2 < 0 )
                  break;
                ++v28;
                Size += 20;
                if ( v28 >= v17 )
                  goto LABEL_12;
              }
            }
            else
            {
LABEL_12:
              v2 = sub_68024C("Microsoft (R) D3DX9 Shader Assembler 5.04.00.2904", 0xFFFFFFFF, 5, (int)&v24[1]);
              if ( v2 >= 0 )
              {
                v20 = sub_680385(v25);
                v21 = v20;
                if ( v20 > 0x8000 )
                {
                  sub_65DD1F((_DWORD *)*this, (int)(this + 4), 2031, "fragment info exceeds maximum comment size");
                  v2 = -2147467259;
                }
                else
                {
                  v2 = sub_65F877((int)this, v20);
                  if ( v2 >= 0 )
                  {
                    memcpy((void *)(this[22] + 4 * v21 + 4), (const void *)(this[22] + 4), 4 * this[23] - 4);
                    v2 = sub_680391(this[22] + 4, v21);
                    if ( v2 >= 0 )
                    {
                      this[23] += v21;
                      v22 = this[23];
                      this[26] += v21;
                      this[25] = v22;
                      v2 = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v2 = -2147024882;
      }
    }
    else
    {
      v2 = -2147024882;
    }
  }
  j__free(Block);
  j__free(v29);
  sub_680214(v25);
  return v2;
}
