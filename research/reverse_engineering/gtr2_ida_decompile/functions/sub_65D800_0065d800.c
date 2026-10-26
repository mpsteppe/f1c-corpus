int __thiscall sub_65D800(
        const char **this,
        const char *a2,
        unsigned int a3,
        const char *a4,
        const char *a5,
        const char *a6,
        const char *a7)
{
  unsigned int v7; // eax

  if ( !a6 || !a7 )
    return -2147467259;
  v7 = a3;
  if ( a3 == -1 )
  {
    if ( a2 )
      v7 = strlen(a2);
    else
      v7 = 0;
  }
  if ( !a2 && v7 )
    return -2147467259;
  *this = a2;
  this[6] = a4;
  this[7] = a5;
  this[11] = a6;
  this[1] = &a2[v7];
  this[12] = a7;
  return 0;
}
