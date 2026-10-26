int __fastcall sub_409050(float *a1, float *a2)
{
  _BYTE v4[36]; // [esp+4h] [ebp-24h] BYREF

  *a1 = *a1 * -1.0;
  a1[1] = a1[1] * -1.0;
  a1[2] = a1[2] * -1.0;
  *a2 = *a2 * -1.0;
  a2[1] = a2[1] * -1.0;
  a2[2] = a2[2] * -1.0;
  sub_579100(a2, v4);
  return sub_579C10(3.1415927, (int)a2);
}
