CHAR *__thiscall sub_4AD7F0(_DWORD *this)
{
  int v1; // eax
  CHAR *result; // eax

  v1 = this[6];
  if ( !v1 || !*(_DWORD *)(v1 + 60) )
    return 0;
  result = *(CHAR **)(*(_DWORD *)(v1 + 68) + 36);
  if ( !result )
    return &byte_629120;
  return result;
}
