// f1c  0x0047ee5c  size=56
// positive sp value has been detected, the output may be wrong!
int sub_47EE5C()
{
  _BYTE v1[36]; // [esp-2Ch] [ebp-50h] BYREF
  _BYTE v2[32]; // [esp+4h] [ebp-20h] BYREF

  qmemcpy(v1, &unk_7D0A30, sizeof(v1));
  sub_58815F(v2, aD_1);
  sub_47E940((int)v2);
  return 0;
}
