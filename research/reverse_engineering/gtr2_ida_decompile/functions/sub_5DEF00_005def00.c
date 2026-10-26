BOOL __thiscall sub_5DEF00(_DWORD *this, char *String2)
{
  _DWORD *v3; // edi
  char *v4; // eax
  char v5; // cl
  const char *v6; // eax
  int v7; // eax

  v3 = this + 259;
  v4 = (char *)(this + 3);
  do
  {
    v5 = *v4;
    v4[1024] = *v4;
    ++v4;
  }
  while ( v5 );
  v6 = (const char *)sub_6331DF(v3, "=");
  this[515] = v6;
  if ( !v6 || _stricmp(v6, String2) )
    return 0;
  v7 = sub_6331DF(0, WindowName);
  this[515] = v7;
  return v7 != 0;
}
