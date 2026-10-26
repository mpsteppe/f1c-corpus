int __thiscall sub_4A6040(_DWORD *this)
{
  const char *v2; // eax
  int result; // eax
  char Destination[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v5; // [esp+45h] [ebp-3h]
  char v6; // [esp+47h] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v5 = 0;
  v6 = 0;
  v2 = (const char *)this[42];
  if ( !v2 )
    v2 = &byte_629120;
  strncpy(Destination, v2, 0x3Fu);
  v6 = 0;
  if ( !_strcmpi(Destination, asc_6087A8) )
    this[68] = 0;
  if ( !_strcmpi(Destination, aC_3) )
    this[68] = 1;
  result = _strcmpi(Destination, aR);
  if ( !result )
    this[68] = 2;
  return result;
}
