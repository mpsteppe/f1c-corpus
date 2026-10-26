_DWORD *__thiscall sub_49D6E0(_DWORD *this)
{
  _DWORD *result; // eax

  result = (_DWORD *)this[21];
  this[23] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      sub_4AFF10(result);
      result = (_DWORD *)this[23];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[23] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
