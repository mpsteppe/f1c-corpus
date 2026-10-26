exception *__thiscall exception::exception(exception *this, const struct exception *a2)
{
  int v3; // eax
  size_t v4; // eax
  char *v5; // eax

  *(_DWORD *)this = &exception::`vftable';
  v3 = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 2) = v3;
  if ( v3 )
  {
    v4 = strlen(*((const char **)a2 + 1));
    v5 = (char *)operator new(v4 + 1);
    *((_DWORD *)this + 1) = v5;
    if ( v5 )
      strcpy(v5, *((const char **)a2 + 1));
  }
  else
  {
    *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  }
  return this;
}
