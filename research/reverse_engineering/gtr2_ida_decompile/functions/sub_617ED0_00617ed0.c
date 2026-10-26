double __thiscall sub_617ED0(_DWORD *this)
{
  DWORD v2; // eax
  unsigned int v3; // ecx
  bool v4; // zf
  __int64 v5; // rax
  DWORD LowPart; // ecx
  unsigned int v7; // kr00_4
  unsigned __int64 v8; // kr08_8
  LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v11; // [esp+14h] [ebp-8h]
  DWORD v12; // [esp+18h] [ebp-4h]

  v2 = this[8];
  v3 = this[9];
  v12 = v2;
  v4 = *this == 0;
  v11 = v3;
  if ( v4 || (this[18] & 1) == 0 )
  {
    LowPart = v12;
    HIDWORD(v5) = v12;
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    HIDWORD(v5) = PerformanceCount.HighPart;
    LowPart = PerformanceCount.LowPart;
  }
  LODWORD(v5) = LowPart;
  v8 = v5 - __PAIR64__(v11, v12);
  PerformanceCount.LowPart = HIDWORD(v8);
  v7 = v8;
  *((_QWORD *)this + 4) = __PAIR64__(HIDWORD(v5), LowPart);
  return (double)v7 / (double)(unsigned int)*this + (double)PerformanceCount.LowPart * *((double *)this + 1);
}
