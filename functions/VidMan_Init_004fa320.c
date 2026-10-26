int sub_4FA320()
{
  const char *v0; // eax
  int v1; // eax
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  int v5; // ecx
  char *i; // eax
  int v7; // ecx
  const char *v8; // ecx
  const char *v9; // eax
  int v10; // ecx
  char *v11; // eax
  const char *v12; // eax
  int v14; // [esp-2h] [ebp-404h] BYREF
  char v15[512]; // [esp+2h] [ebp-400h] BYREF
  char v16[512]; // [esp+202h] [ebp-200h] BYREF

  if ( StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_26, 1019) )
    DebugLogWrite((int)dword_8AD25C, (int)aEnteredVidmanI);
  byte_8AFE70 = 0;
  SingleGlobalSetter(3 - dword_7CF65C);
  ShortComputation_d430(dword_7CFBFC);
  GlobalFlagSetter_d410(dword_7CFC20);
  SetAudioGlobalFlagFromBool(dword_7D032C);
  switch ( dword_7CFB90 )
  {
    case 1:
      sub_54A1C0(1, 0);
      v14 = 0;
      break;
    case 2:
      sub_54A1C0(1, 0);
      v14 = 1;
      break;
    case 3:
      sub_54A1C0(1, 1);
      v14 = 1;
      break;
    default:
      sub_54A1C0(1, 0);
      sub_54A1C0(2, 0);
      sub_54A1C0(4, 0);
      sub_54A1C0(8, 0);
      v14 = 1;
      goto LABEL_11;
  }
  sub_54A1C0(2, v14);
  sub_54A1C0(4, 1);
  sub_54A1C0(8, 1);
  v14 = 0;
LABEL_11:
  sub_54A1C0(16, v14);
  v0 = (const char *)dword_7CE5EC;
  if ( !dword_7CE5EC )
    v0 = byte_5EA438;
  TrackSceneLoader(v0);
  v1 = 396 * dword_8AC48C + dword_8AC490;
  if ( v1 )
  {
    v2 = (char *)(v1 + 4);
    v3 = (char *)(v15 - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 );
    v5 = strlen(v15);
    if ( v5 > 0 )
    {
      for ( i = &v15[v5 - 1]; i >= v15; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v7 = strlen(v15);
    if ( v7 > 0 && v15[v7 - 1] == 92 )
      v15[v7 - 1] = 0;
    StringRegistry(v15);
  }
  v8 = (const char *)dword_5EC428;
  if ( !dword_5EC428 )
    v8 = byte_5EA438;
  v9 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v9 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v16, "%s%s", v9, v8);
  v10 = strlen(v16);
  if ( v10 > 0 && v15[v10 + 511] == 92 )
    v15[v10 + 511] = 0;
  StringRegistry(v16);
  sub_546230(sub_4F9480, 1090519040);
  v11 = (char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v11 = byte_5EA438;
  if ( AudioEngineInitialization(&dword_8AFE88, v11, 0) )
  {
    StringRelocationCopy(0, v15);
    if ( StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_26, 1114) )
    {
      v12 = (const char *)dword_7CE5D0;
      if ( !dword_7CE5D0 )
        v12 = byte_5EA438;
      DebugLogWrite((int)dword_8AD25C, (int)"CUBE error loading scene file %s: %s", v12, v15);
    }
    return 1;
  }
  else
  {
    sub_546230(0, 0);
    sub_4D15F0(dword_8ACEE0);
    sub_4F9480(0, 1120534528);
    FlagBitSetter(2);
    return 0;
  }
}
