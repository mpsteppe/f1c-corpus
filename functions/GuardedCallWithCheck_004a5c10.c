char **__thiscall sub_4A5C10(_DWORD *this, int a2)
{
  char **result; // eax
  char *v3; // eax

  result = (char **)NthValidPartLookup(this, a2);
  if ( result )
  {
    v3 = *result;
    if ( !v3 )
      v3 = byte_5EA438;
    return (char **)TireCompoundNameIDMapping(v3);
  }
  return result;
}
