int __thiscall sub_5AC740(int *this, int a2)
{
  int result; // eax
  LONG HighPart; // edx
  int *v5; // edi
  int *v6; // ebx
  int v7; // edi
  int v8; // ebx
  LARGE_INTEGER PerformanceCount; // [esp+10h] [ebp-8h] BYREF

  result = *this;
  if ( *this )
  {
    if ( (this[18] & 1) != 0 )
    {
      result = QueryPerformanceCounter(&PerformanceCount);
      HighPart = PerformanceCount.HighPart;
      v5 = this + 6;
      v6 = this + 7;
      this[6] = PerformanceCount.LowPart;
      this[7] = HighPart;
    }
    else
    {
      v5 = this + 6;
      v6 = this + 7;
      result = sub_5AE03B(this + 7, this + 6);
    }
    v7 = *v5;
    v8 = *v6;
    this[8] = v7;
    this[9] = v8;
    this[10] = 0;
    this[11] = 0;
    this[4] = 0;
    this[5] = 0;
    if ( a2 )
    {
      this[12] = v7;
      this[13] = v8;
    }
    else
    {
      this[12] = 0;
      this[13] = 0;
    }
  }
  return result;
}
