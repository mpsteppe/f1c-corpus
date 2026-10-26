_DWORD *__thiscall sub_404630(_DWORD *this, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v5; // edx
  _DWORD *v6; // edx
  _DWORD *result; // eax

  v5 = (_DWORD *)(28 * a2 + this[98]);
  *a4 = *v5;
  a4[1] = v5[1];
  a4[2] = v5[2];
  v6 = (_DWORD *)(28 * a2 + this[98] + 12);
  result = a5;
  *a5 = *v6;
  a5[1] = v6[1];
  a5[2] = v6[2];
  return result;
}
