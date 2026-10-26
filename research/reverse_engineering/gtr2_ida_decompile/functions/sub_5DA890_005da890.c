_DWORD *__thiscall sub_5DA890(_DWORD *this, _DWORD *a2, _DWORD *a3, int a4)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = (*this & 2) == 0;
  result = a3;
  if ( a3 )
    *a3 = (*this & 4) == 0;
  return result;
}
