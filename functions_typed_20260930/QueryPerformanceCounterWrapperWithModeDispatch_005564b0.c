int __thiscall sub_5564B0(_DWORD *this, LONG *a2, DWORD *a3)
{
  int v3; // eax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  if ( *this )
  {
    v3 = this[18];
    if ( (v3 & 1) != 0 )
    {
      QueryPerformanceCounter(&PerformanceCount);
      *a2 = PerformanceCount.HighPart;
      *a3 = PerformanceCount.LowPart;
      return 0;
    }
    if ( (v3 & 2) != 0 )
      RDTSCTimestampRead(a2, a3);
  }
  return 0;
}

