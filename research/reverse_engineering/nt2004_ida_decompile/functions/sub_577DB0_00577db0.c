BOOL __thiscall sub_577DB0(char *String, char *String2)
{
  char *v3; // eax
  char v4; // cl
  char *v5; // eax
  char *v6; // eax
  char *v8; // eax

  v3 = String + 408;
  do
  {
    v4 = *v3;
    *(v3 - 408) = *v3;
    ++v3;
  }
  while ( v4 );
  v5 = strtok(String, Delimiter);
  *((_DWORD *)String + 96) = v5;
  if ( !v5 )
    return 0;
  while ( _strcmpi(*((const char **)String + 96), String2) )
  {
    *((_DWORD *)String + 96) = strtok(0, word_5FBEBC);
    v6 = strtok(0, Delimiter);
    *((_DWORD *)String + 96) = v6;
    if ( !v6 )
      return 0;
  }
  v8 = strtok(0, word_5FBEBC);
  *((_DWORD *)String + 96) = v8;
  return v8 != 0;
}
