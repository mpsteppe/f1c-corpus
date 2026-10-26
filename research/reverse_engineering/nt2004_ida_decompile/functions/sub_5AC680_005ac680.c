unsigned int __thiscall sub_5AC680(_BYTE *this)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // eax
  unsigned int v6; // kr00_4
  _DWORD v7[7]; // [esp+4h] [ebp-24h] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+20h] [ebp-8h] BYREF

  if ( *(_DWORD *)this )
  {
    if ( *((_DWORD *)this + 13) || (result = *((_DWORD *)this + 12)) != 0 )
    {
      if ( (this[72] & 1) != 0 )
      {
        QueryPerformanceCounter(&PerformanceCount);
        *(LARGE_INTEGER *)v7 = PerformanceCount;
      }
      else
      {
        sub_5AE03B(&v7[1], v7);
      }
      v3 = *((_DWORD *)this + 12);
      PerformanceCount.LowPart = v7[0];
      v4 = *((_DWORD *)this + 13);
      v5 = *((_DWORD *)this + 10);
      *(_QWORD *)&v7[5] = __PAIR64__(v7[1], v3);
      v6 = v7[0] - v3 + v5;
      result = (*(_QWORD *)v7 - __PAIR64__(v4, v3) + __PAIR64__(*((_DWORD *)this + 11), v5)) >> 32;
      *((_QWORD *)this + 5) = __PAIR64__(result, v6);
      *((_DWORD *)this + 13) = 0;
      *((_DWORD *)this + 12) = 0;
    }
  }
  return result;
}
