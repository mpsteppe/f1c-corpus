char *__thiscall sub_47C0A0(_DWORD *this)
{
  char *result; // eax

  result = UIScreenTextAccessor(this);
  if ( result )
    strcpy(&byte_7CD880, UIScreenTextAccessor(this));
  return result;
}

