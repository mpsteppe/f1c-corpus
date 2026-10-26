_DWORD *__cdecl sub_591C79(int a1)
{
  _DWORD *result; // eax

  result = (_DWORD *)a1;
  if ( a1 == 1 )
  {
    result = (_DWORD *)sub_58AFCF();
    *result = 33;
  }
  else if ( a1 > 1 && a1 <= 3 )
  {
    result = (_DWORD *)sub_58AFCF();
    *result = 34;
  }
  return result;
}
