_DWORD *__thiscall sub_67EB04(_DWORD *this, int a2, int a3)
{
  DWORD dwPageSize; // ecx
  int v5; // eax
  int v6; // ecx
  struct _SYSTEM_INFO SystemInfo; // [esp+4h] [ebp-24h] BYREF

  *this = 0;
  GetSystemInfo(&SystemInfo);
  dwPageSize = SystemInfo.dwPageSize;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[1] = dwPageSize;
  v5 = ~(dwPageSize - 1) & (dwPageSize + a3 - 1);
  v6 = a2;
  this[1] = v5;
  if ( !a2 )
    v6 = 0x100000;
  this[5] = ~(v5 - 1) & (v5 + v6 - 1);
  return this;
}
