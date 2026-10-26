BOOL __thiscall sub_5B1D20(const char **this, char *String2)
{
  char *v3; // edi
  char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char *v7; // eax
  char *v9; // eax

  v3 = (char *)(this + 259);
  v4 = (char *)(this + 3);
  do
  {
    v5 = *v4;
    v4[1024] = *v4;
    ++v4;
  }
  while ( v5 );
  v6 = strtok(v3, Delimiter);
  this[515] = v6;
  if ( !v6 )
    return 0;
  while ( _strcmpi(this[515], String2) )
  {
    this[515] = strtok(0, word_5FBEBC);
    v7 = strtok(0, Delimiter);
    this[515] = v7;
    if ( !v7 )
      return 0;
  }
  v9 = strtok(0, word_5FBEBC);
  this[515] = v9;
  return v9 != 0;
}
