_DWORD *__thiscall sub_5C6870(_DWORD *this)
{
  _DWORD *result; // eax

  result = operator new(8u);
  if ( result )
  {
    *result = off_72A25C;
    result[1] = this[1];
  }
  else
  {
    result = 0;
    MEMORY[4] = this[1];
  }
  return result;
}
