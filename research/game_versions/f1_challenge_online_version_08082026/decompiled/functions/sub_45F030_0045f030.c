void __thiscall sub_45F030(float *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  const char **v5; // ebp
  const char *v6; // eax
  unsigned int v7; // kr08_4
  int v8; // esi
  char *v9; // eax
  bool v10; // cc
  float v11; // [esp+0h] [ebp-290h]
  __int16 *v12; // [esp+18h] [ebp-278h]
  int v13; // [esp+1Ch] [ebp-274h]
  char v14[61]; // [esp+20h] [ebp-270h] BYREF
  __int16 v15; // [esp+5Dh] [ebp-233h]
  char v16; // [esp+5Fh] [ebp-231h]
  _BYTE v17[125]; // [esp+60h] [ebp-230h] BYREF
  __int16 v18; // [esp+DDh] [ebp-1B3h]
  char v19; // [esp+DFh] [ebp-1B1h]
  _BYTE v20[8]; // [esp+E0h] [ebp-1B0h] BYREF
  char v21[424]; // [esp+E8h] [ebp-1A8h] BYREF

  if ( this[225] >= 0.667 && !byte_7CE254 )
  {
    v13 = 0;
    if ( dword_7CB218 > 0 )
    {
      v12 = &word_7CB21C;
      do
      {
        switch ( *v12 )
        {
          case 4098:
            v2 = 1;
            goto LABEL_16;
          case 4099:
            v2 = 2;
            goto LABEL_16;
          case 4100:
            v2 = 3;
            goto LABEL_16;
          case 4101:
            v2 = 4;
            goto LABEL_16;
          case 4102:
            v2 = 5;
            goto LABEL_16;
          case 4103:
            v2 = 6;
            goto LABEL_16;
          case 4104:
            v2 = 7;
            goto LABEL_16;
          case 4105:
            v2 = 8;
            goto LABEL_16;
          case 4106:
            v2 = 9;
            goto LABEL_16;
          case 4107:
            v2 = 10;
LABEL_16:
            if ( v2 > *((_DWORD *)this + 28131) )
              goto LABEL_33;
            v3 = v2 - 1;
            if ( v2 - 1 < 0 || v3 >= *((_DWORD *)this + 28131) )
              goto LABEL_33;
            v4 = *((_DWORD *)this + 28128);
            if ( v3 <= 0 )
              goto LABEL_22;
            break;
          default:
            goto LABEL_33;
        }
        while ( v4 )
        {
          v4 = *(_DWORD *)(v4 + 4);
          if ( --v3 <= 0 )
          {
LABEL_22:
            if ( v4 )
            {
              v5 = *(const char ***)v4;
              if ( *(_DWORD *)v4 )
              {
                v6 = *v5;
                if ( !*v5 )
                  v6 = byte_5EA438;
                v7 = strlen(v6) + 1;
                v8 = v7 - 1;
                if ( (int)(v7 - 1) >= 0 )
                {
                  if ( (int)(v7 - 1) > 159 )
                    v8 = 159;
                }
                else
                {
                  v8 = 0;
                }
                v11 = dbl_8AFEA0;
                sub_4B33B0(4, 6, v8, 0, LODWORD(v11), 1);
                v9 = (char *)*v5;
                if ( !*v5 )
                  v9 = byte_5EA438;
                sub_587DD0(v21, v9, v8);
                v21[v8] = 0;
                sub_462250(v20, 0, -1, -1);
                v17[0] = byte_5EA438[0];
                memset(&v17[1], 0, 0x7Cu);
                v18 = 0;
                v19 = 0;
                v14[0] = byte_5EA438[0];
                memset(&v14[1], 0, 0x3Cu);
                v15 = 0;
                v16 = 0;
                sub_4B0B20(v14, 64);
                sub_45BC50(v14, v21, v17, 128);
                sub_4A0DF0(v17);
                sub_45BD10(&dword_7CD204, (int)v17, 3, 16909060);
                this[225] = 0.0;
              }
            }
            break;
          }
        }
LABEL_33:
        v10 = ++v13 < dword_7CB218;
        ++v12;
      }
      while ( v10 );
    }
  }
}
