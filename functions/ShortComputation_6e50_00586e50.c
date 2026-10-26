_DWORD *__thiscall sub_586E50(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  *this = *a2;
  this[1] = a2[1];
  BufferWriteWithParams(a2 + 2);
  sub_59B3B0(a2 + 5);
  result = this;
  this[19] = a2[19];
  this[20] = a2[20];
  return result;
}
