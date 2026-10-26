LONG __thiscall sub_5AC620(LONG *this)
{
  LONG *v2; // edi
  LONG result; // eax
  DWORD LowPart; // ecx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  if ( *this )
  {
    v2 = this + 13;
    if ( !this[13] || (result = this[12]) == 0 )
    {
      if ( (this[18] & 1) != 0 )
      {
        result = QueryPerformanceCounter(&PerformanceCount);
        LowPart = PerformanceCount.LowPart;
        *v2 = PerformanceCount.HighPart;
        this[12] = LowPart;
      }
      else
      {
        return sub_5AE03B(v2, this + 12);
      }
    }
  }
  return result;
}
