BOOL __usercall _isindst_lk@<eax>(_DWORD *a1@<ebx>)
{
  int v2; // edi
  int v3; // ecx
  int v4; // eax

  if ( !dword_913384 )
    return 0;
  v2 = a1[5];
  if ( v2 != dword_913418 || v2 != dword_913424 )
  {
    if ( dword_FB84D4 )
    {
      if ( TimeZoneInformation.DaylightDate.wYear )
        sub_63DDA5(
          TimeZoneInformation.DaylightDate.wMonth,
          TimeZoneInformation.DaylightDate.wHour,
          1,
          0,
          v2,
          0,
          0,
          TimeZoneInformation.DaylightDate.wDay,
          TimeZoneInformation.DaylightDate.wMinute,
          TimeZoneInformation.DaylightDate.wSecond,
          TimeZoneInformation.DaylightDate.wMilliseconds);
      else
        sub_63DDA5(
          TimeZoneInformation.DaylightDate.wMonth,
          TimeZoneInformation.DaylightDate.wHour,
          1,
          1,
          v2,
          TimeZoneInformation.DaylightDate.wDay,
          TimeZoneInformation.DaylightDate.wDayOfWeek,
          0,
          TimeZoneInformation.DaylightDate.wMinute,
          TimeZoneInformation.DaylightDate.wSecond,
          TimeZoneInformation.DaylightDate.wMilliseconds);
      if ( TimeZoneInformation.StandardDate.wYear )
        sub_63DDA5(
          TimeZoneInformation.StandardDate.wMonth,
          TimeZoneInformation.StandardDate.wHour,
          0,
          0,
          v2,
          0,
          0,
          TimeZoneInformation.StandardDate.wDay,
          TimeZoneInformation.StandardDate.wMinute,
          TimeZoneInformation.StandardDate.wSecond,
          TimeZoneInformation.StandardDate.wMilliseconds);
      else
        sub_63DDA5(
          TimeZoneInformation.StandardDate.wMonth,
          TimeZoneInformation.StandardDate.wHour,
          0,
          1,
          v2,
          TimeZoneInformation.StandardDate.wDay,
          TimeZoneInformation.StandardDate.wDayOfWeek,
          0,
          TimeZoneInformation.StandardDate.wMinute,
          TimeZoneInformation.StandardDate.wSecond,
          TimeZoneInformation.StandardDate.wMilliseconds);
    }
    else
    {
      sub_63DDA5(4, 2, 1, 1, v2, 1, 0, 0, 0, 0, 0);
      sub_63DDA5(10, 2, 0, 1, v2, 5, 0, 0, 0, 0, 0);
    }
  }
  v3 = a1[7];
  if ( dword_91341C < dword_913428 )
  {
    if ( v3 >= dword_91341C && v3 <= dword_913428 )
    {
      if ( v3 > dword_91341C && v3 < dword_913428 )
        return 1;
      goto LABEL_26;
    }
    return 0;
  }
  if ( v3 < dword_913428 || v3 > dword_91341C )
    return 1;
  if ( v3 > dword_913428 && v3 < dword_91341C )
    return 0;
LABEL_26:
  v4 = 1000 * (*a1 + 60 * (a1[1] + 60 * a1[2]));
  if ( v3 == dword_91341C )
    return v4 >= dword_913420;
  else
    return v4 < dword_91342C;
}
