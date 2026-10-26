void __thiscall sub_4DA870(int *this)
{
  int v2; // eax
  const char *v3; // esi
  char v4; // bl
  char *v5; // eax
  char *v6; // edi
  CHAR v7; // cl
  CHAR **v8; // eax
  CHAR *v9; // eax
  char *v10; // edx
  CHAR v11; // cl
  char *v12; // eax
  char *v13; // edi
  char v14; // cl
  char Str[125]; // [esp+8h] [ebp-300h] BYREF
  __int16 v16; // [esp+85h] [ebp-283h]
  char v17; // [esp+87h] [ebp-281h]
  char Source[4]; // [esp+88h] [ebp-280h] BYREF
  _BYTE v19[124]; // [esp+8Ch] [ebp-27Ch] BYREF
  char v20[509]; // [esp+108h] [ebp-200h] BYREF
  __int16 v21; // [esp+305h] [ebp-3h]
  char v22; // [esp+307h] [ebp-1h]

  sub_4D2670(byte_7D4490);
  dword_769800 = 0;
  if ( sub_463490(dword_764D70) )
  {
    if ( dword_768948 )
    {
      if ( !dword_7684E0 && !dword_768504 )
      {
LABEL_5:
        *this = 0;
LABEL_22:
        if ( *(int *)dword_7689CC < 5 || *(int *)dword_7689CC > 7 )
        {
          if ( sub_41F230(dword_62A170, aRecordingOff, Destination) )
          {
            strncpy(Destination, aRecordingOff, 0x1FFu);
            byte_62A37B = 0;
          }
          sub_45D100(&byte_764D68, (int)Destination, 2, 16909060, 0);
        }
        return;
      }
    }
    else if ( !dword_7684E0 && !dword_768504 || dword_75CBB0 != 7 )
    {
      goto LABEL_5;
    }
    *this = 1;
    goto LABEL_11;
  }
  v2 = *this;
  if ( *this == 1 )
  {
LABEL_11:
    v3 = ArgList;
    if ( !ArgList )
      v3 = &byte_629120;
    _mkdir(v3);
    v4 = byte_629120;
    v20[0] = byte_629120;
    memset(&v20[1], 0, 0x1FCu);
    v21 = 0;
    v22 = 0;
    strcpy(v20, v3);
    strcpy(Source, "VCR");
    memset(v19, 0, sizeof(v19));
    Str[0] = v4;
    memset(&Str[1], 0, 0x7Cu);
    v16 = 0;
    v17 = 0;
    sub_4E8F80(Source, 128);
    if ( sub_41F230(dword_62A170, Source, Destination) )
    {
      strncpy(Destination, Source, 0x1FFu);
      byte_62A37B = 0;
    }
    strncpy(Str, Destination, 0x7Fu);
    v17 = 0;
    v5 = strstr(Str, asc_6100B8);
    if ( v5 && v5 > Str )
      *v5 = 0;
    strcat(v20, Str);
    v6 = &v20[strlen(v20) + 1];
    v7 = aVcr[4];
    *(_DWORD *)--v6 = *(_DWORD *)aVcr;
    v6[4] = v7;
    if ( !sub_4D97E0(this + 2, v20, 1) )
      *this = 0;
    sub_4D9810(this + 2);
    sub_4D9870(this + 2, dword_768570);
    return;
  }
  if ( !v2 )
    goto LABEL_22;
  if ( v2 == 2 )
  {
    *(_BYTE *)(this[2] + 2148) = 1;
    *(_DWORD *)(this[2] + 2164) = 5;
    sub_4D2670(byte_7D4490);
    v8 = (CHAR **)(this[2] + 2172);
    v20[0] = 0;
    v9 = *v8;
    if ( !v9 )
      v9 = &byte_629120;
    v10 = (char *)(v20 - v9);
    do
    {
      v11 = *v9;
      v9[(_DWORD)v10] = *v9;
      ++v9;
    }
    while ( v11 );
    v12 = &v20[strlen(v20)];
    if ( v12 > v20 )
    {
      while ( *v12 != 46 )
      {
        if ( --v12 <= v20 )
          goto LABEL_37;
      }
      *v12 = 0;
    }
LABEL_37:
    v13 = &v20[strlen(v20) + 1];
    v14 = byte_6100A4;
    *(_DWORD *)--v13 = dword_6100A0;
    v13[4] = v14;
    sub_4D2A70(byte_7D4490, v20);
    sub_578600(v20);
  }
}
