struct tm *__cdecl localtime(const __time32_t *const Time)
{
  const __time32_t *v1; // esi
  int v3; // eax
  struct tm *v4; // eax
  struct tm *v5; // esi
  struct tm *v6; // eax
  const __time32_t *v7; // eax
  int v8; // edx
  int v9; // edx
  int v10; // ecx
  bool v11; // sf
  int tm_mday; // eax

  v1 = Time;
  if ( *Time < 0 )
    return 0;
  __tzset();
  v3 = *v1;
  if ( *v1 > 259200 && v3 < 2147224447 )
  {
    Time = (const __time32_t *const)(v3 - dword_913380);
    v4 = gmtime((const __time32_t *const)&Time);
    v5 = v4;
    if ( dword_913384 )
    {
      if ( _isindst(v4) )
      {
        Time = (const __time32_t *const)((char *)Time - dword_913388);
        v5 = gmtime((const __time32_t *const)&Time);
        v5->tm_isdst = 1;
      }
    }
    return v5;
  }
  v6 = gmtime(v1);
  v5 = v6;
  if ( dword_913384 && _isindst(v6) )
  {
    Time = (const __time32_t *const)(v5->tm_sec - dword_913388 - dword_913380);
    v5->tm_isdst = 1;
    v7 = Time;
  }
  else
  {
    v7 = (const __time32_t *)(v5->tm_sec - dword_913380);
    Time = v7;
  }
  v5->tm_sec = (int)v7 % 60;
  if ( (int)v7 % 60 < 0 )
  {
    v5->tm_sec = (int)v7 % 60 + 60;
    Time -= 15;
  }
  Time = (const __time32_t *const)(v5->tm_min + (int)Time / 60);
  v8 = (int)Time % 60;
  v11 = (int)Time % 60 < 0;
  v5->tm_min = (int)Time % 60;
  if ( v11 )
  {
    v5->tm_min = v8 + 60;
    Time -= 15;
  }
  Time = (const __time32_t *const)(v5->tm_hour + (int)Time / 60);
  v9 = (int)Time % 24;
  v11 = (int)Time % 24 < 0;
  v5->tm_hour = (int)Time % 24;
  if ( v11 )
  {
    v5->tm_hour = v9 + 24;
    Time -= 6;
  }
  v10 = (int)Time / 24;
  v11 = (int)Time / 24 < 0;
  Time = (const __time32_t *const)((int)Time / 24);
  if ( (int)Time <= 0 )
  {
    if ( !v11 )
      return v5;
    v5->tm_wday = (v5->tm_wday + v10 + 7) % 7;
    v5->tm_mday += (int)Time;
    tm_mday = v5->tm_mday;
    if ( tm_mday <= 0 )
    {
      --v5->tm_year;
      v5->tm_mday = tm_mday + 31;
      v5->tm_yday = 364;
      v5->tm_mon = 11;
      return v5;
    }
  }
  else
  {
    v5->tm_wday = (v10 + v5->tm_wday) % 7;
    v5->tm_mday += (int)Time;
  }
  v5->tm_yday += (int)Time;
  return v5;
}
