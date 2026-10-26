char __thiscall sub_48CAD0(_BYTE *this, const char *a2)
{
  char result; // al

  if ( !strcmp(off_759F1C[0], a2) )
  {
    result = 1;
    this[596] = 1;
  }
  else
  {
    this[596] = 0;
    return 0;
  }
  return result;
}
