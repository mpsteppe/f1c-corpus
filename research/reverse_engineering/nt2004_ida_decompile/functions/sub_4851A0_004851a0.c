_DWORD *__thiscall sub_4851A0(_DWORD *this)
{
  _DWORD *result; // eax
  const char *v3; // eax
  char Destination[64]; // [esp+4h] [ebp-40h] BYREF

  result = (_DWORD *)this[210];
  if ( result )
  {
    v3 = (const char *)sub_49D690(*result);
    strncpy(Destination, v3, 0x3Fu);
    Destination[63] = 0;
    sub_4A1AC0(Destination);
    result = (_DWORD *)dword_62A158;
    if ( *(_DWORD *)this[210] - 1 <= dword_62A158 )
      this[207] = 0;
    else
      this[207] = 2;
  }
  return result;
}
