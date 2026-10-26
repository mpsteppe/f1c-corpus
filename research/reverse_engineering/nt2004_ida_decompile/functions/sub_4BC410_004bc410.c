_DWORD *__thiscall sub_4BC410(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  bool v4; // zf

  result = (_DWORD *)*this;
  v4 = *this == 0;
  this[2] = *this;
  if ( !v4 )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      sub_4BC280(result, a2);
      result = (_DWORD *)this[2];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[2] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
