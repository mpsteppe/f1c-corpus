_DWORD *__thiscall sub_67FD01(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *result; // eax

  v2 = (_DWORD *)sub_65B229(36);
  if ( v2 )
    result = sub_67F2AD(v2);
  else
    result = 0;
  if ( result )
  {
    result[4] = this[4];
    result[5] = this[5];
    result[6] = this[6];
    result[7] = this[7];
    result[8] = this[8];
  }
  return result;
}
