char *__thiscall sub_592030(void *this, char *a2)
{
  char *result; // eax
  char v3; // cl
  int v4; // edi
  const char *i; // ebp
  char String[256]; // [esp+4h] [ebp-100h] BYREF

  result = a2;
  if ( *a2 )
  {
    do
    {
      v3 = *result;
      result[String - a2] = *result;
      ++result;
    }
    while ( v3 );
    _strupr(String);
    v4 = 0;
    if ( dword_7E8D58 > 0 )
    {
      for ( i = byte_7E4CCC; strcmp(String, i); i += 132 )
      {
        if ( ++v4 >= dword_7E8D58 )
          return (char *)sub_592130(this);
      }
      dword_7E4CC8[33 * v4] |= 0x400u;
    }
    return (char *)sub_592130(this);
  }
  return result;
}
