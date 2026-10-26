BOOL __thiscall sub_6134B0(int this, char *String2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  BOOL result; // eax

  if ( !sub_613120((const char **)this, String2) )
    return 0;
  if ( a10 )
    return sscanf(*(const char *const *)(this + 512), "(%f,%f,%f,%f,%f,%f,%f,%f)", a3, a4, a5, a6, a7, a8, a9, a10) == 8;
  if ( a9 )
    return sscanf(*(const char *const *)(this + 512), "(%f,%f,%f,%f,%f,%f,%f)", a3, a4, a5, a6, a7, a8, a9) == 7;
  if ( a8 )
    return sscanf(*(const char *const *)(this + 512), "(%f,%f,%f,%f,%f,%f)", a3, a4, a5, a6, a7, a8) == 6;
  if ( a7 )
    return sscanf(*(const char *const *)(this + 512), "(%f,%f,%f,%f,%f)", a3, a4, a5, a6, a7) == 5;
  if ( a6 )
    return sscanf(*(const char *const *)(this + 512), "(%f,%f,%f,%f)", a3, a4, a5, a6) == 4;
  if ( a5 )
    return sscanf(*(const char *const *)(this + 512), "(%f,%f,%f)", a3, a4, a5) == 3;
  if ( a4 )
    return sscanf(*(const char *const *)(this + 512), "(%f,%f)", a3, a4) == 2;
  if ( !a3 )
    return 0;
  result = sscanf(*(const char *const *)(this + 512), "(%f)", a3) == 1;
  if ( !result )
    return sscanf(*(const char *const *)(this + 512), "%f", a3) == 1;
  return result;
}
