_DWORD *__thiscall sub_4EF560(char *this, int a2, char a3, char a4, _DWORD *a5)
{
  char *v5; // eax
  _DWORD *result; // eax

  v5 = &this[28 * a2];
  v5[15224] = a3;
  v5[15225] = a4;
  result = v5 + 15240;
  *result = *a5;
  result[1] = a5[1];
  result[2] = a5[2];
  return result;
}

