// f1c  0x0044c430  size=49
int sub_44C430()
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
    flt_7CA384[result] = sin(v1 * 0.2243994752564138);
  }
  while ( result < 7 );
  dword_7CA388[result] = 1.0;
  return result;
}
