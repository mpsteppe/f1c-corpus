void __cdecl __security_init_cookie()
{
  DWORD v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [esp+8h] [ebp-8h] BYREF

  if ( !dword_912B08 || dword_912B08 == -1153374642 )
  {
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v0 = SystemTimeAsFileTime.dwLowDateTime ^ SystemTimeAsFileTime.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(&PerformanceCount);
    dword_912B08 = PerformanceCount.LowPart ^ PerformanceCount.HighPart ^ v3;
    if ( !dword_912B08 )
      dword_912B08 = -1153374642;
  }
}
