int __thiscall sub_4D5960(float *this)
{
  char v3; // [esp+7h] [ebp-E5h] BYREF
  float v4[57]; // [esp+8h] [ebp-E4h] BYREF

  v3 = 0;
  sub_4D5BE0(&v3, 1);
  if ( dword_5C753C() )
  {
    dword_7C8314 = 1072168960;
    dword_7C8310 = 0;
  }
  sub_447F30(&dbl_7C7428, v4);
  this[2] = v4[0];
  return sub_4D5BE0(v4, 228);
}
