int __thiscall sub_5AC5A0(double *this, int a2)
{
  LONG HighPart; // eax
  DWORD LowPart; // ecx
  int v5; // eax
  unsigned int v6; // edx
  int v7; // eax
  int result; // eax
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-10h] BYREF
  LARGE_INTEGER Frequency; // [esp+Ch] [ebp-8h] BYREF

  if ( QueryPerformanceFrequency(&Frequency) )
  {
    QueryPerformanceCounter(&PerformanceCount);
    HighPart = PerformanceCount.HighPart;
    LowPart = Frequency.LowPart;
    *((_DWORD *)this + 6) = PerformanceCount.LowPart;
    *((_DWORD *)this + 7) = HighPart;
    *(_DWORD *)this = LowPart;
  }
  v5 = *((_DWORD *)this + 6);
  v6 = *(_DWORD *)this;
  *((_DWORD *)this + 8) = v5;
  *((_DWORD *)this + 12) = v5;
  v7 = *((_DWORD *)this + 7);
  *((_DWORD *)this + 9) = v7;
  *((_DWORD *)this + 13) = v7;
  result = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 18) = 1;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  this[1] = 4294967296.0 / (double)v6;
  return result;
}
