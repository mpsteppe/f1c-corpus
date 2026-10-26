char *__thiscall sub_4862E0(_DWORD *this)
{
  int v1; // eax
  char *result; // eax

  v1 = this[50];
  if ( !v1 )
    return 0;
  result = *(char **)(v1 + 72);
  if ( !result )
    return byte_5EA438;
  return result;
}

