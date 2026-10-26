__time32_t __cdecl time(__time32_t *const Time)
{
  int v1; // eax
  DWORD v2; // eax
  __time32_t result; // eax
  _TIME_ZONE_INFORMATION TimeZoneInformation; // [esp+0h] [ebp-CCh] BYREF
  struct _SYSTEMTIME v5; // [esp+ACh] [ebp-20h] BYREF
  _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-10h] BYREF

  GetLocalTime(&SystemTime);
  GetSystemTime(&v5);
  if ( v5.wMinute == WORD5(xmmword_7FF108)
    && v5.wHour == WORD4(xmmword_7FF108)
    && v5.wDay == WORD3(xmmword_7FF108)
    && v5.wMonth == WORD1(xmmword_7FF108)
    && v5.wYear == (_WORD)xmmword_7FF108 )
  {
    v1 = dword_7FF100;
  }
  else
  {
    v2 = GetTimeZoneInformation(&TimeZoneInformation);
    if ( v2 == -1 )
      v1 = -1;
    else
      v1 = v2 == 2 && TimeZoneInformation.DaylightDate.wMonth && TimeZoneInformation.DaylightBias;
    xmmword_7FF108 = (__int128)v5;
    dword_7FF100 = v1;
  }
  result = __loctotime_t(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             v1);
  if ( Time )
    *Time = result;
  return result;
}
