int __thiscall sub_6133A0(int this, char *String2, int a3, int a4, int a5, int a6)
{
  int result; // eax

  if ( !sub_613120((const char **)this, String2) )
    return 0;
  if ( a6 )
    return off_16C9378(String2, a3, a4, a5, a6);
  if ( a5 )
    return sscanf(*(const char *const *)(this + 512), "(%d,%d,%d)", a3, a4, a5) == 3;
  if ( a4 )
    return sscanf(*(const char *const *)(this + 512), "(%d,%d)", a3, a4) == 2;
  if ( !a3 )
    return 0;
  result = sscanf(*(const char *const *)(this + 512), "(%d)", a3) == 1;
  if ( !result )
    return sscanf(*(const char *const *)(this + 512), "%d", a3) == 1;
  return result;
}
