_DWORD *__thiscall sub_408BB0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = (_DWORD *)this[6];
  this[8] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      sub_4073E0(result, a2);
      result = (_DWORD *)this[8];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[8] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
