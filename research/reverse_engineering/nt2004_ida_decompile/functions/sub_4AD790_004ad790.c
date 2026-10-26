char *__thiscall sub_4AD790(_DWORD *this)
{
  char *result; // eax

  result = (char *)sub_4AD7F0(this);
  if ( result )
  {
    result = (char *)sub_4AD490(this, result);
    if ( result )
      return (char *)sub_4AF730(result);
  }
  return result;
}
