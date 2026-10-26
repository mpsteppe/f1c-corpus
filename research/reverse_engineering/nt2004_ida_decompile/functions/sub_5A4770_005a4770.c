_DWORD *__thiscall sub_5A4770(_DWORD *this, const void *a2)
{
  _DWORD *result; // eax
  int v3; // ecx

  result = this;
  v3 = this[26];
  if ( v3 < 4 )
  {
    qmemcpy(&result[271 * v3 + 27], a2, 0x43Cu);
    ++result[26];
  }
  return result;
}
