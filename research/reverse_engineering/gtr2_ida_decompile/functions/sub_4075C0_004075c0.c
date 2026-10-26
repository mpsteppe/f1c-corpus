BOOL __thiscall sub_4075C0(const char **this, const char *a2)
{
  const char *v2; // eax

  v2 = *this;
  if ( !*this )
    v2 = WindowName;
  return strcmp(v2, a2) == 0;
}
