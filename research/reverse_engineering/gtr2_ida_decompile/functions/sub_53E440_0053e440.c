const char *__fastcall sub_53E440(int a1)
{
  const char *v1; // ecx
  const char *result; // eax

  v1 = (const char *)(a1 + 22084);
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
  return result;
}
