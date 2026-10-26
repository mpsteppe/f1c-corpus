int __thiscall sub_57B690(_DWORD *this)
{
  LONG HighPart; // edx
  int result; // eax
  int v4; // ecx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  if ( *this )
  {
    if ( (this[18] & 1) != 0 )
    {
      QueryPerformanceCounter(&PerformanceCount);
      HighPart = PerformanceCount.HighPart;
      this[6] = PerformanceCount.LowPart;
      this[7] = HighPart;
    }
    result = this[6];
    v4 = this[7];
    this[12] = 0;
    this[13] = 0;
    this[10] = 0;
    this[11] = 0;
    this[8] = result;
    this[9] = v4;
    this[4] = 0;
    this[5] = 0;
  }
  return result;
}
