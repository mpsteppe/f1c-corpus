double __thiscall sub_617F80(double *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx
  bool v5; // zf
  unsigned __int64 v6; // kr00_8
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-1Ch] BYREF
  LONG HighPart; // [esp+10h] [ebp-14h]
  unsigned int v10; // [esp+14h] [ebp-10h]
  unsigned int v11; // [esp+18h] [ebp-Ch]
  unsigned int v12; // [esp+1Ch] [ebp-8h]
  unsigned int v13; // [esp+20h] [ebp-4h]

  v2 = *((_DWORD *)this + 6);
  v3 = *((_DWORD *)this + 7);
  v4 = *((_DWORD *)this + 10);
  v13 = v2;
  v10 = *((_DWORD *)this + 11);
  v5 = *(_DWORD *)this == 0;
  v12 = v3;
  v11 = v4;
  if ( !v5 && ((_BYTE)this[9] & 1) != 0 )
  {
    QueryPerformanceCounter(&PerformanceCount);
    HighPart = PerformanceCount.HighPart;
  }
  v6 = __PAIR64__(HighPart, PerformanceCount.LowPart) - __PAIR64__(v12, v13) - __PAIR64__(v10, v11);
  PerformanceCount.LowPart = PerformanceCount.LowPart - v13 - v11;
  HighPart = HIDWORD(v6);
  return (double)PerformanceCount.LowPart / (double)*(unsigned int *)this + (double)HIDWORD(v6) * this[1] + this[2];
}
