int __thiscall sub_556260(double *this, unsigned int a2)
{
  LONG HighPart; // eax
  DWORD LowPart; // ecx
  int result; // eax
  double QuadPart; // st7
  unsigned int v7; // edx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-B0h] BYREF
  LARGE_INTEGER Frequency; // [esp+10h] [ebp-A8h] BYREF
  _BYTE v10[40]; // [esp+18h] [ebp-A0h] BYREF
  int v11; // [esp+40h] [ebp-78h]

  if ( a2 == 1 )
  {
    if ( QueryPerformanceFrequency(&Frequency) )
    {
      QueryPerformanceCounter(&PerformanceCount);
      HighPart = PerformanceCount.HighPart;
      LowPart = Frequency.LowPart;
      *((_DWORD *)this + 6) = PerformanceCount.LowPart;
      *((_DWORD *)this + 7) = HighPart;
      *(_DWORD *)this = LowPart;
    }
  }
  else if ( a2 == 2 )
  {
    StructZeroInitConstructor_f080(v10);
    GlobalDataCopy(v10);
    RDTSCTimestampRead((char *)this + 28, this + 3);
    *(_DWORD *)this = 1000000 * v11;
    EmptyStub_7470(v10);
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

