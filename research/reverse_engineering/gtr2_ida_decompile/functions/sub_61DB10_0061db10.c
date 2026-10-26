int __thiscall sub_61DB10(int *this, char *String1)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( *this <= 0 )
    return 0;
  for ( i = 0; _stricmp(String1, *(const char **)(i + this[1])); i += 584 )
  {
    if ( ++v3 >= *this )
      return 0;
  }
  return this[1] + 584 * v3;
}
