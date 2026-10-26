_BYTE *__thiscall sub_436120(const char **this, char *Destination, int a3, _BYTE *a4)
{
  _BYTE *result; // eax

  sub_436040(this + 2, Destination, a3);
  if ( byte_75CBC8 )
  {
    if ( (int)strlen(Destination) < a3 - 1 )
      *(_WORD *)&Destination[strlen(Destination)] = *(_WORD *)asc_5FE194;
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
