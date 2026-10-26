_DWORD *__thiscall sub_463160(void *this, int a2)
{
  int v3; // edx
  _BYTE *v4; // eax
  int v5; // edx
  const char *v6; // edx
  int v7; // edx
  unsigned int v8; // kr10_4
  char v9; // al
  unsigned int v10; // edx
  char v11; // al
  int v12; // esi
  char v13; // cl
  _BYTE *v14; // eax
  int v15; // esi
  char *v16; // esi
  int v17; // edx
  char *v18; // edx
  char v19; // al
  char v20; // cl
  char v21; // al
  int i; // esi
  _DWORD *result; // eax
  _BYTE *v25; // edx
  char v26; // al
  int v27; // ecx
  char v28[64]; // [esp+10h] [ebp-40h] BYREF

  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 6949) )
    DebugLogWrite(&dword_8AD25C, aNetcommCheckin);
  v3 = sub_566810(a2, aPassword);
  if ( v3 )
  {
    sub_587DD0(v28, v3 + strlen(aPassword), 15);
    v28[15] = 0;
    v4 = (_BYTE *)sub_587C20(v28, asc_5C64D4);
    if ( v4 )
      *v4 = 0;
    StringCopyToStructField(v28);
    if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 6970) )
      DebugLogWrite(&dword_8AD25C, aSettingGamePas);
  }
  if ( !sub_566810(a2, aDedicated) )
  {
    if ( sub_566810(a2, aHost) )
    {
      *(_BYTE *)(*(_DWORD *)this + 197) = 1;
      if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 6989) )
        DebugLogWrite(&dword_8AD25C, aNetcommActivat);
      v5 = sub_566810(a2, aGamename);
      if ( v5 )
      {
        v28[0] = 0;
        sub_587DD0(v28, v5 + strlen(aGamename), 63);
        v28[63] = 0;
        v6 = (const char *)sub_5897CA(v28, asc_5C64D4);
        if ( v6 && strlen(v6) )
          strcpy((char *)(*(_DWORD *)this + 364), v6);
        if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7007) )
          DebugLogWrite(&dword_8AD25C, aSettingGameNam);
      }
    }
    else
    {
      v7 = sub_566810(a2, aConnect);
      if ( v7 )
      {
        v8 = strlen(aConnect) + 1;
        v9 = *(_BYTE *)(v7 + v8 - 1);
        v10 = v8 - 1 + v7;
        if ( v9 == 32 )
        {
          do
            v11 = *(_BYTE *)++v10;
          while ( v11 == 32 );
        }
        v12 = *(_DWORD *)this + 200;
        sub_587DD0(v12, v10, 79);
        *(_BYTE *)(v12 + 79) = 0;
        v13 = *(_BYTE *)(*(_DWORD *)this + 200);
        v14 = (_BYTE *)(*(_DWORD *)this + 200);
        if ( v13 )
        {
          while ( v13 != 32 )
          {
            v13 = *++v14;
            if ( !v13 )
              goto LABEL_30;
          }
          *v14 = 0;
        }
LABEL_30:
        v15 = sub_587C20(*(_DWORD *)this + 200, byte_5C3F6C);
        if ( v15 )
        {
          *(_BYTE *)(*(_DWORD *)this + 198) = 1;
          if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7035) )
            DebugLogWrite(&dword_8AD25C, aNetcommActivat_0);
          v16 = (char *)(v15 + 1);
          if ( !sub_587ECE(v16) )
          {
            v28[0] = 0;
            StringFormatWithBufferOverflowCheck(v28, "%d", (unsigned __int16)word_7D1004);
            strcpy(v16, v28);
            if ( dword_7C569C != 5 )
            {
              if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7048) )
                DebugLogWrite(&dword_8AD25C, aAutojoinAddres);
              if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7049) )
                DebugLogWrite(&dword_8AD25C, aNewAddressStri);
            }
          }
        }
        else if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7054) )
        {
          DebugLogWrite(&dword_8AD25C, aNoPortSpecifie);
        }
      }
    }
  }
  v17 = sub_566810(a2, aName_1);
  if ( v17 )
  {
    v18 = (char *)(strlen(aName_1) + v17);
    v28[0] = 0;
    v19 = *v18;
    if ( *v18 == 32 )
    {
      while ( v19 )
      {
        v19 = *++v18;
        if ( v19 != 32 )
          goto LABEL_48;
      }
    }
    else
    {
LABEL_48:
      if ( *v18 == 34 )
      {
        v20 = 1;
        ++v18;
LABEL_51:
        v21 = *v18;
        for ( i = 0; v21; ++v18 )
        {
          if ( i >= 30 )
            break;
          if ( v20 ? v21 == 34 : v21 == 32 )
            break;
          v28[i] = v21;
          v21 = v18[1];
          ++i;
        }
        v28[i] = 0;
        if ( strlen(v28) )
        {
          strcpy((char *)(*(_DWORD *)this + 284), v28);
          if ( dword_7C569C != 5 )
          {
            if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7106) )
              DebugLogWrite(&dword_8AD25C, aNetcommSetNetw);
          }
        }
        goto LABEL_62;
      }
    }
    v20 = 0;
    goto LABEL_51;
  }
LABEL_62:
  result = (_DWORD *)sub_566810(a2, aMaxplayers);
  if ( result )
  {
    v25 = (char *)result + strlen(aMaxplayers);
    if ( *v25 == 32 )
    {
      do
        v26 = *++v25;
      while ( v26 == 32 );
    }
    *(_DWORD *)(*(_DWORD *)this + 428) = sub_587ECE(v25);
    v27 = *(_DWORD *)(*(_DWORD *)this + 428);
    result = (_DWORD *)(*(_DWORD *)this + 428);
    if ( v27 >= 2 )
    {
      if ( v27 > 104 )
        *result = 104;
    }
    else
    {
      *result = 2;
    }
  }
  return result;
}
