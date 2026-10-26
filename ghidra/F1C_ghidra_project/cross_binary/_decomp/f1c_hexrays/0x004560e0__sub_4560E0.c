// f1c  0x004560e0  size=42
_DWORD *__thiscall sub_4560E0(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = this[25];
  if ( a3 )
    *a3 = this[26];
  result = a4;
  if ( a4 )
    *a4 = this[27];
  return result;
}
