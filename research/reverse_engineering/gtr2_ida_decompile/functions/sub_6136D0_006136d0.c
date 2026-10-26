BOOL __thiscall sub_6136D0(int this, char *String2, int a3, int a4, int a5, int a6)
{
  BOOL result; // eax

  if ( !sub_613120((const char **)this, String2) )
    return 0;
  if ( a6 )
    return sscanf(*(const char *const *)(this + 512), "(%lf,%lf,%lf,%lf)", a3, a4, a5, a6) == 4;
  if ( a5 )
    return sscanf(*(const char *const *)(this + 512), "(%lf,%lf,%lf)", a3, a4, a5) == 3;
  if ( a4 )
    return sscanf(*(const char *const *)(this + 512), "(%lf,%lf)", a3, a4) == 2;
  if ( !a3 )
    return 0;
  result = sscanf(*(const char *const *)(this + 512), "(%lf)", a3) == 1;
  if ( !result )
    return sscanf(*(const char *const *)(this + 512), off_720734, a3) == 1;
  return result;
}
