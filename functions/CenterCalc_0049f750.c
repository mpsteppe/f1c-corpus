int __stdcall sub_49F750(int a1, int a2, _DWORD *a3, int a4)
{
  int result; // eax

  if ( a4 )
  {
    sub_5531F0(a1, &a4, &a1, 0);
    result = a4 / 2;
    *a3 = a2 - a4 / 2;
  }
  return result;
}
