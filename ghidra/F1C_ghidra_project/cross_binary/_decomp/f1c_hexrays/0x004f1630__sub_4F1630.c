// f1c  0x004f1630  size=30
char *__thiscall sub_4F1630(int this)
{
  char *result; // eax

  result = *(char **)sub_4D7570(*(_DWORD **)(this + 14700), *(_DWORD *)(this + 14704));
  if ( !result )
    return byte_5EA438;
  return result;
}
