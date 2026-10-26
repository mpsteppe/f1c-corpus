int __stdcall sub_4E4750(int a1, int a2, _DWORD *a3, int a4)
{
  int result; // eax

  if ( a4 )
  {
    sub_5F0380(a1, &a4, &a1, 0);
    result = a4;
    *a3 = a2 - a4;
  }
  return result;
}
