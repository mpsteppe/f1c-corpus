_DWORD *__thiscall sub_51BBE0(char *this, int a2, char a3, char a4, _DWORD *a5)
{
  char *v5; // eax
  _DWORD *result; // eax

  v5 = &this[28 * a2];
  v5[19232] = a3;
  v5[19233] = a4;
  result = v5 + 19248;
  *result = *a5;
  result[1] = a5[1];
  result[2] = a5[2];
  return result;
}
