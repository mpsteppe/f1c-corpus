// f1c  0x0054b420  size=42
_DWORD *__thiscall sub_54B420(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = this[8];
  if ( a3 )
    *a3 = this[9];
  result = a4;
  if ( a4 )
    *a4 = this[10];
  return result;
}
