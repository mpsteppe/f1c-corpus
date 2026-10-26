int __fastcall sub_64719B(int *a1, int a2, int a3, DWORD NumberOfBytesWritten)
{
  int v5; // eax
  unsigned int v6; // esi
  bool v7; // zf
  bool v8; // cc
  int v9; // eax
  char v10; // cl
  int v11; // eax
  char *v12; // esi
  unsigned int v13; // edi
  int v14; // ecx
  int v15; // eax
  char v16; // bl
  int v17; // eax
  int v18; // eax
  unsigned int i; // ecx
  int v20; // eax
  int v21; // eax
  _BYTE v24[1023]; // [esp+19h] [ebp-497h] BYREF
  _DWORD v25[28]; // [esp+42Ch] [ebp-84h] BYREF
  char v26; // [esp+49Ch] [ebp-14h]
  char v27; // [esp+49Dh] [ebp-13h]
  char v28; // [esp+49Eh] [ebp-12h]
  char v29; // [esp+49Fh] [ebp-11h]
  _BYTE v30[4]; // [esp+4A0h] [ebp-10h]
  int v31; // [esp+4A4h] [ebp-Ch]
  int v32; // [esp+4A8h] [ebp-8h]
  int v33; // [esp+4ACh] [ebp-4h]

  memset(v25, 0, 0x6Cu);
  v5 = *a1;
  v6 = 0;
  v7 = *a1 == 41;
  v8 = *a1 <= 41;
  v25[27] = a1;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v33 = -5614336;
  v30[0] = 0;
  v30[1] = 36;
  v30[2] = 73;
  v30[3] = 109;
  v31 = -2378094;
  v32 = 0;
  if ( v8 )
  {
    if ( v7 )
    {
      v11 = a1[2];
      v25[4] = 0;
      v12 = (char *)(v11 + 2);
      v13 = 0;
      v25[0] = 40;
      HIWORD(v25[3]) = 8;
      v32 = 1024;
      v14 = v11 - (_DWORD)v24;
      do
      {
        v15 = 4 * v13;
        v24[v15 + 1] = v24[4 * v13 + v14];
        v24[v15] = *(v12 - 1);
        v16 = *v12;
        ++v13;
        v12 += 4;
        v24[v15 - 1] = v16;
        v24[v15 + 2] = 0;
      }
      while ( v13 < 0x100 );
    }
    else
    {
      switch ( v5 )
      {
        case 20:
          v25[0] = 40;
          v25[4] = 0;
          HIWORD(v25[3]) = 24;
          goto LABEL_32;
        case 21:
        case 22:
          v25[0] = 40;
          v25[4] = 0;
          HIWORD(v25[3]) = 32;
          goto LABEL_32;
        case 23:
          v25[0] = 52;
          v25[4] = 3;
          HIWORD(v25[3]) = 16;
          v25[10] = 63488;
          v25[11] = 2016;
          v25[12] = 31;
          goto LABEL_32;
        case 24:
          v25[0] = 40;
          v25[4] = 0;
          HIWORD(v25[3]) = 16;
          goto LABEL_32;
        case 25:
          v25[0] = 56;
          v25[4] = 3;
          HIWORD(v25[3]) = 16;
          v25[10] = 31744;
          v25[11] = 992;
          v25[12] = 31;
          v25[13] = 0x8000;
          goto LABEL_32;
        case 26:
          v25[0] = 56;
          v25[4] = 3;
          HIWORD(v25[3]) = 16;
          v25[10] = 3840;
          v25[11] = 240;
          v25[12] = 15;
          v25[13] = 61440;
          goto LABEL_32;
        case 27:
          v25[0] = 40;
          v25[4] = 0;
          HIWORD(v25[3]) = 8;
          v32 = 1024;
          do
          {
            v9 = 4 * v6;
            v24[v9 + 1] = v30[v6 >> 5];
            v24[v9] = v30[(v6 >> 2) & 7];
            v10 = *((_BYTE *)&v33 + (v6++ & 3));
            v24[v9 - 1] = v10;
            v24[v9 + 2] = 0;
          }
          while ( v6 < 0x100 );
          goto LABEL_32;
        case 29:
          v25[4] = 3;
          v25[10] = 224;
          v25[11] = 28;
          v25[12] = 3;
          goto LABEL_15;
        case 30:
          v25[0] = 52;
          v25[4] = 3;
          HIWORD(v25[3]) = 16;
          v25[10] = 3840;
          v25[11] = 240;
          v25[12] = 15;
          goto LABEL_32;
        case 31:
          v25[10] = 1023;
          v25[12] = 1072693248;
          break;
        case 32:
          v25[0] = 56;
          v25[4] = 3;
          HIWORD(v25[3]) = 32;
          v25[10] = 255;
          v25[11] = 65280;
          v25[12] = dword_FF0000;
          v25[13] = -16777216;
          goto LABEL_32;
        case 33:
          v25[0] = 52;
          v25[4] = 3;
          HIWORD(v25[3]) = 32;
          v25[10] = 255;
          v25[11] = 65280;
          v25[12] = dword_FF0000;
          goto LABEL_32;
        case 34:
          v25[0] = 52;
          v25[4] = 3;
          HIWORD(v25[3]) = 32;
          v25[10] = 0xFFFF;
          v25[11] = -65536;
          v25[12] = 0;
          goto LABEL_32;
        case 35:
          v25[10] = 1072693248;
          v25[12] = 1023;
          break;
        default:
          return -2147467259;
      }
      v25[0] = 56;
      v25[4] = 3;
      HIWORD(v25[3]) = 32;
      v25[11] = 1047552;
      v25[13] = -1073741824;
    }
    goto LABEL_32;
  }
  v17 = v5 - 50;
  if ( !v17 )
  {
    v25[0] = 40;
    v25[4] = 0;
    HIWORD(v25[3]) = 8;
    v32 = 1024;
    for ( i = 0; i < 0x100; ++i )
    {
      v20 = 4 * i;
      v24[v20 + 1] = i;
      v24[v20] = i;
      v24[v20 - 1] = i;
      v24[v20 + 2] = 0;
    }
    goto LABEL_32;
  }
  v18 = v17 - 1;
  if ( !v18 )
  {
    v25[4] = 3;
    v25[10] = 255;
    v25[11] = 255;
    v25[12] = 255;
LABEL_15:
    v25[0] = 56;
    HIWORD(v25[3]) = 16;
    v25[13] = 65280;
    goto LABEL_32;
  }
  if ( v18 == 30 )
  {
    v25[0] = 52;
    v25[4] = 3;
    HIWORD(v25[3]) = 16;
    v25[10] = 0xFFFF;
    v25[11] = 0xFFFF;
    v25[12] = 0xFFFF;
LABEL_32:
    v21 = a1[4];
    v25[1] = a1[3];
    v25[2] = v21;
    return off_16C94CC((HIWORD(v25[3]) >> 3) * v25[1], a3, NumberOfBytesWritten);
  }
  return -2147467259;
}
