double __stdcall sub_556760(int a1)
{
  if ( a1 + 32 >= dword_8B8E48 + 32 )
    return 0.0;
  else
    return HighResolutionTimerDeltaCalculation((double *)&dword_8B6C28[19 * a1 + 608]);
}
