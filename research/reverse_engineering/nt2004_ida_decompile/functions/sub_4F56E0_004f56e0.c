char __thiscall sub_4F56E0(const char **this, char *Str)
{
  const char *v2; // ecx
  char *v3; // eax
  char String[256]; // [esp+0h] [ebp-100h] BYREF

  v2 = *this;
  if ( !v2 )
    v2 = &byte_629120;
  strcpy(String, v2);
  v3 = strtok(String, asc_6100B8);
  if ( !v3 )
    return 0;
  while ( strstr(Str, v3) != Str )
  {
    v3 = strtok(0, asc_6100B8);
    if ( !v3 )
      return 0;
  }
  return 1;
}
