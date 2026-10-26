int *__cdecl _dosmaperr(unsigned int a1)
{
  int v1; // esi
  void (__noreturn **v2)(); // eax
  int *result; // eax

  v1 = 0;
  *__doserrno() = a1;
  v2 = (void (__noreturn **)())&unk_625278;
  do
  {
    if ( (void (__noreturn *)())a1 == *v2 )
    {
      result = _errno();
      *result = dword_62527C[2 * v1];
      return result;
    }
    v2 += 2;
    ++v1;
  }
  while ( (int)v2 < (int)off_6253E0 );
  if ( a1 < 0x13 || a1 > 0x24 )
  {
    if ( a1 < 0xBC || a1 > 0xCA )
    {
      result = _errno();
      *result = 22;
    }
    else
    {
      result = _errno();
      *result = 8;
    }
  }
  else
  {
    result = _errno();
    *result = 13;
  }
  return result;
}
