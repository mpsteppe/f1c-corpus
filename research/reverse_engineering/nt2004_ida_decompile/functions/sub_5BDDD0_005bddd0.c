int __thiscall sub_5BDDD0(_BYTE *this)
{
  DWORD v2; // esi
  __time32_t v3; // edi
  int v4; // edi
  DWORD TickCount; // eax
  int result; // eax
  int i; // esi
  LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-48h] BYREF
  char v9[64]; // [esp+14h] [ebp-40h] BYREF

  strcpy(v9, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  if ( QueryPerformanceCounter(&PerformanceCount) )
    v2 = PerformanceCount.LowPart ^ PerformanceCount.HighPart;
  else
    v2 = 0;
  v3 = time(0);
  v4 = clock() ^ v3;
  TickCount = GetTickCount();
  result = sub_5BDE70(v2 ^ TickCount ^ v4);
  for ( i = 0; i < 19; ++i )
  {
    if ( i == 4 || i == 9 || i == 14 )
    {
      this[i] = 45;
    }
    else
    {
      result = sub_5BDE90(0, 62);
      this[i] = v9[result];
    }
  }
  this[19] = 0;
  return result;
}
