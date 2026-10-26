const char *__thiscall sub_4A55D0(_DWORD *this)
{
  const char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  const char *result; // eax
  const char *v6; // esi
  char Destination[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v8; // [esp+49h] [ebp-3h]
  char v9; // [esp+4Bh] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v8 = 0;
  v9 = 0;
  v2 = (const char *)this[42];
  if ( !v2 )
    v2 = &byte_629120;
  strncpy(Destination, v2, 0x3Fu);
  v9 = 0;
  v3 = strtok(Destination, word_5FBEBC);
  if ( v3 )
    this[97] = atoi(v3);
  v4 = strtok(0, word_5FBEBC);
  if ( v4 )
    this[96] = atoi(v4);
  result = strtok(0, word_5FBEBC);
  v6 = result;
  if ( result )
  {
    if ( !_strcmpi(result, asc_6087A8) )
      this[67] = 0;
    if ( !_strcmpi(v6, aC_3) )
      this[67] = 1;
    result = (const char *)_strcmpi(v6, aR);
    if ( !result )
      this[67] = 2;
  }
  return result;
}
