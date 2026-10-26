// f1c  0x0053b1d0  size=42
_DWORD *__thiscall sub_53B1D0(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = this[7];
  if ( a3 )
    *a3 = this[8];
  result = a4;
  if ( a4 )
    *a4 = this[9];
  return result;
}
