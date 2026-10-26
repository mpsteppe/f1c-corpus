_DWORD *__thiscall sub_5260E0(_BYTE *this, int a2, int a3, float a4, int a5, _DWORD *a6)
{
  _DWORD *result; // eax

  this[a2 + 177] = 1;
  sub_526050(this, a2, a3, a4, a5);
  this[32 * a2 + 240] = 1;
  result = &this[32 * a2 + 244];
  *result = *a6;
  result[1] = a6[1];
  result[2] = a6[2];
  return result;
}
