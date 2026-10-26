int __thiscall sub_41D990(_DWORD *this, char *String1)
{
  const char *v2; // eax
  int result; // eax

  v2 = sub_41D8B0(this, String1);
  if ( !v2 )
    return -1;
  result = *((_DWORD *)v2 + 16);
  if ( result == -2 )
    return -1;
  return result;
}
