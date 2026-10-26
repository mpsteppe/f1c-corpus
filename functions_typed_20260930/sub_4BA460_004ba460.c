char __thiscall sub_4BA460(int *this)
{
  int v2; // eax
  const CHAR *v3; // esi
  char v4; // bl
  int v5; // eax
  char v6; // cl
  char *v7; // eax
  char *v8; // edi
  CHAR v9; // cl
  int v10; // eax
  char v11; // cl
  char v13[125]; // [esp+4h] [ebp-300h] BYREF
  __int16 v14; // [esp+81h] [ebp-283h]
  char v15; // [esp+83h] [ebp-281h]
  _DWORD v16[32]; // [esp+84h] [ebp-280h] BYREF
  char v17[509]; // [esp+104h] [ebp-200h] BYREF
  __int16 v18; // [esp+301h] [ebp-3h]
  char v19; // [esp+303h] [ebp-1h]

  if ( SessionStateCheckWrapper(dword_7CD25C) )
  {
    if ( (dword_7D0038 || dword_7D005C) && dword_7C56A4 == 7 )
    {
      *this = 1;
LABEL_8:
      v3 = lpPathName;
      if ( !lpPathName )
        v3 = byte_5EA438;
      CreateDirectoryAWrapper(v3);
      v4 = byte_5EA438[0];
      v17[0] = byte_5EA438[0];
      memset(&v17[1], 0, 0x1FCu);
      v18 = 0;
      v19 = 0;
      strcpy(v17, v3);
      v16[0] = off_5D2520;
      memset(&v16[1], 0, 0x7Cu);
      v13[0] = v4;
      memset(&v13[1], 0, 0x7Cu);
      v14 = 0;
      v15 = 0;
      TrackNameReader(v16, 128);
      if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)v16, byte_5EC4CC) )
      {
        v5 = 0;
        do
        {
          v6 = *((_BYTE *)v16 + v5);
          byte_5EC4CC[v5++] = v6;
        }
        while ( v6 );
      }
      sub_587DD0(v13, byte_5EC4CC, 127);
      v15 = 0;
      v7 = (char *)sub_587C20(v13, asc_5D251C);
      if ( v7 && v7 > v13 )
        *v7 = 0;
      strcat(v17, v13);
      v8 = &v17[strlen(v17) + 1];
      v9 = FileName[4];
      *(_DWORD *)--v8 = *(_DWORD *)FileName;
      v8[4] = v9;
      if ( !ThunkToFUN004b7300(this + 2, (int)v17, 1) )
        *this = 0;
      SingleFunctionDispatch_9800(this + 2);
      LOBYTE(v2) = SingleFunctionCallWrapper_9860(this + 2, dword_7D00A4);
      return v2;
    }
    *this = 0;
    goto LABEL_20;
  }
  v2 = *this;
  if ( *this == 1 )
    goto LABEL_8;
  if ( !v2 )
  {
LABEL_20:
    LOBYTE(v2) = dword_7D0410;
    if ( dword_7D0410 < 5 || dword_7D0410 > 6 )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, aReplayRecordin_0, byte_5EC4CC) )
      {
        v10 = 0;
        do
        {
          v11 = aReplayRecordin_0[v10];
          byte_5EC4CC[v10++] = v11;
        }
        while ( v11 );
      }
      LOBYTE(v2) = TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 2, 16909060);
    }
    return v2;
  }
  if ( v2 == 2 )
    *(_BYTE *)(this[2] + 3968) = 1;
  return v2;
}

