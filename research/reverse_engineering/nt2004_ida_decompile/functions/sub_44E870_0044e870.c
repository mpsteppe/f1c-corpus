int sub_44E870()
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
    flt_761B6C[result] = sin(v1 * 0.2243994752564138);
  }
  while ( result < 7 );
  dword_761B70[result] = 1.0;
  return result;
}
