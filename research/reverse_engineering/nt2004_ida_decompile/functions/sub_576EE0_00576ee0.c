_DWORD *__thiscall sub_576EE0(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  *this = *a2;
  this[1] = a2[1];
  sub_5776C0(a2 + 2);
  sub_57B920(a2 + 5);
  result = this;
  this[19] = a2[19];
  this[20] = a2[20];
  return result;
}
