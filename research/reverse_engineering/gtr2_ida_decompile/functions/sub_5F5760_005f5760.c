int __thiscall sub_5F5760(double *this, LONG *a2, DWORD *a3, int a4)
{
  int v5; // eax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // kr00_8
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-10h] BYREF
  LARGE_INTEGER Frequency; // [esp+10h] [ebp-8h] BYREF
  float v13; // [esp+20h] [ebp+8h]

  v5 = *(_DWORD *)this;
  if ( a4 )
    LOBYTE(v5) = a4;
  if ( (v5 & 1) != 0 )
  {
    if ( QueryPerformanceFrequency(&Frequency) )
      this[1] = 1.0 / ((double)Frequency.HighPart * 4294967296.0 + (double)Frequency.LowPart);
    QueryPerformanceCounter(&PerformanceCount);
    *a3 = PerformanceCount.LowPart;
    LODWORD(v7) = PerformanceCount.HighPart;
    *a2 = PerformanceCount.HighPart;
    if ( *a3 < *((_DWORD *)this + 22) && (unsigned int)v7 <= *((_DWORD *)this + 23) )
    {
      LODWORD(v7) = dword_FB2774;
      if ( dword_FB2774 )
      {
        v13 = this[1] / (1.0 / ((double)*((int *)dword_FB2774 + 66) * 1000000.0));
        v8 = __rdtsc();
        *a3 = (unsigned __int64)((double)(unsigned int)v8 * v13);
        v7 = (unsigned __int64)((double)HIDWORD(v8) * v13);
        *a2 = v7;
      }
    }
    *((_DWORD *)this + 22) = *a3;
    *((_DWORD *)this + 23) = *a2;
  }
  else
  {
    v7 = __rdtsc();
    *(_QWORD *)a3 = v7;
  }
  return v7;
}
