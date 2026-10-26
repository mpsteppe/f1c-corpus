char *__thiscall sub_41D840(char *this, const char *a2)
{
  char *v2; // edi

  v2 = this + 12;
  if ( strlen(a2) > 0x1000 )
  {
    sub_630FE0(this + 12, a2, 4096);
    return v2;
  }
  if ( sub_41F7F0(a2, this + 12) )
  {
    if ( a2 )
    {
      strcpy(v2, a2);
      return v2;
    }
    *v2 = 0;
  }
  return v2;
}
