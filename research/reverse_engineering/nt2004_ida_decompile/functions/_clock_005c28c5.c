clock_t __cdecl clock()
{
  struct _FILETIME SystemTimeAsFileTime; // [esp+4h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  return (SystemTimeAsFileTime.dwLowDateTime
        + ((unsigned __int64)SystemTimeAsFileTime.dwHighDateTime << 32)
        - qword_7FF170)
       / 0x2710;
}
