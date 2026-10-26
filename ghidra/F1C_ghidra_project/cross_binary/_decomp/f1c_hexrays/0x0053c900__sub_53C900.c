// f1c  0x0053c900  size=192
CHAR *__thiscall sub_53C900(void *this, CHAR *a2)
{
  CHAR *result; // eax
  CHAR v3; // cl
  int v4; // edi
  const char *i; // ebp
  CHAR SrcStr[256]; // [esp+4h] [ebp-100h] BYREF

  result = a2;
  if ( *a2 )
  {
    do
    {
      v3 = *result;
      result[SrcStr - a2] = *result;
      ++result;
    }
    while ( v3 );
    sub_589901(SrcStr);
    v4 = 0;
    if ( dword_8B8E30 > 0 )
    {
      for ( i = byte_8B5A3C; strcmp(SrcStr, i); i += 132 )
      {
        if ( ++v4 >= dword_8B8E30 )
          return (CHAR *)sub_53CA00(this);
      }
      dword_8B5A38[33 * v4] |= 0x400u;
    }
    return (CHAR *)sub_53CA00(this);
  }
  return result;
}
