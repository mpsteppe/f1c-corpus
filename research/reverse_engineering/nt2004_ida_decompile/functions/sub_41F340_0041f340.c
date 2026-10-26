_DWORD *__thiscall sub_41F340(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = &this[4 * a2];
  this[194] = result;
  this[193] = result;
  return result;
}
