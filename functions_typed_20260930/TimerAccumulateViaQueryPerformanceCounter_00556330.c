int __thiscall sub_556330(_DWORD *this)
{
  int result; // eax
  unsigned int v3; // eax
  int v4; // eax
  LARGE_INTEGER v5; // [esp+4h] [ebp-14h] BYREF
  unsigned int v6; // [esp+Ch] [ebp-Ch]
  LARGE_INTEGER PerformanceCount; // [esp+10h] [ebp-8h] BYREF

  if ( *this )
  {
    result = this[13];
    if ( result )
    {
      result = this[12];
      if ( result )
      {
        if ( (this[18] & 1) != 0 )
        {
          QueryPerformanceCounter(&PerformanceCount);
          v5 = PerformanceCount;
        }
        else
        {
          RDTSCTimestampRead((char *)&v5.QuadPart + 4, &v5);
        }
        v3 = this[13];
        PerformanceCount.LowPart = this[12];
        v6 = v3;
        v5.QuadPart -= __PAIR64__(v3, PerformanceCount.LowPart);
        v4 = this[11];
        this[10] += v5.LowPart;
        result = v5.HighPart + v4;
        this[11] = result;
        this[12] = 0;
        this[13] = 0;
      }
    }
  }
  return result;
}

