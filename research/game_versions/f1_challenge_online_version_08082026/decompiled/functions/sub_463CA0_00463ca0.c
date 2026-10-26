char *__thiscall sub_463CA0(char **this)
{
  char *result; // eax

  result = *this;
  if ( *((_DWORD *)*this + 4081) )
  {
    sub_57A730(256);
    return (char *)sub_45F710(*this);
  }
  return result;
}
