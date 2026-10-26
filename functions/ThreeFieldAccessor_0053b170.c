_DWORD *__thiscall sub_53B170(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = this[1];
  if ( a3 )
    *a3 = this[2];
  result = a4;
  if ( a4 )
    *a4 = this[3];
  return result;
}
