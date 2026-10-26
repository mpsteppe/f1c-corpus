int __stdcall sub_53D260(const char *a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax

  result = sub_53D1F0(a1);
  if ( result )
  {
    sub_552FC0(a2);
    sub_552FD0(a3, a4);
    return sub_552FF0(a5, a6);
  }
  return result;
}
