// f1c  0x004862c0  size=26
char *__thiscall sub_4862C0(_DWORD *this)
{
  int v1; // eax
  char *result; // eax

  v1 = this[50];
  if ( !v1 )
    return 0;
  result = *(char **)(v1 + 64);
  if ( !result )
    return byte_5EA438;
  return result;
}
