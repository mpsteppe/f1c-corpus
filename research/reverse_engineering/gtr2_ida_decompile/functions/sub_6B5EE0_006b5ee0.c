int __stdcall sub_6B5EE0(_DWORD *a1)
{
  int result; // eax

  result = a1[1];
  if ( result )
  {
    (*(void (__stdcall **)(_DWORD *, int))(result + 36))(a1, 1);
    result = a1[4];
    if ( result )
    {
      a1[5] = 200;
      a1[77] = 0;
    }
    else
    {
      a1[5] = 100;
    }
  }
  return result;
}
