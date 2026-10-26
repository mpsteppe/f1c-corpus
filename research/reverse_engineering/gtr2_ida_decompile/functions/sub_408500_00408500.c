const char *__fastcall sub_408500(const char *a1)
{
  const char *result; // eax

  result = (const char *)strlen(a1);
  if ( (int)result > 0 )
  {
    for ( result = &a1[(_DWORD)result - 1]; result >= a1; *result-- = 0 )
    {
      if ( *result == 92 )
        break;
    }
  }
  return result;
}
