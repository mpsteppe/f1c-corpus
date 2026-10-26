// f1c  0x0053d8b0  size=45
_DWORD *__thiscall sub_53D8B0(_DWORD *this, const void *a2)
{
  _DWORD *result; // eax
  int v3; // ecx

  result = this;
  v3 = this[2];
  if ( v3 < 4 )
  {
    qmemcpy(&result[271 * v3 + 3], a2, 0x43Cu);
    ++result[2];
  }
  return result;
}
