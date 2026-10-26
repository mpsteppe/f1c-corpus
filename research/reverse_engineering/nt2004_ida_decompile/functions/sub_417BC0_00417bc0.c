_DWORD *__thiscall sub_417BC0(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a2;
  *(_DWORD *)(this[2] + 4 * *this) = a2;
  *a2 = (*this)++;
  return result;
}
