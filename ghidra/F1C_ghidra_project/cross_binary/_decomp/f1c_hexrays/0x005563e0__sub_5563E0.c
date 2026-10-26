// f1c  0x005563e0  size=82
int __thiscall sub_5563E0(_DWORD *this)
{
  int result; // eax
  LONG *v2; // edi
  DWORD *v3; // esi
  DWORD LowPart; // ecx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  result = *this;
  if ( *this )
  {
    result = this[13];
    v2 = this + 13;
    if ( !result )
    {
      result = this[12];
      v3 = this + 12;
      if ( !result )
      {
        if ( (this[18] & 1) != 0 )
        {
          result = QueryPerformanceCounter(&PerformanceCount);
          LowPart = PerformanceCount.LowPart;
          *v2 = PerformanceCount.HighPart;
          *v3 = LowPart;
        }
        else
        {
          return sub_55687B(this + 13, this + 12);
        }
      }
    }
  }
  return result;
}
