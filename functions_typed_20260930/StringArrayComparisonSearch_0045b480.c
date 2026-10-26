char __thiscall sub_45B480(const char *this, const char *a2)
{
  int v2; // edi
  const char *i; // ebp
  char result; // al

  v2 = 0;
  for ( i = this + 60; strcmp(i, a2); i += 92 )
  {
    if ( ++v2 >= 8 )
      return 0;
  }
  result = 1;
  *(float *)&this[92 * v2 + 144] = 5.0;
  return result;
}

