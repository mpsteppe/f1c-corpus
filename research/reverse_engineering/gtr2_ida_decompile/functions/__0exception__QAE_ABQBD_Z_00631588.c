exception *__thiscall exception::exception(exception *this, const char **a2)
{
  int v3; // eax
  char *v4; // eax

  *(_DWORD *)this = &off_730210;
  v3 = sub_6354D0(*a2);
  v4 = (char *)malloc(v3 + 1);
  *((_DWORD *)this + 1) = v4;
  if ( v4 )
    strcpy(v4, *a2);
  *((_DWORD *)this + 2) = 1;
  return this;
}
