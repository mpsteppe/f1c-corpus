_DWORD *__thiscall sub_406A90(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = this[6];
  result = a3;
  if ( a3 )
    *a3 = this[7];
  return result;
}
