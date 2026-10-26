exception *__thiscall exception::exception(exception *this, const char **a2)
{
  size_t v3; // eax
  char *v4; // eax

  *(_DWORD *)this = &exception::`vftable';
  v3 = strlen(*a2);
  v4 = (char *)operator new(v3 + 1);
  *((_DWORD *)this + 1) = v4;
  if ( v4 )
    strcpy(v4, *a2);
  *((_DWORD *)this + 2) = 1;
  return this;
}
