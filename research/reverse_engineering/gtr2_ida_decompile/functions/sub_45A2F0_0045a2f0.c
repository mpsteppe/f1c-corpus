int sub_45A2F0()
{
  int result; // eax
  double v1; // st7
  int v2; // [esp+0h] [ebp-4h]

  result = 0;
  v2 = 0;
  do
  {
    v1 = (double)v2;
    v2 = ++result;
    flt_B685CC[result] = sin(v1 * 0.2243994752564138);
  }
  while ( result < 7 );
  flt_B685D0[result] = 1.0;
  flt_B685F0 = -flt_B685D0[0];
  flt_B685F4 = -flt_B685D4;
  flt_B685F8 = -flt_B685D8;
  flt_B685FC = -flt_B685DC;
  flt_B68600 = -flt_B685E0;
  flt_B68604 = -flt_B685E4;
  flt_B68608 = -flt_B685E8;
  return result;
}
