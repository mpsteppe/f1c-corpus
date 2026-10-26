BOOL __cdecl sub_59249B(_DWORD *a1)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax

  if ( !dword_5E775C )
    return 0;
  v2 = a1[5];
  if ( v2 != dword_5E77F0 || v2 != dword_5E7800 )
  {
    if ( dword_8D3FC0 )
    {
      if ( TimeZoneInformation.DaylightDate.wYear )
        sub_592647(
          1,
          0,
          v2,
          TimeZoneInformation.DaylightDate.wMonth,
          0,
          0,
          TimeZoneInformation.DaylightDate.wDay,
          TimeZoneInformation.DaylightDate.wHour,
          TimeZoneInformation.DaylightDate.wMinute,
          TimeZoneInformation.DaylightDate.wSecond,
          TimeZoneInformation.DaylightDate.wMilliseconds);
      else
        sub_592647(
          1,
          1,
          v2,
          TimeZoneInformation.DaylightDate.wMonth,
          TimeZoneInformation.DaylightDate.wDay,
          TimeZoneInformation.DaylightDate.wDayOfWeek,
          0,
          TimeZoneInformation.DaylightDate.wHour,
          TimeZoneInformation.DaylightDate.wMinute,
          TimeZoneInformation.DaylightDate.wSecond,
          TimeZoneInformation.DaylightDate.wMilliseconds);
      if ( TimeZoneInformation.StandardDate.wYear )
        sub_592647(
          0,
          0,
          a1[5],
          TimeZoneInformation.StandardDate.wMonth,
          0,
          0,
          TimeZoneInformation.StandardDate.wDay,
          TimeZoneInformation.StandardDate.wHour,
          TimeZoneInformation.StandardDate.wMinute,
          TimeZoneInformation.StandardDate.wSecond,
          TimeZoneInformation.StandardDate.wMilliseconds);
      else
        sub_592647(
          0,
          1,
          a1[5],
          TimeZoneInformation.StandardDate.wMonth,
          TimeZoneInformation.StandardDate.wDay,
          TimeZoneInformation.StandardDate.wDayOfWeek,
          0,
          TimeZoneInformation.StandardDate.wHour,
          TimeZoneInformation.StandardDate.wMinute,
          TimeZoneInformation.StandardDate.wSecond,
          TimeZoneInformation.StandardDate.wMilliseconds);
    }
    else
    {
      sub_592647(1, 1, v2, 4, 1, 0, 0, 2, 0, 0, 0);
      sub_592647(0, 1, a1[5], 10, 5, 0, 0, 2, 0, 0, 0);
    }
  }
  v3 = a1[7];
  if ( dword_5E77F4 < dword_5E7804 )
  {
    if ( v3 >= dword_5E77F4 && v3 <= dword_5E7804 )
    {
      if ( v3 > dword_5E77F4 && v3 < dword_5E7804 )
        return 1;
      goto LABEL_24;
    }
    return 0;
  }
  if ( v3 < dword_5E7804 || v3 > dword_5E77F4 )
    return 1;
  if ( v3 > dword_5E7804 && v3 < dword_5E77F4 )
    return 0;
LABEL_24:
  v4 = 1000 * (*a1 + 60 * (a1[1] + 60 * a1[2]));
  if ( v3 == dword_5E77F4 )
    return v4 >= dword_5E77F8;
  else
    return v4 < dword_5E7808;
}

