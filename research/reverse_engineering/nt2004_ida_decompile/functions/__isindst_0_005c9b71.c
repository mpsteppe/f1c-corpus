BOOL __cdecl _isindst_0(_DWORD *a1)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax

  if ( !dword_626424 )
    return 0;
  v2 = a1[5];
  if ( v2 != dword_6264B8 || v2 != dword_6264C8 )
  {
    if ( dword_7FF270 )
    {
      if ( TimeZoneInformation.DaylightDate.wYear )
        cvtdate(
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
        cvtdate(
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
        cvtdate(
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
        cvtdate(
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
      cvtdate(1, 1, v2, 4, 1, 0, 0, 2, 0, 0, 0);
      cvtdate(0, 1, a1[5], 10, 5, 0, 0, 2, 0, 0, 0);
    }
  }
  v3 = a1[7];
  if ( dword_6264BC < dword_6264CC )
  {
    if ( v3 >= dword_6264BC && v3 <= dword_6264CC )
    {
      if ( v3 > dword_6264BC && v3 < dword_6264CC )
        return 1;
      goto LABEL_24;
    }
    return 0;
  }
  if ( v3 < dword_6264CC || v3 > dword_6264BC )
    return 1;
  if ( v3 > dword_6264CC && v3 < dword_6264BC )
    return 0;
LABEL_24:
  v4 = 1000 * (*a1 + 60 * (a1[1] + 60 * a1[2]));
  if ( v3 == dword_6264BC )
    return v4 >= dword_6264C0;
  else
    return v4 < dword_6264D0;
}
