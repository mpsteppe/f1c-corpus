struct tm *__cdecl gmtime(const __time32_t *const Time)
{
  __time32_t v1; // esi
  int v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  void *v6; // eax
  struct tm *v7; // ecx
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int *v11; // edi
  int v12; // esi
  int v13; // eax
  int *i; // ebx
  int tm_yday; // edx
  int v16; // eax
  int v17; // esi

  v1 = *Time;
  v2 = 0;
  v3 = _getptd();
  v4 = v3;
  if ( v1 < 0 )
    return 0;
  if ( v3[16] || (v6 = malloc(0x24u), v4[16] = v6, v7 = (struct tm *)&unk_7FF330, v6) )
    v7 = (struct tm *)v4[16];
  v8 = v1 / 126230400;
  v9 = v1 % 126230400;
  v10 = 4 * v8 + 70;
  if ( v9 >= 31536000 )
  {
    v9 -= 31536000;
    v10 = 4 * v8 + 71;
    if ( v9 >= 31536000 )
    {
      v9 -= 31536000;
      v10 = 4 * v8 + 72;
      if ( v9 < 31622400 )
      {
        v2 = 1;
      }
      else
      {
        v10 = 4 * v8 + 73;
        v9 -= 31622400;
      }
    }
  }
  v7->tm_year = v10;
  v11 = dword_628774;
  v7->tm_yday = v9 / 86400;
  v12 = v9 % 86400;
  if ( !v2 )
    v11 = dword_6287A8;
  v13 = 1;
  for ( i = v11 + 1; *i < v7->tm_yday; ++i )
    ++v13;
  tm_yday = v7->tm_yday;
  v16 = v13 - 1;
  v7->tm_mon = v16;
  v7->tm_mday = tm_yday - v11[v16];
  v7->tm_wday = (*Time / 86400 + 4) % 7;
  v7->tm_hour = v12 / 3600;
  v17 = v12 % 3600;
  v7->tm_min = v17 / 60;
  v7->tm_isdst = 0;
  v7->tm_sec = v17 % 60;
  return v7;
}
