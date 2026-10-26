int __thiscall sub_577E50(char *String, char *String2, char *a3)
{
  char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char *v7; // eax

  v4 = String + 408;
  do
  {
    v5 = *v4;
    *(v4 - 408) = *v4;
    ++v4;
  }
  while ( v5 );
  v6 = strtok(String, Delimiter);
  *((_DWORD *)String + 96) = v6;
  if ( !v6 )
    return 0;
  if ( _strcmpi(v6, String2) )
    return 0;
  v7 = strtok(0, word_5FD024);
  *((_DWORD *)String + 96) = v7;
  if ( !v7 )
    return 0;
  strcpy(a3, v7);
  return 1;
}
