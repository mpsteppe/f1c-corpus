_DWORD *__cdecl sub_591C79(int a1)
{
  _DWORD *result; // eax

  result = (_DWORD *)a1;
  if ( a1 == 1 )
  {
    result = (_DWORD *)TLSOffsetGetter();
    *result = 33;
  }
  else if ( a1 > 1 && a1 <= 3 )
  {
    result = (_DWORD *)TLSOffsetGetter();
    *result = 34;
  }
  return result;
}

