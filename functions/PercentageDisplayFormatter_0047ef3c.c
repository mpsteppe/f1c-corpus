// positive sp value has been detected, the output may be wrong!
int sub_47EF3C()
{
  _BYTE v1[24]; // [esp-18h] [ebp-20h] BYREF

  StringFormatWithBufferOverflowCheck(v1, "%0.0f%%", flt_7D084C * 100.0);
  ConditionalCallWrapper((int)v1);
  return 0;
}
