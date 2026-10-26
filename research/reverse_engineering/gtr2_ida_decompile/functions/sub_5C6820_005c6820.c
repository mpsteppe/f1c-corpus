_DWORD *__thiscall sub_5C6820(_DWORD *this)
{
  _DWORD *result; // eax

  result = operator new(0x10u);
  if ( result )
  {
    *result = off_72A234;
    result[1] = this[1];
    result[2] = this[2];
    result[3] = this[3];
  }
  else
  {
    result = 0;
    MEMORY[4] = this[1];
    MEMORY[8] = this[2];
    MEMORY[0xC] = this[3];
  }
  return result;
}
