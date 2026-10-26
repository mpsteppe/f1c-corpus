int __stdcall sub_540DA0(_DWORD *a1, char a2)
{
  int result; // eax

  if ( a1 )
  {
    if ( (a2 & 4) != 0 )
    {
      result = ArithmeticComparison_0f90(a1[7]);
      a1[8] = 0;
    }
    if ( (a2 & 8) != 0 )
    {
      result = GuardedVirtualDecrement(a1[9]);
      a1[10] = 0;
    }
  }
  return result;
}
