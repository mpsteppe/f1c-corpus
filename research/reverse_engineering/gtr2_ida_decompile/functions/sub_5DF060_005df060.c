int __thiscall sub_5DF060(_DWORD *this, char *String2, char *a3)
{
  _DWORD *v4; // edi
  char *v5; // eax
  char v6; // cl
  const char *v7; // eax
  const char *v8; // eax

  v4 = this + 259;
  v5 = (char *)(this + 3);
  do
  {
    v6 = *v5;
    v5[1024] = *v5;
    ++v5;
  }
  while ( v6 );
  v7 = (const char *)sub_6331DF(v4, "=");
  this[515] = v7;
  if ( !v7 )
    return 0;
  if ( _stricmp(v7, String2) )
    return 0;
  v8 = (const char *)sub_6331DF(0, &word_6F6668);
  this[515] = v8;
  if ( !v8 )
    return 0;
  strcpy(a3, v8);
  return 1;
}
