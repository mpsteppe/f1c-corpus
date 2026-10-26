_DWORD *__thiscall sub_4DCF30(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = this[5];
  result = a3;
  if ( a3 )
    *a3 = this[6];
  return result;
}
