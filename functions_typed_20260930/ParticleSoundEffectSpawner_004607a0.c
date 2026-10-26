int __thiscall sub_4607A0(unsigned __int8 *this)
{
  __int16 v2; // ax
  int v3; // ecx
  char *v4; // eax
  int v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // edi
  char v10; // cl
  char v11; // al
  const char *v12; // ecx
  const char *v13; // eax
  char v14; // al
  float v16; // [esp+0h] [ebp-3CCh]
  int v17; // [esp+10h] [ebp-3BCh] BYREF
  int v18; // [esp+14h] [ebp-3B8h]
  float v19; // [esp+18h] [ebp-3B4h]
  char v20[509]; // [esp+1Ch] [ebp-3B0h] BYREF
  __int16 v21; // [esp+219h] [ebp-1B3h]
  char v22; // [esp+21Bh] [ebp-1B1h]
  _BYTE v23[8]; // [esp+21Ch] [ebp-1B0h] BYREF
  __int16 v24; // [esp+224h] [ebp-1A8h]
  __int16 v25; // [esp+226h] [ebp-1A6h]
  int v26; // [esp+228h] [ebp-1A4h]
  int v27; // [esp+22Ch] [ebp-1A0h]
  int v28; // [esp+230h] [ebp-19Ch]
  int v29; // [esp+234h] [ebp-198h]

  TwoByteFieldSetter(this + 112468, this[112488], this[112489]);
  v16 = dbl_8AFEA0;
  ProgressBarEventEncode(4, 36, 20, 0, LODWORD(v16), 1);
  v2 = HashChecksumComputation(this[112488], this[112489]);
  v19 = dbl_8AFEA0;
  v24 = v2;
  v18 = (int)v19;
  v25 = ((v18 & 0xFFFC) << 6) + (unsigned __int8)RandLCGRandomNumberGenerator(v3);
  v4 = (char *)dword_7CE64C;
  if ( !dword_7CE64C )
    v4 = byte_5EA438;
  v5 = ConditionalDispatch_40b0(v4);
  if ( !v5 )
    goto LABEL_8;
  v6 = *(char **)(v5 + 8);
  if ( !v6 )
    v6 = byte_5EA438;
  if ( sub_45C400(this + 112468, (int)v6, &v17) )
    v26 = v17;
  else
LABEL_8:
    v26 = 0;
  v20[0] = byte_5EA438[0];
  memset(&v20[1], 0, 0x1FCu);
  v21 = 0;
  v22 = 0;
  sub_4CEEF0(v20, 512);
  if ( ParserDispatchWrapper(this + 112468, (int)v20, &v17) )
    v27 = dword_8ACED8 + v17 - 1413405834;
  else
    v27 = 0;
  v7 = (char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v7 = byte_5EA438;
  sub_587DD0(v20, v7, 511);
  v22 = 0;
  v8 = &v20[strlen(v20)];
  if ( v8 > v20 )
  {
    while ( *v8 != 46 )
    {
      if ( --v8 <= v20 )
        goto LABEL_19;
    }
    *v8 = 0;
  }
LABEL_19:
  v9 = &v20[strlen(v20) + 1];
  v10 = byte_5C5D28;
  *(_DWORD *)--v9 = dword_5C5D24;
  v9[4] = v10;
  v11 = DataFileCheckSizeQuery(this + 112468, (int)v20, &v17);
  v12 = (const char *)dword_7D0434;
  v28 = v11 != 0 ? v17 : 0;
  if ( !dword_7D0434 )
    v12 = byte_5EA438;
  v13 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v13 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v20, "%s%s", v13, v12);
  v14 = DataFileCheckSizeQuery(this + 112468, (int)v20, &v17);
  v29 = v14 != 0 ? v17 : 0;
  return TextureCreationWrapper(v23, 2, -1, -1);
}

