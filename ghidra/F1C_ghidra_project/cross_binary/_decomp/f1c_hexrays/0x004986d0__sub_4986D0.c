// f1c  0x004986d0  size=74
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
    return sub_589CA4(1u);
  }
  return result;
}
