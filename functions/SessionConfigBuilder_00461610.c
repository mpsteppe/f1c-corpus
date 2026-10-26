char __thiscall sub_461610(int this)
{
  char *v2; // eax
  const char *v3; // edx
  const char *v4; // ecx
  char *v5; // eax
  char *v6; // eax
  int v7; // eax
  __int16 v8; // ax
  __int16 v9; // ax
  __int16 v10; // ax
  __int16 v11; // ax
  __int16 v12; // ax
  __int16 v13; // ax
  __int16 v14; // ax
  double v15; // st7
  int v16; // eax
  float v18; // [esp+8h] [ebp-28h]
  int v19; // [esp+Ch] [ebp-24h]
  char v20[32]; // [esp+10h] [ebp-20h] BYREF

  v2 = NullSafePointerDereference((char **)&dword_7CE5D0);
  SceneDataParser(v2);
  v3 = (const char *)(396 * dword_8AC48C + dword_8AC490 + 4);
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
  sub_587DD0(v20, v4, 31);
  v20[31] = 0;
  v5 = &v20[strlen(v20)];
  if ( v5 > v20 )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= v20 )
        goto LABEL_11;
    }
    *v5 = 0;
  }
LABEL_11:
  SafeStringCopy(this + 32, (int)v20, 31);
  v6 = NullSafePointerDereference((char **)&dword_7D0434);
  v7 = ReversePathSearchForBackslash(v6);
  SafeStringCopy(this + 64, v7, 31);
  *(_BYTE *)(this + 100) = dword_7D0A44;
  *(_BYTE *)(this + 101) = 0;
  *(_BYTE *)(this + 102) = dword_7D0FC4;
  *(_BYTE *)(this + 103) = dword_7D0C18;
  *(_BYTE *)(this + 104) = dword_7D0D14;
  *(_BYTE *)(this + 105) = dword_7D0014;
  *(_BYTE *)(this + 106) = dword_7CEB10;
  v8 = dword_7D0F70 & 0x3F;
  *(_WORD *)(this + 118) = v8;
  v9 = ((byte_7CE874 & 1) << 6) + v8;
  *(_WORD *)(this + 118) = v9;
  v10 = ((byte_7CE88C & 1) << 7) + v9;
  *(_WORD *)(this + 118) = v10;
  v11 = ((dword_7CE958 & 1) << 8) + v10;
  *(_WORD *)(this + 118) = v11;
  v12 = ((byte_7CE97C & 1) << 9) + v11;
  *(_WORD *)(this + 118) = v12;
  v13 = ((dword_7CED44 & 1) << 10) + v12;
  *(_WORD *)(this + 118) = v13;
  v14 = ((dword_7CEE40 & 1) << 11) + v13;
  *(_WORD *)(this + 118) = v14;
  *(_WORD *)(this + 118) = v14 + ((dword_7CEF3C & 1) << 12);
  *(_WORD *)(this + 120) = dword_7CEC30;
  *(_WORD *)(this + 122) = dword_7CEC54;
  v15 = flt_7D108C * 1000.0;
  v18 = v15;
  if ( v15 >= 0.0 )
  {
    if ( v18 > 65535.0 )
      v18 = 65535.0;
  }
  else
  {
    v18 = 0.0;
  }
  v19 = (int)v18;
  *(_WORD *)(this + 124) = v19;
  switch ( dword_7D0E50 )
  {
    case 1:
      v16 = 8;
      break;
    case 2:
      v16 = 12;
      break;
    case 3:
      v16 = 14;
      break;
    case 4:
      v16 = 32;
      break;
    default:
      v16 = 6;
      break;
  }
  dword_7D0E98 = v16;
  if ( v16 < dword_7D0EA0 )
  {
    v16 = dword_7D0EA0;
LABEL_25:
    dword_7D0E98 = v16;
    goto LABEL_26;
  }
  if ( v16 > dword_7D0EA4 )
  {
    v16 = dword_7D0EA4;
    goto LABEL_25;
  }
LABEL_26:
  *(_BYTE *)(this + 107) = v16;
  *(_BYTE *)(this + 108) = dword_7CF134;
  *(_BYTE *)(this + 109) = dword_7CF038;
  *(float *)(this + 96) = flt_7D084C;
  *(_WORD *)(this + 116) = dword_7D0F4C;
  UtilityFunction_15c0((_BYTE *)this, 0, 0);
  return UtilityFunction_15c0((_BYTE *)this, 1, dword_7D0134 != 0);
}
