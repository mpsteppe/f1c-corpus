_WORD *__thiscall sub_618030(_WORD *this)
{
  _WORD *result; // eax

  result = this;
  this[1] = 0;
  *this = 0;
  return result;
}
