unsigned int __stdcall sub_5E8080(const char *a1)
{
  unsigned int v1; // edx
  unsigned int result; // eax

  v1 = 0;
  result = strlen(a1);
  if ( result )
  {
    while ( a1[v1] != 46 )
    {
      ++v1;
      result = strlen(a1);
      if ( v1 >= result )
        return result;
    }
    a1[v1] = 0;
  }
  return result;
}
