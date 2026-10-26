double __cdecl sub_591BF1(int a1, int a2, int a3, int a4, int a5, int a6, double a7, int a8)
{
  if ( IDToValueTableLookupInConstantTable(a2) )
  {
    ReturnFPUControlWord(a8, 0xFFFF);
    if ( !StubReturning0() )
      SetErrorCodeBasedOnInputRange(a1);
    return a7;
  }
  else
  {
    ReturnFPUControlWord(a8, 0xFFFF);
    SetErrorCodeBasedOnInputRange(a1);
    return a7;
  }
}

