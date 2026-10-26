int *__cdecl sub_63EC68(int a1)
{
  int *result; // eax

  result = (int *)a1;
  if ( a1 == 1 )
  {
    result = _errno();
    *result = 33;
  }
  else if ( a1 > 1 && a1 <= 3 )
  {
    _errno();
    return (int *)off_16C94F8();
  }
  return result;
}
