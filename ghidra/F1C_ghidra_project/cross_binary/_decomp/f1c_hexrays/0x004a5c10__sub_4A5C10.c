// f1c  0x004a5c10  size=38
char **__thiscall sub_4A5C10(_DWORD *this, int a2)
{
  char **result; // eax
  char *v3; // eax

  result = (char **)sub_4A5820(this, a2);
  if ( result )
  {
    v3 = *result;
    if ( !v3 )
      v3 = byte_5EA438;
    return (char **)sub_4A4830(v3);
  }
  return result;
}
