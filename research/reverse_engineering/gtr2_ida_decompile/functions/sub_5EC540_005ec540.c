_DWORD *__thiscall sub_5EC540(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *result; // eax

  result = (_DWORD *)sub_5EB140(this, a2, 1);
  if ( a3 )
    *a3 = *result;
  if ( a4 )
    *a4 = result[1];
  if ( a5 )
  {
    result = (_DWORD *)result[2];
    *a5 = result;
  }
  return result;
}
