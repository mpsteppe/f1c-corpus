int __thiscall sub_61DB70(int *this, char *String1)
{
  int v3; // edi
  int i; // ebx

  v3 = 0;
  if ( this[6] <= 0 )
    return 0;
  for ( i = 0; !*(_DWORD *)(i + this[7]) || _stricmp(String1, *(const char **)(i + this[7])); i += 80 )
  {
    if ( ++v3 >= this[6] )
      return 0;
  }
  return this[7] + 80 * v3;
}
