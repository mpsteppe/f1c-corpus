char *__cdecl _cfltcvt(double *a1, char *Src, int a3, size_t Size, int a5)
{
  if ( a3 == 101 || a3 == 69 )
    return (char *)_cftoe(a1, (int)Src, Size, a5);
  if ( a3 == 102 )
    return _cftof(a1, Src, Size);
  return _cftog(a1, Src, Size, a5);
}
