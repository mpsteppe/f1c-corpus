char *__thiscall sub_566CC0(int *this, char *a2, int a3)
{
  if ( this[4] )
    return LineInputReader(*this, a2, a3);
  else
    return (char *)FileReadUntilNewline(a2, a3, *this);
}
