int __thiscall sub_45CDE0(void *this, int a2)
{
  _BYTE v4[8]; // [esp+Ch] [ebp-8h] BYREF

  ShortComputation_ce30(this);
  v4[0] = 0;
  StringFormatWithBufferOverflowCheck(v4, "%1.3f", 1.026);
  return ShortComputation_ce30(this);
}

