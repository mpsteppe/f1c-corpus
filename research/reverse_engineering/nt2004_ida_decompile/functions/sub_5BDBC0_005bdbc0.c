char *__thiscall sub_5BDBC0(const char *this)
{
  char *result; // eax

  result = 0;
  if ( this )
  {
    result = (char *)malloc(strlen(this) + 1);
    if ( result )
      strcpy(result, this);
  }
  return result;
}
