_DWORD *__thiscall sub_5BC520(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = (_DWORD *)(this[2] + 12 * a2);
  if ( result )
  {
    *result = 0;
    result[1] = 0;
    result[2] = 0;
  }
  return result;
}
