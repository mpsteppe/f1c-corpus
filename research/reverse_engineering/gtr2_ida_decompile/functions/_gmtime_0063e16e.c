struct tm *__cdecl gmtime(const __time32_t *const Time)
{
  __time32_t v1; // esi
  int v2; // ebx
  DWORD *v3; // eax
  DWORD *v4; // edi
  void *v6; // eax
  struct tm *v7; // ecx
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int *v11; // edi
  int v12; // esi
  int tm_yday; // eax
  int i; // edx
  int v15; // edx
  int v16; // esi

  v1 = *Time;
  v2 = 0;
  v3 = _getptd();
  v4 = v3;
  if ( v1 < 0 )
    return 0;
  if ( v3[17] || (v6 = malloc(0x24u), v4[17] = (DWORD)v6, v7 = (struct tm *)&unk_FB84E0, v6) )
    v7 = (struct tm *)v4[17];
  v8 = v1 / 126230400;
  v9 = v1 % 126230400;
  v10 = 4 * v8 + 70;
  if ( v9 >= (int)dword_1E13380 )
  {
    v9 -= (int)dword_1E13380;
    v10 = 4 * v8 + 71;
    if ( v9 >= (int)dword_1E13380 )
    {
      v9 -= (int)dword_1E13380;
      v10 = 4 * v8 + 72;
      if ( v9 < (int)dword_1E28500 )
      {
        v2 = 1;
      }
      else
      {
        v10 = 4 * v8 + 73;
        v9 -= (int)dword_1E28500;
      }
    }
  }
  v7->tm_year = v10;
  v11 = dword_9137DC;
  v7->tm_yday = v9 / 86400;
  v12 = v9 % 86400;
  if ( !v2 )
    v11 = dword_913810;
  tm_yday = v7->tm_yday;
  for ( i = 1; v11[i] < tm_yday; ++i )
    ;
  v15 = i - 1;
  v7->tm_mon = v15;
  v7->tm_mday = tm_yday - v11[v15];
  v7->tm_wday = (*Time / 86400 + 4) % 7;
  v7->tm_hour = v12 / 3600;
  v16 = v12 % 3600;
  v7->tm_min = v16 / 60;
  v7->tm_isdst = 0;
  v7->tm_sec = v16 % 60;
  return v7;
}
