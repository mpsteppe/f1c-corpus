char *__cdecl _cfltcvt(_DWORD *a1, char *a2, int a3, size_t Size, int a5)
{
  if ( a3 == 101 || a3 == 69 )
    return _cftoe(a1, a2, Size, a5);
  if ( a3 == 102 )
    return _cftof(a1, a2, Size);
  return _cftog(a1, a2, Size, a5);
}
