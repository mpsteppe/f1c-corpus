int __thiscall sub_617E70(double *this)
{
  int result; // eax
  LONG HighPart; // edx
  int v4; // ecx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  result = *(_DWORD *)this;
  if ( *(_DWORD *)this )
  {
    if ( ((_BYTE)this[9] & 1) != 0 )
    {
      QueryPerformanceCounter(&PerformanceCount);
      HighPart = PerformanceCount.HighPart;
      *((_DWORD *)this + 6) = PerformanceCount.LowPart;
      *((_DWORD *)this + 7) = HighPart;
    }
    result = *((_DWORD *)this + 6);
    v4 = *((_DWORD *)this + 7);
    this[2] = 0.0;
    *((_DWORD *)this + 12) = 0;
    *((_DWORD *)this + 13) = 0;
    *((_DWORD *)this + 10) = 0;
    *((_DWORD *)this + 11) = 0;
    *((_DWORD *)this + 8) = result;
    *((_DWORD *)this + 9) = v4;
  }
  return result;
}
