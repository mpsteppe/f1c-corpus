// f1c  0x004d1410  size=64
char *__thiscall sub_4D1410(_DWORD *this, int a2)
{
  char *result; // eax

  if ( !this[107] )
    sub_4D12C0(this);
  if ( a2 < 0 || a2 >= this[106] )
    return 0;
  result = *(char **)(this[107] + 8 * a2);
  if ( !result )
    return byte_5EA438;
  return result;
}
