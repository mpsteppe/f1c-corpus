char *__thiscall sub_4D1940(char **this)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // edx
  char *result; // eax

  if ( this[53250] != this[53249] )
  {
    do
    {
      sub_4D0D50(this[53250]);
      v2 = this[53249];
      v3 = (int)(this[53250] + 208);
      v4 = (int)(*this - 1);
      this[53250] = (char *)v3;
      *this = (char *)v4;
    }
    while ( (char *)v3 != v2 );
  }
  result = (char *)(this + 1);
  this[53251] = (char *)(this + 1);
  this[53250] = (char *)(this + 1);
  this[53249] = (char *)(this + 1);
  return result;
}
