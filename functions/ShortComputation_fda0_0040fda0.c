char *__thiscall sub_40FDA0(char *this, char a2)
{
  char *v2; // esi

  v2 = this;
  if ( (a2 & 2) != 0 )
    v2 = this - 4;
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(v2);
  return v2;
}
