int __thiscall sub_500EA0(int *this)
{
  int result; // eax
  const char *v3; // eax
  const char *v4; // eax
  char Buffer[256]; // [esp+4h] [ebp-100h] BYREF

  result = *this;
  if ( *this > 0 )
  {
    if ( result > 2 )
      *this = 2;
    if ( this[1] )
      return fprintf((FILE *const)this[1], "\nTRACE LEVEL = %d", *this);
    v3 = dword_62A0C8;
    if ( !dword_62A0C8 )
      v3 = &byte_629120;
    _mkdir(v3);
    v4 = dword_62A0C8;
    if ( !dword_62A0C8 )
      v4 = &byte_629120;
    sprintf(Buffer, "%strace.txt", v4);
    result = (int)fopen(Buffer, aW);
    this[1] = result;
    if ( result )
      return fprintf((FILE *const)this[1], "\nTRACE LEVEL = %d", *this);
    else
      *this = 0;
  }
  return result;
}
