_DWORD *__thiscall sub_4599E0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  if ( a2 )
    this[14] = *a2;
  result = a3;
  if ( a3 )
    this[15] = *a3;
  return result;
}
