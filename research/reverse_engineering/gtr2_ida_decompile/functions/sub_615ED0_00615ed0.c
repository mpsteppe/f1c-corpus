_BYTE *__thiscall sub_615ED0(void *this)
{
  const char *v1; // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  _BYTE *result; // eax

  v1 = (const char *)sub_615D40(this);
  v2 = (unsigned int)v1;
  if ( !v1 )
    return 0;
  v3 = strlen(v1);
  result = (_BYTE *)(v3 + v2);
  if ( v3 + v2 > v2 )
  {
    while ( *result != 92 )
    {
      if ( (unsigned int)--result <= v2 )
        return result;
    }
    ++result;
  }
  return result;
}
