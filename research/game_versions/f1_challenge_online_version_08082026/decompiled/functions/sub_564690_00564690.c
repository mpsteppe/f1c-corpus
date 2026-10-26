char *__thiscall sub_564690(const char *this)
{
  char *result; // eax

  result = 0;
  if ( this )
  {
    result = (char *)sub_58A935(strlen(this) + 1);
    if ( result )
      strcpy(result, this);
  }
  return result;
}
