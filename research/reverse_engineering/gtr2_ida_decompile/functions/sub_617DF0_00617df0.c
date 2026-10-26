int __thiscall sub_617DF0(double *this, int a2)
{
  LONG HighPart; // eax
  DWORD LowPart; // ecx
  double v5; // st7
  int v6; // edx
  bool v7; // sf
  int result; // eax
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
  v5 = (double)*(int *)this;
  v6 = *((_DWORD *)this + 6);
  v7 = *(int *)this < 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  result = *((_DWORD *)this + 7);
  *((_DWORD *)this + 8) = v6;
  *((_DWORD *)this + 9) = result;
  if ( v7 )
    v5 = v5 + 4294967296.0;
  *((_DWORD *)this + 18) = a2;
  this[1] = 4294967296.0 / v5;
  this[2] = 0.0;
  return result;
}
