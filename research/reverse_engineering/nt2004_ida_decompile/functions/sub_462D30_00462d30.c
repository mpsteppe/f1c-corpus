char __thiscall sub_462D30(int this)
{
  CHAR *v2; // eax
  const char *v3; // edx
  const char *v4; // ecx
  char *v5; // eax
  __int16 v6; // ax
  __int16 v7; // ax
  __int16 v8; // ax
  __int16 v9; // ax
  __int16 v10; // ax
  __int16 v11; // ax
  double v12; // st7
  int v13; // eax
  char v14; // al
  float v16; // [esp+8h] [ebp-28h]
  float v17; // [esp+Ch] [ebp-24h]
  char Destination[32]; // [esp+10h] [ebp-20h] BYREF

  v2 = sub_410E00(&dword_766578);
  sub_4E8D60(v2);
  v3 = (const char *)(400 * dword_7D6B54 + dword_7D6B58 + 4);
  v4 = &v3[strlen(v3)];
  if ( v4 > v3 )
  {
    while ( *v4 != 92 )
    {
      if ( --v4 <= v3 )
        goto LABEL_6;
    }
    ++v4;
  }
LABEL_6:
  strncpy(Destination, v4, 0x1Fu);
  Destination[31] = 0;
  v5 = &Destination[strlen(Destination)];
  if ( v5 > Destination )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= Destination )
        goto LABEL_11;
    }
    *v5 = 0;
  }
LABEL_11:
  sub_431E20((char *)(this + 32), Destination, 0x1Fu);
  *(_BYTE *)(this + 68) = dword_769158;
  *(_BYTE *)(this + 69) = 0;
  *(_BYTE *)(this + 70) = dword_769998;
  *(_BYTE *)(this + 71) = dword_769320;
  *(_BYTE *)(this + 72) = dword_769464;
  *(_BYTE *)(this + 73) = dword_7684BC[0];
  *(_BYTE *)(this + 74) = dword_766C20;
  v6 = dword_769944 & 0x3F;
  *(_WORD *)(this + 86) = v6;
  v7 = ((byte_76699C & 1) << 6) + v6;
  *(_WORD *)(this + 86) = v7;
  v8 = ((byte_7669B4 & 1) << 7) + v7;
  *(_WORD *)(this + 86) = v8;
  v9 = ((dword_766AA4[0] & 1) << 8) + v8;
  *(_WORD *)(this + 86) = v9;
  v10 = ((dword_766EB4 & 1) << 10) + v9;
  *(_WORD *)(this + 86) = v10;
  v11 = ((dword_766FF8 & 1) << 11) + v10;
  *(_WORD *)(this + 86) = v11;
  *(_WORD *)(this + 86) = v11 + ((dword_76713C & 1) << 12);
  v12 = flt_769A90 * 1000.0;
  v16 = v12;
  if ( v12 >= 0.0 )
  {
    if ( v16 > 65535.0 )
      v16 = 65535.0;
  }
  else
  {
    v16 = 0.0;
  }
  LODWORD(v17) = (int)v16;
  *(_WORD *)(this + 88) = LOWORD(v17);
  switch ( dword_769824 )
  {
    case 1:
      v13 = 8;
      break;
    case 2:
      v13 = 12;
      break;
    case 3:
      v13 = 14;
      break;
    case 4:
      v13 = 32;
      break;
    default:
      v13 = 6;
      break;
  }
  *(_DWORD *)dword_76986C = v13;
  if ( v13 < dword_769874 )
  {
    v13 = dword_769874;
LABEL_25:
    *(_DWORD *)dword_76986C = v13;
    goto LABEL_26;
  }
  if ( v13 > dword_769878 )
  {
    v13 = dword_769878;
    goto LABEL_25;
  }
LABEL_26:
  *(_BYTE *)(this + 75) = v13;
  *(_BYTE *)(this + 76) = dword_767508;
  *(_BYTE *)(this + 77) = dword_7673C4;
  *(_DWORD *)(this + 64) = dword_768EAC;
  *(_WORD *)(this + 84) = dword_769920;
  v17 = (flt_767280 - flt_767288) * 255.0 / (flt_76728C - flt_767288);
  *(_BYTE *)(this + 78) = (int)v17;
  v14 = sub_4634F0(dword_764D70);
  sub_462CE0((_BYTE *)this, 0, v14);
  return sub_462CE0((_BYTE *)this, 1, dword_768618 != 0);
}
