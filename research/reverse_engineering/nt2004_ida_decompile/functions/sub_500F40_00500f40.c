const char *__thiscall sub_500F40(int *this, char *Str)
{
  const char *result; // eax

  result = strstr(Str, aTrace);
  if ( result )
  {
    result = (const char *)sscanf(result, "trace=%d", &Str);
    if ( result == (const char *)1 )
    {
      *this = (int)Str;
      return (const char *)sub_500EA0(this);
    }
  }
  return result;
}
