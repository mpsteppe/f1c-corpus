// f1c  0x00462e00  size=19
char *__thiscall sub_462E00(void *this)
{
  char *result; // eax

  result = *(char **)(*(_DWORD *)this + 188);
  if ( !result )
    return byte_5EA438;
  return result;
}
