// Microsoft VisualC 2-14/net runtime
char *__thiscall unknown_libname_185(char *this)
{
  int v2; // edi
  char *v3; // eax
  std::ios_base *v4; // ecx
  int v5; // eax

  v2 = 0;
  v3 = &this[*(_DWORD *)(*(_DWORD *)this + 4)];
  if ( (v3[4] & 6) == 0 && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v3 + 10) + 44))(*((_DWORD *)v3 + 10)) == -1 )
    v2 = 4;
  v4 = (std::ios_base *)&this[*(_DWORD *)(*(_DWORD *)this + 4)];
  if ( v2 )
  {
    v5 = v2 | *((_DWORD *)v4 + 1);
    if ( !*((_DWORD *)v4 + 10) )
      LOBYTE(v5) = v5 | 4;
    std::ios_base::clear(v4, v5, 0);
  }
  return this;
}
