int __stdcall sub_57A9D0(_DWORD *a1)
{
  int result; // eax

  if ( a1 )
  {
    sub_57A9D0(a1[1]);
    sub_57A9D0(a1[2]);
    sub_57A690(a1);
    return sub_5BE8AE();
  }
  return result;
}
