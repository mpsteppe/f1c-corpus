// positive sp value has been detected, the output may be wrong!
int sub_47EE5C()
{
  _BYTE v1[36]; // [esp-2Ch] [ebp-50h] BYREF
  _BYTE v2[32]; // [esp+4h] [ebp-20h] BYREF

  qmemcpy(v1, &unk_7D0A30, sizeof(v1));
  StringFormatWithBufferOverflowCheck(v2, aD_1);
  ConditionalCallWrapper((int)v2);
  return 0;
}
