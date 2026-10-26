char __thiscall sub_4D8860(_DWORD *this, char a2)
{
  char result; // al

  result = a2;
  if ( a2 )
    return IndexValidationSetter(0);
  this[2] = -1;
  return result;
}
