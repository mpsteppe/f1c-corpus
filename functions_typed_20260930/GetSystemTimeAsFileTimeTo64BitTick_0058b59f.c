unsigned __int64 GetSystemTimeAsFileTimeTo64BitTick()
{
  unsigned __int64 result; // rax
  struct _FILETIME SystemTimeAsFileTime; // [esp+4h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  result = SystemTimeAsFileTime.dwLowDateTime + Allmul(SystemTimeAsFileTime.dwHighDateTime, 0x100000000LL);
  qword_8D3EC0 = result;
  return result;
}

