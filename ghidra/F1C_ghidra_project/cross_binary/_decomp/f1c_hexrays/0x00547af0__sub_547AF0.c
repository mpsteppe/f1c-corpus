// f1c  0x00547af0  size=65
int __thiscall sub_547AF0(const char *this)
{
  int v2; // edx

  v2 = 0;
  if ( !strlen(this) )
    return 0;
  while ( this[v2] != 46 )
  {
    if ( ++v2 >= strlen(this) )
      return 0;
  }
  this[v2] = 0;
  return 1;
}
