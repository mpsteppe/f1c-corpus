char *__thiscall sub_497980(_DWORD *this)
{
  int v1; // eax
  char *result; // eax

  v1 = this[6];
  if ( !v1 || !*(_DWORD *)(v1 + 72) )
    return 0;
  result = *(char **)(*(_DWORD *)(v1 + 80) + 52);
  if ( !result )
    return byte_5EA438;
  return result;
}
