int __cdecl sub_5896EE(_DWORD *a1)
{
  int v1; // eax
  DWORD v2; // eax
  int result; // eax
  _TIME_ZONE_INFORMATION TimeZoneInformation; // [esp+0h] [ebp-CCh] BYREF
  struct _SYSTEMTIME v5; // [esp+ACh] [ebp-20h] BYREF
  _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-10h] BYREF

  GetLocalTime(&SystemTime);
  GetSystemTime(&v5);
  if ( v5.wMinute == WORD5(xmmword_8D3E60)
    && v5.wHour == WORD4(xmmword_8D3E60)
    && v5.wDay == WORD3(xmmword_8D3E60)
    && v5.wMonth == WORD1(xmmword_8D3E60)
    && v5.wYear == (_WORD)xmmword_8D3E60 )
  {
    v1 = dword_8D3E58;
  }
  else
  {
    v2 = GetTimeZoneInformation(&TimeZoneInformation);
    if ( v2 == -1 )
      v1 = -1;
    else
      v1 = v2 == 2 && TimeZoneInformation.DaylightDate.wMonth && TimeZoneInformation.DaylightBias;
    xmmword_8D3E60 = (__int128)v5;
    dword_8D3E58 = v1;
  }
  result = sub_591EDF(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             v1);
  if ( a1 )
    *a1 = result;
  return result;
}

