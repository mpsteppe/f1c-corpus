unsigned int __thiscall sub_45D0D0(char *this, int a2)
{
  unsigned int v3; // kr04_4
  char v5[16]; // [esp+8h] [ebp-10h] BYREF

  v5[0] = 0;
  v3 = strlen((const char *)ConstantOffsetAccessor(0)) + 1;
  StringFormatWithBufferOverflowCheck(v5, "%d", v3 != 1);
  return ShortComputation_ce30(aPassword_0, v5, this);
}
