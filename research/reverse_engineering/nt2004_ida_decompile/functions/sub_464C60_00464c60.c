_DWORD *__thiscall sub_464C60(void *this, int ArgList)
{
  int v3; // edx
  char *v4; // eax
  int v5; // edx
  unsigned int v6; // kr08_4
  char v7; // al
  const char *v8; // edx
  char v9; // al
  char *v10; // esi
  char v11; // cl
  _BYTE *v12; // eax
  char *v13; // esi
  char *v14; // esi
  int v15; // eax
  int v16; // edx
  char *v17; // edx
  int v18; // edx
  char *v19; // edx
  char v20; // al
  char v21; // cl
  char v22; // al
  int i; // esi
  _DWORD *result; // eax
  const char *v26; // edx
  char v27; // al
  int v28; // ecx
  char v29; // [esp+0h] [ebp-50h]
  char Str[64]; // [esp+10h] [ebp-40h] BYREF

  if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7734) )
    sub_500FE0((int)&unk_7D7920, aNetcommCheckin, ArgList);
  v3 = sub_579060(ArgList, aPassword);
  if ( v3 )
  {
    strncpy(Str, (const char *)(v3 + strlen(aPassword)), 0xFu);
    Str[15] = 0;
    v4 = strstr(Str, word_5FD024);
    if ( v4 )
      *v4 = 0;
    sub_578600(Str);
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7765) )
      sub_500FE0((int)&unk_7D7920, aSettingGamePas, (char)Str);
  }
  if ( sub_579060(ArgList, aHost) )
  {
    *(_BYTE *)(*(_DWORD *)this + 164) = 1;
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7796) )
      sub_500FE0((int)&unk_7D7920, aNetcommActivat, v29);
  }
  else
  {
    v5 = sub_579060(ArgList, aConnect);
    if ( v5 )
    {
      v6 = strlen(aConnect) + 1;
      v7 = *(_BYTE *)(v5 + v6 - 1);
      v8 = (const char *)(v6 - 1 + v5);
      if ( v7 == 32 )
      {
        do
          v9 = *++v8;
        while ( v9 == 32 );
      }
      v10 = (char *)(*(_DWORD *)this + 167);
      strncpy(v10, v8, 0x4Fu);
      v10[79] = 0;
      v11 = *(_BYTE *)(*(_DWORD *)this + 167);
      v12 = (_BYTE *)(*(_DWORD *)this + 167);
      if ( v11 )
      {
        while ( v11 != 32 )
        {
          v11 = *++v12;
          if ( !v11 )
            goto LABEL_22;
        }
        *v12 = 0;
      }
LABEL_22:
      v13 = strstr((const char *)(*(_DWORD *)this + 167), asc_5FE040);
      if ( v13 )
      {
        *(_BYTE *)(*(_DWORD *)this + 165) = 1;
        if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7823) )
          sub_500FE0((int)&unk_7D7920, aNetcommActivat_0, v29);
        v14 = v13 + 1;
        v15 = atol(v14);
        if ( !v15 || v15 == 6500 )
        {
          Str[0] = 0;
          sprintf(Str, "%d", (unsigned __int16)word_7699D8);
          strcpy(v14, Str);
          if ( dword_75CBA8 != 5 )
          {
            if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7843) )
              sub_500FE0((int)&unk_7D7920, aAutojoinAddres, word_7699D8);
            if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7844) )
              sub_500FE0((int)&unk_7D7920, aNewAddressStri, *(_BYTE *)this - 89);
          }
        }
      }
      else if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7849) )
      {
        sub_500FE0((int)&unk_7D7920, aNoPortSpecifie, v29);
      }
    }
  }
  v16 = sub_579060(ArgList, aGamename);
  if ( v16 )
  {
    Str[0] = 0;
    strncpy(Str, (const char *)(v16 + strlen(aGamename)), 0x3Fu);
    Str[63] = 0;
    v17 = strtok(Str, word_5FD024);
    if ( v17 && strlen(v17) )
      strcpy((char *)(*(_DWORD *)this + 332), v17);
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7869) )
      sub_500FE0((int)&unk_7D7920, aSettingGameNam, *(_BYTE *)this + 76);
  }
  v18 = sub_579060(ArgList, aName);
  if ( v18 )
  {
    v19 = (char *)(strlen(aName) + v18);
    Str[0] = 0;
    if ( *v19 == 32 )
    {
      do
        v20 = *++v19;
      while ( v20 == 32 );
    }
    if ( *v19 == 34 )
    {
      v21 = 1;
      ++v19;
    }
    else
    {
      v21 = 0;
    }
    v22 = *v19;
    for ( i = 0; v22; ++v19 )
    {
      if ( i >= 30 )
        break;
      if ( v21 ? v22 == 34 : v22 == 32 )
        break;
      Str[i] = v22;
      v22 = v19[1];
      ++i;
    }
    Str[i] = 0;
    if ( strlen(Str) )
    {
      strcpy((char *)(*(_DWORD *)this + 252), Str);
      if ( dword_75CBA8 != 5 )
      {
        if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7920) )
          sub_500FE0((int)&unk_7D7920, aNetcommSetNetw, (char)Str);
      }
    }
  }
  result = (_DWORD *)sub_579060(ArgList, aMaxplayers);
  if ( result )
  {
    v26 = (char *)result + strlen(aMaxplayers);
    if ( *v26 == 32 )
    {
      do
        v27 = *++v26;
      while ( v27 == 32 );
    }
    *(_DWORD *)(*(_DWORD *)this + 396) = atol(v26);
    v28 = *(_DWORD *)(*(_DWORD *)this + 396);
    result = (_DWORD *)(*(_DWORD *)this + 396);
    if ( v28 >= 2 )
    {
      if ( v28 > 48 )
        *result = 48;
    }
    else
    {
      *result = 2;
    }
  }
  return result;
}
