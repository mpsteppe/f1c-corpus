char __thiscall sub_45C720(const char *this, const char *a2)
{
  int v2; // edi
  const char *i; // ebp
  char result; // al

  v2 = 0;
  for ( i = this + 68; strcmp(i, a2); i += 140 )
  {
    if ( ++v2 >= 8 )
      return 0;
  }
  result = 1;
  *(float *)&this[140 * v2 + 200] = 5.0;
  return result;
}
