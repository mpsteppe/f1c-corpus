int __thiscall sub_556440(int *this)
{
  int result; // eax
  LONG HighPart; // edx
  int *v4; // edi
  int *v5; // ebx
  int v6; // ecx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  result = *this;
  if ( *this )
  {
    if ( (this[18] & 1) != 0 )
    {
      QueryPerformanceCounter(&PerformanceCount);
      HighPart = PerformanceCount.HighPart;
      v4 = this + 6;
      v5 = this + 7;
      this[6] = PerformanceCount.LowPart;
      this[7] = HighPart;
    }
    else
    {
      v4 = this + 6;
      v5 = this + 7;
      RDTSCTimestampRead(this + 7, this + 6);
    }
    result = *v4;
    v6 = *v5;
    this[12] = 0;
    this[13] = 0;
    this[10] = 0;
    this[11] = 0;
    this[8] = result;
    this[9] = v6;
    this[4] = 0;
    this[5] = 0;
  }
  return result;
}

