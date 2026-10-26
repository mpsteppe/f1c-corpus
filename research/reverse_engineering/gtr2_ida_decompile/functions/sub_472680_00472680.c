char __thiscall sub_472680(const char *this, const char *a2)
{
  int v2; // edi
  const char *i; // ebp

  v2 = 0;
  for ( i = this + 68; strcmp(i, a2); i += 92 )
  {
    if ( ++v2 >= 8 )
      return 0;
  }
  *(_DWORD *)&this[92 * v2 + 152] = 1084227584;
  return 1;
}
