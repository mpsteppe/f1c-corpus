_DWORD *__thiscall sub_485420(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx
  const char *v3; // eax
  char Destination[64]; // [esp+4h] [ebp-40h] BYREF

  result = (_DWORD *)this[210];
  if ( result )
  {
    v2 = this[211];
    if ( *result <= v2 )
    {
      if ( *result < this[212] )
        *result = v2;
    }
    else
    {
      *result = this[212];
    }
    v3 = (const char *)sub_49D690(*(_DWORD *)this[210]);
    strncpy(Destination, v3, 0x3Fu);
    Destination[63] = 0;
    return (_DWORD *)sub_4A1AC0(Destination);
  }
  return result;
}
