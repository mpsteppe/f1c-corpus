BOOL __thiscall sub_613120(const char **this, char *String2)
{
  char *v3; // eax
  char v4; // cl
  const char *v5; // eax
  const char *v6; // eax
  const char *v8; // eax

  v3 = (char *)(this + 134);
  do
  {
    v4 = *v3;
    *(v3 - 536) = *v3;
    ++v3;
  }
  while ( v4 );
  v5 = (const char *)sub_6331DF(this, "=");
  this[128] = v5;
  if ( !v5 )
    return 0;
  while ( _stricmp(this[128], String2) )
  {
    this[128] = (const char *)sub_6331DF(0, CommandLine);
    v6 = (const char *)sub_6331DF(0, "=");
    this[128] = v6;
    if ( !v6 )
      return 0;
  }
  v8 = (const char *)sub_6331DF(0, CommandLine);
  this[128] = v8;
  return v8 != 0;
}
