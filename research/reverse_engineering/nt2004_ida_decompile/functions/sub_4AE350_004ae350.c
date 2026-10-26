const char **__thiscall sub_4AE350(_DWORD *this, char *String2)
{
  const char **result; // eax

  result = sub_4AD420(this, String2);
  if ( result )
    this[92] = result;
  return result;
}
