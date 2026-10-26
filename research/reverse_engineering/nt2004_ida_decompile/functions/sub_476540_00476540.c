BOOL __thiscall sub_476540(char *String1, int a2)
{
  const char *v2; // eax

  v2 = *(const char **)(a2 + 4);
  if ( !v2 )
    v2 = &byte_629120;
  return _strcmpi(String1, v2) == 0;
}
