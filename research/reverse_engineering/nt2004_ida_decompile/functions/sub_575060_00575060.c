char *__thiscall sub_575060(char *this, char *Source)
{
  char *result; // eax
  char *v3; // esi

  result = Source;
  v3 = this + 100;
  this[100] = 0;
  if ( Source )
  {
    result = strncpy(this + 100, Source, 0x10u);
    v3[16] = 0;
  }
  return result;
}
