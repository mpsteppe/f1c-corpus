int __thiscall sub_57B6E0(_BYTE *this, LONG *a2, DWORD *a3)
{
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  if ( *(_DWORD *)this && (this[72] & 1) != 0 )
  {
    QueryPerformanceCounter(&PerformanceCount);
    *a2 = PerformanceCount.HighPart;
    *a3 = PerformanceCount.LowPart;
  }
  return 0;
}
