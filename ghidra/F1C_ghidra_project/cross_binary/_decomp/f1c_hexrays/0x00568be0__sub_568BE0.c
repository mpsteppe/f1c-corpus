// f1c  0x00568be0  size=122
int __thiscall sub_568BE0(double *this, unsigned int a2)
{
  LONG HighPart; // eax
  DWORD LowPart; // ecx
  int result; // eax
  double QuadPart; // st7
  unsigned int v7; // ecx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-10h] BYREF
  LARGE_INTEGER Frequency; // [esp+10h] [ebp-8h] BYREF

  if ( a2 == 1 && QueryPerformanceFrequency(&Frequency) )
  {
    QueryPerformanceCounter(&PerformanceCount);
    HighPart = PerformanceCount.HighPart;
    LowPart = Frequency.LowPart;
    *((_DWORD *)this + 6) = PerformanceCount.LowPart;
    *((_DWORD *)this + 7) = HighPart;
    *(_DWORD *)this = LowPart;
  }
  result = 0;
  *((_DWORD *)this + 8) = *((_DWORD *)this + 6);
  PerformanceCount.QuadPart = *(unsigned int *)this;
  QuadPart = (double)PerformanceCount.QuadPart;
  v7 = *((_DWORD *)this + 7);
  *((_DWORD *)this + 18) = a2;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 9) = v7;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  this[1] = 4294967296.0 / QuadPart;
  return result;
}
