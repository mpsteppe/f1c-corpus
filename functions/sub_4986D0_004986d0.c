int __stdcall sub_4986D0(int a1)
{
  int result; // eax
  CHAR Text[128]; // [esp+0h] [ebp-80h] BYREF

  result = a1;
  if ( a1 )
  {
    sub_587DD0(Text, a1, 127);
    Text[127] = 0;
    MessageBoxA(0, Text, aOptionsError, 0);
    return UtilityFunction_9ca4(1u);
  }
  return result;
}
