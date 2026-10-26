int __thiscall sub_435F50(const CHAR **this, _DWORD *a2)
{
  int result; // eax
  const CHAR *v4; // eax
  const CHAR *v5; // eax
  const CHAR *v6; // edi

  result = 1;
  if ( a2 && a2[1] )
  {
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "%s\n", off_757C4C[0]);
    (*(void (__cdecl **)(_DWORD *, const char *))(*a2 + 32))(a2, "{\n");
    v4 = *this;
    if ( !*this )
      v4 = WindowName;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "  %s=\"%s\"\n", off_757C50[0], v4);
    v5 = this[2];
    if ( !v5 )
      v5 = WindowName;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "  %s=\"%s\"\n", off_757C54[0], v5);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "  %s=%d\n", off_757C58[0], this[4]);
    v6 = this[5];
    if ( !v6 )
      v6 = WindowName;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "  %s=\"%s\"\n", off_757C5C[0], v6);
    (*(void (__cdecl **)(_DWORD *, const char *))(*a2 + 32))(a2, "}\n\n");
    return 0;
  }
  return result;
}
