int __thiscall sub_4FE790(float *this)
{
  char Buffer; // [esp+7h] [ebp-E5h] BYREF
  float v4[57]; // [esp+8h] [ebp-E4h] BYREF

  Buffer = 0;
  sub_4FEA10(&Buffer, 1u);
  sub_44A630((int)&dbl_75E930, v4);
  this[2] = v4[0];
  return sub_4FEA10(v4, 0xE4u);
}
