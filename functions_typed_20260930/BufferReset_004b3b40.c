char *__thiscall sub_4B3B40(char **this)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // edx
  char *result; // eax

  if ( this[110594] != this[110593] )
  {
    do
    {
      sub_4B3400(this[110594]);
      v2 = this[110593];
      v3 = (int)(this[110594] + 432);
      v4 = (int)(*this - 1);
      this[110594] = (char *)v3;
      *this = (char *)v4;
    }
    while ( (char *)v3 != v2 );
  }
  result = (char *)(this + 1);
  this[110595] = (char *)(this + 1);
  this[110594] = (char *)(this + 1);
  this[110593] = (char *)(this + 1);
  return result;
}

