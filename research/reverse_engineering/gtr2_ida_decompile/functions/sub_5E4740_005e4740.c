_DWORD *__thiscall sub_5E4740(_DWORD *this, int a2, int a3)
{
  _DWORD *result; // eax

  result = (_DWORD *)this[133];
  this[135] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      sub_5E4530(result, a2, a3);
      result = (_DWORD *)this[135];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[135] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
