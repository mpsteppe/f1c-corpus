const char *__thiscall sub_565EF0(void *this)
{
  const char *v1; // edx
  const char *result; // eax

  v1 = (const char *)sub_5662D0(this);
  result = 0;
  if ( v1 )
  {
    result = &v1[strlen(v1)];
    if ( result > v1 )
    {
      while ( *result != 92 )
      {
        if ( --result <= v1 )
          return result;
      }
      ++result;
    }
  }
  return result;
}
