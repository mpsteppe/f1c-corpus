int __thiscall sub_581860(int *this, char *String1)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( *this <= 0 )
    return 0;
  for ( i = 0; _strcmpi(String1, *(const char **)(i + this[1])); i += 580 )
  {
    if ( ++v3 >= *this )
      return 0;
  }
  return this[1] + 580 * v3;
}
