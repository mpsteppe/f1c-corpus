// f1c  0x00433370  size=99
_BYTE *__thiscall sub_433370(char **this, const char *a2, int a3, _BYTE *a4)
{
  _BYTE *result; // eax

  sub_433290(this + 2, a2, a3);
  if ( byte_7C56C0 )
  {
    if ( (int)strlen(a2) < a3 - 1 )
      *(_WORD *)&a2[strlen(a2)] = word_5C406C;
    result = a4;
    if ( a4 )
      *a4 = 1;
  }
  else
  {
    result = a4;
    if ( a4 )
      *a4 = 0;
  }
  return result;
}
