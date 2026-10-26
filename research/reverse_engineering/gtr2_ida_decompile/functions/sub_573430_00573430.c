_DWORD *__thiscall sub_573430(_BYTE *this, int a2, char a3, char a4, _DWORD *a5)
{
  char *v5; // eax
  _DWORD *result; // eax

  v5 = &this[28 * a2];
  this[28 * a2 + 17696] = a3;
  v5[17697] = a4;
  result = v5 + 17712;
  *result = *a5;
  result[1] = a5[1];
  result[2] = a5[2];
  return result;
}
