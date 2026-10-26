void _tzset_lk()
{
  char *v0; // eax
  const char *v1; // esi
  size_t v2; // eax
  char *v3; // eax
  const char *v4; // esi
  int v5; // ecx
  char v6; // al
  int v7; // eax
  int v8; // [esp+10h] [ebp-8h]
  BOOL UsedDefaultChar; // [esp+14h] [ebp-4h] BYREF

  v8 = 0;
  _lock(12);
  dword_6264C8 = -1;
  dword_6264B8 = -1;
  dword_7FF270 = 0;
  v0 = getenv("TZ");
  v1 = v0;
  if ( !v0 )
  {
    _unlock(12);
    if ( GetTimeZoneInformation(&TimeZoneInformation) == -1 )
      return;
    dword_626420 = 60 * TimeZoneInformation.Bias;
    dword_7FF270 = 1;
    if ( TimeZoneInformation.StandardDate.wMonth )
      dword_626420 = 60 * TimeZoneInformation.StandardBias + 60 * TimeZoneInformation.Bias;
    if ( TimeZoneInformation.DaylightDate.wMonth && TimeZoneInformation.DaylightBias )
    {
      dword_626424 = 1;
      dword_626428 = 60 * (TimeZoneInformation.DaylightBias - TimeZoneInformation.StandardBias);
    }
    else
    {
      dword_626424 = 0;
      dword_626428 = 0;
    }
    if ( !WideCharToMultiByte(
            CodePage,
            0x220u,
            TimeZoneInformation.StandardName,
            -1,
            lpMultiByteStr,
            63,
            0,
            &UsedDefaultChar)
      || UsedDefaultChar )
    {
      *lpMultiByteStr = 0;
    }
    else
    {
      lpMultiByteStr[63] = 0;
    }
    if ( WideCharToMultiByte(
           CodePage,
           0x220u,
           TimeZoneInformation.DaylightName,
           -1,
           off_6264B0,
           63,
           0,
           &UsedDefaultChar)
      && !UsedDefaultChar )
    {
      off_6264B0[63] = 0;
      return;
    }
LABEL_41:
    *off_6264B0 = 0;
    return;
  }
  if ( *v0 && (!dword_7FF324 || strcmp(v0, dword_7FF324)) )
  {
    sub_5C1B88(dword_7FF324);
    v2 = strlen(v1);
    v3 = (char *)malloc(v2 + 1);
    dword_7FF324 = v3;
    if ( v3 )
    {
      strcpy(v3, v1);
      _unlock(12);
      strncpy(lpMultiByteStr, v1, 3u);
      v4 = v1 + 3;
      lpMultiByteStr[3] = 0;
      if ( *v4 == 45 )
      {
        v8 = 1;
        ++v4;
      }
      v5 = 3600 * atol(v4);
      dword_626420 = v5;
      while ( 1 )
      {
        v6 = *v4;
        if ( *v4 != 43 && (v6 < 48 || v6 > 57) )
          break;
        ++v4;
      }
      if ( *v4 == 58 )
      {
        v5 = 60 * atol(++v4) + dword_626420;
        dword_626420 = v5;
        while ( *v4 >= 48 && *v4 <= 57 )
          ++v4;
        if ( *v4 == 58 )
        {
          v5 = atol(++v4) + dword_626420;
          dword_626420 = v5;
          while ( *v4 >= 48 && *v4 <= 57 )
            ++v4;
        }
      }
      if ( v8 )
        dword_626420 = -v5;
      v7 = *v4;
      dword_626424 = v7;
      if ( v7 )
      {
        strncpy(off_6264B0, v4, 3u);
        off_6264B0[3] = 0;
        return;
      }
      goto LABEL_41;
    }
  }
  _unlock(12);
}
