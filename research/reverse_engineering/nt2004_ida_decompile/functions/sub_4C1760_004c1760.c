char **__thiscall sub_4C1760(_DWORD *this, int ArgList)
{
  char **result; // eax
  char *v3; // eax

  result = (char **)sub_4C0C70(this, ArgList);
  if ( result )
  {
    v3 = *result;
    if ( !v3 )
      v3 = &byte_629120;
    return (char **)sub_4BFFC0(v3);
  }
  return result;
}
