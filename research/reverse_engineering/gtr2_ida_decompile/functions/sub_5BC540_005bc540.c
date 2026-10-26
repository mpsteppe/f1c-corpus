_DWORD *__thiscall sub_5BC540(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = (_DWORD *)(this[2] + 8 * a2);
  if ( result )
  {
    *result = &off_729660;
    result[1] = 0;
  }
  return result;
}
