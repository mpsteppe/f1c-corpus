int __thiscall sub_6131C0(char *this, char *String2, char *a3)
{
  char *v4; // eax
  char v5; // cl
  const char *v6; // eax
  const char *v7; // eax

  v4 = this + 536;
  do
  {
    v5 = *v4;
    *(v4 - 536) = *v4;
    ++v4;
  }
  while ( v5 );
  v6 = (const char *)sub_6331DF(this, "=");
  *((_DWORD *)this + 128) = v6;
  if ( !v6 )
    return 0;
  if ( _stricmp(v6, String2) )
    return 0;
  v7 = (const char *)sub_6331DF(0, &word_6F6668);
  *((_DWORD *)this + 128) = v7;
  if ( !v7 )
    return 0;
  strcpy(a3, v7);
  return 1;
}
