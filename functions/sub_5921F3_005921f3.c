void sub_5921F3()
{
  unsigned int *v0; // eax
  unsigned int *v1; // esi
  char *v2; // eax
  unsigned __int8 *v3; // esi
  int v4; // ecx
  char v5; // al
  int v6; // eax
  int v7; // [esp+10h] [ebp-8h]
  BOOL UsedDefaultChar; // [esp+14h] [ebp-4h] BYREF

  v7 = 0;
  CriticalSectionLazyInitEnter(12);
  dword_5E7800 = -1;
  dword_5E77F0 = -1;
  dword_8D3FC0 = 0;
  v0 = (unsigned int *)sub_596D81("TZ");
  v1 = v0;
  if ( !v0 )
  {
    CritSectLeave(12);
    if ( GetTimeZoneInformation(&TimeZoneInformation) == -1 )
      return;
    dword_5E7758 = 60 * TimeZoneInformation.Bias;
    dword_8D3FC0 = 1;
    if ( TimeZoneInformation.StandardDate.wMonth )
      dword_5E7758 = 60 * TimeZoneInformation.StandardBias + 60 * TimeZoneInformation.Bias;
    if ( TimeZoneInformation.DaylightDate.wMonth && TimeZoneInformation.DaylightBias )
    {
      dword_5E775C = 1;
      dword_5E7760 = 60 * (TimeZoneInformation.DaylightBias - TimeZoneInformation.StandardBias);
    }
    else
    {
      dword_5E775C = 0;
      dword_5E7760 = 0;
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
           off_5E77E8,
           63,
           0,
           &UsedDefaultChar)
      && !UsedDefaultChar )
    {
      off_5E77E8[63] = 0;
      return;
    }
LABEL_41:
    *off_5E77E8 = 0;
    return;
  }
  if ( *(_BYTE *)v0 && (!dword_8D4074 || sub_58FB90(v0, dword_8D4074)) )
  {
    sub_58AA6F(dword_8D4074);
    v2 = Strlen(v1);
    dword_8D4074 = (LPVOID)MallocWrapperForNhMalloc((int)(v2 + 1));
    if ( dword_8D4074 )
    {
      sub_58FCA0();
      CritSectLeave(12);
      sub_587DD0(lpMultiByteStr, (char *)v1, 3u);
      v3 = (unsigned __int8 *)v1 + 3;
      lpMultiByteStr[3] = 0;
      if ( *v3 == 45 )
      {
        v7 = 1;
        ++v3;
      }
      v4 = 3600 * sub_587ECE(v3);
      dword_5E7758 = v4;
      while ( 1 )
      {
        v5 = *v3;
        if ( *v3 != 43 && (v5 < 48 || v5 > 57) )
          break;
        ++v3;
      }
      if ( *v3 == 58 )
      {
        v4 = 60 * sub_587ECE(++v3) + dword_5E7758;
        dword_5E7758 = v4;
        while ( (char)*v3 >= 48 && (char)*v3 <= 57 )
          ++v3;
        if ( *v3 == 58 )
        {
          v4 = sub_587ECE(++v3) + dword_5E7758;
          dword_5E7758 = v4;
          while ( (char)*v3 >= 48 && (char)*v3 <= 57 )
            ++v3;
        }
      }
      if ( v7 )
        dword_5E7758 = -v4;
      v6 = (char)*v3;
      dword_5E775C = v6;
      if ( v6 )
      {
        sub_587DD0(off_5E77E8, (char *)v3, 3u);
        off_5E77E8[3] = 0;
        return;
      }
      goto LABEL_41;
    }
  }
  CritSectLeave(12);
}
