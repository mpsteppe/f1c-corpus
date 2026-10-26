_DWORD *__thiscall sub_5C68A0(_DWORD *this)
{
  _DWORD *result; // eax

  result = operator new(0xCu);
  if ( result )
  {
    *result = off_72A288;
    result[1] = this[1];
    result[2] = this[2];
  }
  else
  {
    result = 0;
    MEMORY[4] = this[1];
    MEMORY[8] = this[2];
  }
  return result;
}
